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
vector<TypeDesc*>* formalParamList;
stack<TypeDesc*> expTypeStack;
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
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

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
     121,   123,   124,   128,   133,   135,   136,   142,   143,   151,
     152,   158,   167,   169,   178,   179,   184,   186,   188,   189,
     195,   199,   201,   204,   207,   210,   211,   213,   215,   217,
     219,   221,   223,   226,   228,   232,   234,   236,   238,   242,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   263,
     267,   272,   273,   277,   281,   286,   287,   289,   290,   294,
     296,   300,   302,   304
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    21,    38,    45,    56,    57,    58,    75,
      42,    -1,    59,    -1,    -1,    61,    -1,    -1,    63,    -1,
      -1,    25,    60,    -1,    60,    65,    -1,    65,    -1,    26,
      62,    -1,    62,    66,    -1,    66,    -1,    64,    -1,    64,
      67,    -1,    64,    69,    -1,    67,    -1,    69,    -1,    38,
      32,    86,    45,    -1,   106,    44,    86,    45,    -1,    -1,
      20,    38,    48,    72,    68,    49,    45,    71,    45,    -1,
      -1,    13,    38,    48,    72,    49,    44,    88,    70,    45,
      71,    45,    -1,    74,    -1,     7,    -1,    73,    -1,    -1,
      73,    45,   106,    44,    86,    -1,   106,    44,    86,    -1,
      57,    75,    -1,     6,    76,    11,    -1,    76,    45,    77,
      -1,    77,    -1,    78,    -1,    79,    -1,    82,    -1,    80,
      -1,    81,    -1,    -1,   101,    46,    92,    -1,    38,    48,
     104,    49,    -1,    75,    -1,    -1,    14,    92,    23,    83,
      77,    -1,    -1,    14,    92,    84,    23,    77,    10,    77,
      -1,    -1,    27,    92,    85,     9,    77,    -1,    12,    38,
      46,    92,    24,    92,     9,    77,    -1,    38,    -1,    15,
      50,    91,    47,    91,    51,    18,    86,    -1,    -1,    22,
      87,    89,    11,    -1,    38,    -1,    90,    -1,    -1,    90,
      45,   106,    44,    86,    -1,   106,    44,    86,    -1,    39,
      -1,   107,    39,    -1,    95,    93,    -1,    94,    95,    -1,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,
      -1,    32,    -1,   107,    97,    -1,    97,    -1,    95,    96,
      97,    -1,    28,    -1,    29,    -1,    19,    -1,    97,    98,
      99,    -1,    99,    -1,    30,    -1,     8,    -1,    16,    -1,
       5,    -1,    39,    -1,     4,    -1,   101,    -1,   100,    -1,
      17,    99,    -1,    48,    92,    49,    -1,    38,    48,   104,
      49,    -1,    -1,    38,   102,   103,    -1,    42,    38,   103,
      -1,    50,    92,    51,   103,    -1,    -1,   105,    -1,    -1,
     105,    43,    92,    -1,    92,    -1,   106,    43,    38,    -1,
      38,    -1,    28,    -1,    29,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   142,   142,   143,   143,   144,   144,   146,
     148,   149,   151,   153,   154,   156,   158,   159,   160,   161,
     163,   290,   431,   430,   468,   466,   570,   570,   572,   575,
     585,   689,   801,   803,   805,   806,   808,   810,   810,   812,
     813,   814,   816,   838,   846,   848,   847,   857,   856,   866,
     865,   874,   876,   879,   947,   946,   956,   972,   973,   978,
    1128,  1277,  1278,  1280,  1282,  1332,  1334,  1338,  1342,  1346,
    1350,  1354,  1359,  1371,  1372,  1422,  1426,  1430,  1435,  1494,
    1496,  1500,  1504,  1508,  1513,  1518,  1522,  1528,  1529,  1538,
    1540,  1549,  1548,  1661,  1674,  1685,  1689,  1690,  1692,  1694,
    1696,  1711,  1716,  1716
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
  "$@3", "$@4", "$@5", "type", "$@6", "resultType", "fieldList",
  "fieldListSeq", "constant", "expression", "groupRelOpSimExpr",
  "relationalOp", "simpleExpression", "addOp", "term", "mulOp", "factor",
  "functionReference", "variable", "$@7", "componentSelection",
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
      79,    79,    80,    81,    82,    83,    82,    84,    82,    85,
      82,    82,    86,    86,    87,    86,    88,    89,    89,    90,
      90,    91,    91,    92,    93,    93,    94,    94,    94,    94,
      94,    94,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    98,    98,    99,    99,    99,    99,    99,    99,
     100,   102,   101,   103,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     0,     1,     0,     1,     0,     2,
       2,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       4,     4,     0,     9,     0,    11,     1,     1,     1,     0,
       5,     3,     2,     3,     3,     1,     1,     1,     1,     1,
       1,     0,     3,     4,     1,     0,     5,     0,     7,     0,
       5,     8,     1,     8,     0,     4,     1,     1,     0,     5,
       3,     1,     2,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     0,     3,     3,     4,     0,     1,     0,     3,     1,
       3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     6,     3,     0,
       9,    11,     0,     8,     5,     0,    10,   101,    12,    14,
       0,     0,     0,     0,     7,    15,    18,    19,     0,    54,
      52,     0,    13,     0,     0,     0,     0,    41,     0,    16,
      17,     0,    58,    20,   100,     0,    29,    29,     0,     0,
       0,    91,    44,     0,    35,    36,    37,    39,    40,    38,
       0,     2,   102,   103,    61,     0,     0,     0,    57,     0,
      21,     0,    28,     0,    22,     0,    85,     0,    91,    84,
       0,     0,    65,    73,    79,    87,    86,     0,    49,    97,
      95,    33,    41,     0,     0,    62,    55,     0,     0,     0,
       0,     0,     0,     0,    88,    97,     0,    45,     0,    77,
      75,    76,    71,    66,    67,    68,    69,    70,    63,     0,
       0,    83,    81,    82,    80,     0,    72,     0,    99,     0,
      96,     0,     0,    92,    34,    42,     0,     0,    60,     0,
       0,    31,     0,     0,     0,    89,    41,    41,    64,    74,
      78,    41,    43,     0,    95,     0,     0,     0,    56,    24,
       0,     6,     0,    90,    46,     0,    50,    98,    93,    95,
       0,    59,     0,    30,    27,     0,     0,    26,     0,    41,
      94,    53,     6,    32,    23,    41,    48,     0,    51,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,   175,    23,     8,    10,    14,    18,    24,
      25,    11,    19,    26,   102,    27,   172,   176,    71,    72,
     177,    52,    53,    54,    55,    56,    57,    58,    59,   146,
     108,   127,    31,    42,   159,    67,    68,    65,   128,   118,
     119,    82,   120,    83,   125,    84,    85,    86,    90,   133,
     129,   130,    20,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -140
static const yytype_int16 yypact[] =
{
       2,    -9,    35,    -8,  -140,    16,    17,    41,  -140,    55,
      17,  -140,    57,    13,  -140,    30,  -140,  -140,    57,  -140,
     -24,    58,    59,    93,  -140,    13,  -140,  -140,    50,  -140,
    -140,    56,  -140,    64,    30,    60,    61,     4,    62,  -140,
    -140,    46,    57,  -140,  -140,    67,    57,    57,    68,    10,
      10,    66,  -140,     6,  -140,  -140,  -140,  -140,  -140,  -140,
      71,  -140,  -140,  -140,  -140,    72,    74,    92,    73,    27,
    -140,    75,    76,    39,  -140,    77,  -140,     5,    78,  -140,
      10,    82,    44,    20,  -140,  -140,  -140,     5,  -140,    10,
     -18,  -140,     4,    10,    46,  -140,  -140,    57,    30,    83,
      57,    30,    80,    10,  -140,    10,    81,  -140,    97,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,    10,
       5,  -140,  -140,  -140,  -140,     5,    20,   113,  -140,    84,
      88,    94,    10,  -140,  -140,  -140,    85,    45,  -140,    96,
      47,  -140,    90,   115,    91,  -140,     4,     4,    65,    20,
    -140,     4,  -140,    10,   -18,    86,   123,    30,  -140,  -140,
      30,    14,    10,  -140,  -140,   132,  -140,  -140,  -140,   -18,
      30,  -140,    99,  -140,  -140,    93,   100,  -140,   137,     4,
    -140,  -140,    14,  -140,  -140,     4,  -140,   102,  -140,  -140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,   141,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,   140,   133,   128,  -140,   129,  -140,   -27,   109,  -140,
    -140,   -23,  -140,   -87,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,   -32,  -140,  -140,  -140,  -140,    63,   -46,  -140,
    -140,    40,  -140,   -74,  -140,   -71,  -140,   -36,  -140,  -139,
      53,  -140,   -35,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    60,    45,    81,    88,   134,   104,    69,    66,    76,
      37,    73,    73,   126,    76,   168,    48,    91,    49,    33,
      34,   174,    77,     1,   131,   121,    21,    77,   122,     3,
     180,    50,   132,    22,   106,     4,   123,     5,    62,    63,
      12,     6,    51,    78,    79,    28,   149,   135,    78,    79,
     124,    92,    29,    80,   150,     9,    60,   143,    80,   164,
     165,    66,   137,   109,   166,   140,   138,    12,    30,   141,
      33,    98,   110,   111,    62,    63,   112,   113,   114,   115,
     116,   117,    33,   101,   109,    64,   155,    15,    33,   157,
      33,   160,   186,   110,   111,    17,    35,    36,   188,    37,
      41,    43,    44,    96,    61,   107,    75,   167,    46,    47,
      60,    60,    70,    95,    89,    60,   178,    93,    97,    94,
     147,   100,   151,   103,    99,   171,   105,   139,   173,   142,
     145,   153,   154,   152,   158,   161,   156,   169,   181,   162,
     163,   170,   179,    60,   182,   184,   185,   189,    13,    60,
      16,    32,   183,    39,    40,   187,    74,   136,   144,   148
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-140))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      23,    37,    34,    49,    50,    92,    77,    42,    41,     4,
       6,    46,    47,    87,     4,   154,    12,    11,    14,    43,
      44,     7,    17,    21,    42,     5,    13,    17,     8,    38,
     169,    27,    50,    20,    80,     0,    16,    45,    28,    29,
      26,    25,    38,    38,    39,    15,   120,    93,    38,    39,
      30,    45,    22,    48,   125,    38,    92,   103,    48,   146,
     147,    94,    97,    19,   151,   100,    98,    26,    38,   101,
      43,    44,    28,    29,    28,    29,    32,    33,    34,    35,
      36,    37,    43,    44,    19,    39,   132,    32,    43,    44,
      43,    44,   179,    28,    29,    38,    38,    38,   185,     6,
      50,    45,    38,    11,    42,    23,    38,   153,    48,    48,
     146,   147,    45,    39,    48,   151,   162,    46,    45,    47,
      23,    45,     9,    46,    49,   157,    48,    44,   160,    49,
      49,    43,    38,    49,    38,    45,    51,    51,   170,    24,
      49,    18,    10,   179,    45,    45,     9,    45,     7,   185,
      10,    18,   175,    25,    25,   182,    47,    94,   105,   119
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    55,    38,     0,    45,    25,    56,    59,    38,
      60,    65,    26,    57,    61,    32,    65,    38,    62,    66,
     106,    13,    20,    58,    63,    64,    67,    69,    15,    22,
      38,    86,    66,    43,    44,    38,    38,     6,    75,    67,
      69,    50,    87,    45,    38,    86,    48,    48,    12,    14,
      27,    38,    75,    76,    77,    78,    79,    80,    81,    82,
     101,    42,    28,    29,    39,    91,   107,    89,    90,   106,
      45,    72,    73,   106,    72,    38,     4,    17,    38,    39,
      48,    92,    95,    97,    99,   100,   101,   107,    92,    48,
     102,    11,    45,    46,    47,    39,    11,    45,    44,    49,
      45,    44,    68,    46,    99,    48,    92,    23,    84,    19,
      28,    29,    32,    33,    34,    35,    36,    37,    93,    94,
      96,     5,     8,    16,    30,    98,    97,    85,    92,   104,
     105,    42,    50,   103,    77,    92,    91,   106,    86,    44,
     106,    86,    49,    92,   104,    49,    83,    23,    95,    97,
      99,     9,    49,    43,    38,    92,    51,    44,    38,    88,
      44,    45,    24,    49,    77,    77,    77,    92,   103,    51,
      18,    86,    70,    86,     7,    57,    71,    74,    92,    10,
     103,    86,    45,    75,    45,     9,    77,    71,    77,    45
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
      vector<TypeDesc*>* copyOfFormalParamList =
          new vector<TypeDesc*>();
      for (int i = 0; i < formalParamList->size(); ++i) {
        TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
        copyOfFormalParamList->push_back(oneTd);
      }
      td = new TypeDesc("procedure", copyOfFormalParamList, NULL);
      sym = new Symbol(lexime, 0, td);
      globalEnv->setSymbol(lexime, sym);
      
    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 463 "parser.y"
    { cout << "procedure_declaration" << endl; envs.pop(); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 468 "parser.y"
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
          vector<TypeDesc*>* copyOfFormalParamList =
              new vector<TypeDesc*>();
          for (int i = 0; i < formalParamList->size(); ++i) {
            TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
            copyOfFormalParamList->push_back(oneTd);
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
            vector<TypeDesc*>* copyOfFormalParamList =
                new vector<TypeDesc*>();
            for (int i = 0; i < formalParamList->size(); ++i) {
              TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
              copyOfFormalParamList->push_back(oneTd);
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
            vector<TypeDesc*>* copyOfFormalParamList =
                new vector<TypeDesc*>();
            for (int i = 0; i < formalParamList->size(); ++i) {
              TypeDesc* oneTd = new TypeDesc(*(formalParamList->at(i)));
              copyOfFormalParamList->push_back(oneTd);
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
#line 568 "parser.y"
    { cout << "function_declaration" << endl; envs.pop(); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 572 "parser.y"
    { cout << "formal_parameter_list" << endl; (yyval.ival) = (yyvsp[(1) - (1)].ival);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 575 "parser.y"
    { cout << "formal_parameter_list_empty" << endl; 
      (yyval.ival) = 0; 

      // Lab3
      Env* prevEnv = envs.top();
      Env* env = new Env(prevEnv);
      envs.push(env);
      allEnvs.push_back(env);
    }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 586 "parser.y"
    { cout << "identifier_lists_more" << endl;
      vector<string> ids = split((yyvsp[(3) - (5)].sval));
      vector<string> strs = split((yyvsp[(5) - (5)].sval));
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, (yyvsp[(5) - (5)].sval));
      }
      string type((yyvsp[(5) - (5)].sval));
      if (strs[0].compare(rec) != 0 && strs[0].compare(arr) !=0) {
        if (symTable.find(strs[0]) == symTable.end()) {
          addSymbol(strs[0], nilStr);
        }
      }
      (yyval.ival) = (yyvsp[(1) - (5)].ival) + ids.size();

      //vector<string> strs = split($5);
      if (strs[0].compare(rec) != 0 && strs[0].compare(arr) !=0) {
        // Type is not literally named record or array.
        if (!envs.empty()) {
          if (strs[0].compare("integer") == 0 ||
              strs[0].compare("string") == 0 ||
              strs[0].compare("boolean") == 0) {
            for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
              string lexime(*it);
              TypeDesc* td = new TypeDesc(strs[0]);
              formalParamList->push_back(td);
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            }
          } else {
            if (envs.top()->getSymbol(strs[0]) == NULL) {
              Env* envPtr = envs.top()->getPrevEnv();
              bool found = false;
              while (envPtr != NULL) {
                if (envPtr->getSymbol(strs[0]) != NULL) {
                  found = true;
                  for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                    string lexime(*it);
                    TypeDesc* td = new TypeDesc(*(envPtr->getSymbol(strs[0])->getTypeDesc()));
                    formalParamList->push_back(td);
                    Symbol* sym = new Symbol(lexime, 0, td);
                    envs.top()->setSymbol(lexime, sym);
                  }
                  break;
                }
                envPtr = envPtr->getPrevEnv();
              }
              if (!found) {
                cout << "Error: type " << strs[0] << " not defined" << endl;

                // Add this invalid type to the symbol table.
                TypeDesc* invalidTd = new TypeDesc("invalid");
                Symbol* sym = new Symbol(strs[0], 0, invalidTd);
                envs.top()->setSymbol(strs[0], sym);

                // Add the defined parameters to the symbol table with invalid type. 
                for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                  string lexime(*it);
                  TypeDesc* td = new TypeDesc(*invalidTd);
                  formalParamList->push_back(td);
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                }
              }
            } else {
              for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                string lexime(*it);
                TypeDesc* td = new TypeDesc(*(envs.top()->getSymbol(strs[0])->getTypeDesc()));
                formalParamList->push_back(td);
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
              }
            }
          } 
        }
      } else if (strs[0].compare(rec) == 0) {
        // Type is record.
        
        // Lab3
        for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
          string lexime(*it);
          TypeDesc* td = new TypeDesc("record", fieldListStack.top());
          formalParamList->push_back(td);
          Symbol* sym = new Symbol(lexime, 0, td);
          envs.top()->setSymbol(lexime, sym);
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
            TypeDesc* td = arrayTypeStack.top();
            Symbol* sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);
          }
          arrayTypeStack.pop();
        }
      }
    }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 690 "parser.y"
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
                TypeDesc* td = new TypeDesc(type);
                formalParamList->push_back(td);
                Symbol* sym = new Symbol(lexime, 0, td);
                envs.top()->setSymbol(lexime, sym);
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
                      TypeDesc* td = new TypeDesc(*(envPtr->getSymbol(type)->getTypeDesc()));
                      formalParamList->push_back(td);
                      Symbol* sym = new Symbol(lexime, 0, td);
                      envs.top()->setSymbol(lexime, sym);
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
                    TypeDesc* td = new TypeDesc(*invalidTd);
                    formalParamList->push_back(td);
                    Symbol* sym = new Symbol(lexime, 0, td);
                    envs.top()->setSymbol(lexime, sym);
                  }
                }
              } else {
                for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
                  string lexime(*it);
                  TypeDesc* td = new TypeDesc(*(envs.top()->getSymbol(type)->getTypeDesc()));
                  formalParamList->push_back(td);
                  Symbol* sym = new Symbol(lexime, 0, td);
                  envs.top()->setSymbol(lexime, sym);
                }
              }
            } 
          }
        } else if (type.compare(rec) == 0) {
          // Type is record.
          
          // Lab3
          for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
            string lexime(*it);
            TypeDesc* td = new TypeDesc("record", fieldListStack.top());
            formalParamList->push_back(td);
            Symbol* sym = new Symbol(lexime, 0, td);
            envs.top()->setSymbol(lexime, sym);
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
              TypeDesc* td = arrayTypeStack.top();
              formalParamList->push_back(td);
              Symbol* sym = new Symbol(lexime, 0, td);
              envs.top()->setSymbol(lexime, sym);
            }
            arrayTypeStack.pop();
          }
        }
      }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 801 "parser.y"
    { cout << "block" << endl; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 803 "parser.y"
    { cout << "compound_statement" << endl; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 805 "parser.y"
    { cout << "statement_sequence_more" << endl; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 806 "parser.y"
    { cout << "statement_sequence" << endl; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 808 "parser.y"
    { cout << "statement" << endl; }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 812 "parser.y"
    { cout << "simple_statement" << endl; }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 813 "parser.y"
    { cout << "simple_statement" << endl; }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 814 "parser.y"
    { cout << "simple_statement_empty" << endl; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 816 "parser.y"
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
#line 839 "parser.y"
    { cout << "procedure_statement" << endl;
      string id((yyvsp[(1) - (4)].sval));
      if (symTable.find(id) == symTable.end()) {
        addSymbol((yyvsp[(1) - (4)].sval), nilStr);
      }
    }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 846 "parser.y"
    { cout << "compound_statement" << endl; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 848 "parser.y"
    {
        if (expTypeStack.top()->getType().compare("boolean") != 0) {
          cout << "Error: while construct expects boolean expression, "
              << expTypeStack.top()->getType() << " found" << endl;
        }
        expTypeStack.pop();
      }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 855 "parser.y"
    { cout << "if_statement" << endl; }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 857 "parser.y"
    {
        if (expTypeStack.top()->getType().compare("boolean") != 0) {
          cout << "Error: while construct expects boolean expression, "
              << expTypeStack.top()->getType() << " found" << endl;
        }
        expTypeStack.pop();
      }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 864 "parser.y"
    { cout << "ifelse_statement" << endl; }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 866 "parser.y"
    {
        if (expTypeStack.top()->getType().compare("boolean") != 0) {
          cout << "Error: while construct expects boolean expression, "
              << expTypeStack.top()->getType() << " found" << endl;
        }
        expTypeStack.pop();
      }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 873 "parser.y"
    { cout << "while_statement" << endl; }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 874 "parser.y"
    { cout << "for_statement" << endl; }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 876 "parser.y"
    { cout << "type_ID" << endl; //addSymbol($1, nilStr);
                 (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
                 strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 880 "parser.y"
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

  case 54:

/* Line 1806 of yacc.c  */
#line 947 "parser.y"
    {
        vector<pair<string, TypeDesc*> >* fieldList = new vector<pair<string, TypeDesc*> >;
        fieldListStack.push(fieldList);
      }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 952 "parser.y"
    { cout << "type_record" << endl;
        (yyval.sval) = (char*) malloc(strlen(recordStr) + 1);;
        strcpy((yyval.sval), recordStr); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 956 "parser.y"
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

  case 57:

/* Line 1806 of yacc.c  */
#line 972 "parser.y"
    { cout << "field_list" << endl; }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 973 "parser.y"
    { cout << "field_list_empty" << endl;
        //vector<pair<string, TypeDesc*> >* fieldList = NULL;
        //fieldListStack.push(fieldList);
      }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 979 "parser.y"
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

  case 60:

/* Line 1806 of yacc.c  */
#line 1129 "parser.y"
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

  case 61:

/* Line 1806 of yacc.c  */
#line 1277 "parser.y"
    { cout << "constant" << endl; (yyval.ival) = (yyvsp[(1) - (1)].ival);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 1278 "parser.y"
    { cout << "constant" << endl; (yyval.ival) = (yyvsp[(2) - (2)].ival);}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 1280 "parser.y"
    { cout << "expression" << endl; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1282 "parser.y"
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

  case 66:

/* Line 1806 of yacc.c  */
#line 1334 "parser.y"
    { cout << "relational_op" << endl; 
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1338 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1342 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 1346 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 1350 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 1354 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 1359 "parser.y"
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

  case 73:

/* Line 1806 of yacc.c  */
#line 1371 "parser.y"
    { cout << "simple_expression" << endl; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1372 "parser.y"
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

  case 75:

/* Line 1806 of yacc.c  */
#line 1422 "parser.y"
    { cout << "addop" << endl; (yyval.sval) == NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1426 "parser.y"
    { cout << "addop" << endl; (yyval.sval) == NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1430 "parser.y"
    { cout << "addop" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1435 "parser.y"
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

  case 79:

/* Line 1806 of yacc.c  */
#line 1494 "parser.y"
    { cout << "term" << endl; }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1496 "parser.y"
    { cout << "mulop" << endl; (yyval.sval) = NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1500 "parser.y"
    { cout << "mulop" << endl; (yyval.sval) = NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1504 "parser.y"
    { cout << "mulop" << endl; (yyval.sval) = NULL;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1508 "parser.y"
    { cout << "mulop" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1513 "parser.y"
    { cout << "factor" << endl; 
      // Lab3
      TypeDesc* td = new TypeDesc("integer");
      expTypeStack.push(td);
    }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1518 "parser.y"
    { cout << "factor" << endl;
      TypeDesc* td = new TypeDesc("string");
      expTypeStack.push(td);
    }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1522 "parser.y"
    { cout << "factor" << endl; 
      //TypeDesc* td = new TypeDesc(*varType);
      //delete varType;
      //varType = NULL;
      //expTypeStack.push(td);
    }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1528 "parser.y"
    { cout << "factor" << endl; }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1529 "parser.y"
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

  case 89:

/* Line 1806 of yacc.c  */
#line 1538 "parser.y"
    { cout << "factor" << endl; }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1541 "parser.y"
    { cout << "function_reference" << endl;
      string id((yyvsp[(1) - (4)].sval));
      if (symTable.find(id) == symTable.end()) {
        addSymbol((yyvsp[(1) - (4)].sval), nilStr);
      }
    }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1549 "parser.y"
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

  case 92:

/* Line 1806 of yacc.c  */
#line 1579 "parser.y"
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

  case 93:

/* Line 1806 of yacc.c  */
#line 1662 "parser.y"
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

  case 94:

/* Line 1806 of yacc.c  */
#line 1675 "parser.y"
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

  case 95:

/* Line 1806 of yacc.c  */
#line 1685 "parser.y"
    { cout << "component_selection_empty" << endl;
        // Lab3
        (yyval.sval) = NULL;}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1689 "parser.y"
    { cout << "actual_parameter_list" << endl; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1690 "parser.y"
    { cout << "actual_parameter_list_empty" << endl; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1693 "parser.y"
    { cout << "expressions_more" << endl; }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1694 "parser.y"
    { cout << "expressions" << endl; }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1697 "parser.y"
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

  case 101:

/* Line 1806 of yacc.c  */
#line 1712 "parser.y"
    { cout << "identifier_list" << endl;
      (yyval.sval) = (char*) malloc (strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));}
    break;



/* Line 1806 of yacc.c  */
#line 3667 "parser.tab.c"
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
#line 1718 "parser.y"

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

