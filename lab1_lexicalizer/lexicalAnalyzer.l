%{
#include <stdio.h>
#include <stdlib.h>
#define MYNEWLINE 10;
int line = 1;
%}

delim   [ \t]
ws      {delim}+
newline \n
letter  [A-Za-z]
digit   [0-9]
id      {letter}({letter}|{digit}|_)*
integer [+-]?{digit}+
decimal [+-]?{digit}+(\.{digit}+)?
expnum  ({integer}|{decimal})(E[+-]?{digit}+)?
str     \"[^\"\n]*\"
comment \{[^\}]*\}
error   [^{delim}{ws}{newline}{letter}{digit}{id}{integer}{decimal}{expnum}{str}]
%%

{ws}        {/* Do nothing */}
{newline} {++line;};
{comment}     {/* Do nothing */
                char* str = yytext;
                int i;
                for (i = 0; str[i] != '\0'; ++i) {
                  if (str[i] == '\n') ++line;
                }
              }
and         {printf("KEYWORD %s\n", yytext);}
begin     {printf("KEYWORD %s\n", yytext);}
forward     {printf("KEYWORD %s\n", yytext);}
div     {printf("KEYWORD %s\n", yytext);}
do     {printf("KEYWORD %s\n", yytext);}
else     {printf("KEYWORD %s\n", yytext);}
end     {printf("KEYWORD %s\n", yytext);}
for     {printf("KEYWORD %s\n", yytext);}
function     {printf("KEYWORD %s\n", yytext);}
if     {printf("KEYWORD %s\n", yytext);}
array     {printf("KEYWORD %s\n", yytext);}
mod     {printf("KEYWORD %s\n", yytext);}
not     {printf("KEYWORD %s\n", yytext);}
of     {printf("KEYWORD %s\n", yytext);}
or     {printf("KEYWORD %s\n", yytext);}
procedure     {printf("KEYWORD %s\n", yytext);}
program     {printf("KEYWORD %s\n", yytext);}
record     {printf("KEYWORD %s\n", yytext);}
then     {printf("KEYWORD %s\n", yytext);}
to     {printf("KEYWORD %s\n", yytext);}
type     {printf("KEYWORD %s\n", yytext);}
var     {printf("KEYWORD %s\n", yytext);}
while     {printf("KEYWORD %s\n", yytext);}
"+" {printf("PLUS\n");}
"-" {printf("MINUS\n");}
"*" {printf("MULT\n");}
"/" {printf("DIVIDE\n");}
"=" {printf("RELOP %s\n", yytext);}
"<" {printf("RELOP %s\n", yytext);}
"<=" {printf("RELOP %s\n", yytext);}
">" {printf("RELOP %s\n", yytext);}
">=" {printf("RELOP %s\n", yytext);}
"<>" {printf("RELOP %s\n", yytext);}
{id}        {printf("IDENTIFIER %s\n", yytext);}
{integer}   {printf("INTEGER %s\n", yytext);}
{decimal}   {printf("DECIMAL %s\n", yytext);}
{expnum}    {printf("EXPNUMBER %s\n", yytext);}
{str}       {printf("STRING %s\n", yytext);}
"." {printf("DOT\n");}
"," {printf("COMMA\n");}
":" {printf("COLON\n");} 
";" {printf("SEMICOLON\n");}
":=" {printf("ASSIGN\n");}
".." {printf("RANGE\n");}
"(" {printf("LPAR\n");}
")" {printf("RPAR\n");}
"[" {printf("LBRACKET\n");}
"]" {printf("RBRACKET\n");}
{error} {printf("ERROR(%d): Unrecognized Symbol \"%s\"\n", line, yytext);}
%%

void main() {
  int val;
  while ((val = yylex()) > 0) {
  }
}

