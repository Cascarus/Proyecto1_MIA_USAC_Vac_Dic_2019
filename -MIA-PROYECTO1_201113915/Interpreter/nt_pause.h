#ifndef NT_PAUSE_H
#define NT_PAUSE_H

#include "procedures.h"

class NT_Pause
{
public:
    NT_Pause();
    void execute(QString command);

    bool ERROR;

};

#endif // NT_PAUSE_H
