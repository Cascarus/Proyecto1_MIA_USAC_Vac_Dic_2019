#include "nt_fdisk.h"

NT_Fdisk::NT_Fdisk()
{

}

void NT_Fdisk::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    B_ADD = false;
    B_DEL = false;
    B_CREATE = false;
    size=0;
    unit="";
    path="";
    type="";
    fit="";
    del="";
    name="";
    add=false;
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case SIZE: if(size==0) size = parameter.value.toInt(); else { Procedures::writeError("Parametro SIZE ya ingresado anteriormente"); ERROR = true; } break;
        case UNIT: if(unit=="") unit = parameter.value; else { Procedures::writeError("Parametro UNIT ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case TYPE: if(type=="") type = parameter.value; else { Procedures::writeError("Parametro TYPE ya ingresado anteriormente"); ERROR = true; } break;
        case FIT: if(fit=="") fit = parameter.value; else { Procedures::writeError("Parametro FIT ya ingresado anteriormente"); ERROR = true; } break;
        case DELETE: if(!B_ADD) B_DEL = true; if(del=="") del = parameter.value; else { Procedures::writeError("Parametro DEL ya ingresado anteriormente"); ERROR = true; } break;
        case NAME: if(name=="") name = parameter.value; else { Procedures::writeError("Parametro NAME ya ingresado anteriormente"); ERROR = true; } break;
        case ADD: if(!B_DEL) B_ADD = true; if(add==false) add = parameter.value.toInt(); else { Procedures::writeError("Parametro ADD ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Error parametro "+parameter.type.toUpper()+" no permitido en FDISK"); ERROR = true; break;
        }
    }
    if(!B_DEL && !B_ADD) B_CREATE = true;
    if(!ERROR) execute(size, unit, path, type, fit, del, name, add, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Fdisk::execute(int size, QString unit, QString path, QString type, QString fit, QString del, QString name, int add, QString command){

    Procedures::writeCommand(command);
    EBR nulo;

    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';

    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    if( path!="" && name!="")
    {
        //Procedures::writeLine("llego a execute NT_Fdisk");
        ifstream exist(path.toUtf8(), ios::in);
        if(exist.good()){
            if(B_DEL && !B_ADD && !B_CREATE)
            {
                if(Procedures::deletePartition(path,del,name))
                    Procedures::writeLine("Se borro éxitosamente la partición");
                else
                    Procedures::writeError("No se logro borrar la partición");
            }
            else if (!B_DEL && B_ADD && !B_CREATE)
                Procedures::addPartition(unit,path,name,add);
            else if (!B_DEL && !B_ADD && B_CREATE)
            {
                if(Procedures::comprobateName(name,path))
                    if(size!=0)
                        Procedures::createPartition(size, unit, path, type, fit, name);
                    else
                       Procedures::writeError("Falta el parametro &size");
                else
                    Procedures::writeError("Nombre para particion no disponible");
            }
        }
        else
            Procedures::writeError("Disco no existe");
    }
    else
    {
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
        if(name=="")
            Procedures::writeError("Falta el parametro &name");
    }
}
