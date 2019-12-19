#include "nt_cat.h"

NT_Cat::NT_Cat()
{

}

void NT_Cat::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    archive.clear();
    id="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ARCHIVE: archive.append(parameter.value); break;
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en CAT"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, archive, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Cat::execute(QString id, QStringList archive, QString command)
{
    Procedures::writeCommand(command);
    if(id != "" && !archive.isEmpty()){
        Procedures::writeLine("llego a execute NT_Cat");
        Procedures::mostrarContenido(id,archive);
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(archive.isEmpty())
            Procedures::writeError("Falta el parametro &file");
    }
}
