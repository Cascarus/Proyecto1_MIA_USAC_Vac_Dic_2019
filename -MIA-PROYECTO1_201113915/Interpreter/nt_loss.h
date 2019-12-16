#ifndef NT_LOSS_H
#define NT_LOSS_H

#include "procedures.h"

class NT_Loss
{
public:
    NT_Loss();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString command);

    bool ERROR;

    QString id;

};

#endif // NT_LOSS_H
