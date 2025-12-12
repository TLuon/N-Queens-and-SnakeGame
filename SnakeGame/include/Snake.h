#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "Position.h"
#include "Direction.h"

class Snake {
private:
    std::deque<Position> body;
    Direction dir;

public:
    Snake(int startX, int startY);

    void move();
    void grow();

    void setDirection(Direction d);
    Direction getDirection() const;

    Position getHead() const;
    const std::deque<Position>& getBody() const;
};

#endif
