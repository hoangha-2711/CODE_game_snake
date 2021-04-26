#include "game.h"
#include <iostream>

game::game()
{

}

game::~game()
{

}

void game::init(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    gameBackground.init(renderer);
    gameBackground.load();
    snakeImage.init(renderer);
    snakeImage.load();
    fruitImage.init(renderer);
    fruitImage.load();
}

void game::handleKeyPress(int key_code)
{
    switch(key_code)
    {
        case SDLK_UP:
            player.setDirection(Up);
            break;
        case SDLK_DOWN:
            player.setDirection(Down);
            break;
        case SDLK_LEFT:
            player.setDirection(Left);
            break;
        case SDLK_RIGHT:
            player.setDirection(Right);
            break;
    }
    player.snakeMove();
}
void game::loop(bool& running)
{
    SDL_Delay(GAME_DELAY);
    player.snakeMove();
    score.spawnFruit();
    SDL_Rect playerRect = {player.getPosX(), player.getPosY(), SNAKE_CELL, SNAKE_CELL};
    SDL_Rect scoreRect = {score.getPosX(), score.getPosY(), FRUIT_CELL, FRUIT_CELL};
    if(Collision(playerRect, scoreRect))
    {
        score.decreaseFruit();
        player.grownUp();
    }
    if(player.dead()) running = false;
}

void game::render(SDL_Renderer* renderer)
{
    gameBackground.display();

    snakeImage.draw_snake(player.getCell());
    if(score.countFruit() > 0) fruitImage.draw_fruit(score.getPosX(), score.getPosY());

    SDL_RenderPresent(renderer);
}
