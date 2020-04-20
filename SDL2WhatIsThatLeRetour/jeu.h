#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "modelemanager.h"
#include "gestionimage.h"
#include "controlleurjoueur.h"

void JeuPrincipal(sdl_manager* SDLmanager, char* cImage, int** tMap);
void Affichage(sdl_manager* SDLmanager, int nXDecalage, int** tMap);
void AffichagePause(sdl_manager *manager);


#endif
