#ifndef NT_REM_H
#define NT_REM_H

#include "procedures.h"

class NT_Rm
{
public:
    NT_Rm();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, bool rf, QString command);

    bool ERROR;

    QString id;
    QString path;
    bool rf;

};

#endif // NT_RM_H
