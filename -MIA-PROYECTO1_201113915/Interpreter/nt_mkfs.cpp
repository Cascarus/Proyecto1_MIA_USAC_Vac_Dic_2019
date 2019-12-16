#include "nt_mkfs.h"

NT_Mkfs::NT_Mkfs()
{

}

void NT_Mkfs::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    type="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case TYPE: if(type=="") type = parameter.value; else { Procedures::writeError("Parametro TYPE ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MKFS"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, type, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Mkfs::execute(QString id, QString type, QString command)
{
    Procedures::writeCommand(command);
    if(id!=""){
        Procedures::writeLine("llego a execute NT_Mkfs");
        Procedures::formatPartition(id, type);
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
    }

}
