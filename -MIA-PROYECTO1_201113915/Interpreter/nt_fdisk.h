#ifndef NT_FDISK_H
#define NT_FDISK_H

#include "procedures.h"

class NT_Fdisk
{
public:
    NT_Fdisk();
    ~NT_Fdisk();
    void tourAST(NodeAST *node, QString command);
    void execute(int size, QString unit, QString path, QString type, QString fit, QString del, QString name, int add, QString command);

    bool ERROR;

    int size;
    QString unit;
    QString path;
    QString type;
    QString fit;
    QString del;
    QString name;
    int add;

    bool B_ADD,B_DEL,B_CREATE;

};

#endif // NT_FDISK_H
