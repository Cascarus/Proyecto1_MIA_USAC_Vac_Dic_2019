#include "nt_login.h"

NT_Login::NT_Login()
{

}

void NT_Login::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    usr="";
    pwd="";
    id="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case USR: if(usr=="") usr = parameter.value; else { Procedures::writeError("Parametro USR ya ingresado anteriormente"); ERROR = true; } break;
        case PWD: if(pwd=="") pwd = parameter.value; else { Procedures::writeError("Parametro PWD ya ingresado anteriormente"); ERROR = true; } break;
        case ID: if(id=="") id = parameter.value; else { Procedures::writeError("Parametro ID ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en LOGIN"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(usr, pwd, id, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Login::execute(QString usr, QString pwd, QString id, QString command)
{
    Procedures::writeCommand(command);
    if(id!="" && usr!="" && pwd!=""){
        Procedures::writeLine("llego a execute NT_Login");
    }
    else{
        if(usr=="")
            Procedures::writeError("Falta el parametro &usr");
        if(pwd=="")
            Procedures::writeError("Falta el parametro &pwd");
        if(id=="")
            Procedures::writeError("Falta el parametro &id");
    }
}
