#include "menu.h"

menu::menu()
{
    texture_menu = NULL;
    running = true;
    play = false;
    quit = false;
    loading = false;
}
menu::~menu()
{

}
void menu::init(SDL_Renderer* _renderer)
{
    renderer = _renderer;
    loadMenuImage();
    loadMenuFont();
}
void menu::render(SDL_Renderer* des, SDL_Texture* texture, const int& rectX, const int& rectY, const int& width, const int& height, SDL_Rect* clip)
{
    SDL_Rect renderQuad = {rectX, rectY, width, height};
    SDL_RenderCopy(des, texture, clip, &renderQuad);
}
void menu::loadMenuImage()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    texture_menu = loadTexture(renderer, texture_menu, "menu.png");
}
void menu::loadMenuFont()
{
    menuFont = TTF_OpenFont("menu fontt.ttf", 50);
}
void menu::handleKeyPresses()
{
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0)
    {
        if(event.type == SDL_QUIT) running = false;
        else if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_RETURN:
                play = true;
                break;
            case SDLK_q:
                quit = true;
                break;
            }
        }
    }
}
void menu::reset()
{
    play = false;
    quit = false;
    loading = false;
}
void menu::displayImage()
{
    render(renderer, texture_menu, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);
}
void menu::writeText(const string& content, const int& posX, const int& posY)
{
    name = loadFont(renderer, name, menuFont, content);
    SDL_Point sizeFont;
    SDL_QueryTexture(name, NULL, NULL, &sizeFont.x, &sizeFont.y);
    render(renderer, name, posX, posY, sizeFont.x, sizeFont.y);
    SDL_RenderPresent(renderer);
}
bool menu::isRunning()
{
    return running;
}
void menu::setLoad(const bool& state)
{
    loading = state;
}
bool menu::isLoaded()
{
    return loading;
}
bool menu::playGame()
{
    return play;
}
bool menu::quitGame()
{
    return quit;
}
