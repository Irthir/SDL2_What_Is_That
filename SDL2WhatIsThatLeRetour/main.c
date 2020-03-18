#include "main.h"


int main(int argc, char *argv[])
{
    //Initialisation de la SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)//Si il n'y a pas d'erreur alors la SDL fonctionne.
    {
        printf("La SDL est initialisee !\n");
        SDL_Window* pWindow=NULL;
        SDL_Renderer* pRenderer=NULL;
        SDL_Texture* pTexture=NULL;
        SDL_Surface* pSurface=NULL;

        pWindow=SDL_CreateWindow("MoutMout",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,780,1024,SDL_WINDOW_SHOWN);
        //On vérifie si la fenetre a ete cree correctement.
        if (pWindow == NULL)
        {
            // Si c'est le cas, la fenetre n'a pas ete creee.
            printf("La fenetre n'a pas pu etre creee: %s\n", SDL_GetError());
            return EXIT_FAILURE;
        }
        pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //On crée le rendu.
        if (pRenderer == NULL)
        {
            printf("Le rendu n'a pas pu etre cree: %s\n", SDL_GetError());
            return EXIT_FAILURE;
        }

        pSurface = IMG_Load("Mouton.png");
        if (!pSurface)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
            return 3;
        }
        pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
        if (!pTexture) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
            return 3;
        }

        if (SDL_RenderCopy(pRenderer,pTexture,NULL,NULL)<0)
        {
            printf("La texture n'a pas pu etre copiee sur le rendu : %s\n", SDL_GetError());
            return EXIT_FAILURE;
        }

        SDL_RenderPresent(pRenderer);

        SDL_Delay(4000);

        SDL_DestroyTexture(pTexture);
        printf("Texture finie.\n");
        //On libère les surfaces.
        SDL_FreeSurface(pSurface);
        printf("Surface liberee.\n");
        //On finit le rendu.
        SDL_DestroyRenderer(pRenderer);
        printf("Rendu fini.\n");
        //On ferme la fenetre.
        SDL_DestroyWindow(pWindow);
        printf("Fenetre fermee.\n");

    }
    SDL_Quit();//Fermeture de la SDL.
    printf("Fin de l'utilisation de la SDL.\n");

    printf("Fin du programme.\n");
    return 0;
}
