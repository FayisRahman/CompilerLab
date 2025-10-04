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
    #include "reghandling.h"
    #include "AST.h"
    #include "evaluator.h"
    #include "global_symbol_table.h"
    #include "local_symbol_table.h"
    #include "dim_node.h"
    #include "param_list.h"
    #include "tree_visualization.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* fptr = NULL;
    void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType);
    

#line 92 "y.tab.c"

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
    STRING = 264,
    begin = 265,
    end = 266,
    MAIN = 267,
    DECL = 268,
    ENDDECL = 269,
    PLUS = 270,
    MINUS = 271,
    DIV = 272,
    MUL = 273,
    IF = 274,
    THEN = 275,
    ELSE = 276,
    ENDIF = 277,
    WHILE = 278,
    DO = 279,
    ENDWHILE = 280,
    REPEAT = 281,
    UNTIL = 282,
    CONTINUE = 283,
    BREAK = 284,
    RETURN = 285,
    BREAKPOINT = 286,
    GT = 287,
    GE = 288,
    LT = 289,
    LE = 290,
    NE = 291,
    EQ = 292,
    AND = 293,
    OR = 294,
    MOD = 295
  };
#endif
/* Tokens.  */
#define WRITE 258
#define READ 259
#define INT 260
#define STR 261
#define ID 262
#define NUM 263
#define STRING 264
#define begin 265
#define end 266
#define MAIN 267
#define DECL 268
#define ENDDECL 269
#define PLUS 270
#define MINUS 271
#define DIV 272
#define MUL 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ENDIF 277
#define WHILE 278
#define DO 279
#define ENDWHILE 280
#define REPEAT 281
#define UNTIL 282
#define CONTINUE 283
#define BREAK 284
#define RETURN 285
#define BREAKPOINT 286
#define GT 287
#define GE 288
#define LT 289
#define LE 290
#define NE 291
#define EQ 292
#define AND 293
#define OR 294
#define MOD 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "exptree.y"

    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;

#line 234 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   588

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
       2,     2,     2,     2,     2,     2,     2,     2,    50,     2,
      43,    44,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    57,    58,    61,    68,    75,    76,    79,
      91,    94,    97,   108,   115,   123,   135,   136,   139,   144,
     151,   159,   167,   170,   176,   181,   190,   200,   203,   216,
     221,   231,   235,   240,   243,   247,   251,   256,   288,   290,
     294,   299,   300,   303,   306,   309,   316,   324,   331,   337,
     355,   367,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   399,   402,   407,   412,   417,   422,   425,   428,   433,
     438,   442,   446,   450,   454,   458,   461,   465,   469,   473,
     477,   481,   485,   489,   493,   502,   512,   522,   536,   542,
     547,   550,   553,   557,   561
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WRITE", "READ", "INT", "STR", "ID",
  "NUM", "STRING", "begin", "end", "MAIN", "DECL", "ENDDECL", "PLUS",
  "MINUS", "DIV", "MUL", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "REPEAT", "UNTIL", "CONTINUE", "BREAK", "RETURN",
  "BREAKPOINT", "GT", "GE", "LT", "LE", "NE", "EQ", "AND", "OR", "MOD",
  "';'", "','", "'('", "')'", "'{'", "'}'", "'['", "']'", "'='", "'&'",
  "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl", "GidList",
  "Gid", "FDefBlock", "Fdef", "Paramlist", "ParamDecl", "Param",
  "LdeclBlock", "LDecList", "LDecl", "IdList", "IdDecl", "ArgList",
  "MainBlock", "body", "Slist", "Type", "DimList", "InputStmt",
  "OutputStmt", "AsgStmt", "Stmt", "Ifstmt", "Whilestmt", "DoWhilestmt",
  "RepeatUntiltstmt", "Jumpstmt", "Debugstmt", "E", "DimAccess", YY_NULLPTR
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
     295,    59,    44,    40,    41,   123,   125,    91,    93,    61,
      38
};
# endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     154,  -111,  -111,   124,    33,   135,  -111,    50,  -111,   150,
    -111,    71,  -111,   135,  -111,  -111,     7,    -4,  -111,  -111,
      51,    98,   185,  -111,  -111,  -111,    65,   105,    78,   135,
     115,   114,  -111,    71,   135,   122,   121,    92,  -111,    75,
     174,   135,  -111,    93,   135,   176,   135,  -111,  -111,   197,
    -111,   170,   119,   179,   139,   135,   220,  -111,  -111,  -111,
    -111,   176,   186,   211,  -111,    83,   404,   200,   220,   176,
    -111,  -111,  -111,   225,   187,  -111,   204,   216,   138,   241,
     217,   224,   404,   404,   227,   228,    61,   229,   328,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
     215,   220,  -111,  -111,    83,    61,    84,    61,    61,   156,
     222,    61,    61,   422,    57,  -111,  -111,   -31,  -111,  -111,
     264,   266,    61,   267,   439,  -111,  -111,  -111,  -111,   243,
    -111,   162,    48,   268,   110,   449,    61,    61,    61,   175,
     205,   247,   265,    22,   244,  -111,  -111,   218,  -111,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,  -111,  -111,   263,   269,    62,   270,  -111,  -111,
     136,   476,   486,   287,   285,    61,    61,  -111,   144,   513,
    -111,     6,     6,  -111,  -111,    27,    27,    27,    27,   548,
     548,    81,   522,  -111,  -111,  -111,   271,   272,  -111,  -111,
    -111,   404,   404,   248,   261,    61,  -111,  -111,  -111,   299,
     346,    -9,   274,   513,   404,   275,   278,  -111,  -111,   375,
    -111,  -111,   283,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    41,    42,     0,     0,     0,     4,     0,     6,     0,
       8,     0,     1,     0,    17,     3,     0,     0,     5,     7,
      44,     0,     0,    11,    16,     2,     0,     0,     0,    22,
      12,    13,     9,     0,    22,     0,     0,     0,    21,     0,
       0,    22,    10,     0,    22,    27,     0,    14,    24,     0,
      23,     0,     0,     0,     0,     0,     0,    20,    25,    43,
      15,    27,     0,     0,    29,     0,     0,     0,     0,    27,
      26,    28,    33,     0,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    40,    55,    56,    57,    58,    59,    60,    37,
       0,     0,    34,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    86,    91,    90,
       0,     0,     0,     0,     0,    69,    38,    39,    18,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    92,    88,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    19,     0,     0,     0,     0,    94,    49,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    36,
      75,    70,    71,    72,    73,    76,    78,    77,    79,    80,
      81,    82,    83,    74,    48,    45,     0,     0,    93,    50,
      51,     0,     0,     0,     0,     0,    85,    46,    47,     0,
       0,     0,     0,    35,     0,     0,     0,    64,    65,     0,
      62,    63,     0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,   302,  -111,   293,  -111,   320,    66,
     288,  -111,   -43,  -111,   273,  -111,   233,  -111,   126,   -64,
     -82,     8,  -111,  -111,  -111,  -111,   -86,  -111,  -111,  -111,
    -111,  -111,  -111,  -102,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     9,    10,    22,    23,    13,    14,    37,
      38,    50,    56,    63,    64,    74,    75,   178,     6,    67,
      88,    39,    30,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   124,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     113,   114,   127,   131,   100,   134,   135,   144,     7,   139,
     140,    11,   143,    16,    26,   202,   107,    11,    68,    17,
     147,    16,   166,   151,   152,    27,   101,   127,   127,   117,
     118,   119,   217,    12,   170,   171,   172,   129,   120,    28,
     121,   179,   149,   150,   151,   152,   161,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      76,    77,    17,    65,    78,   122,   177,   161,   117,   118,
     119,    65,   123,   203,   204,    79,    80,   120,    20,   121,
      81,    82,    48,    83,   142,    84,    85,    86,    87,    21,
      72,   132,   165,    49,    29,   107,   149,   150,   151,   152,
      43,    73,   133,   213,   122,    31,   196,    52,    34,   136,
      54,   123,    35,   153,   154,   155,   156,   157,   158,   209,
     210,   161,    36,   127,   127,   149,   150,   151,   152,     1,
       2,    15,   219,   127,    46,    46,    47,    53,     8,    25,
       1,     2,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   149,   150,   151,   152,     1,     2,    41,   168,     1,
       2,    46,    40,    60,    18,    44,    45,     3,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   149,   150,   151,
     152,    46,    51,    62,   198,   107,   205,   108,   206,    55,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   136,    58,   137,   164,   153,   154,   155,
     156,   157,   158,   159,   160,   161,     1,     2,    59,   173,
     149,   150,   151,   152,    61,    70,    32,    33,   103,   104,
      66,    69,   102,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    99,   105,   110,   174,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   106,
     111,   128,   180,   149,   150,   151,   152,   112,   115,   116,
     125,   138,   145,   146,   148,   167,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   163,
     175,   136,   211,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    76,    77,   194,   212,    78,   201,   176,   202,
     195,    19,   207,   208,   197,   218,   220,    79,    80,   221,
     214,   215,    81,    82,   223,    83,    42,    84,    85,    86,
      87,    76,    77,    24,    57,    78,    71,   130,     0,   126,
       0,     0,     0,     0,     0,     0,    79,    80,     0,    76,
      77,    81,    82,    78,    83,     0,    84,    85,    86,    87,
       0,     0,     0,     0,    79,    80,     0,     0,     0,    81,
      82,   216,    83,     0,    84,    85,    86,    87,    76,    77,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,     0,     0,   222,    81,    82,
       0,    83,     0,    84,    85,    86,    87,    76,    77,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,     0,    76,    77,    81,    82,    78,
      83,     0,    84,    85,    86,    87,     0,     0,     0,     0,
      79,    80,     0,     0,     0,   141,    82,     0,    83,     0,
      84,    85,    86,    87,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,   149,   150,   151,   152,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   149,   150,   151,   152,     0,     0,     0,     0,     0,
       0,   149,   150,   151,   152,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   199,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   200,   149,   150,
     151,   152,     0,     0,     0,     0,     0,   149,   150,   151,
     152,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   153,   154,   155,   156,   157,   158,
     159,     0,   161,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,     0,     0,     0,     0,   161
};

static const yytype_int16 yycheck[] =
{
      82,    83,    88,   105,    68,   107,   108,   117,     0,   111,
     112,     3,    43,     5,     7,    24,    47,     9,    61,    12,
     122,    13,   132,    17,    18,    18,    69,   113,   114,     7,
       8,     9,    41,     0,   136,   137,   138,   101,    16,    43,
      18,   143,    15,    16,    17,    18,    40,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       3,     4,    12,    55,     7,    43,    44,    40,     7,     8,
       9,    63,    50,   175,   176,    18,    19,    16,     7,    18,
      23,    24,     7,    26,    27,    28,    29,    30,    31,    18,
       7,     7,    44,    18,    43,    47,    15,    16,    17,    18,
      34,    18,    18,   205,    43,     7,    44,    41,    43,    47,
      44,    50,     7,    32,    33,    34,    35,    36,    37,   201,
     202,    40,    44,   209,   210,    15,    16,    17,    18,     5,
       6,     5,   214,   219,    42,    42,    44,    44,    14,    13,
       5,     6,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    15,    16,    17,    18,     5,     6,    43,    48,     5,
       6,    42,    47,    44,    14,    43,    45,    13,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    15,    16,    17,
      18,    42,     8,    44,    48,    47,    42,    49,    44,    13,
      15,    16,    17,    18,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    47,     7,    49,    44,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     5,     6,    48,    44,
      15,    16,    17,    18,    45,    14,    41,    42,    41,    42,
      10,    45,     7,    15,    16,    17,    18,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    46,    43,     7,    44,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    43,
      43,    46,    44,    15,    16,    17,    18,    43,    41,    41,
      41,    49,     8,     7,     7,     7,    15,    16,    17,    18,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    46,
      43,    47,    44,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     3,     4,    41,    44,     7,    20,    43,    24,
      41,     9,    41,    41,    44,    41,    41,    18,    19,    41,
      21,    22,    23,    24,    41,    26,    33,    28,    29,    30,
      31,     3,     4,    13,    46,     7,    63,   104,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,     3,
       4,    23,    24,     7,    26,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,     3,     4,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    22,    23,    24,
      -1,    26,    -1,    28,    29,    30,    31,     3,     4,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,     3,     4,    23,    24,     7,
      26,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    23,    24,    -1,    26,    -1,
      28,    29,    30,    31,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    13,    52,    53,    69,    72,    14,    54,
      55,    72,     0,    58,    59,    69,    72,    12,    14,    55,
       7,    18,    56,    57,    59,    69,     7,    18,    43,    43,
      73,     7,    41,    42,    43,     7,    44,    60,    61,    72,
      47,    43,    57,    60,    43,    45,    42,    44,     7,    18,
      62,     8,    60,    44,    60,    13,    63,    61,     7,    48,
      44,    45,    44,    64,    65,    72,    10,    70,    63,    45,
      14,    65,     7,    18,    66,    67,     3,     4,     7,    18,
      19,    23,    24,    26,    28,    29,    30,    31,    71,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    46,
      70,    63,     7,    41,    42,    43,    43,    47,    49,    85,
       7,    43,    43,    71,    71,    41,    41,     7,     8,     9,
      16,    18,    43,    50,    84,    41,    11,    77,    46,    70,
      67,    84,     7,    18,    84,    84,    47,    49,    49,    84,
      84,    23,    27,    43,    85,     8,     7,    84,     7,    15,
      16,    17,    18,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    46,    44,    44,    85,     7,    48,    41,
      84,    84,    84,    44,    44,    43,    43,    44,    68,    84,
      44,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    41,    41,    44,    44,    48,    41,
      41,    20,    24,    84,    84,    42,    44,    41,    41,    71,
      71,    44,    44,    84,    21,    22,    25,    41,    41,    71,
      41,    41,    22,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    61,    62,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    67,    68,    68,    69,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    74,    75,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    80,    81,    82,    82,    82,    83,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     2,     2,     4,     5,     2,     1,     9,    10,
       3,     1,     0,     2,     1,     2,     3,     0,     2,     1,
       3,     3,     1,     1,     2,     3,     1,     8,     3,     2,
       1,     1,     1,     4,     0,     5,     6,     6,     5,     4,
       5,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    10,     8,     8,     7,     7,     2,     2,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     1,     2,     2,     2,
       1,     1,     2,     4,     3
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
#line 56 "exptree.y"
                                         {}
#line 1630 "y.tab.c"
    break;

  case 3:
#line 57 "exptree.y"
                               {}
#line 1636 "y.tab.c"
    break;

  case 4:
#line 58 "exptree.y"
                    {stack_address = curr_stack_address;driver_codegen(fptr);}
#line 1642 "y.tab.c"
    break;

  case 5:
#line 61 "exptree.y"
                                     {
                stack_address = curr_stack_address;
                setup_pointers_codegen(fptr,top,NULL);
                is_global_vars_declared = 1;
                printf("------Global Variables Declared-----\n");
                driver_codegen(fptr);
            }
#line 1654 "y.tab.c"
    break;

  case 6:
#line 68 "exptree.y"
                           {
                stack_address = curr_stack_address;
                is_global_vars_declared = 1;
                driver_codegen(fptr);
            }
#line 1664 "y.tab.c"
    break;

  case 7:
#line 75 "exptree.y"
                              {}
#line 1670 "y.tab.c"
    break;

  case 8:
#line 76 "exptree.y"
                   {}
#line 1676 "y.tab.c"
    break;

  case 9:
#line 79 "exptree.y"
                           {
            Gsymbol* temp = (yyvsp[-1].gsymbol);
            Gsymbol* temp1 = (yyvsp[-1].gsymbol);
            while(temp){
                temp1 = temp->next;
                temp->next = NULL;
                add_gsymbol(temp,(yyvsp[-2].integer));
                temp = temp1;
            }
        }
#line 1691 "y.tab.c"
    break;

  case 10:
#line 91 "exptree.y"
                         {
            (yyval.gsymbol) = append_gsymbol_id_list((yyvsp[-2].gsymbol),(yyvsp[0].gsymbol));    
        }
#line 1699 "y.tab.c"
    break;

  case 11:
#line 94 "exptree.y"
              { (yyval.gsymbol) = (yyvsp[0].gsymbol);}
#line 1705 "y.tab.c"
    break;

  case 12:
#line 97 "exptree.y"
                     {
            Gsymbol* temp = create_symbol_id_with_dims((yyvsp[-1].node)->varname, (yyvsp[0].DimList));
            (yyvsp[-1].node)->Gentry = temp;
            (yyvsp[-1].node)->type = TYPE_ARR;
            (yyvsp[-1].node)->Gentry->varType = TYPE_ARR;
            if(!(yyvsp[0].DimList)){
                (yyvsp[-1].node)->type = TYPE_VAR;
                (yyvsp[-1].node)->Gentry->varType = TYPE_VAR;
            }
            (yyval.gsymbol) = temp;
        }
#line 1721 "y.tab.c"
    break;

  case 13:
#line 108 "exptree.y"
                 {
            Gsymbol* temp = create_gsymbol_id((yyvsp[0].node)->varname, 2);
            (yyvsp[0].node)->Gentry = temp;
            (yyvsp[0].node)->type = TYPE_PTR;
            temp->varType = TYPE_PTR;
            (yyval.gsymbol) = temp;
        }
#line 1733 "y.tab.c"
    break;

  case 14:
#line 115 "exptree.y"
                               {
            int size = get_paramlist_length((yyvsp[-1].plist));
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = (yyvsp[-1].plist);
            temp->varType = TYPE_FUNCT;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 1746 "y.tab.c"
    break;

  case 15:
#line 123 "exptree.y"
                                   {
            int size = get_paramlist_length((yyvsp[-1].plist));
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = (yyvsp[-1].plist);
            temp->varType = TYPE_FUNCT_PTR;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 1759 "y.tab.c"
    break;

  case 16:
#line 135 "exptree.y"
                             {}
#line 1765 "y.tab.c"
    break;

  case 17:
#line 136 "exptree.y"
                   {}
#line 1771 "y.tab.c"
    break;

  case 18:
#line 139 "exptree.y"
                                                                  {    

                function_block((yyvsp[-8].integer),(yyvsp[-7].node),(yyvsp[-5].plist),(yyvsp[-1].node),TYPE_FUNCT);

            }
#line 1781 "y.tab.c"
    break;

  case 19:
#line 144 "exptree.y"
                                                                      {

                function_block((yyvsp[-9].integer), (yyvsp[-7].node),(yyvsp[-5].plist),(yyvsp[-1].node), TYPE_FUNCT_PTR);

            }
#line 1791 "y.tab.c"
    break;

  case 20:
#line 151 "exptree.y"
                                      {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, 1, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    curr_lsymbol_table = append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
#line 1804 "y.tab.c"
    break;

  case 21:
#line 159 "exptree.y"
                        {
                (yyval.plist) = (yyvsp[0].plist);
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, 1, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    curr_lsymbol_table =  append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
#line 1817 "y.tab.c"
    break;

  case 22:
#line 167 "exptree.y"
                                            {(yyval.plist) = NULL;curr_lsymbol_table= NULL;}
#line 1823 "y.tab.c"
    break;

  case 23:
#line 170 "exptree.y"
                         {
                (yyvsp[0].plist)->type = (yyvsp[-1].integer);
                (yyval.plist) = (yyvsp[0].plist);
            }
#line 1832 "y.tab.c"
    break;

  case 24:
#line 176 "exptree.y"
                 {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_VAR;
            }
#line 1842 "y.tab.c"
    break;

  case 25:
#line 181 "exptree.y"
                     {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_PTR;
                
            }
#line 1853 "y.tab.c"
    break;

  case 26:
#line 190 "exptree.y"
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
#line 1868 "y.tab.c"
    break;

  case 27:
#line 200 "exptree.y"
               {(yyval.lsymbol) = NULL;lst_set_bindings(curr_lsymbol_table);}
#line 1874 "y.tab.c"
    break;

  case 28:
#line 203 "exptree.y"
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
#line 1892 "y.tab.c"
    break;

  case 29:
#line 216 "exptree.y"
                    {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);   
            }
#line 1900 "y.tab.c"
    break;

  case 30:
#line 221 "exptree.y"
                              {
                Lsymbol* temp = (yyvsp[-1].lsymbol);
                while(temp){
                    temp->type = (yyvsp[-2].integer);
                    temp = temp->next;
                }
                (yyval.lsymbol) = (yyvsp[-1].lsymbol);
            }
#line 1913 "y.tab.c"
    break;

  case 31:
#line 231 "exptree.y"
                                 {
                check_lpresent((yyvsp[-2].lsymbol),(yyvsp[0].lsymbol)->name);
                (yyval.lsymbol) = append_lsymbol_id_list((yyvsp[-2].lsymbol), (yyvsp[0].lsymbol));
            }
#line 1922 "y.tab.c"
    break;

  case 32:
#line 235 "exptree.y"
                     {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);
            }
#line 1930 "y.tab.c"
    break;

  case 33:
#line 240 "exptree.y"
                 {
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, 1, TYPE_VAR);
            }
#line 1938 "y.tab.c"
    break;

  case 34:
#line 243 "exptree.y"
                    {
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, 2, TYPE_PTR);
                printf("ptr name: %s\n",(yyvsp[0].node)->varname);
            }
#line 1947 "y.tab.c"
    break;

  case 35:
#line 247 "exptree.y"
                            {
                (yyvsp[-2].node)->middle = (yyvsp[0].node);
                (yyval.node) = (yyvsp[-2].node);
            }
#line 1956 "y.tab.c"
    break;

  case 36:
#line 251 "exptree.y"
                { (yyval.node) = (yyvsp[0].node);}
#line 1962 "y.tab.c"
    break;

  case 37:
#line 256 "exptree.y"
                                                      {

        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome
        print_lsymbol_table();

        tree_visual_printTree((yyvsp[-1].node));

        fprintf(fptr, "MAIN:");

        int p = getReg();

        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");

        int curr_offset = get_curr_offset(curr_lsymbol_table);

        fprintf(fptr, "ADD SP, %d\n", curr_offset);

        freeReg();

        setup_pointers_codegen(fptr,NULL,curr_lsymbol_table);

        codeGen((yyvsp[-1].node),0,0,fptr);

        // lst_destroy($6);

        curr_lsymbol_table = NULL;
}
#line 1996 "y.tab.c"
    break;

  case 38:
#line 288 "exptree.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2002 "y.tab.c"
    break;

  case 39:
#line 290 "exptree.y"
                     {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,(yyvsp[-1].node), NULL, (yyvsp[0].node));
            (yyval.node) = temp;
        }
#line 2011 "y.tab.c"
    break;

  case 40:
#line 294 "exptree.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2019 "y.tab.c"
    break;

  case 41:
#line 299 "exptree.y"
                  { (yyval.integer) = TYPE_INT; }
#line 2025 "y.tab.c"
    break;

  case 42:
#line 300 "exptree.y"
                  { (yyval.integer) = TYPE_STRING; }
#line 2031 "y.tab.c"
    break;

  case 43:
#line 303 "exptree.y"
                              {
            (yyval.DimList) = append_dim((yyvsp[-3].DimList), (yyvsp[-1].node)->val);
        }
#line 2039 "y.tab.c"
    break;

  case 44:
#line 306 "exptree.y"
                        { (yyval.DimList) = create_dimlist(NULL); }
#line 2045 "y.tab.c"
    break;

  case 45:
#line 309 "exptree.y"
                                   {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2057 "y.tab.c"
    break;

  case 46:
#line 316 "exptree.y"
                                            {
                Gsymbol* temp = find_gsymbol((yyvsp[-3].node)->varname);
                (yyvsp[-3].node)->Gentry = temp;
                check_not_out_of_bounds((yyvsp[-2].DimList),(yyvsp[-3].node)->Gentry->dimlist);
                (yyvsp[-5].node)->left = (yyvsp[-3].node);
                (yyvsp[-3].node)->dimlist = (yyvsp[-2].DimList);
                (yyval.node) = createTree(0,TYPE_NULL, "Read", READNODE,NULL,(yyvsp[-3].node), NULL, NULL);
            }
#line 2070 "y.tab.c"
    break;

  case 47:
#line 324 "exptree.y"
                                      {
                Gsymbol* entry = find_gsymbol((yyvsp[-2].node)->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,(yyvsp[-2].node), NULL,NULL);
                (yyval.node) = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
#line 2080 "y.tab.c"
    break;

  case 48:
#line 331 "exptree.y"
                                  {
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2089 "y.tab.c"
    break;

  case 49:
#line 337 "exptree.y"
                       {
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-3].node)->varname);
            int varType = get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname);
            if(varType != TYPE_VAR && varType != TYPE_PTR){
                printf("Error: %s is not of variable type\n",(yyvsp[-3].node)->varname);
                exit(1);
            }
            if(ptr2){
                check_data_types(ptr2->type,(yyvsp[-1].node)->type,ptr2->type);
            }else if(ptr1){
                check_data_types(ptr1->type,(yyvsp[-1].node)->type,ptr1->type);
            }else{
                printf("Error: Variable %s Not Declared\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,ptr1,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
        }
#line 2112 "y.tab.c"
    break;

  case 50:
#line 355 "exptree.y"
                                {
            Gsymbol* temp = find_gsymbol((yyvsp[-4].node)->varname);
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is not of array type\n",(yyvsp[-4].node)->varname);
                exit(1);
            }
            check_data_types(temp->type,(yyvsp[-1].node)->type,temp->type);
            (yyvsp[-4].node)->Gentry = temp;
            (yyvsp[-4].node)->dimlist = (yyvsp[-3].DimList);
            check_not_out_of_bounds((yyvsp[-3].DimList),(yyvsp[-4].node)->Gentry->dimlist);
            (yyval.node) = createTree(0,TYPE_ARR, "=", ASSIGNMENT,(yyvsp[-4].node)->Gentry,(yyvsp[-4].node), NULL, (yyvsp[-1].node));
        }
#line 2129 "y.tab.c"
    break;

  case 51:
#line 367 "exptree.y"
                           {  //here i used MUL because lex returnes MUL when the it captures '*'
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-3].node)->varname);
            int varType = get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname);
            if(varType != TYPE_PTR){
                printf("Error: %s is not of pointer type\n",(yyvsp[-3].node)->varname);
                exit(1);
            }
            if(ptr2){
                check_data_types(ptr2->type,(yyvsp[-1].node)->type,ptr2->type);
            }else if(ptr1){
                check_data_types(ptr1->type,(yyvsp[-1].node)->type,ptr1->type);
            }else{
                printf("Error: Variable %s Not Declared\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, NULL,(yyvsp[-3].node), NULL, NULL);
            (yyval.node) = createTree(0,TYPE_PTR, "=", ASSIGNMENT,NULL,t, NULL, (yyvsp[-1].node));
        }
#line 2153 "y.tab.c"
    break;

  case 52:
#line 388 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2159 "y.tab.c"
    break;

  case 53:
#line 389 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2165 "y.tab.c"
    break;

  case 54:
#line 390 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2171 "y.tab.c"
    break;

  case 55:
#line 391 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2177 "y.tab.c"
    break;

  case 56:
#line 392 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2183 "y.tab.c"
    break;

  case 57:
#line 393 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2189 "y.tab.c"
    break;

  case 58:
#line 394 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2195 "y.tab.c"
    break;

  case 59:
#line 395 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2201 "y.tab.c"
    break;

  case 60:
#line 396 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2207 "y.tab.c"
    break;

  case 61:
#line 399 "exptree.y"
                                                       {
            (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-7].node),(yyvsp[-2].node));
        }
#line 2215 "y.tab.c"
    break;

  case 62:
#line 402 "exptree.y"
                                            {
            (yyval.node) = createIfNode((yyvsp[-2].node),(yyvsp[-5].node),NULL);
        }
#line 2223 "y.tab.c"
    break;

  case 63:
#line 407 "exptree.y"
                                                    {
                (yyval.node) = createWhileNode((yyvsp[-2].node),(yyvsp[-5].node));
            }
#line 2231 "y.tab.c"
    break;

  case 64:
#line 412 "exptree.y"
                                           {
                (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
            }
#line 2239 "y.tab.c"
    break;

  case 65:
#line 417 "exptree.y"
                                                      {
                        (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
                    }
#line 2247 "y.tab.c"
    break;

  case 66:
#line 422 "exptree.y"
                           {
                (yyval.node) = createJumpNode(CONTINUENODE);
            }
#line 2255 "y.tab.c"
    break;

  case 67:
#line 425 "exptree.y"
                        {
                (yyval.node) = createJumpNode(BREAKNODE);
            }
#line 2263 "y.tab.c"
    break;

  case 68:
#line 428 "exptree.y"
                           {  
                (yyval.node) = createTree(0, TYPE_NULL, NULL, RETURNNODE, NULL,(yyvsp[-1].node), NULL,NULL);
            }
#line 2271 "y.tab.c"
    break;

  case 69:
#line 433 "exptree.y"
                           {
                (yyval.node) = createTree(0,TYPE_NULL,"BRKP", BREAKPOINTNODE,NULL,NULL, NULL, NULL);
            }
#line 2279 "y.tab.c"
    break;

  case 70:
#line 438 "exptree.y"
               {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "+", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 2288 "y.tab.c"
    break;

  case 71:
#line 442 "exptree.y"
                {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) =  createTree(0, (yyvsp[-2].node)->type , "-", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 2297 "y.tab.c"
    break;

  case 72:
#line 446 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "/", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 2306 "y.tab.c"
    break;

  case 73:
#line 450 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "*", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 2315 "y.tab.c"
    break;

  case 74:
#line 454 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "%", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 2324 "y.tab.c"
    break;

  case 75:
#line 458 "exptree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2332 "y.tab.c"
    break;

  case 76:
#line 461 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2341 "y.tab.c"
    break;

  case 77:
#line 465 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2350 "y.tab.c"
    break;

  case 78:
#line 469 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2359 "y.tab.c"
    break;

  case 79:
#line 473 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2368 "y.tab.c"
    break;

  case 80:
#line 477 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2377 "y.tab.c"
    break;

  case 81:
#line 481 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2386 "y.tab.c"
    break;

  case 82:
#line 485 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL);
        (yyval.node) = createTree(0,TYPE_BOOL,"&&",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2395 "y.tab.c"
    break;

  case 83:
#line 489 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL);
        (yyval.node) = createTree(0,TYPE_BOOL,"||",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2404 "y.tab.c"
    break;

  case 84:
#line 493 "exptree.y"
                 {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
        if(!ptr1 || ptr1->varType != TYPE_FUNCT || ptr1->varType != TYPE_FUNCT_PTR){
            printf("Error: No function with name %s declared\n",(yyvsp[-2].node)->varname);
            exit(0);
        }
        param_list_is_input_args_correct(ptr1->plist, NULL);
        (yyval.node) = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,(yyvsp[-2].node),NULL,NULL);
    }
#line 2418 "y.tab.c"
    break;

  case 85:
#line 502 "exptree.y"
                         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
        print_gsymbol_list(ptr1);
        if(!ptr1 || (ptr1->varType != TYPE_FUNCT && ptr1->varType != TYPE_FUNCT_PTR)){
            printf("Error: No function with name %s declared\n",(yyvsp[-3].node)->varname);
            exit(0);
        }
        param_list_is_input_args_correct(ptr1->plist, (yyvsp[-1].node));
        (yyval.node) = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,(yyvsp[-3].node),NULL,(yyvsp[-1].node));
    }
#line 2433 "y.tab.c"
    break;

  case 86:
#line 512 "exptree.y"
         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);
        int varType = get_var_type(ptr1,ptr2,(yyvsp[0].node)->varname);
        if(varType != TYPE_VAR && varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",(yyvsp[0].node)->varname);
            exit(1);
        }
        (yyval.node) = createTree(0, get_type(ptr1,ptr2,(yyvsp[0].node)->varname), (yyvsp[0].node)->varname, LEAFNODE, ptr1,NULL, NULL,NULL);
    }
#line 2448 "y.tab.c"
    break;

  case 87:
#line 522 "exptree.y"
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
        (yyval.node)->dimlist = (yyvsp[0].DimList);
    }
#line 2467 "y.tab.c"
    break;

  case 88:
#line 536 "exptree.y"
             { //here i used MUL because lex returnes MUL when the it captures '*'
        Gsymbol* temp = find_gsymbol((yyvsp[0].node)->varname);
        (yyvsp[0].node)->Gentry = temp;

        (yyval.node) = createTree(0, TYPE_INT, "*", PTRNODE, temp,(yyvsp[0].node), NULL,NULL);
    }
#line 2478 "y.tab.c"
    break;

  case 89:
#line 542 "exptree.y"
             {
        Gsymbol* temp = find_gsymbol((yyvsp[0].node)->varname);
        (yyvsp[0].node)->Gentry = temp;
        (yyval.node) = createTree(0, TYPE_INT, "&", ADDRNODE, NULL,(yyvsp[0].node), NULL,NULL);
    }
#line 2488 "y.tab.c"
    break;

  case 90:
#line 547 "exptree.y"
             {
        (yyval.node) = createTree(0, TYPE_STRING, (yyvsp[0].string), LEAFNODE,NULL, NULL, NULL,NULL);
    }
#line 2496 "y.tab.c"
    break;

  case 91:
#line 550 "exptree.y"
          {
        (yyval.node) = createTree((yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
    }
#line 2504 "y.tab.c"
    break;

  case 92:
#line 553 "exptree.y"
                {
        (yyval.node) = createTree(-(yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
    }
#line 2512 "y.tab.c"
    break;

  case 93:
#line 557 "exptree.y"
                                  {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT);
                (yyval.DimList) = append_dim_with_id((yyvsp[-3].DimList),(yyvsp[-1].node));
            }
#line 2521 "y.tab.c"
    break;

  case 94:
#line 561 "exptree.y"
                        {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT);
                (yyval.DimList) = append_dim_with_id(NULL,(yyvsp[-1].node));
            }
#line 2530 "y.tab.c"
    break;


#line 2534 "y.tab.c"

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
#line 566 "exptree.y"



void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType){
    Gsymbol* temp = find_gsymbol($2->varname);
    if($1 != temp->type || functionType != temp->varType){
        printf("Error: Incorrect return type for the Function %s\n", $2->varname);
        exit(0);
    }

    is_paramlist_correct(temp->plist,$4);

    print_lsymbol_table();

    
    
    //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome 
    // curr_lsymbol_table = $7;

    ParamList* t = $4;
    int p = getReg();
    fprintf(fptr,"F%d:", temp->flabel);
    fprintf(fptr, "MOV R%d, BP\n", p);
    fprintf(fptr, "PUSH R%d\n", p);
    fprintf(fptr, "MOV BP, SP\n");
    
    int param_list_size = get_paramlist_length($4);

    //setting up the argument values into the respective addresses in the from the local symbol table
    
    while(t){
        fprintf(fptr, "MOV R%d, SP\n", p);
        fprintf(fptr, "SUB R%d, %d\n", p, param_list_size + 3 - 1); //here the 3 is the RETURN VALUE, RETURN ADDRESS, OLD BP and the -1 for preventing the overreduction as subtracting curr_offset u reach the OLD BP 
                                                                    // and from there to reach the return value part u just need to subtract 2 and to reach the 1st arg u just need to subtract the whole paramlist
        fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
        fprintf(fptr, "PUSH R%d\n", p);
        t = t->next;
    }

    // This is to set up space for the locally declared variables in the function
    int curr_offset = get_curr_offset(curr_lsymbol_table) - param_list_size;

    fprintf(fptr, "ADD SP, %d\n", curr_offset);

    freeReg();

    tree_visual_printTree($8);

    Lsymbol* temp1 = curr_lsymbol_table;

    while(param_list_size-- > 0){
        temp1 = temp1->next;
    }

    setup_pointers_codegen(fptr,NULL,temp1);

    codeGen($8,0,0,fptr);
    Lsymbol* a = curr_lsymbol_table;
    // lst_destroy(a);
    curr_lsymbol_table = NULL;
    // ast_destroy($8);
}


void yyerror(char* s){
    printf("Error encountered: %s\n", s);
    exit(1);
}





int main() {
    yyin = fopen("a.txt", "r");
    fptr = fopen("a.xsm", "w");
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
