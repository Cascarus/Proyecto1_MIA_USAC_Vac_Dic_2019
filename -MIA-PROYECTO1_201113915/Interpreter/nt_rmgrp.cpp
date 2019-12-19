#include "nt_rmgrp.h"

NT_Rmgrp::NT_Rmgrp()
{

}

void NT_Rmgrp::tourAST(NodeAST *node, QString command)
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
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en RMGRP"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, name, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Rmgrp::execute(QString id, QString name, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && name!=""){
        Procedures::writeLine("llego a execute NT_Rmgrp");
        if(Procedures::removerGrupo(name,id))
            Procedures::writeLine("Se elimino el grupo y sus usuarios.");
        else
            Procedures::writeError("No se elimino el grupo ya que no existe.");

    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(name=="")
            Procedures::writeError("Falta el parametro &name");
    }
}
