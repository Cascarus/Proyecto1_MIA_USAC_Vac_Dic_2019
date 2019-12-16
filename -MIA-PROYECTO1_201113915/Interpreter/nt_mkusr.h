#ifndef NT_MKUSR_H
#define NT_MKUSR_H

#include "procedures.h"

class NT_Mkusr
{
public:
    NT_Mkusr();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString usr, QString pwd, QString grp, QString command);

    bool ERROR;

    QString id;
    QString usr;
    QString pwd;
    QString grp;

};

#endif // NT_MKUSR_H
