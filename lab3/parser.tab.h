/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_COMMENT = 258,
     TOKEN_STR = 259,
     TOKEN_AND = 260,
     TOKEN_BEGIN = 261,
     TOKEN_FORWARD = 262,
     TOKEN_DIV = 263,
     TOKEN_DO = 264,
     TOKEN_ELSE = 265,
     TOKEN_END = 266,
     TOKEN_FOR = 267,
     TOKEN_FUNCTION = 268,
     TOKEN_IF = 269,
     TOKEN_ARRAY = 270,
     TOKEN_MOD = 271,
     TOKEN_NOT = 272,
     TOKEN_OF = 273,
     TOKEN_OR = 274,
     TOKEN_PROCEDURE = 275,
     TOKEN_PROGRAM = 276,
     TOKEN_RECORD = 277,
     TOKEN_THEN = 278,
     TOKEN_TO = 279,
     TOKEN_TYPE = 280,
     TOKEN_VAR = 281,
     TOKEN_WHILE = 282,
     TOKEN_PLUS = 283,
     TOKEN_MINUS = 284,
     TOKEN_MULTIPLY = 285,
     TOKEN_DIVIDE = 286,
     TOKEN_EQ = 287,
     TOKEN_LT = 288,
     TOKEN_LE = 289,
     TOKEN_GT = 290,
     TOKEN_GE = 291,
     TOKEN_NOTEQ = 292,
     TOKEN_ID = 293,
     TOKEN_INT = 294,
     TOKEN_DECIMAL = 295,
     TOKEN_EXPNUM = 296,
     TOKEN_DOT = 297,
     TOKEN_COMMAS = 298,
     TOKEN_COLON = 299,
     TOKEN_SEMICOLON = 300,
     TOKEN_ASSIGN = 301,
     TOKEN_RANGE = 302,
     TOKEN_LPAR = 303,
     TOKEN_RPAR = 304,
     TOKEN_LBRACKET = 305,
     TOKEN_RBRACKET = 306,
     UMINUS = 307,
     UPLUS = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 60 "parser.y"

  int ival;
  float fval;
  bool bval;
  char *sval;



/* Line 2068 of yacc.c  */
#line 112 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


