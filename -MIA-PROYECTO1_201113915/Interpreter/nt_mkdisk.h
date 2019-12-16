#ifndef NT_MKDISK_H
#define NT_MKDISK_H

#include "procedures.h"

class NT_Mkdisk
{
public:
    NT_Mkdisk();
    ~NT_Mkdisk() ;
    void tourAST(NodeAST *node, QString command);
    void execute(int size, QString name, QString unit, QString path, QString command);

    bool ERROR;

    int size;
    QString name;
    QString unit;
    QString path;

};

#endif // NT_MKDISK_H
