#ifndef VUE_H_INCLUDED
#define VUE_H_INCLUDED
#pragma once

#include "modele.h"

extern void CouleurRendu(sdl_manager *manager,Uint8 nR,Uint8 nG,Uint8 nB,Uint8 nA);
extern void NettoyerRendu(sdl_manager *manager);
extern void AfficherRendu(sdl_manager *manager);
extern void CopierTextureSurRendu(sdl_manager *manager, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
extern void AfficherIconeFenetre(sdl_manager *manager);
extern void AppliquerImageBMPSurface(sdl_manager *manager, const char* sChemin);

#endif