%{
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

#define YYPRINT

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" FILE *yyout;
 
void yyerror(const char *s);
%}

%token-table

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
  int ival;
  float fval;
  char *sval;
}

// define the constant-string tokens:
%token SNAZZLE TYPE
%token END

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%%

// the first rule defined is the highest-level rule, which in our
// case is just the concept of a whole "snazzle file":
snazzle:
  header template body_section footer { cout << "done with a snazzle file!" << endl; }
  ;
header:
  SNAZZLE FLOAT { cout << "reading a snazzle file version " << $2 << endl; }
  ;
template:
  typelines
  ;
typelines:
  typelines typeline
  | typeline
  ;
typeline:
  TYPE STRING { cout << "new defined snazzle type: " << $2 << endl; }
  ;
body_section:
  body_lines
  ;
body_lines:
  body_lines body_line
  | body_line
  ;
body_line:
  INT INT INT INT STRING { cout << "new snazzle: " << $1 << $2 << $3 << $4 << $5 << endl; }
  ;
footer:
  END
  ;

%%

main() {
  // open a file handle to a particular file:
  FILE *myfile = fopen("in.snazzle", "r");
  //FILE *outfile = fopen("out.snazzle", "w");
  FILE *outfile = freopen("out.snazzle", "w", stdout);
  // make sure it's valid:
  if (!myfile) {
    cout << "I can't open a.snazzle.file!" << endl;
    return -1;
  }
  if (!outfile) {
    cout << "I can't open out.snazzle.file!" << endl;
    return -1;
  }
  // set flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  yyout = outfile;
  // parse through the input until there is no more:
  do {
    yyparse();
  } while (!feof(yyin));
  fclose(myfile); 
  fclose(outfile); 
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}

/* Lookup literal names */
static int lookup(char *token_buffer) {
int i;
for (i = 0; i < YYNTOKENS; i++)
{ 
if (yytname[i] != 0
&& yytname[i][0] == '"'
&& !strncmp (yytname[i] + 1, token_buffer,
strlen (token_buffer))
&& yytname[i][strlen (token_buffer) + 1] == '"'
&& yytname[i][strlen (token_buffer) + 2] == 0) {
printf("---Match Success: %s, %d\n",token_buffer,i,yytname[i]);
yylval.sval=token_buffer;
return yytoknum[i];
}
}
printf("---Match Fail: %s\n",token_buffer);
yylval.sval=token_buffer;
return -1;
}
