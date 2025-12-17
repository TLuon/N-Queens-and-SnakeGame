#include "GameEngine.h"
#include "Console.h"
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

void GameEngine::run() {
    Console::hideCursor();

    while (true) {
        switch (state) {
        case GameState::MENU:
            drawMenu();
            break;

        case GameState::PLAYING:
            handleInput();
            if (!paused) {
                update();
                draw();
                Sleep(speed);
            }
            break;

        case GameState::GAME_OVER:
            drawGameOver();
            break;
        }
    }
}

GameEngine::GameEngine()
    : snake(width / 2, height / 2)
{
    srand((unsigned)time(nullptr));
    placeObstacles();                
    food.generate(width, height, snake.getBody());
    state = GameState::MENU;
}

void GameEngine::reset() {
    score = 0;
    speed = 120;
    paused = false;

    snake = Snake(width / 2, height / 2);

    placeObstacles();                
    food.generate(width, height, snake.getBody());

    state = GameState::PLAYING;

    while (_kbhit()) _getch();  
}

void GameEngine::handleInput() { // ổn định, không bị khựng 

    if (!_kbhit()) return;

    int c = _getch();
    if (c == 224) c = _getch(); 

    switch (c)
    {
    case 'p':
        paused = !paused;
        return;

    case 'w': case 'W': case 72:
        if (snake.getDirection() != Direction::DOWN)
            snake.setDirection(Direction::UP);
        break;

    case 's': case 'S': case 80:
        if (snake.getDirection() != Direction::UP)
            snake.setDirection(Direction::DOWN);
        break;

    case 'a': case 'A': case 75:
        if (snake.getDirection() != Direction::RIGHT)
            snake.setDirection(Direction::LEFT);
        break;

    case 'd': case 'D': case 77:
        if (snake.getDirection() != Direction::LEFT)
            snake.setDirection(Direction::RIGHT);
        break;

    default:
        break;
    }
}

void GameEngine::placeObstacles() { // hàm random chướng ngại 
    obstacles.clear();

    int count = rand() % 8 + 6; // 6–13 vật cản

    for (int i = 0; i < count; i++) {
        Position p;

        while (true) {
            p.x = rand() % (width - 2) + 1;
            p.y = rand() % height;

            bool conflict = false;

            for (auto s : snake.getBody())
                if (s == p) { conflict = true; break; }

            for (auto o : obstacles)
                if (o == p) { conflict = true; break; }

            if (p == food.get())
                conflict = true;

            if (!conflict) break;
        }
        obstacles.push_back(p);
    }
}

void GameEngine::drawObstacles() {
    Console::setColor(5);
    for (auto& o : obstacles) {
        Console::gotoXY(o.x, o.y + 1);
        cout << "|";
    }
    Console::setColor(7);
}

void GameEngine::draw() {
    Console::clear();

    Console::setColor(14);
    for (int x = 0; x < width; x++) cout << "#";
    cout << "\n";

    for (int y = 0; y < height; y++)
    {
        Console::setColor(14);
        cout << "#";

        for (int x = 1; x < width - 1; x++)
        {
            bool printed = false;
            Position head = snake.getHead();
            Position f = food.get();

            // HEAD
            if (x == head.x && y == head.y) {
                Console::setColor(10);
                cout << "O";
                Console::setColor(7);
                continue;
            }

            // BODY
            for (auto s : snake.getBody()) {
                if (s.x == x && s.y == y) {
                    Console::setColor(2);
                    cout << "o";
                    Console::setColor(7);
                    printed = true;
                    break;
                }
            }
            if (printed) continue;

            // FOOD
            if (x == f.x && y == f.y) {
                Console::setColor(food.isSpecial() ? 13 : 12);
                cout << (food.isSpecial() ? "$" : "@");
                Console::setColor(7);
                continue;
            }

            // OBSTACLES
            for (auto& o : obstacles) {
                if (o.x == x && o.y == y) {
                    Console::setColor(5);
                    cout << "|";
                    Console::setColor(7);
                    printed = true;
                    break;
                }
            }
            if (printed) continue;

            cout << " ";
        }

        Console::setColor(14);
        cout << "#\n";
    }

    Console::setColor(14);
    for (int x = 0; x < width; x++) cout << "#";
    Console::setColor(7);

    cout << "\nScore: " << score;
    if (paused) cout << "  [PAUSED]";
}

void GameEngine::update() {
    snake.move();
    Position head = snake.getHead();

    // Wall collision
    if (head.x <= 0 || head.x >= width - 1 || head.y < 0 || head.y >= height) {
        state = GameState::GAME_OVER;
        return;
    }

    // Body collision
    for (int i = 1; i < snake.getBody().size(); i++)
        if (snake.getBody()[i] == head)
            state = GameState::GAME_OVER;

    // Obstacle collision
    for (auto& o : obstacles)
        if (o == head) {
            state = GameState::GAME_OVER;
            return;
        }

    // Eat food
    if (head == food.get()) {
        score += food.isSpecial() ? 5 : 1;
        snake.grow();
        changeSpeed();
        food.generate(width, height, snake.getBody());
    }
}

void GameEngine::changeSpeed() {
    if (score > 200) speed = 40;
    else if (score > 100) speed = 55;
    else if (score > 50) speed = 70;
    else if (score > 20) speed = 90;
}

void GameEngine::drawMenu() {
    Console::clear();
    Console::setColor(14);
    cout << "==== SNAKE GAME ====\n";
    Console::setColor(7);
    cout << "SPACE = Start\n";
    cout << "P = Pause\n";

    if (_kbhit() && _getch() == ' ')
        state = GameState::PLAYING;
}

void GameEngine::drawGameOver() {
    Console::clear();
    Console::setColor(12);
    cout << "=== GAME OVER ===\n";

    Console::setColor(7);
    cout << "Score: " << score << "\n";
    cout << "Press R to restart\n";

    if (_kbhit()) {
        int c = _getch();
        if (c == 'r' || c == 'R') {
            while (_kbhit()) _getch();
            reset();
        }
    }
}
