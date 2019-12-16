#include "nt_mkgrp.h"

NT_Mkgrp::NT_Mkgrp()
{

}

void NT_Mkgrp::tourAST(NodeAST *node, QString command)
{
    ERROR = false;

    id="";
    name="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case NAME: if(name=="") name = parameter.value; else { Procedures::writeError("Parametro NAME ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MKGRP"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(name, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Mkgrp::execute(QString name, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && name!=""){
        Procedures::writeLine("llego a execute NT_Mkgrp");
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(name=="")
            Procedures::writeError("Falta el parametro &name");
    }
}
