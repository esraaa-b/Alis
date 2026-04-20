#include "enigma.h"


void afficherEnigme(Enigme e,SDL_Surface *ecran){

	
		
	SDL_BlitSurface(e.back, NULL, ecran, NULL);
 	SDL_BlitSurface(e.image_clock,&(e.single_Clock), ecran, &e.pos_image_clock);
	SDL_BlitSurface(e.quest, NULL, ecran, &e.pos_quest);

	

	switch(e.positionVraiReponse){
		case 1:{

			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans1);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);


			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);

				}
			}	
			break;
		}
		case 2:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);


			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);


	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans3txt);


				}
			}
			break;
		}
		case 3:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans3txt);


			}
			break;
			case 2:                       
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans3txt);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button2, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_ans3);


				SDL_BlitSurface(e.ans1, NULL, ecran, &e.pos_ans1txt);

				SDL_BlitSurface(e.ans2, NULL, ecran, &e.pos_ans2txt);

				SDL_BlitSurface(e.ans3, NULL, ecran, &e.pos_ans3txt);

				}
			}

			break;
		}
	}
		SDL_Flip(ecran);
	SDL_Delay(100);
}


void InitEnigme(Enigme *e)
{

        e->pos_quest.x=300;
	e->pos_quest.y=100;
 
	e->pos_ans1.x=350;
	e->pos_ans1.y=300;


	e->pos_ans2.x=50;
	e->pos_ans2.y=300;

	e->pos_ans3.x=650;
	e->pos_ans3.y=300;

	e->pos_ans1txt.x=e->pos_ans1.x+50;
	e->pos_ans1txt.y=300+30;

	e->pos_ans2txt.x=50+50;
	e->pos_ans2txt.y=300+30;

	e->pos_ans3txt.x=650+50;
	e->pos_ans3txt.y=300+30;
	
	
	(*e).image_clock=IMG_Load("time.png");  

	e->pos_image_clock.x=100;
	e->pos_image_clock.y=100;
	
	e->single_Clock.w=57;
	e->single_Clock.h=81;
	e->single_Clock.x=0;
	e->single_Clock.y=0;

	e->clock_num=0;

     	FILE *fquest=NULL;
	FILE *freponse=NULL;
	FILE *fvraireponse=NULL;
	
	e->pos_selected=0;
	e->back= IMG_Load("pic/background.png");
	e->button= IMG_Load("pic/button.png");
	e->button2= IMG_Load("pic/button2.png");

	TTF_Init();
	SDL_Color couleur; 
        couleur.r=255;
        couleur.g=255;
        couleur.b=255;

	e->police = TTF_OpenFont("arial.ttf", 30);
	e->police1 = TTF_OpenFont("arial.ttf", 20);
	  
	char questionn[100];
	


     e->num_quest=1;   

	 
	
        fquest=fopen("questions.txt","r");
	if(fquest!=NULL){

		int test=1;
		while (fgets(questionn,100, fquest) &&(test!=e->num_quest)){ 
			test++;
		}
		
		fclose(fquest);
	}
	
	char reponse[100];

	int min,max;
   

if(e->num_quest==1)
{
min=0;
max=2;
}
else if(e->num_quest==2)
{
min=3;
max=5;
}
else
{
min=6;
max=8;
}
int try=1;

	freponse=fopen("reponses.txt","r");
	if(freponse!=NULL){

		int test=0;
		while (fgets((reponse),100, freponse) &&(test<max)){	
			
			if(test>=min){

                        if(try==1)
                              {
				e->ans1=TTF_RenderText_Blended(e->police1, reponse, couleur); 
                              try=0;
                              }                                                                                  
				e->ans2=TTF_RenderText_Blended(e->police1, reponse, couleur);  


			}
			test++;
		}	
		
		fclose(freponse);
	}
	
 
	
e->positionVraiReponse=1; 

	
	
	fvraireponse=fopen("vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		
		int test=1;
		while (fgets((reponse),100, fvraireponse)){
			
			if(test==e->num_quest){ 
				printf("%s\n",reponse);
				e->ans3=TTF_RenderText_Blended(e->police1, reponse, couleur); 
			}
			test++;
		}
		fclose(freponse);
	}




	
	printf("%d\n",e->positionVraiReponse);

	e->quest = TTF_RenderText_Blended(e->police, questionn, couleur);

	

 

}



void animerEnigme(Enigme *e){
		 	
	if (e->clock_num >=0 && e->clock_num <7) {
	e->clock_num++;
	e->single_Clock.x=e->clock_num * e->single_Clock.w;

	}
	
	if ( e->clock_num == 7) {
	e->clock_num=0;
	e->single_Clock.x=e->clock_num * e->single_Clock.w;

	}
 
	 
}

void winLost(Enigme e,SDL_Surface *ecran)
{

	SDL_Surface *win;
	SDL_Surface *lost;
SDL_Rect pos; 
        pos.x=160;
       pos.y=330;
        win=IMG_Load("pic/youwin.png");
	lost=IMG_Load("pic/youlose.png");
if(e.win==1){
printf("You win\n");
SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{	
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");	
							}
							SDL_Delay(2000);


}





int fonction_enigme()
{


	SDL_Surface * ecran=NULL;
	ecran = SDL_SetVideoMode(1000,620, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	int play=1;
	SDL_Event event;
	int var=0;
	SDL_Surface *win;
	SDL_Surface *lost;
	SDL_Rect pos; 
        pos.x=160;
        pos.y=330;
	Enigme e;
	InitEnigme(&e);
	win=IMG_Load("pic/youwin.png");
	lost=IMG_Load("pic/youlose.png");
	Uint32 start_time; 
    	start_time = SDL_GetTicks(); 



	while(play){
if(var==0){	
 		animerEnigme(&e);
 	
}

		afficherEnigme(e,ecran);
	
		while (SDL_PollEvent(&event))   
		{
			switch (event.type)
			{
				case SDL_QUIT:
				{	
                                   play=0;

				}
				case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{	
					case SDLK_i:
					e.pos_selected=1;
					break ; 
					
					case SDLK_j:
					e.pos_selected=2;
					break ; 
					
					case SDLK_k:
					e.pos_selected=3;
					break ; 
					
					case SDLK_RETURN:

                                          winLost(e,ecran);
							
						return 0;
					break ; 

				}break;
				case SDL_MOUSEMOTION:
				{
				}
			case SDL_MOUSEBUTTONUP:
				{
					if((event.motion.x>350 && event.motion.x<350+321)&&(event.motion.y>300 && event.motion.y<300+91))
					{
						e.pos_selected=1;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							 winLost(e,ecran);
							return e.win;
						} 	 
					}
					else if((event.motion.x>50 && event.motion.x<50+321)&&(event.motion.y>300 && event.motion.y<300+91))
					{
						e.pos_selected=2;
						if (event.button.button == SDL_BUTTON_LEFT)
						{	
 winLost(e,ecran);

							return e.win;
						} 
					}
					else if((event.motion.x>650 && event.motion.x<650+321)&&(event.motion.y>300 && event.motion.y<300+91))
					{
						e.pos_selected=3;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							 winLost(e,ecran);
							return e.win;
						} 					
					}
				}
				break;
			}
		}
		 
		if(e.positionVraiReponse==e.pos_selected)
		{
		e.win=1;
		}
		else
		{
		e.win=0;
		}

    if (SDL_GetTicks() - start_time >= TEMPS_LIMITE)
    {
        var=1;
        SDL_BlitSurface(lost, NULL, ecran, &pos);
        SDL_Flip(ecran);
        printf("You lost, time's up!\n");
        SDL_Delay(1000);
e.win=0;
return e.win;
    }
		}

	}





















