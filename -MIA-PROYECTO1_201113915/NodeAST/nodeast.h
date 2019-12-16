#ifndef NODEAST_H
#define NODEAST_H

#include <QList>
#include <QString>

class NodeAST
{
public:
    NodeAST();
    NodeAST(int, int, QString,QString);
    int getType();
    void add(NodeAST node);
    QString type;
    QString value;
    int line;
    int column;
    int type_;
    QString command;
    QList<NodeAST> childs;
};

#endif // NODEAST_H
