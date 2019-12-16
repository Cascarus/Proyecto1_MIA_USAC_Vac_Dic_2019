#include "nt_rm.h"

NT_Rm::NT_Rm()
{

}

void NT_Rm::tourAST(NodeAST *node, QString command)
{
    ERROR = false;

    id="";
    path="";
    rf=false;

    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case RF: if(rf==false) rf = parameter.value.toInt(); else { Procedures::writeError("Parametro RF ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en RM"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, rf, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Rm::execute(QString id, QString path, bool rf, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!=""){
        Procedures::writeLine("llego a execute NT_Rm");
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
    }
}
