#include "sources.h"

const std::string WINDOW_TITLE = "SDL Game";

int main(int argc, char* argv[])
{
    srand(time(NULL));
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
