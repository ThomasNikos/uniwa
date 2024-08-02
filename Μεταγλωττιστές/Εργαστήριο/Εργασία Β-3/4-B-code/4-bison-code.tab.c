/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 22 "4-bison-code.y" /* yacc.c:339  */


/* Δήλωση των αρχείων επικεφαλίδας και ορισμός τύπου δεδομένων. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double

/* Δήλωση εξωτερικής συνάρτησης yylex του ΛΑ και των pointers για τα αρχεία εισόδου και εξόδου. */
extern int yylex(void);
extern FILE *yyin, *yyout;

/* Σωστές και λάθος λέξεις που υπολογίζονται από τον ΛΑ. */
extern int correct_words;
extern int wrong_words;

/* Δημιουργία μετρητών: */ 
int correct_expressions = 0;
int wrong_expressions = 0;
int par_warn = 0;

/* Δήλωση συνάρτησης yyerror. */
void yyerror (const char *msg);

#line 91 "4-bison-code.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "4-bison-code.tab.h".  */
#ifndef YY_YY_4_BISON_CODE_TAB_H_INCLUDED
# define YY_YY_4_BISON_CODE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    DIVIDE_ASSIGN = 277,
    AMPERSAND = 278,
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
    RIGHT_BR = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_4_BISON_CODE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "4-bison-code.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  319

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    71,    72,    73,    74,    79,    80,    81,
      86,    87,    92,    93,    98,    99,   104,   105,   110,   111,
     116,   117,   118,   119,   120,   121,   126,   127,   128,   134,
     135,   136,   140,   141,   146,   147,   152,   153,   154,   155,
     156,   161,   162,   169,   170,   171,   172,   177,   178,   179,
     180,   181,   182,   183,   184,   189,   194,   195,   196,   201,
     202,   203,   204,   209,   210,   215,   216,   217,   222,   223,
     224,   228,   229,   230,   231,   235,   236,   241,   246,   250,
     251,   252,   257,   258,   259,   260,   261,   263,   264,   265,
     270,   271,   272,   273,   278,   279,   280,   281,   285,   286,
     287,   288,   293,   294,   298,   299,   304,   305,   310,   311,
     316,   317,   318,   319,   324,   325,   326,   327,   328,   329,
     330,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DELIMITER", "IDENTIFIER", "KEYWORD",
  "STRING", "INTEGER", "FLOAT", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "POWER", "COMMENT", "NEG", "UNKNOWN_TOKEN", "NEWLINE", "MINUS_ASSIGN",
  "PLUS_ASSIGN", "TIMES_ASSIGN", "MOD", "DIVIDE_ASSIGN", "AMPERSAND",
  "PRINT", "LEFT_PT", "RIGHT_PT", "SEMICOLON", "ASSIGNOP", "CMP_OPERATOR",
  "TYPE", "SCAN", "LEN", "CMP", "COMMA", "FUNC", "LEFT_BR", "IF", "WHILE",
  "FOR", "RETURN", "DOUBLE_PLUS", "DOUBLE_MINUS", "LOGIC_OPERATOR",
  "LOG_NOT", "RIGHT_AR", "LEFT_AR", "RIGHT_BR", "$accept", "program",
  "number", "term", "multiple_float", "multiple_int", "string",
  "multiple_newline", "array", "array_plus", "values", "multiple_values",
  "variable_list", "declaration", "assignment", "return", "print_func",
  "scan_func", "len_func", "cmp_func", "func_multiple_types", "func_def",
  "multiple_expressions", "multiple_expressions_functions",
  "multiple_expressions_no_semi", "func_call", "cmp_operator",
  "cmp_operator_multiple", "arith_operation", "augmented_assignments",
  "logical_operator", "logical_operator_multiple", "if_func",
  "if_multiple_func", "while_func", "for_func", "plus_minus",
  "expr_assignment", "expr_no_semi", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -185

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-185)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -185,   217,  -185,     1,   558,  -185,  -185,   466,   143,  -185,
       3,   466,    32,    18,    43,    94,   121,   103,   117,   150,
     130,   174,   174,     7,   222,  -185,   112,   119,   152,   163,
    -185,   169,  -185,  -185,  -185,  -185,  -185,  -185,   185,    68,
    -185,   347,  -185,   164,  -185,  -185,  -185,  -185,  -185,  -185,
     204,   208,   226,  -185,   174,   174,   174,   174,   174,   381,
     242,   256,   222,  -185,  -185,   251,  -185,   453,   309,    49,
     163,  -185,   263,    34,   188,   244,    78,    78,   242,   113,
    -185,   222,   252,  -185,  -185,  -185,   347,  -185,  -185,  -185,
    -185,   153,  -185,   238,   240,   235,   249,   -22,   174,  -185,
    -185,  -185,  -185,   165,  -185,  -185,   174,   174,   466,   466,
     466,   466,   466,   201,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,   253,  -185,  -185,  -185,  -185,  -185,   347,  -185,   267,
    -185,  -185,   260,   268,    73,   389,   274,   287,   136,   266,
     151,  -185,  -185,   269,    52,  -185,   291,    -9,   300,   301,
     294,   308,    64,   282,   304,   320,   323,   325,   326,   327,
     316,   317,    82,    16,    46,   328,   356,   358,   359,   360,
     361,   365,  -185,    11,  -185,   342,  -185,  -185,   304,   354,
    -185,  -185,   227,   227,   251,   251,   251,    83,   349,  -185,
     174,  -185,  -185,  -185,  -185,   107,   492,    78,  -185,  -185,
    -185,   531,  -185,  -185,  -185,  -185,  -185,  -185,   216,   247,
      29,   386,   368,   414,   414,    29,    29,    78,  -185,  -185,
    -185,   174,  -185,  -185,  -185,  -185,   351,   352,  -185,   353,
     180,   369,  -185,   393,   569,   378,   384,   390,   383,  -185,
     391,   394,   402,   404,   376,   340,   372,   172,    29,   387,
    -185,   395,  -185,   396,   401,   406,   409,   412,   358,   356,
     434,   269,  -185,  -185,   405,  -185,  -185,   531,   531,  -185,
    -185,  -185,  -185,   258,  -185,  -185,    29,   411,   415,  -185,
    -185,  -185,  -185,   229,   229,   408,   419,    87,   423,   340,
     448,   420,   462,  -185,  -185,   243,   443,   445,  -185,  -185,
    -185,  -185,   299,  -185,  -185,  -185,   438,    29,    29,    -8,
     340,  -185,   428,   432,   463,  -185,  -185,  -185,  -185
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    10,     7,     8,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    82,     0,     0,     0,
     125,     0,   129,   123,   121,   122,   124,   141,     0,    79,
     126,   130,   131,    98,   127,   128,   142,   139,   140,   132,
       0,     0,     6,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    82,    87,     9,     0,     0,    34,
      36,    40,     0,     0,     0,     0,     0,     0,     0,    10,
      31,     0,    82,    30,    43,    45,    44,    46,   110,   111,
      95,     0,    16,    14,    12,     0,     0,     0,     0,   112,
     113,   137,   138,     0,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   133,     4,    91,    90,    92,
      93,     0,   117,   118,   120,   119,   115,   114,   116,    34,
      35,    94,     0,     0,     0,    10,    16,     0,     0,     0,
       0,    75,    89,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    20,
       0,    22,    78,    10,    29,    32,    42,    41,    80,    79,
      81,    96,    83,    84,    85,    86,    88,    99,     0,   101,
       0,    24,    23,    25,    52,     0,     0,     0,    47,    48,
      49,     0,    38,    37,    55,    58,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    20,
      22,     0,    97,   100,    15,    13,     0,     0,    17,     0,
       0,     0,    53,     0,    10,     0,     0,     0,    10,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    33,    77,     0,    50,    51,     0,     0,    60,
      62,    61,    59,     0,    71,    67,     0,     0,     0,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    66,     0,     0,     0,    27,    26,
      28,    54,    74,    68,    72,    65,    63,     0,     0,    18,
       0,    69,     0,     0,    18,    19,    70,   108,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,    -5,    -7,   -54,   -56,   -60,   186,   -15,   430,
       4,   257,    14,  -185,    -2,  -185,  -185,  -185,   433,   439,
     205,  -185,  -185,  -184,  -185,  -185,   -72,     2,    55,  -185,
     410,    -4,  -185,  -185,  -185,  -185,    27,  -185,   -66,  -158
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,    26,    95,    96,    97,   315,    27,    28,
     175,   176,    29,    30,    31,    32,    33,    34,    35,    36,
     212,    37,   302,   246,   140,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,   141,   134,    66,    64,    83,   133,   138,   132,   314,
      71,    90,   170,    82,    88,    89,    87,   205,    53,   164,
      90,   162,    85,   171,    84,   161,    70,   160,    67,   249,
     251,   253,   254,    91,   179,   181,    69,    62,   147,   -73,
     148,   188,   221,    72,    83,    60,   244,   117,   118,   119,
     120,   121,    82,   143,   145,   128,   143,    62,   149,     5,
       6,   126,    65,   123,   278,   245,    68,     8,    73,   154,
     154,   222,   156,   158,   130,    86,   159,   144,   155,   157,
      81,   139,   153,    60,   154,     5,     6,   274,    83,   107,
     210,   172,   291,     8,   211,    81,   174,   106,    81,   178,
     154,    64,    64,    64,    64,    64,   154,   170,   180,   189,
     224,   107,   -10,   225,   127,   290,   170,   177,   193,    74,
     195,   170,    23,   312,   313,    75,    61,   220,    76,   203,
     235,   303,   300,   232,    79,   239,    80,     5,     6,   202,
       7,    98,    77,   233,   311,     8,   101,   250,   252,   257,
       5,     6,   316,    99,   100,    11,    61,   153,     8,    62,
       5,     6,   198,   182,   183,   184,   185,   186,     8,   173,
     170,    80,     5,     6,    23,    78,    81,   200,    63,   102,
       8,     5,     6,   231,   261,   201,    80,     5,     6,     8,
     154,   103,   150,   237,   151,     8,   104,   163,   276,   236,
     287,   250,   252,   286,   285,   187,   277,   113,     5,     6,
     154,    81,   105,   256,   154,    83,     8,     2,     3,   255,
     240,     4,   241,   174,     5,     6,    81,     7,    92,    93,
      94,   114,     8,    63,     9,   115,     5,     6,   110,   111,
     112,    10,    11,   116,     8,    23,   129,    12,    13,    14,
      15,   242,    16,   243,    17,    18,    19,    20,    21,    22,
     131,    23,     4,    24,   112,     5,     6,   146,     7,   152,
      21,    22,   166,     8,   167,   289,   295,   295,   -29,   -29,
     168,    98,    10,    11,    99,   100,   -29,   190,    12,    13,
      14,    15,   199,    16,   169,    17,    18,    19,    20,    21,
      22,    60,    23,     4,    24,   191,     5,     6,   196,     7,
     296,   297,   197,   192,     8,    62,   309,   204,   108,   109,
     110,   111,   112,    10,    11,    61,   206,   207,   208,    12,
      13,    14,    15,    98,    16,   142,    17,    18,    19,    20,
      21,    22,   209,    23,     4,    24,   213,     5,     6,   214,
       7,   215,   216,   223,   217,     8,   108,   109,   110,   111,
     112,   218,   219,    93,    10,    11,    94,   228,   226,   227,
      12,    13,    14,    15,   229,    16,   230,    17,    18,    19,
      20,    21,    22,   106,    23,    79,    24,    80,     5,     6,
     247,     7,   107,   143,   248,   263,     8,   258,   259,   260,
     264,    54,    55,    56,   266,    57,    11,    54,    55,    56,
     267,    57,   273,    14,    15,   194,   268,   269,   238,   275,
     270,     5,     6,    60,     7,    23,    61,    24,   271,     8,
     272,   244,    61,   283,   279,    81,   284,   222,    10,    11,
      92,   292,   280,   281,    12,    13,    14,    15,   282,   301,
     245,   137,   288,   298,    20,    21,    22,   135,    23,   136,
       5,     6,   294,     7,   299,   304,   306,   305,     8,   307,
      63,   308,   277,     5,     6,   317,     7,    10,    11,   318,
     314,     8,   293,    12,    13,    14,    15,   262,   310,   122,
     137,    11,   124,    20,    21,    22,   234,    23,   125,     5,
       6,   165,     7,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,     0,   137,
       0,     0,    20,    21,    22,   238,    23,     0,     5,     6,
       0,     7,     0,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,   137,     0,
       0,    20,    21,    22,     0,    23,    54,    55,    56,     0,
      57,     0,     0,    58,     0,     0,    59,    54,    55,    56,
       0,    57,    60,     0,     0,   265,     0,     0,     0,     0,
       0,    61,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,    61
};

static const yytype_int16 yycheck[] =
{
       7,    67,    62,     8,    11,    20,    62,    67,    62,    17,
      12,     4,    34,    20,    21,    22,    20,    26,    17,    91,
       4,    81,    20,    45,    20,    81,    12,    81,    25,   213,
     214,   215,   216,    26,   106,   107,     4,    46,     4,    47,
       6,   113,    26,    25,    59,    34,    17,    54,    55,    56,
      57,    58,    59,     4,    69,    59,     4,    46,    73,     7,
       8,    59,     7,    59,   248,    36,    11,    15,    25,    76,
      77,    25,    76,    77,    60,    20,    78,    28,    76,    77,
      46,    67,     4,    34,    91,     7,     8,   245,   103,    43,
      26,    98,   276,    15,    30,    46,   103,    29,    46,   106,
     107,   108,   109,   110,   111,   112,   113,    34,   106,   113,
     166,    43,    29,   167,    59,   273,    34,   103,    45,    25,
     135,    34,    44,   307,   308,     4,    43,    45,    25,   144,
     196,   289,    45,    26,     4,   201,     6,     7,     8,   144,
      10,    29,    25,    36,   302,    15,    27,   213,   214,   221,
       7,     8,   310,    41,    42,    25,    43,     4,    15,    46,
       7,     8,    26,   108,   109,   110,   111,   112,    15,     4,
      34,     6,     7,     8,    44,    25,    46,    26,     4,    27,
      15,     7,     8,   190,     4,    34,     6,     7,     8,    15,
     197,    28,     4,   197,     6,    15,    27,    44,    26,   197,
     260,   267,   268,   259,   258,     4,    34,    43,     7,     8,
     217,    46,    27,   217,   221,   230,    15,     0,     1,   217,
       4,     4,     6,   230,     7,     8,    46,    10,     6,     7,
       8,    27,    15,     4,    17,    27,     7,     8,    11,    12,
      13,    24,    25,    17,    15,    44,     4,    30,    31,    32,
      33,     4,    35,     6,    37,    38,    39,    40,    41,    42,
       4,    44,     4,    46,    13,     7,     8,     4,    10,    25,
      41,    42,    34,    15,    34,    17,   283,   284,    26,    27,
      45,    29,    24,    25,    41,    42,    34,    34,    30,    31,
      32,    33,    26,    35,    45,    37,    38,    39,    40,    41,
      42,    34,    44,     4,    46,    45,     7,     8,    34,    10,
     283,   284,    25,    45,    15,    46,    17,    26,     9,    10,
      11,    12,    13,    24,    25,    43,    26,    26,    34,    30,
      31,    32,    33,    29,    35,    26,    37,    38,    39,    40,
      41,    42,    34,    44,     4,    46,    26,     7,     8,    26,
      10,    26,    26,    25,    27,    15,     9,    10,    11,    12,
      13,    45,    45,     7,    24,    25,     8,     6,     9,     9,
      30,    31,    32,    33,     9,    35,    34,    37,    38,    39,
      40,    41,    42,    29,    44,     4,    46,     6,     7,     8,
       4,    10,    43,     4,    26,    26,    15,    46,    46,    46,
       7,    18,    19,    20,    26,    22,    25,    18,    19,    20,
      26,    22,    36,    32,    33,    26,    26,    26,     4,    47,
      26,     7,     8,    34,    10,    44,    43,    46,    26,    15,
      26,    17,    43,    27,    47,    46,    27,    25,    24,    25,
       6,    30,    47,    47,    30,    31,    32,    33,    47,    26,
      36,    37,    47,    45,    40,    41,    42,     4,    44,     6,
       7,     8,    47,    10,    45,    17,     4,    47,    15,    26,
       4,    26,    34,     7,     8,    47,    10,    24,    25,    47,
      17,    15,   277,    30,    31,    32,    33,   230,   302,    59,
      37,    25,    59,    40,    41,    42,     4,    44,    59,     7,
       8,    91,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      -1,    -1,    40,    41,    42,     4,    44,    -1,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    40,    41,    42,    -1,    44,    18,    19,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,    28,    18,    19,    20,
      -1,    22,    34,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     1,     4,     7,     8,    10,    15,    17,
      24,    25,    30,    31,    32,    33,    35,    37,    38,    39,
      40,    41,    42,    44,    46,    50,    51,    56,    57,    60,
      61,    62,    63,    64,    65,    66,    67,    69,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    17,    18,    19,    20,    22,    25,    28,
      34,    43,    46,     4,    51,    76,    50,    25,    76,     4,
      60,    62,    25,    25,    25,     4,    25,    25,    25,     4,
       6,    46,    51,    56,    58,    75,    76,    79,    51,    51,
       4,    26,     6,     7,     8,    52,    53,    54,    29,    41,
      42,    27,    27,    28,    27,    27,    29,    43,     9,    10,
      11,    12,    13,    43,    27,    27,    17,    51,    51,    51,
      51,    51,    57,    58,    66,    67,    75,    76,    79,     4,
      60,     4,    52,    53,    54,     4,     6,    37,    54,    60,
      72,    86,    26,     4,    28,    56,     4,     4,     6,    56,
       4,     6,    25,     4,    51,    75,    79,    75,    79,    62,
      52,    53,    54,    44,    74,    78,    34,    34,    45,    45,
      34,    45,    51,     4,    51,    58,    59,    60,    51,    74,
      75,    74,    76,    76,    76,    76,    76,     4,    74,    79,
      34,    45,    45,    45,    26,    56,    34,    25,    26,    26,
      26,    34,    50,    56,    26,    26,    26,    26,    34,    34,
      26,    30,    68,    26,    26,    26,    26,    27,    45,    45,
      45,    26,    25,    25,    53,    52,     9,     9,     6,     9,
      34,    51,    26,    36,     4,    86,    75,    79,     4,    86,
       4,     6,     4,     6,    17,    36,    71,     4,    26,    71,
      86,    71,    86,    71,    71,    75,    79,    74,    46,    46,
      46,     4,    59,    26,     7,    26,    26,    26,    26,    26,
      26,    26,    26,    36,    87,    47,    26,    34,    71,    47,
      47,    47,    47,    27,    27,    52,    53,    54,    47,    17,
      87,    71,    30,    68,    47,    51,    84,    84,    45,    45,
      45,    26,    70,    87,    17,    47,     4,    26,    26,    17,
      55,    87,    71,    71,    17,    55,    87,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    69,    70,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    74,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     2,     1,     1,     2,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     2,
       3,     3,     3,     4,     4,     4,     7,     7,     7,     1,
       1,     1,     1,     3,     1,     3,     2,     4,     4,     3,
       2,     3,     3,     2,     2,     2,     2,     4,     4,     4,
       6,     6,     4,     5,     8,     4,     4,     4,     4,     6,
       6,     6,     6,     5,     4,     8,     7,     6,     1,     2,
       3,     2,     4,     5,     4,     1,     3,     6,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     4,     1,     3,
       4,     3,     5,     5,     6,     6,     6,     6,    10,    10,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 73 "4-bison-code.y" /* yacc.c:1646  */
    { yyerrok; wrong_expressions++; }
#line 1543 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 351 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1549 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 352 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1555 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 353 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1561 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 354 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1567 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 355 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1573 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 356 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1579 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 357 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1585 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 358 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1591 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 359 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1597 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 360 "4-bison-code.y" /* yacc.c:1646  */
    { correct_expressions++; }
#line 1603 "4-bison-code.tab.c" /* yacc.c:1646  */
    break;


#line 1607 "4-bison-code.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 363 "4-bison-code.y" /* yacc.c:1906  */


/* Επιπλέον κώδικας σε γλώσσα C. */

/* Η συνάρτηση main, αποτελεί το σημείο εκκίνησης του προγράμματος. */
int main(int argc, char **argv) {
	/* Έλεγχος ορισμάτων εκτέλεσης.
	   Αν είναι 3 (argv[2]): το πρόγραμμα διαβάζει από το αρχείο του 2ου ορίσματος και γράφει στο αρχείο του 3ου.
	   Αν είναι 2 (argv[1]): το πρόγραμμα διαβάζει από το αρχείο του 2ου ορίσματος και γράφει στην οθόνη.
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
		printf("\tBison -> PARSING SUCCEEDED.\n");
   		if (par_warn > 0) printf(" (with %d warning(s))\n", par_warn);
    	printf("\n");
	} else {
    	printf("\tBison -> PARSING FAILED (%d syntax error(s) found).\n", wrong_expressions);
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
