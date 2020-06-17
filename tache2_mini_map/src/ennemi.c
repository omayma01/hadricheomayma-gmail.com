#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "ennemi.h"
#include "background.h"
#include "hero.h"

int loadEnnemiImages(Ennemi * A)
{
	A->image = IMG_Load("../images/Ennemi.png");

	if(A->image == NULL) {
		printf("Unable to load Ennemi jpg:%s\n", SDL_GetError());
		return (-1);
	}

	SDL_SetColorKey( A->image, SDL_SRCCOLORKEY, SDL_MapRGB(A->image->format, 255, 255, 255) );

	return (0);
}



void initEnnemi(Ennemi* E)
{
	E->positionAbsolue.x = 1000;
	E->positionAbsolue.y = 250;
	E->positionAbsolue.w = Ennemi_WIDTH;
	E->positionAbsolue.h = Ennemi_HEIGHT;
	E->positionAnimation.x = 0;
	E->positionAnimation.y = 0;
	E->positionAnimation.w = Ennemi_WIDTH;
	E->positionAnimation.h = Ennemi_HEIGHT;
}
void blitEnnemi(Ennemi E, SDL_Surface* screen)
{
	SDL_BlitSurface(E.image, &E.positionAnimation, screen, &E.positionAbsolue);
}
void AnnimateEnnemi(Ennemi *E)
{
        E->positionAnimation.x += Ennemi_WIDTH;
	E->positionAnimation.x = E->positionAnimation.x % (Ennemi_WIDTH * 3);	
        E->positionAnimation.y = 0;
        SDL_Delay(100);
}
void MoveEnnemi(Ennemi *E)
{
        E->positionAbsolue.x -=10;    
}
	
void freeEnnemi(Ennemi *E)
{
	SDL_FreeSurface(E->image);
}




void deplacer_ennemiealiatoire(ennemie *e)
{
  if(-(e->o.x)+50==e->position.x)
    {
      e->Direction=0;
    }
  if(e->o.x+50==e->position.x)
    {
      e->Direction=0;
    }
  if(e->o.x-50==e->position.x)
  {
    e->Direction=1;
  }
if(-(e->o.x)-50==e->position.x)
  {
    e->Direction=1;
  }
  if(e->Direction==1)
  {
   e->image[0]=IMG_Load("just2.png");
   e->image[1]=IMG_Load("just2.png");
    e->position.x++;
  }
  if(e->Direction==0)
  {
  e->image[0]=IMG_Load("just.png");
  e->image[1]=IMG_Load("just.png");
    e->position.x--;
  }
}
void deplacer_ennemie(ennemie *e)
{
if(e->STATE==FOLLOWING)
 e->position.x--;
else if(e->STATE==FOLLOWING2)
 e->position.x++;
}
void UpdateEnnemi(ennemie *E,Hero A)
{
input(E,A);
switch (E->STATE)
{
case WAITING :
/*AnnimateEnnemi(E);*/
deplacer_ennemiealiatoire(E);
break;
case FOLLOWING :
deplacer_ennemie(E);
break;
case ATTACKING :
/*initEnnemi(E);
AnnimateEnnemi(E);*/
break;
}
}
void input(ennemie *E,Hero A)
{
if((A.positionAbsolue.x-E->position.x>250))
E->STATE=WAITING;
else if((E->position.x-A.positionAbsolue.x>250))
E->STATE=WAITING;
else if((E->position.x-A.positionAbsolue.x<250)&&(E->position.x>A.positionAbsolue.x))
E->STATE=FOLLOWING;
else if((E->position.x-A.positionAbsolue.x<250)&&(E->position.x<A.positionAbsolue.x))
E->STATE=FOLLOWING2;
else if(E->position.x-A.positionAbsolue.x==0)
E->STATE=ATTACKING;
}

void initialiser_ennemie(ennemie *e,SDL_Rect pos)
{
  //init image
    e->image[0]=IMG_Load("just.png");
    e->image[1]=IMG_Load("just.png");
  //init position
    e->o=pos;
    e->position=pos;
e->Direction=1;
}

void afficher_ennemie(ennemie e,SDL_Surface *screen)
{
  SDL_BlitSurface(e.image[0],NULL,screen,&e.position);

}
