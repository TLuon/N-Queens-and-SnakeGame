#include "Snake.h"

Snake::Snake(int startX, int startY) {
    body.clear();
    body.push_back({startX, startY});
    dir = Direction::RIGHT;
}

void Snake::setDirection(Direction d) {
    dir = d;
}

Direction Snake::getDirection() const {
    return dir;
}

Position Snake::getHead() const {
    return body.front();
}

const std::deque<Position>& Snake::getBody() const {
    return body;
}

void Snake::move() {
    Position head = getHead();

    switch (dir) {
    case Direction::UP:    head.y--; break;
    case Direction::DOWN:  head.y++; break;
    case Direction::LEFT:  head.x--; break;
    case Direction::RIGHT: head.x++; break;
    }

    body.push_front(head);
    body.pop_back();
}

void Snake::grow() {
    body.push_back(body.back());
}
