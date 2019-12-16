#ifndef NT_REP_H
#define NT_REP_H

#include "procedures.h"

class NT_Rep
{
public:
    NT_Rep();
    ~NT_Rep();
    void tourAST(NodeAST *node, QString command);
    void execute(QString path, QString name, QString id, QString ruta, QString command);

    bool ERROR;

    QString path;
    QString name;
    QString id;
    QString ruta;

};

#endif // NT_REP_H
