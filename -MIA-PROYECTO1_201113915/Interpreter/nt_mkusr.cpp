#include "nt_mkusr.h"

NT_Mkusr::NT_Mkusr()
{
}

void NT_Mkusr::tourAST(NodeAST *node, QString command)
{
    ERROR = false;

    id="";
    usr="";
    pwd="";
    grp="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro USR ya ingresado anteriormente"); ERROR = true; } break;
        case USR: if(usr=="") usr = parameter.value; else { Procedures::writeError("Parametro USR ya ingresado anteriormente"); ERROR = true; } break;
        case PWD: if(pwd=="") pwd = parameter.value; else { Procedures::writeError("Parametro PWD ya ingresado anteriormente"); ERROR = true; } break;
        case GRP: if(grp=="") grp = parameter.value; else { Procedures::writeError("Parametro GRP ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en MKUSR"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(id, usr, pwd, grp, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Mkusr::execute(QString id, QString usr, QString pwd, QString grp, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && usr!="" && pwd!="" && grp!=""){
        Procedures::writeLine("llego a execute NT_Mkusr");
        if(Procedures::crearUsuario(usr, pwd, grp, id))
            Procedures::writeLine("Se creo el usuario exitosamente");
        else
            Procedures::writeError("No se creo el usuario porque ya existe.");
    }
    else{
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
        if(usr=="")
            Procedures::writeError("Falta el parametro &usr");
        if(pwd=="")
            Procedures::writeError("Falta el parametro &pwd");
        if(grp=="")
            Procedures::writeError("Falta el parametro &grp");
    }
}
