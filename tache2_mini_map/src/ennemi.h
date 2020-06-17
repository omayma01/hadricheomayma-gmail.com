#ifndef Ennemi_H
#define Ennemi_H
#include <SDL/SDL.h>
#include "background.h"
#include "hero.h"

struct Ennemi{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface * image;
	int direction;
	int moving;
};
typedef struct Ennemi Ennemi;


typedef enum STATE STATE;
enum STATE{WAITING,FOLLOWING,ATTACKING,FOLLOWING2};

typedef struct ennemie
{
SDL_Surface *image[2];
SDL_Rect position;
SDL_Rect o;
int Direction;
STATE STATE;
int num_image;
}ennemie;


int loadEnnemiImages(Ennemi * E);
void initEnnemi(Ennemi *E);
void AnnimateEnnemi(Ennemi *E);
void MoveEnnemi(Ennemi *E);
void freeEnnemi(Ennemi *E);

void initialiser_ennemie(ennemie *e,SDL_Rect pos);
void animer_ennemie(ennemie *e);
void afficher_ennemie(ennemie e,SDL_Surface *screen);
void UpdateEnnemi(ennemie *E,Hero A);
void input(ennemie *E,Hero A);
void deplacer_ennemiealiatoire(ennemie *e);



#endif
