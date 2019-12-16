#ifndef NT_EDIT_H
#define NT_EDIT_H

#include "procedures.h"

class NT_Edit
{
public:
    NT_Edit();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, int size, QString cont, QString command);

    bool ERROR;

    QString id;
    QString path;
    int size;
    QString cont;

};

#endif // NT_EDIT_H
