#include "nt_chgrp.h"

NT_Chgrp::NT_Chgrp()
{

}

void NT_Chgrp::tourAST(NodeAST *node, QString command)
{
    ERROR = false;
    usr="";
    grp="";
    for (int i=0;i<node->childs.size();i++)
    {
        NodeAST parameter = node->childs.at(i).childs.at(0);
        switch (parameter.type_)
        {
        case USR: if(usr=="") usr = parameter.value; else { Procedures::writeError("Parametro USR ya ingresado anteriormente"); ERROR = true; } break;
        case GRP: if(grp=="") grp = parameter.value; else { Procedures::writeError("Parametro GRP ya ingresado anteriormente"); ERROR = true; } break;
        default: Procedures::writeError("Parametro "+parameter.type.toUpper()+" no permitido en CHGRP"); ERROR = true; break;
        }
    }
    if(!ERROR) execute(usr, grp, command); else Procedures::writeError("Verificar comando ingresado.");
}

void NT_Chgrp::execute(QString usr, QString grp, QString command)
{

    Procedures::writeCommand(command);
    if(usr!="" && grp!=""){
        Procedures::writeLine("llego a execute NT_Chgrp");
    }
    else{
        if(usr=="")
            Procedures::writeError("Falta el parametro &usr");
        if(grp=="")
            Procedures::writeError("Falta el parametro &grp");
    }
}
