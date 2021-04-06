#ifndef GAME_H_
#define GAME_H_

struct game
{
    // Constructor
    game();
    //Destructor
    ~game();
    void handleKeyPress(int key_code);
    void loop();
    void render();


};



#endif // GAME_H_
