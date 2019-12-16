#ifndef NT_RMDISK_H
#define NT_RMDISK_H

#include "procedures.h"

class NT_Rmdisk
{
public:
    NT_Rmdisk();
    ~NT_Rmdisk();
    void tourAST(NodeAST *node, QString command);
    void execute(QString path, QString command);

    bool ERROR;

    QString path;

};

#endif // NT_RMDISK_H
