#include "sources.h"
#include <iostream>

sources::sources()
{
    std::cout << "CONSTRUCTOR INIT...\n";
    window = NULL;
    renderer = NULL;
    running = false;
    Game = NULL;
    Image = new image; // cấp phát động

}

sources::~sources()
{
    std::cout << "DESTRUCTOR INIT...\n";
    if( renderer != NULL)
    {

        SDL_DestroyRenderer(renderer); // hủy bút vẽ
        renderer = NULL;

    }

    if( window != NULL)
    {

        SDL_DestroyWindow(window);// hủy cửa sổ
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
    if(TTF_Init() < 0)
    {
        std::cout  << "TTF could not initialize! SDL_Error: " << TTF_GetError();
        running = false;
        return;
    }

    window = SDL_CreateWindow(_title.c_str(),
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,  // khởi tạo cửa sổ
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

    Game->init(renderer); // con trỏ, chạy khởi tạo
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
            Game->handleKeyPress(event.key.keysym.sym); // xử lý phím bấm
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

