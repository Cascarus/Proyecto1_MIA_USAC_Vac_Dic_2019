#ifndef NT_CHMOD_H
#define NT_CHMOD_H

#include "procedures.h"

class NT_Chmod
{
public:
    NT_Chmod();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, QString ugo, bool r, QString command);

    bool ERROR;

    QString id;
    QString path;
    QString ugo;
    bool r;

};

#endif // NT_CHMOD_H
