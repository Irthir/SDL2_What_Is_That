#include "AfficheForme.h"


void AfficheForme(tPoint* tabPoint,sdl_manager* manager)
//BUT : Afficher une forme passée en argument.
//ENTREE : Le tableau passé en argument peut être un tableau de points ou de segments.
//SORTIE : La forme géométrique affichée.
//NOTE : nAffiche sert à déterminer le type de pointeur passé en argument pour l'affichage 1 = points, 2 = lignes.
{
    int nMax=div(sizeof(tabPoint),sizeof(tabPoint[0])).quot;
    printf("nMax=%d\n",nMax);
    for (int nI = 0; nI <nMax ; nI++)
    {
        if (SDL_RenderDrawPoint(manager->pRenderer,tabPoint[nI].nX,tabPoint[nI].nY)<0)
        {
            printf("Le dessin du point aux positions %d,%d a echoue. Erreur : %s\n",tabPoint[nI].nX,tabPoint[nI].nY, SDL_GetError());
            return EXIT_FAILURE;
        }
        AfficherRendu(manager);
        SDL_Delay(100);
    }
}
