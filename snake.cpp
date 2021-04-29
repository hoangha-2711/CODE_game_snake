#include "snake.h"
#include "sources.h"
#include <iostream>
#include <string>

snake::snake()
{
    snakePart.x = SCREEN_WIDTH / 4;
    snakePart.y = SCREEN_HEIGHT / 2; 
    snakePart.h = SNAKE_SIZE; 
    snakePart.w = SNAKE_SIZE;
    direct = None; 
    preDirect = None;
    snakeCell.push_back(snakePart);
    isDead = false;
    grow = false;
}

snake::~snake()
{

}

void snake::setDirection(int newDirect)
{
    if(direct == None) 
    {
        preDirect = direct;
        direct = newDirect;
    }
    else if((direct == Up && newDirect != Down) || (direct == Down && newDirect != Up)) 
    {
        preDirect = direct;
        direct = newDirect;
    }
    else if((direct == Left && newDirect != Right) || (direct == Right && newDirect != Left))
    {
        preDirect = direct;
        direct = newDirect;
    }
}

void snake::eraseTail()
{
    snakeCell.erase(snakeCell.begin());
}

void snake::snakeMove()
{
    switch(direct)
    {
    case Up:
        if(preDirect != Down) 
        {
            snakePart.y -= SNAKE_SPEED; 
            snakeCell.push_back(snakePart);
            if(!grow) eraseTail();
            else grow = false;
            if(snakePart.y < LIMIT_UP) isDead = true;//snakePart.y += SNAKE_SPEED;
        }
        break;
    case Down:
        if(preDirect != Up)
        {
            snakePart.y += SNAKE_SPEED;
            snakeCell.push_back(snakePart);
            if(!grow) eraseTail();
            else grow = false;
            if(snakePart.y > SCREEN_HEIGHT - LIMIT_DOWN - SNAKE_CELL) isDead = true;//snakePart.y -= SNAKE_SPEED;
        }
        break;
    case Left:
        if(preDirect != Right)
        {
            snakePart.x -= SNAKE_SPEED;
            snakeCell.push_back(snakePart);
            if(!grow) eraseTail();
            else grow = false;
            if(snakePart.x < LIMIT_LEFT) isDead = true;//snakePart.x += SNAKE_SPEED;
        }
        break;
    case Right:
        if(preDirect != Left)
        {
            snakePart.x += SNAKE_SPEED;
            snakeCell.push_back(snakePart);
            if(!grow) eraseTail();
            else grow = false;
            if(snakePart.x > SCREEN_WIDTH - LIMIT_RIGHT - SNAKE_CELL) isDead = true;//snakePart.x -= SNAKE_SPEED;
        }
        break;
    case None:
        break;
    }
}

void snake::grownUp()
{
    grow = true;
}

bool snake::dead()
{
    return isDead;
}

vector<SDL_Rect> snake::getCell()
{
    return snakeCell;
}

int snake::getPosX()
{
    return snakePart.x;
}

int snake::getPosY()
{
    return snakePart.y;
}
