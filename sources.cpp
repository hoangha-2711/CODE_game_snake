#include "sources.h"
#include <iostream>

sources::sources()
{
    std::cout << "CONSTRUCTOR INIT...\n";
    window = NULL;
    renderer = NULL;
    running = false;
    Game = NULL;
    Image = new image;

}

sources::~sources()
{
    std::cout << "DESTRUCTOR INIT...\n";
    if( renderer != NULL)
    {

        SDL_DestroyRenderer(renderer);
        renderer = NULL;

    }

    if( window != NULL)
    {

        SDL_DestroyWindow(window);
        window = NULL;

    }

    delete Game;
    Game = NULL;

    delete Image;
    Image = NULL;
}

void sources::init(int width , int height, std::string _title)
{
    running = true;
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout  << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        running = false;
        return;
    }

    window = SDL_CreateWindow(_title.c_str(),
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                width,
                                height,
                                SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
          std::cout << "Window could not be created! SDL_Error: " << SDL_GetError();
          running = false;
          return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Game = new game();

    Game->init(renderer);
}


void sources::handleEvent()
{
    SDL_Event event;
    while( SDL_PollEvent( &event ) != 0)
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }

        if(event.type == SDL_KEYDOWN)
        {
            Game->handleKeyPress(event.key.keysym.sym);
        }
    }

}

bool sources::isRunning()
{
    return running;
}

void sources::loop()
{
    Game->loop(running);
}

void sources::render()
{
    Game->render(renderer);
}

