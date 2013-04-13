%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h" 
#include "Symbol.h"
#include "Env.h"
#include "TypeDesc.h"
#include <stack>
#include <vector>
#include <iostream>

#define YY_DECL extern "C" int yylex()
#define MYNEWLINE 10;

using namespace std;

int line = 1;
int address = 1;
int funcSavedAddr;
int procSavedAddr;
int recSavedAddr;
int arrSavedAddr;

// Lab3
stack<Env*> envs;
stack<int> offsets;
vector<Env*> allEnvs;
stack<vector<pair<string, TypeDesc> >* > fieldListStack;
stack<TypeDesc*> arrayTypeStack;
stack<TypeDesc*> expTypeStack;
int recordSeq = 0;
int arraySeq = 0;
%}

DELIM   [ \t]
WS      {DELIM}+
NEWLINE [\n\r]
LETTER  [A-Za-z]
DIGIT   [0-9]
ID      {LETTER}({LETTER}|{DIGIT}|_)*
INTEGER {DIGIT}+
DECIMAL {DIGIT}?(\.{DIGIT}+)+
EXPNUM  ({INTEGER}|{DECIMAL})(E[+-]?{DIGIT}+)?
STR     \"[^\"\n]*\"
COMMENT \{[^\}]*\}
ERROR   [^{DELIM}{WS}{NEWLINE}{LETTER}{DIGIT}{ID}{INTEGER}{DECIMAL}{EXPNUM}{STR}]
%%

{WS}        {/* Do nothing */}
{NEWLINE} {++line;};
{COMMENT}     {/* Do nothing */
                char* str = yytext;
                int i;
                for (i = 0; str[i] != '\0'; ++i) {
                  if (str[i] == '\n') ++line;
                }
                //return TOKEN_COMMENT;
              }
and         {//printf("KEYWORD %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_AND;}
begin     {//printf("KEYWORD %s\n", yytext);
return TOKEN_BEGIN;}
forward     {//printf("KEYWORD %s\n", yytext);
return TOKEN_FORWARD;}
div     {//printf("KEYWORD %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_DIV;}
do     {//printf("KEYWORD %s\n", yytext);
return TOKEN_DO;}
else     {//printf("KEYWORD %s\n", yytext);
return TOKEN_ELSE;}
end     {//printf("KEYWORD %s\n", yytext);
return TOKEN_END;}
for     {//printf("KEYWORD %s\n", yytext);
return TOKEN_FOR;}
function     {//printf("KEYWORD %s\n", yytext);
funcSavedAddr = address;
++address;
return TOKEN_FUNCTION;}
if     {//printf("KEYWORD %s\n", yytext);
return TOKEN_IF;}
array     {//printf("KEYWORD %s\n", yytext);
arrSavedAddr = address;
++address;
return TOKEN_ARRAY;}
mod     {//printf("KEYWORD %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_MOD;}
not     {//printf("KEYWORD %s\n", yytext);
return TOKEN_NOT;}
of     {//printf("KEYWORD %s\n", yytext);
return TOKEN_OF;}
or     {//printf("KEYWORD %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_OR;}
procedure     {//printf("KEYWORD %s\n", yytext);
procSavedAddr = address;
++address;
return TOKEN_PROCEDURE;}
program     {//printf("KEYWORD %s\n", yytext);
Env* envPtr = new Env(NULL);
envs.push(envPtr);
allEnvs.push_back(envPtr);
return TOKEN_PROGRAM;}
record     {//printf("KEYWORD %s\n", yytext);
recSavedAddr = address;
++address;
return TOKEN_RECORD;}
then     {//printf("KEYWORD %s\n", yytext); 
if (expTypeStack.top()->getType().compare("boolean") != 0) {
  cout << "Error: If construct expects boolean expression, "
      << expTypeStack.top()->getType() << " found" << endl;
}
expTypeStack.pop();
return TOKEN_THEN;}
to     {//printf("KEYWORD %s\n", yytext); 
return TOKEN_TO;}
type     {//printf("KEYWORD %s\n", yytext); 
return TOKEN_TYPE;}
var     {//printf("KEYWORD %s\n", yytext); 
return TOKEN_VAR;}
while     {//printf("KEYWORD %s\n", yytext); 
return TOKEN_WHILE;}
"+" {//printf("PLUS\n");
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_PLUS;}
"-" {//printf("MINUS\n");
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_MINUS;}
"*" {//printf("MULT\n");
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_MULTIPLY;}
"/" {//printf("DIVIDE\n");
return TOKEN_DIVIDE;}
"=" {//printf("RELOP %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_EQ;}
"<" {//printf("RELOP %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_LT;
}
"<=" {//printf("RELOP %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_LE;}
">" {//printf("RELOP %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_GT;}
">=" {//printf("RELOP %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_GE;}
"<>" {//printf("RELOP %s\n", yytext);
yylval.sval = (char*) malloc(strlen(yytext) + 1);
strcpy(yylval.sval, yytext);
return TOKEN_NOTEQ;}
{ID}        {//printf("IDENTIFIER %s\n", yytext);
             yylval.sval = (char*) malloc(strlen(yytext) + 1);
             strcpy(yylval.sval, yytext);
             return TOKEN_ID;}
{INTEGER}   {//printf("INTEGER %s\n", yytext); 
             yylval.ival = atoi(yytext); return TOKEN_INT;}
{DECIMAL}   {//printf("DECIMAL %s\n", yytext);
             yylval.fval = atof(yytext); return TOKEN_DECIMAL;}
{EXPNUM}    {//printf("EXPNUMBER %s\n", yytext);
return TOKEN_EXPNUM;}
{STR}       {printf("STRING %s\n", yytext);
             yylval.sval = (char*) malloc(strlen(yytext) + 1);
             strcpy(yylval.sval, yytext);
             return TOKEN_STR;}
"." {//printf("DOT\n");
return TOKEN_DOT;}
"," {//printf("COMMA\n"); 
return TOKEN_COMMAS;}
":" {//printf("COLON\n"); 
return TOKEN_COLON;} 
";" {//printf("SEMICOLON\n"); 
return TOKEN_SEMICOLON;}
":=" {//printf("ASSIGN\n"); 
return TOKEN_ASSIGN;}
".." {//printf("RANGE\n"); 
return TOKEN_RANGE;}
"(" {//printf("LPAR\n"); 
return TOKEN_LPAR;}
")" {//printf("RPAR\n"); 
return TOKEN_RPAR;}
"[" {//printf("LBRACKET\n"); 
return TOKEN_LBRACKET;}
"]" {//printf("RBRACKET\n");
return TOKEN_RBRACKET;}
{ERROR} {printf("ERROR(%d): Unrecognized Symbol \"%s\"\n", line, yytext);}
%%

