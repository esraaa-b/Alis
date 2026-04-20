#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#define LEFT 0
#define RIGHT 1

#define IDLE 0
#define WALKING 1
#define RUNNING 2
#define JUMPING 3
#define FALLING 4
#define ATTACKING 5
#define HURT 6

#define FLOOR 500


SDL_TimerID animateMC;
SDL_TimerID animateMC2;
SDL_Surface* screen;

typedef struct personne {
  int id; 
  int state;
  int currentSprite;
  int direction;
  SDL_Surface* spriteSheet[2][100][100];
  SDL_Rect spritePos;
  Uint8* keystate;
  int hit;
  char nom_perso[30];
  int num_perso;
  int vie;
  SDL_Rect pos_vie;
  SDL_Surface *afficher_vie[3];	
  int score;	
  SDL_Surface *afficher_score;
  float vx;
  float vy;
  float x;
  float y;
		
} personne;

	

void affichiervie(personne p, SDL_Surface *ecran);
int gestionvie(personne *p, SDL_Surface *ecran);


void initPerso(personne *p);

Uint32 animatepersonne(Uint32 interval, void* param);
void afficherPerso(personne p);
void deplacerPerso(personne *p);
void animerPerso(personne*p);
void saut(personne *p);
//2eme perso
void initPerso2(personne *p2);

Uint32 animatepersonne2(Uint32 interval, void* param);
void afficherPerso2(personne p2);
void deplacerPerso2(personne *p2);
void animerPerso2(personne*p2);
void saut2(personne *p2);

