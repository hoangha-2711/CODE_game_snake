#include "sources.h"
#include "menu.h"

const std::string WINDOW_TITLE = "SDL Game";

int main(int argc, char* argv[])
{
    srand(time(NULL));// khởi tạo hạt giống ngẫu nhiên để rand chuẩn
    sources* Gamesources;// game chính
    Gamesources = new sources();// cấp phát động

    Gamesources -> init(SCREEN_WIDTH
                  ,SCREEN_HEIGHT
                  ,WINDOW_TITLE);// khởi tạo game

    menu menuSource;
    menuSource.init(Gamesources->renderer);
    while(menuSource.isRunning())
    {
        if(!menuSource.isLoaded())
        {
            menuSource.setLoad(true);
            menuSource.displayImage();
            menuSource.writeText("<< Fast space snake >>", 120, 250);
            menuSource.writeText("*Press Enter to play", 150, 500);
            menuSource.writeText("*Q to Quit", 350, 650);
        }
        menuSource.handleKeyPresses();
        if(menuSource.playGame())
        {
            while(Gamesources->isRunning())
            {
                Gamesources->handleEvent();
                
                Gamesources->loop();

                Gamesources->render();
            }
            menuSource.reset();
            Gamesources->reset();
        }
        else if(menuSource.quitGame()) break;
    }

    delete Gamesources;
    Gamesources = NULL;
    return 0;
}
