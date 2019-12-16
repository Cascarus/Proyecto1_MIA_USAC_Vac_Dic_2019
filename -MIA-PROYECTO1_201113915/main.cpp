#include <QCoreApplication>
#include <QTimer>
#include <NodeAST/nodeast.h>
#include <Bison/parser.h>  // Nuestro parser
#include <Bison/scanner.h>  // Nuestro scanner
#include <Plotter/plotter.h> // Graficador
#include <Interpreter/interpreter.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Procedures::writeLine("SUPER BOOT:  "+QString::number(sizeof (SUPERBOOT)));
    //Procedures::writeLine("AVD:         "+QString::number(sizeof (AVD)));
    //Procedures::writeLine("DD:          "+QString::number(sizeof (DD)));
    //Procedures::writeLine("INODO:       "+QString::number(sizeof (INODO)));
    //Procedures::writeLine("BLOCK:       "+QString::number(sizeof (BLOCK_DATA)));
    //Procedures::writeLine("BITACORA:    "+QString::number(sizeof (BITACORA)));
    //Procedures::writeLine("N:           "+QString::number(Procedures::getN(10240)));

    QString entrada;

    extern int yyparse(); //
    extern NodeAST *root; // Raiz del arbol
    extern int line; // Linea del token
    extern int column; // Columna de los tokens
    extern int yylineno;


    char* prueba = new char[102];


    for(int i=0; i<102;i++)
        prueba[i] = '0';

    //Procedures::getRepBM("Prueba", prueba,102);

    do
    {
        entrada = IOConsole::readLine();
        Procedures::clearProcedures();
        if(entrada.toUpper() != "EXIT")
        {
            //YY_BUFFER_STATE buffer =
            yy_scan_string(entrada.toUtf8().constData());
            /*Limpiamos los contadores ya que son variables globales*/
            line = 0;
            column = 0;
            yylineno = 0;
            if(yyparse()==0) // Si nos da un número negativo, signifca error.
            {
                //Procedures::writeLine("todo bien, nada mal");

                Plotter *graph = new Plotter(root);
                graph->generateImage();
                Interpreter *interpreter = new Interpreter();
                interpreter->tourAST(root);
            }
            else
            {
                Procedures::writeError("todo mal, nada bien");
            }
        }
        else
        {
            Procedures::writeLine("Saliendo del programa ...");
        }
    }
    while (entrada.toUpper() != "EXIT");

    QTimer::singleShot( 0, &a, &QCoreApplication::quit);

    return a.exec();
}
