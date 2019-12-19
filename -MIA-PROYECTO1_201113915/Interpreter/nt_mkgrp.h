#ifndef NT_MKGRP_H
#define NT_MKGRP_H

#include "procedures.h"

class NT_Mkgrp
{
public:
    NT_Mkgrp();
    void tourAST(NodeAST *node, QString command);
    void execute(QString name, QString id, QString command);

    bool ERROR;

    QString id;
    QString name;

};

#endif // NT_MKGRP_H
