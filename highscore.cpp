#include "highscore.h"

int ReadFile()
{
    int highscore = 0;
    SDL_RWops* file = SDL_RWFromFile("highscore.bin", "r+b");// mở file
    if(file == NULL)// nếu file chưa có , tạo file mới
    {
        file = SDL_RWFromFile("highscore.bin", "w+b");// tạo file
        if(file != NULL)
        {
            highscore = 0;
            SDL_RWwrite(file, &highscore, sizeof(Sint32), 1);
            SDL_RWclose(file);
        }
    }
    else// nếu file đã có, đọc file
    {
        SDL_RWread(file, &highscore, sizeof(Sint32), 1);
        SDL_RWclose(file);
    }
    return highscore;
}
