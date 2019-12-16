#include "nt_rmdisk.h"

NT_Rmdisk::NT_Rmdisk()
{

}

void NT_Rmdisk::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    path="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en RMDISK"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(path, command); else Procedures::writeError("Verificar comando ingresado.");
}
void NT_Rmdisk::execute(QString path, QString command){
    Procedures::writeCommand(command);
    if(path!=""){
        //Procedures::writeLine("llego a execute NT_Rmdisk");
        Procedures::deleteFile(path);
    }
    else{
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
    }
}
