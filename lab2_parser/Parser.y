%{
#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdio.h>
#define YYDEBUG 1
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);
static void lookup(char *token_buffer);

//#define YYPRINT
%}


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
%%

program: TOKEN_PROGRAM TOKEN_ID TOKEN_SEMICOLON groupTypeDefinitions
    groupVariableDeclarations groupSubprogramDeclarations
    compoundStatement TOKEN_DOT
    { cout << "program" << endl; };

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
    { cout << "type_definition" << endl; };

variableDeclaration: identifierList TOKEN_COLON type TOKEN_SEMICOLON
    { cout << "variable_declaration" << endl; };

procedureDeclaration: TOKEN_PROCEDURE TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_SEMICOLON groupBlockForward TOKEN_SEMICOLON
    { cout << "procedure_declaration" << endl; };

functionDeclaration: TOKEN_FUNCTION TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_COLON resultType TOKEN_SEMICOLON groupBlockForward 
    TOKEN_SEMICOLON
    { cout << "function_declaration" << endl; };

groupBlockForward: block | TOKEN_FORWARD;

formalParameterList: formalParamSeq { cout << "formal_parameter_list" << endl; }
    |;

formalParamSeq: formalParamSeq TOKEN_SEMICOLON identifierList TOKEN_COLON type { cout << "identifier_lists_more" << endl; }
    | identifierList TOKEN_COLON type { cout << "identifier_lists" << endl; };

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
    { cout << "procedure_statement" << endl; };

structuredStatement: compoundStatement { cout << "compound_statement" << endl; }
    | TOKEN_IF expression TOKEN_THEN statement { cout << "if_statement" << endl; }
    | TOKEN_IF expression TOKEN_THEN statement TOKEN_ELSE statement { cout << "ifelse_statement" << endl; }
    | TOKEN_WHILE expression TOKEN_DO statement { cout << "while_statement" << endl; }
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO statement { cout << "for_statement" << endl; };

type: TOKEN_ID { cout << "type_ID" << endl; } | TOKEN_ARRAY TOKEN_LBRACKET constant TOKEN_RANGE constant TOKEN_RBRACKET TOKEN_OF type
    | TOKEN_RECORD fieldList TOKEN_END;

resultType: TOKEN_ID { cout << "result_type" << endl; };

fieldList: fieldListSeq |;

fieldListSeq: fieldListSeq TOKEN_SEMICOLON identifierList TOKEN_COLON type
    | identifierList TOKEN_COLON type;

constant: groupSign TOKEN_INT;

groupSign: sign |;

expression: simpleExpression groupRelOpSimExpr { cout << "expression" << endl; };

groupRelOpSimExpr: relationalOp simpleExpression |;

relationalOp: TOKEN_LT { cout << "relational_op" << endl; }
    | TOKEN_LE { cout << "relational_op" << endl; }
    | TOKEN_GT { cout << "relational_op" << endl; }
    | TOKEN_GE { cout << "relational_op" << endl; }
    | TOKEN_NOTEQ { cout << "relational_op" << endl; }
    | TOKEN_EQ { cout << "relational_op" << endl; };

simpleExpression: groupSign term addOpTermList { cout << "simple_expression_more" << endl; }
    | groupSign term { cout << "simple_expression" << endl; };

addOpTermList: addOpTermList addOp term | addOp term;

addOp: TOKEN_PLUS { cout << "addop" << endl; }
    | TOKEN_MINUS { cout << "addop" << endl; }
    | TOKEN_OR { cout << "addop" << endl; };

term: factor mulOpFactorList { cout << "term_more" << endl; }
    | factor { cout << "term" << endl; } ;

mulOpFactorList: mulOpFactorList mulOp factor 
    | mulOp factor;

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
    { cout << "function_reference" << endl; };

variable: TOKEN_ID componentSelection { cout << "variable" << endl; };

componentSelection: TOKEN_DOT TOKEN_ID componentSelection | TOKEN_LBRACKET expression TOKEN_RBRACKET componentSelection
    | { cout << "component_selection_empty" << endl; };

actualParameterList: expressionList { cout << "actual_parameter_list" << endl; }
    | { cout << "actual_parameter_list_empty" << endl; };

expressionList: expressionList TOKEN_COMMAS expression
    { cout << "expressions_more" << endl; }
    | expression { cout << "expressions" << endl; };

identifierList: identifierList TOKEN_COMMAS TOKEN_ID { cout << "identifier_list_more" << endl; }
    | TOKEN_ID { cout << "identifier_list" << endl; };

sign: TOKEN_PLUS | TOKEN_MINUS %prec UMINUS

%%
main(int argc, char **argv) {
  FILE *myfile = fopen(argv[1], "r");
  if (!myfile) {
    cout << "Error in openning test.pas!" << endl;
    return -1;
  }
  
  yyin = myfile;

  yydebug = 1;
  do {
    yyparse();
  } while (!feof(yyin));
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}

/* Lookup literal names */
static void lookup(char *token_buffer) {
int i;
for (i = 0; i < YYNTOKENS; i++) {
  if (!strncmp(yytname[i], token_buffer, strlen(token_buffer))) {
    cout << yytname[i] << endl;
  }
}
/* 
if (yytname[i] != 0
&& yytname[i][0] == '"'
&& !strncmp (yytname[i] + 1, token_buffer,
strlen (token_buffer))
&& yytname[i][strlen (token_buffer) + 1] == '"'
&& yytname[i][strlen (token_buffer) + 2] == 0) {
printf("---Match Success: %s, %d\n",token_buffer,i,yytname[i]);
yylval.sval = token_buffer;
//return yytoknum[i];
return 0;
*/
/*
cout << "yytname[i]: " << yytname[i] << " yytname[i][0]: " << yytname[i][0] <<
    " yytname[i] + 1: " << yytname[i] + 1 << " strlen: " << strlen(token_buffer) <<
    " strlen + 1: " << yytname[i][strlen (token_buffer) + 1] <<
    " strlen + 2: " << yytname[i][strlen (token_buffer) + 2] << endl;
}*/
//printf("---Match Fail: %s\n",token_buffer);
//yylval.sval = token_buffer;
}

