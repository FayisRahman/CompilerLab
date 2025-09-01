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
    #include "symbol_table.h"
    #include "dim_node.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    

#line 87 "y.tab.c"

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
    DECL = 267,
    ENDDECL = 268,
    PLUS = 269,
    MINUS = 270,
    DIV = 271,
    MUL = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    WHILE = 277,
    DO = 278,
    ENDWHILE = 279,
    REPEAT = 280,
    UNTIL = 281,
    CONTINUE = 282,
    BREAK = 283,
    GT = 284,
    GE = 285,
    LT = 286,
    LE = 287,
    NE = 288,
    EQ = 289,
    MOD = 290
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
#define DECL 267
#define ENDDECL 268
#define PLUS 269
#define MINUS 270
#define DIV 271
#define MUL 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define REPEAT 280
#define UNTIL 281
#define CONTINUE 282
#define BREAK 283
#define GT 284
#define GE 285
#define LT 286
#define LE 287
#define NE 288
#define EQ 289
#define MOD 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "exptree.y"

    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* symbol;
    struct DimNode* DimList;

#line 217 "y.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


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
       2,     2,     2,     2,     2,     2,     2,     2,    43,     2,
      40,    41,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    48,    54,    58,    63,    64,    67,    68,
      71,    83,    84,    87,    90,    95,   106,   115,   118,   121,
     127,   135,   142,   148,   157,   169,   181,   182,   183,   184,
     185,   186,   187,   188,   191,   194,   199,   204,   209,   214,
     217,   223,   227,   231,   235,   239,   243,   246,   250,   254,
     258,   262,   266,   270,   278,   292,   298,   303,   306,   310,
     313
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WRITE", "READ", "INT", "STR", "ID",
  "NUM", "STRING", "begin", "end", "DECL", "ENDDECL", "PLUS", "MINUS",
  "DIV", "MUL", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "REPEAT", "UNTIL", "CONTINUE", "BREAK", "GT", "GE", "LT", "LE", "NE",
  "EQ", "MOD", "';'", "','", "'['", "']'", "'('", "')'", "'='", "'&'",
  "$accept", "Program", "Slist", "Declarations", "DeclList", "Decl",
  "Type", "VarList", "Var", "DimList", "InputStmt", "OutputStmt",
  "AsgStmt", "Stmt", "Ifstmt", "Whilestmt", "DoWhilestmt",
  "RepeatUntiltstmt", "Jumpstmt", "E", "DimAccess", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,    59,    44,    91,    93,
      40,    41,    61,    38
};
# endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,   -10,    39,    27,    29,   325,   -40,   -40,   -40,   -40,
     -40,    55,   -40,    74,    24,    44,   -22,    58,    45,    46,
     325,   325,    51,    52,   258,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,    62,   -18,   -40,
      19,    82,    19,    19,   -21,    59,    19,    19,   337,   270,
     -40,   -40,    64,   -40,    65,   -40,   -40,    74,    67,   -40,
     -40,    95,    19,    99,    41,    -1,   101,   188,   352,    19,
      19,    19,    63,   100,    69,    78,   -40,   112,   -40,    83,
     -40,   122,   -40,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    71,    86,     0,    84,   -40,   -40,
     199,   360,   383,   105,   103,    19,    19,    88,   -40,    -6,
      -6,   -40,   -40,    -2,    -2,    -2,    -2,    -2,    -2,   -40,
     -40,   -40,    92,   104,   -40,   -40,   -40,   325,   325,   144,
     166,   -40,   -40,   -40,   232,   287,   -14,   106,   325,   107,
     108,   -40,   -40,   299,   -40,   -40,   109,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     3,    11,    12,
       7,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,     5,    29,
      30,    31,    32,    33,     6,     8,    18,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     4,    15,    16,    10,     0,    53,    58,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,    13,    54,
      55,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    41,
      42,    43,    44,    47,    49,    48,    50,    51,    52,    45,
      22,    19,     0,     0,    59,    24,    25,     0,     0,     0,
       0,    17,    20,    21,     0,     0,     0,     0,     0,     0,
       0,    37,    38,     0,    35,    36,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -15,   -40,   -40,   135,   -40,   -40,    90,   -40,
     -40,   -40,   -40,   -24,   -40,   -40,   -40,   -40,   -40,   -39,
      25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    24,     5,    11,    12,    13,    38,    39,    54,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    64,
      44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,     3,     4,    67,    68,    48,    49,    72,    73,   128,
      85,    86,    83,    84,    85,    86,    42,    69,    56,    57,
      43,    70,   141,    81,    53,    53,    58,    59,    60,    93,
     100,   101,   102,    93,     8,     9,    61,    42,    69,     6,
      95,   122,    10,     1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    83,    84,    85,    86,    62,
       8,     9,    63,     7,    40,    45,   129,   130,    34,    55,
      87,    88,    89,    90,    91,    92,    93,    83,    84,    85,
      86,    36,    94,    79,    41,    46,    47,    50,    51,    65,
      96,    37,    87,    88,    89,    90,    91,    92,    93,    66,
      76,    71,    80,    77,   103,    42,    82,   120,    97,   105,
      53,    53,   134,   135,    83,    84,    85,    86,   106,    53,
     107,    69,   121,   143,   127,   123,   128,   131,   132,    87,
      88,    89,    90,    91,    92,    93,    83,    84,    85,    86,
     133,   104,   142,   144,   145,   147,    35,    78,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    93,    83,    84,
      85,    86,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,    93,
      83,    84,    85,    86,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,    91,
      92,    93,    83,    84,    85,    86,     0,   137,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,    98,    87,    88,
      89,    90,    91,    92,    93,    14,    15,     0,   124,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,   138,   139,    19,    20,     0,    21,     0,    22,
      23,    14,    15,     0,     0,    16,     0,     0,     0,    52,
       0,     0,     0,    14,    15,    17,    18,    16,     0,     0,
      19,    20,     0,    21,     0,    22,    23,    17,    18,     0,
      14,    15,    19,    20,    16,    21,    75,    22,    23,     0,
       0,     0,    14,    15,    17,    18,    16,     0,     0,    19,
      20,   140,    21,     0,    22,    23,    17,    18,     0,     0,
     146,    19,    20,     0,    21,     0,    22,    23,    14,    15,
       0,     0,    16,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    17,    18,    16,     0,     0,    19,    20,     0,
      21,     0,    22,    23,    17,    18,     0,     0,     0,    74,
      20,     0,    21,     0,    22,    23,    83,    84,    85,    86,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    93,    99,    87,
      88,    89,    90,    91,    92,    93,   125,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    92,    93,   126
};

static const yytype_int16 yycheck[] =
{
      24,    11,    12,    42,    43,    20,    21,    46,    47,    23,
      16,    17,    14,    15,    16,    17,    38,    38,    36,    37,
      42,    42,    36,    62,    48,    49,     7,     8,     9,    35,
      69,    70,    71,    35,     5,     6,    17,    38,    38,     0,
      41,    41,    13,    10,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    14,    15,    16,    17,    40,
       5,     6,    43,    36,    40,     7,   105,   106,    13,     7,
      29,    30,    31,    32,    33,    34,    35,    14,    15,    16,
      17,     7,    41,    58,    40,    40,    40,    36,    36,     7,
      65,    17,    29,    30,    31,    32,    33,    34,    35,    17,
      36,    42,     7,    38,    41,    38,     7,    36,     7,    40,
     134,   135,   127,   128,    14,    15,    16,    17,    40,   143,
       8,    38,    36,   138,    19,    41,    23,    39,    36,    29,
      30,    31,    32,    33,    34,    35,    14,    15,    16,    17,
      36,    41,    36,    36,    36,    36,    11,    57,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    14,    15,
      16,    17,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      14,    15,    16,    17,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    14,    15,    16,    17,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    29,    30,
      31,    32,    33,    34,    35,     3,     4,    -1,    39,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,     3,     4,    -1,    -1,     7,    -1,    -1,    -1,    11,
      -1,    -1,    -1,     3,     4,    17,    18,     7,    -1,    -1,
      22,    23,    -1,    25,    -1,    27,    28,    17,    18,    -1,
       3,     4,    22,    23,     7,    25,    26,    27,    28,    -1,
      -1,    -1,     3,     4,    17,    18,     7,    -1,    -1,    22,
      23,    24,    25,    -1,    27,    28,    17,    18,    -1,    -1,
      21,    22,    23,    -1,    25,    -1,    27,    28,     3,     4,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    17,    18,     7,    -1,    -1,    22,    23,    -1,
      25,    -1,    27,    28,    17,    18,    -1,    -1,    -1,    22,
      23,    -1,    25,    -1,    27,    28,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    29,
      30,    31,    32,    33,    34,    35,    36,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    45,    11,    12,    47,     0,    36,     5,     6,
      13,    48,    49,    50,     3,     4,     7,    17,    18,    22,
      23,    25,    27,    28,    46,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    13,    49,     7,    17,    51,    52,
      40,    40,    38,    42,    64,     7,    40,    40,    46,    46,
      36,    36,    11,    57,    53,     7,    36,    37,     7,     8,
       9,    17,    40,    43,    63,     7,    17,    63,    63,    38,
      42,    42,    63,    63,    22,    26,    36,    38,    52,    64,
       7,    63,     7,    14,    15,    16,    17,    29,    30,    31,
      32,    33,    34,    35,    41,    41,    64,     7,    39,    36,
      63,    63,    63,    41,    41,    40,    40,     8,    41,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      36,    36,    41,    41,    39,    36,    36,    19,    23,    63,
      63,    39,    36,    36,    46,    46,    41,    41,    20,    21,
      24,    36,    36,    46,    36,    36,    21,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    55,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    60,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     1,     3,     2,     2,     1,
       3,     1,     1,     3,     1,     2,     2,     4,     0,     5,
       6,     6,     5,     4,     5,     5,     1,     1,     1,     1,
       1,     1,     1,     1,    10,     8,     8,     7,     7,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     2,     2,     1,     1,     4,
       3
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
#line 44 "exptree.y"
                                           {
            (yyval.node) = (yyvsp[-2].node);
            head = (yyvsp[-2].node);
        }
#line 1543 "y.tab.c"
    break;

  case 3:
#line 48 "exptree.y"
                        {
            exit(0);
        }
#line 1551 "y.tab.c"
    break;

  case 4:
#line 54 "exptree.y"
                     {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,(yyvsp[-1].node), NULL, (yyvsp[0].node));
            (yyval.node) = temp;
        }
#line 1560 "y.tab.c"
    break;

  case 5:
#line 58 "exptree.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1568 "y.tab.c"
    break;

  case 6:
#line 63 "exptree.y"
                                        {stack_address = curr_stack_address;}
#line 1574 "y.tab.c"
    break;

  case 7:
#line 64 "exptree.y"
                               {stack_address = curr_stack_address;}
#line 1580 "y.tab.c"
    break;

  case 10:
#line 71 "exptree.y"
                               {
                Gsymbol* temp = (yyvsp[-1].symbol);
                Gsymbol* temp1 = (yyvsp[-1].symbol);
                while(temp){
                    temp1 = temp->next;
                    temp->next = NULL;
                    add_symbol(temp,(yyvsp[-2].node)->type);
                    temp = temp1;
                }
            }
#line 1595 "y.tab.c"
    break;

  case 11:
#line 83 "exptree.y"
                  {(yyval.node) = createVarNode(TYPE_INT,NULL,NULL,NULL); }
#line 1601 "y.tab.c"
    break;

  case 12:
#line 84 "exptree.y"
                  {(yyval.node) = createVarNode(TYPE_STRING,NULL,NULL,NULL); }
#line 1607 "y.tab.c"
    break;

  case 13:
#line 87 "exptree.y"
                              {
                (yyval.symbol) = append_symbol_id_list((yyvsp[-2].symbol),(yyvsp[0].symbol));         
            }
#line 1615 "y.tab.c"
    break;

  case 14:
#line 90 "exptree.y"
                  {
                (yyval.symbol) = (yyvsp[0].symbol);
            }
#line 1623 "y.tab.c"
    break;

  case 15:
#line 95 "exptree.y"
                     {
            Gsymbol* temp = create_symbol_id_with_dims((yyvsp[-1].node)->varname, (yyvsp[0].DimList));
            (yyvsp[-1].node)->Gentry = temp;
            (yyvsp[-1].node)->type = TYPE_ARR;
            (yyvsp[-1].node)->Gentry->varType = TYPE_ARR;
            if(!(yyvsp[0].DimList)){
                (yyvsp[-1].node)->type = TYPE_VAR;
                (yyvsp[-1].node)->Gentry->varType = TYPE_VAR;
            }
            (yyval.symbol) = temp;
        }
#line 1639 "y.tab.c"
    break;

  case 16:
#line 106 "exptree.y"
                 {
            Gsymbol* temp = create_symbol_id((yyvsp[0].node)->varname, 2);
            (yyvsp[0].node)->Gentry = temp;
            (yyvsp[0].node)->type = TYPE_PTR;
            temp->varType = TYPE_PTR;
            (yyval.symbol) = temp;
        }
#line 1651 "y.tab.c"
    break;

  case 17:
#line 115 "exptree.y"
                              {
            (yyval.DimList) = append_dim((yyvsp[-3].DimList), (yyvsp[-1].node)->val);
        }
#line 1659 "y.tab.c"
    break;

  case 18:
#line 118 "exptree.y"
                        { (yyval.DimList) = create_dimlist(NULL); }
#line 1665 "y.tab.c"
    break;

  case 19:
#line 121 "exptree.y"
                                   {
                Gsymbol* temp = find_symbol((yyvsp[-2].node)->varname);
                (yyvsp[-2].node)->Gentry = temp;
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 1676 "y.tab.c"
    break;

  case 20:
#line 127 "exptree.y"
                                            {
                Gsymbol* temp = find_symbol((yyvsp[-3].node)->varname);
                (yyvsp[-3].node)->Gentry = temp;
                check_not_out_of_bounds((yyvsp[-2].DimList),(yyvsp[-3].node)->Gentry->dimlist);
                (yyvsp[-5].node)->left = (yyvsp[-3].node);
                (yyvsp[-3].node)->dimlist = (yyvsp[-2].DimList);
                (yyval.node) = createTree(0,TYPE_NULL, "Read", READNODE,NULL,(yyvsp[-3].node), NULL, NULL);
            }
#line 1689 "y.tab.c"
    break;

  case 21:
#line 135 "exptree.y"
                                      {
                Gsymbol* entry = find_symbol((yyvsp[-2].node)->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,(yyvsp[-2].node), NULL,NULL);
                (yyval.node) = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
#line 1699 "y.tab.c"
    break;

  case 22:
#line 142 "exptree.y"
                                  {
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 1708 "y.tab.c"
    break;

  case 23:
#line 148 "exptree.y"
                       {
            Gsymbol* temp = find_symbol((yyvsp[-3].node)->varname);
            if(temp->varType != TYPE_VAR && temp->varType != TYPE_PTR){
                printf("Error: %s is not of variable type\n",(yyvsp[-3].node)->varname);
                exit(1);
            }
            check_data_types(temp->type,(yyvsp[-1].node)->type,temp->type);
            (yyval.node) = createTree(0,TYPE_VAR, "=", EQUAL,temp,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
        }
#line 1722 "y.tab.c"
    break;

  case 24:
#line 157 "exptree.y"
                                {
            Gsymbol* temp = find_symbol((yyvsp[-4].node)->varname);
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is not of array type\n",(yyvsp[-4].node)->varname);
                exit(1);
            }
            check_data_types(temp->type,(yyvsp[-1].node)->type,temp->type);
            (yyvsp[-4].node)->Gentry = temp;
            (yyvsp[-4].node)->dimlist = (yyvsp[-3].DimList);
            check_not_out_of_bounds((yyvsp[-3].DimList),(yyvsp[-4].node)->Gentry->dimlist);
            (yyval.node) = createTree(0,TYPE_ARR, "=", EQUAL,(yyvsp[-4].node)->Gentry,(yyvsp[-4].node), NULL, (yyvsp[-1].node));
        }
#line 1739 "y.tab.c"
    break;

  case 25:
#line 169 "exptree.y"
                           {  //here i used MUL because lex returnes MUL when the it captures '*'
            Gsymbol* temp = find_symbol((yyvsp[-3].node)->varname);
            if(temp->varType != TYPE_PTR){
                printf("Error: %s is not of pointer type\n",(yyvsp[-3].node)->varname);
                exit(1);
            }
            check_data_types(temp->type,(yyvsp[-1].node)->type,temp->type);
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, temp,(yyvsp[-3].node), NULL, NULL);
            (yyval.node) = createTree(0,TYPE_PTR, "=", EQUAL,NULL,t, NULL, (yyvsp[-1].node));
        }
#line 1754 "y.tab.c"
    break;

  case 26:
#line 181 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1760 "y.tab.c"
    break;

  case 27:
#line 182 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1766 "y.tab.c"
    break;

  case 28:
#line 183 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1772 "y.tab.c"
    break;

  case 29:
#line 184 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1778 "y.tab.c"
    break;

  case 30:
#line 185 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1784 "y.tab.c"
    break;

  case 31:
#line 186 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1790 "y.tab.c"
    break;

  case 32:
#line 187 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1796 "y.tab.c"
    break;

  case 33:
#line 188 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1802 "y.tab.c"
    break;

  case 34:
#line 191 "exptree.y"
                                                       {
            (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-7].node),(yyvsp[-2].node));
        }
#line 1810 "y.tab.c"
    break;

  case 35:
#line 194 "exptree.y"
                                            {
            (yyval.node) = createIfNode((yyvsp[-2].node),(yyvsp[-5].node),NULL);
        }
#line 1818 "y.tab.c"
    break;

  case 36:
#line 199 "exptree.y"
                                                    {
                (yyval.node) = createWhileNode((yyvsp[-2].node),(yyvsp[-5].node));
            }
#line 1826 "y.tab.c"
    break;

  case 37:
#line 204 "exptree.y"
                                           {
                (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
            }
#line 1834 "y.tab.c"
    break;

  case 38:
#line 209 "exptree.y"
                                                      {
                        (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
                    }
#line 1842 "y.tab.c"
    break;

  case 39:
#line 214 "exptree.y"
                           {
                (yyval.node) = createJumpNode(CONTINUENODE);
            }
#line 1850 "y.tab.c"
    break;

  case 40:
#line 217 "exptree.y"
                        {
                (yyval.node) = createJumpNode(BREAKNODE);
            }
#line 1858 "y.tab.c"
    break;

  case 41:
#line 223 "exptree.y"
               {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "+", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 1867 "y.tab.c"
    break;

  case 42:
#line 227 "exptree.y"
                {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) =  createTree(0, (yyvsp[-2].node)->type , "-", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 1876 "y.tab.c"
    break;

  case 43:
#line 231 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "/", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 1885 "y.tab.c"
    break;

  case 44:
#line 235 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "*", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 1894 "y.tab.c"
    break;

  case 45:
#line 239 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "%", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
    }
#line 1903 "y.tab.c"
    break;

  case 46:
#line 243 "exptree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1911 "y.tab.c"
    break;

  case 47:
#line 246 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 1920 "y.tab.c"
    break;

  case 48:
#line 250 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 1929 "y.tab.c"
    break;

  case 49:
#line 254 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 1938 "y.tab.c"
    break;

  case 50:
#line 258 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 1947 "y.tab.c"
    break;

  case 51:
#line 262 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 1956 "y.tab.c"
    break;

  case 52:
#line 266 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT);
        (yyval.node) = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 1965 "y.tab.c"
    break;

  case 53:
#line 270 "exptree.y"
         {
        Gsymbol* temp = find_symbol((yyvsp[0].node)->varname);
        if(temp->varType != TYPE_VAR && temp->varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",(yyvsp[0].node)->varname);
            exit(1);
        }
        (yyval.node) = createTree(0, temp->type, (yyvsp[0].node)->varname, LEAFNODE, temp,NULL, NULL,NULL);
    }
#line 1978 "y.tab.c"
    break;

  case 54:
#line 278 "exptree.y"
                   {
        Gsymbol* temp = find_symbol((yyvsp[-1].node)->varname);
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
#line 1997 "y.tab.c"
    break;

  case 55:
#line 292 "exptree.y"
             { //here i used MUL because lex returnes MUL when the it captures '*'
        Gsymbol* temp = find_symbol((yyvsp[0].node)->varname);
        (yyvsp[0].node)->Gentry = temp;

        (yyval.node) = createTree(0, TYPE_INT, "*", PTRNODE, temp,(yyvsp[0].node), NULL,NULL);
    }
#line 2008 "y.tab.c"
    break;

  case 56:
#line 298 "exptree.y"
             {
        Gsymbol* temp = find_symbol((yyvsp[0].node)->varname);
        (yyvsp[0].node)->Gentry = temp;
        (yyval.node) = createTree(0, TYPE_INT, "&", ADDRNODE, NULL,(yyvsp[0].node), NULL,NULL);
    }
#line 2018 "y.tab.c"
    break;

  case 57:
#line 303 "exptree.y"
             {
        (yyval.node) = createTree(0, TYPE_STRING, (yyvsp[0].string), LEAFNODE,NULL, NULL, NULL,NULL);
    }
#line 2026 "y.tab.c"
    break;

  case 58:
#line 306 "exptree.y"
          {
        (yyval.node) = createTree((yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
    }
#line 2034 "y.tab.c"
    break;

  case 59:
#line 310 "exptree.y"
                                  {
               (yyval.DimList) = append_dim_with_id(NULL,(yyvsp[-1].node));
            }
#line 2042 "y.tab.c"
    break;

  case 60:
#line 313 "exptree.y"
                        {
                (yyval.DimList) = append_dim_with_id(NULL,(yyvsp[-1].node));
            }
#line 2050 "y.tab.c"
    break;


#line 2054 "y.tab.c"

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
#line 317 "exptree.y"




void printNode(struct tnode* node) {
    if (node == NULL) return;
    switch (node->nodetype) {
        case READNODE:
            printf("READ Node\n");
            break;
        case WRITENODE:
            printf("WRITE Node\n");
            break;
        case CONNECTOR:
            printf("CONNECTOR Node\n");
            break;
        case OPERATOR:
            printf("OPERATOR Node: %s\n", node->varname); // e.g. "+"
            break;
        case EQUAL:
            printf("ASSIGNMENT Node (=)\n");
            break;
        case LEAFNODE:
            if (node->varname != NULL) {
                printf("LEAF Node (Variable): %s\n", node->varname);
            } else {
                printf("LEAF Node (Constant): %d\n", node->val);
            }
            break;
        default:
            printf("Unknown Node Type\n");
    }

}



void yyerror(char* s){
    printf("Error encountered: %s\n", s);
    exit(1);
}

void postfixPrint(struct tnode* head){
    if(!head)return;
    if(!head->middle && !head->right){
        if (head->varname != NULL) printf("%s ", head->varname);
        else printf("%d ", head->val);
        return;
    }
    postfixPrint(head->middle);
    postfixPrint(head->right);
    printf("%s ", head->varname);
}



int main() {
    yyin = fopen("a.txt", "r");
    yyparse();
    print_symbol_table();
    FILE* fptr = fopen("a.xsm", "w");
    make_header(fptr);
    setup_pointers_codegen(fptr);
    codeGen(head,0,0,fptr);
    exit_footer(fptr);
    create_label_with_message(fptr,101,"IndexOutOfBounds");
    /* codeIntrepret(head); */
    return 0;
}
