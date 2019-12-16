#ifndef NT_MKDIR_H
#define NT_MKDIR_H

#include "procedures.h"

class NT_Mkdir
{
public:
    NT_Mkdir();
    void tourAST(NodeAST *node, QString command);
    void execute(QString id, QString path, bool p, QString command);

    bool ERROR;
    QString id;
    QString path;
    bool p;

};

#endif // NT_MKDIR_H
