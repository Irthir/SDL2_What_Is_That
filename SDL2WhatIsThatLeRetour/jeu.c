#include "jeu.h"

void JeuPrincipal(sdl_manager* SDLmanager, char* cImage, int** tMap)
//BUT : Gérer le jeu dans cette fonction qui contiendra
//ENTREE : Les inputs du joueurs qui vont agir sur le jeu.
//SORTIE : L'affichage du résultat des actions du joueur.
{
    const int FPS=30; //On veut 30 FPS dans notre affichage.
    unsigned long int nTempsActuel=0;
    unsigned long int nTempsPrecedent=0;
    int nDeltaTime = div(1000,FPS).quot;
    /*On prépare l'image du tileset.*/
    AppliquerImageSurface(SDLmanager,cImage); //On commence par charger l'image dans la surface grâce à la fonction IMG_Load de la SDL_Image.
    CreationTexture(SDLmanager); //On crée ensuite une texture de cette surface.


    int nFonctionnement=1; //L'entier de gestion du fonctionnement.
    int nXDecalage=0; //Pour l'animation.
    const int DECALAGEMAX=16*16*3; //nY ne doit pas dépasser 16 sinon on sort de notre écran.
    static int nPause=0;
    SDL_Event Evenement;

    while(nFonctionnement)
    {
        nTempsActuel = SDL_GetTicks(); //SDL_GetTicks renvoie le nombre de millisecondes depuis que la SDL a été initialisé.
        if (nTempsActuel > nTempsPrecedent + nDeltaTime)
        //On effectue l'affichage à chaque frame.
        {
            nTempsPrecedent = nTempsActuel;

            /*Inputs*/

            inputsJoueur(DECALAGEMAX,Evenement,&nXDecalage,&nFonctionnement,&nPause,1);


            /*Affichage*/
            NettoyerRendu(SDLmanager);

            Affichage(SDLmanager,nXDecalage, tMap);

            if (nPause==1)
            {
                AffichagePause(SDLmanager);
            }

            AfficherRendu(SDLmanager);

        }
    }
}


void Affichage(sdl_manager* SDLmanager, int nXDecalage, int** tMap)
{
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
    AppliquerImageSurface(SDLmanager,"Assets/PNG/Pause.png");
    CreationTexture(SDLmanager);
    CopierTextureSurRendu(SDLmanager,NULL,NULL);
}
