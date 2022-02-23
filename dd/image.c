#include <SDL/SDL.h>

#include "Image.h"

#include <SDL/SDL_image.h>


/*
void CreatePlayer(Image *A)
{
   A->img = IMG_Load("aymen.jpeg");
   if (A->img== NULL) 
   {
     return;
   }
   A->pos1.x=0;
   A->pos1.y=0;
   A->pos1.w=0;
   A->pos1.h=A->img->h;

   A->pos2.x=193;
   A->pos2.y=0;
   A->pos2.w=100;
   A->pos2.h=A->img->h;
}*/

// CreateButton: Creation d'un button 
void CreateButton(Image *b,char image_name_file[], int pos1_x,int pos1_y,int pos2_x,int pos2_y,int pos2_w,int pos2_h)
{
  b->img = NULL; 
  b->img = IMG_Load(image_name_file); 
  if(b->img == NULL)
  {
	printf("Unable to load the Button: %s\n", SDL_GetError());
        return; 
  } 
	b->pos1.x= pos1_x;
	b->pos1.y= pos1_y;
	b->pos2.x= pos2_x;
	b->pos2.y= pos2_y;
	b->pos2.w= pos2_w;
	b->pos2.h= pos2_h;     
}

void CreateBackground(Image *Backg)
{

  Backg->img=NULL;
  //IF the background is BMP use : SDL_LoadBMP(image_name_file); Instead of
 Backg->img=IMG_Load("menu.png"); 
 // Backg->img= SDL_LoadBMP("bg.bmp");//IMG_Load("bg.png");
  if (Backg->img == NULL)
  {
     printf("Unable to load BackGround: %s\n", SDL_GetError());
     return;
  }

	Backg->pos1.x=0;
	Backg->pos1.y=0;
	Backg->pos2.x=0;
	Backg->pos2.y=0;
	Backg->pos2.w= SCREEN_W;
	Backg->pos2.h= SCREEN_H;
}


void ClearSurface(Image A)
{
	SDL_FreeSurface(A.img);
}
void ClearButtonsSurfaces(Image B1, Image B2, Image B3)
{
	SDL_FreeSurface(B1.img); 
	SDL_FreeSurface(B2.img);
	SDL_FreeSurface(B3.img);
}
void ShowImage(Image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,NULL,screen,&p.pos1);
}

/*
SDL_Surface* switchFullScreen(Uint32 flags){
	SDL_Surface *screen =SDL_GetVideoSurface();
	screen =SDL_SetVideoMode(0, 0, 0, flags);
	if (screen==NULL){
        	fprintf(stderr, "Err / switchFullScreen : changement de format impossible :%s\n",   SDL_GetError());
        	screen=SDL_SetVideoMode(0, 0, 0, flags^SDL_FULLSCREEN);
	}
	return(screen);
}*/	
