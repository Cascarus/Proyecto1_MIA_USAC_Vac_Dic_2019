#include "nt_mv.h"

NT_Mv::NT_Mv()
{

}

void NT_Mv::tourAST(NodeAST *node, QString command)
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
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MV"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, destiny, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Mv::execute(QString id, QString path, QString destiny, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!="" && destiny!=""){
        Procedures::writeLine("llego a execute NT_Mv");
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
