#include "nt_logout.h"

NT_Logout::NT_Logout()
{

}

void NT_Logout::execute(QString command)
{
    Procedures::writeCommand(command);
    Procedures::writeLine("llego a execute NT_Logout");
}