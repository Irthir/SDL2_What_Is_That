#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h" //Inclusion de la biblioth�que SDL

int main(int argc, char *argv[])//modification du main pour y ajouter un compteur d'arguments et un tableau de chaines.
{
    //Initialisation de trois pointeurs sur r�f�rence NULL pour pouvoir les manipuler par la suite.
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window poss�de la r�f�rence d'une window(win32)
    SDL_Renderer *pRenderer=NULL; //Pointeur typedef SDL_Renderer poss�de la r�f�rence du rendu encapsul� dans window.
    SDL_Texture *pTexture=NULL; //Pointeur typedef SDL_Texture poss�de la r�f�rence de l'objet image, mat�riel ou texture qui sera blitt� dans le rendu.
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
