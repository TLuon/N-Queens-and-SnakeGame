#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "Position.h"
#include "Direction.h"

class Snake {
private:
    std::deque<Position> body; // mỗi phần tử là 1 đốt rắn, [0] đầu rắn, back là đuôi rắn 
    Direction dir;

public:
    Snake(int startX, int startY); // tạo rắn ban đầu 

    void move();
    void grow();

    void setDirection(Direction d);
    Direction getDirection() const;

    Position getHead() const;
    const std::deque<Position>& getBody() const; // tránh sửa từ bên ngoài, chỉ thay đổi khi ăn thức ăn 
};

#endif
