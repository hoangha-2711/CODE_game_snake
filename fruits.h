#ifndef FRUITS_H_
#define FRUITS_H_
#include "BaseInfo.h"
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

const int MAX_FRUIT = 1;

class fruits
{
public:
    //constructor
    fruits();
    //destructor
    ~fruits();
    void spawnFruit();
    int countFruit();
    void decreaseFruit();
    int getPosX();
    int getPosY();
private:
    int x, y, numFruit;
};

#endif // FRUITS_H_
