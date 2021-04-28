#include "sound.h"

gameSound::gameSound()
{

}

gameSound::~gameSound()
{

}

void gameSound::load()
{
    music = Mix_LoadMUS("sound.mp3");
    sound = Mix_LoadWAV("eat.wav");
}
void gameSound::playMusic()
{
    Mix_PlayMusic(music,-1);
}
void gameSound::playChunk()
{
    Mix_PlayChannel(-1,sound,0);
}
void gameSound::freeSound()
{
    Mix_FreeChunk(sound);
    Mix_FreeMusic(music);
}
