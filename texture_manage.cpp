#include "texture_manage.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

SDL_Texture* loadTexture(SDL_Renderer* renderer, SDL_Texture* texture, string path)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << "\n";
    }
    else
    {
        //Create texture from surface pixels
        SDL_DestroyTexture(texture);
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (texture == NULL)
        {
            cout << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError() << "\n";
        }

        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}
