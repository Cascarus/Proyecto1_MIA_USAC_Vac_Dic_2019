%option case-insensitive
%option yylineno
%{
#include "Bison/parser.h"
#include "procedures.h"
#include <QList>

int yylex();
void yyerror(const char *s);
int line=0;
int column = 0;
int previous = 0;
NodeAST *root;
%}

%option header-file="scanner.h"
%option outfile="scanner.cpp"
%option noyywrap
%option nounput

RW_Add              "add"
RW_Cat              "cat"
RW_Chgrp            "chgrp"
RW_Chmod            "chmod"
RW_Chown            "chown"
RW_Cont             "cont"
RW_Cp               "cp"
RW_Delete           "delete"
RW_Destiny          "destiny"
RW_Edit             "edit"
RW_Exec             "exec"
RW_Fdisk            "fdisk"
RW_File             "file"
RW_Filen            "file"[0-9]+
RW_Find             "find"
RW_Fit              "fit"
RW_Grp              "grp"
RW_Id               "id"
RW_Idn              "id"[0-9]+
RW_Iddestiny        "iddestiny"
RW_Login            "login"
RW_Logout           "logout"
RW_Loss             "loss"
RW_Mkdir            "mkdir"
RW_Mkdisk           "mkdisk"
RW_Mkfile           "mkfile"
RW_Mkfs             "mkfs"
RW_Mkgrp            "mkgrp"
RW_Mkusr            "mkusr"
RW_Mount            "mount"
RW_Mv               "mv"
RW_Name             "name"
RW_P                "p"
RW_Path             "path"
RW_Pause            "pause"
RW_Pwd              "pwd"
RW_R                "r"
RW_Recovery         "recovery"
RW_Ren              "ren"
RW_Rep              "rep"
RW_Rf               "rf"
RW_Rm               "rm"
RW_Rmdisk           "rmdisk"
RW_Rmgrp            "rmgrp"
RW_Rmusr            "rmusr"
RW_Size             "size"
RW_Type             "type"
RW_Ugo              "ugo"
RW_Unit             "unit"
RW_Unmount          "unmount"
RW_Usr              "usr"
RW_Ruta             "ruta"
SYM_Arrow           "->"
SYM_Ampersand       "&"
SYM_Hyphen          "-"
RE_Delete           "fast"|"full"
RE_Fit              "bf"|"ff"|"wf"
RE_Id               [a-zA-Z_0-9]+
RE_Name             "mbr"|"disk"|"inode"|"sb"|"bm_arbdir"|"bm_detdir"|"bm_inode"|"bm_block"|"bitacora"|"directorio"|"tree_file"|"tree_directorio"|"tree_complete"|"ls"
RE_Name2            [a-zA-Z_0-9]+[\.][a-zA-Z0-9_]+
RE_Number           [0-9]+
RE_Path             ([\/]?[a-zA-Z0-9_]+)*([\/]|[\.][a-zA-Z0-9_]+)?
RE_Type             "e"|"l"
RE_Unit             "b"|"k"|"m"

%x CADENA COM

%%
<INITIAL>
{
"\""                {BEGIN CADENA;}
"#"                 {BEGIN COM;}

{RW_Add}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Add;}
{RW_Cat}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Cat;}
{RW_Chgrp}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Chgrp;}
{RW_Chmod}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Chmod;}
{RW_Chown}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Chown;}
{RW_Cont}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Cont;}
{RW_Cp}             {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Cp;}
{RW_Delete}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Delete;}
{RW_Destiny}        {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Destiny;}
{RW_Edit}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Edit;}
{RW_Exec}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Exec;}
{RW_Fdisk}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Fdisk;}
{RW_Filen}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Filen;}
{RW_File}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_File;}
{RW_Find}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Find;}
{RW_Fit}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Fit;}
{RW_Grp}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Grp;}
{RW_Idn}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Idn;}
{RW_Id}             {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Id;}
{RW_Login}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Login;}
{RW_Logout}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Logout;}
{RW_Loss}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Loss;}
{RW_Mkdir}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mkdir;}
{RW_Mkdisk}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mkdisk;}
{RW_Mkfile}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mkfile;}
{RW_Mkfs}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mkfs;}
{RW_Mkgrp}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mkgrp;}
{RW_Mkusr}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mkusr;}
{RW_Mount}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mount;}
{RW_Mv}             {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Mv;}
{RW_Name}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Name;}
{RW_P}              {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_P;}
{RW_Path}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Path;}
{RW_Pause}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Pause;}
{RW_Pwd}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Pwd;}
{RW_R}              {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_R;}
{RW_Recovery}       {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Recovery;}
{RW_Ren}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Ren;}
{RW_Rep}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Rep;}
{RW_Rf}             {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Rf;}
{RW_Rmdisk}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Rmdisk;}
{RW_Rmgrp}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Rmgrp;}
{RW_Rmusr}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Rmusr;}
{RW_Rm}             {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Rm;}
{RW_Ruta}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Ruta;}
{RW_Size}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Size;}
{RW_Type}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Type;}
{RW_Ugo}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Ugo;}
{RW_Unit}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Unit;}
{RW_Unmount}        {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Unmount;}
{RW_Usr}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RW_Usr;}
{SYM_Arrow}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return SYM_Arrow;}
{SYM_Ampersand}     {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return SYM_Ampersand;}
{SYM_Hyphen}        {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return SYM_Hyphen;}
{RE_Delete}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Delete;}
{RE_Fit}            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Fit;}
{RE_Name}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Name;}
{RE_Name2}          {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Name2;}
{RE_Number}         {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Number;}
{RE_Type}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Type;}
{RE_Unit}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Unit;}
{RE_Id}             {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Id;}
{RE_Path}           {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_Path;}
"\t"                {strcpy(yylval.TEXT, yytext); column=26;}
[[:blank:]]         {column++;}
"\n"                {line++; column=0; previous=0;}
.                   {
                      column=column+previous; previous = strlen(yytext);strcpy(yylval.TEXT, yytext);
                      Procedures::writeError(QString::fromUtf8(" Error Lexico en la Línea: ") + QString::number(line+1) + QString::fromUtf8(" Columna: ") + QString::number(column+1) + QString::fromUtf8(" Token: ") + QString::fromLatin1(yylval.TEXT));
                    }
}
<COM>
{
"\n"                {line++; column = 0; BEGIN INITIAL;}
.                   { }
}
<CADENA>
{
[^\"\n]+            {column=column+previous; previous = strlen(yytext); strcpy(yylval.TEXT, yytext); return RE_String;}
"\n"                {
                        yyerror("unclosed cadena");
                        Procedures::writeError(QString::fromUtf8(" Error Lexico en la Línea: ") + QString::number(line+1) + QString::fromUtf8(" Columna: ") + QString::number(column+1) + QString::fromUtf8(" Token: ") + QString::fromLatin1(yylval.TEXT));
                    }
"\""                {BEGIN INITIAL;}
}
%%
