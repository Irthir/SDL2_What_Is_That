#include "modele.h"

sdl_manager* SDL_ManagerInit()
//BUT : Initialiser le SDL_Manager et ses instances.
//ENTREE : Rien.
//SORTIE : Le SDL_Manager créé et initialisé.
{
    sdl_manager* manager = malloc(sizeof(sdl_manager*));
	manager->pWindow=NULL;
    manager->pRenderer=NULL;
    manager->pSurface=NULL;
    manager->pTexture=NULL;
    return manager;
}

void CreationFenetre(sdl_manager *manager,const int nHauteur,const int nLargeur,const char* sTitre)
//BUT : Créer une fenêtre
//ENTREE : Notre pointeur de fenêtre
//SORTIE : Une fenêtre créée, ou un message d'erreur en cas de problème
{
	manager->pWindow=SDL_CreateWindow(sTitre,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,nHauteur,nLargeur,SDL_WINDOW_SHOWN);
    //On vérifie si la fenetre a ete cree correctement.
    if (manager->pWindow == NULL)
    {
        // Si c'est le cas, la fenetre n'a pas ete creee.
        printf("La fenetre n'a pas pu etre creee: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
}

void CreationRendu(sdl_manager *manager)
//BUT : Créer un rendu.
//ENTREE : Le rendu à initialiser et la fenêtre associée, tous deux contenus dans le manager.
//SORTIE : Le rendu initialisé et associé à la fenêtre.
{
	manager->pRenderer = SDL_CreateRenderer(manager->pWindow, -1, SDL_RENDERER_ACCELERATED); //On crée le rendu.
	if (manager->pRenderer == NULL)
    {
        printf("Le rendu n'a pas pu etre cree: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
}

void CreationSurface(sdl_manager *manager,const int nLargeur,const int nHauteur)
//BUT : Créer une surface.
//ENTREE : La surface à initialiser contenue dans le manager, ainsi que sa largeur et sa hauteur.
//SORTIE : La surface initialisée.
{
	manager->pSurface = SDL_CreateRGBSurface(0,nLargeur,nHauteur,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
	if (manager->pSurface == NULL)
    {
        printf("La surface n'a pas pu etre cree: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
}


void CreationTexture(sdl_manager *manager)
//BUT : Créer une texture.
//ENTREE : La texture à créer, la surface depuis laquelle elle va être créée et le rendu correspondant, tous trois compris dans le manager.
//SORTIE : La texture créée
{
	manager->pTexture = SDL_CreateTextureFromSurface(manager->pRenderer,manager->pSurface);
	if (manager->pTexture == NULL)
    {
        printf("La texture n'a pas pu etre cree: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
}

void AssocierCibleRendu(sdl_manager *manager)
//BUT : Associer la texture sur le rendu pour pouvoir appliquer par la suite les fonctions de dessin sur la texture.
//ENTREE : La texture et le rendu tous deux compris dans le manager.
//SORTIE : La texture et le rendu du manager associés.
{
	if (SDL_SetRenderTarget(manager->pRenderer,manager->pTexture)<0)
	{
		printf("L'association de la texture sur le rendu a echouee : %s\n", SDL_GetError());
        return EXIT_FAILURE;
	}
}

void DissocierCibleRendu(sdl_manager *manager)
//BUT : Dissocier la texture du rendu pour pouvoir réappliquer les fonctions de dessin sur le rendu.
//ENTREE : Le rendu comprit dans le manager.
//SORTIE : Le rendu dissocié de la texture précédemment associée.
{
	if (SDL_SetRenderTarget(manager->pRenderer,NULL)<0)
	{
		printf("La dissociation de la texture sur le rendu a echouee : %s\n", SDL_GetError());
        return EXIT_FAILURE;
	}
}

void LibererManager(sdl_manager *manager)
//BUT : Mettre fin aux instances du manager.
//ENTREE : Le manager à libérer.
//SORTIE : Le manager nettoyé.
{
	//On finit la texture
	if (manager->pTexture!=NULL)
        SDL_DestroyTexture(manager->pTexture);
    printf("Texture finie.\n");
    //On libère les surfaces.
    if (manager->pSurface!=NULL)
        SDL_FreeSurface(manager->pSurface);
    printf("Surface liberee.\n");
    //On finit le rendu.
    if (manager->pRenderer!=NULL)
        SDL_DestroyRenderer(manager->pRenderer);
    printf("Rendu fini.\n");
    //On ferme la fenetre.
    if (manager->pWindow!=NULL)
        SDL_DestroyWindow(manager->pWindow);
    printf("Fenetre fermee.\n");
    //On libère le manager.
    if(manager!=NULL)
        free(manager);
    printf("Manager libere.\n");
}
