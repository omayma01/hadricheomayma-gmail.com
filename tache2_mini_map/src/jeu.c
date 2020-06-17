#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "background.h"
#include "ennemi.h"
#include "hero.h"
#include "jeu.h"



int jouer(SDL_Surface * screen)
{

screen = SDL_SetVideoMode(1200, 400, 32,SDL_HWSURFACE|SDL_DOUBLEBUF | SDL_SRCALPHA);
	int done = 0;
	int i=0;
	Hero hero;
	Ennemi ennemi;
        ennemie e;
	Background Backg;
	SDL_Event event;
        SDL_Rect pos;
	  pos.x=550;
          pos.y=200;
	int keysHeld[323] = {0}; // everything will be initialized to false	

	//Uint32 t_prev,dt=1;

	if(loadEnnemiImages(&ennemi) == -1) {
		printf("Erreur Chargement Ennemi Images\n");
		return(-1);

	}
	
	if(loadHeroImages(&hero) == -1) {
		printf("Erreur Chargement Ennemi Images\n");
		return(-1);

	}

	if(loadBackground(&Backg) == -1) {
		printf("Erreur Chargement Background Images\n");
		return(-1);
	}
	

        initialiser_ennemie(&e,pos);
	initBackground(&Backg);
	initEnnemi(&ennemi);
        initHero(&hero);
	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {

	

		while (SDL_PollEvent(&event)) {
			// check for messages
			switch (event.type) {
				// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				keysHeld[event.key.keysym.sym] = 1;				
				break;

			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				//ennemi.moving=0;
				break;
			}
			// exit if ESCAPE is pressed
			if (keysHeld[SDLK_ESCAPE])
				done = 1;
		
                        if(keysHeld[SDLK_RIGHT]) {
				MoveHeroRight(&hero);
				AnnimateHeroRight(&hero);
				}

				if(keysHeld[SDLK_LEFT]) {
				MoveHeroLeft(&hero);
				AnnimateHeroLeft(&hero);
				}

		} 
	
		AnnimateEnnemi(&ennemi);
                blitBackground(&Backg,screen);
                blitHero(hero,screen);
		blitEnnemi(ennemi,screen);
	 UpdateEnnemi(&e,hero);
if(e.STATE==WAITING){
                        deplacer_ennemiealiatoire(&e);
}
if(e.STATE==FOLLOWING)
{
e.o.x=e.position.x;
 e.image[0]=IMG_Load("just.png");
e.image[1]=IMG_Load("just.png");
deplacer_ennemie(&e);
}
else if(e.STATE==FOLLOWING2)
{
e.o.x=e.position.x;
 e.image[0]=IMG_Load("just2.png");
e.image[1]=IMG_Load("just2.png");
                        deplacer_ennemie(&e);
}

          afficher_ennemie(e,screen);






		SDL_Flip(screen);

	}
	freeHero(&hero);
	freeEnnemi(&ennemi);
        //freeEnnemi(&e);
	freeBackground(&Backg);
	
return(0);
}
