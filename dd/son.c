#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "son.h"


void LoadMenuMusic(Mix_Music *music)
{
	music = Mix_LoadMUS("bg.mp3"); 
	Mix_PlayMusic(music, -1);
	Mix_VolumeMusic(10);
}

void LoadOnclickMenuMusic(Mix_Music *son)
{
	son = Mix_LoadMUS("button_click.mp3"); 
	Mix_PlayMusic(son, 0);
}
