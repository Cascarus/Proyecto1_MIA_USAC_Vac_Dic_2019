#ifndef NT_EXEC_H
#define NT_EXEC_H

#include "procedures.h"

class NT_Exec
{
public:
    NT_Exec();
    ~NT_Exec();

    bool ERROR;

    void tourAST(NodeAST *node, QString command);
    void execute(QString path, QString command);

    QString path;
};

#endif // NT_EXEC_H
