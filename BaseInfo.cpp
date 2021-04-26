#include "BaseInfo.h"
#include <iostream>
#include <string>

bool Collision(const SDL_Rect& object_1, const SDL_Rect& object_2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    leftA = object_1.x;
    rightA = object_1.x + object_1.w;
    topA = object_1.y;
    bottomA = object_1.y + object_1.h;
    leftB = object_2.x;
    rightB = object_2.x + object_2.w;
    topB = object_2.y;
    bottomB = object_2.y + object_2.h;
    if(bottomA <= topB) return false;
    if(bottomB <= topA) return false;
    if(rightA <= leftB) return false;
    if(rightB <= leftA) return false;
    return true;
}
