#ifndef NT_FIND_H
#define NT_FIND_H

#include "procedures.h"

class NT_Find
{
public:
    NT_Find();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, QString name, QString command);

    bool ERROR;
    QString id;
    QString path;
    QString name;

};

#endif // NT_FIND_H
