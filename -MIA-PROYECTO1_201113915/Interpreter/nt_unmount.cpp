#include "nt_unmount.h"

NT_Unmount::NT_Unmount()
{

}

void NT_Unmount::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id.clear();
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: id.append(parameter.value); break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en UNMOUNT"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, command); else Procedures::writeError("Verificar comando ingresado.");
}
void NT_Unmount::execute(QStringList id, QString command){

    Procedures::writeCommand(command);
    if(!id.isEmpty()){
        //Procedures::writeLine("llego a execute NT_Unmount");
        for(int i=0;i<id.length();i++)
            Procedures::unmountPartition(id.at(i));
        Procedures::writeMountPartition();
    }else{
        if(id.isEmpty())
            Procedures::writeError("Falta el parametro &id");
    }

}
