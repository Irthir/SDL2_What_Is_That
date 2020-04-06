#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED
#pragma once

#include "point.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct tCercle
{
	//Un cercle se définit par une coordonnée centrale et un rayon.
    tPoint pCentre;
    int nRayon;
}tCercle;

extern tCercle CreatCercle(tPoint pCentre,int nRayon);
extern void tCercleSetCentre(tCercle *pCercle, tPoint pCentre);
extern void tCercleSetRayon(tCercle *pCercle, int nRayon);
extern tPoint tCercleGetCentre(tCercle cCercle);
extern int tCercleGetRayon(tCercle cCercle);
extern tPoint* tCercleDessinerUnCercle(tCercle cCercle);

/*extern void DessinerUnCercle(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon);
extern void DessinerUnDisque(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon);*/


#endif
