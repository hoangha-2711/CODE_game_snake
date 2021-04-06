#include "sources.h"



const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const std::string WINDOW_TITLE = "SDL Game";

int main(int argc, char* argv[])
{
    sources* Gamesources;
    Gamesources = new sources();

    Gamesources -> init(SCREEN_WIDTH
                  ,SCREEN_HEIGHT
                  ,WINDOW_TITLE);

    while (Gamesources->isRunning())
    {
        Gamesources->handleEvent();

        Gamesources->loop();

        Gamesources->render();
    }

    delete Gamesources;
    Gamesources = NULL;
    return 0;
}
