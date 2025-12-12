#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>

class Console {
public:
    static void gotoXY(int x, int y);
    static void hideCursor();
    static void clear();
    static void setColor(int color);
};

#endif
