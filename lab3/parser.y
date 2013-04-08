%{
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <stack>
#include "Symbol.h"
#include "Env.h"
#include "TypeDesc.h"
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

// Lab3
extern "C++" stack<Env*> envs;
extern "C++" stack<int> offsets;

void yyerror(const char *s);
static void lookup(char *token_buffer);
void addSymbol(const char *id, const char *type);
void addSymbol(const char *id, const string &type);
void addSymbol(const string &id, const char *type);
void addSymbol(const char* id, const int type);
void addSymbol(const string &id, const string &type);
vector<string> split(char *ids);
void fixAddress(int addr);

#define YYPRINT

map<string, pair<int, string> > symTable;
map<int, pair<string, string> > symTableIndexedByAddr;
string nilStr("nil");
char recordStr[] = "record";
char arrayStr[] = "array";
string rec(recordStr);
string arr(arrayStr);

// Lab3 variables
//stack<Env*> envs;
//stack<int> offsets;
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
%token TOKEN_AND
%token TOKEN_BEGIN
%token TOKEN_FORWARD
%token TOKEN_DIV
%token TOKEN_DO
%token TOKEN_ELSE
%token TOKEN_END
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_IF
%token TOKEN_ARRAY
%token TOKEN_MOD
%token TOKEN_NOT
%token TOKEN_OF
%token TOKEN_OR
%token TOKEN_PROCEDURE
%token TOKEN_PROGRAM
%token TOKEN_RECORD
%token TOKEN_THEN
%token TOKEN_TO
%token TOKEN_TYPE
%token TOKEN_VAR
%token TOKEN_WHILE
%token <sval> TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MULTIPLY
%token TOKEN_DIVIDE
%token TOKEN_EQ
%token TOKEN_LT
%token TOKEN_LE
%token TOKEN_GT
%token TOKEN_GE
%token TOKEN_NOTEQ
%token <sval> TOKEN_ID
%token <ival> TOKEN_INT
%token TOKEN_DECIMAL
%token TOKEN_EXPNUM
%token TOKEN_DOT
%token TOKEN_COMMAS
%token TOKEN_COLON
%token TOKEN_SEMICOLON
%token TOKEN_ASSIGN
%token TOKEN_RANGE
%token TOKEN_LPAR
%token TOKEN_RPAR
%token TOKEN_LBRACKET
%token TOKEN_RBRACKET

%right TOKEN_ELSE
%left TOKEN_PLUS TOKEN_MINUS TOKEN_OR
%left TOKEN_MULTIPLY TOKEN_DIV TOKEN_MOD TOKEN_AND
%right UPLUS UMINUS

%type <sval> type identifierList
%type <ival> formalParamSeq formalParameterList constant
%%

program: TOKEN_PROGRAM TOKEN_ID TOKEN_SEMICOLON groupTypeDefinitions
    groupVariableDeclarations groupSubprogramDeclarations
    compoundStatement TOKEN_DOT
    { cout << "program" << endl;
      string id($2);
      symTable[id].first = 0;
      symTable[id].second = "nil";

      // Lab3
      /*
      Env env(NULL);
      Env* envPtr = &env; 
      envs.push(envPtr);
      offsets.push(address);
      */
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
      vector<string> strs = split($3);
      //if (type.compare(rec) != 0 && type.compare(arr) !=0) {
      if (strs[0].compare(rec) != 0 && strs[0].compare(arr) !=0) {
        addSymbol($1, $3);
        addSymbol($3, nilStr);

        // Lab3. Address will be fixed later.
        if (!envs.empty()) {
          string lexime($1);
          if (strs[0].compare("integer") == 0 || strs[0].compare("float") == 0
              || strs[0].compare("boolean") == 0) {
            TypeDesc td(strs[0]);
            Symbol sym(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);
          } else {
            if (envs.top()->getSymbol(strs[0]) == NULL) {
              Env* envPtr = envs.top()->getPrevEnv();
              bool found = false;
              while (envPtr != NULL) {
                if (envPtr->getSymbol(strs[0]) != NULL) {
                  found = true;
                  TypeDesc td(envPtr->getSymbol(strs[0])->getTypeDesc());
                  Symbol sym(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                  break;
                }
                envPtr = envPtr->getPrevEnv();
              }
              if (!found) {
                cout << "Error: type " << strs[0] << " not defined" << endl;
              }
            } else {
              TypeDesc td(envs.top()->getSymbol(strs[0])->getTypeDesc());
              Symbol sym(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            }
          }          
        }
      } else if (strs[0].compare(rec) == 0) {
        string id($1);
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = recSavedAddr;
          symTable[id].second = string($3); 
        } else {
          if (symTable[id].first > recSavedAddr) {
            int addr = symTable[id].first;
            fixAddress(addr);
            symTable[id].first = recSavedAddr;
          } else {
            fixAddress(recSavedAddr);
          }
          symTable[id].second = string($3); 
        }

        
      } else {
        string id($1);
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = arrSavedAddr;
          symTable[id].second = strs[0];
          
        } else {
          if (symTable[id].first > arrSavedAddr) {
            int addr = symTable[id].first;
            fixAddress(addr);
            symTable[id].first = arrSavedAddr;
          } else {
            fixAddress(arrSavedAddr);
          }
          symTable[id].second = strs[0];
        }

        // Lab3
        //symTable[id].second = string($3); 
        if (!envs.empty()) {
          int lower = atoi(strs[1].c_str());
          int upper = atoi(strs[2].c_str());
          TypeDesc td(strs[0], lower, upper, strs[3]);
          Symbol sym($1, 0, td);
          string lexime($1);
          envs.top()->setSymbol(lexime, sym);
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

simpleStatement: assignmentStatement { cout << "simple_statement" << endl; }
    | procedureStatement { cout << "simple_statement" << endl; }
    | { cout << "simple_statement_empty" << endl; };

assignmentStatement: variable TOKEN_ASSIGN expression { cout << "assignment_statement" << endl; };

procedureStatement: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR
    { cout << "procedure_statement" << endl;
      string id($1);
      if (symTable.find(id) == symTable.end()) {
        addSymbol($1, nilStr);
      };
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
        //$$ = (char*) malloc(sizeof(arrayStr));;

        // Lab3
        stringstream ss; 
        ss << arrayStr;
        ss << " ";
        ss << $3 << " " << $5 << " " << $8;
        $$ = (char*) malloc(ss.str().length() + 1);
        strcpy($$, ss.str().c_str());
        
        string arrayType($8);
        if (arrayType.compare(rec) != 0 &&
            arrayType.find("array") == string::npos) {
          if (symTable.find(arrayType) == symTable.end()) {
            addSymbol(arrayType, nilStr);
          }
        }
      } 
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

constant: TOKEN_INT { cout << "constant" << endl; $$ = $1;}
    | sign TOKEN_INT { cout << "constant" << endl; $$ = $2;};

expression: simpleExpression groupRelOpSimExpr { cout << "expression" << endl; };

groupRelOpSimExpr: relationalOp simpleExpression |;

relationalOp: TOKEN_LT { cout << "relational_op" << endl; }
    | TOKEN_LE { cout << "relational_op" << endl; }
    | TOKEN_GT { cout << "relational_op" << endl; }
    | TOKEN_GE { cout << "relational_op" << endl; }
    | TOKEN_NOTEQ { cout << "relational_op" << endl; }
    | TOKEN_EQ { cout << "relational_op" << endl; };

simpleExpression: sign term { cout << "simple_expression" << endl; }
    | term { cout << "simple_expression" << endl; }
    | simpleExpression addOp term { cout << "simple_expression_more" << endl; };

addOp: TOKEN_PLUS { cout << "addop" << endl; }
    | TOKEN_MINUS { cout << "addop" << endl; }
    | TOKEN_OR { cout << "addop" << endl; };

term: term mulOp factor { cout << "term_more" << endl; }
    | factor { cout << "term" << endl; } ;

mulOp: TOKEN_MULTIPLY { cout << "mulop" << endl; }
  | TOKEN_DIV { cout << "mulop" << endl; } 
  | TOKEN_MOD { cout << "mulop" << endl; }
  | TOKEN_AND { cout << "mulop" << endl; };

factor: TOKEN_INT { cout << "factor" << endl; }
    | TOKEN_STR { cout << "factor" << endl; }
    | variable { cout << "factor" << endl; }
    | functionReference { cout << "factor" << endl; }
    | TOKEN_NOT factor { cout << "factor" << endl; }
    | TOKEN_LPAR expression TOKEN_RPAR { cout << "factor" << endl; };

functionReference: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR
    { cout << "function_reference" << endl;
      string id($1);
      if (symTable.find(id) == symTable.end()) {
        addSymbol($1, nilStr);
      }
    };

variable: TOKEN_ID componentSelection { cout << "variable" << endl;
    string id($1);
    if (symTable.find(id) == symTable.end()) {
      addSymbol($1, nilStr);
    }
    };

componentSelection: TOKEN_DOT TOKEN_ID componentSelection | TOKEN_LBRACKET expression TOKEN_RBRACKET componentSelection
    | { cout << "component_selection_empty" << endl; };

actualParameterList: expressionList { cout << "actual_parameter_list" << endl; }
    | { cout << "actual_parameter_list_empty" << endl; };

expressionList: expressionList TOKEN_COMMAS expression
    { cout << "expressions_more" << endl; }
    | expression { cout << "expressions" << endl; };

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

sign: TOKEN_PLUS %prec UPLUS | TOKEN_MINUS %prec UMINUS

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
  fclose(myfile);
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

