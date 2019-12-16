#include "nt_cp.h"

NT_Cp::NT_Cp()
{

}

void NT_Cp::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    path="";
    destiny="";

    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case DESTINY: if(destiny=="") destiny = parameter.value; else { Procedures::writeError("Parametro DESTINY ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en CP"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, destiny, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Cp::execute(QString id, QString path, QString destiny, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!="" && destiny!=""){
        Procedures::writeLine("llego a execute NT_Cp");
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
        if(destiny=="")
            Procedures::writeError("Falta el parametro &destiny");
    }
}
