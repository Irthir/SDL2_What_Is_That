#include "controlleurjoueur.h"

SDL_Rect inputsJoueur(const int DECALAGEMAX,SDL_Event Evenement,int *nXDecalage, int *nFonctionnement, int *nPause, int nFrame,SDL_Rect rDestRect)
{
    int nFrameActuelle=-1;
    while (SDL_PollEvent(&Evenement)) //Gestion des évènements.
    {
        if (Evenement.key.keysym.sym==SDLK_SPACE)
        {
            if (nFrameActuelle!=nFrame)
            {
                if (*nPause==1)
                {
                    *nPause=0;
                }
                else
                {
                    *nPause=1;
                }
            }
            nFrameActuelle=nFrame;
        }
        if (*nPause == 0)
        {
            switch (Evenement.type)
            {
                case SDL_KEYDOWN :
                    switch (Evenement.key.keysym.sym)
                    {
                        case SDLK_RIGHT :
                        case SDLK_d :
                            if (*nXDecalage<DECALAGEMAX-4)
                            {
                                *nXDecalage=(int)*nXDecalage+4;
                                //printf("Augmentation du X : %d\n",*nXDecalage);
                            }
                            else
                            {
                                //printf("X est a son maximum : %d\n",*nXDecalage);
                            }
                            break;
                        case SDLK_LEFT :
                        case SDLK_q :
                            if (*nXDecalage>3)
                            {
                                *nXDecalage=(int)*nXDecalage-4;
                                //printf("Reduction du X : %d\n",*nXDecalage);
                            }
                            else
                            {
                                //printf("X est a son minimum : %d\n",*nXDecalage);
                            }
                            break;
                        case SDLK_ESCAPE :
                            printf("Touche echap presse fin du jeu.\n");
                            *nFonctionnement=0;
                            break;
                        default :
                            break;
                    }
                case SDL_MOUSEMOTION :
                            rDestRect.x=Evenement.motion.x-div(rDestRect.w,2).quot;
                            rDestRect.y=Evenement.motion.y-div(rDestRect.h,2).quot;
                            break;
                default :
                    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
                    break;
            }
        }
    }
    return rDestRect;
}
