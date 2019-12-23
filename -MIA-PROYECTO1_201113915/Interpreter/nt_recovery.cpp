#include "nt_recovery.h"

NT_Recovery::NT_Recovery()
{

}

void NT_Recovery::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en RECOVERY"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Recovery::execute(QString id, QString command)
{
    Procedures::writeCommand(command);

    Procedures::recuperacion(id);

    Procedures::writeLine("llego a execute NT_Recovery");
}
