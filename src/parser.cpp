/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "src/parser.y"

    #include <iostream>
    #include <vector>
    #include <assert.h>
    #include "parser.h"
    
    extern Ast ast;
    extern Unit unit;
    int yylex();
    int yyerror( char const * );

#line 80 "src/parser.cpp"




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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_CONTINUE = 8,                   /* CONTINUE  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONST = 10,                     /* CONST  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_LPAREN = 13,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 14,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_ADD = 19,                       /* ADD  */
  YYSYMBOL_SUB = 20,                       /* SUB  */
  YYSYMBOL_MUL = 21,                       /* MUL  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_MOD = 23,                       /* MOD  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_LESS = 26,                      /* LESS  */
  YYSYMBOL_GREATER = 27,                   /* GREATER  */
  YYSYMBOL_LESSEQ = 28,                    /* LESSEQ  */
  YYSYMBOL_GREATEREQ = 29,                 /* GREATEREQ  */
  YYSYMBOL_NOTEQ = 30,                     /* NOTEQ  */
  YYSYMBOL_EQUAL = 31,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 35,                     /* UPLUS  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_THEN = 37,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_Program = 39,                   /* Program  */
  YYSYMBOL_Stmts = 40,                     /* Stmts  */
  YYSYMBOL_Stmt = 41,                      /* Stmt  */
  YYSYMBOL_ExpStmt = 42,                   /* ExpStmt  */
  YYSYMBOL_LVal = 43,                      /* LVal  */
  YYSYMBOL_AssignStmt = 44,                /* AssignStmt  */
  YYSYMBOL_BlockStmt = 45,                 /* BlockStmt  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_IfStmt = 47,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 48,                 /* WhileStmt  */
  YYSYMBOL_ReturnStmt = 49,                /* ReturnStmt  */
  YYSYMBOL_Exp = 50,                       /* Exp  */
  YYSYMBOL_Cond = 51,                      /* Cond  */
  YYSYMBOL_PrimaryExp = 52,                /* PrimaryExp  */
  YYSYMBOL_AddExp = 53,                    /* AddExp  */
  YYSYMBOL_MulExp = 54,                    /* MulExp  */
  YYSYMBOL_UnaryExp = 55,                  /* UnaryExp  */
  YYSYMBOL_FuncUseExp = 56,                /* FuncUseExp  */
  YYSYMBOL_FuncRParams = 57,               /* FuncRParams  */
  YYSYMBOL_RelExp = 58,                    /* RelExp  */
  YYSYMBOL_LAndExp = 59,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 60,                    /* LOrExp  */
  YYSYMBOL_Type = 61,                      /* Type  */
  YYSYMBOL_IDListEle = 62,                 /* IDListEle  */
  YYSYMBOL_IDList = 63,                    /* IDList  */
  YYSYMBOL_IDListDeclStmt = 64,            /* IDListDeclStmt  */
  YYSYMBOL_ParamList = 65,                 /* ParamList  */
  YYSYMBOL_FuncDef = 66,                   /* FuncDef  */
  YYSYMBOL_67_2 = 67,                      /* $@2  */
  YYSYMBOL_68_3 = 68                       /* $@3  */
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
typedef yytype_int8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    59,    60,    65,    66,    67,    68,    69,
      71,    72,    73,    74,    78,    83,    98,   104,   103,   112,
     115,   118,   123,   129,   132,   138,   142,   146,   149,   153,
     161,   163,   169,   177,   179,   185,   191,   199,   201,   203,
     209,   215,   223,   231,   239,   244,   252,   254,   260,   266,
     272,   278,   284,   292,   294,   302,   304,   311,   314,   317,
     337,   340,   346,   350,   358,   390,   394,   403,   401,   424,
     424
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTEGER", "IF",
  "ELSE", "WHILE", "CONTINUE", "BREAK", "CONST", "INT", "VOID", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "ADD", "SUB", "MUL",
  "DIV", "MOD", "OR", "AND", "LESS", "GREATER", "LESSEQ", "GREATEREQ",
  "NOTEQ", "EQUAL", "ASSIGN", "RETURN", "UMINUS", "UPLUS", "NOT", "THEN",
  "$accept", "Program", "Stmts", "Stmt", "ExpStmt", "LVal", "AssignStmt",
  "BlockStmt", "$@1", "IfStmt", "WhileStmt", "ReturnStmt", "Exp", "Cond",
  "PrimaryExp", "AddExp", "MulExp", "UnaryExp", "FuncUseExp",
  "FuncRParams", "RelExp", "LAndExp", "LOrExp", "Type", "IDListEle",
  "IDList", "IDListDeclStmt", "ParamList", "FuncDef", "$@2", "$@3", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     119,  -108,  -108,    -3,     7,    21,  -108,  -108,    74,    19,
    -108,    74,    74,    14,    74,    36,   119,  -108,  -108,    -9,
    -108,  -108,  -108,  -108,  -108,    22,  -108,     6,    23,  -108,
    -108,    46,  -108,  -108,    74,    74,  -108,    38,    54,  -108,
     119,  -108,  -108,  -108,    52,  -108,  -108,  -108,    34,    74,
    -108,    74,    74,    74,    74,    74,    -4,    55,    57,    58,
       6,    90,    50,    56,    65,  -108,    92,  -108,  -108,  -108,
       1,    66,    23,    23,  -108,  -108,  -108,   130,    74,    79,
    -108,   119,    74,    74,    74,    74,    74,    74,    74,    74,
     119,  -108,  -108,    74,  -108,  -108,    81,  -108,  -108,    53,
    -108,    82,     6,     6,     6,     6,     6,     6,    90,    50,
    -108,  -108,    76,    71,    78,   119,  -108,     2,    76,  -108,
    -108,  -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    28,     0,     0,     0,    57,    58,     0,    17,
      13,     0,     0,     0,     0,     0,     2,     3,    12,    27,
       5,     6,     7,     8,     9,     0,    37,    25,    30,    33,
      38,     0,    11,    10,     0,     0,    59,    27,     0,    19,
       0,    40,    39,    24,     0,    41,     1,     4,     0,     0,
      14,     0,     0,     0,     0,     0,    61,    62,     0,     0,
      46,    53,    55,    26,     0,    29,     0,    23,    43,    44,
       0,     0,    31,    32,    34,    35,    36,     0,     0,     0,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    42,     0,    16,    67,     0,    69,    60,    61,
      63,    20,    47,    48,    49,    50,    51,    52,    54,    56,
      22,    45,     0,    65,     0,     0,    68,     0,     0,    21,
      66,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,    60,   -14,  -108,     0,  -108,  -107,  -108,  -108,
    -108,  -108,    -7,    63,  -108,   -27,   -22,    10,  -108,  -108,
      18,    24,  -108,   -74,  -108,    35,  -108,    16,  -108,  -108,
    -108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,    17,    18,    37,    20,    21,    40,    22,
      23,    24,    25,    59,    26,    27,    28,    29,    30,    70,
      61,    62,    63,    31,    57,    58,    32,    97,    33,   112,
     114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    38,    47,    96,    48,   116,    44,    60,    60,    77,
      34,   121,     5,     6,     7,    92,    19,     1,     2,    93,
      35,    41,    42,    49,    45,    51,    52,     8,    78,    72,
      73,    43,    36,    11,    12,    39,    46,     1,     2,    50,
      19,    69,    71,    96,    53,    54,    55,     8,    68,    56,
      14,    48,    47,    11,    12,   102,   103,   104,   105,   106,
     107,    60,    60,    74,    75,    76,    19,   101,    65,    67,
      14,    98,    81,    79,    80,    88,   110,     1,     2,    90,
      89,    19,    99,    94,   113,    78,   111,     8,   115,   117,
      19,     9,   118,    11,    12,     1,     2,     3,    64,     4,
      66,   119,     5,     6,     7,     8,   108,     9,    91,    10,
      14,    11,    12,   109,   100,    19,    82,    83,    84,    85,
      86,    87,     1,     2,     3,    13,     4,     0,    14,     5,
       6,     7,     8,   120,     9,     0,    10,     0,    11,    12,
       5,     6,     7,     0,    95,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,    14
};

static const yytype_int8 yycheck[] =
{
       0,     8,    16,    77,    13,   112,    13,    34,    35,    13,
      13,   118,    10,    11,    12,    14,    16,     3,     4,    18,
      13,    11,    12,    32,    14,    19,    20,    13,    32,    51,
      52,    17,    11,    19,    20,    16,     0,     3,     4,    17,
      40,    48,    49,   117,    21,    22,    23,    13,    14,     3,
      36,    13,    66,    19,    20,    82,    83,    84,    85,    86,
      87,    88,    89,    53,    54,    55,    66,    81,    14,    17,
      36,    78,    14,    18,    17,    25,    90,     3,     4,    14,
      24,    81,     3,    17,     3,    32,    93,    13,     6,    18,
      90,    15,    14,    19,    20,     3,     4,     5,    35,     7,
      40,   115,    10,    11,    12,    13,    88,    15,    16,    17,
      36,    19,    20,    89,    79,   115,    26,    27,    28,    29,
      30,    31,     3,     4,     5,    33,     7,    -1,    36,    10,
      11,    12,    13,   117,    15,    -1,    17,    -1,    19,    20,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    10,    11,    12,    13,    15,
      17,    19,    20,    33,    36,    39,    40,    41,    42,    43,
      44,    45,    47,    48,    49,    50,    52,    53,    54,    55,
      56,    61,    64,    66,    13,    13,    11,    43,    50,    16,
      46,    55,    55,    17,    50,    55,     0,    41,    13,    32,
      17,    19,    20,    21,    22,    23,     3,    62,    63,    51,
      53,    58,    59,    60,    51,    14,    40,    17,    14,    50,
      57,    50,    54,    54,    55,    55,    55,    13,    32,    18,
      17,    14,    26,    27,    28,    29,    30,    31,    25,    24,
      14,    16,    14,    18,    17,    14,    61,    65,    50,     3,
      63,    41,    53,    53,    53,    53,    53,    53,    58,    59,
      41,    50,    67,     3,    68,     6,    45,    18,    14,    41,
      65,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    42,    43,    44,    46,    45,    45,
      47,    47,    48,    49,    49,    50,    51,    52,    52,    52,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    63,    63,    64,    65,    65,    67,    66,    68,
      66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     4,     0,     4,     2,
       5,     7,     5,     3,     2,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     2,
       2,     2,     4,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     1,     1,     2,
       3,     1,     1,     3,     3,     2,     4,     0,     6,     0,
       7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* Program: Stmts  */
#line 54 "src/parser.y"
            {
        ast.setRoot((yyvsp[0].stmttype));
    }
#line 1231 "src/parser.cpp"
    break;

  case 3: /* Stmts: Stmt  */
#line 59 "src/parser.y"
           {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1237 "src/parser.cpp"
    break;

  case 4: /* Stmts: Stmts Stmt  */
#line 60 "src/parser.y"
                {
        (yyval.stmttype) = new SeqNode((yyvsp[-1].stmttype), (yyvsp[0].stmttype));
    }
#line 1245 "src/parser.cpp"
    break;

  case 5: /* Stmt: AssignStmt  */
#line 65 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1251 "src/parser.cpp"
    break;

  case 6: /* Stmt: BlockStmt  */
#line 66 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1257 "src/parser.cpp"
    break;

  case 7: /* Stmt: IfStmt  */
#line 67 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1263 "src/parser.cpp"
    break;

  case 8: /* Stmt: WhileStmt  */
#line 68 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1269 "src/parser.cpp"
    break;

  case 9: /* Stmt: ReturnStmt  */
#line 69 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1275 "src/parser.cpp"
    break;

  case 10: /* Stmt: FuncDef  */
#line 71 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1281 "src/parser.cpp"
    break;

  case 11: /* Stmt: IDListDeclStmt  */
#line 72 "src/parser.y"
                     {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1287 "src/parser.cpp"
    break;

  case 12: /* Stmt: ExpStmt  */
#line 73 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1293 "src/parser.cpp"
    break;

  case 13: /* Stmt: SEMICOLON  */
#line 74 "src/parser.y"
                {(yyval.stmttype) = new EmptyStmt();}
#line 1299 "src/parser.cpp"
    break;

  case 14: /* ExpStmt: Exp SEMICOLON  */
#line 78 "src/parser.y"
                 {
        (yyval.stmttype)=new ExpStmt((yyvsp[-1].exprtype));
    }
#line 1307 "src/parser.cpp"
    break;

  case 15: /* LVal: ID  */
#line 83 "src/parser.y"
         {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[0].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[0].strtype));
            delete [](char*)(yyvsp[0].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new Id(se);
        delete [](yyvsp[0].strtype);
    }
#line 1324 "src/parser.cpp"
    break;

  case 16: /* AssignStmt: LVal ASSIGN Exp SEMICOLON  */
#line 98 "src/parser.y"
                              {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
    }
#line 1332 "src/parser.cpp"
    break;

  case 17: /* $@1: %empty  */
#line 104 "src/parser.y"
        {identifiers = new SymbolTable(identifiers);}
#line 1338 "src/parser.cpp"
    break;

  case 18: /* BlockStmt: LBRACE $@1 Stmts RBRACE  */
#line 106 "src/parser.y"
        {
            (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype));
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
#line 1349 "src/parser.cpp"
    break;

  case 19: /* BlockStmt: LBRACE RBRACE  */
#line 112 "src/parser.y"
                        {(yyval.stmttype)=new EmptyStmt();}
#line 1355 "src/parser.cpp"
    break;

  case 20: /* IfStmt: IF LPAREN Cond RPAREN Stmt  */
#line 115 "src/parser.y"
                                            {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1363 "src/parser.cpp"
    break;

  case 21: /* IfStmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 118 "src/parser.y"
                                           {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 1371 "src/parser.cpp"
    break;

  case 22: /* WhileStmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 123 "src/parser.y"
                                       {
		(yyval.stmttype) = new WhileStmt((yyvsp[-2].exprtype),(yyvsp[0].stmttype));
	}
#line 1379 "src/parser.cpp"
    break;

  case 23: /* ReturnStmt: RETURN Exp SEMICOLON  */
#line 129 "src/parser.y"
                        {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
    }
#line 1387 "src/parser.cpp"
    break;

  case 24: /* ReturnStmt: RETURN SEMICOLON  */
#line 132 "src/parser.y"
                     {
		(yyval.stmttype) = new ReturnStmt(new Constant(new ConstantSymbolEntry(new VoidType(),0)));
	}
#line 1395 "src/parser.cpp"
    break;

  case 25: /* Exp: AddExp  */
#line 138 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1401 "src/parser.cpp"
    break;

  case 26: /* Cond: LOrExp  */
#line 142 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1407 "src/parser.cpp"
    break;

  case 27: /* PrimaryExp: LVal  */
#line 146 "src/parser.y"
         {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1415 "src/parser.cpp"
    break;

  case 28: /* PrimaryExp: INTEGER  */
#line 149 "src/parser.y"
              {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se);
    }
#line 1424 "src/parser.cpp"
    break;

  case 29: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 153 "src/parser.y"
                      {
        //SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        //$$ = new PrimaryExp(se,$2);
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 1434 "src/parser.cpp"
    break;

  case 30: /* AddExp: MulExp  */
#line 161 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1440 "src/parser.cpp"
    break;

  case 31: /* AddExp: AddExp ADD MulExp  */
#line 164 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1449 "src/parser.cpp"
    break;

  case 32: /* AddExp: AddExp SUB MulExp  */
#line 170 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1458 "src/parser.cpp"
    break;

  case 33: /* MulExp: UnaryExp  */
#line 177 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1464 "src/parser.cpp"
    break;

  case 34: /* MulExp: MulExp MUL UnaryExp  */
#line 180 "src/parser.y"
    {
        SymbolEntry *se=new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1473 "src/parser.cpp"
    break;

  case 35: /* MulExp: MulExp DIV UnaryExp  */
#line 186 "src/parser.y"
    {
        SymbolEntry *se=new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1482 "src/parser.cpp"
    break;

  case 36: /* MulExp: MulExp MOD UnaryExp  */
#line 192 "src/parser.y"
    {
        SymbolEntry *se=new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1491 "src/parser.cpp"
    break;

  case 37: /* UnaryExp: PrimaryExp  */
#line 199 "src/parser.y"
              {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1497 "src/parser.cpp"
    break;

  case 38: /* UnaryExp: FuncUseExp  */
#line 201 "src/parser.y"
              {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1503 "src/parser.cpp"
    break;

  case 39: /* UnaryExp: SUB UnaryExp  */
#line 204 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se,UnaryExpr::UMINUS,(yyvsp[0].exprtype));
    }
#line 1512 "src/parser.cpp"
    break;

  case 40: /* UnaryExp: ADD UnaryExp  */
#line 210 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se,UnaryExpr::UPLUS,(yyvsp[0].exprtype));
    }
#line 1521 "src/parser.cpp"
    break;

  case 41: /* UnaryExp: NOT UnaryExp  */
#line 216 "src/parser.y"
    {
         SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
         (yyval.exprtype) = new UnaryExpr(se,UnaryExpr::NOT,(yyvsp[0].exprtype));
    }
#line 1530 "src/parser.cpp"
    break;

  case 42: /* FuncUseExp: LVal LPAREN FuncRParams RPAREN  */
#line 224 "src/parser.y"
    {
        //$1->
        //identifiers->lookup()
        SymbolEntry *se=new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
        (yyval.exprtype)=new FuncUseExpr(se,(yyvsp[-3].exprtype),(yyvsp[-1].exprtype));
    }
#line 1541 "src/parser.cpp"
    break;

  case 43: /* FuncUseExp: LVal LPAREN RPAREN  */
#line 232 "src/parser.y"
    {
        SymbolEntry *se=new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
        (yyval.exprtype)=new FuncUseExpr(se,(yyvsp[-2].exprtype));
    }
#line 1550 "src/parser.cpp"
    break;

  case 44: /* FuncRParams: Exp  */
#line 240 "src/parser.y"
    {
        (yyval.exprtype)=(yyvsp[0].exprtype);
    }
#line 1558 "src/parser.cpp"
    break;

  case 45: /* FuncRParams: FuncRParams COMMA Exp  */
#line 245 "src/parser.y"
    {
         SymbolEntry *se=new TemporarySymbolEntry(TypeSystem::intType,SymbolTable::getLabel());
         (yyval.exprtype)=new FuncRParams(se,(yyvsp[0].exprtype),(yyvsp[-2].exprtype));
    }
#line 1567 "src/parser.cpp"
    break;

  case 46: /* RelExp: AddExp  */
#line 252 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1573 "src/parser.cpp"
    break;

  case 47: /* RelExp: RelExp LESS AddExp  */
#line 255 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1582 "src/parser.cpp"
    break;

  case 48: /* RelExp: RelExp GREATER AddExp  */
#line 261 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1591 "src/parser.cpp"
    break;

  case 49: /* RelExp: RelExp LESSEQ AddExp  */
#line 267 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESSEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1600 "src/parser.cpp"
    break;

  case 50: /* RelExp: RelExp GREATEREQ AddExp  */
#line 273 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATEREQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1609 "src/parser.cpp"
    break;

  case 51: /* RelExp: RelExp NOTEQ AddExp  */
#line 279 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NOTEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1618 "src/parser.cpp"
    break;

  case 52: /* RelExp: RelExp EQUAL AddExp  */
#line 285 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1627 "src/parser.cpp"
    break;

  case 53: /* LAndExp: RelExp  */
#line 292 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1633 "src/parser.cpp"
    break;

  case 54: /* LAndExp: LAndExp AND RelExp  */
#line 295 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1642 "src/parser.cpp"
    break;

  case 55: /* LOrExp: LAndExp  */
#line 302 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1648 "src/parser.cpp"
    break;

  case 56: /* LOrExp: LOrExp OR LAndExp  */
#line 305 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1657 "src/parser.cpp"
    break;

  case 57: /* Type: INT  */
#line 311 "src/parser.y"
          {
        (yyval.type) = TypeSystem::intType;
    }
#line 1665 "src/parser.cpp"
    break;

  case 58: /* Type: VOID  */
#line 314 "src/parser.y"
           {
        (yyval.type) = TypeSystem::voidType;
    }
#line 1673 "src/parser.cpp"
    break;

  case 59: /* Type: CONST INT  */
#line 317 "src/parser.y"
                {
		(yyval.type) = TypeSystem::intType;
	}
#line 1681 "src/parser.cpp"
    break;

  case 60: /* IDListEle: ID ASSIGN Exp  */
#line 337 "src/parser.y"
                     {
		(yyval.idlistelement) = new IDListElement((yyvsp[-2].strtype),(yyvsp[0].exprtype));
	}
#line 1689 "src/parser.cpp"
    break;

  case 61: /* IDListEle: ID  */
#line 340 "src/parser.y"
           {
		(yyval.idlistelement) = new IDListElement((yyvsp[0].strtype),nullptr);
	}
#line 1697 "src/parser.cpp"
    break;

  case 62: /* IDList: IDListEle  */
#line 346 "src/parser.y"
                 {
		(yyval.idlist)=new IDList;
		(yyval.idlist)->insert((yyvsp[0].idlistelement));
	}
#line 1706 "src/parser.cpp"
    break;

  case 63: /* IDList: IDListEle COMMA IDList  */
#line 350 "src/parser.y"
                               {
		(yyval.idlist)=(yyvsp[0].idlist);
		(yyval.idlist)->insert((yyvsp[-2].idlistelement));
	}
#line 1715 "src/parser.cpp"
    break;

  case 64: /* IDListDeclStmt: Type IDList SEMICOLON  */
#line 358 "src/parser.y"
                             {
		//遍历List并设置Type
		std::vector<IDListElement *>l = (yyvsp[-1].idlist)->list;
        IdentifierSymbolEntry *se;
        StmtNode *prestmt;
		for(int i=0;i<(int)l.size();i++){
			se = new IdentifierSymbolEntry((yyvsp[-2].type),l[i]->getName(),identifiers->getLevel());
			identifiers->install(l[i]->getName(),se);

            StmtNode *pretmp = new DeclStmt(new Id(se));
			if(l[i]->isInit()){
				pretmp = new SeqNode(
					pretmp,
					new AssignStmt(
						new Id(se),l[i]->getExpr()
					)
				);
			}
            if(se->isGlobal()){
                if(l[i]->isInit())  se->setValue(l[i]->getExpr()->getValue());
                else se->setValue(0);
                unit.insertGlobal(se);
            }
			if(i==0)prestmt = pretmp;
            else    prestmt = new SeqNode(prestmt,pretmp);
		}
		(yyval.stmttype) = (StmtNode *)prestmt;
	}
#line 1748 "src/parser.cpp"
    break;

  case 65: /* ParamList: Type ID  */
#line 390 "src/parser.y"
               {
		(yyval.paramlist) = new std::vector<std::pair<Type*,std::string>>;
		(yyval.paramlist)->push_back(std::make_pair((yyvsp[-1].type),(yyvsp[0].strtype)));
	}
#line 1757 "src/parser.cpp"
    break;

  case 66: /* ParamList: Type ID COMMA ParamList  */
#line 394 "src/parser.y"
                                {
		(yyval.paramlist) = (yyvsp[0].paramlist);
		(yyval.paramlist)->push_back(std::make_pair((yyvsp[-3].type),(yyvsp[-2].strtype)));
	}
#line 1766 "src/parser.cpp"
    break;

  case 67: /* $@2: %empty  */
#line 403 "src/parser.y"
        {

        Type *funcType;
        funcType = new FunctionType((yyvsp[-3].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        identifiers = new SymbolTable(identifiers);

    }
#line 1780 "src/parser.cpp"
    break;

  case 68: /* FuncDef: Type ID LPAREN RPAREN $@2 BlockStmt  */
#line 413 "src/parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-4].strtype));
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se, (yyvsp[0].stmttype),{});
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-4].strtype);
    }
#line 1795 "src/parser.cpp"
    break;

  case 69: /* $@3: %empty  */
#line 424 "src/parser.y"
                            {

        Type *funcType;

		std::vector<std::pair<Type*,std::string>> l = *(yyvsp[0].paramlist);
		std::vector<Type* > *tl = new std::vector<Type*>;
		for(int i=0;i<(int)l.size();i++)
		{
			tl->push_back(l[i].first);
		}
        funcType = new FunctionType((yyvsp[-3].type),*tl);

		SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        identifiers = new SymbolTable(identifiers);
		for(int i=0;i<(int)l.size();i++){
			IdentifierSymbolEntry *param = new IdentifierSymbolEntry(l[i].first,l[i].second,identifiers->getLevel());
			funcSEList.push_back(param);
        	identifiers->install(l[i].second, param);
		}

    }
#line 1822 "src/parser.cpp"
    break;

  case 70: /* FuncDef: Type ID LPAREN ParamList $@3 RPAREN BlockStmt  */
#line 448 "src/parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-5].strtype));
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se, (yyvsp[0].stmttype),(*(yyvsp[-3].paramlist)));
	dynamic_cast<FunctionDef*>((yyval.stmttype))->seList=funcSEList;
	funcSEList.clear();
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-5].strtype);
	}
#line 1839 "src/parser.cpp"
    break;


#line 1843 "src/parser.cpp"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 461 "src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
