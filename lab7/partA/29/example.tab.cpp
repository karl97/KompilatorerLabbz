/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "example.ypp"


#include <stdio.h>
#include <stdlib.h>
#include "global.h"



#include "StackMachine.h"


StackMachine sm;
int labelCounter = 1;

extern int yyerror(char const *msg);


TreeNode* mkleaf(int type, int value);

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2);

void printTree(TreeNode* tree);
int runTree(TreeNode* tree);
extern int yylex();
int valuetable[1000];

int powe(int a1, int b1);


#line 100 "example.tab.cpp"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_EXAMPLE_TAB_HPP_INCLUDED
# define YY_YY_EXAMPLE_TAB_HPP_INCLUDED
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
    DIV = 258,
    MOD = 259,
    DONE = 260,
    ID = 261,
    NUM = 262,
    EXPR = 263,
    WHILE = 264,
    PRINT = 265,
    READ = 266,
    IF = 267,
    ELSE = 268
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "example.ypp"

  TreeNode* p;
  int i; 

#line 162 "example.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXAMPLE_TAB_HPP_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  28
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  67

#define YYUNDEFTOK  2
#define YYMAXUTOK   268

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    25,    23,     2,
      27,    28,    20,    18,     2,    19,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    15,    26,
      16,    31,    17,    14,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,    24,    30,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    63,    64,    68,    69,    70,    71,    72,
      76,    78,    79,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIV", "MOD", "DONE", "ID", "NUM",
  "EXPR", "WHILE", "PRINT", "READ", "IF", "ELSE", "'?'", "':'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'^'", "'&'", "'|'", "'%'", "';'",
  "'('", "')'", "'{'", "'}'", "'='", "$accept", "start", "statements",
  "statement", "assignment", "optionalelse", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    63,    58,    60,    62,    43,    45,
      42,    47,    94,    38,   124,    37,    59,    40,    41,   123,
     125,    61
};
# endif

#define YYPACT_NINF -20

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-20)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -15,   -20,   -10,    -9,     4,     8,    27,     3,    36,
      35,     3,    26,    25,    27,    27,    50,    61,    27,   -20,
      41,    63,   -20,   -20,   -20,   -20,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,   -20,    94,    54,
      52,    66,    67,   -20,   -20,    82,   121,   121,   -19,   -19,
     112,   112,   128,   -20,   -20,   -20,     3,   -20,   -20,     3,
      27,   -20,    96,   104,     3,   -20,   -20
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    28,    27,     0,     0,     0,     0,     0,     4,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     1,     2,     3,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,    10,     0,
       0,     0,     0,    26,     9,     0,    17,    18,    13,    14,
      15,    16,    21,    19,    20,    22,     0,    24,    25,     0,
       0,     7,    12,    23,     0,     8,    11
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -20,   -20,   139,    74,   -20,   -20,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    65,    13
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    31,    32,    33,    34,    35,    36,    38,    39,     1,
       2,    42,     3,     4,     5,     6,    14,    15,    16,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       7,    17,     8,    19,     2,    18,    22,     4,     5,    26,
      23,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    25,    63,     7,    26,    40,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    41,    26,    43,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      57,    26,    56,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    44,    58,    59,    26,    60,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    26,    64,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      61,     0,     0,    62,    33,    34,    35,    36,    66,    29,
      30,    31,    32,    33,    34,    35,    36,    21,     0,     0,
      24,    34,    35,    36
};

static const yytype_int8 yycheck[] =
{
       7,    20,    21,    22,    23,    24,    25,    14,    15,     6,
       7,    18,     9,    10,    11,    12,    31,    27,    27,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      27,    27,    29,     6,     7,    27,     0,    10,    11,    14,
       5,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    26,    60,    27,    14,     6,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     6,    14,    28,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      28,    14,    28,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    30,    28,    28,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    14,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      56,    -1,    -1,    59,    22,    23,    24,    25,    64,    18,
      19,    20,    21,    22,    23,    24,    25,     8,    -1,    -1,
      11,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     9,    10,    11,    12,    27,    29,    33,
      34,    35,    36,    38,    31,    27,    27,    27,    27,     6,
      38,    34,     0,     5,    34,    26,    14,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    38,    38,
       6,     6,    38,    28,    30,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    28,    28,    28,    28,
      15,    35,    35,    38,    13,    37,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      36,    37,    37,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     5,     6,     3,
       3,     2,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
  case 2:
#line 60 "example.ypp"
    { runTree((yyvsp[-1].p)); sm.append(Instruction(halt)); sm.list_program(); sm.run();}
#line 1304 "example.tab.cpp"
    break;

  case 3:
#line 63 "example.ypp"
    {(yyval.p) = mknode(';', (yyvsp[-1].p), (yyvsp[0].p), 0);}
#line 1310 "example.tab.cpp"
    break;

  case 4:
#line 64 "example.ypp"
    {(yyval.p) = 0;}
#line 1316 "example.tab.cpp"
    break;

  case 5:
#line 68 "example.ypp"
    {(yyval.p) = (yyvsp[-1].p);}
#line 1322 "example.tab.cpp"
    break;

  case 6:
#line 69 "example.ypp"
    {(yyval.p) = (yyvsp[-1].p);}
#line 1328 "example.tab.cpp"
    break;

  case 7:
#line 70 "example.ypp"
    {(yyval.p) = mknode(WHILE, (yyvsp[-2].p), (yyvsp[0].p), 0);}
#line 1334 "example.tab.cpp"
    break;

  case 8:
#line 71 "example.ypp"
    {(yyval.p) = mknode(IF, (yyvsp[-3].p), (yyvsp[-1].p), (yyvsp[0].p));}
#line 1340 "example.tab.cpp"
    break;

  case 9:
#line 72 "example.ypp"
    {(yyval.p) = (yyvsp[-1].p);}
#line 1346 "example.tab.cpp"
    break;

  case 10:
#line 76 "example.ypp"
    {(yyval.p) = mknode((int)'=', mkleaf(ID, (yyvsp[-2].i)), (yyvsp[0].p), 0); }
#line 1352 "example.tab.cpp"
    break;

  case 11:
#line 78 "example.ypp"
    {(yyval.p) = mknode(ELSE, (yyvsp[0].p), 0, 0);}
#line 1358 "example.tab.cpp"
    break;

  case 12:
#line 79 "example.ypp"
    {(yyval.p) = 0;}
#line 1364 "example.tab.cpp"
    break;

  case 13:
#line 81 "example.ypp"
    { (yyval.p) = mknode((int)'+', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1370 "example.tab.cpp"
    break;

  case 14:
#line 82 "example.ypp"
    { (yyval.p) = mknode((int)'-', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1376 "example.tab.cpp"
    break;

  case 15:
#line 83 "example.ypp"
    { (yyval.p) = mknode((int)'*', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1382 "example.tab.cpp"
    break;

  case 16:
#line 84 "example.ypp"
    { (yyval.p) = mknode((int)'/', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1388 "example.tab.cpp"
    break;

  case 17:
#line 85 "example.ypp"
    { (yyval.p) = mknode((int)'<', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1394 "example.tab.cpp"
    break;

  case 18:
#line 86 "example.ypp"
    { (yyval.p) = mknode((int)'>', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1400 "example.tab.cpp"
    break;

  case 19:
#line 87 "example.ypp"
    { (yyval.p) = mknode((int)'&', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1406 "example.tab.cpp"
    break;

  case 20:
#line 88 "example.ypp"
    { (yyval.p) = mknode((int)'|', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1412 "example.tab.cpp"
    break;

  case 21:
#line 89 "example.ypp"
    { (yyval.p) = mknode((int)'^', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1418 "example.tab.cpp"
    break;

  case 22:
#line 90 "example.ypp"
    { (yyval.p) = mknode((int)'%', (yyvsp[-2].p), (yyvsp[0].p), 0); }
#line 1424 "example.tab.cpp"
    break;

  case 23:
#line 91 "example.ypp"
    { (yyval.p) = mknode((int)'?', (yyvsp[-4].p), (yyvsp[-2].p), (yyvsp[0].p)); }
#line 1430 "example.tab.cpp"
    break;

  case 24:
#line 92 "example.ypp"
    { (yyval.p) = mknode(PRINT, mkleaf(ID, (yyvsp[-1].i)), 0, 0); }
#line 1436 "example.tab.cpp"
    break;

  case 25:
#line 93 "example.ypp"
    { (yyval.p) = mknode(READ, mkleaf(ID, (yyvsp[-1].i)), 0, 0); }
#line 1442 "example.tab.cpp"
    break;

  case 26:
#line 94 "example.ypp"
    { (yyval.p) = mknode((int)'(', (yyvsp[-1].p), mkleaf((int)')', ')'), 0); }
#line 1448 "example.tab.cpp"
    break;

  case 27:
#line 95 "example.ypp"
    { (yyval.p) = mkleaf(NUM, (yyvsp[0].i));}
#line 1454 "example.tab.cpp"
    break;

  case 28:
#line 96 "example.ypp"
    { (yyval.p) = mkleaf(ID, (yyvsp[0].i));}
#line 1460 "example.tab.cpp"
    break;


#line 1464 "example.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 102 "example.ypp"


int yyerror(char const *msg) {
	printf("Error: %s\n", msg);
	return 0;
}

void parse()
{
	yyparse();
}

int powe(int a1, int b1){
	int c=a1;
	for(int i=1;i<b1;i++){
		c=c*a1;
	}
	return c;
}

TreeNode* mkleaf(int type, int value) {
  	
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
  	p->type = type;
  	p->value = value;
//print tree extra -----------------------------------------------------------------------------------------------------
	p->spacing = 2;
	if(type == ID)
		p->spacing += strlen(symtable[p->value].lexeme);
	if(type == NUM)
	{
		char buffer [12];
		sprintf (buffer, "%d", p->value);
		p->spacing += strlen(buffer) - 1;
	}
//print tree extra -----------------------------------------------------------------------------------------------------
  	return p;
}

TreeNode* mknode(int type, TreeNode* a0, TreeNode* a1, TreeNode* a2) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
  	p->type = type;
  	p->args[0] = a0;
  	p->args[1] = a1;
  	p->args[2] = a2;
//print tree extra -----------------------------------------------------------------------------------------------------
	int numNodes = 0;
	
	for(int i = 0; i < 3; i++)
	{
		if(p->args[i] != 0)
		{
			numNodes++;
			if(p->spacing < p->args[i]->spacing)
			{
				p->spacing = p->args[i]->spacing;
			}
			if(p->depth < p->args[i]->depth)
			{
				p->depth = p->args[i]->depth;
			}
		}
	}
	p->depth = p->depth + 1;
	if(type == READ || type == ELSE)p->spacing += 4;
	else if(type == PRINT || type == WHILE){p->spacing += 6;}
	else if(type == IF){p->spacing += 2;}
	p->spacing = p->spacing *(numNodes + (numNodes - 1));
//print tree extra ---------------------------------------------------------------------------------------------------
  	return p;
}


//Print tree here -----------------------------------------------------------------------------------------------------
void printTreeReccursive(TreeNode* tree, int h, int globalSpacing, char* row)
{
	
	int index = globalSpacing;
	if(h <= 0)
	{
		if(tree == 0) return;
		switch(tree->type)
		{
		case NUM:
		{
			
			char buffer [12];
			sprintf (buffer, "%d", tree->value);
			for(int k = 0; k < 12; k++){
				if(buffer[k] == '\0')break;
				row[index + k] = buffer[k];
			}			
		}break;
		case ID:
		{
			char* temp = symtable[tree->value].lexeme;
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case PRINT:
		{
			char* temp = "print";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case WHILE:
		{
			char* temp = "while";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case READ:
		{
			char* temp = "read";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case IF:
		{
			char* temp = "if";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		case ELSE:
		{
			char* temp = "else";
			int size = strlen(temp);
			for(int k = 0; k < size; k++)
				row[index + k] = temp[k]; 
		}break;
		default:
		{
			row[index] = (char)tree->type; 
		}break;
		}		

		 	
	}else {
		if(tree != 0){
			int numNodes = 0;
			for(int i = 0; i < 3; i++)
			{
				if(tree->args[i] != 0)
				{
					numNodes++;
				}
			}
			if(numNodes == 3) {
				for(int i = 0; i < 3; i++)
				{
					printTreeReccursive(tree->args[i],  h - 1, globalSpacing + tree->spacing/4* (i - 1), row);
					
				}
			}else if(numNodes == 2)
			{	
				printTreeReccursive(tree->args[0],  h - 1, globalSpacing + tree->spacing/4* ( -1), row);
				printTreeReccursive(tree->args[1],  h - 1, globalSpacing + tree->spacing/4* ( +1), row);
			}else if(numNodes == 1)
			{					
				printTreeReccursive(tree->args[0],  h - 1, globalSpacing, row);
			}
		}
		
	}	
}


void printTree(TreeNode* tree)
{
	int globalSpacing = tree->spacing;
	char* row = (char*) malloc(sizeof(char)*globalSpacing + 1);
	row[globalSpacing] = '\0';
	for(int i = 0; i <= tree->depth; i++){
		for(int j = 0; j < globalSpacing; j++)
		{
			row[j] = ' ';
		}
		printTreeReccursive(tree, i, globalSpacing/2, row);	
		printf("%s\n", row);
	}
	free(row);
}
//Print tree here -----------------------------------------------------------------------------------------------------



#define DEBUG_PRINTS 0


#if !DEBUG_PRINTS
#define DEBUG_CALL(x)
#else 
#define DEBUG_CALL(x) x
#endif


int runTree(TreeNode* tree)
{
	
	if(tree == NULL) return 0;
	switch(tree->type)
		{
		case NUM:
		{	
			DEBUG_CALL(printf("NUM\n"));
			sm.append(Instruction(push,tree->value));
			return tree->value;
						
		}break;
		case ID:{

			DEBUG_CALL(printf("ID\n"));
			sm.append(Instruction(rvalue,tree->value));
			return tree->value;
		}break;
		case PRINT:
		{
			DEBUG_CALL(printf("PRINT\n"));
			int idPosition = (tree->args[0])->value; //runTree(tree->args[0]);
			int idVal=valuetable[idPosition];			
			printf("%s = %d\n", symtable[idPosition].lexeme, idVal);

			sm.append(Instruction(rvalue, idPosition));
			sm.append(Instruction(stackop_write));
			return idVal;
		}break;
		case WHILE:
		{
			DEBUG_CALL(printf("WHILE\n"));
			/*
			while(runTree(tree->args[0]) != 0)
			{
				runTree(tree->args[1]);
			}
			*/
			int label_1 = labelCounter++;
			int label_2 = labelCounter++;

			sm.append(Instruction(label, label_1));
			
			//villkor
			runTree(tree->args[0]);

			sm.append(Instruction(gofalse, label_2));

			//Kroppen
			runTree(tree->args[1]);

			sm.append(Instruction(jump, label_1));
			sm.append(Instruction(label, label_2));


			
		}break;
		case READ:
		{
			DEBUG_CALL(printf("READ\n"));
			int idVal=0;
			int idPosition = (tree->args[0])->value; //runTree(tree->args[0]);
			printf("Input value for %s\n", symtable[idPosition].lexeme);			
			scanf("%d",&idVal);			
			valuetable[idPosition]=idVal;

			sm.append(Instruction(lvalue, idPosition));
			sm.append(Instruction(stackop_read));
			sm.append(Instruction(assign));
			return idVal;
		}break;
		case (int)'?':
		case IF:
		{
			DEBUG_CALL(printf("IF\n"));
			/*
			if(runTree(tree->args[0]) != 0)
			{
				runTree(tree->args[1]);
			}else{
				runTree(tree->args[2]);
			}
			*/
			//Villkor
			runTree(tree->args[0]);
			int label_1 = labelCounter++;
			int label_2 = labelCounter++;
			
			//if
			sm.append(Instruction(gofalse, label_1));
			runTree(tree->args[1]);
			sm.append(Instruction(jump, label_2));

			//else
			sm.append(Instruction(label, label_1));
			runTree(tree->args[2]);
			sm.append(Instruction(label, label_2));

		}break;
		case ELSE:
		{
			DEBUG_CALL(printf("ELSE\n"));
			runTree(tree->args[0]);
		}break;
		case (int)'+':
		{
			DEBUG_CALL(printf("+\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];

			sm.append(Instruction(plus));
			// push times
			return leftValue + rightValue;
		}break;
		case (int)'-':
		{
			DEBUG_CALL(printf("-\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(minus));
			return leftValue - rightValue;
		}break;
		case (int)'/':
		{
			DEBUG_CALL(printf("/\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(divide));
			return leftValue / rightValue;
		}break;
		case (int)'*':
		{
			DEBUG_CALL(printf("*\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(times));
			return leftValue * rightValue;
		}break;
		case (int)'<':
		{
			DEBUG_CALL(printf("<\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(lt));
			return leftValue < rightValue;
		}break;
		case (int)'>':
		{
			DEBUG_CALL(printf(">\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(gt));
			return leftValue > rightValue;
		}break;
		case (int)'&':
		{
			DEBUG_CALL(printf("&\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(stackop_and));
			return leftValue & rightValue;
		}break;
		case (int)'|':
		{
			DEBUG_CALL(printf("|\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);
			
			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(stackop_or));
			return leftValue | rightValue;
		}break;
		case (int)'^':
		{
			DEBUG_CALL(printf("^\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);
			/*
			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			*/
			
/*
			
			int label_1 = labelCounter++;
			int label_2 = labelCounter++;
			
			//Sno lediga platser att spara temporära variabler
			sm.append(Instruction(lvalue, 0));
			sm.append(Instruction(push, 1));
			sm.append(Instruction(assign));
			
			sm.append(Instruction(lvalue, 1));
			sm.append(Instruction(push, rightValue));
			sm.append(Instruction(assign));

			//While part
			sm.append(Instruction(label, label_1));
						

			//villkor
			sm.append(Instruction(rvalue, 1));
			sm.append(Instruction(push, 0));
			sm.append(Instruction(gt));


			sm.append(Instruction(gofalse, label_2));

			//Kroppen
			
			//a1 = a1 * leftValue;
			sm.append(Instruction(lvalue, 0));
			sm.append(Instruction(rvalue, 0));			
			sm.append(Instruction(push, leftValue));			
			sm.append(Instruction(times));			
			sm.append(Instruction(assign));

			//b1 = b1 - 1;
			sm.append(Instruction(lvalue, 1));
			sm.append(Instruction(rvalue, 1));
			sm.append(Instruction(push, 1));
			sm.append(Instruction(minus));			
			sm.append(Instruction(assign));
			

			sm.append(Instruction(jump, label_1));
			sm.append(Instruction(label, label_2));
			
			//Push result to stack
			sm.append(Instruction(rvalue, 0));
*/
			//exp
			return powe(leftValue, rightValue);
		}break;
		case (int)'%':
		{
			DEBUG_CALL(printf("%%\n"));
			int leftValue = runTree(tree->args[0]);
			int rightValue = runTree(tree->args[1]);

			if(tree->args[0]->type == ID)leftValue = valuetable[leftValue];
			if(tree->args[1]->type == ID)rightValue = valuetable[rightValue];
			sm.append(Instruction(modulo));
			return leftValue % rightValue;
		}break;
		case (int)';':
		{
			DEBUG_CALL(printf(";\n"));
			runTree(tree->args[0]);
			runTree(tree->args[1]);

		}break;
		case (int)'=':
		{
			DEBUG_CALL(printf("=\n"));
			int leftValue = tree->args[0]->value;//runTree(tree->args[0]);
			sm.append(Instruction(lvalue, leftValue));
			int rightValue = runTree(tree->args[1]);

			int idVal = valuetable[leftValue] = rightValue;
			
			sm.append(Instruction(assign));
			return idVal;
		}break;
		default:
		{
			
			int arg0 = runTree(tree->args[0]);
			int arg1 = runTree(tree->args[1]);
			int arg2 = runTree(tree->args[2]);
			DEBUG_CALL(printf("DEFAULT: %c, %d, %d, %d\n", tree->type, arg0, arg1, arg2));

			return arg0;
		}break;
	}		
	return 0;

}


