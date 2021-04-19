#ifndef SNAKE_H_
#define SNAKE_H_
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

struct snake
{
    //constructor
    snake();
    //destructor
    ~snake();
    point.body[500];
    int fruits_count;
    void init(int x, int y, SDL_Renderer* _renderer);
    void loop();
    void render();
    void dead();
    SDL_Renderer* renderer;
    int cur_length;
    SDL_Texture* texture;
};

#endif // SNAKE_H_
