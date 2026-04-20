#include "jeu.h"

int jeu()

{
  SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER);
TTF_Init();
  personne p;
  personne p2;
  screen = SDL_SetVideoMode(1360, 650, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  SDL_Rect bgPos = {0,0}; 
  initPerso(&p);
  initPerso2(&p2);
personne* personnes[1] = {&p};
personne* personnes2[1] = {&p2};
personnes[0]->spritePos.x=50;
int done = 0;
  SDL_Event e;
  animateMC = SDL_AddTimer(200, animatepersonne, personnes[0]);
SDL_EnableKeyRepeat(60,60);
/*background*/
int pas_scrolling=5;
	background bg;
	background bg2;
	initBack2(&bg);
	initBack22(&bg2);
/*entite*/
Ennemi en;
entite ent;
  initEnnemi(&en);
  init_entite(&ent);
/*minimap*/
    minimap m;
    initmap(&m);
    minimap minimapObject; // Corrected typo here
    minimapObject.mini_image = m.img_map; // Assuming you want to use the minimap image
    Uint32 start_time = SDL_GetTicks();

TTF_Font *police=TTF_OpenFont("arial.ttf",50);
  while(!done) {






if(personnes2[0]->spritePos.x<800) personnes2[0]->spritePos.x=800;
if(personnes2[0]->spritePos.x>1250) personnes2[0]->spritePos.x=1250;
if(personnes[0]->spritePos.x>550) personnes[0]->spritePos.x=550;
if(personnes[0]->spritePos.x<50) personnes[0]->spritePos.x=50;

    personnes[0]->keystate = SDL_GetKeyState(NULL);
    personnes2[0]->keystate = SDL_GetKeyState(NULL);
    while(SDL_PollEvent(&e)) {
      switch(e.type) {

            case SDL_QUIT:
                done = 1;
                break;
        case SDL_KEYDOWN: {

          int key = e.key.keysym.sym;
          /**/if(key == SDLK_ESCAPE){
            done = 1;
            break;
          }
	if(key == SDLK_LEFT)if(bg.camera2.x>0)scrolling(&bg,1,pas_scrolling);
	if(key == SDLK_RIGHT) if(bg.camera2.x<1970)scrolling(&bg,0,pas_scrolling);
	if(key == SDLK_UP) if(bg.camera2.y>0)scrolling(&bg,2,pas_scrolling);
	if(key == SDLK_DOWN)if(bg.camera2.y<495)scrolling(&bg,3,pas_scrolling);
	if(key == SDLK_q)if(bg2.camera22.x>0)scrolling2(&bg2,1,pas_scrolling);
	if(key == SDLK_d) if(bg2.camera22.x<1970)scrolling2(&bg2,0,pas_scrolling);
	if(key == SDLK_z) if(bg2.camera22.y>0)scrolling2(&bg2,2,pas_scrolling);
	if(key == SDLK_s)if(bg2.camera22.y<495)scrolling2(&bg2,3,pas_scrolling);
          if(key == SDLK_x) {
            personnes[0]->currentSprite = 0;
            personnes[0]->state = ATTACKING;
            break;
          }
          if(key == SDLK_UP) {
            personnes[0]->currentSprite = 0;
            personnes[0]->state = JUMPING;
            break;
          }
 if(key == SDLK_w) {
            personnes2[0]->currentSprite = 0;
            personnes2[0]->state = JUMPING;
            break;
          }
 if(key == SDLK_z) {
            personnes2[0]->currentSprite = 0;
            personnes2[0]->state = ATTACKING;
            break;
          }
/**/
if(key == SDLK_x)
          break;
        }
      }
    }
/*background*/
animerBackground(&bg2);	
animerBackground(&bg);	
afficheBack2(bg,screen);
afficheBack22(bg2,screen);
/*minimap*/
	m.pos_joueur = MAJMinimap (personnes[0]->spritePos,11,bg2.camera2);
        afficherminimap(m, screen);
        animerMinimap(&minimapObject);   
     affichertemp (&start_time,screen,police);


/*perso*/
    deplacerPerso(personnes[0]);
    afficherPerso(p);
    deplacerPerso2(personnes2[0]);
    afficherPerso2(p2);
    affichiervie(p, screen);

/*entite*/

deplacer(&en);
deplacerAI(&en,personnes[0]->spritePos);
    afficherEnnemi(en,screen);
	afficher_entite(ent,screen);
	animer_entite(&ent);
	mouvement_aleatoire_entite(&ent);

if (collisionTRI(ent.pos,personnes[0]->spritePos)) {if(ent.affichage==1)bg.num_score+=500;ent.affichage=0;}
if(p.vie<0) done=1;
		if ((collision2(personnes[0]->spritePos,en)==1) && (en.affichage==1)){
			if(fonction_enigme()==1)
				en.affichage=0;
			else
				{p.vie--;
				personnes[0]->spritePos.x=50;
				initEnnemi(&en);}
			screen = SDL_SetVideoMode(1360, 650, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
		}

    SDL_Flip(screen);
  }
}
