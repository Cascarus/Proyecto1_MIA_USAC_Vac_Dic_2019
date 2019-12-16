#ifndef NT_MKFS_H
#define NT_MKFS_H

#include "procedures.h"

class NT_Mkfs
{
public:
    NT_Mkfs();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString type, QString command);

    bool ERROR;

    QString id;
    QString type;

};

#endif // NT_MKFS_H
