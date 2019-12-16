#ifndef IOCONSOLE_H
#define IOCONSOLE_H

#include "QDebug"
#include "QString"

class IOConsole
{
public:
    IOConsole();
    static void writeLine(QString Line, int TextColor, int TextStyle);
    static void writeLine(QString Line, int TextColor);
    static void writeLine(QString Line);
    static void writeError(QString Line);
    static QString readLine();
    static QString read(int size);
    static void clearScreen();
    static void pauseConsole();

    enum COLOR{
        BLACK    = 30,
        RED      = 31,
        GREEN    = 32,
        YELLOW   = 33,
        BLUE     = 34,
        PURPLE   = 35,
        CYAN     = 36,
        WHITE    = 37,
        BGBLACK  = 40,
        BGRED    = 41,
        BGGREEN  = 42,
        BGYELLOW = 43,
        BGBLUE   = 44,
        BGPURPLE = 45,
        BGCYAN   = 46,
        BGWHITE  = 47
    };

    enum STYLE{
        NORMAL       = 0,
        BRIGHTER     = 1,
        BOLD         = 2,
        UNDERLINE    = 4,
        FLASHING     = 5,
    };
};

#endif // IOCONSOLE_H
