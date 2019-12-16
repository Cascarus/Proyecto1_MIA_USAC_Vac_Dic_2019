#ifndef NT_MKFILE_H
#define NT_MKFILE_H

#include "procedures.h"

class NT_Mkfile
{
public:
    NT_Mkfile();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, bool p, int size, QString cont, QString command);

    bool ERROR;

    QString id;
    QString path;
    bool p;
    int size;
    QString cont;

};

#endif // NT_MKFILE_H
