#include "nt_edit.h"

NT_Edit::NT_Edit()
{

}

void NT_Edit::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    path="";
    size=0;
    cont="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case SIZE: if(size==0) size = parameter.value.toInt(); else { Procedures::writeError("Parametro SIZE ya ingresado anteriormente"); ERROR = true; } break;
        case CONT: if(cont=="") cont = parameter.value; else { Procedures::writeError("Parametro CONT ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en EDIT"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, size, cont, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Edit::execute(QString id, QString path, int size, QString cont, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!=""){
        Procedures::writeLine("llego a execute NT_Edit");
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
    }
}
