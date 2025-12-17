#ifndef POSITION_H
#define POSITION_H

struct Position {
    int x, y;
    bool operator==(const Position& other) const { // để so sánh nhiều thứ với nhau 
        return x == other.x && y == other.y;
    }
};

#endif
