#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h" //Inclusion de la bibliothèque SDL

int main(int argc, char *argv[])//modification du main pour y ajouter un compteur d'arguments et un tableau de chaines.
{
    //Initialisation de trois pointeurs sur référence NULL pour pouvoir les manipuler par la suite.
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'une window(win32)
    SDL_Renderer *pRenderer=NULL; //Pointeur typedef SDL_Renderer possède la référence du rendu encapsulé dans window.
    SDL_Texture *pTexture=NULL; //Pointeur typedef SDL_Texture possède la référence de l'objet image, matériel ou texture qui sera blitté dans le rendu.
    //La SDL manipule des types.

    //Initialisation de la SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)//Si il n'y a pas d'erreur alors la SDL fonctionne.
    {
        printf("La SDL est initialisee !\n");
    }
    SDL_Quit();//Fermeture de la SDL.
    printf("Fin de l'utilisation de la SDL.\n");

    printf("Fin du programme.\n");
    return 0;
}
