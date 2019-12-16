#ifndef NT_CHOWN_H
#define NT_CHOWN_H

#include "procedures.h"

class NT_Chown
{
public:
    NT_Chown();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, QString usr, bool r, QString command);

    bool ERROR;

    QString path;
    QString usr;
    QString id;
    bool r;

};

#endif // NT_CHOWN_H
