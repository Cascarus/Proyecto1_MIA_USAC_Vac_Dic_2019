#include "nodeast.h"

NodeAST::NodeAST()
{
    type ="";
    value = "";
    line = 0;
    column = 0;
    childs =  QList<NodeAST>();
}

NodeAST::NodeAST(int line, int column, QString type, QString value)
{
    this->line = line;
    this->column = column;
    this->type = type;
    this->value = value;
    this->type_ = getType();
    this->command = "";
    this->childs = QList<NodeAST>();
}

int NodeAST::getType()
{
    if(this->type=="ADD") {return 1;}
    if(this->type=="ARCHIVE") {return 2;}
    if(this->type=="CONT") {return 3;}
    if(this->type=="DELETE") {return 4;}
    if(this->type=="DESTINY") {return 5;}
    if(this->type=="FIT") {return 6;}
    if(this->type=="GRP") {return 7;}
    if(this->type=="ID") {return 8;}
    if(this->type=="IDDESTINY") {return 9;}
    if(this->type=="NAME") {return 10;}
    if(this->type=="NTCAT") {return 11;}
    if(this->type=="NTCHGRP") {return 12;}
    if(this->type=="NTCHMOD") {return 13;}
    if(this->type=="NTCHOWN") {return 14;}
    if(this->type=="NTCP") {return 15;}
    if(this->type=="NTEDIT") {return 16;}
    if(this->type=="NTEXEC") {return 17;}
    if(this->type=="NTFDISK") {return 18;}
    if(this->type=="NTFIND") {return 19;}
    if(this->type=="NTINSTRUCTION") {return 20;}
    if(this->type=="NTINSTRUCTIONS") {return 21;}
    if(this->type=="NTLOGIN") {return 22;}
    if(this->type=="NTLOGOUT") {return 23;}
    if(this->type=="NTLOSS") {return 24;}
    if(this->type=="NTMKDIR") {return 25;}
    if(this->type=="NTMKDISK") {return 26;}
    if(this->type=="NTMKFILE") {return 27;}
    if(this->type=="NTMKFS") {return 28;}
    if(this->type=="NTMKGRP") {return 29;}
    if(this->type=="NTMKUSR") {return 30;}
    if(this->type=="NTMOUNT") {return 31;}
    if(this->type=="NTMV") {return 32;}
    if(this->type=="NTPAUSE") {return 33;}
    if(this->type=="NTRECOVERY") {return 34;}
    if(this->type=="NTREN") {return 35;}
    if(this->type=="NTREP") {return 36;}
    if(this->type=="NTRM") {return 37;}
    if(this->type=="NTRMDISK") {return 38;}
    if(this->type=="NTRMGRP") {return 39;}
    if(this->type=="NTRMUSR") {return 40;}
    if(this->type=="NTUNMOUNT") {return 41;}
    if(this->type=="P") {return 42;}
    if(this->type=="PATH") {return 43;}
    if(this->type=="PWD") {return 44;}
    if(this->type=="R") {return 45;}
    if(this->type=="RF") {return 46;}
    if(this->type=="RUTA") {return 47;}
    if(this->type=="SIZE") {return 48;}
    if(this->type=="TYPE") {return 49;}
    if(this->type=="UGO") {return 50;}
    if(this->type=="UNIT") {return 51;}
    if(this->type=="USR") {return 52;}
    return 0;
}

void NodeAST::add(NodeAST node)
{
    this->childs.append(node);
}
