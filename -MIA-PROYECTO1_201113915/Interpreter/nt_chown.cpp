#include "nt_chown.h"

NT_Chown::NT_Chown()
{

}

void NT_Chown::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    id="";
    path="";
    usr="";
    r=false;
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        case PATH: if(path=="") path = parameter.value; else { Procedures::writeError("Parametro PATH ya ingresado anteriormente"); ERROR = true; } break;
        case USR: if(usr=="") usr = parameter.value; else { Procedures::writeError("Parametro USR ya ingresado anteriormente"); ERROR = true; } break;
        case R: if(r==false) r = parameter.value.toInt(); else { Procedures::writeError("Parametro R ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en CHOWN"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, path, usr, r, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Chown::execute(QString id, QString path, QString usr, bool r, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && path!="" && usr!=""){
        Procedures::writeLine("llego a execute NT_Chown");

        USER userlogin = Procedures::getUserLogin();
        if(userlogin.name!="" && userlogin.id!=""){
            if(userlogin.id == id.toUpper()){
                switch (Procedures::cambiarPropietario(id, path, usr, r)) {
                case EXITO:
                    Procedures::writeLine("Se cambio permisos "+ path +" con éxito.");
                    break;
                case FALLO:
                    Procedures::writeError("No se logro cambiar permisos porque faltan carpetas padre");
                    break;
                case SIN_PERMISOS_LECTURA:
                    Procedures::writeError("No se logro cambiar permisos porque no tienen permisos de lectura");
                    break;
                case SIN_PERMISOS_ESCRITURA:
                    Procedures::writeError("No se logro cambiar permisos archivo porque no tienen permisos de escritura.");
                    break;
                default:
                    break;
                }
            }

        }

    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &usr");
        if(path=="")
            Procedures::writeError("Falta el parametro &grp");
        if(usr=="")
            Procedures::writeError("Falta el parametro &grp");
    }
}
