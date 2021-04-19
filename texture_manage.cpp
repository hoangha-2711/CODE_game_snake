#include "texture_manage.h"
#include <SDL.h>
#include <SDL_image.h>

SDL_Texture* loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        std::cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError();
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            std::cout << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError();
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}
