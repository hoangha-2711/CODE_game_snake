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
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // clear cả màn -> màu trắng
    SDL_RenderClear(renderer);

    gameBackground.init(renderer);
    gameBackground.load();
    snakeImage.init(renderer);
    snakeImage.load();
    fruitImage.init(renderer);
    fruitImage.load();
    point.init(renderer);
    point.load();
    bestPoint.init(renderer);
    bestPoint.load();
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
    player.snakeMove();// di chuyển rắn
    score.spawnFruit();// sinh ngẫu nhiên fruit
    SDL_Rect playerRect = {player.getPosX(), player.getPosY(), SNAKE_CELL, SNAKE_CELL}; // lấy vị trí đầu rắn
    SDL_Rect scoreRect = {score.getPosX(), score.getPosY(), FRUIT_CELL, FRUIT_CELL};// lấy vị trí fruit
    if(Collision(playerRect, scoreRect)) // nếu con rắn va chạm với fruit
    {
        score.decreaseFruit(); // giảm số fruit
        player.grownUp();// con rắn to thêm
        countFruit++; // điểm
        if(countFruit > maxFruit) //nếu điểm lớn hơn điểm cao
        {
            //cập nhật điểm cao
            SDL_RWops* file = SDL_RWFromFile("highscore.bin", "w+b");
            maxFruit = countFruit;
            SDL_RWwrite(file, &maxFruit, sizeof(Sint32), 1);
            SDL_RWclose(file);
        }
    }
    if(player.dead()) running = false;
}

void game::render(SDL_Renderer* renderer)
{
    gameBackground.display();// hiển thị background

    snakeImage.draw_snake(player.getCell()); // hiển thị rắn
    if(score.countFruit() > 0) fruitImage.draw_fruit(score.getPosX(), score.getPosY());// nếu có fruit thì hiển thi fruit

    point.writeText("Score:", countFruit, WALL_CELL, WALL_CELL);
    bestPoint.writeText("Highscore:", maxFruit, 10 * WALL_CELL, WALL_CELL);

    SDL_RenderPresent(renderer);
}
