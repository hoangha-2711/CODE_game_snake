#ifndef SOURCES_H_
#define SOURCES_H_
#include<SDL.h>
#include<string>
#include "game.h"
struct sources
{
    // Constructor
    sources();
    // Destructor
    ~sources();
    void init(int w, int h, std::string _title);
    bool isRunning();
    void handleEvent();
    void loop();
    void render();

    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    game* Game;
};
#endif // SOURCES_H_

