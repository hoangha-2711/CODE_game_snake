#include "highscore.h"

int ReadFile()
{
    int highscore = 0;
    SDL_RWops* file = SDL_RWFromFile("highscore.bin", "r+b");
    if(file == NULL)
    {
        file = SDL_RWFromFile("highscore.bin", "w+b");
        if(file != NULL)
        {
            highscore = 0;
            SDL_RWwrite(file, &highscore, sizeof(Sint32), 1);
            SDL_RWclose(file);
        }
    }
    else
    {
        SDL_RWread(file, &highscore, sizeof(Sint32), 1);
        SDL_RWclose(file);
    }
    return highscore;
}
