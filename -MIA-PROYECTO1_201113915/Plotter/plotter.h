#ifndef PLOTTER_H
#define PLOTTER_H

#include "NodeAST/nodeast.h"
#include <fstream>
#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>

class Plotter
{
public:
    Plotter();
    Plotter(NodeAST *root);
    NodeAST *root;
    int counter;
    QString grapho;
    QString graph();
    void tourAST(QString parent, NodeAST *child);
    QString escape(QString strg);
    void generateImage();
};

#endif // PLOTTER_H
