#ifndef NT_CP_H
#define NT_CP_H

#include "procedures.h"

class NT_Cp
{
public:
    NT_Cp();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, QString destiny, QString command);

    bool ERROR;

    QString id;
    QString path;
    QString destiny;
};

#endif // NT_CP_H
