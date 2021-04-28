#ifndef SCORE_H_
#define SCORE_H_
#include "BaseInfo.h"
#include "font_manage.h"
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

struct scoreGame
{
    //Constructor
    scoreGame();
    //Destructor
    ~scoreGame();

    void init(SDL_Renderer* _renderer);
    void render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX = 0, const int& rectY = 0, const int& width = 0, const int& height = 0, SDL_Rect* clip = NULL);
    void load();
    void writeText(const string& content, const int& text, const int& posX, const int& posY);
    void free();

    TTF_Font* fontScore; 
    SDL_Renderer* renderer;
    SDL_Texture* point; 
};



#endif // SCORE_H_
