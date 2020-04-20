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
#include "affichage.h"

extern void JeuPrincipal(sdl_manager* SDLmanager, char* cImage, int** tMap);


#endif
