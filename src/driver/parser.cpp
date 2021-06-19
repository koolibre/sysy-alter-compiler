/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../../src/driver/parser.y"

#ifndef DEBUG
  #define NDEBUG
#else
  #undef NDEBUG
#endif

#include <cassert>     // use assert()

#include <iostream>    // use std::cout
#include <string>      // use std::string

#include "ast/ast.hpp" // use struct Node

#define YYSTYPE Node*
// output error message
// defined in scanner.cpp
extern void yyerror(const char *str);

// defined in scanner.cpp
extern int yylex();

#line 93 "../../src/driver/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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
#ifndef YY_YY_SRC_DRIVER_PARSER_HPP_INCLUDED
# define YY_YY_SRC_DRIVER_PARSER_HPP_INCLUDED
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
    CONST = 258,
    INT = 259,
    FLOAT = 260,
    CHAR = 261,
    VOID = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    BREAK = 266,
    CONTINUE = 267,
    RETURN = 268,
    DEF = 269,
    IDENT = 270,
    INT_CONST = 271,
    FLOAT_CONST = 272,
    CHAR_CONST = 273,
    STRING_CONST = 274,
    LEEQ = 275,
    GEEQ = 276,
    EQ = 277,
    UNEQ = 278,
    AND = 279,
    OR = 280,
    ERROR = 281
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

#endif /* !YY_YY_SRC_DRIVER_PARSER_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

#define YYUNDEFTOK  2
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,    42,    39,     2,
      34,    35,    40,    36,    28,    37,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      43,    29,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    49,    55,    60,    68,    71,    77,    86,
      92,   101,   109,   113,   120,   123,   126,   132,   136,   144,
     153,   158,   165,   173,   177,   184,   187,   190,   196,   200,
     208,   216,   221,   226,   234,   240,   244,   253,   256,   262,
     265,   268,   271,   274,   277,   280,   283,   289,   292,   298,
     304,   307,   313,   319,   324,   331,   336,   344,   347,   350,
     353,   356,   359,   365,   371,   377,   383,   389,   392,   396,
     401,   408,   413,   420,   424,   428,   432,   439,   442,   450,
     454,   458,   465,   468,   476,   480,   487,   492,   498,   502,
     506,   510,   517,   520,   528,   532,   539,   542,   550,   557,
     560,   568,   575,   581,   587,   592,   600,   604,   611,   614,
     620,   625,   632,   637,   642,   647
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "INT", "FLOAT", "CHAR", "VOID",
  "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN", "DEF", "IDENT",
  "INT_CONST", "FLOAT_CONST", "CHAR_CONST", "STRING_CONST", "LEEQ", "GEEQ",
  "EQ", "UNEQ", "AND", "OR", "ERROR", "';'", "','", "'='", "'['", "']'",
  "'{'", "'}'", "'('", "')'", "'+'", "'-'", "'!'", "'&'", "'*'", "'/'",
  "'%'", "'<'", "'>'", "$accept", "CompUnit", "Decl", "ConstDecl",
  "ConstDefList", "ConstDef", "ConstDefDimensionList", "ConstInitVal",
  "ConstInitValList", "VarDecl", "VarDefList", "VarDef",
  "VarDefDimensionList", "VarInitVal", "VarInitValList", "BType", "Block",
  "BlockItemList", "BlockItem", "Stmt", "ExpChoice", "Cond", "ElseChoice",
  "Exp", "LVal", "IndexList", "PrimaryExp", "IntNumber", "FloatNumber",
  "character", "String", "UnaryExp", "FuncRParamList", "UnaryOp", "MulExp",
  "MulOp", "AddExp", "AddOp", "RelExp", "RelOp", "EqExp", "EqOp",
  "LAndExp", "LAndOp", "LOrExp", "LOrOp", "ConstExp", "VarExp", "FuncDef",
  "FuncFParamList", "FuncFParam", "FuncFParamIndexList", "FuncType", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    59,    44,    61,
      91,    93,   123,   125,    40,    41,    43,    45,    33,    38,
      42,    47,    37,    60,    62
};
# endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   149,  -141,  -141,  -141,   113,    53,  -141,  -141,  -141,
      11,  -141,    37,  -141,  -141,  -141,  -141,    39,  -141,  -141,
    -141,  -141,    34,  -141,  -141,    66,  -141,    30,   109,  -141,
      11,   189,  -141,    37,    31,   141,   178,  -141,   166,   178,
    -141,    43,    54,   -16,  -141,    40,  -141,  -141,  -141,  -141,
     108,   178,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   178,   121,   184,  -141,    55,   133,
    -141,   184,  -141,    60,  -141,  -141,    68,   149,    43,   178,
     172,    74,  -141,  -141,    32,   184,    -3,   200,    72,    20,
    -141,  -141,  -141,  -141,   178,  -141,  -141,   178,  -141,  -141,
    -141,    35,  -141,    97,    75,  -141,  -141,    80,   184,  -141,
    -141,   -14,   178,   141,  -141,  -141,  -141,  -141,  -141,   178,
    -141,  -141,   178,  -141,   178,  -141,  -141,   178,  -141,   121,
     166,  -141,    94,    98,   110,   116,   178,  -141,  -141,  -141,
    -141,  -141,   137,  -141,   139,  -141,  -141,   178,  -141,   143,
    -141,   184,    -3,   200,    72,  -141,   178,   178,  -141,  -141,
     159,  -141,   178,   146,  -141,  -141,   157,   174,   190,  -141,
     186,   178,    12,    12,  -141,   170,   215,  -141,  -141,    12,
    -141,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    31,    32,    33,     0,     0,     4,     6,     7,
       0,     5,     0,   113,   114,   115,   112,     0,     1,     2,
       3,    23,     0,    20,    12,     0,     9,     0,    30,    19,
       0,     0,     8,     0,     0,     0,     0,    21,     0,     0,
      10,     0,     0,     0,   106,    54,    63,    64,    65,    66,
       0,     0,    73,    74,    75,    76,    22,    58,    67,    59,
      60,    61,    62,    77,     0,    82,   103,    25,     0,     0,
      11,   102,    14,     0,    35,   105,   108,     0,     0,     0,
       0,    53,    27,    29,     0,    87,    92,    96,    99,     0,
      70,    79,    80,    81,     0,    84,    85,     0,    24,    16,
      18,     0,    13,    47,     0,   107,   104,     0,    52,    69,
      71,     0,     0,     0,    26,    90,    91,    88,    89,     0,
      94,    95,     0,    98,     0,   101,    57,     0,    78,    83,
       0,    15,     0,     0,     0,     0,    47,    34,    37,    44,
      36,    38,     0,    48,    58,   110,    55,     0,    68,     0,
      28,    86,    93,    97,   100,    17,     0,     0,    41,    40,
       0,    45,     0,   109,    72,    56,     0,    49,     0,    39,
       0,     0,    47,    47,    46,     0,    50,    42,   111,    47,
      43,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,    -4,  -141,  -141,   193,  -141,   -58,  -141,  -141,
    -141,   197,  -141,   -42,  -141,     8,   -31,  -141,  -141,  -140,
      92,    73,  -141,   -74,   -96,  -141,  -141,  -141,  -141,  -141,
    -141,   -51,  -141,  -141,   132,  -141,   -35,  -141,   111,  -141,
     107,  -141,   105,  -141,   183,  -141,   196,   201,   230,  -141,
     161,  -141,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    25,    26,    31,    70,   101,     9,
      22,    23,    28,    56,    84,    10,   139,   103,   140,   141,
     142,   166,   180,   143,    57,    81,    58,    59,    60,    61,
      62,    63,   111,    64,    65,    94,   108,    97,    86,   119,
      87,   122,    88,   124,   167,   127,    72,    67,    11,    43,
      44,   163,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    66,    19,    71,    71,   107,   110,   144,    83,    12,
      75,   100,    77,    90,   147,    66,    85,   115,   116,    78,
     132,   148,   133,   134,   135,   136,    21,    45,    46,    47,
      48,    49,   176,   177,    71,     2,     3,     4,   149,   181,
     117,   118,    42,   128,    74,   125,    51,   106,    52,    53,
      54,    55,    24,    18,    27,   126,     1,     2,     3,     4,
     113,    29,    30,   130,    34,   114,    41,     5,   131,    76,
      79,   150,   155,   164,    80,    74,   144,   144,    66,     1,
       2,     3,     4,   144,   151,    42,    98,    85,   170,    85,
       5,   102,    85,    32,    33,    71,   123,   175,   104,   138,
       1,     2,     3,     4,   112,   132,   145,   133,   134,   135,
     136,   146,    45,    46,    47,    48,    49,    13,    14,    15,
      16,    85,    85,    45,    46,    47,    48,    49,   156,    74,
     137,    51,   157,    52,    53,    54,    55,   158,    35,    36,
      50,    82,    51,   159,    52,    53,    54,    55,    45,    46,
      47,    48,    49,     2,     3,     4,    45,    46,    47,    48,
      49,    91,    92,    93,   161,    69,    99,    51,   162,    52,
      53,    54,    55,    50,   165,    51,   171,    52,    53,    54,
      55,    45,    46,    47,    48,    49,   169,    45,    46,    47,
      48,    49,   172,    45,    46,    47,    48,    49,    69,   125,
      51,   178,    52,    53,    54,    55,    51,   109,    52,    53,
      54,    55,    51,   174,    52,    53,    54,    55,    38,    39,
      95,    96,   120,   121,   179,   173,    40,    37,   160,   129,
     168,   153,   154,   152,    89,    73,    20,    68,   105
};

static const yytype_uint8 yycheck[] =
{
      35,    36,     6,    38,    39,    79,    80,   103,    50,     1,
      41,    69,    28,    64,    28,    50,    51,    20,    21,    35,
       8,    35,    10,    11,    12,    13,    15,    15,    16,    17,
      18,    19,   172,   173,    69,     4,     5,     6,   112,   179,
      43,    44,    34,    94,    32,    25,    34,    78,    36,    37,
      38,    39,    15,     0,    15,    35,     3,     4,     5,     6,
      28,    27,    28,    28,    34,    33,    35,    14,    33,    15,
      30,   113,   130,   147,    34,    32,   172,   173,   113,     3,
       4,     5,     6,   179,   119,    77,    31,   122,   162,   124,
      14,    31,   127,    27,    28,   130,    24,   171,    30,   103,
       3,     4,     5,     6,    30,     8,    31,    10,    11,    12,
      13,    31,    15,    16,    17,    18,    19,     4,     5,     6,
       7,   156,   157,    15,    16,    17,    18,    19,    34,    32,
      33,    34,    34,    36,    37,    38,    39,    27,    29,    30,
      32,    33,    34,    27,    36,    37,    38,    39,    15,    16,
      17,    18,    19,     4,     5,     6,    15,    16,    17,    18,
      19,    40,    41,    42,    27,    32,    33,    34,    29,    36,
      37,    38,    39,    32,    31,    34,    30,    36,    37,    38,
      39,    15,    16,    17,    18,    19,    27,    15,    16,    17,
      18,    19,    35,    15,    16,    17,    18,    19,    32,    25,
      34,    31,    36,    37,    38,    39,    34,    35,    36,    37,
      38,    39,    34,    27,    36,    37,    38,    39,    29,    30,
      36,    37,    22,    23,     9,    35,    33,    30,   136,    97,
     157,   124,   127,   122,    51,    39,     6,    36,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    14,    46,    47,    48,    54,
      60,    93,    60,     4,     5,     6,     7,    97,     0,    47,
      93,    15,    55,    56,    15,    49,    50,    15,    57,    27,
      28,    51,    27,    28,    34,    29,    30,    56,    29,    30,
      50,    35,    60,    94,    95,    15,    16,    17,    18,    19,
      32,    34,    36,    37,    38,    39,    58,    69,    71,    72,
      73,    74,    75,    76,    78,    79,    81,    92,    92,    32,
      52,    81,    91,    91,    32,    61,    15,    28,    35,    30,
      34,    70,    33,    58,    59,    81,    83,    85,    87,    89,
      76,    40,    41,    42,    80,    36,    37,    82,    31,    33,
      52,    53,    31,    62,    30,    95,    61,    68,    81,    35,
      68,    77,    30,    28,    33,    20,    21,    43,    44,    84,
      22,    23,    86,    24,    88,    25,    35,    90,    76,    79,
      28,    33,     8,    10,    11,    12,    13,    33,    47,    61,
      63,    64,    65,    68,    69,    31,    31,    28,    35,    68,
      58,    81,    83,    85,    87,    52,    34,    34,    27,    27,
      65,    27,    29,    96,    68,    31,    66,    89,    66,    27,
      68,    30,    35,    35,    27,    68,    64,    64,    31,     9,
      67,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    47,    47,    48,    49,
      49,    50,    51,    51,    52,    52,    52,    53,    53,    54,
      55,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      56,    60,    60,    60,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    73,    74,    75,    76,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    90,    91,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     4,     1,
       3,     4,     0,     4,     1,     3,     2,     3,     1,     3,
       1,     3,     4,     0,     4,     1,     3,     2,     3,     1,
       2,     1,     1,     1,     3,     0,     2,     1,     1,     3,
       2,     2,     5,     6,     1,     2,     4,     0,     1,     1,
       0,     2,     1,     2,     1,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       2,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       3,     1,     1,     1,     7,     6,     1,     3,     2,     5,
       0,     4,     1,     1,     1,     1
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 43 "../../src/driver/parser.y"
                {
    RootNode *tmp_root = dynamic_cast<RootNode*>(yyvsp[-1]);
    assert(tmp_root != nullptr);
    tmp_root->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 1497 "../../src/driver/parser.cpp"
    break;

  case 3:
#line 49 "../../src/driver/parser.y"
                   {
    RootNode *tmp_root = dynamic_cast<RootNode*>(yyvsp[-1]);
    assert(tmp_root != nullptr);
    tmp_root->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];    
  }
#line 1508 "../../src/driver/parser.cpp"
    break;

  case 4:
#line 55 "../../src/driver/parser.y"
       {
    assert(root != nullptr);
    root->AddNode(yyvsp[0]);
    yyval = root;
  }
#line 1518 "../../src/driver/parser.cpp"
    break;

  case 5:
#line 60 "../../src/driver/parser.y"
          {
    assert(root != nullptr);
    root->AddNode(yyvsp[0]);
    yyval = root;    
  }
#line 1528 "../../src/driver/parser.cpp"
    break;

  case 6:
#line 68 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1536 "../../src/driver/parser.cpp"
    break;

  case 7:
#line 71 "../../src/driver/parser.y"
          {
    yyval = yyvsp[0];
  }
#line 1544 "../../src/driver/parser.cpp"
    break;

  case 8:
#line 77 "../../src/driver/parser.y"
                               {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    yyval = yyvsp[-1];
  }
#line 1555 "../../src/driver/parser.cpp"
    break;

  case 9:
#line 86 "../../src/driver/parser.y"
           {
    DeclNode* new_decl_node = new DeclNode(NodeType::CONST_DECL);
    assert(new_decl_node != nullptr);
    new_decl_node->AddDecl();
    yyval = new_decl_node;
  }
#line 1566 "../../src/driver/parser.cpp"
    break;

  case 10:
#line 92 "../../src/driver/parser.y"
                            {
    DeclNode* tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-2]);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->AddDecl();
    yyval = yyvsp[-2];   
  }
#line 1577 "../../src/driver/parser.cpp"
    break;

  case 11:
#line 101 "../../src/driver/parser.y"
                                               {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent();
    declnode_tmp_init_val = yyvsp[0];
    yyval = nullptr;
  }
#line 1587 "../../src/driver/parser.cpp"
    break;

  case 12:
#line 109 "../../src/driver/parser.y"
              {
    declnode_tmp_array_dimension_array.resize(0);
    yyval = nullptr;
  }
#line 1596 "../../src/driver/parser.cpp"
    break;

  case 13:
#line 113 "../../src/driver/parser.y"
                                         {
    declnode_tmp_array_dimension_array.push_back(yyvsp[-1]);
    yyval = yyvsp[-3];
  }
#line 1605 "../../src/driver/parser.cpp"
    break;

  case 14:
#line 120 "../../src/driver/parser.y"
           {
    yyval = yyvsp[0];
  }
#line 1613 "../../src/driver/parser.cpp"
    break;

  case 15:
#line 123 "../../src/driver/parser.y"
                           {
    yyval = yyvsp[-1];
  }
#line 1621 "../../src/driver/parser.cpp"
    break;

  case 16:
#line 126 "../../src/driver/parser.y"
          {
    yyval = new InitValNode;
  }
#line 1629 "../../src/driver/parser.cpp"
    break;

  case 17:
#line 132 "../../src/driver/parser.y"
                                    {
    dynamic_cast<InitValNode*>(yyvsp[-2])->AddInitVal(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 1638 "../../src/driver/parser.cpp"
    break;

  case 18:
#line 136 "../../src/driver/parser.y"
               {
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal(yyvsp[0]);
    yyval = new_init_val_node;
  }
#line 1648 "../../src/driver/parser.cpp"
    break;

  case 19:
#line 144 "../../src/driver/parser.y"
                       {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]); 
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    yyval = yyvsp[-1];
  }
#line 1659 "../../src/driver/parser.cpp"
    break;

  case 20:
#line 153 "../../src/driver/parser.y"
         {
    DeclNode* new_decl_node = new DeclNode(NodeType::VAR_DECL);
    new_decl_node->AddDecl();
    yyval = new_decl_node;
  }
#line 1669 "../../src/driver/parser.cpp"
    break;

  case 21:
#line 158 "../../src/driver/parser.y"
                         {
    dynamic_cast<DeclNode*>(yyvsp[-2])->AddDecl();
    yyval = yyvsp[-2];
  }
#line 1678 "../../src/driver/parser.cpp"
    break;

  case 22:
#line 165 "../../src/driver/parser.y"
                                           {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent();
    declnode_tmp_init_val = yyvsp[0];
    yyval = nullptr; 
  }
#line 1688 "../../src/driver/parser.cpp"
    break;

  case 23:
#line 173 "../../src/driver/parser.y"
              {
    declnode_tmp_array_dimension_array.resize(0);
    yyval = nullptr;
  }
#line 1697 "../../src/driver/parser.cpp"
    break;

  case 24:
#line 177 "../../src/driver/parser.y"
                                     {
    declnode_tmp_array_dimension_array.push_back(yyvsp[-1]);
    yyval = yyvsp[-3];
  }
#line 1706 "../../src/driver/parser.cpp"
    break;

  case 25:
#line 184 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1714 "../../src/driver/parser.cpp"
    break;

  case 26:
#line 187 "../../src/driver/parser.y"
                         {
    yyval = yyvsp[-1];
  }
#line 1722 "../../src/driver/parser.cpp"
    break;

  case 27:
#line 190 "../../src/driver/parser.y"
          {
    yyval = new InitValNode;
  }
#line 1730 "../../src/driver/parser.cpp"
    break;

  case 28:
#line 196 "../../src/driver/parser.y"
                                {
    dynamic_cast<InitValNode*>(yyvsp[-2])->AddInitVal(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 1739 "../../src/driver/parser.cpp"
    break;

  case 29:
#line 200 "../../src/driver/parser.y"
             {
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal(yyvsp[0]);
    yyval = new_init_val_node;
  }
#line 1749 "../../src/driver/parser.cpp"
    break;

  case 30:
#line 208 "../../src/driver/parser.y"
                            {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-1])->GetIdent();
    declnode_tmp_init_val = nullptr;
    yyval = nullptr;
  }
#line 1759 "../../src/driver/parser.cpp"
    break;

  case 31:
#line 216 "../../src/driver/parser.y"
      {
    declnode_tmp_basic_type = BasicType::INT;
    funcdefnode_tmp_fparam_basic_type = BasicType::INT;
    yyval = nullptr;
  }
#line 1769 "../../src/driver/parser.cpp"
    break;

  case 32:
#line 221 "../../src/driver/parser.y"
        {
    declnode_tmp_basic_type = BasicType::FLOAT;
    funcdefnode_tmp_fparam_basic_type = BasicType::FLOAT;
    yyval = nullptr;
  }
#line 1779 "../../src/driver/parser.cpp"
    break;

  case 33:
#line 226 "../../src/driver/parser.y"
       {
    declnode_tmp_basic_type = BasicType::CHAR;
    funcdefnode_tmp_fparam_basic_type = BasicType::CHAR;
    yyval = nullptr;
  }
#line 1789 "../../src/driver/parser.cpp"
    break;

  case 34:
#line 234 "../../src/driver/parser.y"
                        {
    yyval = yyvsp[-1];
  }
#line 1797 "../../src/driver/parser.cpp"
    break;

  case 35:
#line 240 "../../src/driver/parser.y"
              {
    yyval = new BlockNode;
    assert(yyval != nullptr);
  }
#line 1806 "../../src/driver/parser.cpp"
    break;

  case 36:
#line 244 "../../src/driver/parser.y"
                          {
    BlockNode *tmp_block_node = dynamic_cast<BlockNode*>(yyvsp[-1]); 
    assert(tmp_block_node != nullptr);
    tmp_block_node->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 1817 "../../src/driver/parser.cpp"
    break;

  case 37:
#line 253 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 1825 "../../src/driver/parser.cpp"
    break;

  case 38:
#line 256 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 1833 "../../src/driver/parser.cpp"
    break;

  case 39:
#line 262 "../../src/driver/parser.y"
                       {
    yyval = new ReturnStmtNode(yyvsp[-1]);
  }
#line 1841 "../../src/driver/parser.cpp"
    break;

  case 40:
#line 265 "../../src/driver/parser.y"
               {
    yyval = new ContinueStmtNode;  
  }
#line 1849 "../../src/driver/parser.cpp"
    break;

  case 41:
#line 268 "../../src/driver/parser.y"
            {
    yyval = new BreakStmtNode;
  }
#line 1857 "../../src/driver/parser.cpp"
    break;

  case 42:
#line 271 "../../src/driver/parser.y"
                          {
    yyval = new WhileStmtNode(yyvsp[-2], yyvsp[0]);
  }
#line 1865 "../../src/driver/parser.cpp"
    break;

  case 43:
#line 274 "../../src/driver/parser.y"
                                  {
    yyval = new IfStmtNode(yyvsp[-3], yyvsp[-1], yyvsp[0]);
  }
#line 1873 "../../src/driver/parser.cpp"
    break;

  case 44:
#line 277 "../../src/driver/parser.y"
        {
    yyval = yyvsp[0];
  }
#line 1881 "../../src/driver/parser.cpp"
    break;

  case 45:
#line 280 "../../src/driver/parser.y"
                {
    yyval = yyvsp[-1];
  }
#line 1889 "../../src/driver/parser.cpp"
    break;

  case 46:
#line 283 "../../src/driver/parser.y"
                   {
    yyval = new AssignStmtNode(yyvsp[-3], yyvsp[-1]);
  }
#line 1897 "../../src/driver/parser.cpp"
    break;

  case 47:
#line 289 "../../src/driver/parser.y"
              {
    yyval = nullptr;
  }
#line 1905 "../../src/driver/parser.cpp"
    break;

  case 48:
#line 292 "../../src/driver/parser.y"
      {
    yyval = yyvsp[0];
  }
#line 1913 "../../src/driver/parser.cpp"
    break;

  case 49:
#line 298 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1921 "../../src/driver/parser.cpp"
    break;

  case 50:
#line 304 "../../src/driver/parser.y"
              {
    yyval = nullptr;
  }
#line 1929 "../../src/driver/parser.cpp"
    break;

  case 51:
#line 307 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1937 "../../src/driver/parser.cpp"
    break;

  case 52:
#line 313 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1945 "../../src/driver/parser.cpp"
    break;

  case 53:
#line 319 "../../src/driver/parser.y"
                  {
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode(dynamic_cast<IdentNode*>(yyvsp[-1]));
    tmp_node->AddLVal();
    yyval = tmp_node;
  }
#line 1955 "../../src/driver/parser.cpp"
    break;

  case 54:
#line 324 "../../src/driver/parser.y"
        {
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode(dynamic_cast<IdentNode*>(yyvsp[0]));
    yyval = tmp_node;    
  }
#line 1964 "../../src/driver/parser.cpp"
    break;

  case 55:
#line 331 "../../src/driver/parser.y"
              {
    lvalprimaryexpnode_tmp_index_array.resize(0);
    lvalprimaryexpnode_tmp_index_array.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 1974 "../../src/driver/parser.cpp"
    break;

  case 56:
#line 336 "../../src/driver/parser.y"
                        {
    printf("1\n");
    lvalprimaryexpnode_tmp_index_array.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 1984 "../../src/driver/parser.cpp"
    break;

  case 57:
#line 344 "../../src/driver/parser.y"
                 {
    yyval = yyvsp[-1];
  }
#line 1992 "../../src/driver/parser.cpp"
    break;

  case 58:
#line 347 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 2000 "../../src/driver/parser.cpp"
    break;

  case 59:
#line 350 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 2008 "../../src/driver/parser.cpp"
    break;

  case 60:
#line 353 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 2016 "../../src/driver/parser.cpp"
    break;

  case 61:
#line 356 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 2024 "../../src/driver/parser.cpp"
    break;

  case 62:
#line 359 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2032 "../../src/driver/parser.cpp"
    break;

  case 63:
#line 365 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 2040 "../../src/driver/parser.cpp"
    break;

  case 64:
#line 371 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 2048 "../../src/driver/parser.cpp"
    break;

  case 65:
#line 377 "../../src/driver/parser.y"
             {
    yyval = yyvsp[0];
  }
#line 2056 "../../src/driver/parser.cpp"
    break;

  case 66:
#line 383 "../../src/driver/parser.y"
               {
    yyval = yyvsp[0];
  }
#line 2064 "../../src/driver/parser.cpp"
    break;

  case 67:
#line 389 "../../src/driver/parser.y"
             {
    yyval = yyvsp[0];
  }
#line 2072 "../../src/driver/parser.cpp"
    break;

  case 68:
#line 392 "../../src/driver/parser.y"
                               {
    dynamic_cast<FuncCallExpNode*>(yyvsp[-1])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-3]));
    yyval = yyvsp[-1];
  }
#line 2081 "../../src/driver/parser.cpp"
    break;

  case 69:
#line 396 "../../src/driver/parser.y"
                {
    FuncCallExpNode* new_node = new FuncCallExpNode;
    new_node->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-2]));
    yyval = new_node;
  }
#line 2091 "../../src/driver/parser.cpp"
    break;

  case 70:
#line 401 "../../src/driver/parser.y"
                   {
    dynamic_cast<UnaryExpNode*>(yyvsp[-1])->SetExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2100 "../../src/driver/parser.cpp"
    break;

  case 71:
#line 408 "../../src/driver/parser.y"
      {
    FuncCallExpNode *new_node = new FuncCallExpNode;
    new_node->AddParam(yyvsp[0]);
    yyval = new_node;
  }
#line 2110 "../../src/driver/parser.cpp"
    break;

  case 72:
#line 413 "../../src/driver/parser.y"
                         {
    dynamic_cast<FuncCallExpNode*>(yyvsp[-2])->AddParam(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 2119 "../../src/driver/parser.cpp"
    break;

  case 73:
#line 420 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::POSITIVE);
    yyval = new_node;
  }
#line 2128 "../../src/driver/parser.cpp"
    break;

  case 74:
#line 424 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NEGATIVE);
    yyval = new_node;
  }
#line 2137 "../../src/driver/parser.cpp"
    break;

  case 75:
#line 428 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NOT);
    yyval = new_node;
  }
#line 2146 "../../src/driver/parser.cpp"
    break;

  case 76:
#line 432 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::GETPTR);
    yyval = new_node;
  }
#line 2155 "../../src/driver/parser.cpp"
    break;

  case 77:
#line 439 "../../src/driver/parser.y"
           {
    yyval = yyvsp[0];
  }
#line 2163 "../../src/driver/parser.cpp"
    break;

  case 78:
#line 442 "../../src/driver/parser.y"
                        {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2173 "../../src/driver/parser.cpp"
    break;

  case 79:
#line 450 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MUL);
    yyval = new_node;
  }
#line 2182 "../../src/driver/parser.cpp"
    break;

  case 80:
#line 454 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::DIV);
    yyval = new_node;
  }
#line 2191 "../../src/driver/parser.cpp"
    break;

  case 81:
#line 458 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MOD);
    yyval = new_node;
  }
#line 2200 "../../src/driver/parser.cpp"
    break;

  case 82:
#line 465 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2208 "../../src/driver/parser.cpp"
    break;

  case 83:
#line 468 "../../src/driver/parser.y"
                      {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1]; 
  }
#line 2218 "../../src/driver/parser.cpp"
    break;

  case 84:
#line 476 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::ADD);
    yyval = new_node;
  }
#line 2227 "../../src/driver/parser.cpp"
    break;

  case 85:
#line 480 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::SUB);
    yyval = new_node;
  }
#line 2236 "../../src/driver/parser.cpp"
    break;

  case 86:
#line 487 "../../src/driver/parser.y"
                      {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2246 "../../src/driver/parser.cpp"
    break;

  case 87:
#line 492 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0]; 
  }
#line 2254 "../../src/driver/parser.cpp"
    break;

  case 88:
#line 498 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LE);
    yyval = new_node; 
  }
#line 2263 "../../src/driver/parser.cpp"
    break;

  case 89:
#line 502 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GE);
    yyval = new_node; 
  }
#line 2272 "../../src/driver/parser.cpp"
    break;

  case 90:
#line 506 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LEEQ);
    yyval = new_node; 
  }
#line 2281 "../../src/driver/parser.cpp"
    break;

  case 91:
#line 510 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GEEQ);
    yyval = new_node; 
  }
#line 2290 "../../src/driver/parser.cpp"
    break;

  case 92:
#line 517 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2298 "../../src/driver/parser.cpp"
    break;

  case 93:
#line 520 "../../src/driver/parser.y"
                    {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2308 "../../src/driver/parser.cpp"
    break;

  case 94:
#line 528 "../../src/driver/parser.y"
     {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::EQ);
    yyval = new_node;
  }
#line 2317 "../../src/driver/parser.cpp"
    break;

  case 95:
#line 532 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::UNEQ);
    yyval = new_node;
  }
#line 2326 "../../src/driver/parser.cpp"
    break;

  case 96:
#line 539 "../../src/driver/parser.y"
        {
    yyval = yyvsp[0];
  }
#line 2334 "../../src/driver/parser.cpp"
    break;

  case 97:
#line 542 "../../src/driver/parser.y"
                       {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2344 "../../src/driver/parser.cpp"
    break;

  case 98:
#line 550 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::AND);
    yyval = new_node;
  }
#line 2353 "../../src/driver/parser.cpp"
    break;

  case 99:
#line 557 "../../src/driver/parser.y"
          {
    yyval = yyvsp[0];
  }
#line 2361 "../../src/driver/parser.cpp"
    break;

  case 100:
#line 560 "../../src/driver/parser.y"
                       {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2371 "../../src/driver/parser.cpp"
    break;

  case 101:
#line 568 "../../src/driver/parser.y"
     {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::OR);
    yyval = new_node;
  }
#line 2380 "../../src/driver/parser.cpp"
    break;

  case 102:
#line 575 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2388 "../../src/driver/parser.cpp"
    break;

  case 103:
#line 581 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2396 "../../src/driver/parser.cpp"
    break;

  case 104:
#line 587 "../../src/driver/parser.y"
                                                  {
    dynamic_cast<FuncDefNode*>(yyvsp[-5])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-4]));
    dynamic_cast<FuncDefNode*>(yyvsp[-5])->SetBlock(yyvsp[0]);
    yyval = funcdefnode_tmp_func_def_node;
  }
#line 2406 "../../src/driver/parser.cpp"
    break;

  case 105:
#line 592 "../../src/driver/parser.y"
                                   {
    dynamic_cast<FuncDefNode*>(yyvsp[-4])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-3]));
    dynamic_cast<FuncDefNode*>(yyvsp[-4])->SetBlock(yyvsp[0]);
    yyval = funcdefnode_tmp_func_def_node;
  }
#line 2416 "../../src/driver/parser.cpp"
    break;

  case 106:
#line 600 "../../src/driver/parser.y"
             {
    funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>(yyvsp[0]));
    yyval = nullptr;
  }
#line 2425 "../../src/driver/parser.cpp"
    break;

  case 107:
#line 604 "../../src/driver/parser.y"
                                {
    funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>(yyvsp[0]));
    yyval = nullptr;
  }
#line 2434 "../../src/driver/parser.cpp"
    break;

  case 108:
#line 611 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 2442 "../../src/driver/parser.cpp"
    break;

  case 109:
#line 614 "../../src/driver/parser.y"
                                          {
    yyval = yyvsp[-3];
  }
#line 2450 "../../src/driver/parser.cpp"
    break;

  case 110:
#line 620 "../../src/driver/parser.y"
              {
    funcdefnode_tmp_fparam_index_list.resize(0);
    funcdefnode_tmp_fparam_index_list.push_back(nullptr);
    yyval = nullptr;
  }
#line 2460 "../../src/driver/parser.cpp"
    break;

  case 111:
#line 625 "../../src/driver/parser.y"
                                  {
    funcdefnode_tmp_fparam_index_list.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 2469 "../../src/driver/parser.cpp"
    break;

  case 112:
#line 632 "../../src/driver/parser.y"
       {
    FuncDefNode *new_node = new FuncDefNode(BasicType::VOID);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2479 "../../src/driver/parser.cpp"
    break;

  case 113:
#line 637 "../../src/driver/parser.y"
      {
    FuncDefNode *new_node = new FuncDefNode(BasicType::INT);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2489 "../../src/driver/parser.cpp"
    break;

  case 114:
#line 642 "../../src/driver/parser.y"
        {
    FuncDefNode *new_node = new FuncDefNode(BasicType::FLOAT);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2499 "../../src/driver/parser.cpp"
    break;

  case 115:
#line 647 "../../src/driver/parser.y"
       {
    FuncDefNode *new_node = new FuncDefNode(BasicType::CHAR);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2509 "../../src/driver/parser.cpp"
    break;


#line 2513 "../../src/driver/parser.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 654 "../../src/driver/parser.y"
