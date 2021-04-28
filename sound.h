#ifndef SOUND_H_
#define SOUND_H_
#include <bits/stdc++.h>
#include <SDL_mixer.h>
struct gameSound
{
    Mix_Chunk* sound;
    Mix_Music* music;

    //constructor
    gameSound();
    //destructor
    ~gameSound();
    void load();
    void playMusic();
    void playChunk();
    void freeSound();
};


#endif // SOUND_H_
