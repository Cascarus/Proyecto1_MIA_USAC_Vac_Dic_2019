#include "nt_mkfile.h"

NT_Mkfile::NT_Mkfile()
{

}

void NT_Mkfile::tourAST(NodeAST *node, QString command)
{
    ERROR = false;

    id="";
    path="";
    p=false;
    size=0;
    cont="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case P: if(p==false) p = parameter.value.toInt(); else { Procedures::writeError("Parametro P ya ingresado anteriormente"); ERROR = true; } break;
        case SIZE: if(size==0) size = parameter.value.toInt(); else { Procedures::writeError("Parametro SIZE ya ingresado anteriormente"); ERROR = true; } break;
        case CONT: if(cont=="") cont = parameter.value; else { Procedures::writeError("Parametro CONT ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MKFILE"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, p, size, cont, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Mkfile::execute(QString id, QString path, bool p, int size, QString cont, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!=""){
        Procedures::writeLine("llego a execute NT_Mkfile");

        USER userlogin = Procedures::getUserLogin();
        if(userlogin.name!="" && userlogin.id!=""){
            if(userlogin.id == id.toUpper()){
                switch (Procedures::crearArchivoNuevo(id,path,p,size,cont)) {
                case EXISTE:
                    Procedures::writeError("No se logro crear el archivo porque ya existe.");
                    break;
                case EXITO:
                    Procedures::writeLine("Se creo "+ path +" con éxito.");
                    break;
                case FALLO:
                    Procedures::writeError("No se logro crear el archivo porque faltan carpetas padre");
                    break;
                case SIN_PERMISOS_LECTURA:
                    Procedures::writeError("No se logro crear el archivo porque no tienen permisos de lectura");
                    break;
                case SIN_PERMISOS_ESCRITURA:
                    Procedures::writeError("No se logro crear el archivo porque no tienen permisos de escritura.");
                    break;
                default:
                    break;
                }
            }
        }
        else{
            if(id=="")
                Procedures::writeError("Falta el parametro &id");
            if(path=="")
                Procedures::writeError("Falta el parametro &path");
        }
    }
}
