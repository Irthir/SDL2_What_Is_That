#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#pragma once

typedef struct tPoint
//Un point en deux dimensions est un croisement de deux coordonnées en X et en Y.
{
    int nX;
    int nY;
}tPoint;

extern tPoint CreatPoint(int nX,int nY);
extern void tPointSetX(tPoint *pPoint, int nX);
extern void tPointSetY(tPoint *pPoint, int nY);
extern int tPointGetX(tPoint pPoint);
extern int tPointGetY(tPoint pPoint);

#endif 