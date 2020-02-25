#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window poss�de la r�f�rence d'une window(win32)
    SDL_Renderer *pRenderer=NULL; //Pointeur typedef SDL_Renderer poss�de la r�f�rence du rendu encapsul� dans window.

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
        //Si l'initialisation marche on cr�e notre fen�tre.
        //On cr�e le pointeur sur la r�f�rence de la fen�tre Win32.
        pWindow=SDL_CreateWindow("SDL2WhatIsThat",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);
        //https://wiki.libsdl.org/SDL_CreateWindow

        //En cas de succ�s de cr�ation de la fen�tre, cr�er un rendu.
        //Si la fen�tre est cr��e.
        if(pWindow!=NULL)
        {
            //Cr�ation du rendu encapsul� dans la fen�tre point�e par pWindow.
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
        }

        //Traitement de l'affichage.
        //Set de la couleur du traitement.
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        //Effaceemnt de l'�tat precedent du renderer.
        SDL_RenderClear(pRenderer);
        //Affiche l'�tat du nouveau rendu.
        SDL_RenderPresent(pRenderer);
        //Fin du traitement de l'affichage.

        //Synchronisation et rafraichissement d'affichage des frames � l'�cran.
        SDL_Delay(4000);
    }
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return 0;
}
