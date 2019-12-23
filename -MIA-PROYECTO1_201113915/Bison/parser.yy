%{
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
%}
%defines "parser.h"
%output "parser.cpp"
%define parse.error verbose
%locations

%union{
  char TEXT [256];
  class NodeAST *nodo;
}

%token<TEXT> RW_Add;
%token<TEXT> RW_Cat;
%token<TEXT> RW_Chgrp;
%token<TEXT> RW_Chmod;
%token<TEXT> RW_Chown;
%token<TEXT> RW_Cont;
%token<TEXT> RW_Cp;
%token<TEXT> RW_Delete;
%token<TEXT> RW_Destiny;
%token<TEXT> RW_Edit;
%token<TEXT> RW_Exec;
%token<TEXT> RW_Fdisk;
%token<TEXT> RW_File;
%token<TEXT> RW_Filen;
%token<TEXT> RW_Find;
%token<TEXT> RW_Fit;
%token<TEXT> RW_Grp;
%token<TEXT> RW_Id;
%token<TEXT> RW_Idn;
%token<TEXT> RW_Login;
%token<TEXT> RW_Logout;
%token<TEXT> RW_Loss;
%token<TEXT> RW_Mkdir;
%token<TEXT> RW_Mkdisk;
%token<TEXT> RW_Mkfile;
%token<TEXT> RW_Mkfs;
%token<TEXT> RW_Mkgrp;
%token<TEXT> RW_Mkusr;
%token<TEXT> RW_Mount;
%token<TEXT> RW_Mv;
%token<TEXT> RW_Name;
%token<TEXT> RW_P;
%token<TEXT> RW_Path;
%token<TEXT> RW_Pause;
%token<TEXT> RW_Pwd;
%token<TEXT> RW_R;
%token<TEXT> RW_Recovery;
%token<TEXT> RW_Ren;
%token<TEXT> RW_Rep;
%token<TEXT> RW_Rf;
%token<TEXT> RW_Rm;
%token<TEXT> RW_Rmdisk;
%token<TEXT> RW_Rmgrp;
%token<TEXT> RW_Rmusr;
%token<TEXT> RW_Ruta;
%token<TEXT> RW_Size;
%token<TEXT> RW_Type;
%token<TEXT> RW_Ugo;
%token<TEXT> RW_Unit;
%token<TEXT> RW_Unmount;
%token<TEXT> RW_Usr;
%token<TEXT> SYM_Arrow;
%token<TEXT> SYM_Ampersand;
%token<TEXT> SYM_Hyphen;
%token<TEXT> RE_Delete;
%token<TEXT> RE_Fit;
%token<TEXT> RE_Id;
%token<TEXT> RE_Name;
%token<TEXT> RE_Name2;
%token<TEXT> RE_Number;
%token<TEXT> RE_Path;
%token<TEXT> RE_String;
%token<TEXT> RE_Type;
%token<TEXT> RE_Unit;

%type<nodo> NT_Cat;
%type<nodo> NT_Chgrp;
%type<nodo> NT_Chmod;
%type<nodo> NT_Chown;
%type<nodo> NT_Cp;
%type<nodo> NT_Edit;
%type<nodo> NT_Exec;
%type<nodo> NT_Fdisk;
%type<nodo> NT_Find;
%type<nodo> NT_Instruction;
%type<nodo> NT_Instructions;
%type<nodo> NT_Login;
%type<nodo> NT_Logout;
%type<nodo> NT_Loss;
%type<nodo> NT_Mkdir;
%type<nodo> NT_Mkdisk;
%type<nodo> NT_Mkfile;
%type<nodo> NT_Mkfs;
%type<nodo> NT_Mkgrp;
%type<nodo> NT_Mkusr;
%type<nodo> NT_Mount;
%type<nodo> NT_Mv;
%type<nodo> NT_Parametercat;
%type<nodo> NT_Parameterchgrp;
%type<nodo> NT_Parameterchmod;
%type<nodo> NT_Parameterchown;
%type<nodo> NT_Parametercp;
%type<nodo> NT_Parameteredit;
%type<nodo> NT_Parameterfdisk;
%type<nodo> NT_Parameterfind;
%type<nodo> NT_Parameterlogin;
%type<nodo> NT_Parametermkdir;
%type<nodo> NT_Parametermkdisk;
%type<nodo> NT_Parametermkfile;
%type<nodo> NT_Parametermkfs;
%type<nodo> NT_Parametermkgrp;
%type<nodo> NT_Parametermkusr;
%type<nodo> NT_Parametermount;
%type<nodo> NT_Parametermv;
%type<nodo> NT_Parameterren;
%type<nodo> NT_Parameterrep;
%type<nodo> NT_Parameterrm;
%type<nodo> NT_Parameterrmgrp;
%type<nodo> NT_Parameterrmusr;
%type<nodo> NT_Parameterunmount;
%type<nodo> NT_Parameterscat;
%type<nodo> NT_Parameterschgrp;
%type<nodo> NT_Parameterschmod;
%type<nodo> NT_Parameterschown;
%type<nodo> NT_Parameterscp;
%type<nodo> NT_Parametersedit;
%type<nodo> NT_Parametersfdisk;
%type<nodo> NT_Parametersfind;
%type<nodo> NT_Parameterslogin;
%type<nodo> NT_Parametersmkdir;
%type<nodo> NT_Parametersmkdisk;
%type<nodo> NT_Parametersmkfile;
%type<nodo> NT_Parametersmkfs;
%type<nodo> NT_Parametersmkgrp;
%type<nodo> NT_Parametersmkusr;
%type<nodo> NT_Parametersmount;
%type<nodo> NT_Parametersmv;
%type<nodo> NT_Parametersren;
%type<nodo> NT_Parametersrep;
%type<nodo> NT_Parametersrm;
%type<nodo> NT_Parametersrmgrp;
%type<nodo> NT_Parametersrmusr;
%type<nodo> NT_Parametersunmount;
%type<nodo> NT_Pause;
%type<nodo> NT_Recovery;
%type<nodo> NT_Ren;
%type<nodo> NT_Rep;
%type<nodo> NT_Rm;
%type<nodo> NT_Rmdisk;
%type<nodo> NT_Rmgrp;
%type<nodo> NT_Rmusr;
%type<nodo> NT_Unmount;

%start Start

%%

Start                   : NT_Instructions{
                            root = $1;
                        };
NT_Instructions         : NT_Instructions NT_Instruction{
                            $$=$1;
                            NodeAST *node = new NodeAST( @2.first_line,@2.first_column,"NTINSTRUCTION","NTINSTRUCTION");
                            node->add(*$2);
                            $$->add(*node);
                        }
                        | NT_Instruction{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTINSTRUCTIONS","NTINSTRUCTIONS");
                            NodeAST *node = new NodeAST(@1.first_line, @1.first_column,"NTINSTRUCTION","NTINSTRUCTION");
                            node->add(*$1);
                            $$->add(*node);
                        };
NT_Instruction          : NT_Cat{ 
                            $$=$1;
                        }
                        | NT_Chgrp{ 
                            $$=$1;
                        }
                        | NT_Chmod{ 
                            $$=$1;
                        }
                        | NT_Chown{ 
                            $$=$1;
                        }
                        | NT_Cp{ 
                            $$=$1;
                        }
                        | NT_Edit{ 
                            $$=$1;
                        }
                        | NT_Exec{ 
                            $$=$1;
                        }
                        | NT_Fdisk{ 
                            $$=$1;
                        }
                        | NT_Find{ 
                            $$=$1;
                        }
                        | NT_Login{ 
                            $$=$1;
                        }
                        | NT_Logout{ 
                            $$=$1;
                        }
                        | NT_Loss{ 
                            $$=$1;
                        }
                        | NT_Mkdir{ 
                            $$=$1;
                        }
                        | NT_Mkdisk{ 
                            $$=$1;
                        }
                        | NT_Mkfile{ 
                            $$=$1;
                        }
                        | NT_Mkfs{ 
                            $$=$1;
                        }
                        | NT_Mkgrp{ 
                            $$=$1;
                        }
                        | NT_Mkusr{ 
                            $$=$1;
                        }
                        | NT_Mount{ 
                            $$=$1;
                        }
                        | NT_Mv{ 
                            $$=$1;
                        }
                        | NT_Pause{ 
                            $$=$1;
                        }
                        | NT_Recovery{ 
                            $$=$1;
                        }
                        | NT_Rm{ 
                            $$=$1;
                        }
                        | NT_Ren{ 
                            $$=$1;
                        }
                        | NT_Rep{ 
                            $$=$1;
                        }
                        | NT_Rmdisk{ 
                            $$=$1;
                        }
                        | NT_Rmgrp{ 
                            $$=$1;
                        }
                        | NT_Rmusr{ 
                            $$=$1;
                        }
                        | NT_Unmount{ 
                            $$=$1;
                        };
NT_Cat                  : RW_Cat NT_Parameterscat{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTCAT","NTCAT");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parameterscat        : NT_Parameterscat SYM_Ampersand NT_Parametercat{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERCAT","NTPARAMETERCAT");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametercat{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSCAT","NTPARAMETERSCAT");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERCAT","NTPARAMETERCAT");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametercat         : RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Filen SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ARCHIVE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Filen SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ARCHIVE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Chgrp                : RW_Chgrp NT_Parameterschgrp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTCHGRP","NTCHGRP");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parameterschgrp      : NT_Parameterschgrp SYM_Ampersand NT_Parameterchgrp{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERCHGRP","NTPARAMETERCHGRP");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterchgrp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSCHGRP","NTPARAMETERSCHGRP");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERCHGRP","NTPARAMETERCHGRP");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterchgrp       : RW_Usr SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Usr SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Grp SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"GRP",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Grp SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"GRP",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Chmod                : RW_Chmod NT_Parameterschmod{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTCHMOD","NTCHMOD");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parameterschmod      : NT_Parameterschmod SYM_Ampersand NT_Parameterchmod{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERCHMOD","NTPARAMETERCHMOD");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterchmod{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSCHMOD","NTPARAMETERSCHMOD");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERCHMOD","NTPARAMETERCHMOD");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterchmod       : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Ugo SYM_Arrow RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"UGO",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_R{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"R","1");
                            $$->command = QString::fromLatin1($1);
                        };
NT_Chown                : RW_Chown NT_Parameterschown{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTCHOWN","NTCHOWN");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parameterschown      : NT_Parameterschown SYM_Ampersand NT_Parameterchown{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERCHOWN","NTPARAMETERCHOWN");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterchown{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSCHOWN","NTPARAMETERSCHOWN");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERCHOWN","NTPARAMETERCHOWN");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterchown       : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_R{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"R","1");
                            $$->command = QString::fromLatin1($1);
                        }
                        | RW_Usr SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Usr SYM_Arrow RE_String {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Cp                   : RW_Cp NT_Parameterscp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTCP","NTCP");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parameterscp         : NT_Parameterscp SYM_Ampersand NT_Parametercp{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERCP","NTPARAMETERCP");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametercp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSCP","NTPARAMETERSCP");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERCP","NTPARAMETERCP");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametercp          : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Destiny SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"DESTINY",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }   
                        | RW_Destiny SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"DESTINY",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Edit                 : RW_Edit NT_Parametersedit{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTEDIT","NTEDIT");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersedit       : NT_Parametersedit SYM_Ampersand NT_Parameteredit{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETEREDIT","NTPARAMETEREDIT");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameteredit{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSEDIT","NTPARAMETERSEDIT");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETEREDIT","NTPARAMETEREDIT");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameteredit        : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Size SYM_Arrow RE_Number {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"SIZE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Cont SYM_Arrow  RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"CONT",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Exec                 : RW_Exec SYM_Ampersand RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTEXEC","NTEXEC");
                            NodeAST *node = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSEXEC","NTPARAMETERSEXEC");
                            NodeAST *node1 = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETEREXEC","NTPARAMETEREXEC");
                            NodeAST *node2 = new NodeAST(@5.first_line, @5.first_column,"PATH",$5);
                            node1->add(*node2);
                            node->add(*node1);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3) + " " + QString::fromLatin1($4) + " " + QString::fromLatin1($5);
                        }
                        | RW_Exec SYM_Ampersand RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTEXEC","NTEXEC");
                            NodeAST *node = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSEXEC","NTPARAMETERSEXEC");
                            NodeAST *node1 = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETEREXEC","NTPARAMETEREXEC");
                            NodeAST *node2 = new NodeAST(@5.first_line, @5.first_column,"PATH",$5);
                            node1->add(*node2);
                            node->add(*node1);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3) + " " + QString::fromLatin1($4) + " " + QString::fromLatin1($5);
                        };
NT_Fdisk                : RW_Fdisk NT_Parametersfdisk{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTFDISK","NTFDISK");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersfdisk      : NT_Parametersfdisk SYM_Ampersand NT_Parameterfdisk{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERFDISK","NTPARAMETERFDISK");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterfdisk{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSFDISK","NTPARAMETERSFDISK");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERFDISK","NTPARAMETERFDISK");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterfdisk       : RW_Size SYM_Arrow RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"SIZE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Unit SYM_Arrow RE_Unit{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"UNIT",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Type SYM_Arrow RE_Type{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"TYPE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Type SYM_Arrow RW_P{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"TYPE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Fit SYM_Arrow RE_Fit{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"FIT",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Delete SYM_Arrow RE_Delete{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"DELETE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Add SYM_Arrow RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ADD",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Add SYM_Arrow SYM_Hyphen RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ADD",QString::number(QString::fromLatin1($4).toInt()*(-1)));
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3) + QString::fromLatin1($4);
                        };
NT_Find                 : RW_Find NT_Parametersfind{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTFIND","NTFIND");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersfind       : NT_Parametersfind SYM_Ampersand NT_Parameterfind{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERFIND","NTPARAMETERFIND");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterfind{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSFIND","NTPARAMETERSFIND");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERFIND","NTPARAMETERFIND");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterfind        : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_Name2{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Login                : RW_Login NT_Parameterslogin{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTLOGIN","NTLOGIN");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parameterslogin      : NT_Parameterslogin SYM_Ampersand NT_Parameterlogin{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERLOGIN","NTPARAMETERLOGIN");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterlogin{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSLOGIN","NTPARAMETERSLOGIN");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERLOGIN","NTPARAMETERLOGIN");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterlogin       : RW_Usr SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Usr SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Pwd SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PWD",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Pwd SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PWD",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Pwd SYM_Arrow RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PWD",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Logout               : RW_Logout{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTLOGOUT","NTLOGOUT");
                            $$->command = QString::fromLatin1($1);
                        };
NT_Loss                 : RW_Loss SYM_Ampersand RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTLOSS","NTLOSS");
                            NodeAST *node = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSLOSS","NTPARAMETERSLOSS");
                            NodeAST *node1 = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERLOSS","NTPARAMETERLOSS");
                            NodeAST *node2 = new NodeAST(@5.first_line, @5.first_column,"ID",$5);
                            node1->add(*node2);
                            node->add(*node1);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + QString::fromLatin1($3) + " " + QString::fromLatin1($4) + " " + QString::fromLatin1($5);
                        };
NT_Mkdir                : RW_Mkdir NT_Parametersmkdir{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMKDIR","NTMKDIR");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmkdir      : NT_Parametersmkdir SYM_Ampersand NT_Parametermkdir{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMKDIR","NTPARAMETERMKDIR");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermkdir{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMKDIR","NTPARAMETERSMKDIR");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMKDIR","NTPARAMETERMKDIR");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermkdir       : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_P{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"P","1");
                            $$->command = QString::fromLatin1($1);
                        };
NT_Mkdisk               : RW_Mkdisk NT_Parametersmkdisk{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMKDISK","NTMKDISK");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmkdisk     : NT_Parametersmkdisk SYM_Ampersand NT_Parametermkdisk{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMKDISK","NTPARAMETERMKDISK");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermkdisk{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMKDISK","NTPARAMETERSMKDISK");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMKDISK","NTPARAMETERMKDISK");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermkdisk      : RW_Size SYM_Arrow RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"SIZE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Unit SYM_Arrow RE_Unit{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"UNIT",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_Name2{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Mkfile               : RW_Mkfile NT_Parametersmkfile{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMKFILE","NTMKFILE");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmkfile     : NT_Parametersmkfile SYM_Ampersand NT_Parametermkfile{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMKFILE","NTPARAMETERMKFILE");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermkfile{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMKFILE","NTPARAMETERSMKFILE");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMKFILE","NTPARAMETERMKFILE");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermkfile      : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id {
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_P {
                            $$ = new NodeAST(@1.first_line, @1.first_column,"P","1");
                            $$->command = QString::fromLatin1($1);
                        }
                        | RW_Size SYM_Arrow RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"SIZE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Cont SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"CONT",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Mkfs                 : RW_Mkfs NT_Parametersmkfs{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMKFS","NTMKFS");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmkfs       : NT_Parametersmkfs SYM_Ampersand NT_Parametermkfs{    
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMKFS","NTPARAMETERMKFS");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermkfs{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMKFS","NTPARAMETERSMKFS");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMKFS","NTPARAMETERMKFS");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermkfs        : RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Type SYM_Arrow RE_Delete{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"TYPE",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Mkgrp                : RW_Mkgrp NT_Parametersmkgrp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMKGRP","NTMKGRP");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmkgrp      : NT_Parametersmkgrp SYM_Ampersand NT_Parametermkgrp{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMKGRP","NTPARAMETERMKGRP");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermkgrp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMKGRP","NTPARAMETERSMKGRP");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMKGRP","NTPARAMETERMKGRP");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermkgrp       : RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Mkusr                : RW_Mkusr NT_Parametersmkusr{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMKUSR","NTMKUSR");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmkusr      : NT_Parametersmkusr SYM_Ampersand NT_Parametermkusr{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMKUSR","NTPARAMETERMKUSR");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermkusr{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMKUSR","NTPARAMETERSMKUSR");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMKUSR","NTPARAMETERMKUSR");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermkusr       : RW_Usr SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Usr SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Pwd SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PWD",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Pwd SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PWD",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Pwd SYM_Arrow RE_Number{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PWD",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Grp SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"GRP",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Grp SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"GRP",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Mount                : RW_Mount NT_Parametersmount{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMOUNT","NTMOUNT");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmount      : NT_Parametersmount SYM_Ampersand NT_Parametermount{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMOUNT","NTPARAMETERMOUNT");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermount{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMOUNT","NTPARAMETERSMOUNT");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMOUNT","NTPARAMETERMOUNT");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermount       : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Mv                   : RW_Mv NT_Parametersmv{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTMV","NTMV");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersmv         : NT_Parametersmv SYM_Ampersand NT_Parametermv{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERMV","NTPARAMETERMV");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parametermv{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSMV","NTPARAMETERSMV");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERMV","NTPARAMETERMV");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parametermv          : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Destiny SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"DESTINY",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Destiny SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"DESTINY",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Pause                : RW_Pause{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPAUSE","NTPAUSE");
                            $$->command = QString::fromLatin1($1);
                        };
NT_Recovery             : RW_Recovery SYM_Ampersand RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTRECOVERY","NTRECOVERY");
                            NodeAST *node = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSRECOVERY","NTPARAMETERSRECOVERY");
                            NodeAST *node1 = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERRECOVERY","NTPARAMETERRECOVERY");
                            NodeAST *node2 = new NodeAST(@5.first_line, @5.first_column,"ID",$5);
                            node1->add(*node2);
                            node->add(*node1);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + QString::fromLatin1($3) + " " + QString::fromLatin1($4) + " " + QString::fromLatin1($5);
                        };
NT_Ren                  : RW_Ren NT_Parametersren{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTREN","NTREN");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersren        : NT_Parametersren SYM_Ampersand NT_Parameterren{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERREN","NTPARAMETERREN");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterren{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSREN","NTPARAMETERSREN");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERREN","NTPARAMETERREN");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterren         : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_Name2{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
                        | RW_Name SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Rep                  : RW_Rep NT_Parametersrep{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTREP","NTREP");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersrep        : NT_Parametersrep SYM_Ampersand NT_Parameterrep{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERREP","NTPARAMETERREP");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterrep{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSREP","NTPARAMETERSREP");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERREP","NTPARAMETERREP");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterrep         : RW_Name SYM_Arrow RE_Name{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RW_File{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Ruta SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"RUTA",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Ruta SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"RUTA",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Rm                   : RW_Rm NT_Parametersrm{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTRM","NTRM");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersrm         : NT_Parametersrm SYM_Ampersand NT_Parameterrm{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERRM","NTPARAMETERRM");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterrm{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSRM","NTPARAMETERSRM");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERRM","NTPARAMETERRM");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterrm          : RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"PATH",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Rf{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"RF","1");
                            $$->command = QString::fromLatin1($1);
                        };
NT_Rmdisk               : RW_Rmdisk SYM_Ampersand RW_Path SYM_Arrow RE_String{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTRMDISK","NTRMDISK");
                            NodeAST *node = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERS","NTPARAMETERS");
                            NodeAST *node1 = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETER","NTPARAMETER");
                            NodeAST *node2 = new NodeAST(@5.first_line, @5.first_column,"PATH",$5);
                            node1->add(*node2);
                            node->add(*node1);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3) + " " + QString::fromLatin1($4) + " " + QString::fromLatin1($5);
                        }
                        | RW_Rmdisk SYM_Ampersand RW_Path SYM_Arrow RE_Path{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTRMDISK","NTRMDISK");
                            NodeAST *node = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERS","NTPARAMETERS");
                            NodeAST *node1 = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETER","NTPARAMETER");
                            NodeAST *node2 = new NodeAST(@5.first_line, @5.first_column,"PATH",$5);
                            node1->add(*node2);
                            node->add(*node1);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3) + " " + QString::fromLatin1($4) + " " + QString::fromLatin1($5);
                        }; 
NT_Rmgrp                : RW_Rmgrp NT_Parametersrmgrp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTRMGRP","NTRMGRP");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersrmgrp      : NT_Parametersrmgrp SYM_Ampersand NT_Parameterrmgrp{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERRMGRP","NTPARAMETERRMGRP");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterrmgrp{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSRMGRP","NTPARAMETERSRMGRP");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERRMGRP","NTPARAMETERRMGRP");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterrmgrp       : RW_Name SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Name SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"NAME",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Rmusr                : RW_Rmusr NT_Parametersrmusr{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTRMUSR","NTRMUSR");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersrmusr      : NT_Parametersrmusr SYM_Ampersand NT_Parameterrmusr{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERRMUSR","NTPARAMETERRMUSR");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterrmusr{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSRMUSR","NTPARAMETERSRMUSR");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERRMUSR","NTPARAMETERRMUSR");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterrmusr       : RW_Usr SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Usr SYM_Arrow RE_String{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"USR",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        }
                        | RW_Id SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
NT_Unmount              : RW_Unmount NT_Parametersunmount{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTUNMOUNT","NTUNMOUNT");
                            $$->add(*$2);
                            $$->command = QString::fromLatin1($1) + " " + $2->command;
                        };
NT_Parametersunmount    : NT_Parametersunmount SYM_Ampersand NT_Parameterunmount{
                            $$=$1;
                            NodeAST *node = new NodeAST(@3.first_line,@3.first_column,"NTPARAMETERUNMOUNT","NTPARAMETERUNMOUNT");
                            node->add(*$3);
                            $$->add(*node);
                            $$->command = $1->command + " " + QString::fromLatin1($2) + $3->command;
                        }
                        | SYM_Ampersand NT_Parameterunmount{
                            $$ = new NodeAST(@1.first_line, @1.first_column,"NTPARAMETERSUNMOUNT","NTPARAMETERSUNMOUNT");
                            NodeAST *node = new NodeAST(@2.first_line, @2.first_column,"NTPARAMETERUNMOUNT","NTPARAMETERUNMOUNT");
                            node->add(*$2);
                            $$->add(*node);
                            $$->command = QString::fromLatin1($1) + $2->command;
                        };
NT_Parameterunmount     : RW_Idn SYM_Arrow RE_Id{
                            $$ = new NodeAST(@3.first_line, @3.first_column,"ID",$3);
                            $$->command = QString::fromLatin1($1) + " " + QString::fromLatin1($2) + " " + QString::fromLatin1($3);
                        };
%%