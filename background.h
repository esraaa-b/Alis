#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

//-----------------------structure de texte -------------------------------------
typedef struct struct_text{
 TTF_Font *font;
 SDL_Color color;
 SDL_Surface* text;
 SDL_Rect postext;
}Text;
//---------------------------------structure back---------------------------------
typedef struct
{
	SDL_Surface *imgback;
	SDL_Rect positionbackground;
	SDL_Rect positionbackground2;
	SDL_Rect camera2;//chn3ml biha scrolling / bch tafichi koul mra partie mil  back
	SDL_Rect camera22;//chn3ml biha scrolling /bch tafichi koul mra partie mil  back
	Mix_Music *son; //les son 
        Mix_Music *son1;
	SDL_Surface *image_planete;  
	SDL_Rect pos_image_planete;
	SDL_Rect single_planete;	
	int planete_f;
        int num_score;
	Text score; 


}background;
void initBack2(background *b); 
void initBack22(background *b); 
void afficheBack2 (background b, SDL_Surface *ecran);
void afficheBack22 (background b, SDL_Surface *ecran);
void scrolling (background *b,int direction,int pas);
void scrolling2 (background *b,int direction,int pas);
void animerBackground(background *b);
void displayPlaneteffaFWa(background b,SDL_Surface *ecran);
void afficher(background b,SDL_Surface *ecran);


#endif  
