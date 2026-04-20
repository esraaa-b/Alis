#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

void initPerso(personne *p) { 
	p->afficher_vie[0]=IMG_Load("vie0.png");
	p->afficher_vie[1]=IMG_Load("vie1.png");
	p->afficher_vie[2]=IMG_Load("vie2.png");
	p->afficher_vie[3]=IMG_Load("vie3.png");
	p->vie=3;

// Initialisation de l'ID du personnage	
  p->id = 0;

//stocker dans des tableaux de surfaces SDL_Surface*
  SDL_Surface* idle[1] = {
    IMG_Load("mc/idle1.png"),
  };


  SDL_Surface* walking[4] = {
   
    IMG_Load("mc/walk1.png"),
    IMG_Load("mc/walk2.png"),
    IMG_Load("mc/walk3.png"),
    IMG_Load("mc/walk4.png"),
  };

  SDL_Surface* running[4] = {
    IMG_Load("mc/walk1.png"),
    IMG_Load("mc/walk2.png"),
    IMG_Load("mc/walk3.png"),
    IMG_Load("mc/walk4.png"),
  };

  SDL_Surface* jumping[4]= {
    IMG_Load("mc/jump1.png"),
    IMG_Load("mc/jump2.png"),
    IMG_Load("mc/jump3.png"),
    IMG_Load("mc/jump4.png"),
  }; 
  SDL_Surface* falling[4] = {
    IMG_Load("mc/jump4.png"),
    IMG_Load("mc/jump3.png"),
    IMG_Load("mc/jump2.png"),
    IMG_Load("mc/jump1.png"),
  };

  SDL_Surface* attacking[3] = {
    IMG_Load("mc/hit1.png"),
    IMG_Load("mc/hit2.png"),
    IMG_Load("mc/hit3.png"),
  };

  SDL_Surface* idle1[1] = {
    IMG_Load("mc/idle2.png"),
  };

  SDL_Surface* walking1[4] = {
  
    IMG_Load("mc/walk5.png"),
    IMG_Load("mc/walk6.png"),
    IMG_Load("mc/walk7.png"),
    IMG_Load("mc/walk8.png"),
  };

  SDL_Surface* running1[4] = {
    IMG_Load("mc/walk5.png"),
    IMG_Load("mc/walk6.png"),
    IMG_Load("mc/walk7.png"),
    IMG_Load("mc/walk8.png"),
  };

  SDL_Surface* jumping1[4]= {
    IMG_Load("mc/jump5.png"),
    IMG_Load("mc/jump6.png"),
    IMG_Load("mc/jump7.png"),
    IMG_Load("mc/jump8.png"),
  };

  SDL_Surface* falling1[4] = {
    IMG_Load("mc/jump8.png"),
    IMG_Load("mc/jump7.png"),
    IMG_Load("mc/jump6.png"),
    IMG_Load("mc/jump5.png"),
  };

  SDL_Surface* attacking1[3] = {
    IMG_Load("mc/hit4.png"),
    IMG_Load("mc/hit5.png"),
    IMG_Load("mc/hit6.png"),
 };

// Assignation des sprites pour l'état IDLE (sans mouvement) du personnage dans les deux directions (droite et gauche)
  for(int i=0; i<2; i++) {
    p->spriteSheet[RIGHT][IDLE][i] = idle[i];
    p->spriteSheet[LEFT][IDLE][i] = idle1[i];
  }
// Assignation des sprites pour l'état de marche (WALKING) du personnage dans les deux directions
  for(int i=0; i<4; i++) { 
    p->spriteSheet[RIGHT][WALKING][i] = walking[i];
    p->spriteSheet[LEFT][WALKING][i] = walking1[i];
  }
// Assignation des sprites pour l'état de course (RUNNING) du personnage dans les deux directions
  for(int i=0; i<4; i++) {
    p->spriteSheet[RIGHT][RUNNING][i] = running[i];
    p->spriteSheet[LEFT][RUNNING][i] = running1[i];
  }
// Assignation des sprites pour l'état de saut (JUMPING) du personnage dans les deux directions
  for(int i=0; i<4; i++) {
    p->spriteSheet[RIGHT][JUMPING][i] = jumping[i];
    p->spriteSheet[LEFT][JUMPING][i] = jumping1[i];
  }
// Assignation des sprites pour l'état de chute (FALLING) du personnage dans les deux directions
  for(int i=0; i<4; i++) {
    p->spriteSheet[RIGHT][FALLING][i] = falling[i];
    p->spriteSheet[LEFT][FALLING][i] = falling1[i];
  }
// Assignation des sprites pour l'état d'attaque (ATTACKING) du personnage dans les deux directions
  for(int i=0; i<3; i++) {
    p->spriteSheet[RIGHT][ATTACKING][i] = attacking[i];
    p->spriteSheet[LEFT][ATTACKING][i] = attacking1[i];
  }
// Initialisation de l'état initial du personnage (FALLING), de l'indice du sprite actuel, de la direction, et de la position du sprite
p->state = FALLING;
  p->state = FALLING;
  p->currentSprite = 0;
  p->direction = RIGHT;
  p->spritePos.x = FLOOR;// Position en x du personnage, par exemple, sur le sol
  p->spritePos.y = 300; // Position en y du personnage, par exemple, à une certaine hauteur
  p->spritePos.w = 40;
  p->spritePos.h = 40;

  
}
  

void saut(personne *p)
{
  p->spritePos.y=2;// Ajustement temporaire de la position en y (à adapter)
    if(p->spritePos.y <= 70  ) { 
      p->currentSprite = 0;
      p->spritePos.y = 300;// Nouvelle position du personnage après le saut
      p->state = FALLING;
    }
}

void deplacerPerso(personne *p) {
  int run = SDLK_r;
  int right =  SDLK_RIGHT;
  int left = SDLK_LEFT;
 // Vérifie l'état du personnage et les touches enfoncées pour déterminer son déplacement
  if(p->state == ATTACKING || p->state == JUMPING || p->state == FALLING)
    {
// Dans ces états, le personnage ne peut pas se déplacer
}
   else if(p->keystate[run] && p->keystate[right]){
    p->direction = RIGHT;
    p->state = RUNNING;
 
  } else if(p->keystate[run] && p->keystate[left]) {
    p->direction = LEFT;
    p->state = RUNNING;

  } else if(p->keystate[run]) {
    p->direction = RIGHT;
    p->state = RUNNING;
  
  } else if(p->keystate[right]) {
    p->direction = RIGHT;
    p->state = WALKING;
  
    if(p->currentSprite >= 8)
      p->currentSprite = 0;
  
  } else if(p->keystate[left]) {
    p->direction = LEFT;
    p->state = WALKING;

    if(p->currentSprite >= 8)
      p->currentSprite = 0;
 
  } else {
    p->state = IDLE;

   
    if(p->currentSprite >= 4)
      p->currentSprite = 0;
  }
 // Déplacement du personnage en fonction de sa direction et des touches enfoncées
  if(p->keystate[run]) {
// Ajoute à la position en x du personnage -5 s'il va à gauche et +5 s'il va à droite
    p->spritePos.x += p->keystate[left] ? -5 : 5; 
  } else if(p->keystate[left])
// Déplace le personnage d'une unité vers la gauche
      p->spritePos.x -= 1;
  else if(p->keystate[right])
// Déplace le personnage d'une unité vers la droite
      p->spritePos.x += 1;
// Si le personnage est en train de sauter
  if(p->state == JUMPING) {
    saut(p);
    
  }
// Si le personnage est en train de tomber
  if(p->state == FALLING) {
    p->spritePos.y += 1;
    if(p->spritePos.y >= FLOOR) {
      p->spritePos.y = FLOOR;
      p->state = IDLE;
    }
  }
}


void afficherPerso(personne p) {
//afficher le personnage sur l'écran
  SDL_BlitSurface(p.spriteSheet[p.direction][p.state][p.currentSprite], 0, screen, &p.spritePos);

}





Uint32 animatepersonne(Uint32 interval, void* param) {
// Fonction de temporisation pour animer le personnage
  personne* p = param;
// Détermine le nombre maximal de sprites dans l'animation en fonction de l'état du personnage
  int limit = p->state == IDLE || p->state == JUMPING ? 1 : 4;
// Si le personnage est en train de tomber, le nombre maximal de sprites est 4
  if(p->state == FALLING)
    limit = 4;
 // Incrémente l'indice du sprite actuel du personnage
  p->currentSprite++;
  if(p->currentSprite >= limit) {
// Si l'indice du sprite actuel dépasse la limite définie
// Si le personnage est en train d'attaquer, il passe à l'état IDLE    
  if(p->state == ATTACKING)
      p->state = IDLE;
// Si le personnage est en train de tomber et sa position en y est supérieure ou égale au sol, il passe à l'état IDLE
    if(p->state == FALLING && p->spritePos.y >= FLOOR)
      p->state = IDLE;
 // Réinitialise l'indice du sprite actuel à 0 pour recommencer l'animation    
    p->currentSprite = 0;


  }
// Retourne l'intervalle de temps pour la prochaine animation
  return interval;
}



void animerPerso(personne*p)
{
 //lancer l'animation du personnage
 //SDL_AddTimer pour appeler animatepersonne à intervalles réguliers
  SDL_TimerID animateMC = SDL_AddTimer(200, animatepersonne, p);
}


void initPerso2(personne *p2) {

    p2->id = 0;

  SDL_Surface* idle[1] = {
    IMG_Load("mc/idle1.png"),
  };

  SDL_Surface* walking[4] = {
   
    IMG_Load("mc/walk1.png"),
    IMG_Load("mc/walk2.png"),
    IMG_Load("mc/walk3.png"),
    IMG_Load("mc/walk4.png"),
  };

  SDL_Surface* running[4] = {
    IMG_Load("mc/walk1.png"),
    IMG_Load("mc/walk2.png"),
    IMG_Load("mc/walk3.png"),
    IMG_Load("mc/walk4.png"),
  };

  SDL_Surface* jumping[4]= {
    IMG_Load("mc/jump1.png"),
    IMG_Load("mc/jump2.png"),
    IMG_Load("mc/jump3.png"),
    IMG_Load("mc/jump4.png"),
  }; 
  SDL_Surface* falling[4] = {
    IMG_Load("mc/jump4.png"),
    IMG_Load("mc/jump3.png"),
    IMG_Load("mc/jump2.png"),
    IMG_Load("mc/jump1.png"),
  };

  SDL_Surface* attacking[3] = {
    IMG_Load("mc/hit1.png"),
    IMG_Load("mc/hit2.png"),
    IMG_Load("mc/hit3.png"),
  };

  SDL_Surface* idle1[1] = {
    IMG_Load("mc/idle2.png"),
  };

  SDL_Surface* walking1[4] = {
  
    IMG_Load("mc/walk5.png"),
    IMG_Load("mc/walk6.png"),
    IMG_Load("mc/walk7.png"),
    IMG_Load("mc/walk8.png"),
  };

  SDL_Surface* running1[4] = {
    IMG_Load("mc/walk5.png"),
    IMG_Load("mc/walk6.png"),
    IMG_Load("mc/walk7.png"),
    IMG_Load("mc/walk8.png"),
  };

  SDL_Surface* jumping1[4]= {
    IMG_Load("mc/jump5.png"),
    IMG_Load("mc/jump6.png"),
    IMG_Load("mc/jump7.png"),
    IMG_Load("mc/jump8.png"),
  };

  SDL_Surface* falling1[4] = {
    IMG_Load("mc/jump8.png"),
    IMG_Load("mc/jump7.png"),
    IMG_Load("mc/jump6.png"),
    IMG_Load("mc/jump5.png"),
  };

  SDL_Surface* attacking1[3] = {
    IMG_Load("mc/hit4.png"),
    IMG_Load("mc/hit5.png"),
    IMG_Load("mc/hit6.png"),
 };

  for(int i=0; i<2; i++) {
    p2->spriteSheet[RIGHT][IDLE][i] = idle[i];
    p2->spriteSheet[LEFT][IDLE][i] = idle1[i];
  }

  for(int i=0; i<4; i++) { 
    p2->spriteSheet[RIGHT][WALKING][i] = walking[i];
    p2->spriteSheet[LEFT][WALKING][i] = walking1[i];
  }

  for(int i=0; i<4; i++) {
    p2->spriteSheet[RIGHT][RUNNING][i] = running[i];
    p2->spriteSheet[LEFT][RUNNING][i] = running1[i];
  }
  for(int i=0; i<4; i++) {
    p2->spriteSheet[RIGHT][JUMPING][i] = jumping[i];
    p2->spriteSheet[LEFT][JUMPING][i] = jumping1[i];
  }

  for(int i=0; i<4; i++) {
    p2->spriteSheet[RIGHT][FALLING][i] = falling[i];
    p2->spriteSheet[LEFT][FALLING][i] = falling1[i];
  }

  for(int i=0; i<3; i++) {
    p2->spriteSheet[RIGHT][ATTACKING][i] = attacking[i];
    p2->spriteSheet[LEFT][ATTACKING][i] = attacking1[i];
  }

  p2->state = FALLING;
  p2->currentSprite = 0;
  p2->direction = RIGHT;
  p2->spritePos.x = FLOOR;
  p2->spritePos.y = 70;
 
}


  
void saut2(personne *p2)
{
  p2->spritePos.y=2;
    if(p2->spritePos.y <= 70  ) { 
      p2->currentSprite = 0;
      p2->spritePos.y = 300;
      p2->state = FALLING;
    }

}

void deplacerPerso2(personne *p2) {
  int run = SDLK_u;
  int right =  SDLK_d;
  int left = SDLK_a;
 
  if(p2->state == ATTACKING || p2->state == JUMPING || p2->state == FALLING)
    {}
   else if(p2->keystate[run] && p2->keystate[right]){
    p2->direction = RIGHT;
    p2->state = RUNNING;
 
  } else if(p2->keystate[run] && p2->keystate[left]) {
    p2->direction = LEFT;
    p2->state = RUNNING;

  } else if(p2->keystate[run]) {
    p2->direction = RIGHT;
    p2->state = RUNNING;
  
  } else if(p2->keystate[right]) {
    p2->direction = RIGHT;
    p2->state = WALKING;
  
    if(p2->currentSprite >= 8)
      p2->currentSprite = 0;
  
  } else if(p2->keystate[left]) {
    p2->direction = LEFT;
    p2->state = WALKING;

    if(p2->currentSprite >= 8)
      p2->currentSprite = 0;
 
  } else {
    p2->state = IDLE;

   
    if(p2->currentSprite >= 4)
      p2->currentSprite = 0;
  }
 
  if(p2->keystate[run]) {
    p2->spritePos.x += p2->keystate[left] ? -5 : 5; 
  } else if(p2->keystate[left])
      p2->spritePos.x -= 1;
  else if(p2->keystate[right])
      p2->spritePos.x += 1;

  if(p2->state == JUMPING) {
    saut(p2);
    
  }

  if(p2->state == FALLING) {
    p2->spritePos.y += 1;
    if(p2->spritePos.y >= FLOOR) {
      p2->spritePos.y = FLOOR;
      p2->state = IDLE;
    }
  }
}
void afficherPerso2(personne p2) {
  SDL_BlitSurface(p2.spriteSheet[p2.direction][p2.state][p2.currentSprite], 0, screen, &p2.spritePos);

}





Uint32 animatepersonne2(Uint32 interval, void* param) {
  personne* p2 = param;

  int limit = p2->state == IDLE || p2->state == JUMPING ? 1 : 4;

  if(p2->state == FALLING)
    limit = 4;
 
  p2->currentSprite++;
  if(p2->currentSprite >= limit) {
    if(p2->state == ATTACKING)
      p2->state = IDLE;
    if(p2->state == FALLING && p2->spritePos.y >= FLOOR)
      p2->state = IDLE;
      
    p2->currentSprite = 0;





  }
  return interval;
}



void animerPerso2(personne*p2)
{
  SDL_TimerID animateMC = SDL_AddTimer(200, animatepersonne, p2);
}
