#ifndef GAME_H_
#define GAME_H_

#include "BaseInfo.h"
#include "background.h"
#include "image.h"
#include "snake.h"
#include "fruits.h"
#include "score.h"
#include "sound.h"
#include "highscore.h"
#include <SDL_mixer.h>
struct game
{
    // Constructor
    game();
    //Destructor
    ~game();
    void init(SDL_Renderer* renderer); 
    void handleKeyPress(int key_code);
    void loop(bool& running);
    void render(SDL_Renderer* renderer);



    background gameBackground;
    image snakeImage; 
    image fruitImage; 

    snake player; 
    fruits score; 
    scoreGame point; 
    scoreGame bestPoint; 
    int countFruit = 0;
    int maxFruit = ReadFile();
    gameSound voice;
};



#endif // GAME_H_
