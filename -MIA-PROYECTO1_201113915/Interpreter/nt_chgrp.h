#ifndef NT_CHGRP_H
#define NT_CHGRP_H

#include "procedures.h"

class NT_Chgrp
{
public:
    NT_Chgrp();
    void tourAST(NodeAST *node, QString command);
    void execute(QString usr, QString grp, QString command);

    bool ERROR;

    QString usr;
    QString grp;

};

#endif // NT_CHGRP_H
