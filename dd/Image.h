#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1920
#define SCREEN_H 1080
struct Image{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface * img;
};

typedef struct Image Image;
SDL_Surface* switchFullScreen(Uint32 flags) ;
void CreatePlayer(Image *A);
void CreateBackground(Image *Backg);
void ClearSurface(Image A);
void ShowImage(Image p,SDL_Surface *screen);
void CreateButton(Image *b,char image_name_file[], int pos1_x,int pos1_y,int pos2_x,int pos2_y,int pos2_w,int pos2_h);
void ClearButtonsSurfaces(Image B1, Image B2, Image B3);

#endif
