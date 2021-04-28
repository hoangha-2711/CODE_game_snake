#ifndef GAME_H_
#define GAME_H_

#include "BaseInfo.h"
#include "background.h"
#include "image.h"
#include "snake.h"
#include "fruits.h"
#include "score.h"
#include "highscore.h"

struct game
{
    // Constructor
    game();
    //Destructor
    ~game();
    void init(SDL_Renderer* renderer); //Khởi tạo các thành phần game : hình ảnh, font chữ
    void handleKeyPress(int key_code);
    void loop(bool& running);
    void render(SDL_Renderer* renderer);

    background gameBackground;
    image snakeImage; // quản lý hình ảnh rắn
    image fruitImage; // quản lý hình ảnh fruit

    snake player; // lớp rắn
    fruits score; // lớp fruit
    scoreGame point; // font hiển thị điểm
    scoreGame bestPoint; // font hiển thị điểm cao
    int countFruit = 0;
    int maxFruit = ReadFile();
    gameSound voice;
};



#endif // GAME_H_
