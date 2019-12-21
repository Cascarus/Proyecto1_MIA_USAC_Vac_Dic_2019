#include "nt_mkdir.h"

NT_Mkdir::NT_Mkdir()
{

}

void NT_Mkdir::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    path="";
    p=false;
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case P: if(p==false) p = parameter.value.toInt(); else { Procedures::writeError("Parametro P ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MKDIR"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, p, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Mkdir::execute(QString id, QString path, bool p, QString command)
{
    Procedures::writeCommand(command);



    if(id!="" && path!=""){
        Procedures::writeLine("llego a execute NT_Mkdir");

        Procedures::crearRegistroLog(id, ACTIONCREATE, LOG_CARPETA, path, "", p);

        USER userlogin = Procedures::getUserLogin();
        if(userlogin.name!="" && userlogin.id!=""){
            if(userlogin.id == id.toUpper()){
                switch (Procedures::crearCarpetaNueva(id, path, p)) {
                case EXISTE:
                    Procedures::writeError("No se logro crear carpeta porque ya existe.");
                    break;
                case EXITO:
                    Procedures::writeLine("Se creo carpeta con éxito.");
                    break;
                case FALLO:
                    Procedures::writeError("No se logro crear la carpeta porque faltan carpetas padre");
                    break;
                case SIN_PERMISOS_LECTURA:
                    Procedures::writeError("No se logro crear la carpeta porque no tienen permisos de lectura");
                    break;
                case SIN_PERMISOS_ESCRITURA:
                    Procedures::writeError("No se logro crear la carpeta porque no tienen permisos de escritura.");
                    break;
                default:
                    break;
                }
            }else{
                Procedures::writeError("Partición a modificar no corresponde al usuario logeado.");
            }

        }else{
            Procedures::writeError("No se a iniciado sesión.");
        }

    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(path=="")
            Procedures::writeError("Falta el parametro &path");
    }


}
