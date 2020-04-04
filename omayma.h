#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include"perso.h"

typedef struct {
SDL_Surface *entite; 
SDL_Rect animation_entite[60];
SDL_Rect entite_pos;
int type;
int col;
int frame_entite;
}entite ;
void init_tab_anim_entite(SDL_Rect* clip); 
void initialiser_entite (entite *e) ;
void afficher_entite(entite * e , SDL_Surface *screen);
void anim(entite *e);
void mvt_entite(entite *e);
void detect_collision(personnage p, entite e);

#endif
