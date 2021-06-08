/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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

#line 94 "../../src/driver/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_DEF = 14,                       /* DEF  */
  YYSYMBOL_IDENT = 15,                     /* IDENT  */
  YYSYMBOL_INT_CONST = 16,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 17,               /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 18,                /* CHAR_CONST  */
  YYSYMBOL_STRING_CONST = 19,              /* STRING_CONST  */
  YYSYMBOL_LEEQ = 20,                      /* LEEQ  */
  YYSYMBOL_GEEQ = 21,                      /* GEEQ  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_UNEQ = 23,                      /* UNEQ  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_ERROR = 26,                     /* ERROR  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '['  */
  YYSYMBOL_31_ = 31,                       /* ']'  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '!'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '%'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_CompUnit = 45,                  /* CompUnit  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_ConstDecl = 47,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 48,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 49,                  /* ConstDef  */
  YYSYMBOL_ConstDefDimensionList = 50,     /* ConstDefDimensionList  */
  YYSYMBOL_ConstInitVal = 51,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 52,          /* ConstInitValList  */
  YYSYMBOL_VarDecl = 53,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 54,                /* VarDefList  */
  YYSYMBOL_VarDef = 55,                    /* VarDef  */
  YYSYMBOL_VarDefDimensionList = 56,       /* VarDefDimensionList  */
  YYSYMBOL_VarInitVal = 57,                /* VarInitVal  */
  YYSYMBOL_VarInitValList = 58,            /* VarInitValList  */
  YYSYMBOL_BType = 59,                     /* BType  */
  YYSYMBOL_Block = 60,                     /* Block  */
  YYSYMBOL_BlockItemList = 61,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 62,                 /* BlockItem  */
  YYSYMBOL_Stmt = 63,                      /* Stmt  */
  YYSYMBOL_ExpChoice = 64,                 /* ExpChoice  */
  YYSYMBOL_Cond = 65,                      /* Cond  */
  YYSYMBOL_ElseChoice = 66,                /* ElseChoice  */
  YYSYMBOL_Exp = 67,                       /* Exp  */
  YYSYMBOL_LVal = 68,                      /* LVal  */
  YYSYMBOL_IndexList = 69,                 /* IndexList  */
  YYSYMBOL_PrimaryExp = 70,                /* PrimaryExp  */
  YYSYMBOL_IntNumber = 71,                 /* IntNumber  */
  YYSYMBOL_FloatNumber = 72,               /* FloatNumber  */
  YYSYMBOL_character = 73,                 /* character  */
  YYSYMBOL_String = 74,                    /* String  */
  YYSYMBOL_UnaryExp = 75,                  /* UnaryExp  */
  YYSYMBOL_FuncRParamList = 76,            /* FuncRParamList  */
  YYSYMBOL_UnaryOp = 77,                   /* UnaryOp  */
  YYSYMBOL_MulExp = 78,                    /* MulExp  */
  YYSYMBOL_MulOp = 79,                     /* MulOp  */
  YYSYMBOL_AddExp = 80,                    /* AddExp  */
  YYSYMBOL_AddOp = 81,                     /* AddOp  */
  YYSYMBOL_RelExp = 82,                    /* RelExp  */
  YYSYMBOL_RelOp = 83,                     /* RelOp  */
  YYSYMBOL_EqExp = 84,                     /* EqExp  */
  YYSYMBOL_EqOp = 85,                      /* EqOp  */
  YYSYMBOL_LAndExp = 86,                   /* LAndExp  */
  YYSYMBOL_LAndOp = 87,                    /* LAndOp  */
  YYSYMBOL_LOrExp = 88,                    /* LOrExp  */
  YYSYMBOL_LOrOp = 89,                     /* LOrOp  */
  YYSYMBOL_ConstExp = 90,                  /* ConstExp  */
  YYSYMBOL_VarExp = 91,                    /* VarExp  */
  YYSYMBOL_FuncDef = 92,                   /* FuncDef  */
  YYSYMBOL_FuncFParamList = 93,            /* FuncFParamList  */
  YYSYMBOL_FuncFParam = 94,                /* FuncFParam  */
  YYSYMBOL_FuncFParamIndexList = 95,       /* FuncFParamIndexList  */
  YYSYMBOL_FuncType = 96                   /* FuncType  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   228

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,    41,     2,     2,
      34,    35,    39,    36,    28,    37,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      42,    29,    43,     2,     2,     2,     2,     2,     2,     2,
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
     304,   307,   313,   319,   327,   331,   338,   341,   344,   347,
     350,   353,   359,   365,   371,   377,   383,   386,   390,   395,
     402,   406,   413,   417,   421,   428,   431,   439,   443,   447,
     454,   457,   465,   469,   476,   481,   487,   491,   495,   499,
     506,   509,   517,   521,   528,   531,   539,   546,   549,   557,
     564,   570,   576,   581,   589,   593,   600,   603,   609,   614,
     621,   626,   631,   636
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "INT",
  "FLOAT", "CHAR", "VOID", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE",
  "RETURN", "DEF", "IDENT", "INT_CONST", "FLOAT_CONST", "CHAR_CONST",
  "STRING_CONST", "LEEQ", "GEEQ", "EQ", "UNEQ", "AND", "OR", "ERROR",
  "';'", "','", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'+'",
  "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "$accept", "CompUnit",
  "Decl", "ConstDecl", "ConstDefList", "ConstDef", "ConstDefDimensionList",
  "ConstInitVal", "ConstInitValList", "VarDecl", "VarDefList", "VarDef",
  "VarDefDimensionList", "VarInitVal", "VarInitValList", "BType", "Block",
  "BlockItemList", "BlockItem", "Stmt", "ExpChoice", "Cond", "ElseChoice",
  "Exp", "LVal", "IndexList", "PrimaryExp", "IntNumber", "FloatNumber",
  "character", "String", "UnaryExp", "FuncRParamList", "UnaryOp", "MulExp",
  "MulOp", "AddExp", "AddOp", "RelExp", "RelOp", "EqExp", "EqOp",
  "LAndExp", "LAndOp", "LOrExp", "LOrOp", "ConstExp", "VarExp", "FuncDef",
  "FuncFParamList", "FuncFParam", "FuncFParamIndexList", "FuncType", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    59,    44,    61,
      91,    93,   123,   125,    40,    41,    43,    45,    33,    42,
      47,    37,    60,    62
};
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,   120,  -117,  -117,  -117,   151,    58,  -117,  -117,  -117,
      32,  -117,    39,  -117,  -117,  -117,  -117,    50,  -117,  -117,
    -117,  -117,   -10,  -117,  -117,    10,  -117,   -13,    61,  -117,
      32,    66,  -117,    39,     7,   135,   169,  -117,   159,   169,
    -117,    35,    68,    -9,  -117,    54,  -117,  -117,  -117,  -117,
     104,   169,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,   169,   170,    79,  -117,    62,   128,  -117,
      79,  -117,    71,  -117,  -117,    74,   120,    35,   164,   100,
    -117,  -117,    27,    79,    14,   112,    85,    16,  -117,  -117,
    -117,  -117,   169,  -117,  -117,   169,  -117,  -117,  -117,    38,
    -117,    95,   108,  -117,  -117,  -117,  -117,     4,    79,   169,
     135,  -117,  -117,  -117,  -117,  -117,   169,  -117,  -117,   169,
    -117,   169,  -117,  -117,   169,  -117,   170,   159,  -117,   114,
     115,   132,   136,   169,  -117,  -117,  -117,  -117,  -117,   141,
    -117,   160,  -117,   169,  -117,   139,  -117,    79,    14,   112,
      85,  -117,   169,   169,  -117,  -117,   163,  -117,   169,   162,
    -117,  -117,   173,   179,   177,  -117,   167,   169,    12,    12,
    -117,   182,   205,  -117,  -117,    12,  -117,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    31,    32,    33,     0,     0,     4,     6,     7,
       0,     5,     0,   111,   112,   113,   110,     0,     1,     2,
       3,    23,     0,    20,    12,     0,     9,     0,    30,    19,
       0,     0,     8,     0,     0,     0,     0,    21,     0,     0,
      10,     0,     0,     0,   104,    54,    62,    63,    64,    65,
       0,     0,    72,    73,    74,    22,    57,    66,    58,    59,
      60,    61,    75,     0,    80,   101,    25,     0,     0,    11,
     100,    14,     0,    35,   103,   106,     0,     0,     0,    53,
      27,    29,     0,    85,    90,    94,    97,     0,    69,    77,
      78,    79,     0,    82,    83,     0,    24,    16,    18,     0,
      13,    47,     0,   105,   102,    68,    70,     0,    52,     0,
       0,    26,    88,    89,    86,    87,     0,    92,    93,     0,
      96,     0,    99,    56,     0,    76,    81,     0,    15,     0,
       0,     0,     0,    47,    34,    37,    44,    36,    38,     0,
      48,    57,   108,     0,    67,     0,    28,    84,    91,    95,
      98,    17,     0,     0,    41,    40,     0,    45,     0,   107,
      71,    55,     0,    49,     0,    39,     0,     0,    47,    47,
      46,     0,    50,    42,   109,    47,    43,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,    -4,  -117,  -117,   183,  -117,   -58,  -117,  -117,
    -117,   185,  -117,   -42,  -117,     6,   -32,  -117,  -117,  -116,
      84,    65,  -117,   -73,   -95,  -117,  -117,  -117,  -117,  -117,
    -117,   -49,  -117,  -117,   124,  -117,   -35,  -117,   101,  -117,
     102,  -117,    97,  -117,   171,  -117,   186,   188,   220,  -117,
     152,  -117,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,    25,    26,    31,    69,    99,     9,
      22,    23,    28,    55,    82,    10,   136,   101,   137,   138,
     139,   162,   176,   140,    56,    79,    57,    58,    59,    60,
      61,    62,   107,    63,    64,    92,   108,    95,    84,   116,
      85,   119,    86,   121,   163,   124,    71,    66,    11,    43,
      44,   159,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,    65,    19,    70,    70,   106,   141,    12,    81,    74,
      98,     2,     3,     4,    88,    65,    83,    29,    30,    76,
     129,    34,   130,   131,   132,   133,    77,    45,    46,    47,
      48,    49,   143,    70,   112,   113,   145,    32,    33,   144,
      42,   122,    41,   125,    73,   104,    51,    21,    52,    53,
      54,   123,   172,   173,    24,   110,   114,   115,    18,   177,
     111,     1,     2,     3,     4,    27,   127,    73,   146,   151,
     160,   128,     5,   141,   141,    65,     1,     2,     3,     4,
     141,   147,    42,    75,    83,   166,    83,     5,    78,    83,
      35,    36,    70,    96,   171,    38,    39,   135,     1,     2,
       3,     4,   100,   129,   102,   130,   131,   132,   133,   120,
      45,    46,    47,    48,    49,    93,    94,    83,    83,    45,
      46,    47,    48,    49,     2,     3,     4,    73,   134,    51,
     109,    52,    53,    54,   117,   118,    50,    80,    51,   142,
      52,    53,    54,    45,    46,    47,    48,    49,   152,   153,
      45,    46,    47,    48,    49,    13,    14,    15,    16,   154,
      68,    97,    51,   155,    52,    53,    54,    50,   157,    51,
     161,    52,    53,    54,    45,    46,    47,    48,    49,    45,
      46,    47,    48,    49,    45,    46,    47,    48,    49,   158,
     165,    68,   167,    51,   170,    52,    53,    54,    51,   105,
      52,    53,    54,    51,   122,    52,    53,    54,   168,    89,
      90,    91,   169,   174,   175,    37,    40,   156,   164,   126,
     148,   150,    87,   149,    67,    72,    20,     0,   103
};

static const yytype_int16 yycheck[] =
{
      35,    36,     6,    38,    39,    78,   101,     1,    50,    41,
      68,     4,     5,     6,    63,    50,    51,    27,    28,    28,
       8,    34,    10,    11,    12,    13,    35,    15,    16,    17,
      18,    19,    28,    68,    20,    21,   109,    27,    28,    35,
      34,    25,    35,    92,    32,    77,    34,    15,    36,    37,
      38,    35,   168,   169,    15,    28,    42,    43,     0,   175,
      33,     3,     4,     5,     6,    15,    28,    32,   110,   127,
     143,    33,    14,   168,   169,   110,     3,     4,     5,     6,
     175,   116,    76,    15,   119,   158,   121,    14,    34,   124,
      29,    30,   127,    31,   167,    29,    30,   101,     3,     4,
       5,     6,    31,     8,    30,    10,    11,    12,    13,    24,
      15,    16,    17,    18,    19,    36,    37,   152,   153,    15,
      16,    17,    18,    19,     4,     5,     6,    32,    33,    34,
      30,    36,    37,    38,    22,    23,    32,    33,    34,    31,
      36,    37,    38,    15,    16,    17,    18,    19,    34,    34,
      15,    16,    17,    18,    19,     4,     5,     6,     7,    27,
      32,    33,    34,    27,    36,    37,    38,    32,    27,    34,
      31,    36,    37,    38,    15,    16,    17,    18,    19,    15,
      16,    17,    18,    19,    15,    16,    17,    18,    19,    29,
      27,    32,    30,    34,    27,    36,    37,    38,    34,    35,
      36,    37,    38,    34,    25,    36,    37,    38,    35,    39,
      40,    41,    35,    31,     9,    30,    33,   133,   153,    95,
     119,   124,    51,   121,    36,    39,     6,    -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    14,    45,    46,    47,    53,
      59,    92,    59,     4,     5,     6,     7,    96,     0,    46,
      92,    15,    54,    55,    15,    48,    49,    15,    56,    27,
      28,    50,    27,    28,    34,    29,    30,    55,    29,    30,
      49,    35,    59,    93,    94,    15,    16,    17,    18,    19,
      32,    34,    36,    37,    38,    57,    68,    70,    71,    72,
      73,    74,    75,    77,    78,    80,    91,    91,    32,    51,
      80,    90,    90,    32,    60,    15,    28,    35,    34,    69,
      33,    57,    58,    80,    82,    84,    86,    88,    75,    39,
      40,    41,    79,    36,    37,    81,    31,    33,    51,    52,
      31,    61,    30,    94,    60,    35,    67,    76,    80,    30,
      28,    33,    20,    21,    42,    43,    83,    22,    23,    85,
      24,    87,    25,    35,    89,    75,    78,    28,    33,     8,
      10,    11,    12,    13,    33,    46,    60,    62,    63,    64,
      67,    68,    31,    28,    35,    67,    57,    80,    82,    84,
      86,    51,    34,    34,    27,    27,    64,    27,    29,    95,
      67,    31,    65,    88,    65,    27,    67,    30,    35,    35,
      27,    67,    63,    63,    31,     9,    66,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    51,    51,    52,    52,    53,
      54,    54,    55,    56,    56,    57,    57,    57,    58,    58,
      55,    59,    59,    59,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    65,
      66,    66,    67,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    71,    72,    73,    74,    75,    75,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    88,    88,    89,
      90,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     4,     1,
       3,     4,     0,     4,     1,     3,     2,     3,     1,     3,
       1,     3,     4,     0,     4,     1,     3,     2,     3,     1,
       2,     1,     1,     1,     3,     0,     2,     1,     1,     3,
       2,     2,     5,     6,     1,     2,     4,     0,     1,     1,
       0,     2,     1,     2,     0,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     2,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     3,     1,
       1,     1,     7,     6,     1,     3,     2,     5,     0,     4,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* CompUnit: CompUnit Decl  */
#line 43 "../../src/driver/parser.y"
                {
    RootNode *tmp_root = dynamic_cast<RootNode*>(yyvsp[-1]);
    assert(tmp_root != nullptr);
    tmp_root->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 1333 "../../src/driver/parser.cpp"
    break;

  case 3: /* CompUnit: CompUnit FuncDef  */
#line 49 "../../src/driver/parser.y"
                   {
    RootNode *tmp_root = dynamic_cast<RootNode*>(yyvsp[-1]);
    assert(tmp_root != nullptr);
    tmp_root->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];    
  }
#line 1344 "../../src/driver/parser.cpp"
    break;

  case 4: /* CompUnit: Decl  */
#line 55 "../../src/driver/parser.y"
       {
    assert(root != nullptr);
    root->AddNode(yyvsp[0]);
    yyval = root;
  }
#line 1354 "../../src/driver/parser.cpp"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 60 "../../src/driver/parser.y"
          {
    assert(root != nullptr);
    root->AddNode(yyvsp[0]);
    yyval = root;    
  }
#line 1364 "../../src/driver/parser.cpp"
    break;

  case 6: /* Decl: ConstDecl  */
#line 68 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1372 "../../src/driver/parser.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 71 "../../src/driver/parser.y"
          {
    yyval = yyvsp[0];
  }
#line 1380 "../../src/driver/parser.cpp"
    break;

  case 8: /* ConstDecl: CONST BType ConstDefList ';'  */
#line 77 "../../src/driver/parser.y"
                               {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    yyval = yyvsp[-1];
  }
#line 1391 "../../src/driver/parser.cpp"
    break;

  case 9: /* ConstDefList: ConstDef  */
#line 86 "../../src/driver/parser.y"
           {
    DeclNode* new_decl_node = new DeclNode(NodeType::CONST_DECL);
    assert(new_decl_node != nullptr);
    new_decl_node->AddDecl();
    yyval = new_decl_node;
  }
#line 1402 "../../src/driver/parser.cpp"
    break;

  case 10: /* ConstDefList: ConstDefList ',' ConstDef  */
#line 92 "../../src/driver/parser.y"
                            {
    DeclNode* tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-2]);
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->AddDecl();
    yyval = yyvsp[-2];   
  }
#line 1413 "../../src/driver/parser.cpp"
    break;

  case 11: /* ConstDef: IDENT ConstDefDimensionList '=' ConstInitVal  */
#line 101 "../../src/driver/parser.y"
                                               {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent();
    declnode_tmp_init_val = yyvsp[0];
    yyval = nullptr;
  }
#line 1423 "../../src/driver/parser.cpp"
    break;

  case 12: /* ConstDefDimensionList: %empty  */
#line 109 "../../src/driver/parser.y"
              {
    declnode_tmp_array_dimension_array.resize(0);
    yyval = nullptr;
  }
#line 1432 "../../src/driver/parser.cpp"
    break;

  case 13: /* ConstDefDimensionList: ConstDefDimensionList '[' ConstExp ']'  */
#line 113 "../../src/driver/parser.y"
                                         {
    declnode_tmp_array_dimension_array.push_back(yyvsp[-1]);
    yyval = yyvsp[-3];
  }
#line 1441 "../../src/driver/parser.cpp"
    break;

  case 14: /* ConstInitVal: ConstExp  */
#line 120 "../../src/driver/parser.y"
           {
    yyval = yyvsp[0];
  }
#line 1449 "../../src/driver/parser.cpp"
    break;

  case 15: /* ConstInitVal: '{' ConstInitValList '}'  */
#line 123 "../../src/driver/parser.y"
                           {
    yyval = yyvsp[-1];
  }
#line 1457 "../../src/driver/parser.cpp"
    break;

  case 16: /* ConstInitVal: '{' '}'  */
#line 126 "../../src/driver/parser.y"
          {
    yyval = new InitValNode;
  }
#line 1465 "../../src/driver/parser.cpp"
    break;

  case 17: /* ConstInitValList: ConstInitValList ',' ConstInitVal  */
#line 132 "../../src/driver/parser.y"
                                    {
    dynamic_cast<InitValNode*>(yyvsp[-2])->AddInitVal(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 1474 "../../src/driver/parser.cpp"
    break;

  case 18: /* ConstInitValList: ConstInitVal  */
#line 136 "../../src/driver/parser.y"
               {
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal(yyvsp[0]);
    yyval = new_init_val_node;
  }
#line 1484 "../../src/driver/parser.cpp"
    break;

  case 19: /* VarDecl: BType VarDefList ';'  */
#line 144 "../../src/driver/parser.y"
                       {
    DeclNode *tmp_decl_node = dynamic_cast<DeclNode*>(yyvsp[-1]); 
    assert(tmp_decl_node != nullptr);
    tmp_decl_node->SetBasicType();
    yyval = yyvsp[-1];
  }
#line 1495 "../../src/driver/parser.cpp"
    break;

  case 20: /* VarDefList: VarDef  */
#line 153 "../../src/driver/parser.y"
         {
    DeclNode* new_decl_node = new DeclNode(NodeType::VAR_DECL);
    new_decl_node->AddDecl();
    yyval = new_decl_node;
  }
#line 1505 "../../src/driver/parser.cpp"
    break;

  case 21: /* VarDefList: VarDefList ',' VarDef  */
#line 158 "../../src/driver/parser.y"
                         {
    dynamic_cast<DeclNode*>(yyvsp[-2])->AddDecl();
    yyval = yyvsp[-2];
  }
#line 1514 "../../src/driver/parser.cpp"
    break;

  case 22: /* VarDef: IDENT VarDefDimensionList '=' VarInitVal  */
#line 165 "../../src/driver/parser.y"
                                           {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-3])->GetIdent();
    declnode_tmp_init_val = yyvsp[0];
    yyval = nullptr; 
  }
#line 1524 "../../src/driver/parser.cpp"
    break;

  case 23: /* VarDefDimensionList: %empty  */
#line 173 "../../src/driver/parser.y"
              {
    declnode_tmp_array_dimension_array.resize(0);
    yyval = nullptr;
  }
#line 1533 "../../src/driver/parser.cpp"
    break;

  case 24: /* VarDefDimensionList: VarDefDimensionList '[' VarExp ']'  */
#line 177 "../../src/driver/parser.y"
                                     {
    declnode_tmp_array_dimension_array.push_back(yyvsp[-1]);
    yyval = yyvsp[-3];
  }
#line 1542 "../../src/driver/parser.cpp"
    break;

  case 25: /* VarInitVal: VarExp  */
#line 184 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1550 "../../src/driver/parser.cpp"
    break;

  case 26: /* VarInitVal: '{' VarInitValList '}'  */
#line 187 "../../src/driver/parser.y"
                         {
    yyval = yyvsp[-1];
  }
#line 1558 "../../src/driver/parser.cpp"
    break;

  case 27: /* VarInitVal: '{' '}'  */
#line 190 "../../src/driver/parser.y"
          {
    yyval = new InitValNode;
  }
#line 1566 "../../src/driver/parser.cpp"
    break;

  case 28: /* VarInitValList: VarInitValList ',' VarInitVal  */
#line 196 "../../src/driver/parser.y"
                                {
    dynamic_cast<InitValNode*>(yyvsp[-2])->AddInitVal(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 1575 "../../src/driver/parser.cpp"
    break;

  case 29: /* VarInitValList: VarInitVal  */
#line 200 "../../src/driver/parser.y"
             {
    InitValNode *new_init_val_node = new InitValNode;
    new_init_val_node->AddInitVal(yyvsp[0]);
    yyval = new_init_val_node;
  }
#line 1585 "../../src/driver/parser.cpp"
    break;

  case 30: /* VarDef: IDENT VarDefDimensionList  */
#line 208 "../../src/driver/parser.y"
                            {
    declnode_tmp_ident = dynamic_cast<IdentNode*>(yyvsp[-1])->GetIdent();
    declnode_tmp_init_val = nullptr;
    yyval = nullptr;
  }
#line 1595 "../../src/driver/parser.cpp"
    break;

  case 31: /* BType: INT  */
#line 216 "../../src/driver/parser.y"
      {
    declnode_tmp_basic_type = BasicType::INT;
    funcdefnode_tmp_fparam_basic_type = BasicType::INT;
    yyval = nullptr;
  }
#line 1605 "../../src/driver/parser.cpp"
    break;

  case 32: /* BType: FLOAT  */
#line 221 "../../src/driver/parser.y"
        {
    declnode_tmp_basic_type = BasicType::FLOAT;
    funcdefnode_tmp_fparam_basic_type = BasicType::FLOAT;
    yyval = nullptr;
  }
#line 1615 "../../src/driver/parser.cpp"
    break;

  case 33: /* BType: CHAR  */
#line 226 "../../src/driver/parser.y"
       {
    declnode_tmp_basic_type = BasicType::CHAR;
    funcdefnode_tmp_fparam_basic_type = BasicType::CHAR;
    yyval = nullptr;
  }
#line 1625 "../../src/driver/parser.cpp"
    break;

  case 34: /* Block: '{' BlockItemList '}'  */
#line 234 "../../src/driver/parser.y"
                        {
    yyval = yyvsp[-1];
  }
#line 1633 "../../src/driver/parser.cpp"
    break;

  case 35: /* BlockItemList: %empty  */
#line 240 "../../src/driver/parser.y"
              {
    yyval = new BlockNode;
    assert(yyval != nullptr);
  }
#line 1642 "../../src/driver/parser.cpp"
    break;

  case 36: /* BlockItemList: BlockItemList BlockItem  */
#line 244 "../../src/driver/parser.y"
                          {
    BlockNode *tmp_block_node = dynamic_cast<BlockNode*>(yyvsp[-1]); 
    assert(tmp_block_node != nullptr);
    tmp_block_node->AddNode(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 1653 "../../src/driver/parser.cpp"
    break;

  case 37: /* BlockItem: Decl  */
#line 253 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 1661 "../../src/driver/parser.cpp"
    break;

  case 38: /* BlockItem: Stmt  */
#line 256 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 1669 "../../src/driver/parser.cpp"
    break;

  case 39: /* Stmt: RETURN ExpChoice ';'  */
#line 262 "../../src/driver/parser.y"
                       {
    yyval = new ReturnStmtNode(yyvsp[-1]);
  }
#line 1677 "../../src/driver/parser.cpp"
    break;

  case 40: /* Stmt: CONTINUE ';'  */
#line 265 "../../src/driver/parser.y"
               {
    yyval = new ContinueStmtNode;  
  }
#line 1685 "../../src/driver/parser.cpp"
    break;

  case 41: /* Stmt: BREAK ';'  */
#line 268 "../../src/driver/parser.y"
            {
    yyval = new BreakStmtNode;
  }
#line 1693 "../../src/driver/parser.cpp"
    break;

  case 42: /* Stmt: WHILE '(' Cond ')' Stmt  */
#line 271 "../../src/driver/parser.y"
                          {
    yyval = new WhileStmtNode(yyvsp[-2], yyvsp[0]);
  }
#line 1701 "../../src/driver/parser.cpp"
    break;

  case 43: /* Stmt: IF '(' Cond ')' Stmt ElseChoice  */
#line 274 "../../src/driver/parser.y"
                                  {
    yyval = new IfStmtNode(yyvsp[-3], yyvsp[-1], yyvsp[0]);
  }
#line 1709 "../../src/driver/parser.cpp"
    break;

  case 44: /* Stmt: Block  */
#line 277 "../../src/driver/parser.y"
        {
    yyval = yyvsp[0];
  }
#line 1717 "../../src/driver/parser.cpp"
    break;

  case 45: /* Stmt: ExpChoice ';'  */
#line 280 "../../src/driver/parser.y"
                {
    yyval = yyvsp[-1];
  }
#line 1725 "../../src/driver/parser.cpp"
    break;

  case 46: /* Stmt: LVal '=' Exp ';'  */
#line 283 "../../src/driver/parser.y"
                   {
    yyval = new AssignStmtNode(yyvsp[-3], yyvsp[-1]);
  }
#line 1733 "../../src/driver/parser.cpp"
    break;

  case 47: /* ExpChoice: %empty  */
#line 289 "../../src/driver/parser.y"
              {
    yyval = nullptr;
  }
#line 1741 "../../src/driver/parser.cpp"
    break;

  case 48: /* ExpChoice: Exp  */
#line 292 "../../src/driver/parser.y"
      {
    yyval = yyvsp[0];
  }
#line 1749 "../../src/driver/parser.cpp"
    break;

  case 49: /* Cond: LOrExp  */
#line 298 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1757 "../../src/driver/parser.cpp"
    break;

  case 50: /* ElseChoice: %empty  */
#line 304 "../../src/driver/parser.y"
              {
    yyval = nullptr;
  }
#line 1765 "../../src/driver/parser.cpp"
    break;

  case 51: /* ElseChoice: ELSE Stmt  */
#line 307 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1773 "../../src/driver/parser.cpp"
    break;

  case 52: /* Exp: AddExp  */
#line 313 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1781 "../../src/driver/parser.cpp"
    break;

  case 53: /* LVal: IDENT IndexList  */
#line 319 "../../src/driver/parser.y"
                  {
    LValPrimaryExpNode* tmp_node = new LValPrimaryExpNode(dynamic_cast<IdentNode*>(yyvsp[-1]));
    tmp_node->AddLVal();
    yyval = tmp_node;
  }
#line 1791 "../../src/driver/parser.cpp"
    break;

  case 54: /* IndexList: %empty  */
#line 327 "../../src/driver/parser.y"
              {
    lvalprimaryexpnode_tmp_index_array.resize(0);
    yyval = nullptr;
  }
#line 1800 "../../src/driver/parser.cpp"
    break;

  case 55: /* IndexList: IndexList '[' Exp ']'  */
#line 331 "../../src/driver/parser.y"
                        {
    lvalprimaryexpnode_tmp_index_array.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 1809 "../../src/driver/parser.cpp"
    break;

  case 56: /* PrimaryExp: '(' LOrExp ')'  */
#line 338 "../../src/driver/parser.y"
                 {
    yyval = yyvsp[-1];
  }
#line 1817 "../../src/driver/parser.cpp"
    break;

  case 57: /* PrimaryExp: LVal  */
#line 341 "../../src/driver/parser.y"
       {
    yyval = yyvsp[0];
  }
#line 1825 "../../src/driver/parser.cpp"
    break;

  case 58: /* PrimaryExp: IntNumber  */
#line 344 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1833 "../../src/driver/parser.cpp"
    break;

  case 59: /* PrimaryExp: FloatNumber  */
#line 347 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 1841 "../../src/driver/parser.cpp"
    break;

  case 60: /* PrimaryExp: character  */
#line 350 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1849 "../../src/driver/parser.cpp"
    break;

  case 61: /* PrimaryExp: String  */
#line 353 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 1857 "../../src/driver/parser.cpp"
    break;

  case 62: /* IntNumber: INT_CONST  */
#line 359 "../../src/driver/parser.y"
            {
    yyval = yyvsp[0];
  }
#line 1865 "../../src/driver/parser.cpp"
    break;

  case 63: /* FloatNumber: FLOAT_CONST  */
#line 365 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 1873 "../../src/driver/parser.cpp"
    break;

  case 64: /* character: CHAR_CONST  */
#line 371 "../../src/driver/parser.y"
             {
    yyval = yyvsp[0];
  }
#line 1881 "../../src/driver/parser.cpp"
    break;

  case 65: /* String: STRING_CONST  */
#line 377 "../../src/driver/parser.y"
               {
    yyval = yyvsp[0];
  }
#line 1889 "../../src/driver/parser.cpp"
    break;

  case 66: /* UnaryExp: PrimaryExp  */
#line 383 "../../src/driver/parser.y"
             {
    yyval = yyvsp[0];
  }
#line 1897 "../../src/driver/parser.cpp"
    break;

  case 67: /* UnaryExp: IDENT '(' FuncRParamList ')'  */
#line 386 "../../src/driver/parser.y"
                               {
    dynamic_cast<FuncCallExpNode*>(yyvsp[-1])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-3]));
    yyval = yyvsp[-1];
  }
#line 1906 "../../src/driver/parser.cpp"
    break;

  case 68: /* UnaryExp: IDENT '(' ')'  */
#line 390 "../../src/driver/parser.y"
                {
    FuncCallExpNode* new_node = new FuncCallExpNode;
    new_node->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-2]));
    yyval = new_node;
  }
#line 1916 "../../src/driver/parser.cpp"
    break;

  case 69: /* UnaryExp: UnaryOp UnaryExp  */
#line 395 "../../src/driver/parser.y"
                   {
    dynamic_cast<UnaryExpNode*>(yyvsp[-1])->SetExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 1925 "../../src/driver/parser.cpp"
    break;

  case 70: /* FuncRParamList: Exp  */
#line 402 "../../src/driver/parser.y"
      {
    FuncCallExpNode *new_node = new FuncCallExpNode;
    yyval = new_node;
  }
#line 1934 "../../src/driver/parser.cpp"
    break;

  case 71: /* FuncRParamList: FuncRParamList ',' Exp  */
#line 406 "../../src/driver/parser.y"
                         {
    dynamic_cast<FuncCallExpNode*>(yyvsp[-2])->AddParam(yyvsp[0]);
    yyval = yyvsp[-2];
  }
#line 1943 "../../src/driver/parser.cpp"
    break;

  case 72: /* UnaryOp: '+'  */
#line 413 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::POSITIVE);
    yyval = new_node;
  }
#line 1952 "../../src/driver/parser.cpp"
    break;

  case 73: /* UnaryOp: '-'  */
#line 417 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NEGATIVE);
    yyval = new_node;
  }
#line 1961 "../../src/driver/parser.cpp"
    break;

  case 74: /* UnaryOp: '!'  */
#line 421 "../../src/driver/parser.y"
      {
    UnaryExpNode *new_node = new UnaryExpNode(UnaryOpType::NOT);
    yyval = new_node;
  }
#line 1970 "../../src/driver/parser.cpp"
    break;

  case 75: /* MulExp: UnaryExp  */
#line 428 "../../src/driver/parser.y"
           {
    yyval = yyvsp[0];
  }
#line 1978 "../../src/driver/parser.cpp"
    break;

  case 76: /* MulExp: MulExp MulOp UnaryExp  */
#line 431 "../../src/driver/parser.y"
                        {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 1988 "../../src/driver/parser.cpp"
    break;

  case 77: /* MulOp: '*'  */
#line 439 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MUL);
    yyval = new_node;
  }
#line 1997 "../../src/driver/parser.cpp"
    break;

  case 78: /* MulOp: '/'  */
#line 443 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::DIV);
    yyval = new_node;
  }
#line 2006 "../../src/driver/parser.cpp"
    break;

  case 79: /* MulOp: '%'  */
#line 447 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::MOD);
    yyval = new_node;
  }
#line 2015 "../../src/driver/parser.cpp"
    break;

  case 80: /* AddExp: MulExp  */
#line 454 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2023 "../../src/driver/parser.cpp"
    break;

  case 81: /* AddExp: AddExp AddOp MulExp  */
#line 457 "../../src/driver/parser.y"
                      {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1]; 
  }
#line 2033 "../../src/driver/parser.cpp"
    break;

  case 82: /* AddOp: '+'  */
#line 465 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::ADD);
    yyval = new_node;
  }
#line 2042 "../../src/driver/parser.cpp"
    break;

  case 83: /* AddOp: '-'  */
#line 469 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::SUB);
    yyval = new_node;
  }
#line 2051 "../../src/driver/parser.cpp"
    break;

  case 84: /* RelExp: RelExp RelOp AddExp  */
#line 476 "../../src/driver/parser.y"
                      {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2061 "../../src/driver/parser.cpp"
    break;

  case 85: /* RelExp: AddExp  */
#line 481 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0]; 
  }
#line 2069 "../../src/driver/parser.cpp"
    break;

  case 86: /* RelOp: '<'  */
#line 487 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LE);
    yyval = new_node; 
  }
#line 2078 "../../src/driver/parser.cpp"
    break;

  case 87: /* RelOp: '>'  */
#line 491 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GE);
    yyval = new_node; 
  }
#line 2087 "../../src/driver/parser.cpp"
    break;

  case 88: /* RelOp: LEEQ  */
#line 495 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::LEEQ);
    yyval = new_node; 
  }
#line 2096 "../../src/driver/parser.cpp"
    break;

  case 89: /* RelOp: GEEQ  */
#line 499 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::GEEQ);
    yyval = new_node; 
  }
#line 2105 "../../src/driver/parser.cpp"
    break;

  case 90: /* EqExp: RelExp  */
#line 506 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2113 "../../src/driver/parser.cpp"
    break;

  case 91: /* EqExp: EqExp EqOp RelExp  */
#line 509 "../../src/driver/parser.y"
                    {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2123 "../../src/driver/parser.cpp"
    break;

  case 92: /* EqOp: EQ  */
#line 517 "../../src/driver/parser.y"
     {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::EQ);
    yyval = new_node;
  }
#line 2132 "../../src/driver/parser.cpp"
    break;

  case 93: /* EqOp: UNEQ  */
#line 521 "../../src/driver/parser.y"
       {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::UNEQ);
    yyval = new_node;
  }
#line 2141 "../../src/driver/parser.cpp"
    break;

  case 94: /* LAndExp: EqExp  */
#line 528 "../../src/driver/parser.y"
        {
    yyval = yyvsp[0];
  }
#line 2149 "../../src/driver/parser.cpp"
    break;

  case 95: /* LAndExp: LAndExp LAndOp EqExp  */
#line 531 "../../src/driver/parser.y"
                       {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2159 "../../src/driver/parser.cpp"
    break;

  case 96: /* LAndOp: AND  */
#line 539 "../../src/driver/parser.y"
      {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::AND);
    yyval = new_node;
  }
#line 2168 "../../src/driver/parser.cpp"
    break;

  case 97: /* LOrExp: LAndExp  */
#line 546 "../../src/driver/parser.y"
          {
    yyval = yyvsp[0];
  }
#line 2176 "../../src/driver/parser.cpp"
    break;

  case 98: /* LOrExp: LOrExp LOrOp LAndExp  */
#line 549 "../../src/driver/parser.y"
                       {
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetLeftExp(yyvsp[-2]);
    dynamic_cast<BinaryExpNode*>(yyvsp[-1])->SetRightExp(yyvsp[0]);
    yyval = yyvsp[-1];
  }
#line 2186 "../../src/driver/parser.cpp"
    break;

  case 99: /* LOrOp: OR  */
#line 557 "../../src/driver/parser.y"
     {
    BinaryExpNode *new_node = new BinaryExpNode(BinaryOpType::OR);
    yyval = new_node;
  }
#line 2195 "../../src/driver/parser.cpp"
    break;

  case 100: /* ConstExp: AddExp  */
#line 564 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2203 "../../src/driver/parser.cpp"
    break;

  case 101: /* VarExp: AddExp  */
#line 570 "../../src/driver/parser.y"
         {
    yyval = yyvsp[0];
  }
#line 2211 "../../src/driver/parser.cpp"
    break;

  case 102: /* FuncDef: DEF FuncType IDENT '(' FuncFParamList ')' Block  */
#line 576 "../../src/driver/parser.y"
                                                  {
    dynamic_cast<FuncDefNode*>(yyvsp[-5])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-4]));
    dynamic_cast<FuncDefNode*>(yyvsp[-5])->SetBlock(yyvsp[0]);
    yyval = funcdefnode_tmp_func_def_node;
  }
#line 2221 "../../src/driver/parser.cpp"
    break;

  case 103: /* FuncDef: DEF FuncType IDENT '(' ')' Block  */
#line 581 "../../src/driver/parser.y"
                                   {
    dynamic_cast<FuncDefNode*>(yyvsp[-4])->SetIdent(dynamic_cast<IdentNode*>(yyvsp[-3]));
    dynamic_cast<FuncDefNode*>(yyvsp[-4])->SetBlock(yyvsp[0]);
    yyval = funcdefnode_tmp_func_def_node;
  }
#line 2231 "../../src/driver/parser.cpp"
    break;

  case 104: /* FuncFParamList: FuncFParam  */
#line 589 "../../src/driver/parser.y"
             {
    funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>(yyvsp[0]));
    yyval = nullptr;
  }
#line 2240 "../../src/driver/parser.cpp"
    break;

  case 105: /* FuncFParamList: FuncFParamList ',' FuncFParam  */
#line 593 "../../src/driver/parser.y"
                                {
    funcdefnode_tmp_func_def_node->AddParam(dynamic_cast<IdentNode*>(yyvsp[0]));
    yyval = nullptr;
  }
#line 2249 "../../src/driver/parser.cpp"
    break;

  case 106: /* FuncFParam: BType IDENT  */
#line 600 "../../src/driver/parser.y"
              {
    yyval = yyvsp[0];
  }
#line 2257 "../../src/driver/parser.cpp"
    break;

  case 107: /* FuncFParam: BType IDENT '[' ']' FuncFParamIndexList  */
#line 603 "../../src/driver/parser.y"
                                          {
    yyval = yyvsp[-3];
  }
#line 2265 "../../src/driver/parser.cpp"
    break;

  case 108: /* FuncFParamIndexList: %empty  */
#line 609 "../../src/driver/parser.y"
              {
    funcdefnode_tmp_fparam_index_list.resize(0);
    funcdefnode_tmp_fparam_index_list.push_back(nullptr);
    yyval = nullptr;
  }
#line 2275 "../../src/driver/parser.cpp"
    break;

  case 109: /* FuncFParamIndexList: FuncFParamIndexList '[' Exp ']'  */
#line 614 "../../src/driver/parser.y"
                                  {
    funcdefnode_tmp_fparam_index_list.push_back(yyvsp[-1]);
    yyval = nullptr;
  }
#line 2284 "../../src/driver/parser.cpp"
    break;

  case 110: /* FuncType: VOID  */
#line 621 "../../src/driver/parser.y"
       {
    FuncDefNode *new_node = new FuncDefNode(BasicType::VOID);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2294 "../../src/driver/parser.cpp"
    break;

  case 111: /* FuncType: INT  */
#line 626 "../../src/driver/parser.y"
      {
    FuncDefNode *new_node = new FuncDefNode(BasicType::INT);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2304 "../../src/driver/parser.cpp"
    break;

  case 112: /* FuncType: FLOAT  */
#line 631 "../../src/driver/parser.y"
        {
    FuncDefNode *new_node = new FuncDefNode(BasicType::FLOAT);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2314 "../../src/driver/parser.cpp"
    break;

  case 113: /* FuncType: CHAR  */
#line 636 "../../src/driver/parser.y"
       {
    FuncDefNode *new_node = new FuncDefNode(BasicType::CHAR);
    funcdefnode_tmp_func_def_node = new_node;
    yyval = new_node;
  }
#line 2324 "../../src/driver/parser.cpp"
    break;


#line 2328 "../../src/driver/parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 643 "../../src/driver/parser.y"
