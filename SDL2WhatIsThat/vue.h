#ifndef VUE_H_INCLUDED
#define VUE_H_INCLUDED
#pragma once

#include "modele.h"

extern void LesPoints();
extern void DessinerUnRectangle(sdl_manager *manager,SDL_Rect* rect);
extern void RemplirUnRectangle (sdl_manager *manager,SDL_Rect* rect);
extern void DessinerUnCercle(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon);
extern void DessinerUnDisque(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon);
extern void CouleurRendu(sdl_manager *manager,Uint8 nR,Uint8 nG,Uint8 nB,Uint8 nA);
extern void NettoyerRendu(sdl_manager *manager);
extern void AfficherRendu(sdl_manager *manager);
extern void CopierTextureSurRendu(sdl_manager *manager, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
extern void AfficherIconeFenetre(sdl_manager *manager);
extern void AppliquerImageBMPSurface(sdl_manager *manager, const char* sChemin);


#endif 