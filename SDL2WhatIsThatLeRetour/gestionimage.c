#include "gestionimage.h"


void CouleurRendu(sdl_manager *manager,Uint8 nR,Uint8 nG,Uint8 nB,Uint8 nA)
//BUT : Modifier la couleur du rendu.
//ENTREE : Le rendu à initialiser, contenu dans le manager, ainsi que les couleurs.
//SORTIE : Le rendu initialisé et associé à la fenêtre.
{
	if (SDL_SetRenderDrawColor(manager->pRenderer, nR,nG,nB,nA)<0)
	{
		printf("Erreur dans la modification de la couleur du rendu : %s\n", SDL_GetError());
        return EXIT_FAILURE;
	}
}

void NettoyerRendu(sdl_manager *manager)
//BUT : Effacer le contenu du rendu et le remplacer par la couleur enregistrée pour le rendu actuellement.
//ENTREE : Le rendu à nettoyer contenu dans le manager.
//SORTIE : Le rendu du manager nettoyé.
{
	if (SDL_RenderClear(manager->pRenderer)<0)
	{
		printf("Erreur dans le nettoyage du rendu : %s\n", SDL_GetError());
        return EXIT_FAILURE;
	}
}

void AfficherRendu(sdl_manager *manager)
//BUT : Afficher le contenu du rendu.
//ENTREE : Le rendu à afficher contenu dans le manager.
//SORTIE : Le rendu du manager affiché.
{
	SDL_RenderPresent(manager->pRenderer);
}

void CopierTextureSurRendu(sdl_manager *manager, const SDL_Rect* srcrect, const SDL_Rect* dstrect)
//BUT : Copier la surface du manager sur le rendu du manager, ainsi que les deux rectangles source et de sortie.
//ENTREE : La surface et le rendu tous deux compris dans le manager.
//SORTIE : La surface est copiée dans le rendu.
{
	if (SDL_RenderCopy(manager->pRenderer,manager->pTexture,srcrect,dstrect)<0)
    {
        printf("La texture n'a pas pu etre copiee sur le rendu : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
}

void AfficherIconeFenetre(sdl_manager *manager)
//BUT : Appliquer une surface dans l'icone de la fenêtre.
//ENTREE : La fenêtre et la surface toutes deux comprises dans le manager.
//SORTIE : Le contenu de la surface appliqué à l'icone de la fenêtre.
{
	SDL_SetWindowIcon(manager->pWindow,manager->pSurface);
}

void AppliquerImageBMPSurface(sdl_manager *manager, const char* sChemin)
//BUT : Appliquer une image BMP dans une surface.
//ENTREE : La surface comprise dans le manager et le chemin de l'image BMP.
//SORTIE : L'image BMP appliquée à la surface.
{
	manager->pSurface=SDL_LoadBMP(sChemin);
	if (manager->pSurface==NULL)
    {
    	printf("Erreur lors de l'association de l'image a la surface : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void AppliquerImageSurface(sdl_manager *manager, const char* sChemin)
//BUT : Appliquer une image dans une surface grâce à la SDL_Image.
//ENTREE : La surface comprise dans le manager et le chemin de l'image.
//SORTIE : L'image appliquée à la surface.
{
    printf("Chemin : %s\n",sChemin);
    manager->pSurface=IMG_Load(sChemin);
    if (manager->pSurface==NULL)
    {
        printf("Erreur lors de l'association de l'image a la surface : %s",SDL_GetError());
        exit(EXIT_FAILURE);
    }
}
