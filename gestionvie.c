#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"perso.h"
#include <time.h>
#include <unistd.h>

void affichiervie(personne p, SDL_Surface *ecran){
	SDL_BlitSurface(p.afficher_vie[p.vie],NULL,ecran,&p.pos_vie);
}
int gestionvie(personne *p, SDL_Surface *ecran){
	
	
	if((p->hit==1)&&(p->vie!=0)){
		p->vie--;
	affichiervie(*p,ecran);
	SDL_Flip(ecran);
	usleep(1000000);
	p->spritePos.y=50;
	
	}
	p->hit=0;
	if (p->vie==0)
	return 0;
	else return 1;

}

