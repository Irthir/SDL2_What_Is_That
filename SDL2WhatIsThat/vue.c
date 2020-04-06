#include "vue.h"


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

void DessinerUnRectangle(sdl_manager *manager,SDL_Rect* rect)
//BUT : Dessiner un rectangle.
//ENTREE : Un rectangle SDL, le rendu pour le dessin.
//SORTIE : Le dessin du rectangle dans le rendu.
{
    if(SDL_RenderDrawRect(manager->pRenderer,rect)<0)
    {
        printf("Erreur lors de la creation d'un rectangle: %s",SDL_GetError());
        return EXIT_FAILURE;
    }
}

void RemplirUnRectangle (sdl_manager *manager,SDL_Rect* rect)
//BUT : Remplir un rectangle.
//ENTREE : Un rectangle SDL, le rendu pour l'affichage.
//SORTIE : Le remplissage d'un rectangle dans la fenêtre.
{
    if(SDL_RenderFillRect(manager->pRenderer,rect)<0)
    {
        printf("Erreur lors du remplissage d'un rectangle : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
}

void DessinerUnCercle(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon)
//BUT : Dessiner un cercle.
//ENTREE : Le rendu, les coordonnées du centre du cercle et le rayon.
//SORTIE : Le cercle affiché à l'écran.
{
    const int nDiametre = (nRayon * 2);
    int nX = (nRayon - 1);
    int nY = 0;
    int tX = 1;
    int tY = 1;
    int nErreur = (tX - nDiametre);

    while (nX >= nY)
    {
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nX, nCentreY - nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nX, nCentreY + nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nX, nCentreY - nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nX, nCentreY + nY);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nY, nCentreY - nX);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX + nY, nCentreY + nX);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nY, nCentreY - nX);
        SDL_RenderDrawPoint(manager->pRenderer, nCentreX - nY, nCentreY + nX);

        if (nErreur <= 0)
        {
            nY++;
            nErreur += tY;
            tY += 2;
        }
        if (nErreur > 0)
        {
            nX--;
            tX += 2;
            nErreur += (tX - nDiametre);
        }
    }
}


void DessinerUnDisque(sdl_manager *manager, int nCentreX, int nCentreY, int nRayon)
//BUT : Dessiner un disque.
//ENTREE : Le rendu, les coordonnées du centre du disque et le rayon.
//SORTIE : Le disque affiché à l'écran.
{
    int nDiametre = 3 - (2 * nRayon);
    int nX = 0;
    int nY = nRayon;

    while (nY >= nX)
    {
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nX, nCentreY - nY, nCentreX - nX +  2 * nX + 1, nCentreY - nY);
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nX, nCentreY + nY, nCentreX - nX +  2 * nX + 1, nCentreY + nY);
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nY, nCentreY - nX, nCentreX - nY +  2 * nY + 1, nCentreY - nX);
        SDL_RenderDrawLine(manager->pRenderer, nCentreX - nY, nCentreY + nX, nCentreX - nY +  2 * nY + 1, nCentreY + nX);

        if (nDiametre < 0)
            nDiametre = nDiametre + (4 * nX) + 6;
        else
        {
            nDiametre = nDiametre + 4 * (nX - nY) + 10;
            nY--;
        }
        nX++;
    }
}

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
    if (manager->pWindow!=NULL && manager->pSurface!=NULL)
    {
        SDL_SetWindowIcon(manager->pWindow,manager->pSurface);
    }
}

void AppliquerImageBMPSurface(sdl_manager *manager, const char* sChemin)
//BUT : Appliquer une image BMP dans une surface.
//ENTREE : La surface comprise dans le manager et le chemin de l'image BMP.
//SORTIE : L'image BMP appliquée à la surface.
{
    printf("Chargement image : %s.\n",sChemin);
	manager->pSurface=SDL_LoadBMP(sChemin);
	if (manager->pSurface==NULL)
    {
    	printf("Erreur lors de l'association de l'image a la surface : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
}
