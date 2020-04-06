#include "listePoint.h"


tListePoint CreatListePointCercle(tCercle cCercle)
//BUT : Pour dessiner un cercle, il nous faut l'ensemble des points qui composent ce cercle, donc créer un tableau de points.
//ENTREE : Le cercle à dessiner.
//SORTIE : La liste des points composant le périmètre de ce cercle.
{
    const int nDiametre = (cCercle.nRayon * 2);
    int nX = (cCercle.nRayon - 1);
    int nY = 0;
    int tX = 1;
    int tY = 1;
    int nErreur = (tX - nDiametre);
    int nI=0; //Pour l'incrément du tableau de points.
    int nCentreX=cCercle.pCentre.nX;
    int nCentreY=cCercle.pCentre.nY;

    tTabPoint tabPoint.tabPoint=malloc(sizeof(tPoint*));
    while (nX >= nY)
    {
        printf("Realloc : Taille = %d\n",sizeof(tPoint)*(nI+8));
        tTabPoint.tabPoint=realloc(tabPoint,sizeof(tPoint)*(nI+8));
        if (tabPoint==NULL)
            exit(EXIT_FAILURE);
        printf("Taille du tableau apres reallocation : %d\n",sizeof(tabPoint));
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX + nX, nCentreY - nY);
        nI++;
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX + nX, nCentreY + nY);
        nI++;
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX - nX, nCentreY - nY);
        nI++;
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX - nX, nCentreY + nY);
        nI++;
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX + nY, nCentreY - nX);
        nI++;
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX + nY, nCentreY + nX);
        nI++;
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX - nY, nCentreY - nX);
        nI++;
        tTabPoint.tabPoint[nI]=CreatPoint(nCentreX - nY, nCentreY + nX);
        nI++;
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
    tTabPoint.nTaille=nI;
    printf("Cercle dessine en theorie !\n");
    printf("Taille Finale : %d\n",sizeof(*tabPoint));
}
