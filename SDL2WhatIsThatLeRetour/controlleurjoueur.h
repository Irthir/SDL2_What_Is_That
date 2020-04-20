#ifndef CONTROLLEURJOUEUR_H_INCLUDED
#define CONTROLLEURJOUEUR_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

void inputsJoueur(const int DECALAGEMAX,SDL_Event Evenement,int *nXDecalage, int *nFonctionnement, int *nPause, int nFrame);

#endif
