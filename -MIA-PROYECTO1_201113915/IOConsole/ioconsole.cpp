#include "ioconsole.h"
#include <iostream>
#include <stdio.h>

using namespace std;
IOConsole::IOConsole()
{

}
void IOConsole::writeLine(QString Line, int TextColor, int TextStyle)
{
    QTextStream out(stdout);
    out << "\x1B["<< QString::number(TextStyle) <<";" << QString::number(TextColor) <<"m" << Line.toUtf8() << "\x1B[00m" << endl;
}
void IOConsole::writeLine(QString Line, int TextColor)
{
    QTextStream out(stdout);
    out << "\x1B[0;" << QString::number(TextColor) <<"m" << Line.toUtf8() << "\x1B[00m" << endl;
}
void IOConsole::writeLine(QString Line)
{
    QTextStream out(stdout);
    out << Line.toUtf8() << endl;
}
void IOConsole::writeError(QString Line)
{
    QTextStream out(stdout);
    out << "\x1B[5;41m" << Line.toUtf8() << "\x1B[00m" << endl;
}
QString IOConsole::readLine()
{
    QTextStream in(stdin);
    return in.readLine();
}
QString IOConsole::read(int size)
{
    QTextStream in(stdin);
    return in.read(size);
}
void IOConsole::clearScreen(){
    system("clear");
}

void IOConsole::pauseConsole(){
    QTextStream in(stdin);
    in.read(1);
}


