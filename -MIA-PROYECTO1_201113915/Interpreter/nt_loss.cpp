#include "nt_loss.h"

NT_Loss::NT_Loss()
{

}

void NT_Loss::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en LOSS"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Loss::execute(QString id, QString command)
{
    Procedures::writeCommand(command);
    if(id!=""){
        Procedures::writeLine("llego a execute NT_Loss");
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
    }

}
