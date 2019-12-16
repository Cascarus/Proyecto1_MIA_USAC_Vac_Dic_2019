#ifndef NT_UNMOUNT_H
#define NT_UNMOUNT_H

#include "procedures.h"

class NT_Unmount
{
public:
    NT_Unmount();
    ~NT_Unmount();
    void tourAST(NodeAST *node, QString command);
    void execute(QStringList id, QString command);

    bool ERROR;

    QStringList id;

};

#endif // NT_UNMOUNT_H
