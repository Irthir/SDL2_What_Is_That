#ifndef LISTEPOINT_H_INCLUDED
#define LISTEPOINT_H_INCLUDED
#pragma once

#include "point.h"
#include "cercle.h"

typedef struct tElementListePoint tElementListePoint;
struct tElementListePoint
{
    tPoint pPoint;
    tElementListePoint* pSuivant;
};

typedef struct tListePoint
//Un point en deux dimensions est un croisement de deux coordonnées en X et en Y.
{
    tElementListePoint* pDebut; //Pointeur sur le premier élément de la liste.
    int nTaille;
}tListePoint;


#endif
