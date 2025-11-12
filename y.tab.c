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
#line 1 "exptree.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include "reghandling.h"
    #include "AST.h"
    #include "evaluator.h"
    #include "global_symbol_table.h"
    #include "local_symbol_table.h"
    #include "dim_node.h"
    #include "param_list.h"
    #include "tree_visualization.h"
    #include "type_table.h"
    #include "exptree.h"
    #include "class_table.h"
    #include "./TreeViz/tree_viz.h"

    extern int yylex();
    extern FILE *yyin;
    extern int yylineno;
    extern char *yytext;
    void yyerror(const char* s,...);
    struct tnode* head = NULL;
    FILE* fptr = NULL;
    void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType);
    Classtable* Cptr = NULL;
    Fieldlist* curr_type1 = NULL;
    int is_declaration_done = 0;
    

#line 102 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    WRITE = 258,
    READ = 259,
    INT = 260,
    STR = 261,
    ID = 262,
    NUM = 263,
    NILL = 264,
    SELF = 265,
    STRING = 266,
    begin = 267,
    end = 268,
    MAIN = 269,
    DECL = 270,
    ENDDECL = 271,
    TYPE = 272,
    ENDTYPE = 273,
    TUPLE = 274,
    STRUCT = 275,
    CLASS = 276,
    ENDCLASS = 277,
    EXTENDS = 278,
    NEW = 279,
    DELETE = 280,
    PLUS = 281,
    MINUS = 282,
    DIV = 283,
    MUL = 284,
    ARROW = 285,
    IF = 286,
    THEN = 287,
    ELSE = 288,
    ENDIF = 289,
    WHILE = 290,
    DO = 291,
    ENDWHILE = 292,
    REPEAT = 293,
    UNTIL = 294,
    CONTINUE = 295,
    BREAK = 296,
    RETURN = 297,
    BREAKPOINT = 298,
    FREE = 299,
    ALLOC = 300,
    INITIALIZE = 301,
    GT = 302,
    GE = 303,
    LT = 304,
    LE = 305,
    NE = 306,
    EQ = 307,
    AND = 308,
    OR = 309,
    MOD = 310
  };
#endif
/* Tokens.  */
#define WRITE 258
#define READ 259
#define INT 260
#define STR 261
#define ID 262
#define NUM 263
#define NILL 264
#define SELF 265
#define STRING 266
#define begin 267
#define end 268
#define MAIN 269
#define DECL 270
#define ENDDECL 271
#define TYPE 272
#define ENDTYPE 273
#define TUPLE 274
#define STRUCT 275
#define CLASS 276
#define ENDCLASS 277
#define EXTENDS 278
#define NEW 279
#define DELETE 280
#define PLUS 281
#define MINUS 282
#define DIV 283
#define MUL 284
#define ARROW 285
#define IF 286
#define THEN 287
#define ELSE 288
#define ENDIF 289
#define WHILE 290
#define DO 291
#define ENDWHILE 292
#define REPEAT 293
#define UNTIL 294
#define CONTINUE 295
#define BREAK 296
#define RETURN 297
#define BREAKPOINT 298
#define FREE 299
#define ALLOC 300
#define INITIALIZE 301
#define GT 302
#define GE 303
#define LT 304
#define LE 305
#define NE 306
#define EQ 307
#define AND 308
#define OR 309
#define MOD 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "exptree.y"

    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;
    struct Fieldlist* type;

#line 275 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   837

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  364

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


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
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
      58,    59,     2,     2,    57,     2,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
       2,    65,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    71,    72,    75,    84,    92,    93,    96,
     123,   126,   129,   141,   147,   155,   166,   170,   175,   176,
     179,   183,   189,   196,   199,   201,   212,   213,   215,   216,
     219,   227,   231,   238,   253,   254,   257,   264,   265,   268,
     275,   276,   280,   298,   323,   344,   345,   348,   353,   360,
     374,   385,   397,   400,   410,   415,   424,   435,   438,   451,
     456,   474,   478,   483,   486,   494,   503,   504,   510,   545,
     547,   551,   556,   560,   561,   573,   576,   579,   586,   594,
     599,   604,   621,   627,   651,   663,   682,   698,   731,   747,
     758,   772,   783,   787,   817,   840,   850,   864,   865,   866,
     867,   868,   869,   870,   871,   872,   873,   874,   877,   880,
     885,   890,   895,   900,   903,   906,   912,   917,   924,   930,
     936,   942,   948,   951,   956,   961,   966,   971,   980,   989,
     993,   997,  1000,  1003,  1006,  1031,  1049,  1064,  1081,  1094,
    1108,  1113,  1118,  1124,  1128,  1134,  1161,  1180
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WRITE", "READ", "INT", "STR", "ID",
  "NUM", "NILL", "SELF", "STRING", "begin", "end", "MAIN", "DECL",
  "ENDDECL", "TYPE", "ENDTYPE", "TUPLE", "STRUCT", "CLASS", "ENDCLASS",
  "EXTENDS", "NEW", "DELETE", "PLUS", "MINUS", "DIV", "MUL", "ARROW", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL",
  "CONTINUE", "BREAK", "RETURN", "BREAKPOINT", "FREE", "ALLOC",
  "INITIALIZE", "GT", "GE", "LT", "LE", "NE", "EQ", "AND", "OR", "MOD",
  "';'", "','", "'('", "')'", "'{'", "'}'", "'.'", "'['", "']'", "'='",
  "'&'", "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl",
  "GidList", "Gid", "TDeclBlock", "TDeclList", "TDeclStart", "TDecl",
  "TIdList", "TIdDecl", "ClassDefBlock", "ClassDefList", "Classdef",
  "ClassdeclList", "Cname", "Fieldlists", "Fld", "MethodDecl", "MDecl",
  "MethodDefns", "FieldFunction", "FDefBlock", "Fdef", "ParamdeclBlock",
  "Paramlist", "ParamDecl", "Param", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "IdDecl", "ArgList", "MainBlock", "body", "Slist", "Type",
  "DimList", "InputStmt", "OutputStmt", "AsgStmt", "Allocstmnt", "Stmt",
  "Ifstmt", "Whilestmt", "DoWhilestmt", "RepeatUntiltstmt", "Jumpstmt",
  "Debugstmt", "E", "DimAccess", "Field", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    59,    44,    40,    41,
     123,   125,    46,    91,    93,    61,    38
};
# endif

#define YYPACT_NINF (-218)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,   266,    12,   164,    26,    52,    58,   -17,  -218,  -218,
    -218,  -218,  -218,    81,   157,  -218,   196,  -218,  -218,  -218,
    -218,   221,   206,  -218,   145,  -218,   174,   183,   221,   210,
     207,  -218,   242,   259,  -218,  -218,   258,  -218,   208,  -218,
      72,   221,  -218,  -218,    53,   216,     4,  -218,  -218,  -218,
    -218,  -218,   223,   287,   232,  -218,  -218,  -218,   237,   289,
     238,   241,  -218,   283,   221,   221,   239,   243,  -218,    72,
     221,   248,   285,  -218,   221,  -218,   221,  -218,   301,   253,
     256,  -218,   114,   306,   221,  -218,   260,   221,   221,   305,
      13,  -218,   115,  -218,   320,    84,  -218,   221,  -218,   321,
    -218,   268,   271,   273,   275,   225,  -218,   139,   408,   276,
    -218,  -218,   291,  -218,   221,  -218,  -218,  -218,  -218,   285,
     290,  -218,  -218,  -218,   338,   235,  -218,   294,   295,    -9,
     293,   298,   350,   302,   303,   408,   408,   307,   308,    15,
     309,   304,   312,   310,   280,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,   -48,  -218,   299,   305,
     285,  -218,  -218,   139,    15,   144,   352,   365,    15,   121,
     179,   369,   188,   313,    15,    15,   428,   300,  -218,  -218,
      31,  -218,  -218,  -218,   375,   370,    15,   384,  -218,   650,
     330,  -218,   190,   335,  -218,  -218,  -218,   389,   167,   341,
     340,   305,  -218,   509,    36,   347,   396,   149,   348,   356,
     449,   358,   359,   660,    15,    15,   361,   161,   193,    15,
     522,   556,   362,   363,   415,    15,   360,  -218,  -218,   569,
    -218,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,  -218,   195,   197,   368,   367,   371,
     372,   691,  -218,  -218,   366,   378,   419,   380,   421,    43,
     433,   382,   386,   438,    15,    15,  -218,   440,   397,  -218,
     479,   701,    15,   399,   402,   732,   429,   424,    15,    15,
    -218,   127,   773,  -218,     3,     3,  -218,  -218,    98,    98,
      98,    98,   154,   154,   782,   110,  -218,   406,   409,  -218,
      15,   460,   414,  -218,  -218,  -218,   420,  -218,  -218,   425,
    -218,   426,  -218,  -218,   742,   191,   427,   431,  -218,  -218,
     201,  -218,  -218,  -218,   408,   408,   603,   616,    15,  -218,
    -218,  -218,   205,   430,   432,   434,  -218,  -218,  -218,  -218,
     435,  -218,  -218,   236,   344,   -21,   436,   773,  -218,   437,
    -218,  -218,  -218,   408,   439,   453,  -218,  -218,  -218,   364,
    -218,  -218,   454,  -218
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,     0,     0,     0,     0,     0,     0,     0,    19,     1,
      72,    73,    74,     0,     0,     4,     0,    20,    21,    16,
      18,     0,    32,    27,     0,    29,     0,     0,     0,     0,
       0,    24,     0,     0,    26,    28,     0,     6,     0,     8,
       0,     0,    46,     3,     0,     0,     0,    25,    33,    35,
       5,     7,    76,     0,     0,    11,    45,     2,     0,     0,
       0,     0,    23,     0,     0,    52,    12,    13,     9,     0,
      52,     0,    57,    22,     0,    34,    31,    38,     0,     0,
      49,    51,     0,     0,    52,    10,     0,    52,     0,     0,
       0,    41,     0,    37,     0,     0,    14,     0,    54,     0,
      53,     0,     0,     0,     0,     0,    59,     0,     0,     0,
      30,    40,     0,    36,    52,    50,    55,    75,    15,    57,
       0,    56,    58,    63,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   106,    71,
     100,   101,   102,   103,   104,   105,     0,    68,     0,     0,
      57,    64,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   114,
     136,   141,   131,   140,     0,     0,     0,     0,   133,     0,
     132,   116,     0,     0,   107,    69,    70,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,   146,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,    67,   137,   142,   138,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,     0,     0,     0,   145,     0,
       0,     0,    39,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,   144,     0,     0,    83,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
     134,     0,    66,   122,   117,   118,   119,   120,   123,   125,
     124,   126,   127,   128,   129,   130,   121,     0,     0,    92,
      67,     0,     0,    86,    48,    82,     0,    77,   146,     0,
     147,     0,    80,   145,     0,     0,     0,     0,   143,    84,
       0,    95,    96,    85,     0,     0,     0,     0,     0,   135,
      90,    91,     0,     0,     0,     0,    78,    79,    87,    43,
       0,    88,    42,     0,     0,     0,     0,    65,    44,     0,
      89,    81,    93,     0,     0,     0,   111,   112,    94,     0,
     109,   110,     0,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,  -218,  -218,   442,  -218,   416,  -218,  -218,  -218,
     477,  -218,   448,  -218,  -218,   487,  -218,  -218,  -218,  -218,
    -218,   441,  -218,  -106,  -218,   -40,    20,  -218,   387,  -218,
    -111,  -218,   407,  -218,   351,  -217,    44,  -154,  -132,    59,
    -218,  -218,  -218,  -218,  -218,  -137,  -218,  -218,  -218,  -218,
    -218,  -218,  -123,  -167,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    28,    38,    39,    54,    55,     3,     6,     7,
       8,    30,    31,    14,    24,    25,    63,    26,    64,    75,
      76,    77,    90,   188,    41,    42,    79,    80,    81,   100,
      89,   105,   106,   125,   126,   281,    15,   109,   144,    82,
      66,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   282,   170,   190
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     156,    56,   143,   176,   177,   200,     1,   196,   159,    10,
      11,    12,     9,   226,   197,   325,   189,   198,    10,    11,
      12,   166,   180,   181,   182,   130,   183,   156,   156,   143,
     143,   233,   234,    17,    91,   356,   156,   259,   143,   196,
     196,   203,   184,    21,   185,   210,   213,   254,   315,   201,
     111,   220,   221,   167,   168,   320,   169,   207,   243,    18,
      58,   224,    16,   229,   218,    61,   256,    29,   156,   156,
     143,   143,    43,   186,   110,   251,    19,     4,     5,    52,
      32,   187,    59,   332,   246,    57,    40,    44,    22,   225,
      86,   270,   271,   167,   168,   257,   275,    40,   258,   168,
      44,    53,   309,    23,   102,    32,   214,   104,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,    98,    58,    78,   231,   232,   233,   234,   180,   181,
     182,   130,   183,    92,   158,    94,   231,   232,   233,   234,
     113,   314,   114,    99,    59,   211,   123,   107,   184,    92,
     185,   204,    22,   243,   205,   326,   327,   235,   236,   237,
     238,   239,   240,   241,   107,   243,   212,    34,   124,    10,
      11,    12,    27,   206,   180,   181,   182,   130,   183,   186,
     231,   232,   233,   234,   328,    13,   329,   187,    10,    11,
      12,   249,   343,   344,   184,   217,   185,   245,   205,    37,
     205,   235,   236,   237,   238,   347,   196,   196,   262,   243,
      29,   263,   250,    10,    11,    12,   156,   156,   143,   143,
     273,   359,   196,   258,    50,   186,    10,    11,    12,    33,
      10,    11,    12,   187,    36,   156,   156,   143,   143,   127,
     128,   121,   214,   129,   215,   156,   130,   143,   328,    47,
     339,   156,   274,   143,   297,   263,   298,   258,   328,   263,
     342,   131,   328,    46,   348,   132,    48,   133,    45,   353,
     354,   134,   135,    49,   136,    60,   137,   138,   139,   140,
     141,    65,   142,   127,   128,     4,     5,   129,    68,    69,
     130,   162,   163,   195,    67,    70,    71,    73,    72,    74,
      88,    84,    83,   127,   128,   131,    87,   129,    95,   132,
     130,   133,    96,    97,   101,   134,   135,   108,   136,   103,
     137,   138,   139,   140,   141,   131,   142,   112,   116,   132,
     118,   133,   117,   119,   120,   134,   135,   157,   136,   223,
     137,   138,   139,   140,   141,   161,   142,   127,   128,   114,
     160,   129,   164,   165,   130,   171,   172,   173,   199,   208,
     174,   175,   192,   178,   179,   191,   194,   127,   128,   131,
     193,   129,   209,   132,   130,   133,   216,   228,   219,   134,
     135,   355,   136,   227,   137,   138,   139,   140,   141,   131,
     142,   230,   197,   132,   247,   133,   248,   252,   362,   134,
     135,   253,   136,   261,   137,   138,   139,   140,   141,   260,
     142,   127,   128,   264,   265,   129,   267,   268,   130,   272,
     278,   279,   280,   214,   299,   300,   306,   304,   308,   301,
     302,   127,   128,   131,   305,   129,   307,   132,   130,   133,
     310,   311,   312,   134,   135,   313,   136,   316,   137,   138,
     139,   140,   141,   131,   142,   321,   317,   132,   322,   133,
     325,   324,   330,   222,   135,   331,   136,   333,   137,   138,
     139,   140,   141,   334,   142,   231,   232,   233,   234,   335,
      51,   336,   337,    20,   115,    85,   340,   341,   350,   349,
     351,   352,   357,   358,    62,   360,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   231,   232,   233,   234,   361,
     363,    35,   122,   266,   202,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   231,   232,   233,   234,     0,
       0,     0,     0,   318,     0,     0,     0,     0,   231,   232,
     233,   234,     0,     0,     0,     0,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,   255,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,   276,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,   232,   233,   234,     0,
       0,     0,     0,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,   277,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,   283,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   232,   233,   234,     0,     0,     0,     0,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,     0,   345,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,   346,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   269,   231,   232,   233,
     234,     0,     0,     0,     0,     0,     0,   231,   232,   233,
     234,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   303,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   319,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   323,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   338,   231,
     232,   233,   234,     0,     0,     0,     0,     0,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   235,
     236,   237,   238,   239,   240,     0,     0,   243
};

static const yytype_int16 yycheck[] =
{
     108,    41,   108,   135,   136,   159,    17,   144,   119,     5,
       6,     7,     0,   180,    62,    36,   139,    65,     5,     6,
       7,    30,     7,     8,     9,    10,    11,   135,   136,   135,
     136,    28,    29,     7,    74,    56,   144,   204,   144,   176,
     177,   164,    27,    60,    29,   168,   169,   201,   265,   160,
      90,   174,   175,    62,    63,   272,    65,   165,    55,     7,
       7,    30,     3,   186,   172,    61,    30,    14,   176,   177,
     176,   177,    28,    58,    61,   198,    18,    19,    20,     7,
      21,    66,    29,   300,   192,    41,    27,    28,     7,    58,
      70,   214,   215,    62,    63,    59,   219,    38,    62,    63,
      41,    29,    59,    22,    84,    46,    63,    87,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     7,     7,    64,    26,    27,    28,    29,     7,     8,
       9,    10,    11,    74,   114,    76,    26,    27,    28,    29,
      56,   264,    58,    29,    29,    24,     7,    88,    27,    90,
      29,     7,     7,    55,    10,   278,   279,    47,    48,    49,
      50,    51,    52,    53,   105,    55,    45,    22,    29,     5,
       6,     7,    15,    29,     7,     8,     9,    10,    11,    58,
      26,    27,    28,    29,    57,    21,    59,    66,     5,     6,
       7,    24,   324,   325,    27,     7,    29,     7,    10,    16,
      10,    47,    48,    49,    50,   328,   343,   344,    59,    55,
      14,    62,    45,     5,     6,     7,   324,   325,   324,   325,
      59,   353,   359,    62,    16,    58,     5,     6,     7,    23,
       5,     6,     7,    66,    60,   343,   344,   343,   344,     3,
       4,    16,    63,     7,    65,   353,    10,   353,    57,     7,
      59,   359,    59,   359,    59,    62,    59,    62,    57,    62,
      59,    25,    57,    56,    59,    29,     7,    31,    58,    33,
      34,    35,    36,    15,    38,    59,    40,    41,    42,    43,
      44,    58,    46,     3,     4,    19,    20,     7,    56,    57,
      10,    56,    57,    13,     7,    58,     7,    56,    60,    16,
      15,    58,    63,     3,     4,    25,    58,     7,     7,    29,
      10,    31,    59,    57,     8,    35,    36,    12,    38,    59,
      40,    41,    42,    43,    44,    25,    46,     7,     7,    29,
      59,    31,    64,    60,    59,    35,    36,    61,    38,    39,
      40,    41,    42,    43,    44,     7,    46,     3,     4,    58,
      60,     7,    58,    58,    10,    62,    58,     7,    59,     7,
      58,    58,    58,    56,    56,    56,    56,     3,     4,    25,
      58,     7,     7,    29,    10,    31,     7,     7,    65,    35,
      36,    37,    38,     8,    40,    41,    42,    43,    44,    25,
      46,     7,    62,    29,    59,    31,     7,    56,    34,    35,
      36,    61,    38,     7,    40,    41,    42,    43,    44,    62,
      46,     3,     4,    65,    58,     7,    58,    58,    10,    58,
      58,    58,     7,    63,    56,    58,     7,    61,     7,    58,
      58,     3,     4,    25,    56,     7,    56,    29,    10,    31,
       7,    59,    56,    35,    36,     7,    38,     7,    40,    41,
      42,    43,    44,    25,    46,    56,    59,    29,    56,    31,
      36,    32,    56,    35,    36,    56,    38,     7,    40,    41,
      42,    43,    44,    59,    46,    26,    27,    28,    29,    59,
      38,    56,    56,     6,    97,    69,    59,    56,    56,    59,
      56,    56,    56,    56,    46,    56,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    26,    27,    28,    29,    56,
      56,    24,   105,    64,   163,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    17,    68,    74,    19,    20,    75,    76,    77,     0,
       5,     6,     7,    21,    80,   103,   106,     7,     7,    18,
      77,    60,     7,    22,    81,    82,    84,    15,    69,    14,
      78,    79,   106,    23,    22,    82,    60,    16,    70,    71,
     106,    91,    92,   103,   106,    58,    56,     7,     7,    15,
      16,    71,     7,    29,    72,    73,    92,   103,     7,    29,
      59,    61,    79,    83,    85,    58,   107,     7,    56,    57,
      58,     7,    60,    56,    16,    86,    87,    88,   106,    93,
      94,    95,   106,    63,    58,    73,    93,    58,    15,    97,
      89,    92,   106,    88,   106,     7,    59,    57,     7,    29,
      96,     8,    93,    59,    93,    98,    99,   106,    12,   104,
      61,    92,     7,    56,    58,    95,     7,    64,    59,    60,
      59,    16,    99,     7,    29,   100,   101,     3,     4,     7,
      10,    25,    29,    31,    35,    36,    38,    40,    41,    42,
      43,    44,    46,    90,   105,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   121,    61,    93,    97,
      60,     7,    56,    57,    58,    58,    30,    62,    63,    65,
     120,    62,    58,     7,    58,    58,   105,   105,    56,    56,
       7,     8,     9,    11,    27,    29,    58,    66,    90,   119,
     121,    56,    58,    58,    56,    13,   112,    62,    65,    59,
     104,    97,   101,   119,     7,    10,    29,   121,     7,     7,
     119,    24,    45,   119,    63,    65,     7,     7,   121,    65,
     119,   119,    35,    39,    30,    58,   120,     8,     7,   119,
       7,    26,    27,    28,    29,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     7,   121,    59,     7,    24,
      45,   119,    56,    61,   104,    59,    30,    59,    62,   120,
      62,     7,    59,    62,    65,    58,    64,    58,    58,    56,
     119,   119,    58,    59,    59,   119,    59,    59,    58,    58,
       7,   102,   119,    59,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,    59,    59,    56,
      58,    58,    58,    56,    61,    56,     7,    56,     7,    59,
       7,    59,    56,     7,   119,   102,     7,    59,    64,    56,
     102,    56,    56,    56,    32,    36,   119,   119,    57,    59,
      56,    56,   102,     7,    59,    59,    56,    56,    56,    59,
      59,    56,    59,   105,   105,    59,    59,   119,    59,    59,
      56,    56,    56,    33,    34,    37,    56,    56,    56,   105,
      56,    56,    34,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    83,    84,    84,    85,    85,    86,    87,    87,    88,
      89,    89,    90,    90,    90,    91,    91,    92,    92,    93,
      94,    94,    94,    95,    96,    96,    97,    97,    98,    98,
      99,   100,   100,   101,   101,   102,   102,   102,   103,   104,
     105,   105,   106,   106,   106,   107,   107,   108,   108,   108,
     108,   108,   109,   110,   110,   110,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   115,   116,   117,   117,   117,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     3,     2,     2,     1,     3,
       3,     1,     2,     2,     4,     5,     3,     0,     2,     1,
       2,     2,     6,     3,     1,     2,     3,     2,     2,     1,
       7,     2,     1,     3,     2,     0,     3,     2,     1,     6,
       2,     1,     6,     6,     6,     2,     1,     9,    10,     1,
       3,     1,     0,     2,     1,     2,     3,     0,     2,     1,
       3,     3,     1,     1,     2,     3,     1,     0,     8,     3,
       2,     1,     1,     1,     1,     4,     0,     5,     6,     6,
       5,     7,     5,     4,     5,     5,     4,     6,     6,     6,
       5,     5,     4,     7,     7,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,    10,     8,
       8,     7,     7,     2,     2,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     4,     1,     2,     2,     2,
       1,     1,     2,     4,     3,     3,     3,     3
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 70 "exptree.y"
                                                                  {}
#line 1903 "y.tab.c"
    break;

  case 3:
#line 71 "exptree.y"
                                                        {}
#line 1909 "y.tab.c"
    break;

  case 4:
#line 72 "exptree.y"
                               {}
#line 1915 "y.tab.c"
    break;

  case 5:
#line 75 "exptree.y"
                                     {
                stack_address = curr_stack_address;
                setup_pointers_codegen(fptr,top,NULL);
                is_global_vars_declared = 1;
                is_declaration_done = 1;
                print_gsymbol_table();
                printf("------Global Variables Declared-----\n");
                // driver_codegen(fptr);
            }
#line 1929 "y.tab.c"
    break;

  case 6:
#line 84 "exptree.y"
                           {
                stack_address = curr_stack_address;
                is_global_vars_declared = 1;
                is_declaration_done = 1;
                
            }
#line 1940 "y.tab.c"
    break;

  case 7:
#line 92 "exptree.y"
                              {}
#line 1946 "y.tab.c"
    break;

  case 8:
#line 93 "exptree.y"
                   {}
#line 1952 "y.tab.c"
    break;

  case 9:
#line 96 "exptree.y"
                           {
            Gsymbol* temp = (yyvsp[-1].gsymbol);
            Gsymbol* temp1 = (yyvsp[-1].gsymbol);
            while(temp){
                temp1 = temp->next;
                temp->next = NULL;
                temp->typeEntry = (yyvsp[-2].type)->Type;
                temp->centry = (yyvsp[-2].type)->Ctype;
                int type = (yyvsp[-2].type)->Type ? (yyvsp[-2].type)->Type->type : TYPE_CLASS;
                if(type == TYPE_TUPLE && temp->varType != TYPE_ARR){
                    temp->size = (yyvsp[-2].type)->Type->size;
                }else if(type == TYPE_CLASS){
                    temp->size = (yyvsp[-2].type)->Ctype->Fieldcount + (yyvsp[-2].type)->Ctype->Methodcount;
                }
                if(temp->varType == TYPE_FUNCT_PTR)temp->size = 1;
                if(type == TYPE_TUPLE && temp->varType == TYPE_PTR){
                    temp->size++;
                }
                
                add_gsymbol(temp,type);
                
                temp->type = type;
                temp = temp1;
            }
        }
#line 1982 "y.tab.c"
    break;

  case 10:
#line 123 "exptree.y"
                         {
            (yyval.gsymbol) = append_gsymbol_id_list((yyvsp[-2].gsymbol),(yyvsp[0].gsymbol));    
        }
#line 1990 "y.tab.c"
    break;

  case 11:
#line 126 "exptree.y"
              { (yyval.gsymbol) = (yyvsp[0].gsymbol);}
#line 1996 "y.tab.c"
    break;

  case 12:
#line 129 "exptree.y"
                     {
            Gsymbol* temp = create_symbol_id_with_dims((yyvsp[-1].node)->varname, (yyvsp[0].DimList));
            (yyvsp[-1].node)->Gentry = temp;
            if((yyvsp[0].DimList)){
                (yyvsp[-1].node)->type = TYPE_ARR;
                (yyvsp[-1].node)->Gentry->varType = TYPE_ARR;
            }else{
                (yyvsp[-1].node)->Gentry->varType = TYPE_VAR;
            }

            (yyval.gsymbol) = temp;
        }
#line 2013 "y.tab.c"
    break;

  case 13:
#line 141 "exptree.y"
                 {
            Gsymbol* temp = create_gsymbol_id((yyvsp[0].node)->varname, 2);
            (yyvsp[0].node)->Gentry = temp;
            temp->varType = TYPE_PTR;
            (yyval.gsymbol) = temp;
        }
#line 2024 "y.tab.c"
    break;

  case 14:
#line 147 "exptree.y"
                                    {
            // int size = get_paramlist_length($3);
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = paramlist_deepcopy((yyvsp[-1].plist));
            temp->varType = TYPE_FUNCT;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 2037 "y.tab.c"
    break;

  case 15:
#line 155 "exptree.y"
                                        {
            // int size = get_paramlist_length($4);
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = paramlist_deepcopy((yyvsp[-1].plist));;
            temp->varType = TYPE_FUNCT_PTR;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 2050 "y.tab.c"
    break;

  case 16:
#line 166 "exptree.y"
                                      {
                // typetable_print(type_table);
                driver_codegen(fptr);
            }
#line 2059 "y.tab.c"
    break;

  case 17:
#line 170 "exptree.y"
                {
                driver_codegen(fptr);
            }
#line 2067 "y.tab.c"
    break;

  case 18:
#line 175 "exptree.y"
                              {}
#line 2073 "y.tab.c"
    break;

  case 19:
#line 176 "exptree.y"
                    {}
#line 2079 "y.tab.c"
    break;

  case 20:
#line 179 "exptree.y"
                       {
                typetable_create((yyvsp[0].node)->varname,TYPE_TUPLE,NULL);
                (yyval.string) = (yyvsp[0].node)->varname;
            }
#line 2088 "y.tab.c"
    break;

  case 21:
#line 183 "exptree.y"
                        {
                typetable_create((yyvsp[0].node)->varname,TYPE_TUPLE,NULL);
                (yyval.string) = (yyvsp[0].node)->varname;
            }
#line 2097 "y.tab.c"
    break;

  case 22:
#line 189 "exptree.y"
                                                 {
                typetable_append_plist((char*) (yyvsp[-5].string), (yyvsp[-3].plist));
                ParamList* temp = (yyvsp[-3].plist);
                
                
            }
#line 2108 "y.tab.c"
    break;

  case 23:
#line 196 "exptree.y"
                                  {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
            }
#line 2116 "y.tab.c"
    break;

  case 24:
#line 199 "exptree.y"
                      { (yyval.plist) = (yyvsp[0].plist); }
#line 2122 "y.tab.c"
    break;

  case 25:
#line 201 "exptree.y"
                      {
                if(!(yyvsp[-1].type)->Type){
                    printf("Error: Not Allowed to Use Classes in struct\n");
                    exit(0);
                }
                (yyval.plist) = create_param((yyvsp[0].node)->varname, (yyvsp[-1].type)->Type ? (yyvsp[-1].type)->Type->type : TYPE_CLASS);
                (yyval.plist)->typeEntry = (yyvsp[-1].type)->Type;
            }
#line 2135 "y.tab.c"
    break;

  case 26:
#line 212 "exptree.y"
                                              {}
#line 2141 "y.tab.c"
    break;

  case 27:
#line 213 "exptree.y"
                                 {}
#line 2147 "y.tab.c"
    break;

  case 30:
#line 219 "exptree.y"
                                                                      {

                    curr_class_table = NULL;
                    Cptr = NULL;
                    is_declaration_done = 0;

                }
#line 2159 "y.tab.c"
    break;

  case 31:
#line 227 "exptree.y"
                                       {is_declaration_done = 1;}
#line 2165 "y.tab.c"
    break;

  case 32:
#line 231 "exptree.y"
                      {
                        if(typetable_lookup((yyvsp[0].node)->varname) != NULL || CLookup((yyvsp[0].node)->varname)){
                            printf("Error: Type already exists\n");
                            exit(0);
                        }
                        Cptr = CInstall((yyvsp[0].node)->varname,NULL); curr_class_table = Cptr;
                }
#line 2177 "y.tab.c"
    break;

  case 33:
#line 238 "exptree.y"
                                {

                    if(CLookup((yyvsp[0].node)->varname) == NULL){
                        printf("Error: Class %s doesnt exist\n",(yyvsp[0].node)->varname);
                        exit(0);
                    }
                    if(typetable_lookup((yyvsp[-2].node)->varname) != NULL || CLookup((yyvsp[-2].node)->varname)){
                            printf("Error: Type already exists\n");
                            exit(0);
                    }

                    Cptr = CInstall((yyvsp[-2].node)->varname,(yyvsp[0].node)->varname); curr_class_table = Cptr;
                }
#line 2195 "y.tab.c"
    break;

  case 36:
#line 257 "exptree.y"
                               {

                    Class_Finstall(Cptr,(yyvsp[-2].type)->Name,(yyvsp[-1].node)->varname);

                }
#line 2205 "y.tab.c"
    break;

  case 39:
#line 268 "exptree.y"
                                                     {
                    Class_Minstall(Cptr,(yyvsp[-4].node)->varname,(yyvsp[-5].type)->Type,(yyvsp[-2].plist));
                    
                    }
#line 2214 "y.tab.c"
    break;

  case 42:
#line 280 "exptree.y"
                                              {

                    if(Cptr == NULL){
                        printf("Error: Not inside a class\n");
                        exit(0);
                    }
                    
                    tnode* t1 = createTree(0,TYPE_FUNCT,(yyvsp[-3].node)->varname,METHODNODE,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
                    t1->centry = Cptr;
                    
                    struct tnode* temp = createTree(0,TYPE_CLASS,(yyvsp[-3].node)->varname,DOTNODE,NULL,(yyvsp[-5].node),NULL,t1);
                    (yyvsp[-5].node)->centry = Cptr;
                    (yyval.node) = temp;
                    temp->centry = Cptr;
                    temp->typeEntry = Class_Mlookup(Cptr, (yyvsp[-3].node)->varname)->Type;
                    t1->typeEntry = temp->typeEntry;

                }
#line 2237 "y.tab.c"
    break;

  case 43:
#line 298 "exptree.y"
                                            {
                    //This will not occur inside a class.
                    Classtable* cls = get_classtable((yyvsp[-5].node)->varname);
                    if(!cls){
                        printf("Error: Not of class type\n");
                        exit(0);
                    }
                    Memberfunclist* func = Class_Mlookup(cls,(yyvsp[-3].node)->varname);
                    
                    if(func == NULL){
                        printf("Error: No method %s in class %s\n", (yyvsp[-3].node)->varname,(yyvsp[-5].node)->varname);
                        exit(0);
                    }
                    TypeTable* type = func->Type;
                    
                    paramlist_is_input_args_correct(func->Paramlist, (yyvsp[-1].node));

                    tnode* t1 = createTree(0,TYPE_FUNCT,(yyvsp[-3].node)->varname,METHODNODE,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
                    t1->centry = cls;
                    t1->typeEntry = type;
                    struct tnode* temp = createTree(0,TYPE_CLASS,"funct",DOTNODE,NULL,(yyvsp[-5].node),NULL,t1);
                    (yyval.node) = temp;
                    (yyval.node)->centry = cls;
                    (yyval.node)->typeEntry = type;
                }
#line 2267 "y.tab.c"
    break;

  case 44:
#line 323 "exptree.y"
                                              {
                    Memberfunclist* func = Class_Mlookup((yyvsp[-5].node)->centry,(yyvsp[-3].node)->varname);
                    if(!(yyvsp[-5].node)->centry){
                        printf("Error: Not of class type\n");
                        exit(0);
                    }
                    paramlist_is_input_args_correct(func->Paramlist, (yyvsp[-1].node));
                    tnode* t1 = createTree(0,TYPE_FUNCT,(yyvsp[-3].node)->varname,METHODNODE,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
                    t1->centry = (yyvsp[-5].node)->centry;
                    struct tnode* temp = createTree(0,TYPE_CLASS,"funct",DOTNODE,NULL,(yyvsp[-5].node),NULL,t1);
                    (yyval.node) = temp;
                    (yyval.node)->typeEntry = Class_Mlookup((yyvsp[-5].node)->centry,(yyvsp[-3].node)->varname)->Type;
                    t1->typeEntry = (yyval.node)->typeEntry;
                    (yyval.node)->centry = NULL;
                }
#line 2287 "y.tab.c"
    break;

  case 45:
#line 344 "exptree.y"
                             {}
#line 2293 "y.tab.c"
    break;

  case 46:
#line 345 "exptree.y"
                   {}
#line 2299 "y.tab.c"
    break;

  case 47:
#line 348 "exptree.y"
                                                                     {    
                
                function_block((yyvsp[-8].type)->Type->type,(yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node),TYPE_FUNCT);

            }
#line 2309 "y.tab.c"
    break;

  case 48:
#line 353 "exptree.y"
                                                                         {
                
                function_block((yyvsp[-9].type)->Type->type, (yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node), TYPE_FUNCT_PTR);

            }
#line 2319 "y.tab.c"
    break;

  case 49:
#line 360 "exptree.y"
                           {

                    (yyval.plist) = (yyvsp[0].plist);
                    if(is_declaration_done == 1){
                        if(curr_lsymbol_table== NULL){
                            curr_lsymbol_table = create_lsymbol_id("self", 1, TYPE_VOID);
                        }else{
                            Lsymbol* t1 = create_lsymbol_id("self", 1, TYPE_VOID);
                            append_lsymbol_id_list(curr_lsymbol_table,t1);
                        }
                    }
                }
#line 2336 "y.tab.c"
    break;

  case 50:
#line 374 "exptree.y"
                                      {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
                if(is_declaration_done == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->varType == TYPE_PTR ? 1 : (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    t1->centry = (yyvsp[0].plist)->centry;
                    curr_lsymbol_table = append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
#line 2352 "y.tab.c"
    break;

  case 51:
#line 385 "exptree.y"
                        {
                (yyval.plist) = (yyvsp[0].plist);
                if(is_declaration_done == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    t1->centry = (yyvsp[0].plist)->centry;

                    curr_lsymbol_table =  append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
                
            }
#line 2369 "y.tab.c"
    break;

  case 52:
#line 397 "exptree.y"
                                            {(yyval.plist) = NULL;curr_lsymbol_table= NULL;}
#line 2375 "y.tab.c"
    break;

  case 53:
#line 400 "exptree.y"
                         {
                (yyvsp[0].plist)->type = (yyvsp[-1].type)->Type ? (yyvsp[-1].type)->Type->type : TYPE_CLASS;
                (yyvsp[0].plist)->centry = (yyvsp[-1].type)->Ctype;
                (yyvsp[0].plist)->typeEntry = (yyvsp[-1].type)->Type;
                (yyvsp[0].plist)->size = (yyvsp[-1].type)->Type ? (yyvsp[-1].type)->Type->size : (yyvsp[-1].type)->Ctype->Fieldcount;
                (yyval.plist) = (yyvsp[0].plist);
                
            }
#line 2388 "y.tab.c"
    break;

  case 54:
#line 410 "exptree.y"
                 {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_VAR;
            }
#line 2398 "y.tab.c"
    break;

  case 55:
#line 415 "exptree.y"
                     {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_PTR;
                
            }
#line 2409 "y.tab.c"
    break;

  case 56:
#line 424 "exptree.y"
                                    {
                Lsymbol* temp = curr_lsymbol_table;
                while(temp && temp->next){
                    temp = temp->next;
                }
                if(temp) temp->next = (yyvsp[-1].lsymbol);
                else curr_lsymbol_table = (yyvsp[-1].lsymbol);
                lst_set_bindings(curr_lsymbol_table);
                
                (yyval.lsymbol) = curr_lsymbol_table;
            }
#line 2425 "y.tab.c"
    break;

  case 57:
#line 435 "exptree.y"
               {(yyval.lsymbol) = NULL;lst_set_bindings(curr_lsymbol_table);}
#line 2431 "y.tab.c"
    break;

  case 58:
#line 438 "exptree.y"
                             {
                Lsymbol* temp = (yyvsp[0].lsymbol);
                while(temp){
                    check_lpresent((yyvsp[-1].lsymbol),temp->name);
                    temp = temp->next;
                }
                temp = (yyvsp[-1].lsymbol);
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = (yyvsp[0].lsymbol);
                (yyval.lsymbol) = (yyvsp[-1].lsymbol);
            }
#line 2449 "y.tab.c"
    break;

  case 59:
#line 451 "exptree.y"
                    {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);   
            }
#line 2457 "y.tab.c"
    break;

  case 60:
#line 456 "exptree.y"
                              {
                Lsymbol* temp = (yyvsp[-1].lsymbol);
                while(temp){
                    temp->type = (yyvsp[-2].type)->Type ? (yyvsp[-2].type)->Type->type : TYPE_CLASS;
                    temp->typeEntry = (yyvsp[-2].type)->Type;
                    temp->centry = (yyvsp[-2].type)->Ctype;
                    if((yyvsp[-2].type)->Ctype != NULL){
                        temp->type = TYPE_CLASS;
                    }else if(temp->typeEntry->type == TYPE_TUPLE){
                        temp->type = TYPE_TUPLE;
                    }
                    temp = temp->next;
                }
                print_lsymbol_table();
                (yyval.lsymbol) = (yyvsp[-1].lsymbol);
            }
#line 2478 "y.tab.c"
    break;

  case 61:
#line 474 "exptree.y"
                                 {
                check_lpresent((yyvsp[-2].lsymbol),(yyvsp[0].lsymbol)->name);
                (yyval.lsymbol) = append_lsymbol_id_list((yyvsp[-2].lsymbol), (yyvsp[0].lsymbol));
            }
#line 2487 "y.tab.c"
    break;

  case 62:
#line 478 "exptree.y"
                     {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);
            }
#line 2495 "y.tab.c"
    break;

  case 63:
#line 483 "exptree.y"
                 {
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, curr_type1->Ctype ? curr_type1->Ctype->Fieldcount : curr_type1->Type->size, TYPE_VAR);
            }
#line 2503 "y.tab.c"
    break;

  case 64:
#line 486 "exptree.y"
                    {
                int size = 2;
                if(curr_type1->Type && curr_type1->Type->type == TYPE_TUPLE){
                    size = 1 + curr_type1->Type->size;
                }else 
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, size, TYPE_PTR);
                printf("ptr name: %s\n",(yyvsp[0].node)->varname);
            }
#line 2516 "y.tab.c"
    break;

  case 65:
#line 494 "exptree.y"
                            {

                tnode* temp = (yyvsp[-2].node);
                while(temp->middle){
                    temp = temp->middle;
                }
                temp->middle = (yyvsp[0].node);
                (yyval.node) = (yyvsp[-2].node);
            }
#line 2530 "y.tab.c"
    break;

  case 66:
#line 503 "exptree.y"
                { (yyval.node) = (yyvsp[0].node);}
#line 2536 "y.tab.c"
    break;

  case 67:
#line 504 "exptree.y"
                          { (yyval.node) = NULL;}
#line 2542 "y.tab.c"
    break;

  case 68:
#line 510 "exptree.y"
                                                      {

        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome
        print_lsymbol_table();

        curr_function_type = (yyvsp[-7].type)->Type;

        tree_visual_printTree((yyvsp[-1].node));
        export_ast_to_graphviz((yyvsp[-1].node),"Main");

        fprintf(fptr, "MAIN:");

        int p = getReg();

        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");

        int curr_offset = get_ltable_length(curr_lsymbol_table);

        if(curr_offset!=0)fprintf(fptr, "ADD SP, %d\n", curr_offset);

        freeReg();

        setup_pointers_codegen(fptr,NULL,curr_lsymbol_table);

        codeGen((yyvsp[-1].node),0,0,fptr);

        // lst_destroy($6);

        curr_lsymbol_table = NULL;
}
#line 2579 "y.tab.c"
    break;

  case 69:
#line 545 "exptree.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2585 "y.tab.c"
    break;

  case 70:
#line 547 "exptree.y"
                     {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,(yyvsp[-1].node), NULL, (yyvsp[0].node));
            (yyval.node) = temp;
        }
#line 2594 "y.tab.c"
    break;

  case 71:
#line 551 "exptree.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2602 "y.tab.c"
    break;

  case 72:
#line 556 "exptree.y"
                  { 
                    (yyval.type) = fieldlist_create("int",NULL,typetable_lookup("int"));
                    curr_type1 = (yyval.type);
            }
#line 2611 "y.tab.c"
    break;

  case 73:
#line 560 "exptree.y"
                  { (yyval.type) = fieldlist_create("str",NULL,typetable_lookup("str"));curr_type1 = (yyval.type); }
#line 2617 "y.tab.c"
    break;

  case 74:
#line 561 "exptree.y"
                 {
                TypeTable* curr_type = typetable_lookup((yyvsp[0].node)->varname);
                Classtable* cls = CLookup((yyvsp[0].node)->varname);
                if(curr_type == NULL && cls == NULL){
                    printf("Error: No UserDefined struct %s exists\n", (yyvsp[0].node)->varname);
                    exit(0); 
                }
                (yyval.type) = fieldlist_create((yyvsp[0].node)->varname,cls,curr_type);
                curr_type1 = (yyval.type);
            }
#line 2632 "y.tab.c"
    break;

  case 75:
#line 573 "exptree.y"
                              {
            (yyval.DimList) = append_dim((yyvsp[-3].DimList), (yyvsp[-1].node)->val);
        }
#line 2640 "y.tab.c"
    break;

  case 76:
#line 576 "exptree.y"
                        { (yyval.DimList) = create_dimlist(NULL); }
#line 2646 "y.tab.c"
    break;

  case 77:
#line 579 "exptree.y"
                                   {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2658 "y.tab.c"
    break;

  case 78:
#line 586 "exptree.y"
                                            {
                Gsymbol* temp = find_gsymbol((yyvsp[-3].node)->varname);
                (yyvsp[-3].node)->Gentry = temp;
                check_not_out_of_bounds((yyvsp[-2].DimList),(yyvsp[-3].node)->Gentry->dimlist);
                (yyvsp[-5].node)->left = (yyvsp[-3].node);
                (yyvsp[-3].node)->dimlist = (yyvsp[-2].DimList);
                (yyval.node) = createTree(0,TYPE_NULL, "Read", READNODE,NULL,(yyvsp[-3].node), NULL, NULL);
            }
#line 2671 "y.tab.c"
    break;

  case 79:
#line 594 "exptree.y"
                                      {
                Gsymbol* entry = find_gsymbol((yyvsp[-2].node)->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,(yyvsp[-2].node), NULL,NULL);
                (yyval.node) = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
#line 2681 "y.tab.c"
    break;

  case 80:
#line 599 "exptree.y"
                                     {
                int type = (yyvsp[-2].node)->type;
                TypeTable* typet = (yyvsp[-2].node)->typeEntry;
                (yyval.node) = createTree(0,(yyvsp[-2].node)->type,"Read",READNODE,NULL,(yyvsp[-2].node),NULL,NULL);
            }
#line 2691 "y.tab.c"
    break;

  case 81:
#line 604 "exptree.y"
                                           {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-4].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-4].node)->varname);
                int type = get_type(ptr1,ptr2,(yyvsp[-4].node)->varname);
                check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,649);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-4].node)->varname);
                if(varType != TYPE_PTR){
                    printf("Error: %s is not of pointer type, use . operator to access its attributes\n", (yyvsp[-4].node)->varname);
                    exit(0);
                }
                TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-4].node)->varname);
                tnode* arrow = createTree(0,typetable_lookup_id_type(typet,(yyvsp[-2].node)->varname),"->",ARROWNODE,NULL,(yyvsp[-4].node),NULL,(yyvsp[-2].node));
                (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[-2].node)->varname),"Read",READNODE,NULL,arrow,NULL,NULL);
                arrow->typeEntry = typet;
            }
#line 2711 "y.tab.c"
    break;

  case 82:
#line 621 "exptree.y"
                                  {
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2720 "y.tab.c"
    break;

  case 83:
#line 627 "exptree.y"
                       {
            if((yyvsp[-1].node)->nodetype != NULLNODE){
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-3].node)->varname);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname);
                TypeTable* type1 = get_typetable(ptr1,ptr2,(yyvsp[-3].node)->varname);

                TypeTable* type2 = (yyvsp[-1].node)->typeEntry;

                if(strcmp(type1->name,type2->name) != 0){
                    printf("Error: Assignment with different Data Types, LHS => %s and RHS => %s\n", type1->name,type2->name);
                    exit(0);
                }
                if(varType != TYPE_VAR && varType != TYPE_PTR){
                    printf("Error: %s is not of variable type\n",(yyvsp[-3].node)->varname);
                    printf("%s\n",type_to_string(varType));
                    exit(1);
                }
                
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
            }else{
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL, (yyvsp[-3].node), NULL, (yyvsp[-1].node));
            }
        }
#line 2749 "y.tab.c"
    break;

  case 84:
#line 651 "exptree.y"
                                {
            Gsymbol* temp = find_gsymbol((yyvsp[-4].node)->varname);
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is not of array type\n",(yyvsp[-4].node)->varname);
                exit(1);
            }
            check_data_types(temp->type,(yyvsp[-1].node)->type,temp->type,432);
            (yyvsp[-4].node)->Gentry = temp;
            (yyvsp[-4].node)->dimlist = (yyvsp[-3].DimList);
            check_not_out_of_bounds((yyvsp[-3].DimList),(yyvsp[-4].node)->Gentry->dimlist);
            (yyval.node) = createTree(0,TYPE_ARR, "=", ASSIGNMENT,(yyvsp[-4].node)->Gentry,(yyvsp[-4].node), NULL, (yyvsp[-1].node));
        }
#line 2766 "y.tab.c"
    break;

  case 85:
#line 663 "exptree.y"
                           {  //here i used MUL because lex returnes MUL when the it captures '*'
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-3].node)->varname);
            int varType = get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname);
            if(varType != TYPE_PTR){
                printf("Error: %s is not of pointer type\n",(yyvsp[-3].node)->varname);
                exit(1);
            }
            if(ptr2){
                check_data_types(ptr2->type,(yyvsp[-1].node)->type,ptr2->type,447);
            }else if(ptr1){
                check_data_types(ptr1->type,(yyvsp[-1].node)->type,ptr1->type,449);
            }else{
                printf("Error: Variable %s Not Declared 498\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, NULL,(yyvsp[-3].node), NULL, NULL);
            (yyval.node) = createTree(0,TYPE_PTR, "=", ASSIGNMENT,NULL,t, NULL, (yyvsp[-1].node));
        }
#line 2790 "y.tab.c"
    break;

  case 86:
#line 682 "exptree.y"
                          {
            TypeTable* type1 = (yyvsp[-3].node)->typeEntry;
            TypeTable* type2 = (yyvsp[-1].node)->typeEntry;
            if((yyvsp[-1].node)->nodetype != NULLNODE){
                if(strcmp((yyvsp[-3].node)->typeEntry->name,(yyvsp[-1].node)->typeEntry->name) != 0){
                    printf("Error: Assignment with different Data Types, LHS => %s and RHS => %s\n", type1->name,type2->name);
                    exit(0);
                }
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
                (yyval.node)->typeEntry = (yyvsp[-3].node)->typeEntry;
                (yyval.node)->centry = (yyvsp[-3].node)->centry;
            }else {
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
                (yyval.node)->typeEntry = (yyvsp[-3].node)->typeEntry;
            }
        }
#line 2811 "y.tab.c"
    break;

  case 87:
#line 698 "exptree.y"
                                {
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-5].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-5].node)->varname);
            TypeTable* type = NULL;
            if(ptr2){
                type = ptr2->typeEntry;
            }else if(ptr1){
                type = ptr1->typeEntry;
            }else{
                printf("Error: Variable %s Not Declared 539\n", (yyvsp[-5].node)->varname);
                exit(0);
            }
            if(type->type != TYPE_TUPLE){
                printf("Error: Variable %s is not of tuple type\n", (yyvsp[-5].node)->varname);
                exit(0);
            }

            if(typetable_lookup_id_type(type,(yyvsp[-3].node)->varname) != (yyvsp[-1].node)->type){
                printf("Error: Variable %s Not Declared in the tuple definition\n", (yyvsp[-3].node)->varname);
                exit(0);
                
            }
            if(get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname) != TYPE_PTR){
                printf("Error: %s is not of pointer type, use . operator\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            tnode* arrow = createTree(0,typetable_lookup_id_type(type,(yyvsp[-3].node)->varname),"->",ARROWNODE,NULL,(yyvsp[-5].node),NULL,(yyvsp[-3].node));
            (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,ptr1,arrow, NULL, (yyvsp[-1].node));
            (yyval.node)->typeEntry = type;
        }
#line 2846 "y.tab.c"
    break;

  case 88:
#line 731 "exptree.y"
                                     {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-5].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-5].node)->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,(yyvsp[-5].node)->varname);
                Classtable* cls = get_classtable((yyvsp[-5].node)->varname);

                check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-5].node), NULL, NULL);

                temp->typeEntry = type;
                temp->centry = cls;

                (yyval.node) = temp;
            }
#line 2867 "y.tab.c"
    break;

  case 89:
#line 747 "exptree.y"
                                         {

                if((yyvsp[-5].node)->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise allocation not possible %s\n", (yyvsp[-5].node)->right->varname);
                    exit(0);
                }

                tnode* temp = createTree((yyvsp[-5].node)->typeEntry->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-5].node), NULL, NULL);

                (yyval.node) = temp;
            }
#line 2883 "y.tab.c"
    break;

  case 90:
#line 758 "exptree.y"
                                  {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);

                // check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);

                temp->typeEntry = type;

                (yyval.node) = temp;
            }
#line 2902 "y.tab.c"
    break;

  case 91:
#line 772 "exptree.y"
                                     {

                if((yyvsp[-2].node)->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise deallocation not possible %s\n", (yyvsp[-2].node)->right->varname);
                    exit(0);
                }

                tnode* temp = createTree((yyvsp[-2].node)->typeEntry->size, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);

                (yyval.node) = temp;
            }
#line 2918 "y.tab.c"
    break;

  case 92:
#line 783 "exptree.y"
                                   {
                tnode* temp = createTree(0, TYPE_NULL, "initalize", INITIALIZENODE,NULL,NULL, NULL, NULL);
                (yyval.node) = temp;
            }
#line 2927 "y.tab.c"
    break;

  case 93:
#line 787 "exptree.y"
                                        {

                Gsymbol* ptr1 = find_gsymbol((yyvsp[-6].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-6].node)->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,(yyvsp[-6].node)->varname);
                Classtable* cls1 = get_classtable((yyvsp[-6].node)->varname);
                Classtable* cls2 = CLookup((yyvsp[-2].node)->varname);

                if(!cls1 ){
                    printf("Error: No class entry found for the variable %s\n",(yyvsp[-6].node)->varname);
                    exit(0);
                }else if( !cls2){
                    printf("Error: No class entry found for the variable %s\n",(yyvsp[-2].node)->varname);
                    exit(0);
                }

                if(strcmp(cls1->Name,cls2->Name) != 0){
                    printf("Error: Allocating to different class type\n");
                    exit(0);
                }

                if(type)check_data_types(type->type,type->type,TYPE_CLASS,738);

                tnode* temp = createTree(cls2->Fieldcount, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-6].node), NULL, NULL);
                temp->typeEntry = NULL;
                temp->centry = cls1;

                (yyval.node) = temp;
            }
#line 2962 "y.tab.c"
    break;

  case 94:
#line 817 "exptree.y"
                                           {
                Classtable* cls1 = (yyvsp[-6].node)->centry;
                Classtable* cls2 = CLookup((yyvsp[-2].node)->varname);

                if(!cls1 ){
                    printf("Error: No class entry found for the variable SELFNODE\n");
                    exit(0);
                }else if( !cls2){
                    printf("Error: No class entry found for the variable %s\n",(yyvsp[-2].node)->varname);
                    exit(0);
                }

                if(strcmp(cls1->Name,cls2->Name) != 0){
                    printf("Error: Allocating to different class type\n");
                    exit(0);
                }

                tnode* temp = createTree(cls2->Fieldcount, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-6].node), NULL, NULL);
                temp->typeEntry = NULL;
                temp->centry = cls1;

                (yyval.node) = temp;
            }
#line 2990 "y.tab.c"
    break;

  case 95:
#line 840 "exptree.y"
                                        {
                Classtable* cls = get_classtable((yyvsp[-2].node)->varname);
                if(cls == NULL){
                    printf("Error: Piecewise deallocation not possible %s\n", (yyvsp[-2].node)->right->varname);
                    exit(0);
                }
                tnode* temp = createTree((yyvsp[-2].node)->centry->Fieldcount, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);
                (yyval.node)->centry = cls;
                (yyval.node) = temp;
            }
#line 3005 "y.tab.c"
    break;

  case 96:
#line 850 "exptree.y"
                                       {
                if((yyvsp[-2].node)->centry == NULL){
                    printf("Error: Piecewise deallocation not possible %s\n", (yyvsp[-2].node)->right->varname);
                    exit(0);
                }

                tnode* temp = createTree((yyvsp[-2].node)->centry->Fieldcount, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);

                (yyval.node) = temp;
            }
#line 3020 "y.tab.c"
    break;

  case 97:
#line 864 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3026 "y.tab.c"
    break;

  case 98:
#line 865 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3032 "y.tab.c"
    break;

  case 99:
#line 866 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3038 "y.tab.c"
    break;

  case 100:
#line 867 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3044 "y.tab.c"
    break;

  case 101:
#line 868 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3050 "y.tab.c"
    break;

  case 102:
#line 869 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3056 "y.tab.c"
    break;

  case 103:
#line 870 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3062 "y.tab.c"
    break;

  case 104:
#line 871 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3068 "y.tab.c"
    break;

  case 105:
#line 872 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3074 "y.tab.c"
    break;

  case 106:
#line 873 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3080 "y.tab.c"
    break;

  case 107:
#line 874 "exptree.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 3086 "y.tab.c"
    break;

  case 108:
#line 877 "exptree.y"
                                                       {
            (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-7].node),(yyvsp[-2].node));
        }
#line 3094 "y.tab.c"
    break;

  case 109:
#line 880 "exptree.y"
                                            {
            (yyval.node) = createIfNode((yyvsp[-2].node),(yyvsp[-5].node),NULL);
        }
#line 3102 "y.tab.c"
    break;

  case 110:
#line 885 "exptree.y"
                                                    {
                (yyval.node) = createWhileNode((yyvsp[-2].node),(yyvsp[-5].node));
            }
#line 3110 "y.tab.c"
    break;

  case 111:
#line 890 "exptree.y"
                                           {
                (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
            }
#line 3118 "y.tab.c"
    break;

  case 112:
#line 895 "exptree.y"
                                                      {
                        (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
                    }
#line 3126 "y.tab.c"
    break;

  case 113:
#line 900 "exptree.y"
                           {
                (yyval.node) = createJumpNode(CONTINUENODE);
            }
#line 3134 "y.tab.c"
    break;

  case 114:
#line 903 "exptree.y"
                        {
                (yyval.node) = createJumpNode(BREAKNODE);
            }
#line 3142 "y.tab.c"
    break;

  case 115:
#line 906 "exptree.y"
                           { 
                (yyval.node) = createTree(0, (yyvsp[-1].node)->type, NULL, RETURNNODE, NULL,(yyvsp[-1].node), NULL,NULL);
                (yyval.node)->typeEntry = (yyvsp[-1].node)->typeEntry;
            }
#line 3151 "y.tab.c"
    break;

  case 116:
#line 912 "exptree.y"
                           {
                (yyval.node) = createTree(0,TYPE_NULL,"BRKP", BREAKPOINTNODE,NULL,NULL, NULL, NULL);
            }
#line 3159 "y.tab.c"
    break;

  case 117:
#line 917 "exptree.y"
               {
        
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "+", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node)->typeEntry = typet;
    }
#line 3171 "y.tab.c"
    break;

  case 118:
#line 924 "exptree.y"
                {
        (yyval.node) =  createTree(0, (yyvsp[-2].node)->type , "-", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node)->typeEntry = typet;
    }
#line 3182 "y.tab.c"
    break;

  case 119:
#line 930 "exptree.y"
              {
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "/", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node)->typeEntry = typet;
    }
#line 3193 "y.tab.c"
    break;

  case 120:
#line 936 "exptree.y"
              {
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "*", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node)->typeEntry = typet;
    }
#line 3204 "y.tab.c"
    break;

  case 121:
#line 942 "exptree.y"
              {
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "%", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node)->typeEntry = typet;
    }
#line 3215 "y.tab.c"
    break;

  case 122:
#line 948 "exptree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3223 "y.tab.c"
    break;

  case 123:
#line 951 "exptree.y"
             {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node) = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3233 "y.tab.c"
    break;

  case 124:
#line 956 "exptree.y"
             {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node) = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3243 "y.tab.c"
    break;

  case 125:
#line 961 "exptree.y"
             {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node) = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3253 "y.tab.c"
    break;

  case 126:
#line 966 "exptree.y"
             {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        (yyval.node) = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3263 "y.tab.c"
    break;

  case 127:
#line 971 "exptree.y"
             {
        if((yyvsp[-2].node)->type == TYPE_TUPLE && (yyvsp[0].node)->nodetype == NULLNODE){

        }else{
            TypeTable* typet = typetable_lookup("int");
            typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        }
        (yyval.node) = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3277 "y.tab.c"
    break;

  case 128:
#line 980 "exptree.y"
             {
        if((yyvsp[-2].node)->type == TYPE_TUPLE && (yyvsp[0].node)->nodetype == NULLNODE){
                
        }else{
            TypeTable* typet = typetable_lookup("int");
            typetable_check_type((yyvsp[-2].node)->typeEntry, (yyvsp[0].node)->typeEntry, typet);
        }
        (yyval.node) = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3291 "y.tab.c"
    break;

  case 129:
#line 989 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,624);
        (yyval.node) = createTree(0,TYPE_BOOL,"&&",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3300 "y.tab.c"
    break;

  case 130:
#line 993 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,628);
        (yyval.node) = createTree(0,TYPE_BOOL,"||",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 3309 "y.tab.c"
    break;

  case 131:
#line 997 "exptree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3317 "y.tab.c"
    break;

  case 132:
#line 1000 "exptree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3325 "y.tab.c"
    break;

  case 133:
#line 1003 "exptree.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3333 "y.tab.c"
    break;

  case 134:
#line 1006 "exptree.y"
                  {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
        int type = get_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
        check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,649);
        int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
        if(varType != TYPE_PTR){
            printf("Error: %s is not of pointer type, use . operator to access its attributes\n", (yyvsp[-2].node)->varname);
            exit(0);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);
        (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[0].node)->varname),"->",ARROWNODE,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
        (yyval.node)->typeEntry = typet;
    }
#line 3352 "y.tab.c"
    break;

  case 135:
#line 1031 "exptree.y"
                         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);

        print_gsymbol_list(ptr1);
        if(!ptr1 || (ptr1->varType != TYPE_FUNCT && ptr1->varType != TYPE_FUNCT_PTR)){
            printf("Error: No function with name %s declared\n",(yyvsp[-3].node)->varname);
            exit(0);
        }
        tnode* temp = (yyvsp[-1].node);
        // while(temp){
        //     print_ast_node(temp);
        //     temp = temp->middle;
        // }
        paramlist_is_input_args_correct(ptr1->plist, (yyvsp[-1].node));
        TypeTable* typet = get_typetable(ptr1,NULL,(yyvsp[-3].node)->varname);
        (yyval.node) = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,(yyvsp[-3].node),NULL,(yyvsp[-1].node));
        (yyval.node)->typeEntry = typet;
    }
#line 3375 "y.tab.c"
    break;

  case 136:
#line 1049 "exptree.y"
         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);
        
        int varType = get_var_type(ptr1,ptr2,(yyvsp[0].node)->varname);
        // printf("%s is of %s\n",$1->varname, type_to_string(varType));
        if(varType != TYPE_VAR && varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",(yyvsp[0].node)->varname);
            exit(1);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[0].node)->varname);
        (yyval.node) = createTree(0, get_type(ptr1,ptr2,(yyvsp[0].node)->varname), (yyvsp[0].node)->varname, LEAFNODE, ptr1,NULL, NULL,NULL);
        (yyval.node)->typeEntry = typet;
        (yyval.node)->centry = get_classtable((yyvsp[0].node)->varname);
    }
#line 3395 "y.tab.c"
    break;

  case 137:
#line 1064 "exptree.y"
                   {
        Gsymbol* temp = find_gsymbol((yyvsp[-1].node)->varname);
        if(!(yyvsp[0].DimList)){
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is of array type but using it as variable type here\n",(yyvsp[-1].node)->varname);
                exit(1);
            }
        }
        (yyvsp[-1].node)->Gentry = temp;
        check_not_out_of_bounds((yyvsp[0].DimList),(yyvsp[-1].node)->Gentry->dimlist);
        int val = get_pos((yyvsp[0].DimList),(yyvsp[-1].node)->Gentry->dimlist);
        (yyval.node) = createTree(val, temp->type, (yyvsp[-1].node)->varname, LEAFNODE, temp,NULL, NULL,NULL);
        TypeTable* typet = get_typetable(temp,NULL,(yyvsp[-1].node)->varname);
        (yyval.node)->typeEntry = typet;
        (yyval.node)->dimlist = (yyvsp[0].DimList);
        (yyval.node)->centry = get_classtable((yyvsp[-1].node)->varname);
    }
#line 3417 "y.tab.c"
    break;

  case 138:
#line 1081 "exptree.y"
             { //here i used MUL because lex returnes MUL when the it captures '*'
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);

        if(!ptr1 && !ptr2){
            printf("Error: pointer %s is not declared\n", (yyvsp[0].node)->varname);
        }
        (yyvsp[0].node)->Gentry = ptr1;
        (yyval.node) = createTree(0, TYPE_INT, "*", PTRNODE, ptr1,(yyvsp[0].node), NULL,NULL);
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[0].node)->varname);
        (yyval.node)->typeEntry = typet;
        (yyvsp[0].node)->typeEntry = typet;
    }
#line 3435 "y.tab.c"
    break;

  case 139:
#line 1094 "exptree.y"
             {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);

        if(!ptr1 && !ptr2){
            printf("Error: pointer %s is not declared\n", (yyvsp[0].node)->varname);
        }
        (yyvsp[0].node)->Gentry = ptr1;

        (yyval.node) = createTree(0, TYPE_INT, "&", ADDRNODE, NULL,(yyvsp[0].node), NULL,NULL);
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[0].node)->varname);
        (yyval.node)->typeEntry = typet;
        (yyvsp[0].node)->typeEntry = typet;
    }
#line 3454 "y.tab.c"
    break;

  case 140:
#line 1108 "exptree.y"
             {
        (yyval.node) = createTree(-10, TYPE_STRING, (yyvsp[0].string), LEAFNODE,NULL, NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("str");
        (yyval.node)->typeEntry = typet;
    }
#line 3464 "y.tab.c"
    break;

  case 141:
#line 1113 "exptree.y"
          {
        (yyval.node) = createTree((yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 3474 "y.tab.c"
    break;

  case 142:
#line 1118 "exptree.y"
                {
        (yyval.node) = createTree(-(yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 3484 "y.tab.c"
    break;

  case 143:
#line 1124 "exptree.y"
                                  {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,756);
                (yyval.DimList) = append_dim_with_id((yyvsp[-3].DimList),(yyvsp[-1].node));
            }
#line 3493 "y.tab.c"
    break;

  case 144:
#line 1128 "exptree.y"
                        {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,760);
                (yyval.DimList) = append_dim_with_id(NULL,(yyvsp[-1].node));
            }
#line 3502 "y.tab.c"
    break;

  case 145:
#line 1134 "exptree.y"
                       {
            int type = (yyvsp[-2].node)->type;
            check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,803);
            TypeTable* typet = (yyvsp[-2].node)->typeEntry;
            TypeTable* typet2 = typetable_lookup_id_typetable(typet,(yyvsp[0].node)->varname);
            (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[0].node)->varname),".",DOTNODE,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
            (yyval.node)->typeEntry = typet2;
            (yyvsp[0].node)->typeEntry = typet2;
            if((yyvsp[-2].node)->centry){
                Classtable* cls = (yyvsp[-2].node)->centry;
                Fieldlist* field = Class_Flookup(cls,(yyvsp[0].node)->varname);
                if(!field){
                    printf("Error: No field %s found in class %s\n",(yyvsp[0].node)->varname,cls->Name);
                    exit(0);
                }
                (yyval.node)->centry = field->Ctype;
                (yyvsp[0].node)->centry = field->Ctype;
            }
            // printf("for ID %s -> ID %s\n", $1->varname, $3->varname);
            // if(typet2){
            //     printf("typeEntry name %s 805\n", typet2->name);
            // }else if($$->centry){
            //     printf("centry name %s 805\n", $$->centry->Name);
            // }

            // printf("typeEntry %s 806\n", typet->name);
        }
#line 3534 "y.tab.c"
    break;

  case 146:
#line 1161 "exptree.y"
                    {
            
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
            int type = get_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
            int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
            if(varType == TYPE_PTR){
                printf("Error: %s is of pointer type, use -> operator to access its attributes\n", (yyvsp[-2].node)->varname);
                exit(0);
            }
            TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);
            Classtable* cls = get_classtable((yyvsp[-2].node)->varname);
            TypeTable* typet2 = typetable_lookup_id_typetable(typet,(yyvsp[0].node)->varname);
            (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[0].node)->varname),"dot",DOTNODE,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
            (yyval.node)->typeEntry = typet2;
            (yyvsp[-2].node)->typeEntry = typet;
            (yyvsp[-2].node)->centry = cls;

         }
#line 3558 "y.tab.c"
    break;

  case 147:
#line 1180 "exptree.y"
                      {
            if(Cptr != NULL){
                Fieldlist* t = Class_Flookup(Cptr,(yyvsp[0].node)->varname);
                (yyval.node) = createTree(0,t->Type ? t->Type->type : TYPE_CLASS,(yyvsp[0].node)->varname, DOTNODE, NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
                if(!t){
                    printf("Error: No field %s found\n",(yyvsp[0].node)->varname);
                    exit(0);
                }
                (yyvsp[-2].node)->centry = Cptr;
                (yyvsp[-2].node)->typeEntry = NULL;
                (yyval.node)->centry = t->Ctype;
                (yyval.node)->typeEntry = t->Type;
                // printf("---\n");
                // printf("ID SELF -> FOR ID %s\n", $3->varname);
                // if(t->Type){
                //     printf("typeEntry name %s\n", $$->typeEntry->name);
                // }else if(t->Ctype){
                //         printf("centry name %s\n", $$->centry->Name);
                // }
                

            }else{
                printf("Error:Not inside a class\n");
                exit(0);
            }
        }
#line 3589 "y.tab.c"
    break;


#line 3593 "y.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 1210 "exptree.y"



void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType){


        Gsymbol* temp = find_gsymbol($2->varname);
        Memberfunclist* func = Cptr ? Class_Mlookup(Cptr,$2->varname) : NULL;
        
        TypeTable* type = temp ? temp->typeEntry : func->Type; 
        int flabel = temp ? temp->flabel : func->Flabel;
        

        ParamList* param = func ? func->Paramlist : temp->plist;
        curr_function_type = type;
        is_paramlist_correct(param,$4);

        print_lsymbol_table();

        curr_funct_return_type = functionType;
        
        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome 
        // curr_lsymbol_table = $7;

        ParamList* t = $4;
        int p = getReg();
        fprintf(fptr,"F%d:", flabel);
        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");
        
        int param_list_size = get_paramlist_length($4);

        //setting up the argument values into the respective addresses in the from the local symbol table
        int count = param_list_size + 1;
        int returnSize = 1;
        if(functionType == TYPE_FUNCT_PTR){
            returnSize = 1;
        }
        /* fprintf(fptr, "BRKP\n");
        fprintf(fptr, "BRKP\n"); */
        while(count--){
            fprintf(fptr, "MOV R%d, SP\n", p);
            fprintf(fptr, "SUB R%d, %d\n", p, param_list_size + 3 + returnSize - 1); //here the 3 is the RETURN VALUE, RETURN ADDRESS, OLD BP and the -1 for preventing the overreduction as subtracting curr_offset u reach the OLD BP 
                                                                        // and from there to reach the return value part u just need to subtract 2 and to reach the 1st arg u just need to subtract the whole paramlist
            fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
            fprintf(fptr, "PUSH R%d\n", p);
        }

        /* fprintf(fptr, "BRKP\n"); */

        // This is to set up space for the locally declared variables in the function
        int curr_offset = get_ltable_length(curr_lsymbol_table) - param_list_size - 1;

        if(curr_offset > 0)fprintf(fptr, "MOV R%d, \"SPACE\"\n", p);
        for(int i=0;i<curr_offset;i++){
            
            fprintf(fptr,"PUSH R%d\n",p);
        }

        freeReg();

        export_ast_to_graphviz($8,$2->varname);

        tree_visual_printTree($8);

        Lsymbol* temp1 = curr_lsymbol_table;

        int param_list_length = get_paramlist_length($4);
        while(param_list_length-- > 0){
            temp1 = temp1->next;
        }

        setup_pointers_codegen(fptr,NULL,temp1);
    
    

    codeGen($8,0,0,fptr);
    Lsymbol* a = curr_lsymbol_table;
    // lst_destroy(a);
    curr_lsymbol_table = NULL;
    // ast_destroy($8);
}


void yyerror(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "Error at line %d near '%s': ", yylloc.first_line, yytext);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);
    exit(1);
}





int main(int argc, char *argv[]) {
    

    yyin = fopen(argv[1], "r");
    fptr = fopen("machinecode.xsm", "w");
    typetable_create("int", TYPE_INT,  NULL);
    typetable_create("str", TYPE_STRING, NULL);
    typetable_create("bool", TYPE_BOOL, NULL);
    typetable_create("void", TYPE_VOID, NULL);
    make_header(fptr);
    yyparse();
    print_gsymbol_table();
    exit_footer(fptr);
    create_label_with_message(fptr,101,"IndexOutOfBounds");
    fclose(fptr);
    fclose(yyin);
    /* codeIntrepret(head); */
    return 0;
}
