#include "nt_mount.h"

NT_Mount::NT_Mount()
{

}

void NT_Mount::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    name="";
    path="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case NAME: if(name=="") name = parameter.value; else { Procedures::writeError("Parametro NAME ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MOUNT"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(name, path, command); else Procedures::writeError("Verificar comando ingresado.");
}
void NT_Mount::execute(QString name,QString path, QString command){
    Procedures::writeCommand(command);
    if(name!="" && path!=""){
        //Procedures::writeLine("llego a execute NT_Mount");
        bool EXIST = Procedures::existPartition(name,path);

        if(EXIST)
        {
            Procedures::mountPartition(path,name);
            Procedures::writeMountPartition();
        }
        else
            Procedures::writeError("No existe el disco o la partición, no se monto la partición");
    }
    else{
        if(name=="")
            Procedures::writeError("Falta el parametro &usr");
        if(path=="")
            Procedures::writeError("Falta el parametro &grp");
    }
}
