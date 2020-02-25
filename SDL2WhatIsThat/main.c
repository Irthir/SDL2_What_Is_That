#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'une window(win32)
    SDL_Renderer *pRenderer=NULL; //Pointeur typedef SDL_Renderer possède la référence du rendu encapsulé dans window.

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
        //Si l'initialisation marche on crée notre fenêtre.
        //On crée le pointeur sur la référence de la fenêtre Win32.
        pWindow=SDL_CreateWindow("SDL2WhatIsThat",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);
        //https://wiki.libsdl.org/SDL_CreateWindow

        //En cas de succès de création de la fenêtre, créer un rendu.
        //Si la fenêtre est créée.
        if(pWindow!=NULL)
        {
            //Création du rendu encapsulé dans la fenêtre pointée par pWindow.
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
        }

        //Traitement de l'affichage.
        //Set de la couleur du traitement.
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        //Effaceemnt de l'état precedent du renderer.
        SDL_RenderClear(pRenderer);
        //Affiche l'état du nouveau rendu.
        SDL_RenderPresent(pRenderer);
        //Fin du traitement de l'affichage.

        //Synchronisation et rafraichissement d'affichage des frames à l'écran.
        SDL_Delay(4000);
    }
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return 0;
}
