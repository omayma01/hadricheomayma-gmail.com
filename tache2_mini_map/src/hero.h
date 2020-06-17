#ifndef Hero_H
#define Hero_H
#include <SDL/SDL.h>
#include "background.h"

struct Hero{
        SDL_Rect positionAbsolue;
	SDL_Rect positionAnimation;
	SDL_Surface * image;
	int vie;
};
typedef struct Hero Hero;

int loadHeroImages(Hero * H);

void initHero(Hero *H);

void AnnimateHeroRight(Hero *H);

void AnnimateHeroLeft(Hero *H);

void blitHero(Hero A, SDL_Surface * screen);

void MoveHeroLeft(Hero *H);

void MoveHeroRight(Hero *H);

void freeHero(Hero *H);

#endif
