#ifndef NT_RMUSR_H
#define NT_RMUSR_H

#include "procedures.h"

class NT_Rmusr
{
public:
    NT_Rmusr();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString usr, QString command);

    bool ERROR;

    QString id;
    QString usr;

};

#endif // NT_RMUSR_H
