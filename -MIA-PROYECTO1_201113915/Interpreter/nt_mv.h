#ifndef NT_MV_H
#define NT_MV_H

#include "procedures.h"

class NT_Mv
{
public:
    NT_Mv();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, QString destiny, QString command);

    bool ERROR;
    QString id;
    QString path;
    QString destiny;

};

#endif // NT_MV_H
