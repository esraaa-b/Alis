#ifndef ENIGMA_H_INCLUDED
#define ENIGMA_H_INCLUDED

#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <unistd.h>
#define TEMPS_LIMITE 10000 // (millisecondes)


typedef struct{

	SDL_Surface *back;
	SDL_Surface *quest; 
	SDL_Surface *ans1; 
	SDL_Surface *ans2;
	SDL_Surface *ans3; 
	SDL_Surface *button;
	SDL_Surface *button2;

	int pos_selected;
	SDL_Rect pos_quest;
	SDL_Rect pos_ans1;
	SDL_Rect pos_ans2;
	SDL_Rect pos_ans3;
	int num_quest;
	
	SDL_Rect pos_ans1txt;//position du texte situé sur l'image de la reponse
	SDL_Rect pos_ans2txt;
	SDL_Rect pos_ans3txt;

	int positionVraiReponse;//position de la vraie reponse, celle de l'image et du texte
	TTF_Font *police; 
	TTF_Font *police1;
	
		
	SDL_Surface *image_clock;  
	SDL_Rect pos_image_clock;
	SDL_Rect single_Clock;
	int clock_num;
        int win;

}Enigme;
void InitEnigme(Enigme *e);
void afficherEnigme(Enigme e,SDL_Surface *ecran);
void animerEnigme(Enigme *e);
void winLost(Enigme e,SDL_Surface *ecran);
int fonction_enigme();

#endif
