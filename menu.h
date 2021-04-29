#ifndef MENU_H_
#define MENU_H_
#include "BaseInfo.h"
#include "texture_manage.h"
#include "font_manage.h"
#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>

using namespace std;

struct menu
{
    menu();
    ~menu();
    void init(SDL_Renderer* _renderer);
    void loadMenuImage();
    void loadMenuFont();
    void handleKeyPresses();
    void reset();
    void render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX, const int& rectY, const int& width, const int& height, SDL_Rect* clip = NULL);
    void displayImage();
    void writeText(const string& content, const int& posX, const int& posY);
    bool isRunning();
    void setLoad(const bool& state);
    bool isLoaded();
    bool playGame();
    bool quitGame();

    SDL_Renderer* renderer;
    SDL_Texture* texture_menu;
    SDL_Texture* name;
    TTF_Font* menuFont;
    bool running, play, quit, loading;
};

#endif // MENU_H_
