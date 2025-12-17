#ifndef FOOD_H
#define FOOD_H

#include "Position.h"
#include <deque>

class Food {
private:
    Position pos; //  @
    bool special; // $ 

public:
    Food();
    void generate(int width, int height, const std::deque<Position>& snake);  // random vị trí nhưng né con rắn ra 
    Position get() const;
    bool isSpecial() const;
};

#endif
