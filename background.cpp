#include "background.h"
#include <iostream>
#include <string>

background::background()
{
    background_game = NULL;
    wall = NULL;
}
background::~background()
{
    background_game = NULL;
    wall = NULL;
}
void background::init(SDL_Renderer* _renderer)
{
    renderer = _renderer;
}
void background::render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX, const int& rectY, const int& reW, const int& reH, SDL_Rect* clip)
{
    SDL_Rect renderQuad = {rectX, rectY, reW, reH};
    SDL_RenderCopy(des, texture , clip, &renderQuad);
}
void background::load()
{
    background_game = loadTexture(renderer, background_game, "background_black.png");
    wall = loadTexture(renderer, wall,+ "block_square.png");
}
void background::display()
{
    render(renderer, background_game, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Load wall up and down
    for(int x = 0; x <= SCREEN_WIDTH; x += WALL_CELL)
    {
        render(renderer, wall, x, 0, WALL_CELL, WALL_CELL);
        render(renderer, wall, x, SCREEN_HEIGHT - WALL_CELL, WALL_CELL, WALL_CELL);
    }
    // Load wall left and right
    for(int y = 0; y <= SCREEN_HEIGHT; y += WALL_CELL)
    {
        render(renderer, wall, 0, y, WALL_CELL, WALL_CELL);
        render(renderer, wall, SCREEN_WIDTH - WALL_CELL, y, WALL_CELL, WALL_CELL);
    }
}
void background::free()
{
    SDL_DestroyTexture(background_game);
    background_game = NULL;
    SDL_DestroyTexture(wall);
    wall = NULL;
}
