#include "font_manage.h"
#include <SDL_ttf.h>

SDL_Texture* loadFont(SDL_Renderer* renderer, TTF_Font* font, string text )
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), {255, 255, 255});
    if(textSurface == NULL)
    {
        cout << "Unable to load font! SDL_ttf Error: " << TTF_GetError() << "\n";
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if(newTexture == NULL)
        {
            cout << "Unable to create texture from! SDL Error: " << SDL_GetError() << "\n";
        }
        SDL_FreeSurface(textSurface);
    }
    return newTexture;
}

