#include "plotter.h"

Plotter::Plotter()
{
    this->counter = 0;
}

Plotter::Plotter(NodeAST *root)
{
    this->grapho = "";
    this->root = root;
    this->counter = 0;
}

QString Plotter::graph()
{
    grapho = "digraph G{";
    grapho += "node[shape=\"box\"];";
    grapho += "NodoAST0[label=\"" + escape(/*"[" +raiz->tipo +",\n" + QString::number(raiz->tipo_)+ "("+ QString::number(raiz->linea)+","+ QString::number(raiz->columna)+")"+"]"+*/root->value)  + "\"];\n";
    this->counter = 1;
    tourAST("NodoAST0", root);
    grapho += "}";
    return grapho;
}

void Plotter::tourAST(QString parent, NodeAST *child)
{
    int x = 0;
    for (x = 0 ; x < child->childs.count() ; x++)
    {
        NodeAST NodeAST = child->childs[x];
        QString nameChild = "NodoAST" +  QString::number(counter);
        grapho += nameChild + "[label=\"" + escape(/*"[" +NodoAST.tipo +"," + QString::number(NodoAST.tipo_)+ "("+ QString::number(NodoAST.linea)+","+ QString::number(NodoAST.columna)+")"+*/NodeAST.value)  + "\"];\n";
        grapho += parent + "->" + nameChild + ";\n";
        counter++;
        tourAST(nameChild, &NodeAST);
    }
}

QString Plotter::escape(QString strg)
{
    strg = strg.replace("\\", "\\\\");
    strg = strg.replace("\"", "\\\"");
    return strg;
}

void Plotter:: generateImage()
{
    graph();
    QString graphoDOT = this->grapho;
    QString path = "/home/victorsdb/";
    QFile qFile(path+"grapho.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << graphoDOT;
        qFile.close();
    }
    QString strgComand = "dot -Tpdf " + path + "grapho.dot -o " + path+"grapho.pdf";
    //std::cout << strgComand.toStdString() << "\n" << &endl;
    system(strgComand.toUtf8().constData());
    //system("xreader /home/victorsdb/grapho.pdf");
}
