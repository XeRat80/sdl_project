#ifndef Texte_H

#define Texte_H

#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_ttf.h>

typedef struct {

	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char text [50];
} Text;



void CreateText(Text *A, char font_name[],int fontsize, int posx, int posy, int colorR, int colorG, int colorB);
void ClearText(Text A);
void displayText(Text t,SDL_Surface *screen, char input[]);
void SwapTxtColors(Text * x, int r, int g, int b);

#endif
