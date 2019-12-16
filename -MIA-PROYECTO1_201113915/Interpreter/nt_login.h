#ifndef NT_LOGIN_H
#define NT_LOGIN_H

#include "procedures.h"

class NT_Login
{
public:
    NT_Login();
    void tourAST(NodeAST *node, QString command);
    void execute(QString usr, QString pwd, QString id, QString command);

    bool ERROR;

    QString usr;
    QString pwd;
    QString id;

};

#endif // NT_LOGIN_H
