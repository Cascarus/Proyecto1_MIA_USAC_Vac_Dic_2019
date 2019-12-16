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
#line 1 "parser.yy" /* yacc.c:339  */

  #include "Bison/scanner.h"
  #include "procedures.h"
  extern int yylineno;
  extern int column;
  extern int line;
  extern char *yytext;
  extern NodeAST *root;

  int yyerror(const char* mens)
  {
    Procedures::writeError(mens + QString::fromUtf8(" Linea: ") + QString::number(line+1) + QString::fromUtf8(" Columna: ") + QString::number(column+1) + QString::fromUtf8(" Simbolo: ") + yytext);
    return 0;
  }

#line 82 "parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    RW_Add = 258,
    RW_Cat = 259,
    RW_Chgrp = 260,
    RW_Chmod = 261,
    RW_Chown = 262,
    RW_Cont = 263,
    RW_Cp = 264,
    RW_Delete = 265,
    RW_Destiny = 266,
    RW_Edit = 267,
    RW_Exec = 268,
    RW_Fdisk = 269,
    RW_File = 270,
    RW_Filen = 271,
    RW_Find = 272,
    RW_Fit = 273,
    RW_Grp = 274,
    RW_Id = 275,
    RW_Idn = 276,
    RW_Login = 277,
    RW_Logout = 278,
    RW_Loss = 279,
    RW_Mkdir = 280,
    RW_Mkdisk = 281,
    RW_Mkfile = 282,
    RW_Mkfs = 283,
    RW_Mkgrp = 284,
    RW_Mkusr = 285,
    RW_Mount = 286,
    RW_Mv = 287,
    RW_Name = 288,
    RW_P = 289,
    RW_Path = 290,
    RW_Pause = 291,
    RW_Pwd = 292,
    RW_R = 293,
    RW_Recovery = 294,
    RW_Ren = 295,
    RW_Rep = 296,
    RW_Rf = 297,
    RW_Rm = 298,
    RW_Rmdisk = 299,
    RW_Rmgrp = 300,
    RW_Rmusr = 301,
    RW_Ruta = 302,
    RW_Size = 303,
    RW_Type = 304,
    RW_Ugo = 305,
    RW_Unit = 306,
    RW_Unmount = 307,
    RW_Usr = 308,
    SYM_Arrow = 309,
    SYM_Ampersand = 310,
    SYM_Hyphen = 311,
    RE_Delete = 312,
    RE_Fit = 313,
    RE_Id = 314,
    RE_Name = 315,
    RE_Name2 = 316,
    RE_Number = 317,
    RE_Path = 318,
    RE_String = 319,
    RE_Type = 320,
    RE_Unit = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "parser.yy" /* yacc.c:355  */

  char TEXT [256];
  class NodeAST *nodo;

#line 194 "parser.cpp" /* yacc.c:355  */
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

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 225 "parser.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
#define YYFINAL  112
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   524

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  445

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   176,   182,   188,   191,   194,   197,   200,
     203,   206,   209,   212,   215,   218,   221,   224,   227,   230,
     233,   236,   239,   242,   245,   248,   251,   254,   257,   260,
     263,   266,   269,   272,   275,   280,   287,   294,   298,   302,
     306,   311,   318,   325,   329,   333,   337,   341,   346,   353,
     360,   364,   368,   372,   376,   380,   385,   392,   399,   403,
     407,   411,   415,   419,   423,   428,   435,   442,   446,   450,
     454,   458,   462,   467,   474,   481,   485,   489,   493,   497,
     501,   511,   521,   526,   533,   540,   544,   548,   552,   556,
     560,   564,   568,   572,   576,   580,   584,   588,   593,   600,
     607,   611,   615,   619,   623,   627,   632,   639,   646,   650,
     654,   658,   662,   666,   670,   674,   684,   689,   696,   703,
     707,   711,   715,   719,   724,   731,   738,   742,   746,   750,
     754,   758,   763,   770,   777,   781,   785,   789,   793,   797,
     801,   806,   813,   820,   824,   828,   833,   840,   847,   851,
     855,   859,   864,   871,   878,   882,   886,   890,   894,   898,
     902,   906,   910,   915,   922,   929,   933,   937,   941,   945,
     950,   957,   964,   968,   972,   976,   980,   984,   988,   998,
    1003,  1010,  1017,  1021,  1025,  1029,  1033,  1037,  1042,  1049,
    1056,  1060,  1064,  1068,  1072,  1076,  1080,  1084,  1089,  1096,
    1103,  1107,  1111,  1115,  1119,  1129,  1139,  1144,  1151,  1158,
    1162,  1166,  1170,  1175,  1182,  1189,  1193,  1197,  1201,  1206,
    1213,  1220
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RW_Add", "RW_Cat", "RW_Chgrp",
  "RW_Chmod", "RW_Chown", "RW_Cont", "RW_Cp", "RW_Delete", "RW_Destiny",
  "RW_Edit", "RW_Exec", "RW_Fdisk", "RW_File", "RW_Filen", "RW_Find",
  "RW_Fit", "RW_Grp", "RW_Id", "RW_Idn", "RW_Login", "RW_Logout",
  "RW_Loss", "RW_Mkdir", "RW_Mkdisk", "RW_Mkfile", "RW_Mkfs", "RW_Mkgrp",
  "RW_Mkusr", "RW_Mount", "RW_Mv", "RW_Name", "RW_P", "RW_Path",
  "RW_Pause", "RW_Pwd", "RW_R", "RW_Recovery", "RW_Ren", "RW_Rep", "RW_Rf",
  "RW_Rm", "RW_Rmdisk", "RW_Rmgrp", "RW_Rmusr", "RW_Ruta", "RW_Size",
  "RW_Type", "RW_Ugo", "RW_Unit", "RW_Unmount", "RW_Usr", "SYM_Arrow",
  "SYM_Ampersand", "SYM_Hyphen", "RE_Delete", "RE_Fit", "RE_Id", "RE_Name",
  "RE_Name2", "RE_Number", "RE_Path", "RE_String", "RE_Type", "RE_Unit",
  "$accept", "Start", "NT_Instructions", "NT_Instruction", "NT_Cat",
  "NT_Parameterscat", "NT_Parametercat", "NT_Chgrp", "NT_Parameterschgrp",
  "NT_Parameterchgrp", "NT_Chmod", "NT_Parameterschmod",
  "NT_Parameterchmod", "NT_Chown", "NT_Parameterschown",
  "NT_Parameterchown", "NT_Cp", "NT_Parameterscp", "NT_Parametercp",
  "NT_Edit", "NT_Parametersedit", "NT_Parameteredit", "NT_Exec",
  "NT_Fdisk", "NT_Parametersfdisk", "NT_Parameterfdisk", "NT_Find",
  "NT_Parametersfind", "NT_Parameterfind", "NT_Login",
  "NT_Parameterslogin", "NT_Parameterlogin", "NT_Logout", "NT_Loss",
  "NT_Mkdir", "NT_Parametersmkdir", "NT_Parametermkdir", "NT_Mkdisk",
  "NT_Parametersmkdisk", "NT_Parametermkdisk", "NT_Mkfile",
  "NT_Parametersmkfile", "NT_Parametermkfile", "NT_Mkfs",
  "NT_Parametersmkfs", "NT_Parametermkfs", "NT_Mkgrp",
  "NT_Parametersmkgrp", "NT_Parametermkgrp", "NT_Mkusr",
  "NT_Parametersmkusr", "NT_Parametermkusr", "NT_Mount",
  "NT_Parametersmount", "NT_Parametermount", "NT_Mv", "NT_Parametersmv",
  "NT_Parametermv", "NT_Pause", "NT_Recovery", "NT_Ren",
  "NT_Parametersren", "NT_Parameterren", "NT_Rep", "NT_Parametersrep",
  "NT_Parameterrep", "NT_Rm", "NT_Parametersrm", "NT_Parameterrm",
  "NT_Rmdisk", "NT_Rmgrp", "NT_Parametersrmgrp", "NT_Parameterrmgrp",
  "NT_Rmusr", "NT_Parametersrmusr", "NT_Parameterrmusr", "NT_Unmount",
  "NT_Parametersunmount", "NT_Parameterunmount", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,   -40,     3,    20,    34,    44,    65,    90,   133,   134,
     135,   -51,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   -51,   145,   146,   147,   148,   149,   150,   151,   152,
       7,    -4,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   102,   153,    11,   154,    52,   155,    27,   156,
      63,   157,    25,   158,   179,    28,   160,    80,   161,    32,
     162,    46,    36,   163,    59,   164,     9,   165,    33,   166,
      75,   167,    31,   168,   106,   169,    77,   170,   206,    81,
     172,    58,   173,    61,   174,   195,    84,   176,    14,   177,
     212,   180,   -51,   -51,   182,   183,   -51,   102,   184,   185,
     -51,    11,   186,   187,   -51,   188,   -51,    52,   189,   190,
     -51,   191,   -51,    27,   192,   193,   194,   -51,    63,   196,
     197,   198,   199,   -51,    25,   200,   201,   202,   203,   204,
     205,   207,   208,   209,   -51,    28,   210,   211,   213,   -51,
      80,   214,   215,   216,   -51,    32,   217,   218,   -51,   219,
     -51,    36,   220,   221,   222,   223,   -51,    59,   224,   225,
     -51,   226,   227,   -51,     9,   228,   229,   -51,    33,   230,
     231,   -51,    75,   232,   233,   234,   235,   -51,    31,   236,
     237,   -51,   106,   238,   239,   240,   -51,    77,   241,   242,
     243,   244,   -51,    81,   245,   246,   247,   248,   -51,    58,
     249,   250,   -51,   -51,    61,   251,   252,   253,   -51,    84,
     254,   255,   -51,    14,   256,   -51,   212,    85,   175,   -51,
      -5,    60,   -51,   257,    87,   258,   -51,   259,    89,    62,
     -51,    91,   260,    93,   -51,   261,   262,    95,   264,   -51,
      97,   -50,   265,   266,    64,    99,   267,    21,   268,   -51,
     269,    82,   101,   -51,   271,   -48,    66,   -51,   272,   273,
     103,   -51,   274,   105,   275,   270,   -51,   263,   279,   107,
     277,   -51,   281,   276,   -51,   282,    68,   -51,    70,   283,
      47,    72,   -51,    74,   109,   -51,   111,   284,   113,   -51,
     285,   286,    83,   115,   -51,   287,   -11,   117,   119,   -51,
     288,   121,   -51,   123,   289,    76,   -51,   290,    78,   -51,
     291,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     292,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    28,    29,    27,    30,    31,
      32,    33,     0,    34,     0,    40,     0,    47,     0,    55,
       0,    64,     0,    72,     0,     0,    82,     0,    97,     0,
     105,     0,     0,   116,     0,   123,     0,   131,     0,   140,
       0,   145,     0,   151,     0,   162,     0,   169,     0,     0,
     179,     0,   187,     0,   197,     0,     0,   206,     0,   212,
       0,   218,     1,     3,     0,     0,    36,     0,     0,     0,
      42,     0,     0,     0,    54,     0,    49,     0,     0,     0,
      61,     0,    57,     0,     0,     0,     0,    66,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,    99,
       0,     0,     0,     0,   107,     0,     0,     0,   122,     0,
     118,     0,     0,     0,     0,     0,   125,     0,     0,     0,
     137,     0,     0,   133,     0,     0,     0,   142,     0,     0,
       0,   147,     0,     0,     0,     0,     0,   153,     0,     0,
       0,   164,     0,     0,     0,     0,   171,     0,     0,     0,
       0,     0,   181,     0,     0,     0,     0,     0,   189,     0,
       0,     0,   203,   199,     0,     0,     0,     0,   208,     0,
       0,     0,   214,     0,     0,   220,     0,     0,     0,    35,
       0,     0,    41,     0,     0,     0,    48,     0,     0,     0,
      56,     0,     0,     0,    65,     0,     0,     0,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,    98,     0,     0,     0,   106,     0,     0,
       0,   117,     0,     0,     0,     0,   124,     0,     0,     0,
       0,   132,     0,     0,   141,     0,     0,   146,     0,     0,
       0,     0,   152,     0,     0,   163,     0,     0,     0,   170,
       0,     0,     0,     0,   180,     0,     0,     0,     0,   188,
       0,     0,   198,     0,     0,     0,   207,     0,     0,   213,
       0,   219,    39,    38,    37,    45,    46,    43,    44,    52,
      50,    51,    53,    60,    58,    59,    62,    63,    70,    71,
      69,    67,    68,    79,    77,    75,    76,    78,    80,    81,
       0,    95,    92,    91,    94,    93,    87,    88,    85,    90,
      89,    86,   102,   103,   104,   100,   101,   113,   110,   112,
     111,   108,   109,   115,   121,   119,   120,   130,   129,   128,
     126,   127,   139,   136,   134,   135,   138,   143,   144,   148,
     149,   150,   160,   161,   156,   157,   159,   158,   154,   155,
     168,   167,   165,   166,   174,   175,   176,   172,   173,   178,
     184,   185,   186,   182,   183,   194,   191,   190,   192,   193,
     195,   196,   202,   200,   201,   205,   204,   211,   209,   210,
     217,   215,   216,   221,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -51,   280,   -51,   -51,   132,   -51,   -51,   278,
     -51,   -51,   293,   -51,   -51,   127,   -51,   -51,   128,   -51,
     -51,   171,   -51,   -51,   -51,   159,   -51,   -51,   294,   -51,
     -51,   295,   -51,   -51,   -51,   -51,   181,   -51,   -51,   178,
     -51,   -51,   129,   -51,   -51,   124,   -51,   -51,   125,   -51,
     -51,   296,   -51,   -51,   297,   -51,   -51,   116,   -51,   -51,
     -51,   -51,   298,   -51,   -51,   299,   -51,   -51,   300,   -51,
     -51,   -51,   122,   -51,   -51,   120,   -51,   -51,   126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,    31,    32,    33,    63,   116,    34,    65,   120,
      35,    67,   126,    36,    69,   132,    37,    71,   137,    38,
      73,   143,    39,    40,    76,   154,    41,    78,   159,    42,
      80,   164,    43,    44,    45,    83,   170,    46,    85,   176,
      47,    87,   183,    48,    89,   187,    49,    91,   191,    50,
      93,   197,    51,    95,   201,    52,    97,   206,    53,    54,
      55,   100,   212,    56,   102,   218,    57,   104,   223,    58,
      59,   107,   228,    60,   109,   232,    61,   111,   235
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       1,     2,     3,     4,   426,     5,   360,   112,     6,     7,
       8,   378,   361,     9,   379,    62,   380,   178,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   179,
     118,   146,    21,   139,   230,    22,    23,    24,   147,    25,
      26,    27,    28,   180,   181,   140,   148,   128,    29,   427,
     193,   194,   161,   185,   335,   369,   167,   182,    64,   336,
     141,   149,   129,   150,   119,   130,   166,   231,   195,   162,
     168,   169,   122,   142,   134,    66,   151,   152,   214,   153,
     131,   220,   186,   135,   196,   163,   370,   123,   203,    68,
     124,   215,   172,   216,   173,   189,   221,   204,   136,    70,
     156,   209,   125,   222,   226,   217,   405,   174,   190,   406,
     175,   407,   205,   157,   210,   158,   211,   227,   114,   337,
      72,   346,   115,   364,   338,   381,   347,   400,   365,   402,
     382,   408,   401,   410,   403,   438,   409,   441,   411,   199,
     439,   200,   442,   373,   421,    74,   374,   422,   332,   333,
     340,   341,   344,   345,   348,   349,   351,   352,   355,   356,
     358,   359,   366,   367,   375,   376,   385,   386,   388,   389,
     394,   395,   412,   413,   414,   415,   417,   418,   423,   424,
     428,   429,   430,   431,   433,   434,   435,   436,    75,    77,
      79,    81,    82,    84,    86,    88,    90,    92,    94,    96,
      98,    99,   101,   103,   105,   106,   108,   110,   117,   121,
     127,   133,   138,   144,   145,   155,   160,   165,   171,   177,
     184,   188,   192,   198,   202,   207,   208,   213,   219,   224,
     225,   229,   233,   234,   334,   236,   237,   238,   240,   241,
     243,   244,   245,   247,   248,   249,   251,   252,   253,   239,
     255,   256,   257,   258,   260,   261,   262,   263,   264,   265,
     250,   266,   267,   268,   270,   271,   254,   272,   274,   275,
     276,   278,   279,   280,   282,   283,   284,   285,   287,   288,
     289,   290,   292,   293,   295,   296,   298,   299,   300,   301,
     303,   304,   306,   307,   308,   310,   311,   312,   313,   315,
     316,   317,   318,   320,   321,   323,   324,   325,   327,   328,
     330,   113,   294,   291,   269,   259,   339,   297,   343,   350,
     342,   354,   362,   309,   363,   353,   357,   392,   372,   368,
     377,   383,   384,   398,   371,   387,   391,   390,   393,   396,
     397,   399,   404,   416,   419,   420,   425,   432,   437,   440,
     443,   326,   281,   329,   444,   286,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,     0,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   302,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   319,     0,
       0,     0,     0,     0,   322
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,     7,    15,     9,    56,     0,    12,    13,
      14,    59,    62,    17,    62,    55,    64,     8,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    20,
      19,     3,    36,     8,    20,    39,    40,    41,    10,    43,
      44,    45,    46,    34,    35,    20,    18,    20,    52,    60,
      19,    20,    20,    20,    59,    34,    20,    48,    55,    64,
      35,    33,    35,    35,    53,    38,    20,    53,    37,    37,
      34,    35,    20,    48,    11,    55,    48,    49,    20,    51,
      53,    20,    49,    20,    53,    53,    65,    35,    11,    55,
      38,    33,    33,    35,    35,    20,    35,    20,    35,    55,
      20,    20,    50,    42,    20,    47,    59,    48,    33,    62,
      51,    64,    35,    33,    33,    35,    35,    33,    16,    59,
      55,    59,    20,    59,    64,    59,    64,    59,    64,    59,
      64,    59,    64,    59,    64,    59,    64,    59,    64,    33,
      64,    35,    64,    61,    61,    55,    64,    64,    63,    64,
      63,    64,    63,    64,    63,    64,    63,    64,    63,    64,
      63,    64,    63,    64,    63,    64,    63,    64,    63,    64,
      63,    64,    63,    64,    63,    64,    63,    64,    63,    64,
      63,    64,    63,    64,    63,    64,    63,    64,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    35,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    20,    55,    55,    55,
      35,    55,    55,    21,    59,    55,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,   117,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
     133,    54,    54,    54,    54,    54,   138,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    31,   188,   184,   155,   144,    59,   192,    59,    59,
      62,    59,    57,   207,    58,    64,    62,    64,    59,    62,
      59,    59,    59,    57,    66,    61,    66,    62,    59,    62,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,   229,   171,   233,    62,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,   224
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     9,    12,    13,    14,    17,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    36,    39,    40,    41,    43,    44,    45,    46,    52,
      68,    69,    70,    71,    74,    77,    80,    83,    86,    89,
      90,    93,    96,    99,   100,   101,   104,   107,   110,   113,
     116,   119,   122,   125,   126,   127,   130,   133,   136,   137,
     140,   143,    55,    72,    55,    75,    55,    78,    55,    81,
      55,    84,    55,    87,    55,    55,    91,    55,    94,    55,
      97,    55,    55,   102,    55,   105,    55,   108,    55,   111,
      55,   114,    55,   117,    55,   120,    55,   123,    55,    55,
     128,    55,   131,    55,   134,    55,    55,   138,    55,   141,
      55,   144,     0,    70,    16,    20,    73,    55,    19,    53,
      76,    55,    20,    35,    38,    50,    79,    55,    20,    35,
      38,    53,    82,    55,    11,    20,    35,    85,    55,     8,
      20,    35,    48,    88,    55,    35,     3,    10,    18,    33,
      35,    48,    49,    51,    92,    55,    20,    33,    35,    95,
      55,    20,    37,    53,    98,    55,    20,    20,    34,    35,
     103,    55,    33,    35,    48,    51,   106,    55,     8,    20,
      34,    35,    48,   109,    55,    20,    49,   112,    55,    20,
      33,   115,    55,    19,    20,    37,    53,   118,    55,    33,
      35,   121,    55,    11,    20,    35,   124,    55,    20,    20,
      33,    35,   129,    55,    20,    33,    35,    47,   132,    55,
      20,    35,    42,   135,    55,    35,    20,    33,   139,    55,
      20,    53,   142,    55,    21,   145,    55,    54,    54,    73,
      54,    54,    76,    54,    54,    54,    79,    54,    54,    54,
      82,    54,    54,    54,    85,    54,    54,    54,    54,    88,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    92,
      54,    54,    54,    95,    54,    54,    54,    98,    54,    54,
      54,   103,    54,    54,    54,    54,   106,    54,    54,    54,
      54,   109,    54,    54,   112,    54,    54,   115,    54,    54,
      54,    54,   118,    54,    54,   121,    54,    54,    54,   124,
      54,    54,    54,    54,   129,    54,    54,    54,    54,   132,
      54,    54,   135,    54,    54,    54,   139,    54,    54,   142,
      54,   145,    63,    64,    59,    59,    64,    59,    64,    59,
      63,    64,    62,    59,    63,    64,    59,    64,    63,    64,
      59,    63,    64,    64,    59,    63,    64,    62,    63,    64,
      56,    62,    57,    58,    59,    64,    63,    64,    62,    34,
      65,    66,    59,    61,    64,    63,    64,    59,    59,    62,
      64,    59,    64,    59,    59,    63,    64,    61,    63,    64,
      62,    66,    64,    59,    63,    64,    62,    59,    57,    59,
      59,    64,    59,    64,    59,    59,    62,    64,    59,    64,
      59,    64,    63,    64,    63,    64,    59,    63,    64,    59,
      59,    61,    64,    63,    64,    59,    15,    60,    63,    64,
      63,    64,    59,    63,    64,    63,    64,    59,    59,    64,
      59,    59,    64,    59,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    72,    72,    73,    73,    73,
      74,    75,    75,    76,    76,    76,    76,    77,    78,    78,
      79,    79,    79,    79,    79,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    83,    84,    84,    85,    85,    85,
      85,    85,    86,    87,    87,    88,    88,    88,    88,    88,
      89,    89,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    94,    94,
      95,    95,    95,    95,    95,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    99,   100,   101,   102,   102,   103,
     103,   103,   103,   104,   105,   105,   106,   106,   106,   106,
     106,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     110,   111,   111,   112,   112,   113,   114,   114,   115,   115,
     115,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   120,   120,   121,   121,   121,   121,   122,
     123,   123,   124,   124,   124,   124,   124,   125,   126,   127,
     128,   128,   129,   129,   129,   129,   129,   130,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   133,   134,   134,
     135,   135,   135,   135,   136,   136,   137,   138,   138,   139,
     139,   139,   140,   141,   141,   142,   142,   142,   143,   144,
     144,   145
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     2,     3,     3,     3,
       2,     3,     2,     3,     3,     3,     3,     2,     3,     2,
       3,     3,     3,     3,     1,     2,     3,     2,     3,     3,
       3,     1,     3,     3,     2,     3,     2,     3,     3,     3,
       3,     3,     2,     3,     2,     3,     3,     3,     3,     3,
       5,     5,     2,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     2,     3,     2,
       3,     3,     3,     3,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     5,     2,     3,     2,     3,
       3,     3,     1,     2,     3,     2,     3,     3,     3,     3,
       3,     2,     3,     2,     3,     3,     3,     1,     3,     3,
       2,     3,     2,     3,     3,     2,     3,     2,     3,     3,
       3,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     2,     3,     3,     3,     3,     2,
       3,     2,     3,     3,     3,     3,     3,     1,     5,     2,
       3,     2,     3,     3,     3,     3,     3,     2,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     2,
       3,     3,     3,     1,     5,     5,     2,     3,     2,     3,
       3,     3,     2,     3,     2,     3,     3,     3,     2,     3,
       2,     3
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
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 173 "parser.yy" /* yacc.c:1646  */
    {
                            root = (yyvsp[0].nodo);
                        }
#line 1747 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 176 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-1].nodo);
                            NodeAST *node = new NodeAST( (yylsp[0]).first_line,(yylsp[0]).first_column,"NTINSTRUCTION","NTINSTRUCTION");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                        }
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 182 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTINSTRUCTIONS","NTINSTRUCTIONS");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTINSTRUCTION","NTINSTRUCTION");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                        }
#line 1769 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 188 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 191 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 194 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1793 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 197 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 200 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1809 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 203 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1817 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 206 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 209 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1833 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 212 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 215 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1849 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1857 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 221 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1865 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 224 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1873 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 227 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1881 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 230 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1889 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 233 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1897 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 236 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1905 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 239 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1913 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 242 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1921 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 245 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1929 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 248 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1937 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 251 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1945 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 254 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1953 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 257 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1961 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 260 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1969 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 263 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1977 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 266 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1985 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 269 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 1993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 272 "parser.yy" /* yacc.c:1646  */
    { 
                            (yyval.nodo)=(yyvsp[0].nodo);
                        }
#line 2001 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 275 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTCAT","NTCAT");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2011 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 280 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERCAT","NTPARAMETERCAT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2023 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 287 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSCAT","NTPARAMETERSCAT");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERCAT","NTPARAMETERCAT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2035 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 294 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2044 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 298 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ARCHIVE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 302 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ARCHIVE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2062 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 306 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTCHGRP","NTCHGRP");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2072 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 311 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERCHGRP","NTPARAMETERCHGRP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2084 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 318 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSCHGRP","NTPARAMETERSCHGRP");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERCHGRP","NTPARAMETERCHGRP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2096 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 325 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2105 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 329 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2114 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 333 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"GRP",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 337 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"GRP",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 341 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTCHMOD","NTCHMOD");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 346 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERCHMOD","NTPARAMETERCHMOD");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2154 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 353 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSCHMOD","NTPARAMETERSCHMOD");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERCHMOD","NTPARAMETERCHMOD");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2166 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 360 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2175 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 364 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2184 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 368 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2193 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 372 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"UGO",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2202 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 376 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"R","1");
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2211 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 380 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTCHOWN","NTCHOWN");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2221 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 385 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERCHOWN","NTPARAMETERCHOWN");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2233 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 392 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSCHOWN","NTPARAMETERSCHOWN");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERCHOWN","NTPARAMETERCHOWN");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2245 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 399 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2254 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 403 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2263 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 407 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2272 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 411 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"R","1");
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2281 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 415 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2290 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 419 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2299 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 423 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTCP","NTCP");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2309 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 428 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERCP","NTPARAMETERCP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2321 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 435 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSCP","NTPARAMETERSCP");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERCP","NTPARAMETERCP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2333 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 442 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2342 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 446 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2351 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 450 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2360 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 454 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"DESTINY",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2369 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 458 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"DESTINY",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2378 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTEDIT","NTEDIT");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2388 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 467 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETEREDIT","NTPARAMETEREDIT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2400 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 474 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSEDIT","NTPARAMETERSEDIT");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETEREDIT","NTPARAMETEREDIT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2412 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 481 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2421 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 485 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2430 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 489 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2439 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 493 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"SIZE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2448 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 497 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"CONT",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2457 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 501 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTEXEC","NTEXEC");
                            NodeAST *node = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERSEXEC","NTPARAMETERSEXEC");
                            NodeAST *node1 = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETEREXEC","NTPARAMETEREXEC");
                            NodeAST *node2 = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            node1->add(*node2);
                            node->add(*node1);
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-4].TEXT)) + " " + QString::fromLatin1((yyvsp[-3].TEXT)) + " " + QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2472 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 511 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTEXEC","NTEXEC");
                            NodeAST *node = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERSEXEC","NTPARAMETERSEXEC");
                            NodeAST *node1 = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETEREXEC","NTPARAMETEREXEC");
                            NodeAST *node2 = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            node1->add(*node2);
                            node->add(*node1);
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-4].TEXT)) + " " + QString::fromLatin1((yyvsp[-3].TEXT)) + " " + QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2487 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 521 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTFDISK","NTFDISK");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2497 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 526 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERFDISK","NTPARAMETERFDISK");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 533 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSFDISK","NTPARAMETERSFDISK");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERFDISK","NTPARAMETERFDISK");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2521 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 540 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"SIZE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2530 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 544 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"UNIT",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2539 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 548 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2548 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 552 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2557 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 556 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"TYPE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 560 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"TYPE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2575 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 564 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"FIT",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 568 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"DELETE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2593 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 572 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 576 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2611 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 580 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ADD",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 584 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"ADD",QString::number(QString::fromLatin1((yyvsp[0].TEXT)).toInt()*(-1)));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-3].TEXT)) + " " + QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2629 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 588 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTFIND","NTFIND");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2639 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 593 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERFIND","NTPARAMETERFIND");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 600 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSFIND","NTPARAMETERSFIND");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERFIND","NTPARAMETERFIND");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2663 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 607 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 611 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 615 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 619 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2699 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 623 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 627 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTLOGIN","NTLOGIN");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2718 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 632 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERLOGIN","NTPARAMETERLOGIN");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2730 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 639 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSLOGIN","NTPARAMETERSLOGIN");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERLOGIN","NTPARAMETERLOGIN");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2742 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 646 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 650 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2760 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 654 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PWD",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2769 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 658 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PWD",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 662 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PWD",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2787 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 666 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2796 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 670 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTLOGOUT","NTLOGOUT");
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2805 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 674 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTLOSS","NTLOSS");
                            NodeAST *node = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERSLOSS","NTPARAMETERSLOSS");
                            NodeAST *node1 = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERLOSS","NTPARAMETERLOSS");
                            NodeAST *node2 = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            node1->add(*node2);
                            node->add(*node1);
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-4].TEXT)) + " " + QString::fromLatin1((yyvsp[-3].TEXT)) + QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 684 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMKDIR","NTMKDIR");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2830 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 689 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMKDIR","NTPARAMETERMKDIR");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 696 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMKDIR","NTPARAMETERSMKDIR");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMKDIR","NTPARAMETERMKDIR");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2854 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 703 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2863 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 707 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 711 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2881 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 715 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"P","1");
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2890 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 719 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMKDISK","NTMKDISK");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 724 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMKDISK","NTPARAMETERMKDISK");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2912 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 731 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMKDISK","NTPARAMETERSMKDISK");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMKDISK","NTPARAMETERMKDISK");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 738 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"SIZE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2933 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 742 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"UNIT",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2942 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 746 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2951 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 750 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 754 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 2969 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 758 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMKFILE","NTMKFILE");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 2979 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 763 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMKFILE","NTPARAMETERMKFILE");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 2991 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 770 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMKFILE","NTPARAMETERSMKFILE");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMKFILE","NTPARAMETERMKFILE");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 777 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3012 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 781 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 785 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3030 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 789 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"P","1");
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 793 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"SIZE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3048 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 797 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"CONT",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3057 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 801 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMKFS","NTMKFS");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3067 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 806 "parser.yy" /* yacc.c:1646  */
    {    
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMKFS","NTPARAMETERMKFS");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3079 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 813 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMKFS","NTPARAMETERSMKFS");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMKFS","NTPARAMETERMKFS");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3091 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 820 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3100 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 824 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"TYPE",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3109 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 828 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMKGRP","NTMKGRP");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3119 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 833 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMKGRP","NTPARAMETERMKGRP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3131 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 840 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMKGRP","NTPARAMETERSMKGRP");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMKGRP","NTPARAMETERMKGRP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3143 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 847 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 851 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3161 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 855 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3170 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 859 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMKUSR","NTMKUSR");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 864 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMKUSR","NTPARAMETERMKUSR");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3192 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 871 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMKUSR","NTPARAMETERSMKUSR");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMKUSR","NTPARAMETERMKUSR");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3204 "parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 878 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3213 "parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 882 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 886 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3231 "parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 890 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PWD",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3240 "parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 894 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PWD",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 898 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PWD",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3258 "parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 902 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"GRP",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3267 "parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 906 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"GRP",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3276 "parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 910 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMOUNT","NTMOUNT");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3286 "parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 915 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMOUNT","NTPARAMETERMOUNT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3298 "parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 922 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMOUNT","NTPARAMETERSMOUNT");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMOUNT","NTPARAMETERMOUNT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3310 "parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 929 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3319 "parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 933 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3328 "parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 937 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3337 "parser.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 941 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3346 "parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 945 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTMV","NTMV");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3356 "parser.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 950 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERMV","NTPARAMETERMV");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3368 "parser.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 957 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSMV","NTPARAMETERSMV");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERMV","NTPARAMETERMV");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3380 "parser.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 964 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3389 "parser.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 968 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3398 "parser.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 972 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"DESTINY",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3407 "parser.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 976 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"DESTINY",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 980 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3425 "parser.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 984 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPAUSE","NTPAUSE");
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 988 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTRECOVERY","NTRECOVERY");
                            NodeAST *node = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERSRECOVERY","NTPARAMETERSRECOVERY");
                            NodeAST *node1 = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERRECOVERY","NTPARAMETERRECOVERY");
                            NodeAST *node2 = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            node1->add(*node2);
                            node->add(*node1);
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-4].TEXT)) + " " + QString::fromLatin1((yyvsp[-3].TEXT)) + QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3449 "parser.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 998 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTREN","NTREN");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3459 "parser.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1003 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERREN","NTPARAMETERREN");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3471 "parser.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1010 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSREN","NTPARAMETERSREN");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERREN","NTPARAMETERREN");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3483 "parser.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1017 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1021 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1025 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1029 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3519 "parser.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1033 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1037 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTREP","NTREP");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3538 "parser.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1042 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERREP","NTPARAMETERREP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1049 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSREP","NTPARAMETERSREP");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERREP","NTPARAMETERREP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1056 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3571 "parser.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1060 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1064 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3589 "parser.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1068 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1072 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3607 "parser.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1076 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"RUTA",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1080 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"RUTA",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3625 "parser.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1084 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTRM","NTRM");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3635 "parser.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1089 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERRM","NTPARAMETERRM");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3647 "parser.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1096 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSRM","NTPARAMETERSRM");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERRM","NTPARAMETERRM");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3659 "parser.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1103 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1107 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3677 "parser.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1111 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1115 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"RF","1");
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3695 "parser.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1119 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTRMDISK","NTRMDISK");
                            NodeAST *node = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERS","NTPARAMETERS");
                            NodeAST *node1 = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETER","NTPARAMETER");
                            NodeAST *node2 = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            node1->add(*node2);
                            node->add(*node1);
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-4].TEXT)) + " " + QString::fromLatin1((yyvsp[-3].TEXT)) + " " + QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1129 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTRMDISK","NTRMDISK");
                            NodeAST *node = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETERS","NTPARAMETERS");
                            NodeAST *node1 = new NodeAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"NTPARAMETER","NTPARAMETER");
                            NodeAST *node2 = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"PATH",(yyvsp[0].TEXT));
                            node1->add(*node2);
                            node->add(*node1);
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-4].TEXT)) + " " + QString::fromLatin1((yyvsp[-3].TEXT)) + " " + QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1139 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTRMGRP","NTRMGRP");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1144 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERRMGRP","NTPARAMETERRMGRP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3747 "parser.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1151 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSRMGRP","NTPARAMETERSRMGRP");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERRMGRP","NTPARAMETERRMGRP");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3759 "parser.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1158 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1162 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NAME",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1166 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1170 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTRMUSR","NTRMUSR");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3796 "parser.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1175 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERRMUSR","NTPARAMETERRMUSR");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3808 "parser.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1182 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSRMUSR","NTPARAMETERSRMUSR");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERRMUSR","NTPARAMETERRMUSR");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1189 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3829 "parser.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1193 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"USR",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1197 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3847 "parser.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1201 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTUNMOUNT","NTUNMOUNT");
                            (yyval.nodo)->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + " " + (yyvsp[0].nodo)->command;
                        }
#line 3857 "parser.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1206 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo)=(yyvsp[-2].nodo);
                            NodeAST *node = new NodeAST((yylsp[0]).first_line,(yylsp[0]).first_column,"NTPARAMETERUNMOUNT","NTPARAMETERUNMOUNT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = (yyvsp[-2].nodo)->command + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3869 "parser.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1213 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"NTPARAMETERSUNMOUNT","NTPARAMETERSUNMOUNT");
                            NodeAST *node = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"NTPARAMETERUNMOUNT","NTPARAMETERUNMOUNT");
                            node->add(*(yyvsp[0].nodo));
                            (yyval.nodo)->add(*node);
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-1].TEXT)) + (yyvsp[0].nodo)->command;
                        }
#line 3881 "parser.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1220 "parser.yy" /* yacc.c:1646  */
    {
                            (yyval.nodo) = new NodeAST((yylsp[0]).first_line, (yylsp[0]).first_column,"ID",(yyvsp[0].TEXT));
                            (yyval.nodo)->command = QString::fromLatin1((yyvsp[-2].TEXT)) + " " + QString::fromLatin1((yyvsp[-1].TEXT)) + " " + QString::fromLatin1((yyvsp[0].TEXT));
                        }
#line 3890 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3894 "parser.cpp" /* yacc.c:1646  */
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 1224 "parser.yy" /* yacc.c:1906  */
