#ifndef NT_MOUNT_H
#define NT_MOUNT_H

#include "procedures.h"

class NT_Mount
{
public:
    NT_Mount();
    ~NT_Mount();
    void tourAST(NodeAST *node, QString command);
    void execute(QString name,QString path, QString command);

    bool ERROR;

    QString name;
    QString path;

};

#endif // NT_MOUNT_H
