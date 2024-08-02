/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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

/* Line 189 of yacc.c  */
#line 1 "4-bison-code.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
	//#define YYDEBUG 1 //DEBUGGING

        extern int yylex(void);
        extern FILE *yyin, *yyout;

	extern int correct_words;
	extern int wrong_words;
	int correct_expressions = 0;
	int wrong_expressions = 0;
	int par_warn=0;

void yyerror (const char *msg);


/* Line 189 of yacc.c  */
#line 92 "4-bison-code.tab.c"

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
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DELIMITER = 258,
     IDENTIFIER = 259,
     KEYWORD = 260,
     STRING = 261,
     INTEGER = 262,
     FLOAT = 263,
     PLUS = 264,
     MOD = 265,
     MINUS = 266,
     TIMES = 267,
     DIVIDE = 268,
     PLUS_ASSIGN = 269,
     MINUS_ASSIGN = 270,
     TIMES_ASSIGN = 271,
     DIVIDE_ASSIGN = 272,
     NEG = 273,
     POWER = 274,
     COMMENT = 275,
     UNKNOWN_TOKEN = 276,
     NEWLINE = 277,
     PRINT = 278,
     LEFT_PT = 279,
     RIGHT_PT = 280,
     SEMICOLON = 281,
     ASSIGNOP = 282,
     CMP_OPERATOR = 283,
     TYPE = 284,
     SCAN = 285,
     LEN = 286,
     CMP = 287,
     COMMA = 288,
     FUNC = 289,
     LEFT_BR = 290,
     RIGHT_BR = 291,
     IF = 292,
     WHILE = 293,
     FOR = 294,
     RETURN = 295,
     DOUBLE_PLUS = 296,
     DOUBLE_MINUS = 297,
     LOGIC_OPERATOR = 298,
     LOG_NOT = 299,
     RIGHT_AR = 300,
     LEFT_AR = 301,
     AMPERSAND = 302,
     BACKSLASH_NEWLINE = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 182 "4-bison-code.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNRULES -- Number of states.  */
#define YYNSTATES  298

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    18,    20,    22,
      25,    27,    29,    31,    35,    37,    41,    43,    46,    50,
      54,    58,    63,    68,    73,    81,    89,    97,    99,   101,
     103,   105,   109,   111,   115,   116,   120,   124,   126,   130,
     133,   136,   141,   146,   151,   158,   165,   170,   176,   179,
     182,   185,   188,   193,   199,   204,   206,   209,   213,   215,
     219,   224,   229,   234,   239,   246,   253,   260,   267,   274,
     286,   293,   297,   299,   303,   307,   309,   313,   317,   321,
     325,   328,   332,   336,   340,   343,   347,   352,   354,   358,
     363,   367,   373,   381,   387,   395,   402,   409,   420,   431,
     434,   437,   440,   443,   447,   451,   455,   459,   463,   466,
     468,   470,   472,   474,   476,   478,   480,   482,   484,   486,
     489,   492,   495,   498,   500,   503,   506,   508,   510,   513,
     516
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    -1,    50,    22,    -1,    50,    86,    22,
      -1,    50,     1,    22,    -1,    50,    86,    -1,     7,    -1,
       8,    -1,    18,    51,    -1,     4,    -1,    51,    -1,     8,
      -1,     8,    33,    53,    -1,     7,    -1,     7,    33,    54,
      -1,    22,    -1,    22,    55,    -1,    46,    54,    45,    -1,
      46,    53,    45,    -1,    46,    62,    45,    -1,     4,    46,
      54,    45,    -1,     4,    46,    53,    45,    -1,     4,    46,
      62,    45,    -1,    46,    54,    45,     9,    46,    54,    45,
      -1,    46,    53,    45,     9,    46,    53,    45,    -1,    46,
      62,    45,     9,    46,    62,    45,    -1,    52,    -1,    56,
      -1,     6,    -1,    58,    -1,    58,    33,    59,    -1,     4,
      -1,     4,    33,    60,    -1,    -1,    60,    27,    60,    -1,
      60,    27,    59,    -1,     6,    -1,    62,    33,     6,    -1,
      40,     7,    -1,    40,     4,    -1,    23,    24,    62,    25,
      -1,    23,    24,    60,    25,    -1,    23,    24,    68,    25,
      -1,    23,    24,     6,    33,     4,    25,    -1,    23,    24,
       6,    33,    85,    25,    -1,    23,    24,     4,    25,    -1,
      23,    24,     4,    56,    25,    -1,    29,    60,    -1,    29,
      56,    -1,    29,    61,    -1,    35,    86,    -1,    22,    35,
      86,    22,    -1,    22,    35,    22,    67,    22,    -1,    22,
      35,    22,    67,    -1,    86,    -1,    67,    86,    -1,    67,
      55,    86,    -1,    85,    -1,    68,    33,    85,    -1,    30,
      24,     4,    25,    -1,    31,    24,     6,    25,    -1,    31,
      24,    56,    25,    -1,    31,    24,     4,    25,    -1,    32,
      24,     6,    33,     6,    25,    -1,    32,    24,     4,    33,
       4,    25,    -1,    32,    24,     6,    33,     4,    25,    -1,
      32,    24,     4,    33,     6,    25,    -1,    32,    24,    51,
      33,    51,    25,    -1,    34,     4,    24,    29,     4,    33,
      29,     4,    25,    66,    36,    -1,     4,    24,    52,    33,
      52,    25,    -1,    52,    28,    52,    -1,    74,    -1,    74,
      28,    52,    -1,    74,    28,    75,    -1,    52,    -1,    76,
       9,    76,    -1,    76,    11,    76,    -1,    76,    12,    76,
      -1,    76,    13,    76,    -1,    11,    76,    -1,    76,    19,
      76,    -1,    24,    76,    25,    -1,     4,    43,     4,    -1,
      44,     4,    -1,    74,    43,    74,    -1,    44,    25,    74,
      24,    -1,    77,    -1,    77,    43,     4,    -1,    44,    25,
      77,    24,    -1,    77,    43,    78,    -1,    37,    24,    75,
      25,    85,    -1,    37,    24,    75,    25,    35,    67,    36,
      -1,    37,    24,    78,    25,    85,    -1,    37,    24,    78,
      25,    35,    67,    36,    -1,    38,    24,    75,    25,    66,
      36,    -1,    38,    24,    78,    25,    66,    36,    -1,    39,
      24,    61,    26,    75,    26,    82,    25,    66,    36,    -1,
      39,    24,    61,    26,    78,    26,    82,    25,    66,    36,
      -1,    41,    52,    -1,    42,    52,    -1,    52,    41,    -1,
      52,    42,    -1,     4,    27,    76,    -1,     4,    27,    75,
      -1,     4,    27,    78,    -1,     4,    27,    57,    -1,     4,
      27,    58,    -1,    40,    58,    -1,    69,    -1,    70,    -1,
      64,    -1,    71,    -1,    65,    -1,    75,    -1,    78,    -1,
      79,    -1,    63,    -1,    76,    -1,    85,    26,    -1,    64,
      26,    -1,    83,    26,    -1,    61,    26,    -1,    72,    -1,
      73,    26,    -1,    76,    26,    -1,    80,    -1,    81,    -1,
      56,    26,    -1,    57,    26,    -1,    84,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    35,    36,    37,    38,    42,    43,    44,
      48,    49,    53,    54,    58,    59,    63,    64,    68,    69,
      70,    71,    72,    73,    77,    78,    79,    83,    84,    85,
      89,    90,    94,    95,    98,    99,   100,   104,   105,   109,
     110,   114,   115,   116,   117,   118,   119,   120,   124,   125,
     126,   130,   131,   132,   133,   137,   138,   139,   143,   144,
     148,   152,   153,   154,   158,   159,   160,   161,   162,   166,
     170,   174,   178,   179,   180,   184,   185,   186,   187,   188,
     189,   190,   191,   195,   196,   197,   198,   203,   204,   205,
     206,   210,   211,   212,   213,   217,   218,   222,   223,   227,
     228,   229,   230,   234,   235,   236,   237,   238,   242,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DELIMITER", "IDENTIFIER", "KEYWORD",
  "STRING", "INTEGER", "FLOAT", "PLUS", "MOD", "MINUS", "TIMES", "DIVIDE",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "TIMES_ASSIGN", "DIVIDE_ASSIGN", "NEG",
  "POWER", "COMMENT", "UNKNOWN_TOKEN", "NEWLINE", "PRINT", "LEFT_PT",
  "RIGHT_PT", "SEMICOLON", "ASSIGNOP", "CMP_OPERATOR", "TYPE", "SCAN",
  "LEN", "CMP", "COMMA", "FUNC", "LEFT_BR", "RIGHT_BR", "IF", "WHILE",
  "FOR", "RETURN", "DOUBLE_PLUS", "DOUBLE_MINUS", "LOGIC_OPERATOR",
  "LOG_NOT", "RIGHT_AR", "LEFT_AR", "AMPERSAND", "BACKSLASH_NEWLINE",
  "$accept", "program", "number", "term", "multiple_float", "multiple_int",
  "multiple_newline", "array", "array_plus", "values", "multiple_values",
  "variable_list", "assignment", "string", "ret", "print_func",
  "declaration", "multiple_expressions_functions", "multiple_expressions",
  "multiple_expressions_no_semi", "scan_func", "len_func", "cmp_func",
  "func_def", "func_call", "cmp_operator", "cmp_operator_multiple",
  "arith_operation", "logical_operator", "logical_operator_multiple",
  "if_func", "while_func", "for_func", "plus_minus", "expr_assignment",
  "return", "expr_no_semi", "expr", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    68,    68,
      69,    70,    70,    70,    71,    71,    71,    71,    71,    72,
      73,    74,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     2,     1,     1,     2,
       1,     1,     1,     3,     1,     3,     1,     2,     3,     3,
       3,     4,     4,     4,     7,     7,     7,     1,     1,     1,
       1,     3,     1,     3,     0,     3,     3,     1,     3,     2,
       2,     4,     4,     4,     6,     6,     4,     5,     2,     2,
       2,     2,     4,     5,     4,     1,     2,     3,     1,     3,
       4,     4,     4,     4,     6,     6,     6,     6,     6,    11,
       6,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       2,     3,     3,     3,     2,     3,     4,     1,     3,     4,
       3,     5,     7,     5,     7,     6,     6,    10,    10,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     1,     1,     2,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    10,     7,     8,     0,     0,     3,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    75,     0,     0,     0,     0,   117,
       0,   113,   109,   110,   112,   123,     0,    72,   114,     0,
      87,   115,   116,   126,   127,     0,     0,     0,     6,     5,
       0,     0,     0,     0,     0,    10,    75,    80,     9,     0,
       0,    32,     0,    49,    48,    50,     0,     0,     0,     0,
       0,     0,    34,    10,    29,     7,    27,    28,   108,    84,
       0,    37,    14,    12,     0,     0,     0,     0,   128,   129,
       0,   122,   120,   124,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   121,   130,   119,     4,     0,    10,    75,
     106,   107,   104,   103,   105,    32,    33,    83,     0,     0,
       0,    10,    37,     0,     0,     0,   111,     0,   118,    58,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    18,     0,    20,    71,    10,
      30,    36,    35,    73,    72,    74,    85,    76,    77,    78,
      79,    81,    88,     0,    90,     0,    22,    21,    23,     0,
      46,     0,     0,    40,    39,    42,    41,    43,     0,    19,
      18,    20,    60,    63,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    89,    15,    13,
       0,     0,    38,     0,     0,     0,    47,    10,     0,    59,
       0,     0,     0,     0,     0,     0,    34,    91,    34,    93,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    31,    70,    44,    45,    65,    67,    66,    64,    68,
       0,    34,    55,    34,    34,    51,    95,    96,     0,     0,
       0,     0,     0,     0,    16,    92,    34,    56,    94,    34,
       0,     0,     0,     0,     0,     0,    25,    24,    26,     0,
      17,    57,    34,    52,    99,   100,   101,   102,     0,     0,
       0,    16,     0,     0,     0,    97,    98,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    23,    24,    84,    85,   266,    25,    26,   160,
     161,    27,    28,    86,    29,    30,    31,   232,   251,   127,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,   274,    45,    46,    47,   252
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -235
static const yytype_int16 yypact[] =
{
    -235,   240,  -235,    14,   200,  -235,  -235,   214,   289,  -235,
      29,   214,    28,    83,   106,   152,    21,   178,   182,   190,
      31,    56,   253,  -235,    52,   133,   143,   172,   194,  -235,
     213,  -235,  -235,  -235,  -235,  -235,   230,   114,  -235,   282,
     183,  -235,  -235,  -235,  -235,   231,   247,   257,   209,  -235,
     365,   110,   283,   286,   253,  -235,  -235,   279,  -235,   205,
     323,    73,   253,  -235,   172,  -235,   296,    38,   371,   278,
      44,    44,   283,   260,  -235,  -235,  -235,  -235,  -235,  -235,
     144,  -235,   276,   290,   269,   271,    42,   365,  -235,  -235,
     118,  -235,  -235,  -235,   365,   365,   214,   214,   214,   214,
     214,  -235,   175,  -235,  -235,  -235,  -235,   291,    15,   159,
    -235,  -235,  -235,   405,  -235,   295,  -235,  -235,   277,   292,
      96,    39,   298,   171,   313,    98,  -235,   107,   405,  -235,
    -235,   294,   302,   127,   316,    43,   318,   324,   317,   330,
     331,   326,   314,    52,   340,   351,   355,   357,   358,    95,
      26,   364,   383,   388,   382,   389,   398,   396,  -235,    73,
     373,  -235,  -235,    52,   385,  -235,  -235,   263,   263,   279,
     279,   279,   115,   367,  -235,   365,  -235,  -235,  -235,   260,
    -235,   394,   554,  -235,  -235,  -235,  -235,  -235,   585,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,   192,   211,   289,   416,
     486,   520,   128,   128,    44,   365,  -235,  -235,  -235,  -235,
     375,   377,  -235,   379,   131,   406,  -235,    72,   407,  -235,
     412,   414,   415,   420,   421,   397,   445,  -235,   445,  -235,
     419,   445,   393,   411,   425,   429,   433,   388,   383,   452,
     260,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
     430,   281,  -235,   322,   404,  -235,  -235,  -235,   166,   166,
     417,   422,   135,   456,   439,  -235,   445,  -235,  -235,   445,
     442,   365,   365,   149,   440,   441,  -235,  -235,  -235,   446,
    -235,  -235,   363,  -235,  -235,  -235,  -235,  -235,   128,   128,
     128,   145,   434,   436,   437,  -235,  -235,  -235
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,    -3,    -4,   -48,   -44,  -234,   -11,   427,     3,
     266,    19,     1,   -42,  -235,   -55,  -235,  -177,  -199,  -235,
    -235,  -235,  -235,  -235,  -235,   -61,   -49,     4,   401,   -43,
    -235,  -235,  -235,   227,  -235,  -235,   -35,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      48,    63,   112,    56,   126,    58,   118,    56,   114,    77,
     119,    57,   120,    65,   131,    60,    76,   125,   132,   150,
     133,   144,   146,    78,   129,    69,   233,   145,   147,   253,
     280,    64,    61,   164,   166,    73,    49,    74,    75,     6,
      77,   173,   135,   179,   136,   165,   107,   109,   142,     8,
     206,     5,     6,    59,   111,   113,   137,   280,    53,   174,
      79,    54,     8,   128,   180,   140,   143,   143,   193,    95,
     282,   116,    52,   148,    62,   156,   143,    62,   124,    77,
      87,    80,    53,   158,    62,    62,    76,   157,    21,    54,
     163,   143,    56,    56,    56,    56,    56,   243,   143,    79,
     167,   168,   169,   170,   171,   209,    52,    66,   208,   162,
     181,   292,   293,   294,   108,    53,    74,     5,     6,    54,
     205,     7,   159,   186,    74,     5,     6,   126,     8,   156,
      67,   156,   187,   126,    11,   240,     8,    74,     5,     6,
     188,   178,    94,   -10,   236,   126,   126,   218,   142,     8,
     230,     5,     6,   219,    21,   234,    22,    95,    53,    88,
     156,   235,     8,   231,    62,   227,   229,   264,   156,    89,
      55,   215,   191,     5,     6,   183,    68,    62,   184,   172,
     278,   -53,     5,     6,     8,   -27,   128,    87,   149,   260,
     286,   287,   128,     8,   261,   224,   220,   262,   221,    90,
     143,   143,    70,    77,   128,   128,    71,   271,   272,   121,
      76,   122,     5,     6,    72,   222,     7,   223,    55,    21,
      91,     5,     6,     8,    50,     7,   102,    51,    10,    11,
     255,   106,     8,    52,    12,    13,    14,    15,    11,    92,
       2,     3,    17,    53,     4,   123,    54,     5,     6,    21,
     267,     7,   267,   270,   273,   273,    93,   103,     8,    81,
      82,    83,     9,    10,    11,   281,   -34,   284,   285,    12,
      13,    14,    15,   104,    16,    98,    99,    17,    18,    19,
      20,   267,   100,   105,    21,     4,    22,   115,     5,     6,
     117,    96,     7,    97,    98,    99,     5,     6,   100,     8,
     134,   100,   141,   264,    10,    11,    54,     8,   101,   152,
      12,    13,    14,    15,   154,    16,   155,   265,    17,    18,
      19,    20,   176,   153,   175,    21,     4,    22,    52,     5,
       6,   182,    96,     7,    97,    98,    99,   177,   185,   189,
       8,   192,   100,   194,   264,    10,    11,   190,   130,   195,
     196,    12,    13,    14,    15,   199,    16,    53,   268,    17,
      18,    19,    20,   197,   198,   200,    21,     4,    22,    55,
       5,     6,     5,     6,     7,   138,   201,   139,     5,     6,
     202,     8,   203,     8,   204,   291,    10,    11,   207,     8,
      82,   210,    12,    13,    14,    15,    83,    16,   211,   -54,
      17,    18,    19,    20,   212,   213,   214,    21,     4,    22,
      95,     5,     6,    94,    96,     7,    97,    98,    99,   216,
     225,   237,     8,   238,   100,   239,   269,    10,    11,   256,
     250,   242,   244,    12,    13,    14,    15,   245,    16,   246,
     247,    17,    18,    19,    20,   248,   249,   257,    21,     4,
      22,   258,     5,     6,   254,   259,     7,   206,    81,   263,
     279,   264,   276,     8,   283,   288,   289,   277,    10,    11,
     295,   290,   296,   297,    12,    13,    14,    15,   110,    16,
     241,   151,    17,    18,    19,    20,   275,     0,     0,    21,
     142,    22,     0,     5,     6,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,    13,    14,    15,     0,
       0,   226,     0,    17,   142,     0,   123,     5,     6,     0,
      21,     7,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
      13,    14,    15,     0,     0,   228,     0,    17,   217,     0,
     123,     5,     6,     0,    21,     7,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,    13,    14,    15,     0,     0,   142,
       0,    17,     5,     6,   123,     0,     7,     0,    21,     0,
       0,     0,     0,     8,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,    13,    14,    15,     0,     0,
       0,     0,    17,     0,     0,   123,     0,     0,     0,    21
};

static const yytype_int16 yycheck[] =
{
       1,    12,    51,     7,    59,     8,    54,    11,    51,    20,
      54,     7,    54,    12,    62,    11,    20,    59,    62,    80,
      62,    70,    71,    20,    59,     4,   203,    70,    71,   228,
     264,    12,     4,    94,    95,     4,    22,     6,     7,     8,
      51,   102,     4,     4,     6,    94,    50,    51,     4,    18,
      24,     7,     8,    24,    51,    51,    67,   291,    43,   102,
       4,    46,    18,    59,    25,    68,    70,    71,    25,    43,
     269,    52,    33,    72,    46,    33,    80,    46,    59,    90,
      28,    25,    43,    87,    46,    46,    90,    45,    44,    46,
      94,    95,    96,    97,    98,    99,   100,    25,   102,     4,
      96,    97,    98,    99,   100,   153,    33,    24,   152,    90,
     121,   288,   289,   290,     4,    43,     6,     7,     8,    46,
      25,    11,     4,    25,     6,     7,     8,   182,    18,    33,
      24,    33,    25,   188,    24,     4,    18,     6,     7,     8,
      33,    45,    28,    28,   205,   200,   201,   182,     4,    18,
      22,     7,     8,   188,    44,   204,    46,    43,    43,    26,
      33,   204,    18,    35,    46,   200,   201,    22,    33,    26,
       4,   175,    45,     7,     8,     4,    24,    46,     7,     4,
      45,    36,     7,     8,    18,    26,   182,    28,    44,   237,
      41,    42,   188,    18,   238,   198,     4,   239,     6,    27,
     204,   205,    24,   214,   200,   201,    24,    41,    42,     4,
     214,     6,     7,     8,    24,     4,    11,     6,     4,    44,
      26,     7,     8,    18,    24,    11,    43,    27,    23,    24,
     231,    22,    18,    33,    29,    30,    31,    32,    24,    26,
       0,     1,    37,    43,     4,    40,    46,     7,     8,    44,
     251,    11,   253,   254,   258,   259,    26,    26,    18,     6,
       7,     8,    22,    23,    24,   266,    26,   271,   272,    29,
      30,    31,    32,    26,    34,    12,    13,    37,    38,    39,
      40,   282,    19,    26,    44,     4,    46,     4,     7,     8,
       4,     9,    11,    11,    12,    13,     7,     8,    19,    18,
       4,    19,    24,    22,    23,    24,    46,    18,    26,    33,
      29,    30,    31,    32,    45,    34,    45,    36,    37,    38,
      39,    40,    45,    33,    33,    44,     4,    46,    33,     7,
       8,    33,     9,    11,    11,    12,    13,    45,    25,    45,
      18,    25,    19,    25,    22,    23,    24,    45,    25,    25,
      33,    29,    30,    31,    32,    29,    34,    43,    36,    37,
      38,    39,    40,    33,    33,    25,    44,     4,    46,     4,
       7,     8,     7,     8,    11,     4,    25,     6,     7,     8,
      25,    18,    25,    18,    26,    22,    23,    24,    24,    18,
       7,     9,    29,    30,    31,    32,     8,    34,     9,    36,
      37,    38,    39,    40,     6,     9,    33,    44,     4,    46,
      43,     7,     8,    28,     9,    11,    11,    12,    13,    25,
       4,    46,    18,    46,    19,    46,    22,    23,    24,    36,
      33,    25,    25,    29,    30,    31,    32,    25,    34,    25,
      25,    37,    38,    39,    40,    25,    25,    36,    44,     4,
      46,    26,     7,     8,    35,    26,    11,    24,     6,    29,
       4,    22,    45,    18,    22,    25,    25,    45,    23,    24,
      36,    25,    36,    36,    29,    30,    31,    32,    51,    34,
     214,    80,    37,    38,    39,    40,   259,    -1,    -1,    44,
       4,    46,    -1,     7,     8,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    35,    -1,    37,     4,    -1,    40,     7,     8,    -1,
      44,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    35,    -1,    37,     4,    -1,
      40,     7,     8,    -1,    44,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,     4,
      -1,    37,     7,     8,    40,    -1,    11,    -1,    44,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,     0,     1,     4,     7,     8,    11,    18,    22,
      23,    24,    29,    30,    31,    32,    34,    37,    38,    39,
      40,    44,    46,    51,    52,    56,    57,    60,    61,    63,
      64,    65,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    83,    84,    85,    86,    22,
      24,    27,    33,    43,    46,     4,    52,    76,    51,    24,
      76,     4,    46,    56,    60,    61,    24,    24,    24,     4,
      24,    24,    24,     4,     6,     7,    52,    56,    58,     4,
      25,     6,     7,     8,    53,    54,    62,    28,    26,    26,
      27,    26,    26,    26,    28,    43,     9,    11,    12,    13,
      19,    26,    43,    26,    26,    26,    22,    52,     4,    52,
      57,    58,    75,    76,    78,     4,    60,     4,    53,    54,
      62,     4,     6,    40,    60,    62,    64,    68,    76,    85,
      25,    53,    54,    62,     4,     4,     6,    56,     4,     6,
      51,    24,     4,    52,    75,    78,    75,    78,    61,    44,
      74,    77,    33,    33,    45,    45,    33,    45,    52,     4,
      58,    59,    60,    52,    74,    75,    74,    76,    76,    76,
      76,    76,     4,    74,    78,    33,    45,    45,    45,     4,
      25,    56,    33,     4,     7,    25,    25,    25,    33,    45,
      45,    45,    25,    25,    25,    25,    33,    33,    33,    29,
      25,    25,    25,    25,    26,    25,    24,    24,    54,    53,
       9,     9,     6,     9,    33,    52,    25,     4,    85,    85,
       4,     6,     4,     6,    51,     4,    35,    85,    35,    85,
      22,    35,    66,    66,    75,    78,    74,    46,    46,    46,
       4,    59,    25,    25,    25,    25,    25,    25,    25,    25,
      33,    67,    86,    67,    35,    86,    36,    36,    26,    26,
      53,    54,    62,    29,    22,    36,    55,    86,    36,    22,
      86,    41,    42,    52,    82,    82,    45,    45,    45,     4,
      55,    86,    67,    22,    52,    52,    41,    42,    25,    25,
      25,    22,    66,    66,    66,    36,    36,    36
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
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 5:

/* Line 1464 of yacc.c  */
#line 37 "4-bison-code.y"
    { printf("\tERROR !\n"); yyerrok; wrong_expressions++; ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 259 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 260 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 261 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 262 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 263 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 264 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 265 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 266 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 267 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 268 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 269 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 270 "4-bison-code.y"
    { correct_expressions++; ;}
    break;



/* Line 1464 of yacc.c  */
#line 1803 "4-bison-code.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1684 of yacc.c  */
#line 273 "4-bison-code.y"


int main(int argc, char **argv) {
	//yydebug=1;

	if (argc == 3) {
		if (!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
		if (!(yyout = fopen(argv[2], "w"))) {
			fprintf(stderr, "Cannot create file: %s\n", argv[2]);
			fclose(yyin);
			return 1;
		}
	} else if (argc == 2) {
		if (!(yyin = fopen(argv[1], "r"))) {
			fprintf(stderr, "Cannot read file: %s\n", argv[1]);
			return 1;
		}
        yyout = stdout;
	} else {
		fprintf(stderr, "Usage: %s input (output)\n", *argv);
		return 2;
	}

   int ret = yyparse();
if (wrong_expressions==0 && ret==0) { 
    printf("\t\tBison -> PARSING SUCCEEDED.\n");
    if (par_warn > 0) printf(" (with %d warning(s))\n", par_warn);
        printf("\n");
} else {
    printf("\t\tBison -> PARSING FAILED (%d syntax error(s) found).\n", wrong_expressions);
} 
	fprintf(yyout, "\nCorrect Words: %d\n", correct_words);
	fprintf(yyout, "Correct Expressions: %d\n", correct_expressions);
	fprintf(yyout, "Wrong Words: %d\n", wrong_words);
	fprintf(yyout, "Wrong Expressions: %d\n", wrong_expressions);

	if (yyin) fclose(yyin);
	if (yyout && yyout != stdout) fclose(yyout);
	
	return 0;
	
}
