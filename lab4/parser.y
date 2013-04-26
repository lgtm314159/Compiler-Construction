%{
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <assert.h>
#define YYDEBUG 1

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int address;
extern "C" int funcSavedAddr;
extern "C" int procSavedAddr;
extern "C" int recSavedAddr;
extern "C" int arrSavedAddr;

// Lab4
vector<string> quadruples;
int counter = 0;

void yyerror(const char *s);
static void lookup(char *token_buffer);
void addSymbol(const char *id, const char *type);
void addSymbol(const char *id, const string &type);
void addSymbol(const string &id, const char *type);
void addSymbol(const char* id, const int type);
void addSymbol(const string &id, const string &type);
vector<string> split(char *ids);
void fixAddress(int addr);
string processVarWithCompSel(string varStr);
void addQuadruple(const string& op, const string& arg1, const string& arg2,
    const string& result);

#define YYPRINT

map<string, pair<int, string> > symTable;
map<int, pair<string, string> > symTableIndexedByAddr;
string nilStr("nil");
char recordStr[] = "record";
char arrayStr[] = "array";
string rec(recordStr);
string arr(arrayStr);
%}

%expect 1

%union {
  int ival;
  float fval;
  bool bval;
  char *sval;
}

%token-table

%token TOKEN_COMMENT;
%token <sval> TOKEN_STR
%token <sval> TOKEN_AND
%token TOKEN_BEGIN
%token TOKEN_FORWARD
%token <sval> TOKEN_DIV
%token TOKEN_DO
%token TOKEN_ELSE
%token TOKEN_END
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_IF
%token TOKEN_ARRAY
%token <sval> TOKEN_MOD
%token <sval> TOKEN_NOT
%token TOKEN_OF
%token <sval> TOKEN_OR
%token TOKEN_PROCEDURE
%token TOKEN_PROGRAM
%token TOKEN_RECORD
%token TOKEN_THEN
%token TOKEN_TO
%token TOKEN_TYPE
%token TOKEN_VAR
%token TOKEN_WHILE
%token <sval> TOKEN_PLUS
%token <sval> TOKEN_MINUS
%token <sval> TOKEN_MULTIPLY
%token TOKEN_DIVIDE
%token <sval> TOKEN_EQ
%token <sval> TOKEN_LT
%token <sval> TOKEN_LE
%token <sval> TOKEN_GT
%token <sval> TOKEN_GE
%token <sval> TOKEN_NOTEQ
%token <sval> TOKEN_ID
%token <ival> TOKEN_INT
%token TOKEN_DECIMAL
%token TOKEN_EXPNUM
%token <sval> TOKEN_DOT
%token TOKEN_COMMAS
%token TOKEN_COLON
%token TOKEN_SEMICOLON
%token <sval> TOKEN_ASSIGN
%token TOKEN_RANGE
%token TOKEN_LPAR
%token TOKEN_RPAR
%token <sval> TOKEN_LBRACKET
%token <sval> TOKEN_RBRACKET

%right TOKEN_ELSE
%left TOKEN_PLUS TOKEN_MINUS TOKEN_OR
%left TOKEN_MULTIPLY TOKEN_DIV TOKEN_MOD TOKEN_AND
%right UPLUS UMINUS

%type <sval> type identifierList sign term factor factorElement
%type <sval> componentSelection variable expression groupComponentSelection
%type <sval> functionReference mulOp addOp simpleExpression assignmentStatement
%type <sval> relationalOp groupRelOpSimExpr procedureStatement simpleStatement
%type <ival> formalParamSeq formalParameterList
%%

program: TOKEN_PROGRAM TOKEN_ID TOKEN_SEMICOLON groupTypeDefinitions
    groupVariableDeclarations groupSubprogramDeclarations
    compoundStatement TOKEN_DOT
    { cout << "program" << endl;
      string id($2);
      symTable[id].first = 0;
      symTable[id].second = "nil";
    };

groupTypeDefinitions: typeDefinitions |;
groupVariableDeclarations: variableDeclarations |;
groupSubprogramDeclarations: subprogramDeclarations |;

typeDefinitions: TOKEN_TYPE typeDefinitionList ;

typeDefinitionList: typeDefinitionList typeDefinition { cout << "type_definition_more" << endl; } 
    | typeDefinition { cout << "type_definition" << endl; };

variableDeclarations: TOKEN_VAR variableDeclarationList;

variableDeclarationList: variableDeclarationList variableDeclaration { cout << "variable_declaration_more" << endl; }
    | variableDeclaration {cout << "variable_declaration" << endl; };

subprogramDeclarations: subprogramDeclarationList;

subprogramDeclarationList: subprogramDeclarationList procedureDeclaration { cout << "sub_program_declarations_more" << endl; }
    | subprogramDeclarationList functionDeclaration { cout << "sub_program_declarations_more" << endl; }
    | procedureDeclaration { cout << "sub_program_declarations" << endl; }
    | functionDeclaration { cout << "sub_program_declarations" << endl; };

typeDefinition: TOKEN_ID TOKEN_EQ type TOKEN_SEMICOLON
    { cout << "type_definition" << endl;
      string type($3);
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        addSymbol($1, $3);
        addSymbol($3, nilStr);
      } else if (type.compare(rec) == 0) {
        string id($1);
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = recSavedAddr;
          symTable[id].second = string($3); 
        }
      } else {
        string id($1);
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = arrSavedAddr;
          symTable[id].second = string($3); 
        }
      }
    };

variableDeclaration: identifierList TOKEN_COLON type TOKEN_SEMICOLON
    { cout << "variable_declaration" << endl;
      vector<string> ids = split($1);
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, $3);
      }
      string type($3);
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol($3, nilStr);
        }
      }
    };

procedureDeclaration: TOKEN_PROCEDURE TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_SEMICOLON groupBlockForward TOKEN_SEMICOLON
    { cout << "procedure_declaration" << endl;
      string id($2);
      if (symTable.find(id) != symTable.end()) {
        int addr = symTable[id].first;
        fixAddress(addr);
      }
      symTable[id].first = procSavedAddr;
      ostringstream convert;
      convert << $4;
      symTable[id].second = convert.str(); 
    };

functionDeclaration: TOKEN_FUNCTION TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_COLON resultType TOKEN_SEMICOLON groupBlockForward 
    TOKEN_SEMICOLON
    { cout << "function_declaration" << endl;
      string id($2);
      // This might have flaws.
      if (symTable.find(id) != symTable.end()) {
        if (symTable[id].first > funcSavedAddr) {
          int addr = symTable[id].first;
          fixAddress(addr);
          symTable[id].first = funcSavedAddr;
          ostringstream convert;
          convert << $4;
          symTable[id].second = convert.str();
        } else {
          fixAddress(funcSavedAddr);
          ostringstream convert;
          convert << $4;
          symTable[id].second = convert.str();
        }
      } else {
        symTable[id].first = funcSavedAddr;
        ostringstream convert;
        convert << $4;
        symTable[id].second = convert.str();
      }
    };

groupBlockForward: block | TOKEN_FORWARD;

formalParameterList: formalParamSeq { cout << "formal_parameter_list" << endl; $$ = $1; }
    | { $$ = 0; };

formalParamSeq: formalParamSeq TOKEN_SEMICOLON identifierList TOKEN_COLON type
    { cout << "identifier_lists_more" << endl;
      vector<string> ids = split($3);
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, $5);
      }
      string type($5);
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol($5, nilStr);
        }
      }
      $$ = $1 + ids.size();
    }
    | identifierList TOKEN_COLON type
      { cout << "identifier_lists" << endl;
        vector<string> ids = split($1);
        for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
          addSymbol(*it, $3);
        }
        string type($3);
        if (type.compare(rec) != 0 && type.compare(arr) !=0) {
          if (symTable.find(type) == symTable.end()) {
            addSymbol($3, nilStr);
          }
        }
        $$ = ids.size();
      };

block: groupVariableDeclarations compoundStatement { cout << "block" << endl; };

compoundStatement: TOKEN_BEGIN statementSequence TOKEN_END { cout << "compound_statement" << endl; };

statementSequence: statementSequence TOKEN_SEMICOLON statement { cout << "statement_sequence_more" << endl; }
    | statement { cout << "statement_sequence" << endl; };

statement: groupSimStruStatement { cout << "statement" << endl; };

groupSimStruStatement: simpleStatement | structuredStatement;

simpleStatement: assignmentStatement {
    cout << "simple_statement" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
    | procedureStatement {
    cout << "simple_statement" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
    | { cout << "simple_statement_empty" << endl;
    stringstream ss;
    ss << quadruples.size() - 1 << " " << quadruples.size() - 1; 
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    };

assignmentStatement: variable TOKEN_ASSIGN expression {
    cout << "assignment_statement" << endl;

    // lab4
    addQuadruple(string($2), string($3), string("NULL"), string($1));
    stringstream ss;
    ss << quadruples.size() - 1 << " " << quadruples.size() - 1; 
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    };

procedureStatement: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR {
    cout << "procedure_statement" << endl;
    string id($1);
    if (symTable.find(id) == symTable.end()) {
      addSymbol($1, nilStr);
    };

    // lab4
    addQuadruple("call", string($1), "NULL", "NULL");
    addQuadruple("return", "NULL", "NULL", "NULL"); 
    stringstream ss;
    ss << quadruples.size() - 2 << " " << quadruples.size() - 1; 
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    };

structuredStatement: compoundStatement { cout << "compound_statement" << endl; }
    | TOKEN_IF expression TOKEN_THEN statement { cout << "if_statement" << endl; }
    | TOKEN_IF expression TOKEN_THEN statement TOKEN_ELSE statement { cout << "ifelse_statement" << endl; }
    | TOKEN_WHILE expression TOKEN_DO statement { cout << "while_statement" << endl; }
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO statement { cout << "for_statement" << endl; };

type: TOKEN_ID { cout << "type_ID" << endl; //addSymbol($1, nilStr);
                 $$ = (char*) malloc(strlen($1) + 1);
                 strcpy($$, $1);} 
    | TOKEN_ARRAY TOKEN_LBRACKET constant TOKEN_RANGE constant TOKEN_RBRACKET TOKEN_OF type
      { cout << "type_array" << endl;
        $$ = (char*) malloc(sizeof(arrayStr));;
        strcpy($$, arrayStr); } 
    | TOKEN_RECORD fieldList TOKEN_END
      { cout << "type_record" << endl;
        $$ = (char*) malloc(sizeof(recordStr));;
        strcpy($$, recordStr); }; 

resultType: TOKEN_ID { cout << "result_type" << endl;
    string id($1);
    if (symTable.find(id) == symTable.end()) {
      addSymbol($1, nilStr);
    };
    };

fieldList: fieldListSeq { cout << "field_list" << endl; }
    | { cout << "field_list_empty" << endl; };

fieldListSeq: fieldListSeq TOKEN_SEMICOLON identifierList TOKEN_COLON type
    { cout << "identifier_lists_more" << endl;
      vector<string> ids = split($3);
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, $5);
      }
      string type($5);
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol($5, nilStr);
        }
      }
      
    }
    | identifierList TOKEN_COLON type
    { cout << "identifier_lists" << endl;
      vector<string> ids = split($1);
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, $3);
      }
      string type($3);
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol($3, nilStr);
        }
      }
    };

constant: TOKEN_INT { cout << "constant" << endl; }
    | sign TOKEN_INT { cout << "constant" << endl; };

expression: simpleExpression groupRelOpSimExpr {
    cout << "expression" << endl;
    if ($2 == NULL) {
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    } else {
      vector<string> opAndArg = split($2);
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(opAndArg[0], string($1), opAndArg[1], newTemp);
      $$ = (char*) malloc(newTemp.length() + 1);
      strcpy($$, newTemp.c_str());
    }
    };

groupRelOpSimExpr: relationalOp simpleExpression {
    stringstream ss;
    ss << $1 << " " << $2;
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    } 
    | { $$ = NULL; };

relationalOp: TOKEN_LT { cout << "relational_op" << endl;
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    }
    | TOKEN_LE { cout << "relational_op" << endl;
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    }
    | TOKEN_GT { cout << "relational_op" << endl;
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    }
    | TOKEN_GE { cout << "relational_op" << endl;
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    }
    | TOKEN_NOTEQ { cout << "relational_op" << endl;
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    }
    | TOKEN_EQ { cout << "relational_op" << endl;
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    };

simpleExpression: sign term { cout << "simple_expression" << endl;
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(string($1), string($2), string("NULL"), newTemp);
    $$ = (char*) malloc(newTemp.length() + 1);
    strcpy($$, newTemp.c_str());
    }
    | term { cout << "simple_expression" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
    | simpleExpression addOp term { cout << "simple_expression_more" << endl;
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(string($2), string($1), string($3), newTemp);
    $$ = (char*) malloc(newTemp.length() + 1);
    strcpy($$, newTemp.c_str());
    };

addOp: TOKEN_PLUS { cout << "addop" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
    | TOKEN_MINUS { cout << "addop" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
    | TOKEN_OR { cout << "addop" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    };

term: term mulOp factor { cout << "term_more" << endl;
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(string($2), string($1), string($3), newTemp);
    $$ = (char*) malloc(newTemp.length() + 1);
    strcpy($$, newTemp.c_str());
    }
    | factor { cout << "term" << endl;
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
      };

mulOp: TOKEN_MULTIPLY { cout << "mulop" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
  | TOKEN_DIV { cout << "mulop" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    } 
  | TOKEN_MOD { cout << "mulop" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
  | TOKEN_AND { cout << "mulop" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    };

factor: factorElement { cout << "factor" << endl;
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
    | TOKEN_NOT factorElement { cout << "factor" << endl;
      // lab4
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(string($1), string($2), string("NULL"), newTemp);
      $$ = (char*) malloc(newTemp.length() + 1);
      strcpy($$, newTemp.c_str());
    }

factorElement: TOKEN_INT {
    // Lab4
    stringstream ss;
    ss << $1;
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    }
    | TOKEN_STR {
      // Lab4
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
      }
    | variable {
      // lab4
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    }
    | functionReference {
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    }
    | TOKEN_LPAR expression TOKEN_RPAR {
      $$ = (char*) malloc(strlen($2) + 1);
      strcpy($$, $2);
    };

functionReference: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR {
    cout << "function_reference" << endl;
    string id($1);
    if (symTable.find(id) == symTable.end()) {
      addSymbol($1, nilStr);
    }

    // lab4
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(":=", "funcall", string($1), newTemp);
    addQuadruple("funreturn", newTemp, "NULL", "NULL");
    $$ = (char*) malloc(newTemp.length() + 1);
    strcpy($$, newTemp.c_str());
    };

variable: TOKEN_ID groupComponentSelection { cout << "variable" << endl;
    string id($1);
    if (symTable.find(id) == symTable.end()) {
      addSymbol($1, nilStr);
    }

    // lab4
    if ($2 == NULL) {
      $$ = (char*) malloc(strlen($1) + 1);
      strcpy($$, $1);
    } else {
      stringstream ss;
      ss << $1 << " " << $2;
      string newTemp = processVarWithCompSel(ss.str());
      $$ = (char*) malloc(newTemp.length() + 1);
      strcpy($$, newTemp.c_str());
    }
    };

groupComponentSelection: componentSelection {
    $$ = (char*) malloc(strlen($1) + 1);
    strcpy($$, $1);
    }
    | { cout << "component_selection_empty" << endl; $$ = NULL; };

componentSelection: TOKEN_DOT TOKEN_ID { cout << "component_selection" << endl;
    // lab4
    stringstream ss;
    ss << $1 << " " << $2;
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    } |
    TOKEN_LBRACKET expression TOKEN_RBRACKET { cout << "component_selection" << endl;
    // lab4
    stringstream ss;
    ss << $1 << $2 << $3;
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    } |
    componentSelection TOKEN_DOT TOKEN_ID { cout << "component_selection_more" << endl;
    stringstream ss;
    ss << $1 << " " << $2 << " " << $3;
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    } |
    componentSelection TOKEN_LBRACKET expression TOKEN_RBRACKET { cout << "component_selection_more" << endl;
    stringstream ss;
    ss << $1 << " " << $2 << $3 << $4;
    $$ = (char*) malloc(ss.str().length() + 1);
    strcpy($$, ss.str().c_str());
    }; 

actualParameterList: expressionList { cout << "actual_parameter_list" << endl; }
    | { cout << "actual_parameter_list_empty" << endl; };

expressionList: expressionList TOKEN_COMMAS expression {
    cout << "expressions_more" << endl;
    addQuadruple("param", string($3), string("NULL"), string("NULL"));
    }
    | expression { cout << "expressions" << endl;
    addQuadruple("param", string($1), string("NULL"), string("NULL"));
    };

identifierList: identifierList TOKEN_COMMAS TOKEN_ID
    { cout << "identifier_list_more" << endl;
      $$ = (char*) malloc (strlen($1) + strlen($3) + 2);
      int i = 0;
      while ($1[i] != '\0') {
        $$[i] = $1[i];
        ++i;
      }
      $$[i++] = ' ';
      int j = 0;
      while ($3[j] != '\0') {
        $$[i++] = $3[j++];
      }
      $$[i] = '\0';
    }
    | TOKEN_ID
    { cout << "identifier_list" << endl;
      $$ = (char*) malloc (strlen($1) + 1);
      strcpy($$, $1);};

sign: TOKEN_PLUS %prec UPLUS {
      // Lab4
      $$ = (char*) malloc(2);
      *$$ = '+';
      *($$ + 1) = '\0';
      }
    | TOKEN_MINUS %prec UMINUS {
      // Lab4
      $$ = (char*) malloc(2);
      *$$ = '-';
      *($$ + 1) = '\0';
      }

%%
main(int argc, char **argv) {
  FILE *myfile = fopen(argv[1], "r");
  freopen ("rules.out", "w", stdout);
  if (!myfile) {
    cout << "Error in openning test.pas!" << endl;
    return -1;
  }
  yyin = myfile;
  //yydebug = 1;
  do {
    yyparse();
  } while (!feof(yyin));
  fclose(stdout);
  fclose(myfile);

  map<string, pair<int, string> >::iterator it;
  for (it = symTable.begin(); it != symTable.end(); ++it) {
    symTableIndexedByAddr[it->second.first] = make_pair(it->first, it->second.second);
  }
  map<int, pair<string, string> >::iterator it2;
  stringstream ss; 
  freopen("symtable.out", "w", stdout);
  for (it2 = symTableIndexedByAddr.begin(); it2 != symTableIndexedByAddr.end(); ++it2) {
    ss.str(string());
    ss << "address: " << it2->first;
    cout << setw(14) << std::left << ss.str();
    ss.str(string());
    ss << ", identifier: " << it2->second.first;
    cout << setw(29) << std::left << ss.str();
    ss.str(string());
    ss << ", type: " << it2->second.second;
    cout << setw(18) << std::left << ss.str();
    cout << endl;
  }
  fclose(stdout);

  freopen("a.txt", "w", stdout);
  for (int i = 0; i < quadruples.size(); ++i) {
    cout << quadruples[i] << endl;
  }
  fclose(stdout);
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}

/* Lookup literal names. */
static void lookup(char *token_buffer) {
  int i;
  for (i = 0; i < YYNTOKENS; i++) {
    if (!strncmp(yytname[i], token_buffer, strlen(token_buffer))) {
      cout << yytname[i] << endl;
    }
  }
}

void addSymbol(const char* id, const char *type) {
  string idName(id);
  string typeName(type);
  addSymbol(idName, typeName);
}

void addSymbol(const char* id, const string &type) {
  string idName(id);
  addSymbol(idName, type);
}

void addSymbol(const string &id, const char *type) {
  string typeName(type);
  addSymbol(id, typeName);
}

void addSymbol(const char* id, const int type) {
  std::ostringstream convert;
  convert << type;
  string typeName = convert.str();
  string idName(id); 
  addSymbol(id, typeName);
}

void addSymbol(const string &id, const string &type) {
  if (symTable.find(id) != symTable.end()) {
    symTable[id].second = type;
  } else {
    symTable[id].first = address;
    symTable[id].second = type;
    ++address;
  }
}

/* Function to fix the addresses for symbols. */
void fixAddress(int addr) {
  --address;
  map<string, pair<int, string> >::iterator it;
  for (it = symTable.begin(); it != symTable.end(); ++it) {
    if (it->second.first > addr) {
      it->second.first = it->second.first - 1;
    }
  }
}

/* Function to split an identifier list into identifiers.*/
vector<string> split(char* ids) {
  vector<string> result;
  int i = 0;
  int j = 0;
  while (true) {
    if (ids[j] == '\0') {
      char* str = (char*) malloc(j - i + 1);
      for (int k = i; k <= j - 1; ++k) {
        str[k - i] = ids[k];
      }
      str[j - i] = '\0';
      string id(str);
      result.push_back(id);
      break;
    }
    if (ids[j] == ' ') {
      char* str = (char*) malloc(j - i + 1);
      for (int k = i; k <= j - 1; ++k) {
        str[k - i] = ids[k];
      }
      str[j - i] = '\0';
      string id(str);
      result.push_back(id);
      i = j + 1;
    }
    ++j;
  }
  return result;
}

string processVarWithCompSel(string varStr) {
  vector<string> fields = split((char*)varStr.c_str());
  string prevVar = fields[0];
  for (int i = 1; i < fields.size(); ++i) {
    if (fields[i].compare(".") == 0) {
      ++i;
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(string("record_field_select"), prevVar, fields[i], newTemp);
      prevVar = newTemp;
    } else {
      assert(fields[i].find("[") != string::npos);
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(string("array_element_select"), prevVar,
          fields[i].substr(0, fields[i].length() - 2), newTemp);
      prevVar = newTemp;
    }
  }
  return prevVar;
}

void addQuadruple(const string& op, const string& arg1, const string& arg2,
    const string& result) {
  stringstream ss;
  ss << op << " " << arg1 << " " << arg2 << " " << result;
  quadruples.push_back(ss.str());
} 
