#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "BaseInfo.h"
#include "texture_manage.h"
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

struct background
{
    //Constructor
    background();
    //Destructor
    ~background();

    void init(SDL_Renderer* _renderer);
    void render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX = 0, const int& rectY = 0, const int& reW = 0, const int& reH = 0, SDL_Rect* clip = NULL);
    void load();
    void display();
    void free();

    SDL_Renderer *renderer;
    SDL_Texture *background_game;
    SDL_Texture *wall;
};

#endif // BACKGROUND_H_
