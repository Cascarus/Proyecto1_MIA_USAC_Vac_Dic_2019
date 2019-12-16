/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 21 "parser.yy" /* yacc.c:1909  */

  char TEXT [256];
  class NodeAST *nodo;

#line 126 "parser.h" /* yacc.c:1909  */
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
