#include "Food.h"
#include <cstdlib>

Food::Food() {
    special = false;
}

void Food::generate(int width, int height, const std::deque<Position>& snake) {
    while (true) {
        pos.x = rand() % (width - 2) + 1; // tránh 2 bên tường 
        pos.y = rand() % height; 

        bool conflict = false;
        for (auto s : snake)
            if (s.x == pos.x && s.y == pos.y) { conflict = true; break; }

        if (!conflict) break;
    }

    special = (rand() % 5 == 0); // 20%
}

Position Food::get() const {
    return pos;
}

bool Food::isSpecial() const {
    return special;
}
