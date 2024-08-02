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
#line 29 "4-bison-code.y"


/* Δήλωση των header files (αρχείων επικεφαλίδας) και δηλώση σταθεράς. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
	//#define YYDEBUG 1 //DEBUGGING


/* Ο δείκτης yyin είναι αυτός που δείχενει στο αρχείο εισόδου. */

    extern int yylex(void);
    extern FILE *yyin, *yyout;

	extern int correct_words;
	extern int wrong_words;
	int correct_expressions = 0;
	int wrong_expressions = 0;
	int par_warn=0;

/* Η συνάρτηση yyerror χρησιμοποιείται για την αναφορά σφαλμάτων. Καλείται από την 
   yyparse όταν υπάρξει κάποιο συντακτικό λάθος. */

void yyerror (const char *msg);


/* Line 189 of yacc.c  */
#line 100 "4-bison-code.tab.c"

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
     MINUS = 265,
     TIMES = 266,
     DIVIDE = 267,
     POWER = 268,
     COMMENT = 269,
     NEG = 270,
     UNKNOWN_TOKEN = 271,
     NEWLINE = 272,
     MINUS_ASSIGN = 273,
     PLUS_ASSIGN = 274,
     TIMES_ASSIGN = 275,
     MOD = 276,
     BACKSLASH_NEWLINE = 277,
     DIVIDE_ASSIGN = 278,
     PRINT = 279,
     LEFT_PT = 280,
     RIGHT_PT = 281,
     SEMICOLON = 282,
     ASSIGNOP = 283,
     CMP_OPERATOR = 284,
     TYPE = 285,
     SCAN = 286,
     LEN = 287,
     CMP = 288,
     COMMA = 289,
     FUNC = 290,
     LEFT_BR = 291,
     RIGHT_BR = 292,
     IF = 293,
     WHILE = 294,
     FOR = 295,
     RETURN = 296,
     DOUBLE_PLUS = 297,
     DOUBLE_MINUS = 298,
     LOGIC_OPERATOR = 299,
     LOG_NOT = 300,
     RIGHT_AR = 301,
     LEFT_AR = 302,
     AMPERSAND = 303
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
#line 190 "4-bison-code.tab.c"

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
#define YYLAST   613

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNRULES -- Number of states.  */
#define YYNSTATES  308

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
     133,   136,   141,   146,   151,   158,   165,   170,   176,   181,
     184,   187,   190,   193,   198,   204,   209,   211,   214,   218,
     220,   224,   229,   234,   239,   246,   253,   260,   267,   274,
     286,   293,   297,   299,   303,   307,   309,   313,   317,   321,
     325,   328,   332,   336,   340,   344,   348,   352,   356,   359,
     363,   368,   370,   374,   379,   383,   389,   397,   403,   411,
     418,   425,   436,   447,   450,   453,   456,   459,   463,   467,
     471,   475,   479,   482,   484,   486,   488,   490,   492,   494,
     496,   498,   500,   502,   504,   507,   510,   513,   516,   518,
     521,   524,   526,   528,   531,   534
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    -1,    50,    17,    -1,    50,    87,    17,
      -1,    50,     1,    17,    -1,    50,    87,    -1,     7,    -1,
       8,    -1,    15,    51,    -1,     4,    -1,    51,    -1,     8,
      -1,     8,    34,    53,    -1,     7,    -1,     7,    34,    54,
      -1,    17,    -1,    17,    55,    -1,    47,    54,    46,    -1,
      47,    53,    46,    -1,    47,    62,    46,    -1,     4,    47,
      54,    46,    -1,     4,    47,    53,    46,    -1,     4,    47,
      62,    46,    -1,    47,    54,    46,     9,    47,    54,    46,
      -1,    47,    53,    46,     9,    47,    53,    46,    -1,    47,
      62,    46,     9,    47,    62,    46,    -1,    52,    -1,    56,
      -1,     6,    -1,    58,    -1,    58,    34,    59,    -1,     4,
      -1,     4,    34,    60,    -1,    -1,    60,    28,    60,    -1,
      60,    28,    59,    -1,     6,    -1,    62,    34,     6,    -1,
      41,     7,    -1,    41,     4,    -1,    24,    25,    62,    26,
      -1,    24,    25,    60,    26,    -1,    24,    25,    69,    26,
      -1,    24,    25,     6,    34,     4,    26,    -1,    24,    25,
       6,    34,    86,    26,    -1,    24,    25,     4,    26,    -1,
      24,    25,     4,    56,    26,    -1,    31,    25,     4,    26,
      -1,    30,    60,    -1,    30,    56,    -1,    30,    61,    -1,
      36,    87,    -1,    17,    36,    87,    17,    -1,    17,    36,
      17,    68,    17,    -1,    17,    36,    17,    68,    -1,    87,
      -1,    68,    87,    -1,    68,    55,    87,    -1,    86,    -1,
      69,    34,    86,    -1,    32,    25,     6,    26,    -1,    32,
      25,    56,    26,    -1,    32,    25,     4,    26,    -1,    33,
      25,     6,    34,     6,    26,    -1,    33,    25,     4,    34,
       4,    26,    -1,    33,    25,     6,    34,     4,    26,    -1,
      33,    25,     4,    34,     6,    26,    -1,    33,    25,    51,
      34,    51,    26,    -1,    35,     4,    25,    30,     4,    34,
      30,     4,    26,    67,    37,    -1,     4,    25,    52,    34,
      52,    26,    -1,    52,    29,    52,    -1,    74,    -1,    74,
      29,    52,    -1,    74,    29,    75,    -1,    52,    -1,    76,
       9,    76,    -1,    76,    10,    76,    -1,    76,    11,    76,
      -1,    76,    12,    76,    -1,    10,    76,    -1,    76,    13,
      76,    -1,    25,    76,    26,    -1,     4,    19,    52,    -1,
       4,    18,    52,    -1,     4,    20,    52,    -1,     4,    23,
      52,    -1,     4,    44,     4,    -1,    45,     4,    -1,    74,
      44,    74,    -1,    45,    26,    74,    25,    -1,    78,    -1,
      78,    44,     4,    -1,    45,    26,    78,    25,    -1,    78,
      44,    79,    -1,    38,    25,    75,    26,    86,    -1,    38,
      25,    75,    26,    36,    68,    37,    -1,    38,    25,    79,
      26,    86,    -1,    38,    25,    79,    26,    36,    68,    37,
      -1,    39,    25,    75,    26,    67,    37,    -1,    39,    25,
      79,    26,    67,    37,    -1,    40,    25,    61,    27,    75,
      27,    83,    26,    67,    37,    -1,    40,    25,    61,    27,
      79,    27,    83,    26,    67,    37,    -1,    42,    52,    -1,
      43,    52,    -1,    52,    42,    -1,    52,    43,    -1,     4,
      28,    76,    -1,     4,    28,    75,    -1,     4,    28,    79,
      -1,     4,    28,    57,    -1,     4,    28,    58,    -1,    41,
      58,    -1,    65,    -1,    70,    -1,    64,    -1,    71,    -1,
      66,    -1,    75,    -1,    79,    -1,    80,    -1,    63,    -1,
      76,    -1,    77,    -1,    86,    27,    -1,    64,    27,    -1,
      84,    27,    -1,    61,    27,    -1,    72,    -1,    73,    27,
      -1,    76,    27,    -1,    81,    -1,    82,    -1,    56,    27,
      -1,    57,    27,    -1,    85,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    81,    82,    83,    84,    88,    89,    90,
      94,    95,    99,   100,   104,   105,   109,   110,   114,   115,
     116,   117,   118,   119,   123,   124,   125,   129,   130,   131,
     135,   136,   140,   141,   144,   145,   146,   150,   151,   155,
     156,   160,   161,   162,   163,   164,   165,   166,   170,   174,
     175,   176,   180,   181,   182,   183,   187,   188,   189,   193,
     194,   198,   199,   200,   204,   205,   206,   207,   208,   212,
     216,   220,   224,   225,   226,   230,   231,   232,   233,   234,
     236,   237,   238,   242,   243,   244,   245,   249,   250,   251,
     252,   257,   258,   259,   260,   264,   265,   266,   267,   271,
     272,   276,   277,   281,   282,   283,   284,   288,   289,   290,
     291,   292,   296,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DELIMITER", "IDENTIFIER", "KEYWORD",
  "STRING", "INTEGER", "FLOAT", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "POWER", "COMMENT", "NEG", "UNKNOWN_TOKEN", "NEWLINE", "MINUS_ASSIGN",
  "PLUS_ASSIGN", "TIMES_ASSIGN", "MOD", "BACKSLASH_NEWLINE",
  "DIVIDE_ASSIGN", "PRINT", "LEFT_PT", "RIGHT_PT", "SEMICOLON", "ASSIGNOP",
  "CMP_OPERATOR", "TYPE", "SCAN", "LEN", "CMP", "COMMA", "FUNC", "LEFT_BR",
  "RIGHT_BR", "IF", "WHILE", "FOR", "RETURN", "DOUBLE_PLUS",
  "DOUBLE_MINUS", "LOGIC_OPERATOR", "LOG_NOT", "RIGHT_AR", "LEFT_AR",
  "AMPERSAND", "$accept", "program", "number", "term", "multiple_float",
  "multiple_int", "multiple_newline", "array", "array_plus", "values",
  "multiple_values", "variable_list", "assignment", "string", "ret",
  "print_func", "scan_func", "declaration",
  "multiple_expressions_functions", "multiple_expressions",
  "multiple_expressions_no_semi", "len_func", "cmp_func", "func_def",
  "func_call", "cmp_operator", "cmp_operator_multiple", "arith_operation",
  "augmented_assignments", "logical_operator", "logical_operator_multiple",
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
      63,    64,    64,    64,    64,    64,    64,    64,    65,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    70,    71,    71,    71,    71,    71,    72,
      73,    74,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    84,    84,    84,
      84,    84,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     2,     1,     1,     2,
       1,     1,     1,     3,     1,     3,     1,     2,     3,     3,
       3,     4,     4,     4,     7,     7,     7,     1,     1,     1,
       1,     3,     1,     3,     0,     3,     3,     1,     3,     2,
       2,     4,     4,     4,     6,     6,     4,     5,     4,     2,
       2,     2,     2,     4,     5,     4,     1,     2,     3,     1,
       3,     4,     4,     4,     6,     6,     6,     6,     6,    11,
       6,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       4,     1,     3,     4,     3,     5,     7,     5,     7,     6,
       6,    10,    10,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    10,     7,     8,     0,     0,     3,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    75,     0,     0,     0,     0,   121,
       0,   113,   117,   114,   116,   128,     0,    72,   118,     0,
     123,    91,   119,   120,   131,   132,     0,     0,     0,     6,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    75,    80,     9,     0,     0,    32,     0,    50,    49,
      51,     0,     0,     0,     0,     0,     0,    34,    10,    29,
       7,    27,    28,   112,    88,     0,    37,    14,    12,     0,
       0,     0,     0,   133,   134,     0,   127,   125,   129,     0,
       0,     0,     0,     0,     0,     0,   130,     0,   126,   135,
     124,     4,    84,    83,    85,    86,     0,    10,    75,   110,
     111,   108,   107,   109,    32,    33,    87,     0,     0,     0,
      10,    37,     0,     0,     0,   115,     0,   122,    59,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    18,     0,    20,    71,    10,    30,
      36,    35,    73,    72,    74,    89,    76,    77,    78,    79,
      81,    92,     0,    94,     0,    22,    21,    23,     0,    46,
       0,     0,    40,    39,    42,    41,    43,     0,    19,    18,
      20,    48,    63,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    93,    15,    13,     0,
       0,    38,     0,     0,     0,    47,    10,     0,    10,    60,
       0,     0,     0,     0,     0,     0,    34,    95,    34,    97,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    31,    70,    44,    45,    65,    67,    66,    64,    68,
       0,    34,    56,    34,    34,    52,    99,   100,     0,     0,
       0,     0,     0,     0,    16,    96,    34,    57,    98,    34,
       0,     0,     0,     0,     0,     0,    25,    24,    26,     0,
      17,    58,    34,    53,   103,   104,   105,   106,     0,     0,
       0,    16,     0,     0,     0,   101,   102,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    23,    24,    89,    90,   276,    25,    26,   169,
     170,    27,    28,    91,    29,    30,    31,    32,   242,   261,
     136,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   284,    46,    47,    48,   262
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -235
static const yytype_int16 yypact[] =
{
    -235,   272,  -235,    24,   566,  -235,  -235,   554,   200,  -235,
       2,   554,    15,    48,    52,    69,    30,    85,   106,   144,
      31,    49,   220,  -235,   148,   151,   154,   161,   156,  -235,
     163,  -235,  -235,  -235,  -235,  -235,   165,    45,  -235,   499,
    -235,   150,  -235,  -235,  -235,  -235,   169,   171,   172,   186,
    -235,   228,   228,   228,   228,   228,   119,   201,   207,   220,
    -235,  -235,   203,  -235,   436,   586,    35,   220,  -235,   161,
    -235,   213,    38,   286,   195,   226,   226,   201,   176,  -235,
    -235,  -235,  -235,  -235,  -235,   449,  -235,   208,   216,   191,
     202,    82,   228,  -235,  -235,   141,  -235,  -235,  -235,   228,
     228,   554,   554,   554,   554,   554,  -235,   468,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,   240,    43,    93,  -235,
    -235,  -235,   257,  -235,   247,  -235,  -235,   249,   252,   104,
     153,   266,   155,   260,    98,  -235,   134,   257,  -235,  -235,
     262,   268,   112,   280,    17,   289,   290,   291,   292,   293,
     298,   276,   148,   297,   304,   306,   307,   308,    76,    92,
     309,   329,   334,   347,   351,   356,   358,  -235,    35,   335,
    -235,  -235,   148,   346,  -235,  -235,   245,   245,   203,   203,
     203,    86,   332,  -235,   228,  -235,  -235,  -235,   176,  -235,
     355,   510,  -235,  -235,  -235,  -235,  -235,   542,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,   136,   159,   200,   373,   455,
     491,   101,   101,   226,   228,  -235,  -235,  -235,  -235,   337,
     342,  -235,   348,   178,   367,  -235,   368,   370,   265,  -235,
     371,   377,   385,   391,   395,   389,   394,  -235,   394,  -235,
     392,   394,   393,   399,   404,   410,   413,   334,   329,   439,
     176,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
     417,   214,  -235,   314,   375,  -235,  -235,  -235,    50,    50,
     402,   403,   121,   446,   435,  -235,   394,  -235,  -235,   394,
     437,   228,   228,   132,   429,   432,  -235,  -235,  -235,   445,
    -235,  -235,   333,  -235,  -235,  -235,  -235,  -235,   101,   101,
     101,    42,   441,   447,   452,  -235,  -235,  -235
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,    -3,    -4,   -41,   -57,  -234,   -11,   426,    10,
     250,    19,     9,   -47,  -235,   -58,  -235,  -235,  -187,  -216,
    -235,  -235,  -235,  -235,  -235,   -71,   -43,     4,  -235,   405,
     -52,  -235,  -235,  -235,   223,  -235,  -235,   -56,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int16 yytable[] =
{
      49,    68,   128,    61,   123,    63,   135,    61,   138,    82,
     141,    62,   129,   121,   159,    65,    81,   134,   127,    66,
     142,    70,   263,   154,   156,   243,   140,    64,   173,   175,
      83,    69,   153,   155,    74,    78,   182,    79,    80,     6,
     290,    50,   144,   202,   145,    82,     8,   112,   113,   114,
     115,   116,   118,    84,    60,   183,   174,     5,     6,   274,
     122,   146,    67,   292,    59,     8,   120,   290,   137,    57,
     149,   152,   152,    71,    99,    85,   125,    72,    67,   -54,
      84,   152,    59,   133,    82,    67,   157,    58,   167,   100,
      59,    81,   281,   282,    73,   172,   152,    61,    61,    61,
      61,    61,   214,   152,   217,   176,   177,   178,   179,   180,
      75,   302,   303,   304,   171,   -10,   165,   215,   240,   190,
     -27,   218,    92,   117,   195,    79,     5,     6,   166,     7,
      58,    76,   165,   135,     8,   227,   100,   241,   165,   135,
     230,   229,   231,   246,    11,   168,   165,    79,     5,     6,
     187,   135,   135,   237,   239,   165,     8,   188,   200,   192,
     196,   245,   193,   232,    21,   233,    22,   288,   197,    77,
     244,    51,    52,    53,   296,   297,    54,    92,    93,   189,
     224,    94,   250,    96,    79,     5,     6,    57,    67,    95,
      97,   271,    98,     8,   107,   137,   108,    58,   109,   110,
      67,   137,   272,   111,   234,   124,   270,     5,     6,   152,
     152,   126,    82,   137,   137,     8,   105,   143,     4,    81,
     150,     5,     6,    59,     7,    67,    86,    87,    88,     8,
     151,   274,    60,     5,     6,     5,     6,   163,    10,    11,
     265,     8,   161,     8,    12,    13,    14,    15,   164,    16,
     162,   275,    17,    18,    19,    20,   103,   104,   105,    21,
     277,    22,   277,   280,   283,   283,   101,   102,   103,   104,
     105,    21,     2,     3,   184,   291,     4,   294,   295,     5,
       6,    57,     7,    51,    52,    53,   194,     8,    54,     9,
     147,   277,   148,     5,     6,   185,    10,    11,   186,   -34,
     191,     8,    12,    13,    14,    15,   201,    16,   198,    58,
      17,    18,    19,    20,   199,   203,   204,    21,     4,    22,
      58,     5,     6,   209,     7,   205,   206,   207,   208,     8,
     210,   274,   211,   212,   216,   213,    87,     4,    10,    11,
       5,     6,    88,     7,    12,    13,    14,    15,     8,    16,
     301,   278,    17,    18,    19,    20,   219,    10,    11,    21,
     220,    22,   221,    12,    13,    14,    15,   222,    16,   223,
     -55,    17,    18,    19,    20,    99,   100,   235,    21,     4,
      22,   225,     5,     6,   247,     7,    51,    52,    53,   248,
       8,    54,   279,   252,   253,   249,   254,   255,     4,    10,
      11,     5,     6,   256,     7,    12,    13,    14,    15,     8,
      16,   257,    58,    17,    18,    19,    20,   258,    10,    11,
      21,   259,    22,   260,    12,    13,    14,    15,   264,    16,
     266,   268,    17,    18,    19,    20,   267,   269,   215,    21,
     130,    22,   131,     5,     6,    86,     7,   273,   286,   287,
     289,     8,   274,   151,   293,   298,     5,     6,   299,   228,
      10,    11,     5,     6,     8,     7,    12,    13,    14,    15,
       8,   300,   181,   251,    17,     5,     6,   132,   305,    10,
      11,    21,   119,     8,   306,    12,    13,    14,    15,   307,
     160,   236,   285,    17,   158,   228,   132,     0,     5,     6,
      21,     7,     0,     0,     0,     0,     8,     0,   101,   102,
     103,   104,   105,    21,   226,    10,    11,     5,     6,     0,
       7,    12,    13,    14,    15,     8,   106,   238,     0,    17,
       0,     0,   132,     0,    10,    11,    21,     0,     0,     0,
      12,    13,    14,    15,     0,     0,   228,     0,    17,     5,
       6,   132,     7,     0,     0,    21,     0,     8,    60,     0,
       0,     5,     6,     0,     7,     0,    10,    11,     0,     8,
       0,     0,    12,    13,    14,    15,     0,     0,     0,    11,
      17,     0,     0,   132,    51,    52,    53,    21,     0,    54,
       0,    55,     0,     0,    56,   101,   102,   103,   104,   105,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,   139,    59
};

static const yytype_int16 yycheck[] =
{
       1,    12,    59,     7,    56,     8,    64,    11,    64,    20,
      67,     7,    59,    56,    85,    11,    20,    64,    59,     4,
      67,    12,   238,    75,    76,   212,    67,    25,    99,   100,
      20,    12,    75,    76,     4,     4,   107,     6,     7,     8,
     274,    17,     4,    26,     6,    56,    15,    51,    52,    53,
      54,    55,    56,     4,     4,   107,    99,     7,     8,    17,
      56,    72,    47,   279,    47,    15,    56,   301,    64,    34,
      73,    75,    76,    25,    29,    26,    57,    25,    47,    37,
       4,    85,    47,    64,    95,    47,    77,    44,    92,    44,
      47,    95,    42,    43,    25,    99,   100,   101,   102,   103,
     104,   105,    26,   107,   161,   101,   102,   103,   104,   105,
      25,   298,   299,   300,    95,    29,    34,    25,    17,   130,
      27,   162,    29,     4,    26,     6,     7,     8,    46,    10,
      44,    25,    34,   191,    15,   191,    44,    36,    34,   197,
       4,   197,     6,   214,    25,     4,    34,     6,     7,     8,
      46,   209,   210,   209,   210,    34,    15,     4,    46,     4,
      26,   213,     7,     4,    45,     6,    47,    46,    34,    25,
     213,    18,    19,    20,    42,    43,    23,    29,    27,    26,
     184,    27,     4,    27,     6,     7,     8,    34,    47,    28,
      27,   248,    27,    15,    44,   191,    27,    44,    27,    27,
      47,   197,   249,    17,   207,     4,   247,     7,     8,   213,
     214,     4,   223,   209,   210,    15,    13,     4,     4,   223,
      25,     7,     8,    47,    10,    47,     6,     7,     8,    15,
       4,    17,     4,     7,     8,     7,     8,    46,    24,    25,
     241,    15,    34,    15,    30,    31,    32,    33,    46,    35,
      34,    37,    38,    39,    40,    41,    11,    12,    13,    45,
     261,    47,   263,   264,   268,   269,     9,    10,    11,    12,
      13,    45,     0,     1,    34,   276,     4,   281,   282,     7,
       8,    34,    10,    18,    19,    20,    26,    15,    23,    17,
       4,   292,     6,     7,     8,    46,    24,    25,    46,    27,
      34,    15,    30,    31,    32,    33,    26,    35,    46,    44,
      38,    39,    40,    41,    46,    26,    26,    45,     4,    47,
      44,     7,     8,    26,    10,    34,    34,    34,    30,    15,
      26,    17,    26,    26,    25,    27,     7,     4,    24,    25,
       7,     8,     8,    10,    30,    31,    32,    33,    15,    35,
      17,    37,    38,    39,    40,    41,     9,    24,    25,    45,
       9,    47,     6,    30,    31,    32,    33,     9,    35,    34,
      37,    38,    39,    40,    41,    29,    44,     4,    45,     4,
      47,    26,     7,     8,    47,    10,    18,    19,    20,    47,
      15,    23,    17,    26,    26,    47,    26,    26,     4,    24,
      25,     7,     8,    26,    10,    30,    31,    32,    33,    15,
      35,    26,    44,    38,    39,    40,    41,    26,    24,    25,
      45,    26,    47,    34,    30,    31,    32,    33,    36,    35,
      37,    27,    38,    39,    40,    41,    37,    27,    25,    45,
       4,    47,     6,     7,     8,     6,    10,    30,    46,    46,
       4,    15,    17,     4,    17,    26,     7,     8,    26,     4,
      24,    25,     7,     8,    15,    10,    30,    31,    32,    33,
      15,    26,     4,   223,    38,     7,     8,    41,    37,    24,
      25,    45,    56,    15,    37,    30,    31,    32,    33,    37,
      85,    36,   269,    38,    45,     4,    41,    -1,     7,     8,
      45,    10,    -1,    -1,    -1,    -1,    15,    -1,     9,    10,
      11,    12,    13,    45,     4,    24,    25,     7,     8,    -1,
      10,    30,    31,    32,    33,    15,    27,    36,    -1,    38,
      -1,    -1,    41,    -1,    24,    25,    45,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    -1,     4,    -1,    38,     7,
       8,    41,    10,    -1,    -1,    45,    -1,    15,     4,    -1,
      -1,     7,     8,    -1,    10,    -1,    24,    25,    -1,    15,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    25,
      38,    -1,    -1,    41,    18,    19,    20,    45,    -1,    23,
      -1,    25,    -1,    -1,    28,     9,    10,    11,    12,    13,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    26,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,     0,     1,     4,     7,     8,    10,    15,    17,
      24,    25,    30,    31,    32,    33,    35,    38,    39,    40,
      41,    45,    47,    51,    52,    56,    57,    60,    61,    63,
      64,    65,    66,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    84,    85,    86,    87,
      17,    18,    19,    20,    23,    25,    28,    34,    44,    47,
       4,    52,    76,    51,    25,    76,     4,    47,    56,    60,
      61,    25,    25,    25,     4,    25,    25,    25,     4,     6,
       7,    52,    56,    58,     4,    26,     6,     7,     8,    53,
      54,    62,    29,    27,    27,    28,    27,    27,    27,    29,
      44,     9,    10,    11,    12,    13,    27,    44,    27,    27,
      27,    17,    52,    52,    52,    52,    52,     4,    52,    57,
      58,    75,    76,    79,     4,    60,     4,    53,    54,    62,
       4,     6,    41,    60,    62,    64,    69,    76,    86,    26,
      53,    54,    62,     4,     4,     6,    56,     4,     6,    51,
      25,     4,    52,    75,    79,    75,    79,    61,    45,    74,
      78,    34,    34,    46,    46,    34,    46,    52,     4,    58,
      59,    60,    52,    74,    75,    74,    76,    76,    76,    76,
      76,     4,    74,    79,    34,    46,    46,    46,     4,    26,
      56,    34,     4,     7,    26,    26,    26,    34,    46,    46,
      46,    26,    26,    26,    26,    34,    34,    34,    30,    26,
      26,    26,    26,    27,    26,    25,    25,    54,    53,     9,
       9,     6,     9,    34,    52,    26,     4,    86,     4,    86,
       4,     6,     4,     6,    51,     4,    36,    86,    36,    86,
      17,    36,    67,    67,    75,    79,    74,    47,    47,    47,
       4,    59,    26,    26,    26,    26,    26,    26,    26,    26,
      34,    68,    87,    68,    36,    87,    37,    37,    27,    27,
      53,    54,    62,    30,    17,    37,    55,    87,    37,    17,
      87,    42,    43,    52,    83,    83,    46,    46,    46,     4,
      55,    87,    68,    17,    52,    52,    42,    43,    26,    26,
      26,    17,    67,    67,    67,    37,    37,    37
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
#line 83 "4-bison-code.y"
    { printf("\tERROR !\n"); yyerrok; wrong_expressions++; ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 314 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 315 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 316 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 317 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 318 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 319 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 320 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 321 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 322 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 323 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 324 "4-bison-code.y"
    { correct_expressions++; ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 325 "4-bison-code.y"
    { correct_expressions++; ;}
    break;



/* Line 1464 of yacc.c  */
#line 1815 "4-bison-code.tab.c"
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
#line 328 "4-bison-code.y"


/* Επιπλέον κώδικας σε γλώσσα C. */

/* Η συνάρτηση main, αποτελεί το σημείο εκκίνησης του προγράμματος. */

int main(int argc, char **argv) {
	//yydebug=1;

	/* Έλεγχος ορισμάτων γραμμής εντολών.
	   Αν είναι 3 (argv[2]): το πρόγραμμα διαβάζει απο το απο το αρχείο του 2ου ορίσματος και γράφει στο αρχείο του 3ου.
	   Αν είναι 2 (argv[1]): το πρόγραμμα διαβάζει απο το απο το αρχείο του 2ου ορίσματος και γράφει στην οθόνη.
	   Το 1ο όρισμα (argv[0]) αποτελεί το όνομα του εκτελέσιμου αρχείου. */
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

	/* Γίνεται έλεγχος των ορισμάτων της γραμμής εντολών και κλήση της yyparse
	   που πραγματοποιεί τη συντακτική ανάλυση. Ελέγχεται και εμφανίζεται η 
       επιτυχής ή μη συντακτική ανάλυση. */
	int ret = yyparse();
	if (wrong_expressions==0 && ret==0) { 
   		printf("\t\tBison -> PARSING SUCCEEDED.\n");
   		if (par_warn > 0) printf(" (with %d warning(s))\n", par_warn);
    	printf("\n");
	} else {
    	printf("\t\tBison -> PARSING FAILED (%d syntax error(s) found).\n", wrong_expressions);
	} 
		/* Εμφανίζονται τα πλήθη των σωστών και λανθασμένων λέξεων και εκφράσεων. */ 
		fprintf(yyout, "\nCorrect Words: %d\n", correct_words);
		fprintf(yyout, "Correct Expressions: %d\n", correct_expressions);
		fprintf(yyout, "Wrong Words: %d\n", wrong_words);
		fprintf(yyout, "Wrong Expressions: %d\n", wrong_expressions);

	/* Κλείσιμο των αρχείων που χρησιμοποιήθηκαν για την εκτέλεση του προγράμματος. */
	if (yyin) fclose(yyin);
	if (yyout && yyout != stdout) fclose(yyout);
	
	return 0;
	
}
