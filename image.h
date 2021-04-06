#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL.h>
#include <SDL_image.h>

struct image
{
    //Constructor
    image();
    //Destructor
    ~image();

    void init(SDL_Renderer* _renderer);
    void Load();
    void draw_snake(SDL_Rect dest);
    void draw_fruits(SDL_Rect dest);
    void free();

    SDL_Renderer* renderer;
    SDL_Texture* texture_snake;
    SDL_Texture* texture_fruits;
    //SDL_Rect snake_sprite;

};

SDL_Texture* loadFromFIle(std::string path);

#endif // IMAGE_H_

