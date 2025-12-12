#include "Console.h"

void Console::gotoXY(int x, int y) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(h, pos);
}

void Console::hideCursor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 20;
    SetConsoleCursorInfo(h, &info);
}

void Console::clear() {
    gotoXY(0, 0);
}

void Console::setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
