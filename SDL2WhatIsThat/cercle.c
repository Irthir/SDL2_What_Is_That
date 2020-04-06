#include "cercle.h"

tCercle CreatCercle(tPoint pCentre,int nRayon)
//BUT : Créer un cercle à partir d'un point et de son rayon.
//ENTREE : Le point centrale et le rayon.
//SORTIE : Le cercle de type tCercle créé.
{
    tCercle cCercle;
    cCercle.pCentre=pCentre;
    cCercle.nRayon=nRayon;
    return cCercle;
}

void tCercleSetCentre(tCercle *pCercle, tPoint pCentre)
//BUT : Changer le centre d'un cercle.
//ENTREE : Le cercle à modifier et le point qui sera son nouveau centre.
//SORTIE : Le cercle actualisé.
{
    pCercle->pCentre=pCentre;
}

void tCercleSetRayon(tCercle *pCercle, int nRayon)
//BUT : Changer le rayon d'un cercle.
//ENTREE : Le cercle à modifier et la valeur de son nouveau rayon.
//SORTIE : Le cercle actualisé.
{
    pCercle->nRayon=nRayon;
}

tPoint tCercleGetCentre(tCercle cCercle)
//BUT : Récupérer le point central d'un cercle.
//ENTREE : Le cercle dont on veut le centre.
//SORTIE : Le point central du cercle.
{
    return cCercle.pCentre;
}

int tCercleGetRayon(tCercle cCercle)
//BUT : Récupérer le rayon d'un cercle.
//ENTREE : Le cercle dont on veut le rayon.
//SORTIE : Le rayon du cercle.
{
    return cCercle.nRayon;
}


/*
void DessinerUnCercle(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon)
//BUT : Dessiner un cercle.
//ENTREE : Le rendu, les coordonnées du centre du cercle et le rayon.
//SORTIE : Le cercle affiché à l'écran.
{
    const int nDiametre = (nRayon * 2);
    int nX = (nRayon - 1);
    int nY = 0;
    int tX = 1;
    int tY = 1;
    int nErreur = (tX - nDiametre);

    while (nX >= nY)
    {
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nX, nCentreY - nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nX, nCentreY + nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nX, nCentreY - nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nX, nCentreY + nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nY, nCentreY - nX);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nY, nCentreY + nX);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nY, nCentreY - nX);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nY, nCentreY + nX);

        if (nErreur <= 0)
        {
            nY++;
            nErreur += tY;
            tY += 2;
        }
        if (nErreur > 0)
        {
            nX--;
            tX += 2;
            nErreur += (tX - nDiametre);
        }
    }
}


void DessinerUnDisque(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon)
//BUT : Dessiner un disque.
//ENTREE : Le rendu, les coordonnées du centre du disque et le rayon.
//SORTIE : Le disque affiché à l'écran.
{
    int nDiametre = 3 - (2 * nRayon);
    int nX = 0;
    int nY = nRayon;

    while (nY >= nX)
    {
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nX, nCentreY - nY, nCentreX - nX +  2 * nX + 1, nCentreY - nY);
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nX, nCentreY + nY, nCentreX - nX +  2 * nX + 1, nCentreY + nY);
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nY, nCentreY - nX, nCentreX - nY +  2 * nY + 1, nCentreY - nX);
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nY, nCentreY + nX, nCentreX - nY +  2 * nY + 1, nCentreY + nX);

        if (nDiametre < 0)
            nDiametre = nDiametre + (4 * nX) + 6;
        else
        {
            nDiametre = nDiametre + 4 * (nX - nY) + 10;
            nY--;
        }
        nX++;
    }
}
*/
