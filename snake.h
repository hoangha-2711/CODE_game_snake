#ifndef SNAKE_H_
#define SNAKE_H_
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

const int SNAKE_SIZE = 128;
const int SNAKE_SPEED = 15;

enum Direction // khởi tạo các hướng
{
    Up,
    Down,
    Left,
    Right,
    None// ko di chuyển
};

class snake
{
public:
    //constructor
    snake();
    //destructor
    ~snake();
    void setDirection(int newDirect);
    void eraseTail(); 
    void snakeMove();
    bool getFruit();
    void moveSnakeCell();
    void grownUp();
    bool dead();
    vector<SDL_Rect> getCell();
    int getPosX();
    int getPosY();
private:
    bool isDead, grow;
    int direct, preDirect;
    vector<SDL_Rect> snakeCell;
    SDL_Rect snakePart;
};

#endif // SNAKE_H_
