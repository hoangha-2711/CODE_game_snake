#include "score.h"

scoreGame::scoreGame()
{
    point = NULL;
    return;
}

scoreGame::~scoreGame()
{
    point = NULL;
    return;
}

void scoreGame::init(SDL_Renderer* _renderer) 
{
    renderer = _renderer;
}
void scoreGame::render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX, const int& rectY, const int& width, const int& height, SDL_Rect* clip)
{
    SDL_Rect renderQuad = {rectX, rectY, width, height};
    SDL_RenderCopy(des, texture, clip, &renderQuad);
}
void scoreGame::load()
{
    fontScore = TTF_OpenFont("fontt.ttf", 20);
}
void scoreGame::writeText(const string& content, const int& score, const int& posX, const int& posY)
{
    string text = content; // gán nội dung
    text = text + to_string(score);
    point = loadFont(renderer, fontScore, text);
    SDL_Point sizeFont;
    SDL_QueryTexture(point, NULL, NULL, &sizeFont.x, &sizeFont.y);
    render(renderer, point, posX, posY, sizeFont.x, sizeFont.y);
}
void scoreGame::free()
{
    SDL_DestroyTexture(point);
    point = NULL;
}
