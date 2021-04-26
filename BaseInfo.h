#ifndef BASE_INFO_H_
#define BASE_INFO_H_
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int LIMIT_UP = 45;
const int LIMIT_DOWN = 45;
const int LIMIT_LEFT = 45;
const int LIMIT_RIGHT = 45;
const int SNAKE_CELL = 40;
const int FRUIT_CELL = 20;

const int GAME_DELAY = 15;

bool Collision(const SDL_Rect& object_1, const SDL_Rect& object_2);

#endif // BASE_INFO_H_
