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

%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIV
%right UPLUS UMINUS
%%

program: TOKEN_PROGRAM TOKEN_ID TOKEN_SEMICOLON groupTypeDefinitions
    groupVariableDeclarations groupSubprogramDeclarations
    compoundStatement TOKEN_DOT
    { cout << "program" << endl; };

groupTypeDefinitions: typeDefinitions |;
groupVariableDeclarations: variableDeclarations |;
groupSubprogramDeclarations: subprogramDeclarations |;

typeDefinitions: TOKEN_TYPE typeDefinitionList;

typeDefinitionList: typeDefinitionList typeDefinition | typeDefinition;

variableDeclarations: TOKEN_VAR variableDeclarationList;

variableDeclarationList: variableDeclarationList variableDeclaration
    | variableDeclaration;

subprogramDeclarations: subprogramDeclarationList;

subprogramDeclarationList: subprogramDeclarationList procedureDeclaration
    | subprogramDeclarationList functionDeclaration
    | procedureDeclaration | functionDeclaration;

typeDefinition: TOKEN_ID TOKEN_EQ type TOKEN_SEMICOLON;

variableDeclaration: identifierList TOKEN_COLON type TOKEN_SEMICOLON;

procedureDeclaration: TOKEN_PROCEDURE TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_SEMICOLON groupBlockForward TOKEN_SEMICOLON;

functionDeclaration: TOKEN_FUNCTION TOKEN_ID TOKEN_LPAR formalParameterList
    TOKEN_RPAR TOKEN_COLON resultType TOKEN_SEMICOLON groupBlockForward 
    TOKEN_SEMICOLON;

groupBlockForward: block | TOKEN_FORWARD;

formalParameterList: formalParamSeq |;

formalParamSeq: formalParamSeq TOKEN_SEMICOLON identifierList TOKEN_COLON type
    | identifierList TOKEN_COLON type;

block: groupVariableDeclarations compoundStatement;

compoundStatement: TOKEN_BEGIN statementSequence TOKEN_END;

statementSequence: statementSequence TOKEN_SEMICOLON statement | statement;

statement: groupSimStruStatement;

groupSimStruStatement: simpleStatement | structuredStatement;

simpleStatement: assignmentStatement | procedureStatement |;

assignmentStatement: variable TOKEN_ASSIGN expression;

procedureStatement: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR

structuredStatement: compoundStatement
    | TOKEN_IF expression TOKEN_THEN statement groupElseStatement
    | TOKEN_WHILE expression TOKEN_DO statement
    | TOKEN_FOR TOKEN_ID TOKEN_ASSIGN expression TOKEN_TO expression TOKEN_DO statement;

groupElseStatement: TOKEN_ELSE statement |;

type: TOKEN_ID | TOKEN_ARRAY TOKEN_LBRACKET constant TOKEN_RANGE constant TOKEN_RBRACKET TOKEN_OF type
    | TOKEN_RECORD fieldList TOKEN_END;

resultType: TOKEN_ID;

fieldList: fieldListSeq |;

fieldListSeq: fieldListSeq identifierList TOKEN_COLON type TOKEN_SEMICOLON
    | identifierList TOKEN_COLON type TOKEN_SEMICOLON;

constant: groupSign TOKEN_INT;

groupSign: sign |;

expression: simpleExpression groupRelOpSimExpr;

groupRelOpSimExpr: relationalOp simpleExpression |;

relationalOp: TOKEN_LT | TOKEN_LE | TOKEN_GT | TOKEN_GE | TOKEN_NOTEQ
    | TOKEN_EQ;

simpleExpression: groupSign term addOpTermList;

addOpTermList: addOpTermList addOp term|;

addOp: TOKEN_PLUS | TOKEN_MINUS | TOKEN_OR;

term: factor mulOpFactorList;

mulOpFactorList: mulOpFactorList mulOp factor |;

mulOp: TOKEN_MULTIPLY | TOKEN_DIV | TOKEN_MOD | TOKEN_AND;

factor: TOKEN_INT | TOKEN_STR | variable | functionReference
    | TOKEN_NOT factor | TOKEN_LPAR expression TOKEN_RPAR;

functionReference: TOKEN_ID TOKEN_LPAR actualParameterList TOKEN_RPAR;

variable: TOKEN_ID componentSelection;

componentSelection: TOKEN_DOT TOKEN_ID componentSelection | TOKEN_LBRACKET expression TOKEN_RBRACKET componentSelection
    |;

actualParameterList: expressionList |;

expressionList: expressionList expression | expression;

identifierList: identifierList TOKEN_COMMAS TOKEN_ID | TOKEN_ID;

sign: TOKEN_PLUS | TOKEN_MINUS %prec UMINUS

%%
main() {
  FILE *myfile = fopen("test.pas", "r");
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

