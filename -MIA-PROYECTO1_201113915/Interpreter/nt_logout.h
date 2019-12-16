#ifndef NT_LOGOUT_H
#define NT_LOGOUT_H

#include "procedures.h"

class NT_Logout
{
public:
    NT_Logout();
    void execute(QString command);

    bool ERROR;

};

#endif // NT_LOGOUT_H
