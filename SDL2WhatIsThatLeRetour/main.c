#include "main.h"


int main(int argc, char *argv[])
{
    //Initialisation de la SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)//Si il n'y a pas d'erreur alors la SDL fonctionne.
    {
        printf("La SDL est initialisee !\n");
        sdl_manager* SDLmanager=SDL_ManagerInit();

        CreationFenetre(SDLmanager,1024,780,"SDL2 Partie2");

        CreationRendu(SDLmanager);

        Question3(SDLmanager,"Assets/PNG/Mouton.png"); //Réponse à la question 3.
        SDL_Delay(4000);

        Question5(SDLmanager,"Assets/PNG/helicoptere.png");
        SDL_Delay(500);

        //La map tirée de Tiled.
        int tMap[]=
        {
            75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
            75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
            75,75,66,67,75,75,75,75,75,75,75,75,75,75,75,75,
            75,75,73,74,75,75,75,75,75,75,75,75,75,75,75,75,
            75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
            75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,
            75,75,75,75,57,58,64,65,75,75,75,75,75,75,75,75,
            75,75,75,75,25,26,33,34,22,75,75,75,75,75,75,75,
            75,75,75,75,75,75,30,75,29,75,75,75,75,75,75,75,
            75,75,75,75,75,75,30,75,29,75,75,75,75,75,75,75,
            75,75,75,75,75,75,30,75,29,75,75,75,75,75,75,75,
            75,75,75,75,75,75,30,75,29,75,75,75,75,75,75,75,
            75,75,75,24,75,75,30,75,29,75,75,75,75,75,75,75,
            75,75,75,31,75,75,30,75,29,75,75,75,75,75,75,75,
            75,75,75,38,75,75,37,75,36,75,75,46,75,50,51,49,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
        };
        //NOTE La tileset est divisée sur 11 étages de 7 tuiles qui font 16x16 pixels
        //La 75ème tuile est donc à la onzième ligne et c'est la cinquième tuile en partant de la gauche.
        //Il n'y a pas de marge ni d'espace dans ce tileset.

        Question8(SDLmanager,"Assets/PNG/nature-paltformer-tileset-16x16.png",tMap);
        SDL_Delay(8000);

        LibererManager(SDLmanager);
    }
    SDL_Quit();//Fermeture de la SDL.
    printf("Fin de l'utilisation de la SDL.\n");

    printf("Fin du programme.\n");
    return 0;
}

void Question3(sdl_manager* SDLmanager, char* cImage)
//BUT : Charger une image au format png et l'afficher.
//ENTREE : La surface qui va charger l'image, la texture qui va être créée à partir de cette surface, le rendu sur lequel la texture sera affichée et le chemin vers l'image.
//SORTIE : L'image affichée à l'écran.
{
    printf("Question 3) Donnez un exemple de code en c chargeant une image de votre choix.\n");

    AppliquerImageSurface(SDLmanager,cImage); //On commence par charger l'image dans la surface grâce à la fonction IMG_Load de la SDL_Image.

    CreationTexture(SDLmanager); //On crée ensuite une texture de cette surface.

    NettoyerRendu(SDLmanager); //On nettoie le rendu.

    SDL_Rect sourceRect={0,0,0,0}; //On crée le rectangle source
    SDL_QueryTexture(SDLmanager->pTexture,NULL,NULL,&sourceRect.w,&sourceRect.h); //A partir des informations de la texture.
    int RenderW=0;
    int RenderH=0;
    if (SDL_GetRendererOutputSize(SDLmanager->pRenderer,&RenderW,&RenderH)<0) //On récupère la taille du rendu pour la comparer ensuite.
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


void Question5(sdl_manager* SDLmanager, char* cImage)
//BUT : Charger une image tileset au format png et l'afficher puis l'animer.
//ENTREE : Le manager et le chemin de l'image.
//SORTIE : L'image affichée et animée à l'écran.
{
    const int NBIMAGESTILESET=4; //Notre image est un tileset avec 4 images en hauteur.
    const int FPS=60; //On veut 60 FPS dans notre affichage.

    printf("Question 5) Creez une image animee dans votre fenetre.\n");

    AppliquerImageSurface(SDLmanager,cImage); //On commence par charger l'image dans la surface grâce à la fonction IMG_Load de la SDL_Image.

    CreationTexture(SDLmanager); //On crée ensuite une texture de cette surface.

    NettoyerRendu(SDLmanager); //On nettoie le rendu.

    SDL_Rect sourceRect={0,0,0,0}; //On crée le rectangle source
    SDL_QueryTexture(SDLmanager->pTexture,NULL,NULL,&sourceRect.w,&sourceRect.h); //A partir des informations de la texture.

    int nHauteurImage=div(sourceRect.h,NBIMAGESTILESET).quot; //Notre image est un tileset qui possède la même image 4 fois avec les changement d'animation en hauteur.
    sourceRect.h=nHauteurImage;

    int RenderW=0;
    int RenderH=0;
    if (SDL_GetRendererOutputSize(SDLmanager->pRenderer,&RenderW,&RenderH)<0) //On récupère la taille du rendu pour la comparer ensuite.
    {
        printf("Erreur lors de la recuperation de la taille du rendu : %s.\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (sourceRect.w<=RenderW && sourceRect.h<=RenderH) //A la taille de la texture et donc de l'image pour voir si le rendu est assez grand pour supporter l'image.
    {
        SDL_Rect destRect=sourceRect;
        printf("L'image peut s'afficher correctement, cliquez pour arreter l'animation.\n");

        unsigned long int nTempsActuel=0;
        unsigned long int nTempsPrecedent=0;
        int nDeltaTime = div(1000,FPS).quot; //On veut le temps d'une frame en milliseconde.
        int nAnimation=0;
        int nFonctionnement=1;

        //On met en place les évènements.
        SDL_Event Evenement;

        while(nFonctionnement)
        {
            nTempsActuel = SDL_GetTicks(); //SDL_GetTicks renvoie le nombre de millisecondes depuis que la SDL a été initialisé.
            if (nTempsActuel > nTempsPrecedent + nDeltaTime)
            //On effectue l'affichage à chaque frame.
            {
                while (SDL_PollEvent(&Evenement)) //Gestion des évènements.
                {
                    switch (Evenement.type)
                    {
                        case SDL_MOUSEMOTION :
                            printf("Souris deplacee en position : (%d, %d)\n", Evenement.motion.x, Evenement.motion.y);
                            destRect.x=Evenement.motion.x-div(destRect.w,2).quot;
                            destRect.y=Evenement.motion.y-div(destRect.h,2).quot;
                            break;
                        case SDL_MOUSEBUTTONDOWN :
                            printf("Clique de souris repere, fin de l'animation.\n");
                            nFonctionnement=0;
                            break;
                    }
                }

                nAnimation++; //notre nAnimation va aller de 0 à 3 pour mouvoir notre y sur la source sur les phases 1,2,3,4 pour faire notre animation.
                if (nAnimation==NBIMAGESTILESET)
                    nAnimation=0;

                nTempsPrecedent = nTempsActuel;
                NettoyerRendu(SDLmanager);
                sourceRect.y=nHauteurImage*(nAnimation%NBIMAGESTILESET);
                CopierTextureSurRendu(SDLmanager,&sourceRect,&destRect); //Si le rendu est assez grand, on lui met l'image au centre.
                AfficherRendu(SDLmanager); // Enfin, on affiche le rendu.
            }
        }
    }
    else
    {
    	//CopierTextureSurRendu(SDLmanager,NULL,NULL); //Si le rendu n'est pas assez grand, on applique l'image comme on peut dedans.
        printf("L'image est trop grande pour le rendue.\n");
    }
}


void Question8(sdl_manager* SDLmanager, char* cImage, int tMap[])
//BUT : Charger un tilemap et à partir d'un tableau map afficher la map à l'écran.
//ENTREE : Le manager, le chemin du tilemap et le tableau pour l'affichage.
//SORTIE : La carte affichée à l'écran.
{
    const int TAILLETUILE_H=16; //Nos tuiles font 16 pixels de haut.
    const int TAILLETUILE_L=16; //Nos tuiles font 16 pixels de large.
    const int NBTUILE_H=16; //Nous avons 16 tuiles en hauteur.
    const int NBTUILE_L=16; //Nous avons 16 tuiles en largeur.
    const int NBTUILELIGNE=7; //notre tilemap possède 7 tuiles par ligne.

    printf("Notre Tilemap est : \n");
    for (int nI=0; nI<16*16; nI++) //Affichage de notre tilemap.
    {
            printf("%2d,",tMap[nI]);
            if ((nI+1)%16==0)
                printf("\n");
    }
    AppliquerImageSurface(SDLmanager,cImage); //On commence par charger l'image dans la surface grâce à la fonction IMG_Load de la SDL_Image.

    CreationTexture(SDLmanager); //On crée ensuite une texture de cette surface.

    NettoyerRendu(SDLmanager); //On nettoie le rendu.

    SDL_Rect sourceRect={0,0,0,0}; //On crée le rectangle source
    SDL_QueryTexture(SDLmanager->pTexture,NULL,NULL,&sourceRect.w,&sourceRect.h); //A partir des informations de la texture.

    CopierTextureSurRendu(SDLmanager,&sourceRect,&sourceRect); //Si le rendu est assez grand, on lui met l'image au centre.
    AfficherRendu(SDLmanager);
    SDL_Delay(4000);

    //On a affiché notre tilemap, le tableau et l'image, affichons à présent le niveau.
    const int ZOOM=3;
    SDL_SetWindowSize(SDLmanager->pWindow,TAILLETUILE_H*NBTUILE_H*ZOOM,TAILLETUILE_L*NBTUILE_L*ZOOM); //On va afficher dans la fenêtre un niveau d'une taille de 16x16 carrés 16x16 pixels.

    if (SDL_SetRenderDrawColor(SDLmanager->pRenderer,0,191,255,255)<0) //On change le fond en bleu clair
	{
		printf("Erreur dans la modification de la couleur du rendu : %s\n", SDL_GetError());
        return EXIT_FAILURE;
	}
    NettoyerRendu(SDLmanager); //On nettoie le rendu.
    sourceRect.h=TAILLETUILE_H; //On donne à notre rectangle source la taille d'une tuile.
    sourceRect.w=TAILLETUILE_L;
    SDL_Rect destRect={0,0,TAILLETUILE_H*ZOOM,TAILLETUILE_L*ZOOM}; //On initialise notre rectangle de destination aux coordonnées 0,0 et à la taille 32,32 pour agrandir les tuiles affichées.

    for(int nI=0;nI<NBTUILE_H*NBTUILE_L;nI++) //Notre niveau fait 16 par 16 tuiles de 16 par 16 pixels.
    {
        sourceRect.x=(div(tMap[nI],NBTUILELIGNE).rem-1)*TAILLETUILE_L; //notre tilemap fait une largeur de 7 tuiles.
        sourceRect.y=(div(tMap[nI],NBTUILELIGNE).quot)*TAILLETUILE_H;

        destRect.x=(nI%NBTUILE_L)*TAILLETUILE_L*ZOOM;
        destRect.y=div(nI,NBTUILE_H).quot*TAILLETUILE_H*ZOOM;

        printf("Rectangle source Num :%d X=%d Y=%d.\n",nI,sourceRect.x,sourceRect.y);
        printf("Rectangle destination Num :%d X=%d Y=%d.\n",nI,destRect.x,destRect.y);
        CopierTextureSurRendu(SDLmanager,&sourceRect,&destRect);
        AfficherRendu(SDLmanager);
    }
}
