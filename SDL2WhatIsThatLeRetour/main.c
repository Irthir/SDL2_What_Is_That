#include "main.h"


int main(int argc, char *argv[])
{
    //Initialisation de la SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)//Si il n'y a pas d'erreur alors la SDL fonctionne.
    {
        printf("La SDL est initialisee !\n");
        sdl_manager* SDLmanager;
        SDL_ManagerInit(SDLmanager);

        CreationFenetre(SDLmanager,1024,780,"SDL2 Partie2");

        CreationRendu(SDLmanager);

        Question3(SDLmanager,"Mouton.png"); //R�ponse � la question 3.

        SDL_Delay(4000);

        LibererManager(SDLmanager);

    }
    SDL_Quit();//Fermeture de la SDL.
    printf("Fin de l'utilisation de la SDL.\n");

    printf("Fin du programme.\n");
    return 0;
}

void Question3(sdl_manager* SDLmanager, char* cImage)
//BUT : Charger une image au format png et l'afficher.
//ENTREE : La surface qui va charger l'image, la texture qui va �tre cr��e � partir de cette surface, le rendu sur lequel la texture sera affich�e et le chemin vers l'image.
//SORTIE : L'image affich�e � l'�cran.
{
    printf("Question 3) Donnez un exemple de code en c chargeant une image de votre choix.\n");

    AppliquerImageSurface(SDLmanager,cImage); //On commence par charger l'image dans la surface gr�ce � la fonction IMG_Load de la SDL_Image.

    CreationTexture(SDLmanager); //On cr�e ensuite une texture de cette surface.

    NettoyerRendu(SDLmanager); //On nettoie le rendu.

    SDL_Rect sourceRect={0,0,0,0}; //On cr�e le rectangle source
    SDL_QueryTexture(SDLmanager->pTexture,NULL,NULL,&sourceRect.w,&sourceRect.h); //A partir des informations de la texture.
    int RenderW=0;
    int RenderH=0;
    if (SDL_GetRendererOutputSize(SDLmanager->pRenderer,&RenderW,&RenderH)<0) //On r�cup�re la taille du rendu pour la comparer ensuite.
    {
        printf("Erreur lors de la recuperation de la taille du rendu : %s.\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (sourceRect.w<=RenderW && sourceRect.h<=RenderH) //A la taille de la texture et donc de l'image pour voir si le rendu est assez grand pour supporter l'image.
    {
        SDL_Rect destRect=sourceRect;
        destRect.x=div(RenderW-destRect.w,2).quot;
        destRect.y=div(RenderH-destRect.h,2).quot;
        CopierTextureSurRendu(SDLmanager,&sourceRect,&destRect); //Si le rendu est assez grand, on lui met l'image au centre.
        printf("L'image a pu s'afficher correctement au centre du rendu.\n");
    }
    else
    {
    	CopierTextureSurRendu(SDLmanager,NULL,NULL); //Si le rendu n'est pas assez grand, on applique l'image comme on peut dedans.
        printf("L'image est trop grande pour le rendue et risque d'etre deformee.\n");
    }
    AfficherRendu(SDLmanager); // Enfin, on affiche le rendu.
}
