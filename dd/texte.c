#include <SDL/SDL.h>

#include "text.h"

#include <SDL/SDL_image.h>



void CreateText(Text *A, char font_name[],int fontsize, int posx, int posy, int colorR, int colorG, int colorB)
{
	A->position.x= posx;
	A->position.y= posy;
	A->textColor.r= colorR;
	A->textColor.g= colorG;
	A->textColor.b= colorB;
	A->font =TTF_OpenFont(font_name, fontsize);
}

void ClearText(Text A)
{
	SDL_FreeSurface(A.surfaceTexte);
}

void displayText(Text t,SDL_Surface *screen, char input[])
{
	t.surfaceTexte = TTF_RenderText_Solid(t.font, input, t.textColor );
	SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position);
}

void SwapTxtColors(Text * bts, int r, int g, int b)
{
  (*bts).textColor.r = r; 
  (*bts).textColor.g = g;
  (*bts).textColor.b = b;  	
}

