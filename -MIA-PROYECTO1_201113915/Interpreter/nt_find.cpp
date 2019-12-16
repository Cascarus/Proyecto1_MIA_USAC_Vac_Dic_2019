#include "nt_find.h"

NT_Find::NT_Find()
{

}

void NT_Find::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    path="";
    name="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case NAME: if(name=="") name = parameter.value; else { Procedures::writeError("Parametro NAME ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en FIND"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, name, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Find::execute(QString id, QString path, QString name, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!="" && name!=""){
        Procedures::writeLine("llego a execute NT_Find");
        //TODO Falta ? *
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
        if(name=="")
            Procedures::writeError("Falta el parametro &name");
    }


}
