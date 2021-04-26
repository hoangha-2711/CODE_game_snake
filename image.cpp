#include "image.h"
#include <iostream>
#include <string>

image::image()
{
    texture_snake = NULL;
    return;
}

image::~image()
{
    texture_snake = NULL;
    return;
}

void image::init(SDL_Renderer* _renderer)
{
    renderer = _renderer;
}

void image::render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX, const int& rectY, const int& reW, const int& reH, SDL_Rect* clip)
{
    SDL_Rect renderQuad = {rectX, rectY, reW, reH};
    SDL_RenderCopy(des, texture , clip, &renderQuad);
}

void image::load()
{
    texture_snake = loadTexture(renderer, "body_snake.png");
    texture_fruit = loadTexture(renderer, "fruit.png");
}

void image::draw_snake(const vector<SDL_Rect>& snakeCell)
{
    int numberCell = snakeCell.size();
    for(int i = 0; i < numberCell; i++) render(renderer, texture_snake, snakeCell[i].x, snakeCell[i].y, SNAKE_CELL, SNAKE_CELL);
}

void image::draw_fruit(const int& posX, const int& posY)
{
    render(renderer, texture_fruit, posX, posY, FRUIT_CELL, FRUIT_CELL);
}

void image::free()
{
    SDL_DestroyTexture (texture_snake);
    texture_snake = NULL;
    SDL_DestroyTexture (texture_fruit);
    texture_fruit = NULL;
}
