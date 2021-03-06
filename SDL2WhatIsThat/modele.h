#ifndef MODELE_H_INCLUDED
#define MODELE_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

typedef struct sdl_manager
{
	SDL_Window *pWindow ;
	SDL_Renderer *pRenderer ;
	SDL_Texture *pTexture ;
	SDL_Surface *pSurface ;
}sdl_manager;

extern void SDL_ManagerInit(sdl_manager* manager);
extern void CreationFenetre(sdl_manager *manager,const int nHauteur,const int nLargeur,const char* sTitre);
extern void CreationRendu(sdl_manager *manager);
extern void CreationSurface(sdl_manager *manager,const int nLargeur,const int nHauteur);
extern void CreationTexture(sdl_manager *manager);
extern void AssocierCibleRendu(sdl_manager *manager);
extern void DissocierCibleRendu(sdl_manager *manager);
extern void LibererManager(sdl_manager* manager);

#endif