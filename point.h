#ifndef POINT_H_
#define POINT_H_
#include <bits/stdc++.h>
#include <SDL.h>

struct point
{
    // Constructor
    point(int _x,int _y);
    ~point();

    int x,y;
};

point snake_pos;
snake_pos.x
snake_pos.y
snake_pos = point(1, 2);

#endif // POINT_H_
