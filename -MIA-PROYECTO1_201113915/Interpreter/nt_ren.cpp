#include "nt_ren.h"

NT_Ren::NT_Ren()
{

}

void NT_Ren::tourAST(NodeAST *node, QString command)
{
    ERROR = false;

    id="";
    path="";
    name="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case NAME: if(name=="") name = parameter.value; else { Procedures::writeError("Parametro NAME ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en REN"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, name, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Ren::execute(QString id, QString path, QString name, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!="" && name!=""){

        USER userlogin = Procedures::getUserLogin();
        if(userlogin.name!="" && userlogin.id!=""){
            if(userlogin.id == id.toUpper()){
                switch (Procedures::renombrar(path,name,id)) {
                case EXITO:
                    Procedures::writeLine("Se renombro "+ path +" con éxito.");
                    break;
                case FALLO:
                    Procedures::writeError("No se logro renombrar porque faltan carpetas padre");
                    break;
                case SIN_PERMISOS_LECTURA:
                    Procedures::writeError("No se logro renombrar porque no tienen permisos de lectura");
                    break;
                case SIN_PERMISOS_ESCRITURA:
                    Procedures::writeError("No se logro renombrar archivo porque no tienen permisos de escritura.");
                    break;
                default:
                    break;
                }
            }

        }

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
