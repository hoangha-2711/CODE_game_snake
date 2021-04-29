#ifndef FONT_MANAGE_H_
#define FONT_MANAGE_H_
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;

SDL_Texture* loadFont(SDL_Renderer* renderer, SDL_Texture* texture, TTF_Font* font, string text);

#endif // FONT_MANAGE_H_


