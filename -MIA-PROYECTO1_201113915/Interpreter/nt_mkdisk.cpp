#include "nt_mkdisk.h"

NT_Mkdisk::NT_Mkdisk()
{

}

void NT_Mkdisk::tourAST(NodeAST *node, QString command){
    ERROR = false;
    size=0;
    name="";
    unit="";
    path="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case SIZE: if(size==0) size = parameter.value.toInt(); else { Procedures::writeError("Parametro SIZE ya ingresado anteriormente"); ERROR = true; } break;
        case NAME: if(name=="") name = parameter.value; else { Procedures::writeError("Parametro NAME ya ingresado anteriormente"); ERROR = true; } break;
        case UNIT: if(unit=="") unit = parameter.value; else { Procedures::writeError("Parametro UNIT ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MKDISK"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(size, name, unit, path, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Mkdisk::execute(int size, QString name, QString unit,QString path, QString command){
    Procedures::writeCommand(command);
    if(size != 0 && path!="" && name!=""){
        //Procedures::writeLine("llego a execute NT_Mkdisk");
        QStringList Directorys = path.split('/',QString::SkipEmptyParts);

        path = "/" + Directorys.join('/')+"/";

        Procedures::createDirectory(path+name);
        Procedures::createFile(path+name,size,unit);
    }
    else{
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
        if(name=="")
            Procedures::writeError("Falta el parametro &name");
        if(size==0)
            Procedures::writeError("Falta el parametro &size");
    }
}


