#include "entite_secondaire.h"
#include <math.h>

///////////////////////////

void initEnnemi(Ennemi *e){
  int i ;
  char ch[100]= "ennemi/";
  char n [3],ch1[100];
  for(i=0;i<12;i++){
    strcpy (ch1,"");
    strcat (ch1,ch);

    sprintf (n, "%d" ,i);
    strcat (ch1,n);

    strcat (ch1, ".png");

    e->image[i]=IMG_Load(ch1);
    if  (e->image[i]==NULL)
    {
      printf("Unable to load Ennemi %s\n" , IMG_GetError());
    }
    e->position.x =400;
    e->position.y =500;
    e->direction = 0;
    e->numIM = 0;
    e->status = 0;
    e->affichage = 1;



  }


}
//////////////////////////////
void afficherEnnemi (Ennemi e,SDL_Surface *ecran){
if (e.affichage == 1)
  SDL_BlitSurface (e.image[e.numIM],NULL,ecran,&e.position);



}

////////////////////////////////
void animerEnnemi (Ennemi *e){
  if(e->direction==0 && e->status ==0){
    e->numIM++;
    if (e->numIM>2) e->numIM=0;

  }
  if (e->direction==1 && e->status ==0)
  {
    e->numIM++;
    if (e->numIM>5) e->numIM=3;


  }

  ///////////////////////////////////
  if(e->direction==0 && e->status ==1){
    e->numIM++;
    if (e->numIM>8) e->numIM=6;

  }
  if(e->direction==1 && e->status ==1){
    e->numIM++;
    if (e->numIM>11) e->numIM=9;

  }



}
//////////////////////////////////
void deplacer(Ennemi *e){
  if ((e->position.x>=400)&&(e->position.x<600)&&(e->direction==0)){
   
    e->position.x=e->position.x + 1 ;
    animerEnnemi(e);
    if (e->position.x >= 600){
      e->direction = 1;
    }

  }
  if ((e->direction ==1)&&(e->position.x>400)){
    
    e->position.x=e->position.x - 1 ;
    animerEnnemi(e);
    if (e->position.x <=400)
    {
      e->direction=0;
    }

  }



}
/////////////////////////////////////////
int collision (SDL_Surface *p,SDL_Rect posp,Ennemi e){
  if ((((posp.x+p->w) >= e.position.x)) && ((posp.x+p->w) <= (e.position.x+e.image[e.numIM]->w))&&((posp.y+p->h)>=e.position.y)){
    return 1;
  }
  if (((posp.x >= e.position.x)) && (posp.x <= (e.position.x+e.image[e.numIM]->w))&&((posp.y+p->h)>=e.position.y)){
    return 1;
  }

  return 0;
}
int collision2 (SDL_Rect posp,Ennemi e){
  if ((((posp.x+posp.w) >= e.position.x)) && ((posp.x+posp.w) <= (e.position.x+e.image[e.numIM]->w))&&((posp.y+posp.h)>=e.position.y)){
    return 1;
  }
  if (((posp.x >= e.position.x)) && (posp.x <= (e.position.x+e.image[e.numIM]->w))&&((posp.y+posp.h)>=e.position.y)){
    return 1;
  }

  return 0;
}
void deplacerAI(Ennemi *e,SDL_Rect pos){
  if (e->position.x-pos.x<100 && e->position.x>pos.x){
    e->status =1;
    e->direction = 1;
    e->numIM =9;
    e->position.x=e->position.x-1;
    animerEnnemi(e);
  }
  if ((e->position.x-pos.x)<300&&e->status ==0 &&e->position.x>pos.x){
    e->status = 0;
    e->direction = 1;
    e->position.x=e->position.x-1;
    animerEnnemi(e);

  }
  ///////////////////////////////////////////////////
  if (pos.x-e->position.x<100 && e->position.x<pos.x){
    e->status =1;
    e->direction = 0;
    e->numIM =6;
    e->position.x=e->position.x+1;
    animerEnnemi(e);
  }
  if ((pos.x-e->position.x)<300&&e->status ==0 &&e->position.x<pos.x){
    e->status = 0;
    e->direction = 1;
    e->position.x=e->position.x+1;
    animerEnnemi(e);

  }


}

void init_entite(entite * p) 
{
  ( * p).d_h = 0;
  ( * p).d_v = 0;
  ( * p).affichage = 1;
  ( * p).pos.x = 400;
  ( * p).pos.y = 400;
  ( * p).sprite.x = 0;
  ( * p).sprite.y = 0;
  ( * p).sprite_n = 0;
  ( * p).speed = 1;
  ( * p).image = IMG_Load("mini-coin.png");
  ( * p).pos.w = ( * p).image -> w/6;
  ( * p).pos.h = ( * p).image -> h;
  ( * p).sprite.w = ( * p).image -> w/6;
  ( * p).sprite.y = 0;
  ( * p).sprite.h = ( * p).image -> h;
}
void afficher_entite(entite p, SDL_Surface * screen) {
if (p.affichage == 1)
    SDL_BlitSurface(p.image, & p.sprite, screen, & p.pos);
}
void animer_entite(entite * p) 
{
    ( * p).sprite_n++;
    if (( * p).sprite_n >= 6) {
      ( * p).sprite_n = 0;
    }

    ( * p).sprite.x = ( * p).pos.w * ( * p).sprite_n;
}
void mouvement_aleatoire_entite(entite *p)
{
if (( * p).pos.x % 200<( * p).speed) ( * p).d_h=rand()%2;
if(( * p).pos.x<0) ( * p).d_h=0;
if(( * p).pos.x>1200) ( * p).d_h=1;
if (( * p).d_h==1) ( * p).pos.x-=( * p).speed;
else ( * p).pos.x+=( * p).speed;

if (( * p).pos.y % 100<( * p).speed) ( * p).d_v=rand()%2;
if(( * p).pos.y<300) ( * p).d_v=0;
if(( * p).pos.y>600) ( * p).d_v=1;
if (( * p).d_v==1) ( * p).pos.y-=( * p).speed;
else ( * p).pos.y+=( * p).speed;
}

int collisionTRI(SDL_Rect x1,SDL_Rect x2)
{
int r1,r2;
if (x1.w>x1.h) r1 = x1.w/2;
else r1 = x1.h/2;
if (x2.w>x2.h) r2 = x2.w/2;
else r2 = x2.h/2;
int distance = sqrt( (x2.y - x1.y)*(x2.y - x1.y) + (x2.x - x1.x)*(x2.x - x1.x) );
if(r1+r2>distance) return 1;
return 0;
}
