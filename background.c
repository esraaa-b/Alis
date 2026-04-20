#include "background.h"

#define SCREEN_W 1360
#define SCREEN_H 765
void initBack2 (background *b)
{
//background2
b->imgback =IMG_Load("back.png");
b->positionbackground.x=0;
b->positionbackground.y=0;
//b->positionbackground.w=SCREEN_W/2;
//b->positionbackground.y=SCREEN_H;
//camera2
b->camera2.x=0;
b->camera2.y=500;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;
//musique

        b->son1=Mix_LoadMUS("son.mp3"); //Chargement de la musique
        b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique
	b->image_planete=IMG_Load("planete.png");  
	b->pos_image_planete.x=500;
	b->pos_image_planete.y=100;
	b->single_planete.w=100;
	b->single_planete.h=100;
	b->single_planete.x=0;
	b->single_planete.y=0;
	b->planete_f=0;
//------------------------------------------font--------------------------
TTF_Init();
b->score.font=TTF_OpenFont("pol.ttf",50);

b->score.color=(SDL_Color) {0,255,255};
//rendertext_:blened  va ecrire le text aka hasib il font+ color -----------------------------
b->score.text=TTF_RenderText_Blended(b->score.font,"score1 : 0",b->score.color);




b->score.postext.x=200;
b->score.postext.y=0;


//--------------------------initialisation de  score -----------------
b->num_score=0;



}




void initBack22 (background *b)
{
//-------------------------background2
b->imgback =IMG_Load("back.png");
b->positionbackground2.x=SCREEN_W/2;
b->positionbackground2.y=0;

//-----------------------camera2    bch tafichi koul mra partie mil  back------------
b->camera22.x=0;
b->camera22.y=500;
b->camera22.w=SCREEN_W; 
b->camera22.h=SCREEN_H;

b->image_planete=IMG_Load("planete.png");  
//x=500 bch tejina keka fil partie 2--------------------------
	b->pos_image_planete.x=800;
	b->pos_image_planete.y=100;
	b->single_planete.w=100;
	b->single_planete.h=100;
	b->single_planete.x=0;
	b->single_planete.y=0;
	b->planete_f=0;
TTF_Init();
b->score.font=TTF_OpenFont("arial.ttf",50);

b->score.color=(SDL_Color) {255,255,0};
b->score.text=TTF_RenderText_Blended(b->score.font,"score2: 0",b->score.color);




b->score.postext.x=800;
b->score.postext.y=0;



b->num_score=0;




}
//--------------------affichage de back 2 il bch telsa9 fil pos 2-------------------------
void afficheBack22(background b, SDL_Surface *ecran)
{
 

char ch_score[12];
//--------------la fonction sprintf va ecrire -------------------------
 sprintf(ch_score,"score 2: %d",b.num_score);
b.score.text=TTF_RenderText_Blended(b.score.font,ch_score,b.score.color);

SDL_BlitSurface(b.imgback ,&b.camera22,ecran,&b.positionbackground2);

displayPlaneteffaFWa(b,ecran);
  SDL_BlitSurface(b.score.text,NULL,ecran,&b.score.postext);

}


void afficheBack2(background b, SDL_Surface *ecran)
{
 

char ch_score[12];
 sprintf(ch_score,"score 1: %d",b.num_score);

b.score.text=TTF_RenderText_Blended(b.score.font,ch_score,b.score.color);


SDL_BlitSurface(b.imgback ,&b.camera2,ecran,&b.positionbackground);//&b.camera
displayPlaneteffaFWa(b,ecran);
  SDL_BlitSurface(b.score.text,NULL,ecran,&b.score.postext);

}

//----------------fonction scrolling permet de : kif yemchy howa yetzed fil score ---------
void scrolling (background *b,int direction,int pas)

{

if (direction ==0){//yminbac1  


	b->camera2.x+= pas;
        b->num_score+=1;
	
        }
else if (direction ==1){//ysarbac1          


	b->camera2.x-=pas; 
        b->num_score+=1;
	}
 
else if (direction ==2){//lfouk back 2 o 1 


         b->camera2.y-= pas;
        b->num_score+=1;
	}
else if (direction ==3){//         


	 b->camera2.y+= pas;
        b->num_score+=1;
	 }

}

void scrolling2 (background *b,int direction,int pas)
{

if (direction ==0){//ymin_bac1  


	b->camera22.x+= pas;
        b->num_score+=1;
	
        }
else if (direction ==1){//ysar_bac1          


	b->camera22.x-=pas; 
        b->num_score+=1;
	}
 
else if (direction ==2){//lfouk back 2 o 1 


         b->camera22.y-= pas;
        b->num_score+=1;
	}
else if (direction ==3){//         


	 b->camera22.y+= pas;
        b->num_score+=1;
	 }

}

void displayPlaneteffaFWa(background b,SDL_Surface *ecran){
			
 		SDL_BlitSurface(b.image_planete,&(b.single_planete), ecran, &b.pos_image_planete);
}
void animerBackground(background *b){//cht3mili annimation tswira 
		 	
	if (b->planete_f >=0 && b->planete_f<6) {
	b->single_planete.x=b->planete_f * b->single_planete.w;
	b->planete_f++;
	}
	
	if ( b->planete_f == 6) {
	b->single_planete.x=b->planete_f * b->single_planete.w;
	b->planete_f=0;//kif weslt 8 nffichi tswira lowla 
	}
 
	 
}









