#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "gestionimage.h"
#include "modelemanager.h"


extern void Affichage(sdl_manager* SDLmanager, int nXDecalage, int** tMap);
extern void AffichagePause(sdl_manager *manager);
extern void AffichageJoueur (sdl_manager *SDLmanager, const int NBIMAGETILESET, int nAnimation, SDL_Rect destRect);
extern void NettoyageSurface (sdl_manager *SDLmananager);

#endif
