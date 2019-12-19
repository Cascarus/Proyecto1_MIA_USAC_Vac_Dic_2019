#include "nt_rmusr.h"

NT_Rmusr::NT_Rmusr()
{

}

void NT_Rmusr::tourAST(NodeAST *node, QString command)
{
    ERROR = false;

    id="";
    usr="";

    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case USR: if(usr=="") usr = parameter.value; else { Procedures::writeError("Parametro USR ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en RMUSR"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, usr, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Rmusr::execute(QString id, QString usr, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && usr!=""){
        Procedures::writeLine("llego a execute NT_Rmusr");
        if(Procedures::removerUsuario(usr,id))
            Procedures::writeLine("Se elimino el usuario.");
        else
            Procedures::writeError("No se elimino el usuario ya que no existe.");
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(usr=="")
            Procedures::writeError("Falta el parametro &usr");
    }
}
