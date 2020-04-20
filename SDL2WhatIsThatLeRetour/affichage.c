#include "affichage.h"


void Affichage(sdl_manager* SDLmanager, int nXDecalage, int** tMap)
{
    NettoyageSurface (SDLmanager);
    AppliquerImageSurface(SDLmanager,"Assets/PNG/nature-paltformer-tileset-16x16.png");
    CreationTexture(SDLmanager);
    int nAffichageX = div(nXDecalage,16*3).quot;

    const int TAILLETUILE_H=16; //Nos tuiles font 16 pixels de haut.
    const int TAILLETUILE_L=16; //Nos tuiles font 16 pixels de large.
    const int NBTUILE_H=16; //Nous avons 16 tuiles en hauteur.
    const int NBTUILE_L=16; //Nous avons 16 tuiles en largeur.
    const int NBTUILELIGNE=7; //notre tilemap possède 7 tuiles par ligne.
    const int ZOOM=3; //On zoom par trois notre image.

    SDL_Rect sourceRect={0,0,0,0}; //On crée le rectangle source
    sourceRect.h=TAILLETUILE_H; //On donne à notre rectangle source la taille d'une tuile.
    sourceRect.w=TAILLETUILE_L;
    SDL_Rect destRect={0,0,TAILLETUILE_H*ZOOM,TAILLETUILE_L*ZOOM};



    for(int nJ=0;nJ<NBTUILE_H;nJ++) //Notre niveau fait 16 par 16 tuiles de 16 par 16 pixels.
    {
        for (int nI=0+nAffichageX; nI<NBTUILE_L+nAffichageX+1;nI++)
        {
            sourceRect.x=(div(tMap[nI][nJ],NBTUILELIGNE).rem-1)*TAILLETUILE_L; //notre tilemap fait une largeur de 7 tuiles.
            sourceRect.y=(div(tMap[nI][nJ],NBTUILELIGNE).quot)*TAILLETUILE_H;

            destRect.x=nI*TAILLETUILE_L*ZOOM-nXDecalage;
            destRect.y=nJ*TAILLETUILE_H*ZOOM;

            CopierTextureSurRendu(SDLmanager,&sourceRect,&destRect);
        }
    }
}

void AffichagePause(sdl_manager *SDLmanager)
{
    NettoyageSurface (SDLmanager);
    AppliquerImageSurface(SDLmanager,"Assets/PNG/Pause.png");
    CreationTexture(SDLmanager);
    CopierTextureSurRendu(SDLmanager,NULL,NULL);
}

void AffichageJoueur (sdl_manager *SDLmanager,const int NBIMAGETILESET, int nAnimation, SDL_Rect destRect)
{
    NettoyageSurface (SDLmanager);
    AppliquerImageSurface(SDLmanager,"Assets/PNG/helicoptere.png");
    CreationTexture(SDLmanager);

    SDL_Rect sourceRect={0,0,0,0}; //On crée le rectangle source
    SDL_QueryTexture(SDLmanager->pTexture,NULL,NULL,&sourceRect.w,&sourceRect.h); //A partir des informations de la texture.
    int nHauteurImage=div(sourceRect.h,NBIMAGETILESET).quot; //Notre image est un tileset qui possède la même image 4 fois avec les changement d'animation en hauteur.
    sourceRect.h=nHauteurImage;
    sourceRect.y=nHauteurImage*(nAnimation%NBIMAGETILESET);

    CopierTextureSurRendu(SDLmanager,&sourceRect,&destRect);
}

void NettoyageSurface (sdl_manager *SDLmananager)
//BUT : Eviter les réécritures constante sur la surface et un dépassement de mémoire.
{
    free(SDLmananager->pSurface);
    SDLmananager->pSurface=malloc(sizeof(SDL_Surface));
}
