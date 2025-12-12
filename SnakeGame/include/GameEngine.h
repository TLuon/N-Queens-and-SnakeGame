#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Snake.h"
#include "Food.h"
#include "GameState.h"
#include <vector>

class GameEngine {
private:
    const int width = 40;
    const int height = 20;

    Snake snake;
    Food food;
    int score = 0;
    int speed = 120;

    GameState state;
    bool paused = false;

    std::vector<Position> obstacles;

    void draw();
    void drawMenu();
    void drawGameOver();
    void placeObstacles();
    void drawObstacles();

    void handleInput();
    void update();
    void changeSpeed();

    void reset();   // <-- THÊM DÒNG NÀY

public:
    GameEngine();
    void run();
};

#endif
