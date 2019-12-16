#include "nt_exec.h"
#include <NodeAST/nodeast.h>
#include <Bison/parser.h>  // Nuestro parser
#include <Bison/scanner.h>  // Nuestro scanner
#include <Plotter/plotter.h> // Graficador
#include <Interpreter/interpreter.h>

NT_Exec::NT_Exec()
{

}

void NT_Exec::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    path="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en EXEC"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(path, command); else Procedures::writeError("Verificar comando ingresado.");
}
void NT_Exec::execute(QString path, QString command)
{
    Procedures::writeCommand(command);
    if(path!=""){
        //Procedures::writeLine("llego a execute NT_Exec");
        QString text= "";
        QFile file(path);
        if(file.open(QFile::ReadOnly))
            text = file.readAll();
        else
            Procedures::writeLine("Error al leer el archivo");


        extern int yyparse(); //
        extern NodeAST *root; // Raiz del arbol
        extern int line; // Linea del token
        extern int column; // Columna de los tokens
        extern int yylineno;

        //YY_BUFFER_STATE buffer =
        yy_scan_string(text.toUtf8().constData());

        line = 0;
        column = 0;
        yylineno = 0;

        if(yyparse()==0)
        {
            Procedures::writeLine("todo bien, nada mal");
            Plotter *graph = new Plotter(root);
            graph->generateImage();
            Interpreter *interpreter = new Interpreter();
            interpreter->tourAST(root);
        }
        else
            Procedures::writeError("todo mal, nada bien");
    }
    else{
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
    }




}
