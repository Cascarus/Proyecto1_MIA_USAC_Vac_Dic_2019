#ifndef NT_REN_H
#define NT_REN_H

#include "procedures.h"

class NT_Ren
{
public:
    NT_Ren();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, QString name, QString command);

    bool ERROR;

    QString id;
    QString path;
    QString name;

};

#endif // NT_REN_H
