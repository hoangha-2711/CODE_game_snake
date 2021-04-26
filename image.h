#ifndef IMAGE_H_
#define IMAGE_H_
#include "BaseInfo.h"
#include "texture_manage.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include  <SDL_ttf.h>
struct image
{
    //Constructor
    image();
    //Destructor
    ~image();

    void init(SDL_Renderer* _renderer);
    void render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX = 0, const int& rectY = 0, const int& reW = 0, const int& reH = 0, SDL_Rect* clip = NULL);
    void load();
    void draw_snake(const vector<SDL_Rect>& snakeCell);
    void draw_fruit(const int& posX, const int& posY);
    void free();

    SDL_Renderer* renderer;
    SDL_Texture* texture_snake;
    SDL_Texture* texture_fruit;
    //SDL_Rect snake_sprite;

};

#endif // IMAGE_H_
