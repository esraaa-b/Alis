#include "def.h"
typedef struct Ennemi
{
  SDL_Surface *image[12];
  SDL_Rect position;
  int direction;
  int numIM;
  int status;
  int affichage;

}Ennemi;

void initEnnemi(Ennemi *e);
void afficherEnnemi (Ennemi e,SDL_Surface *ecran);
void animerEnnemi (Ennemi *e);
void deplacer(Ennemi *e);
int collision (SDL_Surface *p,SDL_Rect posp,Ennemi e);
void deplacerAI(Ennemi *e,SDL_Rect pos);
typedef struct
{
SDL_Rect pos;
SDL_Rect sprite;
SDL_Surface *image;
int sprite_n;
int d_h;
int d_v;
int speed;
int affichage;
}entite;

void init_entite(entite *p);
void afficher_entite(entite p,SDL_Surface *screen);
void animer_entite(entite *p);
void mouvement_aleatoire_entite(entite *p);
int collisionTRI(SDL_Rect x1,SDL_Rect x2);
int collision2(SDL_Rect posp,Ennemi e);
