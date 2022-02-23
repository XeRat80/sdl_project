#include "text.h"
#include "Image.h"
//#include "menu.h"
#include "son.h"

int main ()
{
   int c=0;

  TTF_Init(); //INITIALISATION DE TTF COMMENT IN CASE IF U ARE NOT USING A TEXT AND COMMENT THE #INCLUDE "text.h"
  
  SDL_Event event;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen;
  Image Backg,startg,option,credit,exit,testst,testop,testcr,testex,opbutton,exop;
 Text info;
  int game_in_progress = 0;
  
  atexit(SDL_Quit);
  screen =SDL_SetVideoMode(0,0,0,SDL_HWSURFACE | SDL_SRCALPHA | SDL_RESIZABLE); // YOU CAN CHANGE SCREENW AND SCREENH FROM IMAGE.H


  if(!screen)
  {

    printf("unable to set %d x %d video: %s\n",SCREEN_W,SCREEN_H,SDL_GetError());
    return 1;
  }



//ADDING MUSIC - INCLUDE SON.H et AJOUTER -lSDL_mixer AU TEMPS DE COMPILATION

  Mix_Music *music;
  //Mix_Chunck *Click_sound;

  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) == -1)
  {
	printf("Failed to load the Music Chanel: %s\n",SDL_GetError()); 
  }
  
 	//son = Mix_LoadWAV("22.wav"); Load the Chunk Music( WAV )
	//Mix_PlayChannel(-1,son, 0); Jouer le son WAV

	music = Mix_LoadMUS("sound1.mp3"); //Load the music
	Mix_PlayMusic(music, -1); // Jouer le son
	Mix_VolumeMusic(10); // Pour adjuster le volume 0 = Mute // 128 MAX VOLUME




  CreateBackground(&Backg);
  CreateButton(&startg,"start.png",240 ,220 , 200, 200 , 500,600); // start game
  CreateButton(&option,"set.png", 240, 344, 250, 200 , 200,300); // option
  CreateButton(&credit,"load.png", 240, 456, 250, 200 , 200,300); //credit
  CreateButton(&exit,"ext.png", 240, 585, 250,200 , 200,300); //exit
  CreateButton(&testst,"startS.png", 240 ,220 , 200,200 , 200,300);
  CreateButton(&testop,"ss.png", 240, 344, 250,200 , 200,300);
  CreateButton(&testcr,"loadS.png", 240, 456, 250,200, 200,300);
  CreateButton(&testex,"exitS.png", 240, 585, 250,200 , 200,300);

 //****************option*******************//
  CreateButton(&opbutton,"opbutton.png", 540, 180, 250,200 , 200,300);
  CreateButton(&exop,"exop.png", 540, 180, 250,200 , 200,300);

int e=1 ; 

  CreateText(&info, "Soccer Jersey.ttf",20, 0, 0, 0, 0,0);
    ShowImage(Backg, screen); // Pastes the Background
     ShowImage(startg, screen); // Pastes the Image
     ShowImage(option, screen); // Pastes the Image
     ShowImage(credit, screen); // Pastes the Image
     ShowImage(exit, screen); // Pastes the Image
 displayText(info,screen,"created by 'Carthage Gladiators' "); //PASTES THE TEXT
     SDL_Flip(screen); // Flips the screen to show everything
  while(!game_in_progress)
  {  
    
    
     SDL_PollEvent(&event);
    while (SDL_PollEvent(&event)) 
     {
     switch(event.type)
     {
	 case SDL_QUIT:
	 {
	    game_in_progress = 1;
	    break;
	 }
	/* case SDL_MOUSEBUTTONDOWN: //FLAG
	 {
		
		
		
	    break;
	 }*/
	 case SDL_MOUSEMOTION...SDL_MOUSEBUTTONDOWN: // FLAG
	 {
	   printf("x: %d, y:%d \n, e=%d\n",event.motion.x,event.motion.y,e);
	   if(event.motion.x >= 240 && event.motion.y >=220 && event.motion.x <= 445  && event.motion.y <= 256)
	   {    if(e==1) {
                printf("im in\n") ; 
                printf("im in\n") ;
		ShowImage(testst, screen);
		SDL_Flip(screen);
		 }
	   }
	else if(event.motion.x >= 240 && event.motion.y >= 340 && event.motion.x <= 394 && event.motion.y <= 376)
	   {   
 		if (e==1)
		 {
                printf("option run") ; 
		ShowImage(testop, screen); // Pastes the Image
		SDL_Flip(screen);
		 }
                if(event.button.button==SDL_BUTTON_LEFT) 
		{
 		e=0 ;
		printf("running correctly\n");									//e==0 : menu ma7loul / e==1 :menu msaker
		// option..
		ShowImage(opbutton,screen);
		ShowImage(exop, screen);
		SDL_Flip(screen);
		}
	    } 

         if(event.motion.x >= 540 && event.motion.y >= 180 && event.motion.x <= 608 && event.motion.y <= 210 && e==0)
            {  printf("m here\n" ) ;
		if(event.button.button==SDL_BUTTON_LEFT)
                {
		printf("test\n"); 
		ShowImage(Backg, screen); // Pastes the Background
    		ShowImage(startg, screen); // Pastes the Image
     		ShowImage(option, screen); // Pastes the Image
     		ShowImage(credit, screen); // Pastes the Image
     		ShowImage(exit, screen); // Pastes the Image
		displayText(info,screen,"created by 'Carthage Gladiators' ");
		SDL_Flip(screen) ; 
		e=1 ; 
		} 
 	    }
  	   

        else if(event.motion.x >= 240 && event.motion.y >= 457 && event.motion.x <= 440 && event.motion.y <= 499)
	   {
	        if (e==1) {
		ShowImage(testcr, screen); // Pastes the Image
     		//displayText(info,screen,"Printemps");
		SDL_Flip(screen); }


 		


 }

        else if(event.motion.x >= 240 && event.motion.y >= 589 && event.motion.x <= 309 && event.motion.y <= 615)
	   {   
		 ShowImage(testex, screen); // Pastes the Image
     		//displayText(info,screen,"Printemps");
		  SDL_Flip(screen); 
 		if(event.button.button==SDL_BUTTON_LEFT) { printf("exit game\n\n\n") ; game_in_progress=1 ;} 

 	    } 
	else 
	{ 
	   if (e==1) {
	ShowImage(startg, screen); // Pastes the Image
        ShowImage(option, screen); // Pastes the Image
        ShowImage(credit, screen); // Pastes the Image
        ShowImage(exit, screen); // Pastes the Image
        SDL_Flip(screen); 
}
        }




	   break;
	 }
	 case SDL_KEYDOWN: //FLAG
  	 {
	   switch(event.key.keysym.sym)
	   {
   	     case SDLK_o: // Down Arrow
	     {
                 e=0 ;
		printf("running correctly\n");			//e==0 : menu ma7loul  e==1 :menu msaker
		// option..
		ShowImage(opbutton,screen);
		ShowImage(exop, screen);
		SDL_Flip(screen);
		//WRITE HERE iF NEEDED
		break;
	     }
	     case SDLK_ESCAPE : 
                 {switch(e)
		   { case 1: {
                ShowImage(Backg, screen); // Pastes the Background
    		ShowImage(startg, screen); // Pastes the Image
     		ShowImage(option, screen); // Pastes the Image
     		ShowImage(credit, screen); // Pastes the Image
     		ShowImage(exit, screen); // Pastes the Image
		displayText(info,screen,"created by 'Carthage Gladiators' ");
		SDL_Flip(screen) ; 
		e=1 ; 
	          break;}
		   case 2 : 
 		   {
			ShowImage(testex, screen); 
                        c=1 ; 
		       break;} 
		  }
             break ; }
		case SDLK_k : {if (c==1) {game_in_progress=1 ; }   break; }
 	    /* case SDLK_UP: // UP Arrow
	     {
		//WRITE HERE IF NEEDED
		break;
	     }
	     case SDLK_RETURN...SDLK_KP_ENTER: // ENTER OR NUM ENTER
	     {
		//write here if NEEDED
	        break;
	     }*/
	   }
	    break;
	 }}
     }
  }
  ClearSurface(Backg);
 ClearSurface(startg);
 ClearSurface(option);
ClearSurface(credit);
 ClearSurface(exit);
 ClearSurface(testst);
ClearSurface(testop);
ClearSurface(testcr);
ClearSurface(testex);

//IF MUSIC IS ADDED DON'T FORGET TO FREE WHEN YOU QUIT

  Mix_FreeMusic(music);
  //Mix_FreeChunk(Click_sound);



 //IF TEXT IS ADDED DON'T FORGET TO FREE WHEN U QUIT
ClearText(info);

return 0;
}
