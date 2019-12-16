#ifndef NT_RMGRP_H
#define NT_RMGRP_H

#include "procedures.h"

class NT_Rmgrp
{
public:
    NT_Rmgrp();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString name, QString command);

    bool ERROR;

    QString id;
    QString name;

};

#endif // NT_RMGRP_H
