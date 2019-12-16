#ifndef NT_CAT_H
#define NT_CAT_H

#include "procedures.h"

class NT_Cat
{
public:
    NT_Cat();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QStringList file, QString command);

    bool ERROR;

    QString id;
    QStringList archive;

};

#endif // NT_CAT_H
