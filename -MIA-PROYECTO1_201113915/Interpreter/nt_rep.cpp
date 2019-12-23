#include "nt_rep.h"

NT_Rep::NT_Rep()
{

}

void NT_Rep::tourAST(NodeAST *node, QString command) {
    ERROR = false;
    path="";
    name="";
    id="";
    ruta="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case NAME: if(name=="") name = parameter.value; else { Procedures::writeError("Parametro NAME ya ingresado anteriormente"); ERROR = true; } break;
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case RUTA: if(ruta=="") ruta = parameter.value; else { Procedures::writeError("Parametro RUTA ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en REP"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(path, name, id, ruta, command); else Procedures::writeError("Verificar comando ingresado.");
}
void NT_Rep::execute(QString path, QString name, QString id, QString ruta, QString command){

    Procedures::writeCommand(command);
    if(id!="" && path!="" && name!=""){
        Procedures::writeLine("llego a execute NT_Rep");
        if(name.toUpper()=="MBR")
            Procedures::generateRepMBR(path,id);
        else if(name.toUpper()=="FILE")
            Procedures::generateRepFile(path,id,ruta);
        else if(name.toUpper()=="DISK")
            Procedures::generateRepDisk(path,id);
        else if(name.toUpper()=="INODE")
            Procedures::generateRepInode(path,id);
        else if(name.toUpper()=="SB")
            Procedures::generateRepSb(path,id);
        else if(name.toUpper()=="BM_ARBDIR")
            Procedures::generateRepBm_Arbdir(path,id);
        else if(name.toUpper()=="BM_DETDIR")
            Procedures::generateRepBm_Detdir(path,id);
        else if(name.toUpper()=="BM_INODE")
            Procedures::generateRepBm_Inode(path,id);
        else if(name.toUpper()=="BM_BLOCK")
            Procedures::generateRepBm_Block(path,id);
        else if(name.toUpper()=="BITACORA")
            Procedures::generateRepBitacora(path,id);
        else if(name.toUpper()=="DIRECTORIO")
            Procedures::generateRepDirectorio(path,id);
        else if(name.toUpper()=="TREE_FILE")
            Procedures::generateRepTreeFile(path,id,ruta);
        else if(name.toUpper()=="TREE_DIRECTORIO")
            Procedures::generateRepTreeDirectorio(path,id);
        else if(name.toUpper()=="TREE_COMPLETE")
            Procedures::generateRepTreeComplete(path,id);
        else if(name.toUpper()=="LS")
            Procedures::generateRepLs(path,id,ruta);
        else
            Procedures::writeError("No existe tipo de reporte");
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
