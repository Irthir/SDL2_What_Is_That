#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h" //Inclusion de la bibliothèque SDL

void LesPoints();

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

        printf("Creation de la fenetre.\n");
        pWindow=SDL_CreateWindow("SDL2WhatIsThat",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);

        //On vérifie si la fenetre a ete cree correctement.
        if (pWindow == NULL)
        {
            // Si c'est le cas, la fenetre n'a pas ete creee.
            printf("La fenetre n'a pas pu etre creee: %s\n", SDL_GetError());
            return 1;
        }

        LesPoints();

        printf("Question 10) Quant aux SDL_Point et SDL_Rect.\n");
        SDL_Point monPoint={30,40};
        SDL_Rect monRectangle={0,0,300,400};
        printf("Mon point a comme coordonnees x=%d, y=%d.\n",monPoint.x,monPoint.y);
        printf("Mon Rectangle a comme point de depart : (%d,%d) et comme dimensions : Largeur=%d Hauteur=%d.\n",monRectangle.x,monRectangle.y,monRectangle.h,monRectangle.w);
        LesPoints();

        printf("Question 12) Donnez le code permettant d'afficher un fond rouge dans le rendu.\n");

        pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //On crée le rendu.
        SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255); //On change la couleur du rendu, ici on met du rouge.
        SDL_RenderClear(pRenderer); //On actualise le rendu.
        SDL_RenderPresent(pRenderer); //On affiche le rendu.

        SDL_Delay(4000);  //On met l'execution en pause pendant 4 secondes pour pouvoir voir la fenetre.

        //On ferme la fenetre.
        SDL_DestroyWindow(pWindow);
        printf("Fenetre fermee.\n");
    }
    SDL_Quit();//Fermeture de la SDL.
    printf("Fin de l'utilisation de la SDL.\n");

    printf("Fin du programme.\n");
    return 0;
}

void LesPoints()
//BUT : Afficher des points pour structurer l'affichage dans la console.
//ENTREE : Rien.
//SORTIE : Des points affichés.
{
    for (int nI=0; nI<=100; nI++)
    {
        printf("*");
    }
    printf("\n");
}
