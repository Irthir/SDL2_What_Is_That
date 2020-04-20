#ifndef CONTROLLEURJOUEUR_H_INCLUDED
#define CONTROLLEURJOUEUR_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

extern SDL_Rect inputsJoueur(const int DECALAGEMAX,SDL_Event Evenement,int *nXDecalage, int *nFonctionnement, int *nPause, int nFrame,SDL_Rect rDestRect);

#endif
