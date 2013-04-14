/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

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
extern "C" FILE *yyin; extern "C" int address;
extern "C" int funcSavedAddr;
extern "C" int procSavedAddr;
extern "C" int recSavedAddr;
extern "C" int arrSavedAddr;

// Lab3
extern "C++" stack<Env*> envs;
extern "C++" stack<int> offsets;
extern "C++" vector<Env*> allEnvs;
extern "C++" stack<vector<pair<string, TypeDesc*> >* > fieldListStack;
extern "C++" stack<TypeDesc*> arrayTypeStack;
extern "C" int recordSeq;
extern "C" int arraySeq;
extern "C++" stack<TypeDesc*> expTypeStack;
vector<TypeDesc*>* formalParamList;
//TypeDesc* varType = NULL;

void yyerror(const char *s);
static void lookup(char *token_buffer);
void addSymbol(const char *id, const char *type);
void addSymbol(const char *id, const string &type);
void addSymbol(const string &id, const char *type);
void addSymbol(const char* id, const int type);
void addSymbol(const string &id, const string &type);
vector<string> split(char *ids);
void fixAddress(int addr);
void freeFieldList(vector<pair<string, TypeDesc*> >* fl); 
bool checkTypeEquiv(TypeDesc* td1, TypeDesc* td2);

#define YYPRINT

map<string, pair<int, string> > symTable;
map<int, pair<string, string> > symTableIndexedByAddr;
string nilStr("nil");
char recordStr[] = "record";
char arrayStr[] = "array";
string rec(recordStr);
string arr(arrayStr);



/* Line 268 of yacc.c  */
#line 133 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


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

/* Line 293 of yacc.c  */
#line 64 "parser.y"

  int ival;
  float fval;
  bool bval;
  char *sval;



/* Line 293 of yacc.c  */
#line 231 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 243 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    14,    15,    17,    18,    20,    21,
      24,    27,    29,    32,    35,    37,    39,    42,    45,    47,
      49,    54,    59,    60,    70,    71,    83,    85,    87,    89,
      90,    96,   100,   103,   107,   111,   113,   115,   117,   119,
     121,   123,   124,   128,   133,   135,   140,   147,   148,   154,
     163,   165,   174,   175,   180,   182,   184,   185,   191,   195,
     197,   200,   203,   206,   207,   209,   211,   213,   215,   217,
     219,   222,   224,   228,   230,   232,   234,   238,   240,   242,
     244,   246,   248,   250,   252,   254,   256,   259,   263,   268,
     269,   273,   277,   282,   283,   285,   286,   290,   292,   296,
     298,   300
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    21,    38,    45,    56,    57,    58,    75,
      42,    -1,    59,    -1,    -1,    61,    -1,    -1,    63,    -1,
      -1,    25,    60,    -1,    60,    65,    -1,    65,    -1,    26,
      62,    -1,    62,    66,    -1,    66,    -1,    64,    -1,    64,
      67,    -1,    64,    69,    -1,    67,    -1,    69,    -1,    38,
      32,    84,    45,    -1,   104,    44,    84,    45,    -1,    -1,
      20,    38,    48,    72,    68,    49,    45,    71,    45,    -1,
      -1,    13,    38,    48,    72,    49,    44,    86,    70,    45,
      71,    45,    -1,    74,    -1,     7,    -1,    73,    -1,    -1,
      73,    45,   104,    44,    84,    -1,   104,    44,    84,    -1,
      57,    75,    -1,     6,    76,    11,    -1,    76,    45,    77,
      -1,    77,    -1,    78,    -1,    79,    -1,    82,    -1,    80,
      -1,    81,    -1,    -1,    99,    46,    90,    -1,    38,    48,
     102,    49,    -1,    75,    -1,    14,    90,    23,    77,    -1,
      14,    90,    23,    77,    10,    77,    -1,    -1,    27,    90,
      83,     9,    77,    -1,    12,    38,    46,    90,    24,    90,
       9,    77,    -1,    38,    -1,    15,    50,    89,    47,    89,
      51,    18,    84,    -1,    -1,    22,    85,    87,    11,    -1,
      38,    -1,    88,    -1,    -1,    88,    45,   104,    44,    84,
      -1,   104,    44,    84,    -1,    39,    -1,   105,    39,    -1,
      93,    91,    -1,    92,    93,    -1,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    32,    -1,   105,
      95,    -1,    95,    -1,    93,    94,    95,    -1,    28,    -1,
      29,    -1,    19,    -1,    95,    96,    97,    -1,    97,    -1,
      30,    -1,     8,    -1,    16,    -1,     5,    -1,    39,    -1,
       4,    -1,    99,    -1,    98,    -1,    17,    97,    -1,    48,
      90,    49,    -1,    38,    48,   102,    49,    -1,    -1,    38,
     100,   101,    -1,    42,    38,   101,    -1,    50,    90,    51,
     101,    -1,    -1,   103,    -1,    -1,   103,    43,    90,    -1,
      90,    -1,   104,    43,    38,    -1,    38,    -1,    28,    -1,
      29,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   142,   142,   143,   143,   144,   144,   146,
     148,   149,   151,   153,   154,   156,   158,   159,   160,   161,
     163,   290,   431,   430,   472,   470,   586,   586,   588,   591,
     602,   756,   917,   919,   921,   922,   924,   926,   926,   928,
     929,   930,   932,   954,  1025,  1026,  1027,  1029,  1028,  1037,
    1039,  1042,  1110,  1109,  1119,  1135,  1136,  1141,  1291,  1440,
    1441,  1443,  1445,  1495,  1497,  1501,  1505,  1509,  1513,  1517,
    1522,  1534,  1535,  1585,  1589,  1593,  1598,  1657,  1659,  1663,
    1667,  1671,  1676,  1681,  1685,  1691,  1692,  1701,  1703,  1792,
    1791,  1904,  1917,  1928,  1932,  1933,  1935,  1937,  1939,  1954,
    1959,  1959
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_COMMENT", "TOKEN_STR",
  "TOKEN_AND", "TOKEN_BEGIN", "TOKEN_FORWARD", "TOKEN_DIV", "TOKEN_DO",
  "TOKEN_ELSE", "TOKEN_END", "TOKEN_FOR", "TOKEN_FUNCTION", "TOKEN_IF",
  "TOKEN_ARRAY", "TOKEN_MOD", "TOKEN_NOT", "TOKEN_OF", "TOKEN_OR",
  "TOKEN_PROCEDURE", "TOKEN_PROGRAM", "TOKEN_RECORD", "TOKEN_THEN",
  "TOKEN_TO", "TOKEN_TYPE", "TOKEN_VAR", "TOKEN_WHILE", "TOKEN_PLUS",
  "TOKEN_MINUS", "TOKEN_MULTIPLY", "TOKEN_DIVIDE", "TOKEN_EQ", "TOKEN_LT",
  "TOKEN_LE", "TOKEN_GT", "TOKEN_GE", "TOKEN_NOTEQ", "TOKEN_ID",
  "TOKEN_INT", "TOKEN_DECIMAL", "TOKEN_EXPNUM", "TOKEN_DOT",
  "TOKEN_COMMAS", "TOKEN_COLON", "TOKEN_SEMICOLON", "TOKEN_ASSIGN",
  "TOKEN_RANGE", "TOKEN_LPAR", "TOKEN_RPAR", "TOKEN_LBRACKET",
  "TOKEN_RBRACKET", "UMINUS", "UPLUS", "$accept", "program",
  "groupTypeDefinitions", "groupVariableDeclarations",
  "groupSubprogramDeclarations", "typeDefinitions", "typeDefinitionList",
  "variableDeclarations", "variableDeclarationList",
  "subprogramDeclarations", "subprogramDeclarationList", "typeDefinition",
  "variableDeclaration", "procedureDeclaration", "$@1",
  "functionDeclaration", "$@2", "groupBlockForward", "formalParameterList",
  "formalParamSeq", "block", "compoundStatement", "statementSequence",
  "statement", "groupSimStruStatement", "simpleStatement",
  "assignmentStatement", "procedureStatement", "structuredStatement",
  "$@3", "type", "$@4", "resultType", "fieldList", "fieldListSeq",
  "constant", "expression", "groupRelOpSimExpr", "relationalOp",
  "simpleExpression", "addOp", "term", "mulOp", "factor",
  "functionReference", "variable", "$@5", "componentSelection",
  "actualParameterList", "expressionList", "identifierList", "sign", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      60,    60,    61,    62,    62,    63,    64,    64,    64,    64,
      65,    66,    68,    67,    70,    69,    71,    71,    72,    72,
      73,    73,    74,    75,    76,    76,    77,    78,    78,    79,
      79,    79,    80,    81,    82,    82,    82,    83,    82,    82,
      84,    84,    85,    84,    86,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    94,    94,    94,    95,    95,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    98,   100,
      99,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     0,     1,     0,     1,     0,     2,
       2,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       4,     4,     0,     9,     0,    11,     1,     1,     1,     0,
       5,     3,     2,     3,     3,     1,     1,     1,     1,     1,
       1,     0,     3,     4,     1,     4,     6,     0,     5,     8,
       1,     8,     0,     4,     1,     1,     0,     5,     3,     1,
       2,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     0,
       3,     3,     4,     0,     1,     0,     3,     1,     3,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     6,     3,     0,
       9,    11,     0,     8,     5,     0,    10,    99,    12,    14,
       0,     0,     0,     0,     7,    15,    18,    19,     0,    52,
      50,     0,    13,     0,     0,     0,     0,    41,     0,    16,
      17,     0,    56,    20,    98,     0,    29,    29,     0,     0,
       0,    89,    44,     0,    35,    36,    37,    39,    40,    38,
       0,     2,   100,   101,    59,     0,     0,     0,    55,     0,
      21,     0,    28,     0,    22,     0,    83,     0,    89,    82,
       0,     0,    63,    71,    77,    85,    84,     0,    47,    95,
      93,    33,    41,     0,     0,    60,    53,     0,     0,     0,
       0,     0,     0,     0,    86,    95,     0,    41,    75,    73,
      74,    69,    64,    65,    66,    67,    68,    61,     0,     0,
      81,    79,    80,    78,     0,    70,     0,    97,     0,    94,
       0,     0,    90,    34,    42,     0,     0,    58,     0,     0,
      31,     0,     0,     0,    87,    45,    62,    72,    76,    41,
      43,     0,    93,     0,     0,     0,    54,    24,     0,     6,
       0,    88,    41,    48,    96,    91,    93,     0,    57,     0,
      30,    27,     0,     0,    26,     0,    46,    92,    51,     6,
      32,    23,    41,     0,    49,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,   172,    23,     8,    10,    14,    18,    24,
      25,    11,    19,    26,   102,    27,   169,   173,    71,    72,
     174,    52,    53,    54,    55,    56,    57,    58,    59,   126,
      31,    42,   157,    67,    68,    65,   127,   117,   118,    82,
     119,    83,   124,    84,    85,    86,    90,   132,   128,   129,
      20,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -135
static const yytype_int16 yypact[] =
{
      -8,   -19,    24,   -17,  -135,    -3,    17,    10,  -135,    31,
      17,  -135,    53,    29,  -135,    -1,  -135,  -135,    53,  -135,
      25,    61,    62,    79,  -135,    29,  -135,  -135,    43,  -135,
    -135,    56,  -135,    64,    -1,    57,    59,    19,    66,  -135,
    -135,    55,    53,  -135,  -135,    58,    53,    53,    71,    12,
      12,    63,  -135,    -2,  -135,  -135,  -135,  -135,  -135,  -135,
      68,  -135,  -135,  -135,  -135,    65,    77,    93,    72,    44,
    -135,    69,    74,    46,  -135,    75,  -135,     6,    80,  -135,
      12,    87,    45,    22,  -135,  -135,  -135,     6,  -135,    12,
     -16,  -135,    19,    12,    55,  -135,  -135,    53,    -1,    76,
      53,    -1,    73,    12,  -135,    12,    81,    19,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,    12,     6,
    -135,  -135,  -135,  -135,     6,    22,   114,  -135,    82,    86,
      94,    12,  -135,  -135,  -135,    83,    52,  -135,    95,    54,
    -135,    90,   101,    88,  -135,   128,    47,    22,  -135,    19,
    -135,    12,   -16,    89,   121,    -1,  -135,  -135,    -1,    13,
      12,  -135,    19,  -135,  -135,  -135,   -16,    -1,  -135,    96,
    -135,  -135,    79,    97,  -135,   134,  -135,  -135,  -135,    13,
    -135,  -135,    19,    99,  -135,  -135
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   138,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,   137,   130,   125,  -135,   126,  -135,   -27,   106,  -135,
    -135,   -23,  -135,   -90,  -135,  -135,  -135,  -135,  -135,  -135,
     -31,  -135,  -135,  -135,  -135,    60,   -45,  -135,  -135,    37,
    -135,   -72,  -135,   -71,  -135,   -36,  -135,  -134,    51,  -135,
     -35,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    60,   133,    45,    81,    88,   104,    69,    66,    91,
      76,    73,    73,     1,    28,   125,    76,   145,   165,     3,
     171,    29,     6,    77,     4,    37,   130,   120,     5,    77,
     121,    48,   177,    49,   131,   106,    12,    30,   122,    12,
      62,    63,    21,    92,    78,    79,    50,   147,   134,    22,
      78,    79,   123,   148,    80,     9,    60,    51,   142,   163,
      80,    66,   136,    15,   108,   139,   108,   137,    33,    34,
     140,    60,   176,   109,   110,   109,   110,   111,   112,   113,
     114,   115,   116,    62,    63,    37,   153,    33,    98,    33,
     101,    17,   184,    41,    64,    33,   155,    33,   158,    35,
      36,    43,    44,    70,    96,    46,   164,    47,    61,    75,
     107,    89,    94,    60,    93,   175,    95,    97,    99,   100,
     138,   103,   141,   149,   168,   160,    60,   170,   105,   151,
     144,   150,   152,   156,   154,   159,   178,   161,   162,   167,
     166,   179,   181,   182,   185,    13,    60,    16,    32,   180,
      39,    40,   183,    74,   135,   146,   143
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-135))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      23,    37,    92,    34,    49,    50,    77,    42,    41,    11,
       4,    46,    47,    21,    15,    87,     4,   107,   152,    38,
       7,    22,    25,    17,     0,     6,    42,     5,    45,    17,
       8,    12,   166,    14,    50,    80,    26,    38,    16,    26,
      28,    29,    13,    45,    38,    39,    27,   119,    93,    20,
      38,    39,    30,   124,    48,    38,    92,    38,   103,   149,
      48,    94,    97,    32,    19,   100,    19,    98,    43,    44,
     101,   107,   162,    28,    29,    28,    29,    32,    33,    34,
      35,    36,    37,    28,    29,     6,   131,    43,    44,    43,
      44,    38,   182,    50,    39,    43,    44,    43,    44,    38,
      38,    45,    38,    45,    11,    48,   151,    48,    42,    38,
      23,    48,    47,   149,    46,   160,    39,    45,    49,    45,
      44,    46,    49,     9,   155,    24,   162,   158,    48,    43,
      49,    49,    38,    38,    51,    45,   167,    49,    10,    18,
      51,    45,    45,     9,    45,     7,   182,    10,    18,   172,
      25,    25,   179,    47,    94,   118,   105
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    55,    38,     0,    45,    25,    56,    59,    38,
      60,    65,    26,    57,    61,    32,    65,    38,    62,    66,
     104,    13,    20,    58,    63,    64,    67,    69,    15,    22,
      38,    84,    66,    43,    44,    38,    38,     6,    75,    67,
      69,    50,    85,    45,    38,    84,    48,    48,    12,    14,
      27,    38,    75,    76,    77,    78,    79,    80,    81,    82,
      99,    42,    28,    29,    39,    89,   105,    87,    88,   104,
      45,    72,    73,   104,    72,    38,     4,    17,    38,    39,
      48,    90,    93,    95,    97,    98,    99,   105,    90,    48,
     100,    11,    45,    46,    47,    39,    11,    45,    44,    49,
      45,    44,    68,    46,    97,    48,    90,    23,    19,    28,
      29,    32,    33,    34,    35,    36,    37,    91,    92,    94,
       5,     8,    16,    30,    96,    95,    83,    90,   102,   103,
      42,    50,   101,    77,    90,    89,   104,    84,    44,   104,
      84,    49,    90,   102,    49,    77,    93,    95,    97,     9,
      49,    43,    38,    90,    51,    44,    38,    86,    44,    45,
      24,    49,    10,    77,    90,   101,    51,    18,    84,    70,
      84,     7,    57,    71,    74,    90,    77,   101,    84,    45,
      75,    45,     9,    71,    77,    45
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 135 "parser.y"
    { cout << "program" << endl;
      string id((yyvsp[(2) - (8)].sval));
      symTable[id].first = 0;
      symTable[id].second = "nil";

    }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 148 "parser.y"
    { cout << "type_definition_more" << endl; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    { cout << "type_definition" << endl; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 153 "parser.y"
    { cout << "variable_declaration_more" << endl; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 154 "parser.y"
    {cout << "variable_declaration" << endl; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 158 "parser.y"
    { cout << "sub_program_declarations_more" << endl; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    { cout << "sub_program_declarations_more" << endl; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { cout << "sub_program_declarations" << endl; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 161 "parser.y"
    { cout << "sub_program_declarations" << endl; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 164 "parser.y"
    { cout << "type_definition" << endl;
      //vector<string> strs = split($3);
      string type((yyvsp[(3) - (4)].sval));
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        // Type is not literally named record or array.
        addSymbol((yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].sval));
        addSymbol((yyvsp[(3) - (4)].sval), nilStr);

        // Lab3. Address will be fixed later.
        string lexime((yyvsp[(1) - (4)].sval));
        if (envs.top()->getSymbol(lexime) != NULL) {
          if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
            cout << "Invalid use of keyword " << lexime << endl;
          else
            cout << "Duplicated type definition for " << lexime << endl;
        } else {
          if (!envs.empty()) {
            if (type.compare("integer") == 0 ||
                type.compare("string") == 0 ||
                type.compare("boolean") == 0) {
              TypeDesc* td = new TypeDesc(type);
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            } else {
              if (envs.top()->getSymbol(type) == NULL) {
                Env* envPtr = envs.top()->getPrevEnv();
                bool found = false;
                while (envPtr != NULL) {
                  if (envPtr->getSymbol(type) != NULL) {
                    found = true;
                    // Copy the type descriptor.
                    TypeDesc* tmpTd = envPtr->getSymbol(type)->getTypeDesc();
                    TypeDesc* td = new TypeDesc(*tmpTd);
                    Symbol* sym = new Symbol(lexime, 0, td);
                    envs.top()->setSymbol(lexime, sym);
                    break;
                  }
                  envPtr = envPtr->getPrevEnv();
                }
                if (!found) {
                  cout << "Error: type " << type << " not defined" << endl;
                  
                  // Add this invalid type to the symbol table.
                  TypeDesc* invalidTd = new TypeDesc("invalid");
                  Symbol* sym = new Symbol(type, 0, invalidTd);
                  envs.top()->setSymbol(type, sym);
                  // Add the defined type to the symbol table with invalid type. 
                  TypeDesc* td = new TypeDesc(*invalidTd);
                  sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                }
              } else {
                TypeDesc* td = envs.top()->getSymbol(type)->getTypeDesc();
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
              }
            }          
          }
        }
      } else if (type.compare(rec) == 0) {
        // Type is record.
        string id((yyvsp[(1) - (4)].sval));
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = recSavedAddr;
          symTable[id].second = string((yyvsp[(3) - (4)].sval)); 
        } else {
          if (symTable[id].first > recSavedAddr) {
            int addr = symTable[id].first;
            fixAddress(addr);
            symTable[id].first = recSavedAddr;
          } else {
            fixAddress(recSavedAddr);
          }
          symTable[id].second = string((yyvsp[(3) - (4)].sval)); 
        }
        
        // Lab3
        string lexime((yyvsp[(1) - (4)].sval));
        if (envs.top()->getSymbol(lexime) != NULL) {
          if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
            cout << "Invalid use of keyword " << lexime << endl;
          else
            cout << "Duplicated type definition for " << lexime << endl;
        } else {
          TypeDesc* td = new TypeDesc("record", fieldListStack.top());
          Symbol* sym = new Symbol(lexime, 0, td);
          envs.top()->setSymbol(lexime, sym);
        }
        //freeFieldList(fieldListStack.top());
        fieldListStack.pop();
      } else {
        // Type is array.
        string id((yyvsp[(1) - (4)].sval));
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = arrSavedAddr;
          symTable[id].second = type;
          
        } else {
          if (symTable[id].first > arrSavedAddr) {
            int addr = symTable[id].first;
            fixAddress(addr);
            symTable[id].first = arrSavedAddr;
          } else {
            fixAddress(arrSavedAddr);
          }
          symTable[id].second = type;
        }
        
        // Lab3
        if (!envs.empty()) {
          string lexime((yyvsp[(1) - (4)].sval));
          if (envs.top()->getSymbol(lexime) != NULL) {
            if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
              cout << "Invalid use of keyword " << lexime << endl;
            else
              cout << "Duplicated type definition for " << lexime << endl;
          } else {
            TypeDesc* td = arrayTypeStack.top();
            Symbol* sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);
            arrayTypeStack.pop();
          }
        }
      }
    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 291 "parser.y"
    { cout << "variable_declaration" << endl;
      vector<string> ids = split((yyvsp[(1) - (4)].sval));
      //vector<string> strs = split($3);
      string type((yyvsp[(3) - (4)].sval));
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, type);
      }
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol(type, nilStr);
        }
      }

      // Lab3. Address will be fixed later.
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        // Type is not literally named record or array.
        if (!envs.empty()) {
          if (type.compare("integer") == 0 ||
              type.compare("string") == 0 ||
              type.compare("boolean") == 0) {
            for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
              string lexime(*it);
              if (envs.top()->getSymbol(lexime) != NULL) {
                if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                  cout << "Invalid use of keyword " << lexime << endl;
                else
                  cout << "Duplicated variable declaration for " << lexime << endl;
              } else {
                TypeDesc* td = new TypeDesc(type);
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
              }
            }
          } else {
            if (envs.top()->getSymbol(type) == NULL) {
              Env* envPtr = envs.top()->getPrevEnv();
              bool found = false; while (envPtr != NULL) {
                if (envPtr->getSymbol(type) != NULL) {
                  found = true;
                  for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                    string lexime(*it);
                    if (envs.top()->getSymbol(lexime) != NULL) {
                      if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                        cout << "Invalid use of keyword " << lexime << endl;
                      else
                        cout << "Duplicated variable definition for " << lexime << endl;
                    } else {
                      TypeDesc* td = new TypeDesc(*(envPtr->getSymbol(type)->getTypeDesc()));
                      Symbol* sym = new Symbol(lexime, 0, td);
                      envs.top()->setSymbol(lexime, sym);
                    }
                  }
                  break;
                }
                envPtr = envPtr->getPrevEnv();
              }
              if (!found) {
                cout << "Error: type " << type << " not defined" << endl;

                // Add this invalid type to the symbol table.
                TypeDesc* invalidTd = new TypeDesc("invalid");
                Symbol* sym = new Symbol(type, 0, invalidTd);
                envs.top()->setSymbol(type, sym);

                // Add the declared variables to the symbol table with invalid type. 
                for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                  string lexime(*it);
                  if (envs.top()->getSymbol(lexime) != NULL) {
                    if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                      cout << "Invalid use of keyword " << lexime << endl;
                    else
                      cout << "Duplicated variable definition for " << lexime << endl;
                  } else {
                    TypeDesc* td = new TypeDesc(*invalidTd);
                    Symbol* sym = new Symbol(lexime, 0, td);
                    envs.top()->setSymbol(lexime, sym);
                  }
                }
              }
            } else {
              for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                string lexime(*it);
                if (envs.top()->getSymbol(lexime) != NULL) {
                  if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                    cout << "Invalid use of keyword " << lexime << endl;
                  else
                    cout << "Duplicated variable definition for " << lexime << endl;
                } else {
                  TypeDesc* td = new TypeDesc(*(envs.top()->getSymbol(type)->getTypeDesc()));
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                }
              }
            }
          } 
        }
      } else if (type.compare(rec) == 0) {
        // Type is record.
        
        // Lab3
        for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
          string lexime(*it);
          if (envs.top()->getSymbol(lexime) != NULL) {
            if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
              cout << "Invalid use of keyword " << lexime << endl;
            else
              cout << "Duplicated variable definition for " << lexime << endl;
          } else {
            TypeDesc* td = new TypeDesc("record", fieldListStack.top());
            Symbol* sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);
          }
        }
        //delete fieldListStack.top();
        //freeFieldList(fieldListStack.top());
        fieldListStack.pop();
      } else {
        // Type is array.

        // Lab3
        if (!envs.empty()) {
          for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
            string lexime(*it);
            if (envs.top()->getSymbol(lexime) != NULL) {
              if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                cout << "Invalid use of keyword " << lexime << endl;
              else
                cout << "Duplicated variable definition for " << lexime << endl;
            } else {
              TypeDesc* td = arrayTypeStack.top();
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            }
          }
          arrayTypeStack.pop();
        }
      }
    }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 431 "parser.y"
    { 
      string id((yyvsp[(2) - (4)].sval));
      if (symTable.find(id) != symTable.end()) {
        int addr = symTable[id].first;
        fixAddress(addr);
      }
      symTable[id].first = procSavedAddr;
      ostringstream convert;
      convert << (yyvsp[(4) - (4)].ival);
      symTable[id].second = convert.str(); 

      // Lab3
      string lexime((yyvsp[(2) - (4)].sval));
      // Add to the local symbol table.
      TypeDesc* td = new TypeDesc("procedure", formalParamList, NULL);
      Symbol* sym = new Symbol(lexime, 0, td);
      envs.top()->setSymbol(lexime, sym);

      // Add to the global symbol table.
      Env* globalEnv = envs.top()->getPrevEnv();
      vector<TypeDesc*>* copyOfFormalParamList;
      if (formalParamList != NULL) {
        copyOfFormalParamList = new vector<TypeDesc*>();
        for (int i = 0; i < formalParamList->size(); ++i) {
          TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
          copyOfFormalParamList->push_back(oneTd);
        }
      } else {
        copyOfFormalParamList = NULL;
      }
      td = new TypeDesc("procedure", copyOfFormalParamList, NULL);
      sym = new Symbol(lexime, 0, td);
      globalEnv->setSymbol(lexime, sym);
      
    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 467 "parser.y"
    { cout << "procedure_declaration" << endl; envs.pop(); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 472 "parser.y"
    { 
      string id((yyvsp[(2) - (7)].sval));
      if (symTable.find(id) != symTable.end()) {
        if (symTable[id].first > funcSavedAddr) {
          int addr = symTable[id].first;
          fixAddress(addr);
          symTable[id].first = funcSavedAddr;
          ostringstream convert;
          convert << (yyvsp[(4) - (7)].ival);
          symTable[id].second = convert.str();
        } else {
          fixAddress(funcSavedAddr);
          ostringstream convert;
          convert << (yyvsp[(4) - (7)].ival);
          symTable[id].second = convert.str();
        }
      } else {
        symTable[id].first = funcSavedAddr;
        ostringstream convert;
        convert << (yyvsp[(4) - (7)].ival);
        symTable[id].second = convert.str();
      }

      // Lab3
      string lexime((yyvsp[(2) - (7)].sval));
      string resultType((yyvsp[(7) - (7)].sval));

      // Type is not literally named record or array.
      if (!envs.empty()) {
        if (resultType.compare("integer") == 0 ||
            resultType.compare("string") == 0 ||
            resultType.compare("boolean") == 0) {
          // Add to the local symbol table.
          TypeDesc* rt = new TypeDesc(resultType);
          TypeDesc* td = new TypeDesc("function", formalParamList, rt);
          Symbol* sym = new Symbol(lexime, 0, td);
          envs.top()->setSymbol(lexime, sym);

          // Add to the global symbol table.
          Env* globalEnv = envs.top()->getPrevEnv();
          vector<TypeDesc*>* copyOfFormalParamList;
          if (formalParamList != NULL) {
            copyOfFormalParamList = new vector<TypeDesc*>();
            for (int i = 0; i < formalParamList->size(); ++i) {
              TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
              copyOfFormalParamList->push_back(oneTd);
            }
          } else {
            copyOfFormalParamList = NULL;
          }
          rt = new TypeDesc(resultType);
          td = new TypeDesc("function", copyOfFormalParamList, rt);
          sym = new Symbol(lexime, 0, td);
          globalEnv->setSymbol(lexime, sym);
        } else {
          if (envs.top()->getPrevEnv()->getSymbol(resultType) == NULL) {
            cout << "Error: type " << resultType << " not defined" << endl;
            // Add the invalid result type to the global symbol table.
            Env* globalEnv = envs.top()->getPrevEnv();
            TypeDesc* invalidTd = new TypeDesc("invalid");
            Symbol* sym = new Symbol(resultType, 0, invalidTd); 
            globalEnv->setSymbol(resultType, sym);

            // Add to the local symbol table.
            TypeDesc* rt = new TypeDesc(*invalidTd);
            TypeDesc* td = new TypeDesc("function", formalParamList, rt);
            sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);

            // Add to the global symbol table.
            vector<TypeDesc*>* copyOfFormalParamList;
            if (formalParamList != NULL) {
              copyOfFormalParamList = new vector<TypeDesc*>();
              for (int i = 0; i < formalParamList->size(); ++i) {
                TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
                copyOfFormalParamList->push_back(oneTd);
              }
            } else {
              copyOfFormalParamList = NULL;
            }
            rt = new TypeDesc(*invalidTd);
            td = new TypeDesc("function", copyOfFormalParamList, rt);
            sym = new Symbol(lexime, 0, td);
            globalEnv->setSymbol(lexime, sym);
          } else {
            // Add to the local symbol table.
            TypeDesc* rt = new TypeDesc(*(envs.top()->getPrevEnv()->getSymbol(resultType)->getTypeDesc()));
            TypeDesc* td = new TypeDesc("function", formalParamList, rt);
            Symbol* sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);

            // Add to the global symbol table.
            Env* globalEnv = envs.top()->getPrevEnv();
            vector<TypeDesc*>* copyOfFormalParamList;
            if (formalParamList != NULL) {
              copyOfFormalParamList = new vector<TypeDesc*>();
              for (int i = 0; i < formalParamList->size(); ++i) {
                TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
                copyOfFormalParamList->push_back(oneTd);
              }
            } else {
              copyOfFormalParamList = NULL;
            }
            rt = new TypeDesc(*(envs.top()->getPrevEnv()->getSymbol(resultType)->getTypeDesc()));
            td = new TypeDesc("function", copyOfFormalParamList, rt);
            sym = new Symbol(lexime, 0, td);
            globalEnv->setSymbol(lexime, sym);
          }
        } 
      }
    }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 584 "parser.y"
    { cout << "function_declaration" << endl; envs.pop(); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 588 "parser.y"
    { cout << "formal_parameter_list" << endl; (yyval.ival) = (yyvsp[(1) - (1)].ival);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 591 "parser.y"
    { cout << "formal_parameter_list_empty" << endl; 
      (yyval.ival) = 0; 

      // Lab3
      Env* prevEnv = envs.top();
      Env* env = new Env(prevEnv);
      envs.push(env);
      allEnvs.push_back(env);
      formalParamList = NULL;
    }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 603 "parser.y"
    { cout << "identifier_lists_more" << endl;
      vector<string> ids = split((yyvsp[(3) - (5)].sval));
      //vector<string> strs = split($5);
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, (yyvsp[(5) - (5)].sval));
      }
      string type((yyvsp[(5) - (5)].sval));
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol(type, nilStr);
        }
      }
      (yyval.ival) = (yyvsp[(1) - (5)].ival) + ids.size();

      //vector<string> strs = split($5);
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        // Type is not literally named record or array.
        if (!envs.empty()) {
          if (type.compare("integer") == 0 ||
              type.compare("string") == 0 ||
              type.compare("boolean") == 0) {
            for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
              string lexime(*it);
              if (envs.top()->getSymbol(lexime) != NULL) {
                cout << "Error: Duplicated decaration of parameter "
                    << lexime << " for function" << endl;
                TypeDesc* td = new TypeDesc("invalid");
                formalParamList->push_back(td);
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
              } else {
                TypeDesc* td = new TypeDesc(type);
                formalParamList->push_back(td);
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
              }
            }
          } else {
            if (envs.top()->getSymbol(type) == NULL) {
              Env* envPtr = envs.top()->getPrevEnv();
              bool found = false;
              while (envPtr != NULL) {
                if (envPtr->getSymbol(type) != NULL) {
                  found = true;
                  for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                    string lexime(*it);
                    if (envs.top()->getSymbol(lexime) != NULL) {
                      cout << "Error: Duplicated decaration of parameter "
                          << lexime << " for function" << endl;
                      TypeDesc* td = new TypeDesc("invalid");
                      formalParamList->push_back(td);
                      Symbol* sym = new Symbol(lexime, 0, td);
                      envs.top()->setSymbol(lexime, sym);
                    } else {
                      TypeDesc* td = new TypeDesc(*(envPtr->getSymbol(type)->getTypeDesc()));
                      formalParamList->push_back(td);
                      Symbol* sym = new Symbol(lexime, 0, td);
                      envs.top()->setSymbol(lexime, sym);
                    }
                  }
                  break;
                }
                envPtr = envPtr->getPrevEnv();
              }
              if (!found) {
                cout << "Error: type " << type << " not defined" << endl;

                // Add this invalid type to the symbol table.
                TypeDesc* invalidTd = new TypeDesc("invalid");
                Symbol* sym = new Symbol(type, 0, invalidTd);
                envs.top()->setSymbol(type, sym);

                // Add the defined parameters to the symbol table with invalid type. 
                for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                  string lexime(*it);
                  if (envs.top()->getSymbol(lexime) != NULL) {
                    cout << "Error: Duplicated decaration of parameter "
                        << lexime << " for function" << endl;
                  }
                  TypeDesc* td = new TypeDesc(*invalidTd);
                  formalParamList->push_back(td);
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                }
              }
            } else {
              for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                string lexime(*it);
                if (envs.top()->getSymbol(lexime) != NULL) {
                  cout << "Error: Duplicated decaration of parameter "
                      << lexime << " for function" << endl;
                  TypeDesc* td = new TypeDesc("invalid");
                  formalParamList->push_back(td);
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                } else {
                  TypeDesc* td = new TypeDesc(*(envs.top()->getSymbol(type)->getTypeDesc()));
                  formalParamList->push_back(td);
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                }
              }
            }
          } 
        }
      } else if (type.compare(rec) == 0) {
        // Type is record.
        
        // Lab3
        for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
          string lexime(*it);
          if (envs.top()->getSymbol(lexime) != NULL) {
            cout << "Error: Duplicated decaration of parameter "
                << lexime << " for function" << endl;
            TypeDesc* td = new TypeDesc("invalid");
            formalParamList->push_back(td);
            Symbol* sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);
          } else {
            TypeDesc* td = new TypeDesc("record", fieldListStack.top());
            formalParamList->push_back(td);
            Symbol* sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);
          }
        }
        //delete fieldListStack.top();
        //freeFieldList(fieldListStack.top());
        fieldListStack.pop();
      } else {
        // Type is array.

        // Lab3
        if (!envs.empty()) {
          for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
            string lexime(*it);
            if (envs.top()->getSymbol(lexime) != NULL) {
              cout << "Error: Duplicated decaration of parameter "
                  << lexime << " for function" << endl;
              TypeDesc* td = new TypeDesc("invalid");
              formalParamList->push_back(td);
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            } else {
              TypeDesc* td = arrayTypeStack.top();
              formalParamList->push_back(td);
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            }
          }
          arrayTypeStack.pop();
        }
      }
    }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 757 "parser.y"
    { cout << "identifier_lists" << endl;
        vector<string> ids = split((yyvsp[(1) - (3)].sval));
        for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
          addSymbol(*it, (yyvsp[(3) - (3)].sval));
        }
        string type((yyvsp[(3) - (3)].sval));
        if (type.compare(rec) != 0 && type.compare(arr) !=0) {
          if (symTable.find(type) == symTable.end()) {
            addSymbol((yyvsp[(3) - (3)].sval), nilStr);
          }
        }
        (yyval.ival) = ids.size();

        // Lab3. Address will be fixed later.
        Env* prevEnv = envs.top();
        Env* env = new Env(prevEnv);
        envs.push(env);
        allEnvs.push_back(env);
        formalParamList = new vector<TypeDesc*>();

        //vector<string> strs = split($3);
        if (type.compare(rec) != 0 && type.compare(arr) !=0) {
          // Type is not literally named record or array.
          if (!envs.empty()) {
            if (type.compare("integer") == 0 ||
                type.compare("string") == 0 ||
                type.compare("boolean") == 0) {
              for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                string lexime(*it);
                if (envs.top()->getSymbol(lexime) != NULL) {
                  cout << "Error: Duplicated decaration of parameter "
                      << lexime << " for function" << endl;
                  TypeDesc* td = new TypeDesc("invalid");
                  formalParamList->push_back(td);
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                } else {
                  TypeDesc* td = new TypeDesc(type);
                  formalParamList->push_back(td);
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                }
              }
            } else {
              if (envs.top()->getSymbol(type) == NULL) {
                Env* envPtr = envs.top()->getPrevEnv();
                bool found = false;
                while (envPtr != NULL) {
                  if (envPtr->getSymbol(type) != NULL) {
                    found = true;
                    for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                      string lexime(*it);
                      if (envs.top()->getSymbol(lexime) != NULL) {
                        cout << "Error: Duplicated decaration of parameter "
                            << lexime << " for function" << endl;
                        TypeDesc* td = new TypeDesc("invalid");
                        formalParamList->push_back(td);
                        Symbol* sym = new Symbol(lexime, 0, td);
                        envs.top()->setSymbol(lexime, sym);
                      } else {
                        TypeDesc* td = new TypeDesc(*(envPtr->getSymbol(type)->getTypeDesc()));
                        formalParamList->push_back(td);
                        Symbol* sym = new Symbol(lexime, 0, td);
                        envs.top()->setSymbol(lexime, sym);
                      }
                    }
                    break;
                  }
                  envPtr = envPtr->getPrevEnv();
                }
                if (!found) {
                  cout << "Error: type " << type << " not defined" << endl;

                  // Add this invalid type to the symbol table.
                  TypeDesc* invalidTd = new TypeDesc("invalid");
                  Symbol* sym = new Symbol(type, 0, invalidTd);
                  envs.top()->setSymbol(type, sym);

                  // Add the defined parameters to the symbol table with invalid type. 
                  for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                    string lexime(*it);
                    if (envs.top()->getSymbol(lexime) != NULL) {
                      cout << "Error: Duplicated decaration of parameter "
                          << lexime << " for function" << endl;
                    }
                    TypeDesc* td = new TypeDesc(*invalidTd);
                    formalParamList->push_back(td);
                    Symbol* sym = new Symbol(lexime, 0, td);
                    envs.top()->setSymbol(lexime, sym);
                  }
                }
              } else {
                for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                  string lexime(*it);
                  if (envs.top()->getSymbol(lexime) != NULL) {
                    cout << "Error: Duplicated decaration of parameter "
                        << lexime << " for function" << endl;
                    TypeDesc* td = new TypeDesc("invalid");
                    formalParamList->push_back(td);
                    Symbol* sym = new Symbol(lexime, 0, td);
                    envs.top()->setSymbol(lexime, sym);
                  } else {
                    TypeDesc* td = new TypeDesc(*(envs.top()->getSymbol(type)->getTypeDesc()));
                    formalParamList->push_back(td);
                    Symbol* sym = new Symbol(lexime, 0, td);
                    envs.top()->setSymbol(lexime, sym);
                  }
                }
              }
            } 
          }
        } else if (type.compare(rec) == 0) {
          // Type is record.
          
          // Lab3
          for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
            string lexime(*it);
            if (envs.top()->getSymbol(lexime) != NULL) {
              cout << "Error: Duplicated decaration of parameter "
                  << lexime << " for function" << endl;
              TypeDesc* td = new TypeDesc("invalid");
              formalParamList->push_back(td);
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            } else {
              TypeDesc* td = new TypeDesc("record", fieldListStack.top());
              formalParamList->push_back(td);
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            }
          }
          //delete fieldListStack.top();
          //freeFieldList(fieldListStack.top());
          fieldListStack.pop();
        } else {
          // Type is array.

          // Lab3
          if (!envs.empty()) {
            for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
              string lexime(*it);
              if (envs.top()->getSymbol(lexime) != NULL) {
                cout << "Error: Duplicated decaration of parameter "
                    << lexime << " for function" << endl;
                TypeDesc* td = new TypeDesc("invalid");
                formalParamList->push_back(td);
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
              } else {
                TypeDesc* td = arrayTypeStack.top();
                formalParamList->push_back(td);
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
              }
            }
            arrayTypeStack.pop();
          }
        }
      }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 917 "parser.y"
    { cout << "block" << endl; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 919 "parser.y"
    { cout << "compound_statement" << endl; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 921 "parser.y"
    { cout << "statement_sequence_more" << endl; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 922 "parser.y"
    { cout << "statement_sequence" << endl; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 924 "parser.y"
    { cout << "statement" << endl; }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 928 "parser.y"
    { cout << "simple_statement" << endl; }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 929 "parser.y"
    { cout << "simple_statement" << endl; }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 930 "parser.y"
    { cout << "simple_statement_empty" << endl; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 932 "parser.y"
    { cout << "assignment_statement" << endl;
      TypeDesc* td2 = expTypeStack.top();
      expTypeStack.pop();
      TypeDesc* td1 = expTypeStack.top();
      expTypeStack.pop();
      if (checkTypeEquiv(td1, td2)) {
        if (td1->getType().compare("invalid") != 0 &&
            td2->getType().compare("invalid") != 0) {
          TypeDesc* resultTd = new TypeDesc(*td1);
          expTypeStack.push(resultTd);
        } else {
          TypeDesc* resultTd = new TypeDesc("invalid");
          expTypeStack.push(resultTd);
        }
      } else {
        cout << "Error: types not equivalent for assignment operation, found "
            << td1->getType() << " and " << td2->getType() << endl;
        TypeDesc* resultTd = new TypeDesc("invalid");
        expTypeStack.push(resultTd);
      }
    }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 955 "parser.y"
    { cout << "procedure_statement" << endl;
      string id((yyvsp[(1) - (4)].sval));
      if (symTable.find(id) == symTable.end()) {
        addSymbol((yyvsp[(1) - (4)].sval), nilStr);
      }

      // Lab3
      int numOfParams = (yyvsp[(3) - (4)].ival);
      string procName((yyvsp[(1) - (4)].sval));
      TypeDesc* procTd = NULL;
      if (envs.top()->getSymbol(procName) == NULL) {
        Env* envPtr = envs.top()->getPrevEnv();
        while (envPtr != NULL) {
          if (envPtr->getSymbol(procName) != NULL) {
            procTd = envPtr->getSymbol(procName)->getTypeDesc();
            break;
          }
          envPtr = envPtr->getPrevEnv();
        }
      } else {
        procTd = envs.top()->getSymbol(procName)->getTypeDesc();
      }

      if (procTd != NULL) {
        if (procTd->getType().compare("procedure") != 0) {
          cout << "Error: " << procName << " is not a procedure" << endl;
          for (int i = 0; i < numOfParams; ++i) {
            expTypeStack.pop();
          }
        } else {
          // Check if the actual parameter list matches the function's
          // formal parameter list.
          if (numOfParams == procTd->getNumOfFormalParams()) {
            for (int i = numOfParams - 1; i >= 0; --i) {
              TypeDesc* td = expTypeStack.top();
              expTypeStack.pop();
              TypeDesc* formalParamTd = procTd->getNthFormalParamType(i);
              if (!checkTypeEquiv(td, formalParamTd)) {
                cout << "Error: Procedure " << procName
                    << "'s parameter type not matched, expected "
                    << formalParamTd->getType() << ", given "
                    << td->getType() << endl;
                // Pop the not checked actual parameters out of the expression
                // type stack;
                --i;
                while (i >= 0) {
                  expTypeStack.pop();
                  --i;
                }
              }
            }
          } else {
            cout << "Error: Procedure " << procName
                << "'s parameters number not matching!"
                <<" Expected " << procTd->getNumOfFormalParams() << ", given "
                << numOfParams << endl;
            for (int i = 0; i < numOfParams; ++i) {
              expTypeStack.pop();
            }
          }
        }
      } else {
        // Procedure hasn't been declared.
        cout << "Error: Procedure " << procName << " hasn't been declared" << endl;
        for (int i = 0; i < numOfParams; ++i) {
          expTypeStack.pop();
        }
      }
    }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 1025 "parser.y"
    { cout << "compound_statement" << endl; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 1026 "parser.y"
    { cout << "if_statement" << endl; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 1027 "parser.y"
    { cout << "ifelse_statement" << endl; }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 1029 "parser.y"
    {
        if (expTypeStack.top()->getType().compare("boolean") != 0) {
          cout << "Error: While construct expects boolean expression, "
              << expTypeStack.top()->getType() << " found" << endl;
        }
        expTypeStack.pop();
      }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 1036 "parser.y"
    { cout << "while_statement" << endl; }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 1037 "parser.y"
    { cout << "for_statement" << endl; }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 1039 "parser.y"
    { cout << "type_ID" << endl; //addSymbol($1, nilStr);
                 (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
                 strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 1043 "parser.y"
    { cout << "type_array" << endl;
        (yyval.sval) = (char*) malloc(strlen(arrayStr) + 1);;
        strcpy((yyval.sval), arrayStr);

        string arrayType((yyvsp[(8) - (8)].sval));
        // The array's element type is not record or array.
        if (arrayType.compare(rec) != 0 &&
            arrayType.compare(arr) != 0) {
          if (symTable.find(arrayType) == symTable.end()) {
            addSymbol(arrayType, nilStr);
          }
        }

        // Lab3
        int lower = (yyvsp[(3) - (8)].ival);
        int upper = (yyvsp[(5) - (8)].ival);
        if (arrayType.compare(rec) != 0 &&
            arrayType.compare(arr) != 0) {
          // Array's element type is not literally named record or array.
          if (arrayType.compare("integer") == 0 ||
              arrayType.compare("string") == 0 ||
              arrayType.compare("boolean") == 0) {
            // Array's element type is a primitive type.
            TypeDesc* arrayEleType = new TypeDesc(arrayType);
            TypeDesc* td = new TypeDesc("array", lower, upper, arrayEleType);
            arrayTypeStack.push(td);
          } else {
            // Array's element type is some customed defined type.
            if (envs.top()->getSymbol(arrayType) == NULL) {
              Env* envPtr = envs.top()->getPrevEnv();
              bool found = false;
              while (envPtr != NULL) {
                if (envPtr->getSymbol(arrayType) != NULL) {
                  found = true;
                  TypeDesc* arrayEleType = new TypeDesc(*(envPtr->getSymbol(arrayType)->getTypeDesc()));
                  TypeDesc* td = new TypeDesc("array", lower, upper, arrayEleType);
                  arrayTypeStack.push(td);
                  break;
                }
                envPtr = envPtr->getPrevEnv();
              }
              if (!found) {
                cout << "Error: type " << arrayType << " undefined" << endl;
              }
            } else {
              TypeDesc* arrayEleType = new TypeDesc(*(envs.top()->getSymbol(arrayType)->getTypeDesc()));
              TypeDesc* td = new TypeDesc("array", lower, upper, arrayEleType);
              arrayTypeStack.push(td);
            }
          } 
        } else if (arrayType.compare(rec) == 0) {
          // Array's element type is record.
          TypeDesc* arrayEleType = new TypeDesc("record", fieldListStack.top());
          TypeDesc* td = new TypeDesc("array", lower, upper, arrayEleType);
          arrayTypeStack.push(td);
          //delete fieldListStack.top();
          //freeFieldList(fieldListStack.top());
          fieldListStack.pop();
        } else {
          // Array's element type is array.
          TypeDesc* arrayEleType = arrayTypeStack.top();
          TypeDesc* td = new TypeDesc("array", lower, upper, arrayEleType);
          arrayTypeStack.pop();
          arrayTypeStack.push(td);
        }
      }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 1110 "parser.y"
    {
        vector<pair<string, TypeDesc*> >* fieldList = new vector<pair<string, TypeDesc*> >;
        fieldListStack.push(fieldList);
      }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 1115 "parser.y"
    { cout << "type_record" << endl;
        (yyval.sval) = (char*) malloc(strlen(recordStr) + 1);;
        strcpy((yyval.sval), recordStr); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1119 "parser.y"
    { cout << "result_type" << endl;
    (yyval.sval) = (yyvsp[(1) - (1)].sval);
    string id((yyvsp[(1) - (1)].sval));
    if (symTable.find(id) == symTable.end()) {
      addSymbol((yyvsp[(1) - (1)].sval), nilStr);
    };

    // Lab3
    /*
    Env* globalEnv = envs.top()->getPrevEnv();
    string lexime($1);
    if (globalEnv->getSymbol(lexime) == NULL) {
      
    }*/
    }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 1135 "parser.y"
    { cout << "field_list" << endl; }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 1136 "parser.y"
    { cout << "field_list_empty" << endl;
        //vector<pair<string, TypeDesc*> >* fieldList = NULL;
        //fieldListStack.push(fieldList);
      }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 1142 "parser.y"
    { cout << "identifier_lists_more" << endl;
      vector<string> ids = split((yyvsp[(3) - (5)].sval));
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, (yyvsp[(5) - (5)].sval));
      }
      string type((yyvsp[(5) - (5)].sval));
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol((yyvsp[(5) - (5)].sval), nilStr);
        }
      }
      
      // Lab3
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        // Lab3. Address will be fixed later.
        if (!envs.empty()) {
          if (type.compare("integer") == 0 ||
              type.compare("string") == 0 ||
              type.compare("boolean") == 0) {
            for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
              string lexime(*it);
              if (envs.top()->getSymbol(lexime) != NULL) {
                if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                  cout << "Invalid use of keyword " << lexime << endl;
                else
                  cout << "Duplicated variable declaration for " << lexime << endl;
              } else {
                TypeDesc* td = new TypeDesc(type);
                fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                //Symbol* sym = new Symbol(lexime, 0, td);
                //envs.top()->setSymbol(lexime, sym);
              }
            }
          } else {
            if (envs.top()->getSymbol(type) == NULL) {
              Env* envPtr = envs.top()->getPrevEnv();
              bool found = false;
              while (envPtr != NULL) {
                if (envPtr->getSymbol(type) != NULL) {
                  found = true;
                  for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                    string lexime(*it);
                    if (envs.top()->getSymbol(lexime) != NULL) {
                      if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                        cout << "Invalid use of keyword " << lexime << endl;
                      else
                        cout << "Duplicated variable declaration for " << lexime << endl;
                    } else {
                      TypeDesc* td = new TypeDesc(*(envPtr->getSymbol(type)->getTypeDesc()));
                      fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                      //Symbol* sym = new Symbol(lexime, 0, td);
                      //envs.top()->setSymbol(lexime, sym);
                    }
                  }
                  break;
                }
                envPtr = envPtr->getPrevEnv();
              }
              if (!found) {
                cout << "Error: type " << type << " not defined" << endl;

                // Add this invalid type to the symbol table? Or not?
                //TypeDesc* invalidTd = new TypeDesc("invalid");
                //Symbol* sym = new Symbol(strs[0], 0, invalidTd);
                //envs.top()->setSymbol(strs[0], sym);

                // Add the defined identifier of invalid type to the fieldList of the record. 
                for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                  string lexime(*it);
                  if (envs.top()->getSymbol(lexime) != NULL) {
                    if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                      cout << "Invalid use of keyword " << lexime << endl;
                    else
                      cout << "Duplicated variable declaration for " << lexime << endl;
                  } else {
                    TypeDesc* td = new TypeDesc("invalid");
                    fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                    //Symbol* sym = new Symbol(lexime, 0, td);
                    //envs.top()->setSymbol(lexime, sym);
                  }
                }
              }
            } else {
              for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                string lexime(*it);
                if (envs.top()->getSymbol(lexime) != NULL) {
                  if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                    cout << "Invalid use of keyword " << lexime << endl;
                  else
                    cout << "Duplicated variable declaration for " << lexime << endl;
                } else {
                  TypeDesc* td = new TypeDesc(*(envs.top()->getSymbol(type)->getTypeDesc()));
                  fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                  //Symbol* sym = new Symbol(lexime, 0, td);
                  //envs.top()->setSymbol(lexime, sym);
                }
              }
            }
          } 
        }
      } else if (type.compare(rec) == 0) {
        // Type is record.
        
        // Lab3
        vector<pair<string, TypeDesc*> >* recFl = fieldListStack.top();
        //cout << "fl stack size: " << fieldListStack.size() << endl;
        fieldListStack.pop();
        //cout << "fl stack size: " << fieldListStack.size() << endl;
        for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
          string lexime(*it);
          if (envs.top()->getSymbol(lexime) != NULL) {
            if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
              cout << "Invalid use of keyword " << lexime << endl;
            else
              cout << "Duplicated variable declaration for " << lexime << endl;
          } else {
            //TypeDesc* td = new TypeDesc("record", fieldListStack.top());
            TypeDesc* td = new TypeDesc("record", recFl);
            fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
            //Symbol* sym = new Symbol(lexime, 0, td);
            //envs.top()->setSymbol(lexime, sym);
          }
        }
        //delete recFl;
        //freeFieldList(recFl);
        //fieldListStack.pop();
      } else {
        // Type is array.

        // Lab3
        if (!envs.empty()) {
          for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
            string lexime(*it);
            if (envs.top()->getSymbol(lexime) != NULL) {
              if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                cout << "Invalid use of keyword " << lexime << endl;
              else
                cout << "Duplicated variable declaration for " << lexime << endl;
            } else {
              TypeDesc* td = arrayTypeStack.top();
              fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
              //Symbol* sym = new Symbol(lexime, 0, td);
              //envs.top()->setSymbol(lexime, sym);
            }
          }
          arrayTypeStack.pop();
        }
      }
    }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 1292 "parser.y"
    { cout << "identifier_lists" << endl;
      vector<string> ids = split((yyvsp[(1) - (3)].sval));
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, (yyvsp[(3) - (3)].sval));
      }
      string type((yyvsp[(3) - (3)].sval));
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol((yyvsp[(3) - (3)].sval), nilStr);
        }
      }

      // Lab3
      //vector<string> strs = split($3);
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        // Lab3. Address will be fixed later.
        if (!envs.empty()) {
          if (type.compare("integer") == 0 ||
              type.compare("string") == 0 ||
              type.compare("boolean") == 0) {
            for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
              string lexime(*it);
              if (envs.top()->getSymbol(lexime) != NULL) {
                if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                  cout << "Invalid use of keyword " << lexime << endl;
                else
                  cout << "Duplicated variable declaration for " << lexime << endl;
              } else {
                TypeDesc* td = new TypeDesc(type);
                fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                //Symbol* sym = new Symbol(lexime, 0, td);
                //envs.top()->setSymbol(lexime, sym);
              }
            }
          } else {
            if (envs.top()->getSymbol(type) == NULL) {
              Env* envPtr = envs.top()->getPrevEnv();
              bool found = false;
              while (envPtr != NULL) {
                if (envPtr->getSymbol(type) != NULL) {
                  found = true;
                  for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                    string lexime(*it);
                    if (envs.top()->getSymbol(lexime) != NULL) {
                      if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                        cout << "Invalid use of keyword " << lexime << endl;
                      else
                        cout << "Duplicated variable declaration for " << lexime << endl;
                    } else {
                      TypeDesc* td = new TypeDesc(*(envPtr->getSymbol(type)->getTypeDesc()));
                      fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                      //Symbol* sym = new Symbol(lexime, 0, td);
                      //envs.top()->setSymbol(lexime, sym);
                    }
                  }
                  break;
                }
                envPtr = envPtr->getPrevEnv();
              }
              if (!found) {
                cout << "Error: type " << type << " not defined" << endl;

                // Add this invalid type to the symbol table? Or not?
                //TypeDesc* invalidTd = new TypeDesc("invalid");
                //Symbol* sym = new Symbol(strs[0], 0, invalidTd);
                //envs.top()->setSymbol(strs[0], sym);

                // Add the defined identifiers of invalid type to the fieldList of the record. 
                for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                  string lexime(*it);
                  if (envs.top()->getSymbol(lexime) != NULL) {
                    if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                      cout << "Invalid use of keyword " << lexime << endl;
                    else
                      cout << "Duplicated variable declaration for " << lexime << endl;
                  } else {
                    TypeDesc* td = new TypeDesc("invalid");
                    fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                    //Symbol* sym = new Symbol(lexime, 0, td);
                    //envs.top()->setSymbol(lexime, sym);
                  }
                }
              }
            } else {
              for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                string lexime(*it);
                if (envs.top()->getSymbol(lexime) != NULL) {
                  if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                    cout << "Invalid use of keyword " << lexime << endl;
                  else
                    cout << "Duplicated variable declaration for " << lexime << endl;
                } else {
                  TypeDesc* td = new TypeDesc(*(envs.top()->getSymbol(type)->getTypeDesc()));
                  fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
                  //Symbol* sym = new Symbol(lexime, 0, td);
                  //envs.top()->setSymbol(lexime, sym);
                }
              }
            }
          } 
        }
      } else if (type.compare(rec) == 0) {
        // Type is record.
        
        // Lab3
        vector<pair<string, TypeDesc*> >* recFl = fieldListStack.top();
        fieldListStack.pop();
        for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
          string lexime(*it);
          if (envs.top()->getSymbol(lexime) != NULL) {
            if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
              cout << "Invalid use of keyword " << lexime << endl;
            else
              cout << "Duplicated variable declaration for " << lexime << endl;
          } else {
            TypeDesc* td = new TypeDesc("record", recFl);
            fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
            //Symbol* sym = new Symbol(lexime, 0, td);
            //envs.top()->setSymbol(lexime, sym);
          }
        }
        //delete recFl;
        //freeFieldList(recFl);
        //fieldListStack.pop();
      } else {
        // Type is array.

        // Lab3
        if (!envs.empty()) {
          for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
            string lexime(*it);
            if (envs.top()->getSymbol(lexime) != NULL) {
              if (envs.top()->getSymbol(lexime)->getTypeDesc()->getType().compare("nil") == 0)
                cout << "Invalid use of keyword " << lexime << endl;
              else
                cout << "Duplicated variable declaration for " << lexime << endl;
            } else {
              TypeDesc* td = arrayTypeStack.top();
              fieldListStack.top()->push_back(pair<string, TypeDesc*>(lexime, td));
              //Symbol* sym = new Symbol(lexime, 0, td);
              //envs.top()->setSymbol(lexime, sym);
            }
          }
          arrayTypeStack.pop();
        }
      }
    }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 1440 "parser.y"
    { cout << "constant" << endl; (yyval.ival) = (yyvsp[(1) - (1)].ival);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 1441 "parser.y"
    { cout << "constant" << endl; (yyval.ival) = (yyvsp[(2) - (2)].ival);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 1443 "parser.y"
    { cout << "expression" << endl; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 1445 "parser.y"
    {
      // Lab3
      string op((yyvsp[(1) - (2)].sval));
      TypeDesc* td2 = expTypeStack.top();
      expTypeStack.pop();
      TypeDesc* td1 = expTypeStack.top();
      expTypeStack.pop();
      if (op.compare("=") == 0 || op.compare("<>") == 0) {
        if (checkTypeEquiv(td1, td2)) {
          if (td1->getType().compare("invalid") != 0 &&
              td2->getType().compare("invalid") != 0) {
            TypeDesc* resultTd = new TypeDesc("boolean");
            expTypeStack.push(resultTd);
          } else {
            TypeDesc* resultTd = new TypeDesc("invalid");
            expTypeStack.push(resultTd);
          }
        } else {
          cout << "Error: Types not equivalent for " << td1->getType()
              << " and " << td2->getType() << " for operator " << op << endl;
          TypeDesc* resultTd = new TypeDesc("invalid");
          expTypeStack.push(resultTd);
        }
      } else {
        if (td1->getType().compare("integer") == 0 &&
            td2->getType().compare("integer") == 0) {
          TypeDesc* resultTd = new TypeDesc("boolean");
          expTypeStack.push(resultTd);
        /*
        } else if (td1->getType().compare("integer") == 0 &&
              td2->getType().compare("invalid") == 0) {
          TypeDesc* resultTd = new TypeDesc("invalid");
          expTypeStack.push(resultTd);
        } else if (td1->getType().compare("invalid") == 0 &&
              td2->getType().compare("integer") == 0) {
          TypeDesc* resultTd = new TypeDesc("invalid");
          expTypeStack.push(resultTd);
        */
        } else {
          cout << "Error: Operator " << op
              << " only valid for integer equivalents, "
              << td1->getType() << " and " << td2->getType()
              << " found however" << endl;
          TypeDesc* resultTd = new TypeDesc("invalid");
          expTypeStack.push(resultTd);
        }
      }
      delete td1;
      delete td2;
    }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1497 "parser.y"
    { cout << "relational_op" << endl; 
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 1501 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1505 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1509 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1513 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 1517 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 1522 "parser.y"
    { cout << "simple_expression" << endl; 
      TypeDesc* td = expTypeStack.top();
      cout << "stack size: " << expTypeStack.size() << endl;
      if (td->getType().compare("integer") != 0) {
        cout << "Error: Unary operator can only be applied to integer type, "
            << td->getType() << " found however." << endl;
        expTypeStack.pop();
        TypeDesc* resultTd = new TypeDesc("invalid");
        expTypeStack.push(resultTd);
        delete td;
      }
    }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 1534 "parser.y"
    { cout << "simple_expression" << endl; }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1535 "parser.y"
    { cout << "simple_expression_more" << endl;

      // Lab3
      TypeDesc* td2 = expTypeStack.top();
      expTypeStack.pop();
      TypeDesc* td1 = expTypeStack.top();
      expTypeStack.pop();
      string op((yyvsp[(2) - (3)].sval));
      if (checkTypeEquiv(td1, td2)) {
        if (td1->getType().compare("invalid") != 0 &&
            td2->getType().compare("invalid") != 0) {
          if (op.compare("or") == 0) {
            // If the operator is or, check if the types are booleans.
            if (td1->getType().compare("boolean") == 0) {
              TypeDesc* resultTd = new TypeDesc(*td1);
              expTypeStack.push(resultTd);
            } else {
              cout << "Error: Operator " << op << " can only be applied to"
                  << " booleans, " << td1->getType() << " and "
                  << td2->getType() << " found however" << endl;
              TypeDesc* resultTd = new TypeDesc("invalid");
              expTypeStack.push(resultTd);
            } 
          } else {
            if (td1->getType().compare("integer") == 0) {
              TypeDesc* resultTd = new TypeDesc(*td1);
              expTypeStack.push(resultTd);
            } else {
              cout << "Error: Operator " << op << " can only be applied to"
                  << " integers, " << td1->getType() << " and "
                  << td2->getType() << " found however" << endl;
              TypeDesc* resultTd = new TypeDesc("invalid");
              expTypeStack.push(resultTd);
            }
          }
        } else {
          TypeDesc* resultTd = new TypeDesc("invalid");
          expTypeStack.push(resultTd);
        }
      } else {
        cout << "Error: types not equivalent for " << td1->getType()
            << " and " << td2->getType() << endl;
        TypeDesc* resultTd = new TypeDesc("invalid");
        expTypeStack.push(resultTd);
      }
      
      delete td1;
      delete td2;
    }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1585 "parser.y"
    { cout << "addop" << endl; (yyval.sval) == NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1589 "parser.y"
    { cout << "addop" << endl; (yyval.sval) == NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1593 "parser.y"
    { cout << "addop" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1598 "parser.y"
    { cout << "term_more" << endl;

      // Lab3
      TypeDesc* td2 = expTypeStack.top();
      expTypeStack.pop();
      TypeDesc* td1 = expTypeStack.top();
      expTypeStack.pop();
      /*
      if (checkTypeEquiv(td1, td2)) {
        TypeDesc* resultTd = new TypeDesc(*td1);
        expTypeStack.push(resultTd);
      } else {
        cout << "Error: type not equivalent" << endl;
        TypeDesc* resultTd = new TypeDesc("invalid");
        expTypeStack.push(resultTd);
      }
      */
      string op((yyvsp[(2) - (3)].sval));
      if (checkTypeEquiv(td1, td2)) {
        if (td1->getType().compare("invalid") != 0 &&
            td2->getType().compare("invalid") != 0) {
          if (op.compare("and") == 0) {
            // If the operator is and, check if the types are booleans.
            if (td1->getType().compare("boolean") == 0) {
              TypeDesc* resultTd = new TypeDesc(*td1);
              expTypeStack.push(resultTd);
            } else {
              cout << "Error: Operator " << op << " can only be applied to"
                  << " booleans, " << td1->getType() << " and "
                  << td2->getType() << " found however" << endl;
              TypeDesc* resultTd = new TypeDesc("invalid");
              expTypeStack.push(resultTd);
            } 
          } else {
            if (td1->getType().compare("integer") == 0) {
              TypeDesc* resultTd = new TypeDesc(*td1);
              expTypeStack.push(resultTd);
            } else {
              cout << "Error: Operator " << op << " can only be applied to"
                  << " integers, " << td1->getType() << " and "
                  << td2->getType() << " found however" << endl;
              TypeDesc* resultTd = new TypeDesc("invalid");
              expTypeStack.push(resultTd);
            }
          }
        } else {
          TypeDesc* resultTd = new TypeDesc("invalid");
          expTypeStack.push(resultTd);
        }
      } else {
        cout << "Error: types not equivalent for " << op << ", found "
            << td1->getType() << " and " << td2->getType() << endl;
        TypeDesc* resultTd = new TypeDesc("invalid");
        expTypeStack.push(resultTd);
      }
      
      delete td1;
      delete td2;
    }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1657 "parser.y"
    { cout << "term" << endl; }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1659 "parser.y"
    { cout << "mulop" << endl; (yyval.sval) = NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1663 "parser.y"
    { cout << "mulop" << endl; (yyval.sval) = NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1667 "parser.y"
    { cout << "mulop" << endl; (yyval.sval) = NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1671 "parser.y"
    { cout << "mulop" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1676 "parser.y"
    { cout << "factor" << endl; 
      // Lab3
      TypeDesc* td = new TypeDesc("integer");
      expTypeStack.push(td);
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1681 "parser.y"
    { cout << "factor" << endl;
      TypeDesc* td = new TypeDesc("string");
      expTypeStack.push(td);
    }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1685 "parser.y"
    { cout << "factor" << endl; 
      //TypeDesc* td = new TypeDesc(*varType);
      //delete varType;
      //varType = NULL;
      //expTypeStack.push(td);
    }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1691 "parser.y"
    { cout << "factor" << endl; }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1692 "parser.y"
    { cout << "factor" << endl;
      TypeDesc* td = expTypeStack.top();
      expTypeStack.pop();
      if (td->getType().compare("boolean") != 0) {
        cout << "Error: Boolean operator 'not' applied to non-boolean type" << endl;
        TypeDesc* resultTd = new TypeDesc("invalid");
        expTypeStack.push(resultTd);
      }
    }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1701 "parser.y"
    { cout << "factor" << endl; }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1704 "parser.y"
    { cout << "function_reference" << endl;
      string id((yyvsp[(1) - (4)].sval));
      if (symTable.find(id) == symTable.end()) {
        addSymbol((yyvsp[(1) - (4)].sval), nilStr);
      }

      // Lab3
      int numOfParams = (yyvsp[(3) - (4)].ival);
      string funcName((yyvsp[(1) - (4)].sval));
      bool found = false;
      TypeDesc* funcTd = NULL;
      if (envs.top()->getSymbol(funcName) == NULL) {
        Env* envPtr = envs.top()->getPrevEnv();
        while (envPtr != NULL) {
          if (envPtr->getSymbol(funcName) != NULL) {
            funcTd = envPtr->getSymbol(funcName)->getTypeDesc();
            break;
          }
          envPtr = envPtr->getPrevEnv();
        }
      } else {
        funcTd = envs.top()->getSymbol(funcName)->getTypeDesc();
      }

      if (funcTd != NULL) {
        if (funcTd->getType().compare("function") != 0) {
          cout << "Error: " << funcName << " is not a function" << endl;
          for (int i = 0; i < numOfParams; ++i) {
            expTypeStack.pop();
          }
          TypeDesc* td = new TypeDesc("invalid");
          expTypeStack.push(td);
        } else {
          // Check if the actual parameter list matches the function's
          // formal parameter list.
          if (numOfParams == funcTd->getNumOfFormalParams()) {
            bool isMatched = true;
            for (int i = numOfParams - 1; i >= 0; --i) {
              TypeDesc* td = expTypeStack.top();
              expTypeStack.pop();
              TypeDesc* formalParamTd = funcTd->getNthFormalParamType(i);
              if (checkTypeEquiv(td, formalParamTd)) {
              } else {
                cout << "Error: Function " << funcName
                    << "'s parameter type not matched, found "
                    << td->getType() << " and " << formalParamTd << endl; 
                isMatched = false;
                // Pop the not checked actual parameters out of the expression
                // type stack;
                --i;
                while (i >= 0) {
                  expTypeStack.pop();
                  --i;
                }
              }
            }

            if (isMatched) {
              TypeDesc* resultTd = new TypeDesc(*(funcTd->getResultType()));
              expTypeStack.push(resultTd);
            } else {
              TypeDesc* resultTd = new TypeDesc("invalid");
              expTypeStack.push(resultTd);
            }
          } else {
            cout << "Error: Function " << funcName
                << "'s parameters number not matching!"
                <<" Expected " << funcTd->getNumOfFormalParams() << ", given "
                << numOfParams << endl;
            for (int i = 0; i < numOfParams; ++i) {
              expTypeStack.pop();
            }
            TypeDesc* td = new TypeDesc("invalid");
            expTypeStack.push(td);
          }
        }
      } else {
        // Function hasn't been declared.
        cout << "Error: Function " << funcName << " hasn't been declared" << endl;
        for (int i = 0; i < numOfParams; ++i) {
          expTypeStack.pop();
        }
        TypeDesc* td = new TypeDesc("invalid");
        expTypeStack.push(td);
      }
    }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1792 "parser.y"
    {
      // Lab3
      /*
      string lexime($1);
      
      bool found = false;
      if (envs.top()->getSymbol(lexime) == NULL) {
        Env* envPtr = envs.top()->getPrevEnv();
        while (envPtr != NULL) {
          if (envPtr->getSymbol(lexime) != NULL) {
            found = true;
            break;
          }
          envPtr = envPtr->getPrevEnv();
        }
      } else {
        found = true;
      }

      if (!found) {
        cout << "Error: variable " << lexime << " hasn't been declared" << endl;

        // Assign an invalid type to this undeclared variable.
        //TypeDesc* td = new TypeDesc("invalid");
        //Symbol* sym = new Symbol(lexime, 0, td);
        //envs.top()->setSymbol(lexime, sym);
      }
      */

    }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1822 "parser.y"
    { cout << "variable" << endl;
    string id((yyvsp[(1) - (3)].sval));
    if (symTable.find(id) == symTable.end()) {
      addSymbol((yyvsp[(1) - (3)].sval), nilStr);
    }

    // Lab3
    string lexime((yyvsp[(1) - (3)].sval));
    TypeDesc* outterMostTd = NULL;
    if (envs.top()->getSymbol(lexime) == NULL) {
      Env* envPtr = envs.top()->getPrevEnv();
      while (envPtr != NULL) {
        if (envPtr->getSymbol(lexime) != NULL) {
          outterMostTd = envPtr->getSymbol(lexime)->getTypeDesc();
          break;
        }
        envPtr = envPtr->getPrevEnv();
      }
    } else {
      outterMostTd = envs.top()->getSymbol(lexime)->getTypeDesc();
    }

    if (outterMostTd == NULL) {
      cout << "Error: variable " << lexime << " hasn't been declared" << endl;
      //varType = new TypeDesc("invalid");
      TypeDesc* td = new TypeDesc("invalid");
      expTypeStack.push(td);
    } else {
      // Validate component selection.
      if ((yyvsp[(3) - (3)].sval) != NULL) {
        vector<string> components = split((yyvsp[(3) - (3)].sval));
        TypeDesc* currentTd = outterMostTd;
        TypeDesc* prevTd = currentTd;
        bool valid = true;
        for (int i = 0; i < components.size(); ++i) {
          if (prevTd->getType().compare(rec) == 0) {
            currentTd = prevTd->getTypeDescFromFieldList(components[i]);
            if (currentTd == NULL) {
              string name;
              if (i == 0) {
                name = lexime;
              } else {
                name = components[i - 1];
              }
              cout << "Variable " << components[i] << " hasn't been defined in record "
                  << name << endl;
              valid = false;
              break;
            } else {
              prevTd = currentTd;
            }
          } else {
            string name;
            if (i == 0) {
              name = lexime;
            } else {
              name = components[i - 1];
            }
            cout << "Variable " << name << " is not a record" << endl;
            valid = false;
            break;
          }
        }
        if (valid) {
          //varType = new TypeDesc(*currentTd);
          TypeDesc* td = new TypeDesc(*currentTd);
          expTypeStack.push(td);
        } else {
          //varType = new TypeDesc("invalid");
          TypeDesc* td = new TypeDesc("invalid");
          expTypeStack.push(td);
        }
      } else {
        //varType = new TypeDesc(*outterMostTd);
        TypeDesc* td = new TypeDesc(*outterMostTd);
        expTypeStack.push(td);
      }
    }

    
    }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1905 "parser.y"
    {
      // Lab3
      stringstream ss;
      if ((yyvsp[(3) - (3)].sval) != NULL) {
        ss << (yyvsp[(2) - (3)].sval) << " " << (yyvsp[(3) - (3)].sval);
        (yyval.sval) = (char*) malloc(ss.str().length() + 1);
        strcpy((yyval.sval), ss.str().c_str());
      } else {
        (yyval.sval) = (char*) malloc(strlen((yyvsp[(2) - (3)].sval)) + 1);
        strcpy((yyval.sval), (yyvsp[(2) - (3)].sval));
      }
    }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1918 "parser.y"
    {
        // Lab3
        if ((yyvsp[(4) - (4)].sval) == NULL) {
          (yyval.sval) = NULL;
        }
        else {
          (yyval.sval) = (char*) malloc(strlen((yyvsp[(4) - (4)].sval)) + 1);
          strcpy((yyval.sval), (yyvsp[(4) - (4)].sval));
        }
      }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1928 "parser.y"
    { cout << "component_selection_empty" << endl;
        // Lab3
        (yyval.sval) = NULL;}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1932 "parser.y"
    { cout << "actual_parameter_list" << endl; (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1933 "parser.y"
    { cout << "actual_parameter_list_empty" << endl; (yyval.ival) = 0; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1936 "parser.y"
    { cout << "expressions_more" << endl; (yyval.ival) = (yyvsp[(1) - (3)].ival) + 1; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1937 "parser.y"
    { cout << "expressions" << endl; (yyval.ival) = 1; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1940 "parser.y"
    { cout << "identifier_list_more" << endl;
      (yyval.sval) = (char*) malloc (strlen((yyvsp[(1) - (3)].sval)) + strlen((yyvsp[(3) - (3)].sval)) + 2);
      int i = 0;
      while ((yyvsp[(1) - (3)].sval)[i] != '\0') {
        (yyval.sval)[i] = (yyvsp[(1) - (3)].sval)[i];
        ++i;
      }
      (yyval.sval)[i++] = ' ';
      int j = 0;
      while ((yyvsp[(3) - (3)].sval)[j] != '\0') {
        (yyval.sval)[i++] = (yyvsp[(3) - (3)].sval)[j++];
      }
      (yyval.sval)[i] = '\0';
    }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1955 "parser.y"
    { cout << "identifier_list" << endl;
      (yyval.sval) = (char*) malloc (strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));}
    break;



/* Line 1806 of yacc.c  */
#line 3900 "parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1961 "parser.y"

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
  
  //envs.top()->displayTable();
  for (int i = allEnvs.size() - 1; i >= 0; --i) {
   // cout << allEnvs[i]->getTableSize() << endl;
   // allEnvs[i]->displayTable();
  } 
  //cout << envs.size() << endl;
  for (int i = allEnvs.size() - 1; i >= 0; --i) {
    delete allEnvs[i];
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

void freeFieldList(vector<pair<string, TypeDesc*> >* fl) {
  if (fl != NULL) {
    for(int i = 0; i < fl->size(); ++i) {
      delete fl->at(i).second;
      fl->at(i).second = NULL;
    }
  }

    delete fl;
    fl = NULL;
}

bool checkTypeEquiv(TypeDesc* td1, TypeDesc* td2) {
  string name1 = td1->getType();
  string name2 = td2->getType();

  if (name1.compare("invalid") == 0 || name2.compare("invalid") == 0) {
    return true;
  } else {
    if (name1.compare(name2) == 0) {
      if (name1.compare("integer") == 0 ||
          name1.compare("string") == 0 ||
          name1.compare("boolean") == 0) {
        return true;
      } else if (name1.compare("array") == 0) {
        if (td1->getLower() == td2->getLower() && td1->getUpper() == td2->getUpper()) {
          return checkTypeEquiv(td1->getArrayEleType(), td2->getArrayEleType());
        } else {
          return false;
        }
      } else {
        vector<pair<string, TypeDesc*> >* fl1 = td1->getFieldList();
        vector<pair<string, TypeDesc*> >* fl2 = td2->getFieldList();
        if (fl1->size() == fl2->size()) {
          bool equiv = true;
          for (int i = 0; i < fl1->size(); ++i) {
            if (fl1->at(i).first.compare(fl2->at(i).first) == 0) {
              if (!checkTypeEquiv(fl1->at(i).second, fl2->at(i).second)) {
                equiv = false;
                break; 
              }
            } else {
              equiv = false;
              break;
            }
          }
          return equiv;
        } else {
          return false;
        }
      }
    } else {
      return false;
    } 
  }
}

