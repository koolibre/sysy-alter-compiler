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
  #define YYDEBUG 1
#endif

#include <cassert>     // use assert()

#include <iostream>    // use std::cout
#include <string>      // use std::string
#include <sstream>

#include "ast/ast.hpp" // use struct Node

#define YYSTYPE Node*
// output error message
// defined in scanner.cpp
extern void yyerror(const char *str);

// defined in scanner.cpp
extern int yylex();

extern int yylineno;


#line 98 "../../src/driver/parser.cpp"

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

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
       0,    48,    48,    54,    60,    65,    73,    76,    82,    88,
      98,   105,   115,   121,   130,   138,   142,   149,   152,   155,
     161,   165,   173,   179,   189,   196,   206,   211,   218,   226,
     230,   237,   240,   243,   249,   253,   261,   269,   274,   279,
     287,   290,   299,   303,   317,   320,   326,   329,   332,   335,
     338,   341,   344,   347,   350,   365,   380,   391,   394,   400,
     406,   409,   415,   421,   426,   433,   438,   446,   449,   452,
     455,   458,   461,   467,   473,   479,   485,   491,   494,   498,
     503,   510,   515,   523,   527,   531,   535,   542,   545,   553,
     557,   561,   568,   571,   579,   583,   590,   595,   601,   605,
     609,   613,   620,   623,   631,   635,   642,   645,   653,   660,
     663,   671,   678,   684,   690,   717,   736,   747,   758,   768,
     779,   793,   796,   799,   807,   818,   823,   830,   835,   840,
     845,   850
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

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     300,    73,  -150,  -150,  -150,   141,   276,   296,  -150,  -150,
    -150,    17,  -150,    18,    22,  -150,  -150,  -150,  -150,  -150,
      21,    26,    23,    -3,  -150,    25,  -150,  -150,  -150,    45,
    -150,    80,  -150,    55,  -150,    83,    62,   122,    12,  -150,
     124,  -150,    86,    70,  -150,   136,  -150,   103,  -150,  -150,
    -150,  -150,    11,    61,   217,   256,  -150,    65,   225,   256,
    -150,  -150,  -150,  -150,   105,    11,   117,     0,  -150,    72,
    -150,  -150,  -150,  -150,   184,   256,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   256,    82,
     146,  -150,    64,    11,    57,   192,  -150,   146,  -150,   108,
     125,   104,  -150,   121,   175,    11,   256,   250,   138,  -150,
    -150,     6,   146,    54,   162,   131,    -8,  -150,  -150,  -150,
    -150,   256,  -150,  -150,   256,  -150,  -150,    11,  -150,  -150,
      40,  -150,   165,    13,    14,   167,   177,   256,    15,  -150,
    -150,  -150,  -150,  -150,   178,  -150,   144,   146,   158,   181,
    -150,  -150,   182,  -150,  -150,    58,   256,   217,  -150,  -150,
    -150,  -150,  -150,   256,  -150,  -150,   256,  -150,   256,  -150,
    -150,   256,  -150,    82,  -150,   225,  -150,  -150,   159,   256,
     159,   256,  -150,  -150,   179,  -150,   256,  -150,  -150,  -150,
     256,  -150,   183,  -150,   146,    54,   162,   131,  -150,   206,
     202,   194,  -150,   203,  -150,   200,   209,   209,  -150,  -150,
     159,  -150,   159,   159,  -150,   256,  -150,   206,  -150,   214,
    -150,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    37,    38,    39,     0,     0,     0,     4,     6,
       7,     0,     5,     0,     0,   128,   129,   130,   127,   131,
       0,     0,    15,     0,    12,     0,     1,     2,     3,     0,
      29,     0,    26,     0,    15,     0,     0,     0,     0,    25,
       0,    23,     0,     0,    24,    36,    22,     0,    11,     9,
      10,     8,     0,     0,     0,     0,    13,     0,     0,     0,
      27,    41,    42,   118,     0,     0,     0,     0,   119,    64,
      73,    74,    75,    76,     0,     0,    83,    84,    85,    86,
      14,    68,    77,    69,    70,    71,    72,    87,     0,    92,
     112,    17,     0,     0,     0,     0,    28,   113,    31,     0,
       0,   123,   115,   121,     0,     0,     0,     0,    63,    19,
      21,     0,    97,   102,   106,   109,     0,    80,    89,    90,
      91,     0,    94,    95,     0,    16,   117,     0,    33,    35,
       0,    30,    41,     0,     0,     0,     0,    57,     0,    40,
      44,    51,    43,    45,     0,    58,    68,    62,     0,     0,
     120,   114,     0,    79,    81,     0,     0,     0,    18,   100,
     101,    98,    99,     0,   104,   105,     0,   108,     0,   111,
      67,     0,    88,    93,   116,     0,    32,    56,     0,     0,
       0,     0,    48,    47,     0,    52,     0,   125,   125,    65,
       0,    78,     0,    20,    96,   103,   107,   110,    34,    60,
       0,    59,    54,     0,    46,     0,   124,   122,    82,    66,
       0,    55,     0,     0,    53,     0,    61,    60,    49,     0,
      50,   126
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,    -1,  -150,   174,   204,  -150,   -66,  -150,  -150,
    -150,   201,  -150,   -88,  -150,     1,   -43,  -150,  -150,  -149,
     110,    69,    35,   -96,   -97,  -150,  -150,  -150,  -150,  -150,
    -150,   -62,  -150,  -150,   134,  -150,   -54,  -150,    94,  -150,
     102,  -150,   107,  -150,   222,  -150,   221,   220,   291,   251,
     205,   119,   306
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    23,    24,    40,    80,   111,    10,
      31,    32,    45,    96,   130,    11,   141,   100,   142,   143,
     144,   200,   211,   145,    81,   108,    82,    83,    84,    85,
      86,    87,   155,    88,    89,   121,   147,   124,   113,   163,
     114,   166,   115,   168,   201,   171,    91,    98,    12,    67,
      68,   206,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    90,    14,   146,    97,    97,    27,   129,   110,    63,
     152,   154,    61,    52,   178,   180,    21,   169,    29,    33,
      90,   112,   102,    36,    41,    42,   117,   170,   104,   199,
      34,   202,    30,    34,   157,   105,    38,    34,  -131,   158,
      43,    97,   -64,    62,   -64,   106,    53,   179,   181,   107,
     126,   -64,   -64,    39,    66,   -64,   -64,   -64,    66,   172,
     192,   216,   151,   217,   218,     2,     3,     4,   175,     2,
       3,     4,    44,   176,   159,   160,    64,     2,     3,     4,
      64,   146,    48,   146,   174,   104,   190,   198,    13,    50,
     205,   193,   127,   191,   208,   125,    65,   161,   162,   140,
      93,    34,   106,    90,    57,    66,   107,    46,    47,   194,
      49,    42,   112,   146,   112,   146,   146,   112,    30,   219,
     101,    97,   118,   119,   120,   112,   132,   112,     1,     2,
       3,     4,   103,   133,   148,   134,   135,   136,   137,   131,
     138,    70,    71,    72,    73,    15,    16,    17,    18,    51,
      42,   149,   -57,    54,    55,   167,    19,    62,   139,    75,
     132,    76,    77,    78,    79,    58,    59,   133,   156,   134,
     135,   136,   137,   186,    69,    70,    71,    72,    73,     2,
       3,     4,   122,   123,   164,   165,   -57,    35,    37,   187,
      64,    62,   177,    75,   182,    76,    77,    78,    79,    69,
      70,    71,    72,    73,   183,   185,   204,    69,    70,    71,
      72,    73,   188,   189,   209,   210,    74,   109,    75,   169,
      76,    77,    78,    79,    95,   128,    75,   214,    76,    77,
      78,    79,    69,    70,    71,    72,    73,   212,   213,   215,
      69,    70,    71,    72,    73,   221,    56,   184,    60,    74,
     203,    75,   220,    76,    77,    78,    79,    95,   173,    75,
     195,    76,    77,    78,    79,    69,    70,    71,    72,    73,
     196,    69,    70,    71,    72,    73,    92,    21,   197,    99,
      15,    16,    17,    18,    75,   153,    76,    77,    78,    79,
      75,    22,    76,    77,    78,    79,    26,   116,    28,     1,
       2,     3,     4,     1,     2,     3,     4,   207,    94,   150,
       5,     6,    25,     0,     5,     6
};

static const yytype_int16 yycheck[] =
{
      54,    55,     1,   100,    58,    59,     7,    95,    74,    52,
     106,   107,     1,     1,     1,     1,     1,    25,     1,     1,
      74,    75,    65,     1,    27,    28,    88,    35,    28,   178,
      15,   180,    15,    15,    28,    35,    15,    15,    15,    33,
      15,    95,    27,    32,    29,    30,    34,    34,    34,    34,
      93,    36,    37,    27,    53,    40,    41,    42,    57,   121,
     156,   210,   105,   212,   213,     4,     5,     6,    28,     4,
       5,     6,    27,    33,    20,    21,    15,     4,     5,     6,
      15,   178,    27,   180,   127,    28,    28,   175,    15,    27,
     186,   157,    35,    35,   190,    31,    35,    43,    44,   100,
      35,    15,    30,   157,    34,   104,    34,    27,    28,   163,
      27,    28,   166,   210,   168,   212,   213,   171,    15,   215,
      15,   175,    40,    41,    42,   179,     1,   181,     3,     4,
       5,     6,    15,     8,    30,    10,    11,    12,    13,    31,
      15,    16,    17,    18,    19,     4,     5,     6,     7,    27,
      28,    30,    27,    29,    30,    24,    15,    32,    33,    34,
       1,    36,    37,    38,    39,    29,    30,     8,    30,    10,
      11,    12,    13,    29,    15,    16,    17,    18,    19,     4,
       5,     6,    36,    37,    22,    23,    27,    13,    14,    31,
      15,    32,    27,    34,    27,    36,    37,    38,    39,    15,
      16,    17,    18,    19,    27,    27,    27,    15,    16,    17,
      18,    19,    31,    31,    31,     9,    32,    33,    34,    25,
      36,    37,    38,    39,    32,    33,    34,    27,    36,    37,
      38,    39,    15,    16,    17,    18,    19,    35,    35,    30,
      15,    16,    17,    18,    19,    31,    42,   137,    47,    32,
     181,    34,   217,    36,    37,    38,    39,    32,   124,    34,
     166,    36,    37,    38,    39,    15,    16,    17,    18,    19,
     168,    15,    16,    17,    18,    19,    55,     1,   171,    59,
       4,     5,     6,     7,    34,    35,    36,    37,    38,    39,
      34,    15,    36,    37,    38,    39,     0,    75,     7,     3,
       4,     5,     6,     3,     4,     5,     6,   188,    57,   104,
      14,    15,     6,    -1,    14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    14,    15,    46,    47,    48,
      54,    60,    93,    15,    60,     4,     5,     6,     7,    15,
      97,     1,    15,    49,    50,    97,     0,    47,    93,     1,
      15,    55,    56,     1,    15,    49,     1,    49,    15,    27,
      51,    27,    28,    15,    27,    57,    27,    28,    27,    27,
      27,    27,     1,    34,    29,    30,    50,    34,    29,    30,
      56,     1,    32,    61,    15,    35,    60,    94,    95,    15,
      16,    17,    18,    19,    32,    34,    36,    37,    38,    39,
      52,    69,    71,    72,    73,    74,    75,    76,    78,    79,
      81,    91,    91,    35,    94,    32,    58,    81,    92,    92,
      62,    15,    61,    15,    28,    35,    30,    34,    70,    33,
      52,    53,    81,    83,    85,    87,    89,    76,    40,    41,
      42,    80,    36,    37,    82,    31,    61,    35,    33,    58,
      59,    31,     1,     8,    10,    11,    12,    13,    15,    33,
      47,    61,    63,    64,    65,    68,    69,    81,    30,    30,
      95,    61,    68,    35,    68,    77,    30,    28,    33,    20,
      21,    43,    44,    84,    22,    23,    86,    24,    88,    25,
      35,    90,    76,    79,    61,    28,    33,    27,     1,    34,
       1,    34,    27,    27,    65,    27,    29,    31,    31,    31,
      28,    35,    68,    52,    81,    83,    85,    87,    58,    64,
      66,    89,    64,    66,    27,    68,    96,    96,    68,    31,
       9,    67,    35,    35,    27,    30,    64,    64,    64,    68,
      67,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    47,    47,    48,    48,
      48,    48,    49,    49,    50,    51,    51,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    58,    59,    59,    56,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    73,    74,    75,    76,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    90,    91,    92,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     4,     4,
       4,     4,     1,     3,     4,     0,     4,     1,     3,     2,
       3,     1,     3,     3,     3,     3,     1,     3,     4,     0,
       4,     1,     3,     2,     3,     1,     2,     1,     1,     1,
       3,     1,     0,     2,     1,     1,     3,     2,     2,     5,
       6,     1,     2,     4,     3,     4,     2,     0,     1,     1,
       0,     2,     1,     2,     1,     3,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       2,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       3,     1,     1,     1,     7,     6,     7,     6,     5,     1,
       3,     2,     5,     2,     5,     0,     4,     1,     1,     1,
       1,     1
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
#line 48 "../../src/driver/parser.y"
                {
    RootNode *tmp_root = dynamic_cast<RootNode*>(yyvsp[-1]);
    assert(tmp_root != nullptr);
    tmp_root->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 1536 "../../src/driver/parser.cpp"
    break;

  case 3:
#line 54 "../../src/driver/parser.y"
                   {
    RootNode *tmp_root = dynamic_cast<RootNode*>(yyvsp[-1]);
    assert(tmp_root != nullptr);
    tmp_root->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];    
  }
#line 1547 "../../src/driver/parser.cpp"
    break;

  case 4:
#line 60 "../../src/driver/parser.y"
       {
    assert(root != nullptr);
    root->AddNode(yyvsp[0]);
    yyval = root;
  }
#line 1557 "../../src/driver/parser.cpp"
    break;

  case 5:
#line 65 "../../src/driver/parser.y"
          {
    assert(root != nullptr);
    root->AddNode(yyvsp[0]);
    yyval = root;    
  }
#line 1567 "../../src/driver/parser.cpp"
    break;

  case 6:
#line 73 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1575 "../../src/driver/parser.cpp"
    break;

  case 7:
#line 76 "../../src/driver/parser.y"
          {
    yyval = yyvsp[0];
  }
#line 1583 "../../src/driver/parser.cpp"
    break;

  case 8:
#line 82 "../../src/driver/parser.y"
                               {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    yyval = yyvsp[-1];
  }
#line 1594 "../../src/driver/parser.cpp"
    break;

  case 9:
#line 88 "../../src/driver/parser.y"
                               {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]);
    assert(tmp_decl_node != nullptr);
    std::stringstream msg;
    msg << "[ERROR] Declaration to const value(s) at line " << dynamic_cast<Node*>(yyvsp[-1])->line_no << " is omitted due to unknown type \"" << dynamic_cast<IdentNode*>(yyvsp[-2])->GetIdent() << "\".";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>(yyvsp[-1])->line_no);
    yyval = new_node;
    delete tmp_decl_node;
    printf("%s\n",msg.str().c_str());
  }
#line 1609 "../../src/driver/parser.cpp"
    break;

  case 10:
#line 98 "../../src/driver/parser.y"
                        {
    std::stringstream msg;
    msg << "[ERROR] Declaration to const value(s) at line " << yylineno << " is omitted due to error(s) in the list of declaration.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    yyval = new_node;
    printf("%s\n",msg.str().c_str());
  }
#line 1621 "../../src/driver/parser.cpp"
    break;

  case 11:
#line 105 "../../src/driver/parser.y"
                        {
    std::stringstream msg;
    msg << "[ERROR] Declaration to const value(s) at line " << dynamic_cast<Node*>(yyvsp[-2])->line_no << " is omitted due to error(s) in the list of declaration and data type.";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>(yyvsp[-2])->line_no);
    yyval = new_node;
    printf("%s\n",msg.str().c_str());
  }
#line 1633 "../../src/driver/parser.cpp"
    break;

  case 12:
#line 115 "../../src/driver/parser.y"
           {
    DeclNode* new_decl_node = new DeclNode(NodeType::CONST_DECL,yylineno);
    assert(new_decl_node != nullptr);
    new_decl_node->AddDecl();
    yyval = new_decl_node;
  }
#line 1644 "../../src/driver/parser.cpp"
    break;

  case 13:
#line 121 "../../src/driver/parser.y"
                            {
    DeclNode* tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-2]);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->AddDecl();
    yyval = yyvsp[-2];   
  }
#line 1655 "../../src/driver/parser.cpp"
    break;

  case 14:
#line 130 "../../src/driver/parser.y"
                                               {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent();
    declnode_tmp_init_val = yyvsp[0];
    yyval = nullptr;
  }
#line 1665 "../../src/driver/parser.cpp"
    break;

  case 15:
#line 138 "../../src/driver/parser.y"
              {
    declnode_tmp_array_dimension_array.resize(0);
    yyval = nullptr;
  }
#line 1674 "../../src/driver/parser.cpp"
    break;

  case 16:
#line 142 "../../src/driver/parser.y"
                                         {
    declnode_tmp_array_dimension_array.push_back(yyvsp[-1]);
    yyval = yyvsp[-3];
  }
#line 1683 "../../src/driver/parser.cpp"
    break;

  case 17:
#line 149 "../../src/driver/parser.y"
           {
    yyval = yyvsp[0];
  }
#line 1691 "../../src/driver/parser.cpp"
    break;

  case 18:
#line 152 "../../src/driver/parser.y"
                           {
    yyval = yyvsp[-1];
  }
#line 1699 "../../src/driver/parser.cpp"
    break;

  case 19:
#line 155 "../../src/driver/parser.y"
          {
    yyval = new InitValNode(yylineno);
  }
#line 1707 "../../src/driver/parser.cpp"
    break;

  case 20:
#line 161 "../../src/driver/parser.y"
                                    {
    dynamic_cast<InitValNode*>(yyvsp[-2])->AddInitVal(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 1716 "../../src/driver/parser.cpp"
    break;

  case 21:
#line 165 "../../src/driver/parser.y"
               {
    InitValNode *new_init_val_node = new InitValNode(yylineno);
    new_init_val_node->AddInitVal(yyvsp[0]);
    yyval = new_init_val_node;
  }
#line 1726 "../../src/driver/parser.cpp"
    break;

  case 22:
#line 173 "../../src/driver/parser.y"
                       {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]); 
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    yyval = yyvsp[-1];
  }
#line 1737 "../../src/driver/parser.cpp"
    break;

  case 23:
#line 179 "../../src/driver/parser.y"
                         {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]);
    assert(tmp_decl_node != nullptr);
    std::stringstream msg;
    msg << "[ERROR] Declaration to value(s) at line " << dynamic_cast<Node*>(yyvsp[-1])->line_no << " is omitted due to unknown type \"" << dynamic_cast<IdentNode*>(yyvsp[-2])->GetIdent() << "\".";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>(yyvsp[-1])->line_no);
    yyval = new_node;
    delete tmp_decl_node;
    printf("%s\n",msg.str().c_str());
  }
#line 1752 "../../src/driver/parser.cpp"
    break;

  case 24:
#line 189 "../../src/driver/parser.y"
                  {
    std::stringstream msg;
    msg << "[ERROR] Declaration to value(s) at line " << yylineno << " is omitted due to error(s) in the list of declaration.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    yyval = new_node;
    printf("%s\n",msg.str().c_str());
  }
#line 1764 "../../src/driver/parser.cpp"
    break;

  case 25:
#line 196 "../../src/driver/parser.y"
                  {
    std::stringstream msg;
    msg << "[ERROR] Declaration to value(s) at line " << dynamic_cast<Node*>(yyvsp[-2])->line_no << " is omitted due to error(s) in the list of declaration and data type.";
    ErrorNode* new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>(yyvsp[-2])->line_no);
    yyval = new_node;
    printf("%s\n",msg.str().c_str());
  }
#line 1776 "../../src/driver/parser.cpp"
    break;

  case 26:
#line 206 "../../src/driver/parser.y"
         {
    DeclNode* new_decl_node = new DeclNode(NodeType::VAR_DECL,yylineno);
    new_decl_node->AddDecl();
    yyval = new_decl_node;
  }
#line 1786 "../../src/driver/parser.cpp"
    break;

  case 27:
#line 211 "../../src/driver/parser.y"
                         {
    dynamic_cast<DeclNode*>(yyvsp[-2])->AddDecl();
    yyval = yyvsp[-2];
  }
#line 1795 "../../src/driver/parser.cpp"
    break;

  case 28:
#line 218 "../../src/driver/parser.y"
                                           {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent();
    declnode_tmp_init_val = yyvsp[0];
    yyval = nullptr; 
  }
#line 1805 "../../src/driver/parser.cpp"
    break;

  case 29:
#line 226 "../../src/driver/parser.y"
              {
    declnode_tmp_array_dimension_array.resize(0);
    yyval = nullptr;
  }
#line 1814 "../../src/driver/parser.cpp"
    break;

  case 30:
#line 230 "../../src/driver/parser.y"
                                     {
    declnode_tmp_array_dimension_array.push_back(yyvsp[-1]);
    yyval = yyvsp[-3];
  }
#line 1823 "../../src/driver/parser.cpp"
    break;

  case 31:
#line 237 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1831 "../../src/driver/parser.cpp"
    break;

  case 32:
#line 240 "../../src/driver/parser.y"
                         {
    yyval = yyvsp[-1];
  }
#line 1839 "../../src/driver/parser.cpp"
    break;

  case 33:
#line 243 "../../src/driver/parser.y"
          {
    yyval = new InitValNode(yylineno);
  }
#line 1847 "../../src/driver/parser.cpp"
    break;

  case 34:
#line 249 "../../src/driver/parser.y"
                                {
    dynamic_cast<InitValNode*>(yyvsp[-2])->AddInitVal(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 1856 "../../src/driver/parser.cpp"
    break;

  case 35:
#line 253 "../../src/driver/parser.y"
             {
    InitValNode *new_init_val_node = new InitValNode(yylineno);
    new_init_val_node->AddInitVal(yyvsp[0]);
    yyval = new_init_val_node;
  }
#line 1866 "../../src/driver/parser.cpp"
    break;

  case 36:
#line 261 "../../src/driver/parser.y"
                            {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-1])->GetIdent();
    declnode_tmp_init_val = nullptr;
    yyval = nullptr;
  }
#line 1876 "../../src/driver/parser.cpp"
    break;

  case 37:
#line 269 "../../src/driver/parser.y"
      {
    declnode_tmp_basic_type = BasicType::INT;
    funcdefnode_tmp_fparam_basic_type = BasicType::INT;
    yyval = nullptr;
  }
#line 1886 "../../src/driver/parser.cpp"
    break;

  case 38:
#line 274 "../../src/driver/parser.y"
        {
    declnode_tmp_basic_type = BasicType::FLOAT;
    funcdefnode_tmp_fparam_basic_type = BasicType::FLOAT;
    yyval = nullptr;
  }
#line 1896 "../../src/driver/parser.cpp"
    break;

  case 39:
#line 279 "../../src/driver/parser.y"
       {
    declnode_tmp_basic_type = BasicType::CHAR;
    funcdefnode_tmp_fparam_basic_type = BasicType::CHAR;
    yyval = nullptr;
  }
#line 1906 "../../src/driver/parser.cpp"
    break;

  case 40:
#line 287 "../../src/driver/parser.y"
                        {
    yyval = yyvsp[-1];
  }
#line 1914 "../../src/driver/parser.cpp"
    break;

  case 41:
#line 290 "../../src/driver/parser.y"
        {
    std::stringstream msg;
    msg << "[ERROR] Block or unknown in-block error found at line " << yylineno << ".";
    yyval = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
  }
#line 1925 "../../src/driver/parser.cpp"
    break;

  case 42:
#line 299 "../../src/driver/parser.y"
              {
    yyval = new BlockNode(yylineno);
    assert(yyval != nullptr);
  }
#line 1934 "../../src/driver/parser.cpp"
    break;

  case 43:
#line 303 "../../src/driver/parser.y"
                          {
    BlockNode *tmp_block_node = dynamic_cast<BlockNode*>(yyvsp[-1]); 
    assert(tmp_block_node != nullptr);
    if(yyvsp[0]->CheckNodeType(NodeType::ERROR)){
      tmp_block_node->AddError(dynamic_cast<ErrorNode*>(yyvsp[0]));
      tmp_block_node->AddNode(yyvsp[0]);
    } else {
      tmp_block_node->AddNode(yyvsp[0]);
    }
    yyval = yyvsp[-1];
  }
#line 1950 "../../src/driver/parser.cpp"
    break;

  case 44:
#line 317 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 1958 "../../src/driver/parser.cpp"
    break;

  case 45:
#line 320 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 1966 "../../src/driver/parser.cpp"
    break;

  case 46:
#line 326 "../../src/driver/parser.y"
                       {
    yyval = new ReturnStmtNode(yyvsp[-1],yylineno);
  }
#line 1974 "../../src/driver/parser.cpp"
    break;

  case 47:
#line 329 "../../src/driver/parser.y"
               {
    yyval = new ContinueStmtNode(yylineno);  
  }
#line 1982 "../../src/driver/parser.cpp"
    break;

  case 48:
#line 332 "../../src/driver/parser.y"
            {
    yyval = new BreakStmtNode(yylineno);
  }
#line 1990 "../../src/driver/parser.cpp"
    break;

  case 49:
#line 335 "../../src/driver/parser.y"
                          {
    yyval = new WhileStmtNode(yyvsp[-2], yyvsp[0],yyvsp[-2]->line_no);
  }
#line 1998 "../../src/driver/parser.cpp"
    break;

  case 50:
#line 338 "../../src/driver/parser.y"
                                  {
    yyval = new IfStmtNode(yyvsp[-3], yyvsp[-1], yyvsp[0],yyvsp[-3]->line_no);
  }
#line 2006 "../../src/driver/parser.cpp"
    break;

  case 51:
#line 341 "../../src/driver/parser.y"
        {
    yyval = yyvsp[0];
  }
#line 2014 "../../src/driver/parser.cpp"
    break;

  case 52:
#line 344 "../../src/driver/parser.y"
                {
    yyval = yyvsp[-1];
  }
#line 2022 "../../src/driver/parser.cpp"
    break;

  case 53:
#line 347 "../../src/driver/parser.y"
                   {
    yyval = new AssignStmtNode(yyvsp[-3], yyvsp[-1],yylineno);
  }
#line 2030 "../../src/driver/parser.cpp"
    break;

  case 54:
#line 350 "../../src/driver/parser.y"
                   {
    std::stringstream msg;
    int start_line_no = 0;
    if(yyvsp[0]==nullptr){
      start_line_no = yylineno;
    } else {
      start_line_no = yyvsp[0]->line_no;
    }
    msg << "[ERROR] While block at line " << start_line_no << " to " << yylineno << " is omitted due to error(s) found in its condition statement.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    assert(new_node!=nullptr);
    printf("%s\n",msg.str().c_str());
    yyval = new_node;
    yyerrok;
  }
#line 2050 "../../src/driver/parser.cpp"
    break;

  case 55:
#line 365 "../../src/driver/parser.y"
                           {
    std::stringstream msg;
    int start_line_no = 0;
    if(yyvsp[-1]==nullptr){
      start_line_no = yylineno;
    } else {
      start_line_no = yyvsp[-1]->line_no;
    }
    msg << "[ERROR] If block at line " << start_line_no << " to " << yylineno << " is omitted due to error(s) found in its condition statement.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    assert(new_node!=nullptr);
    printf("%s\n",msg.str().c_str());
    yyval = new_node;
    yyerrok;
  }
#line 2070 "../../src/driver/parser.cpp"
    break;

  case 56:
#line 380 "../../src/driver/parser.y"
            {
    std::stringstream msg;
    msg << "[ERROR] Statement at line " << yylineno << " is omitted due to error(s) found in it.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
    yyval = new_node;
    yyerrok;
  }
#line 2083 "../../src/driver/parser.cpp"
    break;

  case 57:
#line 391 "../../src/driver/parser.y"
              {
    yyval = nullptr;
  }
#line 2091 "../../src/driver/parser.cpp"
    break;

  case 58:
#line 394 "../../src/driver/parser.y"
      {
    yyval = yyvsp[0];
  }
#line 2099 "../../src/driver/parser.cpp"
    break;

  case 59:
#line 400 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2107 "../../src/driver/parser.cpp"
    break;

  case 60:
#line 406 "../../src/driver/parser.y"
              {
    yyval = nullptr;
  }
#line 2115 "../../src/driver/parser.cpp"
    break;

  case 61:
#line 409 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 2123 "../../src/driver/parser.cpp"
    break;

  case 62:
#line 415 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2131 "../../src/driver/parser.cpp"
    break;

  case 63:
#line 421 "../../src/driver/parser.y"
                  {
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode(dynamic_cast<IdentNode*>(yyvsp[-1]),yylineno);
    tmp_node->AddLVal();
    yyval = tmp_node;
  }
#line 2141 "../../src/driver/parser.cpp"
    break;

  case 64:
#line 426 "../../src/driver/parser.y"
        {
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode(dynamic_cast<IdentNode*>(yyvsp[0]),yylineno);
    yyval = tmp_node;    
  }
#line 2150 "../../src/driver/parser.cpp"
    break;

  case 65:
#line 433 "../../src/driver/parser.y"
              {
    lvalprimaryexpnode_tmp_index_array.resize(0);
    lvalprimaryexpnode_tmp_index_array.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 2160 "../../src/driver/parser.cpp"
    break;

  case 66:
#line 438 "../../src/driver/parser.y"
                        {
    //printf("1\n");
    lvalprimaryexpnode_tmp_index_array.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 2170 "../../src/driver/parser.cpp"
    break;

  case 67:
#line 446 "../../src/driver/parser.y"
                 {
    yyval = yyvsp[-1];
  }
#line 2178 "../../src/driver/parser.cpp"
    break;

  case 68:
#line 449 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 2186 "../../src/driver/parser.cpp"
    break;

  case 69:
#line 452 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 2194 "../../src/driver/parser.cpp"
    break;

  case 70:
#line 455 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 2202 "../../src/driver/parser.cpp"
    break;

  case 71:
#line 458 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 2210 "../../src/driver/parser.cpp"
    break;

  case 72:
#line 461 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2218 "../../src/driver/parser.cpp"
    break;

  case 73:
#line 467 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 2226 "../../src/driver/parser.cpp"
    break;

  case 74:
#line 473 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 2234 "../../src/driver/parser.cpp"
    break;

  case 75:
#line 479 "../../src/driver/parser.y"
             {
    yyval = yyvsp[0];
  }
#line 2242 "../../src/driver/parser.cpp"
    break;

  case 76:
#line 485 "../../src/driver/parser.y"
               {
    yyval = yyvsp[0];
  }
#line 2250 "../../src/driver/parser.cpp"
    break;

  case 77:
#line 491 "../../src/driver/parser.y"
             {
    yyval = yyvsp[0];
  }
#line 2258 "../../src/driver/parser.cpp"
    break;

  case 78:
#line 494 "../../src/driver/parser.y"
                               {
    dynamic_cast<FuncCallExpNode*>(yyvsp[-1])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-3]));
    yyval = yyvsp[-1];
  }
#line 2267 "../../src/driver/parser.cpp"
    break;

  case 79:
#line 498 "../../src/driver/parser.y"
                {
    FuncCallExpNode* new_node = new FuncCallExpNode(yylineno);
    new_node->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-2]));
    yyval = new_node;
  }
#line 2277 "../../src/driver/parser.cpp"
    break;

  case 80:
#line 503 "../../src/driver/parser.y"
                   {
    dynamic_cast<UnaryExpNode*>(yyvsp[-1])->SetExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2286 "../../src/driver/parser.cpp"
    break;

  case 81:
#line 510 "../../src/driver/parser.y"
      {
    FuncCallExpNode *new_node = new FuncCallExpNode(yylineno);
    new_node->AddParam(yyvsp[0]);
    yyval = new_node;
  }
#line 2296 "../../src/driver/parser.cpp"
    break;

  case 82:
#line 515 "../../src/driver/parser.y"
                         {
    assert(yyvsp[-2]!=nullptr);
    dynamic_cast<FuncCallExpNode*>(yyvsp[-2])->AddParam(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 2306 "../../src/driver/parser.cpp"
    break;

  case 83:
#line 523 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::POSITIVE,yylineno);
    yyval = new_node;
  }
#line 2315 "../../src/driver/parser.cpp"
    break;

  case 84:
#line 527 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NEGATIVE,yylineno);
    yyval = new_node;
  }
#line 2324 "../../src/driver/parser.cpp"
    break;

  case 85:
#line 531 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NOT,yylineno);
    yyval = new_node;
  }
#line 2333 "../../src/driver/parser.cpp"
    break;

  case 86:
#line 535 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::GETPTR,yylineno);
    yyval = new_node;
  }
#line 2342 "../../src/driver/parser.cpp"
    break;

  case 87:
#line 542 "../../src/driver/parser.y"
           {
    yyval = yyvsp[0];
  }
#line 2350 "../../src/driver/parser.cpp"
    break;

  case 88:
#line 545 "../../src/driver/parser.y"
                        {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2360 "../../src/driver/parser.cpp"
    break;

  case 89:
#line 553 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MUL,yylineno);
    yyval = new_node;
  }
#line 2369 "../../src/driver/parser.cpp"
    break;

  case 90:
#line 557 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::DIV,yylineno);
    yyval = new_node;
  }
#line 2378 "../../src/driver/parser.cpp"
    break;

  case 91:
#line 561 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MOD,yylineno);
    yyval = new_node;
  }
#line 2387 "../../src/driver/parser.cpp"
    break;

  case 92:
#line 568 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2395 "../../src/driver/parser.cpp"
    break;

  case 93:
#line 571 "../../src/driver/parser.y"
                      {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1]; 
  }
#line 2405 "../../src/driver/parser.cpp"
    break;

  case 94:
#line 579 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::ADD,yylineno);
    yyval = new_node;
  }
#line 2414 "../../src/driver/parser.cpp"
    break;

  case 95:
#line 583 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::SUB,yylineno);
    yyval = new_node;
  }
#line 2423 "../../src/driver/parser.cpp"
    break;

  case 96:
#line 590 "../../src/driver/parser.y"
                      {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2433 "../../src/driver/parser.cpp"
    break;

  case 97:
#line 595 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0]; 
  }
#line 2441 "../../src/driver/parser.cpp"
    break;

  case 98:
#line 601 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LE,yylineno);
    yyval = new_node; 
  }
#line 2450 "../../src/driver/parser.cpp"
    break;

  case 99:
#line 605 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GE,yylineno);
    yyval = new_node; 
  }
#line 2459 "../../src/driver/parser.cpp"
    break;

  case 100:
#line 609 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LEEQ,yylineno);
    yyval = new_node; 
  }
#line 2468 "../../src/driver/parser.cpp"
    break;

  case 101:
#line 613 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GEEQ,yylineno);
    yyval = new_node; 
  }
#line 2477 "../../src/driver/parser.cpp"
    break;

  case 102:
#line 620 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2485 "../../src/driver/parser.cpp"
    break;

  case 103:
#line 623 "../../src/driver/parser.y"
                    {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2495 "../../src/driver/parser.cpp"
    break;

  case 104:
#line 631 "../../src/driver/parser.y"
     {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::EQ,yylineno);
    yyval = new_node;
  }
#line 2504 "../../src/driver/parser.cpp"
    break;

  case 105:
#line 635 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::UNEQ,yylineno);
    yyval = new_node;
  }
#line 2513 "../../src/driver/parser.cpp"
    break;

  case 106:
#line 642 "../../src/driver/parser.y"
        {
    yyval = yyvsp[0];
  }
#line 2521 "../../src/driver/parser.cpp"
    break;

  case 107:
#line 645 "../../src/driver/parser.y"
                       {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2531 "../../src/driver/parser.cpp"
    break;

  case 108:
#line 653 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::AND,yylineno);
    yyval = new_node;
  }
#line 2540 "../../src/driver/parser.cpp"
    break;

  case 109:
#line 660 "../../src/driver/parser.y"
          {
    yyval = yyvsp[0];
  }
#line 2548 "../../src/driver/parser.cpp"
    break;

  case 110:
#line 663 "../../src/driver/parser.y"
                       {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2558 "../../src/driver/parser.cpp"
    break;

  case 111:
#line 671 "../../src/driver/parser.y"
     {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::OR,yylineno);
    yyval = new_node;
  }
#line 2567 "../../src/driver/parser.cpp"
    break;

  case 112:
#line 678 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2575 "../../src/driver/parser.cpp"
    break;

  case 113:
#line 684 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2583 "../../src/driver/parser.cpp"
    break;

  case 114:
#line 690 "../../src/driver/parser.y"
                                                  {
    dynamic_cast<FuncDefNode*>(yyvsp[-5])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-4]));
    dynamic_cast<FuncDefNode*>(yyvsp[-5])->SetBlock(yyvsp[0]);
    yyval = funcdefnode_tmp_func_def_node;
    assert(yyval!=nullptr);
    bool func_type_error = (dynamic_cast<FuncDefNode*>(yyvsp[-5])->GetType() == BasicType::UNKNOWN);
    bool func_param_list_error = dynamic_cast<Node*>(yyval)->error_list_.size()>(func_type_error?1:0);
    if(func_type_error or func_param_list_error){
      std::stringstream msg;
      msg << "[ERROR] Function \"" << dynamic_cast<IdentNode*>(yyvsp[-4])->GetIdent() << "\" at line " << dynamic_cast<Node*>(yyvsp[-4])->line_no << " is omitted due to following error(s) in its declaration:\n";
      if(func_type_error){
        assert(yyval->error_list_.size()>0);
        msg << "  " << "Unknown return type \"" << dynamic_cast<ErrorNode*>(yyval->error_list_[0])->err_msg << "\".\n";
        yyval->error_list_.erase(yyval->error_list_.begin());
      }
      if(func_param_list_error){
        for (auto iter: dynamic_cast<Node*>(yyval)->error_list_){
          msg << "  " << dynamic_cast<ErrorNode*>(&(*iter)) -> err_msg << ".\n";
        }
      }
      ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>(yyvsp[-4])->line_no);
      printf("%s",msg.str().c_str());
      delete yyval;
      yyval = new_node;
    }
    yyerrok;
  }
#line 2615 "../../src/driver/parser.cpp"
    break;

  case 115:
#line 717 "../../src/driver/parser.y"
                                   {
    dynamic_cast<FuncDefNode*>(yyvsp[-4])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-3]));
    dynamic_cast<FuncDefNode*>(yyvsp[-4])->SetBlock(yyvsp[0]);
    yyval = funcdefnode_tmp_func_def_node;
    assert(yyval!=nullptr);
    bool func_type_error = (dynamic_cast<FuncDefNode*>(yyvsp[-4])->GetType() == BasicType::UNKNOWN);
    if(func_type_error){
      std::stringstream msg;
      msg << "[ERROR] Function \"" << dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent() << "\" at line " << dynamic_cast<Node*>(yyvsp[-3])->line_no << " is omitted due to following error(s) in its declaration:\n";
      assert(yyval->error_list_.size()>0);
      msg << "  " << "Unknown return type \"" << dynamic_cast<ErrorNode*>(yyval->error_list_[0])->err_msg << "\".\n";
      yyval->error_list_.erase(yyval->error_list_.begin());
      ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<Node*>(yyvsp[-3])->line_no);
      printf("%s",msg.str().c_str());
      delete yyval;
      yyval = new_node;
    }
    yyerrok;
  }
#line 2639 "../../src/driver/parser.cpp"
    break;

  case 116:
#line 736 "../../src/driver/parser.y"
                                                    {
    if(funcdefnode_tmp_func_def_node!=nullptr){
      delete funcdefnode_tmp_func_def_node;
    }
    std::stringstream msg;
    msg << "[ERROR] An unit seems to be a declaration of a function at line " << yylineno << " is omitted.";
    ErrorNode *new_node = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
    yyval = new_node;
    yyerrok;
  }
#line 2655 "../../src/driver/parser.cpp"
    break;

  case 117:
#line 747 "../../src/driver/parser.y"
                                     {
    if(funcdefnode_tmp_func_def_node!=nullptr){
      delete funcdefnode_tmp_func_def_node;
    }
    std::stringstream msg;
    msg << "[ERROR] An unit seems to be a declaration of a function at line " << yylineno << " is omitted.";
    ErrorNode *new_node = new ErrorNode(msg.str(),yylineno);
    printf("%s\n",msg.str().c_str());
    yyval = new_node;
    yyerrok;
  }
#line 2671 "../../src/driver/parser.cpp"
    break;

  case 118:
#line 758 "../../src/driver/parser.y"
                                 {
    std::stringstream msg;
    msg << "[ERROR] Function \"" << dynamic_cast<IdentNode*>(yyvsp[-2])->GetIdent() << "\" at line " << yyvsp[-3]->line_no << " is omitted due to error(s) found in its param list.";
    ErrorNode* new_node = new ErrorNode(msg.str(),yyvsp[-3]->line_no);
    yyval = new_node;
    printf("%s\n",msg.str().c_str());
  }
#line 2683 "../../src/driver/parser.cpp"
    break;

  case 119:
#line 768 "../../src/driver/parser.y"
             {
    assert(yyvsp[0]!=nullptr);
    if(dynamic_cast<Node*>(yyvsp[0])->CheckNodeType(NodeType::IDENT)){
      assert(funcdefnode_tmp_func_def_node!=nullptr);
      funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>(yyvsp[0]));
    }
    else if(dynamic_cast<Node*>(yyvsp[0])->CheckNodeType(NodeType::ERROR)){
      dynamic_cast<Node*>(funcdefnode_tmp_func_def_node)->AddError(dynamic_cast<Node*>(yyvsp[0]));
    }
    yyval = nullptr;
  }
#line 2699 "../../src/driver/parser.cpp"
    break;

  case 120:
#line 779 "../../src/driver/parser.y"
                                {
    assert(yyvsp[0]!=nullptr);
    if(dynamic_cast<Node*>(yyvsp[0])->CheckNodeType(NodeType::IDENT)){
      assert(funcdefnode_tmp_func_def_node!=nullptr);
      funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>(yyvsp[0]));
    }
    else if(dynamic_cast<Node*>(yyvsp[0])->CheckNodeType(NodeType::ERROR)){
      dynamic_cast<Node*>(funcdefnode_tmp_func_def_node)->AddError(dynamic_cast<Node*>(yyvsp[0]));
    }
    yyval = nullptr;
  }
#line 2715 "../../src/driver/parser.cpp"
    break;

  case 121:
#line 793 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 2723 "../../src/driver/parser.cpp"
    break;

  case 122:
#line 796 "../../src/driver/parser.y"
                                          {
    yyval = yyvsp[-3];
  }
#line 2731 "../../src/driver/parser.cpp"
    break;

  case 123:
#line 799 "../../src/driver/parser.y"
              {
    assert(yyvsp[-1]!=nullptr);
    std::stringstream msg;
    msg << "Unknown data type \"" << dynamic_cast<IdentNode*>(yyvsp[-1])->GetIdent() << "\" for param \"" << dynamic_cast<IdentNode*>(yyvsp[0])->GetIdent() << "\"";
    ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<IdentNode*>(yyvsp[0])->line_no);
        assert(new_node!=nullptr);
    yyval = new_node;
  }
#line 2744 "../../src/driver/parser.cpp"
    break;

  case 124:
#line 807 "../../src/driver/parser.y"
                                          {
    assert(yyvsp[-4]!=nullptr);
    std::stringstream msg;
    msg << "Unknown data type \"" << dynamic_cast<IdentNode*>(yyvsp[-4])->GetIdent() << "[]\" for param \"" << dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent() << "\"";
    ErrorNode *new_node = new ErrorNode(msg.str(),dynamic_cast<IdentNode*>(yyvsp[-3])->line_no);
    assert(new_node!=nullptr);
    yyval = new_node;
  }
#line 2757 "../../src/driver/parser.cpp"
    break;

  case 125:
#line 818 "../../src/driver/parser.y"
              {
    funcdefnode_tmp_fparam_index_list.resize(0);
    funcdefnode_tmp_fparam_index_list.push_back(nullptr);
    yyval = nullptr;
  }
#line 2767 "../../src/driver/parser.cpp"
    break;

  case 126:
#line 823 "../../src/driver/parser.y"
                                  {
    funcdefnode_tmp_fparam_index_list.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 2776 "../../src/driver/parser.cpp"
    break;

  case 127:
#line 830 "../../src/driver/parser.y"
       {
    FuncDefNode *new_node = new FuncDefNode(BasicType::VOID,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2786 "../../src/driver/parser.cpp"
    break;

  case 128:
#line 835 "../../src/driver/parser.y"
      {
    FuncDefNode *new_node = new FuncDefNode(BasicType::INT,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2796 "../../src/driver/parser.cpp"
    break;

  case 129:
#line 840 "../../src/driver/parser.y"
        {
    FuncDefNode *new_node = new FuncDefNode(BasicType::FLOAT,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2806 "../../src/driver/parser.cpp"
    break;

  case 130:
#line 845 "../../src/driver/parser.y"
       {
    FuncDefNode *new_node = new FuncDefNode(BasicType::CHAR,yylineno);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2816 "../../src/driver/parser.cpp"
    break;

  case 131:
#line 850 "../../src/driver/parser.y"
        {
    FuncDefNode *new_node = new FuncDefNode(BasicType::UNKNOWN,yylineno);
    ErrorNode* error_info = new ErrorNode(dynamic_cast<IdentNode*>(yyvsp[0])->GetIdent(),yylineno);
    new_node -> AddError(error_info);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2828 "../../src/driver/parser.cpp"
    break;


#line 2832 "../../src/driver/parser.cpp"

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
#line 859 "../../src/driver/parser.y"
