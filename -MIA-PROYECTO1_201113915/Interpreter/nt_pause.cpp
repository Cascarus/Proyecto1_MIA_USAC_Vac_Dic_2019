#include "nt_pause.h"

NT_Pause::NT_Pause()
{

}

void NT_Pause::execute(QString command)
{
    Procedures::writeCommand(command);
    //Procedures::writeLine("llego a execute NT_Pause");
    Procedures::writeLine("Presione ENTER para continuar...");
    IOConsole::pauseConsole();
    Procedures::writeLine("Continuando...");
}
