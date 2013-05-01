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
int labelCounter = 0;

void yyerror(const char *s);
static void lookup(char *token_buffer);
void addSymbol(const char *id, const char *type);
void addSymbol(const char *id, const string &type);
void addSymbol(const string &id, const char *type);
void addSymbol(const char* id, const int type);
void addSymbol(const string &id, const string &type);
vector<string> split(const char *ids);
void fixAddress(int addr);
string processVarWithCompSel(string varStr);
void addQuadruple(const string& op, const string& arg1, const string& arg2,
    const string& result);
int getQuadrupleIndex(const string& result);
void modifyQuadResult(int index, const string& result);
void flipQuadRelOp(int index);
void addLabelToQuad(int index, const string& label);
bool isQuadOpAssign(int index);
void changeQuadToCondExp(int index, const string& op, const string& arg2,
    const string& result);

#define YYPRINT

map<string, pair<int, string> > symTable;
map<int, pair<string, string> > symTableIndexedByAddr;
string nilStr("nil");
char recordStr[] = "record";
char arrayStr[] = "array";
string rec(recordStr);
string arr(arrayStr);


/* Line 268 of yacc.c  */
#line 132 "parser.tab.c"

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
#line 63 "parser.y"

  int ival;
  float fval;
  bool bval;
  char *sval;



/* Line 293 of yacc.c  */
#line 230 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 242 "parser.tab.c"

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
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

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
     121,   122,   126,   131,   133,   138,   145,   150,   151,   161,
     163,   172,   176,   178,   180,   181,   187,   191,   193,   196,
     199,   202,   203,   205,   207,   209,   211,   213,   215,   218,
     220,   224,   226,   228,   230,   234,   236,   238,   240,   242,
     244,   246,   249,   251,   253,   255,   257,   261,   266,   269,
     271,   272,   275,   279,   283,   288,   290,   291,   295,   297,
     301,   303,   305
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    21,    38,    45,    56,    57,    58,    75,
      42,    -1,    59,    -1,    -1,    61,    -1,    -1,    63,    -1,
      -1,    25,    60,    -1,    60,    65,    -1,    65,    -1,    26,
      62,    -1,    62,    66,    -1,    66,    -1,    64,    -1,    64,
      67,    -1,    64,    69,    -1,    67,    -1,    69,    -1,    38,
      32,    83,    45,    -1,   103,    44,    83,    45,    -1,    -1,
      20,    38,    68,    48,    72,    49,    45,    71,    45,    -1,
      -1,    13,    38,    70,    48,    72,    49,    44,    84,    45,
      71,    45,    -1,    74,    -1,     7,    -1,    73,    -1,    -1,
      73,    45,   103,    44,    83,    -1,   103,    44,    83,    -1,
      57,    75,    -1,     6,    76,    11,    -1,    76,    45,    77,
      -1,    77,    -1,    78,    -1,    81,    -1,    79,    -1,    80,
      -1,    -1,    98,    46,    88,    -1,    38,    48,   101,    49,
      -1,    75,    -1,    14,    88,    23,    77,    -1,    14,    88,
      23,    77,    10,    77,    -1,    27,    88,     9,    77,    -1,
      -1,    12,    38,    46,    88,    24,    88,    82,     9,    77,
      -1,    38,    -1,    15,    50,    87,    47,    87,    51,    18,
      83,    -1,    22,    85,    11,    -1,    38,    -1,    86,    -1,
      -1,    86,    45,   103,    44,    83,    -1,   103,    44,    83,
      -1,    39,    -1,   104,    39,    -1,    91,    89,    -1,    90,
      91,    -1,    -1,    33,    -1,    34,    -1,    35,    -1,    36,
      -1,    37,    -1,    32,    -1,   104,    93,    -1,    93,    -1,
      91,    92,    93,    -1,    28,    -1,    29,    -1,    19,    -1,
      93,    94,    95,    -1,    95,    -1,    30,    -1,     8,    -1,
      16,    -1,     5,    -1,    96,    -1,    17,    96,    -1,    39,
      -1,     4,    -1,    98,    -1,    97,    -1,    48,    88,    49,
      -1,    38,    48,   101,    49,    -1,    38,    99,    -1,   100,
      -1,    -1,    42,    38,    -1,    50,    88,    51,    -1,   100,
      42,    38,    -1,   100,    50,    88,    51,    -1,   102,    -1,
      -1,   102,    43,    88,    -1,    88,    -1,   103,    43,    38,
      -1,    38,    -1,    28,    -1,    29,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   144,   144,   145,   145,   146,   146,   148,
     150,   151,   153,   155,   156,   158,   160,   161,   162,   163,
     165,   186,   200,   200,   221,   221,   259,   259,   261,   262,
     264,   278,   293,   295,   301,   308,   314,   315,   317,   322,
     327,   334,   345,   360,   365,   387,   415,   443,   443,   474,
     477,   481,   486,   493,   494,   496,   510,   524,   525,   527,
     544,   550,   552,   556,   560,   564,   568,   572,   577,   586,
     590,   600,   604,   608,   613,   622,   627,   631,   635,   639,
     644,   648,   659,   671,   681,   691,   695,   700,   717,   736,
     740,   742,   749,   756,   762,   769,   770,   772,   776,   780,
     795,   800,   806
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
  "statement", "simpleStatement", "assignmentStatement",
  "procedureStatement", "structuredStatement", "@3", "type", "resultType",
  "fieldList", "fieldListSeq", "constant", "expression",
  "groupRelOpSimExpr", "relationalOp", "simpleExpression", "addOp", "term",
  "mulOp", "factor", "factorElement", "functionReference", "variable",
  "groupComponentSelection", "componentSelection", "actualParameterList",
  "expressionList", "identifierList", "sign", 0
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
      73,    73,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    80,    81,    81,    81,    81,    82,    81,    83,
      83,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    92,    92,    92,    93,    93,    94,    94,    94,    94,
      95,    95,    96,    96,    96,    96,    96,    97,    98,    99,
      99,   100,   100,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     0,     1,     0,     1,     0,     2,
       2,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       4,     4,     0,     9,     0,    11,     1,     1,     1,     0,
       5,     3,     2,     3,     3,     1,     1,     1,     1,     1,
       0,     3,     4,     1,     4,     6,     4,     0,     9,     1,
       8,     3,     1,     1,     0,     5,     3,     1,     2,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     4,     2,     1,
       0,     2,     3,     3,     4,     1,     0,     3,     1,     3,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     6,     3,     0,
       9,    11,     0,     8,     5,     0,    10,   100,    12,    14,
       0,     0,     0,     0,     7,    15,    18,    19,     0,    54,
      49,     0,    13,     0,     0,    24,    22,    40,     0,    16,
      17,     0,     0,    53,     0,    20,    99,     0,     0,     0,
       0,     0,     0,    90,    43,     0,    35,    36,    38,    39,
      37,     0,     2,   101,   102,    57,     0,     0,    51,     0,
       0,    21,    29,    29,     0,    83,     0,    90,    82,     0,
       0,    61,    69,    75,    80,    85,    84,     0,     0,     0,
      96,     0,    88,    89,    33,    40,     0,     0,    58,     0,
      56,     0,    28,     0,     0,     0,    81,    96,     0,    40,
      73,    71,    72,    67,    62,    63,    64,    65,    66,    59,
       0,     0,    79,    77,    78,    76,     0,    68,    40,    91,
      98,     0,    95,     0,     0,     0,    34,    41,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    44,    60,    70,
      74,    46,    42,     0,    92,    93,     0,     0,    55,     0,
       0,    31,     6,     0,    87,    40,    97,    94,     0,    52,
       0,     0,    27,     0,     0,    26,    47,    45,    50,     6,
      30,    32,    23,     0,     0,    40,    25,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,   173,    23,     8,    10,    14,    18,    24,
      25,    11,    19,    26,    49,    27,    48,   174,   101,   102,
     175,    54,    55,    56,    57,    58,    59,    60,   183,    31,
     170,    42,    43,    66,   130,   119,   120,    81,   121,    82,
     126,    83,    84,    85,    86,    92,    93,   131,   132,    20,
      87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -90
static const yytype_int16 yypact[] =
{
      37,    29,    19,    27,   -90,    50,    52,    65,   -90,    62,
      52,   -90,    60,    16,   -90,    -6,   -90,   -90,    60,   -90,
     -19,    66,    68,    94,   -90,    16,   -90,   -90,    61,    60,
     -90,    63,   -90,    71,    -6,   -90,   -90,    -1,    70,   -90,
     -90,   -11,   102,    69,    -2,   -90,   -90,    72,    73,    74,
      78,     6,     6,    47,   -90,     1,   -90,   -90,   -90,   -90,
     -90,    77,   -90,   -90,   -90,   -90,    79,    81,   -90,    60,
      -6,   -90,    60,    60,    82,   -90,    17,    51,   -90,     6,
      95,    49,    58,   -90,   -90,   -90,   -90,    23,   115,    87,
       6,     6,   -90,   -20,   -90,    -1,     6,   -11,   -90,     9,
     -90,    83,    85,    36,    84,     6,   -90,     6,    86,    -1,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
       6,    23,   -90,   -90,   -90,   -90,    23,    58,    -1,   -90,
     -90,    88,    91,    76,    93,     6,   -90,   -90,    89,    -6,
      97,    60,    -6,    98,   114,    96,   -90,   132,    41,    58,
     -90,   -90,   -90,     6,   -90,   -90,   100,   126,   -90,   108,
      59,   -90,     7,     6,   -90,    -1,   -90,   -90,    -6,   -90,
     103,    -6,   -90,    94,   107,   -90,   -90,   -90,   -90,     7,
     -90,   -90,   -90,   138,   109,    -1,   -90,   -90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   146,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   145,   139,   131,   -90,   133,   -90,   -18,    90,   -90,
     -90,   -23,   -90,   -89,   -90,   -90,   -90,   -90,   -90,   -32,
     -90,   -90,   -90,    67,   -48,   -90,   -90,    39,   -90,   -72,
     -90,    34,    92,   -90,   -36,   -90,   -90,    55,   -90,   -22,
     -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    61,    47,    80,    88,    37,   136,    44,    67,    28,
      75,    50,    94,    51,   172,   127,    29,    63,    64,     4,
     147,    75,   134,    76,    33,    34,    52,    75,    65,    21,
     135,   108,    30,    12,    63,    64,    22,    53,   100,   151,
      76,    33,    70,   133,    77,    78,    95,    99,   137,   149,
     103,   103,    33,   139,    79,    77,    78,   144,     1,    61,
     110,    77,    78,   122,    67,    79,   123,     3,   110,   111,
     112,    79,     5,    61,   124,     6,   177,   111,   112,    33,
     142,   113,   114,   115,   116,   117,   118,   156,   125,    89,
       9,    12,    61,    89,    15,    90,   187,    91,    17,   107,
      37,    91,    33,   171,    35,   166,    36,   158,    45,    46,
     161,    41,    62,    68,    69,   176,    74,    71,   109,   160,
      98,    72,    73,    96,   128,   129,    97,   154,   105,    61,
     141,   155,   140,   143,   153,   146,   178,   152,   163,   180,
     157,   159,   165,   162,   168,   164,   169,   185,   179,    61,
     181,   167,   182,    13,   186,    16,    39,    32,    40,   148,
     150,   184,   145,   104,   138,     0,     0,     0,   106
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-90))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      23,    37,    34,    51,    52,     6,    95,    29,    41,    15,
       4,    12,    11,    14,     7,    87,    22,    28,    29,     0,
     109,     4,    42,    17,    43,    44,    27,     4,    39,    13,
      50,    79,    38,    26,    28,    29,    20,    38,    70,   128,
      17,    43,    44,    91,    38,    39,    45,    69,    96,   121,
      72,    73,    43,    44,    48,    38,    39,   105,    21,    95,
      19,    38,    39,     5,    97,    48,     8,    38,    19,    28,
      29,    48,    45,   109,    16,    25,   165,    28,    29,    43,
      44,    32,    33,    34,    35,    36,    37,   135,    30,    42,
      38,    26,   128,    42,    32,    48,   185,    50,    38,    48,
       6,    50,    43,    44,    38,   153,    38,   139,    45,    38,
     142,    50,    42,    11,    45,   163,    38,    45,    23,   141,
      39,    48,    48,    46,     9,    38,    47,    51,    46,   165,
      45,    38,    49,    49,    43,    49,   168,    49,    24,   171,
      51,    44,    10,    45,    18,    49,    38,     9,    45,   185,
     173,    51,    45,     7,    45,    10,    25,    18,    25,   120,
     126,   179,   107,    73,    97,    -1,    -1,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    55,    38,     0,    45,    25,    56,    59,    38,
      60,    65,    26,    57,    61,    32,    65,    38,    62,    66,
     103,    13,    20,    58,    63,    64,    67,    69,    15,    22,
      38,    83,    66,    43,    44,    38,    38,     6,    75,    67,
      69,    50,    85,    86,   103,    45,    38,    83,    70,    68,
      12,    14,    27,    38,    75,    76,    77,    78,    79,    80,
      81,    98,    42,    28,    29,    39,    87,   104,    11,    45,
      44,    45,    48,    48,    38,     4,    17,    38,    39,    48,
      88,    91,    93,    95,    96,    97,    98,   104,    88,    42,
      48,    50,    99,   100,    11,    45,    46,    47,    39,   103,
      83,    72,    73,   103,    72,    46,    96,    48,    88,    23,
      19,    28,    29,    32,    33,    34,    35,    36,    37,    89,
      90,    92,     5,     8,    16,    30,    94,    93,     9,    38,
      88,   101,   102,    88,    42,    50,    77,    88,    87,    44,
      49,    45,    44,    49,    88,   101,    49,    77,    91,    93,
      95,    77,    49,    43,    51,    38,    88,    51,    83,    44,
     103,    83,    45,    24,    49,    10,    88,    51,    18,    38,
      84,    44,     7,    57,    71,    74,    88,    77,    83,    45,
      83,    75,    45,    82,    71,     9,    45,    77
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
#line 138 "parser.y"
    { cout << "program" << endl;
      string id((yyvsp[(2) - (8)].sval));
      symTable[id].first = 0;
      symTable[id].second = "nil";
    }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 150 "parser.y"
    { cout << "type_definition_more" << endl; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 151 "parser.y"
    { cout << "type_definition" << endl; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 155 "parser.y"
    { cout << "variable_declaration_more" << endl; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 156 "parser.y"
    {cout << "variable_declaration" << endl; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { cout << "sub_program_declarations_more" << endl; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 161 "parser.y"
    { cout << "sub_program_declarations_more" << endl; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 162 "parser.y"
    { cout << "sub_program_declarations" << endl; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 163 "parser.y"
    { cout << "sub_program_declarations" << endl; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    { cout << "type_definition" << endl;
      string type((yyvsp[(3) - (4)].sval));
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        addSymbol((yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].sval));
        addSymbol((yyvsp[(3) - (4)].sval), nilStr);
      } else if (type.compare(rec) == 0) {
        string id((yyvsp[(1) - (4)].sval));
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = recSavedAddr;
          symTable[id].second = string((yyvsp[(3) - (4)].sval)); 
        }
      } else {
        string id((yyvsp[(1) - (4)].sval));
        if (symTable.find(id) == symTable.end()) {
          symTable[id].first = arrSavedAddr;
          symTable[id].second = string((yyvsp[(3) - (4)].sval)); 
        }
      }
    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { cout << "variable_declaration" << endl;
      vector<string> ids = split((yyvsp[(1) - (4)].sval));
      for (vector<string>::iterator it = ids.begin(); it != ids.end(); ++it) {
        addSymbol(*it, (yyvsp[(3) - (4)].sval));
      }
      string type((yyvsp[(3) - (4)].sval));
      if (type.compare(rec) != 0 && type.compare(arr) !=0) {
        if (symTable.find(type) == symTable.end()) {
          addSymbol((yyvsp[(3) - (4)].sval), nilStr);
        }
      }
    }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 200 "parser.y"
    {
    stringstream ss;
    ss << (yyvsp[(2) - (2)].sval) << ": NULL";
    addQuadruple(ss.str(), "NULL", "NULL", "NULL");
    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    { cout << "procedure_declaration" << endl;
      string id((yyvsp[(2) - (9)].sval));
      if (symTable.find(id) != symTable.end()) {
        int addr = symTable[id].first;
        fixAddress(addr);
      }
      symTable[id].first = procSavedAddr;
      ostringstream convert;
      convert << (yyvsp[(5) - (9)].ival);
      symTable[id].second = convert.str(); 

      addQuadruple("return", "NULL", "NULL", "NULL"); 
    }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 221 "parser.y"
    {
    stringstream ss;
    ss << (yyvsp[(2) - (2)].sval) << ": NULL";
    addQuadruple(ss.str(), "NULL", "NULL", "NULL");
    }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    { cout << "function_declaration" << endl;
      string id((yyvsp[(2) - (11)].sval));
      // This might have flaws.
      if (symTable.find(id) != symTable.end()) {
        if (symTable[id].first > funcSavedAddr) {
          int addr = symTable[id].first;
          fixAddress(addr);
          symTable[id].first = funcSavedAddr;
          ostringstream convert;
          convert << (yyvsp[(5) - (11)].ival);
          symTable[id].second = convert.str();
        } else {
          fixAddress(funcSavedAddr);
          ostringstream convert;
          convert << (yyvsp[(5) - (11)].ival);
          symTable[id].second = convert.str();
        }
      } else {
        symTable[id].first = funcSavedAddr;
        ostringstream convert;
        convert << (yyvsp[(5) - (11)].ival);
        symTable[id].second = convert.str();
      }

      ++counter; 
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple("funreturn", newTemp, "NULL", "NULL");
    }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 261 "parser.y"
    { cout << "formal_parameter_list" << endl; (yyval.ival) = (yyvsp[(1) - (1)].ival); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 262 "parser.y"
    { (yyval.ival) = 0; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 265 "parser.y"
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
      (yyval.ival) = (yyvsp[(1) - (5)].ival) + ids.size();
    }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 279 "parser.y"
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
      }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 293 "parser.y"
    { cout << "block" << endl; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 295 "parser.y"
    {
    cout << "compound_statement" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(2) - (3)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(2) - (3)].sval));
    }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 301 "parser.y"
    {
    cout << "statement_sequence_more" << endl;
    stringstream ss;
    ss << (yyvsp[(1) - (3)].sval) << " " << (yyvsp[(3) - (3)].sval);
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 308 "parser.y"
    {
    cout << "statement_sequence" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 314 "parser.y"
    { cout << "statement" << endl; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 315 "parser.y"
    { cout << "statement" << endl; }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 317 "parser.y"
    {
    cout << "simple_statement" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 322 "parser.y"
    {
    cout << "simple_statement" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 327 "parser.y"
    { cout << "simple_statement_empty" << endl;
    stringstream ss;
    ss << quadruples.size() - 1 << " " << quadruples.size() - 1; 
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 334 "parser.y"
    {
    cout << "assignment_statement" << endl;

    // lab4
    addQuadruple(string((yyvsp[(2) - (3)].sval)), string((yyvsp[(3) - (3)].sval)), string("NULL"), string((yyvsp[(1) - (3)].sval)));
    stringstream ss;
    ss << quadruples.size() - 1 << " " << quadruples.size() - 1; 
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 345 "parser.y"
    {
    cout << "procedure_statement" << endl;
    string id((yyvsp[(1) - (4)].sval));
    if (symTable.find(id) == symTable.end()) {
      addSymbol((yyvsp[(1) - (4)].sval), nilStr);
    };

    // lab4
    addQuadruple("call", string((yyvsp[(1) - (4)].sval)), "NULL", "NULL");
    stringstream ss;
    ss << quadruples.size() - 1 << " " << quadruples.size() - 1; 
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 360 "parser.y"
    {
    cout << "compound_statement" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 365 "parser.y"
    {
    cout << "if_statement" << endl;
    int beginIndex = getQuadrupleIndex(string((yyvsp[(2) - (4)].sval)));
    vector<string> indexes = split((yyvsp[(4) - (4)].sval));
    stringstream ss;
    ss << beginIndex << " " << indexes.back();
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());

    ++labelCounter;
    ss.str(string());
    ss << "L" << labelCounter;
    string newLabel = ss.str();
    addQuadruple("NULL", "NULL", "NULL", "NULL");
    addLabelToQuad(quadruples.size() - 1, newLabel);
    if (isQuadOpAssign(beginIndex)) {
      changeQuadToCondExp(beginIndex, "=", "false", newLabel);
    } else {
      flipQuadRelOp(beginIndex);
      modifyQuadResult(beginIndex, newLabel);
    }
    }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 387 "parser.y"
    {
    cout << "ifelse_statement" << endl;
    int beginIndex = getQuadrupleIndex(string((yyvsp[(2) - (6)].sval)));
    vector<string> indexes = split((yyvsp[(6) - (6)].sval));
    stringstream ss;
    ss << beginIndex << " " << indexes.back();
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());

    ++labelCounter;
    ss.str(string());
    ss << "L" << labelCounter;
    string newLabel = ss.str();
    if (isQuadOpAssign(beginIndex)) {
      changeQuadToCondExp(beginIndex, "=", "false", newLabel);
    } else {
      flipQuadRelOp(beginIndex);
      modifyQuadResult(beginIndex, newLabel);
    }
    indexes = split((yyvsp[(4) - (6)].sval));
    int labelQuadIndex = atoi(indexes.back().c_str()) + 1; 
    if (labelQuadIndex >= quadruples.size()) {
      addQuadruple("NULL", "NULL", "NULL", "NULL");
      addLabelToQuad(labelQuadIndex, newLabel);
    } else {
      addLabelToQuad(labelQuadIndex, newLabel);
    }
    }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 415 "parser.y"
    {
    cout << "while_statement" << endl;
    int beginIndex = getQuadrupleIndex(string((yyvsp[(2) - (4)].sval)));
    vector<string> indexes = split((yyvsp[(4) - (4)].sval));
    stringstream ss;
    ss << beginIndex << " " << indexes.back();
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());

    ++labelCounter;
    ss.str(string());
    ss << "L" << labelCounter;
    string newLabel = ss.str();
    addLabelToQuad(beginIndex, newLabel);
    addQuadruple("goto", "NULL", "NULL", newLabel);
    ++labelCounter;
    ss.str(string());
    ss << "L" << labelCounter;
    newLabel = ss.str();
    addQuadruple("NULL", "NULL", "NULL", "NULL");
    addLabelToQuad(quadruples.size() - 1, newLabel);
    if (isQuadOpAssign(beginIndex)) {
      changeQuadToCondExp(beginIndex, "=", "false", newLabel);
    } else {
      flipQuadRelOp(beginIndex);
      modifyQuadResult(beginIndex, newLabel);
    }
    }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 443 "parser.y"
    {
    addQuadruple(":=", string((yyvsp[(4) - (6)].sval)), "NULL", string((yyvsp[(2) - (6)].sval)));
    addQuadruple(">", string((yyvsp[(2) - (6)].sval)), string((yyvsp[(6) - (6)].sval)), "NULL");
    (yyval.ival) = quadruples.size() - 1;
    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 448 "parser.y"
    {
    cout << "for_statement" << endl;
    int beginIndex = getQuadrupleIndex(string((yyvsp[(4) - (9)].sval)));
    vector<string> indexes = split((yyvsp[(9) - (9)].sval));
    stringstream ss;
    ss << beginIndex << " " << indexes.back();
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());

    ++labelCounter;
    ss.str(string());
    ss << "L" << labelCounter;
    string newLabel = ss.str();
    int forCondQuadIndex = (yyvsp[(7) - (9)].ival);
    addLabelToQuad(forCondQuadIndex, newLabel);
    addQuadruple("+", string((yyvsp[(2) - (9)].sval)), "1", string((yyvsp[(2) - (9)].sval)));
    addQuadruple("goto", "NULL", "NULL", newLabel);
    ++labelCounter;
    ss.str(string());
    ss << "L" << labelCounter;
    newLabel = ss.str();
    addQuadruple("NULL", "NULL", "NULL", "NULL");
    addLabelToQuad(quadruples.size() - 1, newLabel);
    modifyQuadResult(forCondQuadIndex, newLabel);
    }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 474 "parser.y"
    { cout << "type_ID" << endl; //addSymbol($1, nilStr);
                 (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
                 strcpy((yyval.sval), (yyvsp[(1) - (1)].sval)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 478 "parser.y"
    { cout << "type_array" << endl;
        (yyval.sval) = (char*) malloc(sizeof(arrayStr));;
        strcpy((yyval.sval), arrayStr); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 482 "parser.y"
    { cout << "type_record" << endl;
        (yyval.sval) = (char*) malloc(sizeof(recordStr));;
        strcpy((yyval.sval), recordStr); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 486 "parser.y"
    { cout << "result_type" << endl;
    string id((yyvsp[(1) - (1)].sval));
    if (symTable.find(id) == symTable.end()) {
      addSymbol((yyvsp[(1) - (1)].sval), nilStr);
    };
    }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 493 "parser.y"
    { cout << "field_list" << endl; }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 494 "parser.y"
    { cout << "field_list_empty" << endl; }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 497 "parser.y"
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
      
    }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 511 "parser.y"
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
    }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 524 "parser.y"
    { cout << "constant" << endl; }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 525 "parser.y"
    { cout << "constant" << endl; }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 527 "parser.y"
    {
    cout << "expression" << endl;
    if ((yyvsp[(2) - (2)].sval) == NULL) {
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (2)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (2)].sval));
    } else {
      vector<string> opAndArg = split((yyvsp[(2) - (2)].sval));
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(opAndArg[0], string((yyvsp[(1) - (2)].sval)), opAndArg[1], newTemp);
      (yyval.sval) = (char*) malloc(newTemp.length() + 1);
      strcpy((yyval.sval), newTemp.c_str());
    }
    }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 544 "parser.y"
    {
    stringstream ss;
    ss << (yyvsp[(1) - (2)].sval) << " " << (yyvsp[(2) - (2)].sval);
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 550 "parser.y"
    { (yyval.sval) = NULL; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 552 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 556 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 560 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 564 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 568 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 572 "parser.y"
    { cout << "relational_op" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 577 "parser.y"
    { cout << "simple_expression" << endl;
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(string((yyvsp[(1) - (2)].sval)), string((yyvsp[(2) - (2)].sval)), string("NULL"), newTemp);
    (yyval.sval) = (char*) malloc(newTemp.length() + 1);
    strcpy((yyval.sval), newTemp.c_str());
    }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 586 "parser.y"
    { cout << "simple_expression" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 590 "parser.y"
    { cout << "simple_expression_more" << endl;
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(string((yyvsp[(2) - (3)].sval)), string((yyvsp[(1) - (3)].sval)), string((yyvsp[(3) - (3)].sval)), newTemp);
    (yyval.sval) = (char*) malloc(newTemp.length() + 1);
    strcpy((yyval.sval), newTemp.c_str());
    }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 600 "parser.y"
    { cout << "addop" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 604 "parser.y"
    { cout << "addop" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 608 "parser.y"
    { cout << "addop" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 613 "parser.y"
    { cout << "term_more" << endl;
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(string((yyvsp[(2) - (3)].sval)), string((yyvsp[(1) - (3)].sval)), string((yyvsp[(3) - (3)].sval)), newTemp);
    (yyval.sval) = (char*) malloc(newTemp.length() + 1);
    strcpy((yyval.sval), newTemp.c_str());
    }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 622 "parser.y"
    { cout << "term" << endl;
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
      }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 627 "parser.y"
    { cout << "mulop" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 631 "parser.y"
    { cout << "mulop" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 635 "parser.y"
    { cout << "mulop" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 639 "parser.y"
    { cout << "mulop" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 644 "parser.y"
    { cout << "factor" << endl;
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 648 "parser.y"
    { cout << "factor" << endl;
      // lab4
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(string((yyvsp[(1) - (2)].sval)), string((yyvsp[(2) - (2)].sval)), string("NULL"), newTemp);
      (yyval.sval) = (char*) malloc(newTemp.length() + 1);
      strcpy((yyval.sval), newTemp.c_str());
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 659 "parser.y"
    {
    // Lab4
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    ss.str(string());
    ss << (yyvsp[(1) - (1)].ival);
    addQuadruple(":=", ss.str(), "NULL", newTemp);
    (yyval.sval) = (char*) malloc(newTemp.length() + 1);
    strcpy((yyval.sval), newTemp.c_str());
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 671 "parser.y"
    {
      // Lab4
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(":=", string((yyvsp[(1) - (1)].sval)), string("NULL"), newTemp);
      (yyval.sval) = (char*) malloc(newTemp.length() + 1);
      strcpy((yyval.sval), newTemp.c_str());
      }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 681 "parser.y"
    {
      // lab4
      ++counter;
      stringstream ss;
      ss << "t" << counter;
      string newTemp = ss.str();
      addQuadruple(":=", string((yyvsp[(1) - (1)].sval)), string("NULL"), newTemp);
      (yyval.sval) = (char*) malloc(newTemp.length() + 1);
      strcpy((yyval.sval), newTemp.c_str());
    }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 691 "parser.y"
    {
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 695 "parser.y"
    {
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(2) - (3)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(2) - (3)].sval));
    }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 700 "parser.y"
    {
    cout << "function_reference" << endl;
    string id((yyvsp[(1) - (4)].sval));
    if (symTable.find(id) == symTable.end()) {
      addSymbol((yyvsp[(1) - (4)].sval), nilStr);
    }

    // lab4
    ++counter;
    stringstream ss;
    ss << "t" << counter;
    string newTemp = ss.str();
    addQuadruple(":=", "funcall", string((yyvsp[(1) - (4)].sval)), newTemp);
    (yyval.sval) = (char*) malloc(newTemp.length() + 1);
    strcpy((yyval.sval), newTemp.c_str());
    }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 717 "parser.y"
    { cout << "variable" << endl;
    string id((yyvsp[(1) - (2)].sval));
    if (symTable.find(id) == symTable.end()) {
      addSymbol((yyvsp[(1) - (2)].sval), nilStr);
    }

    // lab4
    if ((yyvsp[(2) - (2)].sval) == NULL) {
      (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (2)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (2)].sval));
    } else {
      stringstream ss;
      ss << (yyvsp[(1) - (2)].sval) << " " << (yyvsp[(2) - (2)].sval);
      string newTemp = processVarWithCompSel(ss.str());
      (yyval.sval) = (char*) malloc(newTemp.length() + 1);
      strcpy((yyval.sval), newTemp.c_str());
    }
    }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 736 "parser.y"
    {
    (yyval.sval) = (char*) malloc(strlen((yyvsp[(1) - (1)].sval)) + 1);
    strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
    }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 740 "parser.y"
    { cout << "component_selection_empty" << endl; (yyval.sval) = NULL; }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 742 "parser.y"
    { cout << "component_selection" << endl;
    // lab4
    stringstream ss;
    ss << (yyvsp[(1) - (2)].sval) << " " << (yyvsp[(2) - (2)].sval);
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 749 "parser.y"
    { cout << "component_selection" << endl;
    // lab4
    stringstream ss;
    ss << (yyvsp[(1) - (3)].sval) << (yyvsp[(2) - (3)].sval) << (yyvsp[(3) - (3)].sval);
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 756 "parser.y"
    { cout << "component_selection_more" << endl;
    stringstream ss;
    ss << (yyvsp[(1) - (3)].sval) << " " << (yyvsp[(2) - (3)].sval) << " " << (yyvsp[(3) - (3)].sval);
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 762 "parser.y"
    { cout << "component_selection_more" << endl;
    stringstream ss;
    ss << (yyvsp[(1) - (4)].sval) << " " << (yyvsp[(2) - (4)].sval) << (yyvsp[(3) - (4)].sval) << (yyvsp[(4) - (4)].sval);
    (yyval.sval) = (char*) malloc(ss.str().length() + 1);
    strcpy((yyval.sval), ss.str().c_str());
    }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 769 "parser.y"
    { cout << "actual_parameter_list" << endl; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 770 "parser.y"
    { cout << "actual_parameter_list_empty" << endl; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 772 "parser.y"
    {
    cout << "expressions_more" << endl;
    addQuadruple("param", string((yyvsp[(3) - (3)].sval)), string("NULL"), string("NULL"));
    }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 776 "parser.y"
    { cout << "expressions" << endl;
    addQuadruple("param", string((yyvsp[(1) - (1)].sval)), string("NULL"), string("NULL"));
    }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 781 "parser.y"
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

  case 100:

/* Line 1806 of yacc.c  */
#line 796 "parser.y"
    { cout << "identifier_list" << endl;
      (yyval.sval) = (char*) malloc (strlen((yyvsp[(1) - (1)].sval)) + 1);
      strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 800 "parser.y"
    {
      // Lab4
      (yyval.sval) = (char*) malloc(2);
      *(yyval.sval) = '+';
      *((yyval.sval) + 1) = '\0';
      }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 806 "parser.y"
    {
      // Lab4
      (yyval.sval) = (char*) malloc(2);
      *(yyval.sval) = '-';
      *((yyval.sval) + 1) = '\0';
      }
    break;



/* Line 1806 of yacc.c  */
#line 2800 "parser.tab.c"
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
#line 813 "parser.y"

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
vector<string> split(const char* ids) {
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

int getQuadrupleIndex(const string& result) {
  int index = -1;
  for (int i = 0; i < quadruples.size(); ++i) {
    vector<string> fields = split(quadruples[i].c_str());
    if (fields[3].compare(result) == 0)
      index = i; 
  } 
  return index;
}

void modifyQuadResult(int index, const string& result) {
  vector<string> fields = split(quadruples[index].c_str());
  if (fields.size() == 4) {
    stringstream ss;
    ss << fields[0] << " " << fields[1] << " " << fields[2] << " " << result;
    quadruples[index] = ss.str();
  } else {
    assert(fields.size() == 5);
    stringstream ss;
    ss << fields[0] << " " << fields[1] << " " << fields[2] << " "
        << fields[3] << " " << result;
    quadruples[index] = ss.str();
  }
}

void flipQuadRelOp(int index) {
  vector<string> fields = split(quadruples[index].c_str());
  stringstream ss;
  if (fields.size() == 4) {
    if (fields[0].compare("<") == 0)
      fields[0] = ">=";
    else if (fields[0].compare(">") == 0)
      fields[0] = "<=";
    else if (fields[0].compare("<=") == 0)
      fields[0] = ">";
    else if (fields[0].compare(">=") == 0)
      fields[0] = "<";
    else if (fields[0].compare("=") == 0)
      fields[0] = "<>";
    else {
      assert(fields[0].compare("<>") == 0);
      fields[0] = "=";
    }
    ss << fields[0] << " " << fields[1] << " " << fields[2] << " " << fields[3];
  } else {
    assert(fields.size() == 5);
    if (fields[1].compare("<") == 0)
      fields[1] = ">=";
    else if (fields[1].compare(">") == 0)
      fields[1] = "<=";
    else if (fields[1].compare("<=") == 0)
      fields[1] = ">";
    else if (fields[1].compare(">=") == 0)
      fields[1] = "<";
    else if (fields[1].compare("=") == 0)
      fields[1] = "<>";
    else {
      assert(fields[1].compare("<>") == 0);
      fields[1] = "=";
    }
    ss << fields[0] << " " << fields[1] << " " << fields[2] << " " << fields[3]
        << " " << fields[4];
  }
  quadruples[index] = ss.str();
}

void addLabelToQuad(int index, const string& label) {
  stringstream ss;
  ss << label << ": " << quadruples[index]; 
  quadruples[index] = ss.str();
}

void changeQuadToCondExp(int index, const string& op, const string& arg2,
    const string& result) {
  stringstream ss;
  vector<string> fields = split(quadruples[index].c_str());
  if (fields.size() == 4) {
    ss << op << " " << fields[1] << " " << arg2 << " " << result;
  } else {
    assert(fields.size() == 5);
    ss << fields[0] << " " << op << " " << fields[2] << " " << arg2 << " "
        << result;
  }
  quadruples[index] = ss.str();
}

bool isQuadOpAssign(int index) {
  vector<string> fields = split(quadruples[index].c_str());
  if (fields.size() == 4) {
    return fields[0].compare(":=") == 0;
  } else {
    assert(fields.size() == 5);
    return fields[1].compare(":=") == 0;
  }
}


