#include "fruits.h"

fruits::fruits()
{
    x = 0, y = 0, numFruit = 0;
}
fruits::~fruits()
{

}
void fruits::spawnFruit()
{
    if(countFruit() < MAX_FRUIT)
    {
        x = rand() % SCREEN_WIDTH;
        y = rand() % SCREEN_HEIGHT;
        if(x < 2 * LIMIT_LEFT) x = 2 * LIMIT_LEFT;
        if(x > SCREEN_WIDTH - 2 * LIMIT_RIGHT - FRUIT_CELL) x = SCREEN_WIDTH - 2 * LIMIT_RIGHT - FRUIT_CELL;
        if(y < 2 * LIMIT_UP) y = 2 * LIMIT_UP;
        if(y > SCREEN_HEIGHT - 2 * LIMIT_DOWN - FRUIT_CELL) y = SCREEN_HEIGHT - 2 * LIMIT_DOWN - FRUIT_CELL;
        numFruit++;
    }
}
int fruits::countFruit()
{
    return numFruit;
}
void fruits::decreaseFruit()
{
    numFruit--;
}
int fruits::getPosX()
{
    return x;
}
int fruits::getPosY()
{
    return y;
}

