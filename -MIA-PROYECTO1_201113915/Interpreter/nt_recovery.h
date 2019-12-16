#ifndef NT_RECOVERY_H
#define NT_RECOVERY_H

#include "procedures.h"

class NT_Recovery
{
public:
    NT_Recovery();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString command);

    bool ERROR;

    QString id;

};

#endif // NT_RECOVERY_H
