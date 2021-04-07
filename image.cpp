#include "image.h"
#include <iostream>
#include <string>

image::image()
{
    texture_snake = NULL;
    texture_fruits = NULL;
    return;
}

image::~image()
{
    texture_snake = NULL;
    texture_fruits = NULL;
    return;
}

void image::init(SDL_Renderer* _renderer)
{
    renderer = _renderer;
    return;
}

void image::Load()
{
    texture_snake = loadFromFIle(renderer,"body_snake.png");
    texture_fruits = loadFromFIle(renderer,"small_fruits.png");

    return;
}

void image::draw_snake(SDL_Rect dest)
{
    SDL_RenderCopy(renderer, texture_snake, NULL, &dest);
    return;
}

void image::draw_fruits(SDL_Rect dest)
{
    SDL_RenderCopy(renderer, texture_fruits, NULL, &dest);
    return;
}

SDL_Texture* loadFromFIle(SDL_Renderer* renderer, std::string path)
{
    SDL_Texture* tmpTexture = NULL;
    SDL_Surface* tmpSurface = IMG_Load(path.c_str());
    if (tmpSurface == NULL)
    {
        std::cout << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError();
        return tmpTexture;
    }

    tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    if (tmpTexture == NULL)
    {
        std::cout << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError();
        return tmpTexture;
    }

    //cout << done!
    return tmpTexture;
}

void image::free()
{
    SDL_DestroyTexture (texture_snake);
    texture_snake = NULL;
    SDL_DestroyTexture (texture_fruits);
    texture_fruits = NULL;

}
