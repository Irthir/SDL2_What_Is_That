#include "jeu.h"

void JeuPrincipal(sdl_manager* SDLmanager, char* cImage, int** tMap)
//BUT : Gérer le jeu dans cette fonction qui contiendra
//ENTREE : Les inputs du joueurs qui vont agir sur le jeu.
//SORTIE : L'affichage du résultat des actions du joueur.
{
    printf("Appuyez sur les touches flechees ou les touches 'q' et 'd' pour deplacer la camera,\n deplacez la souris pour deplacer l'helicoptere,\n appuyez sur la barre espace pour mettre en pause,\n appuyez sur la touche echap pour fermer le programme.\n");


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

    /*Gestion de l'affichage du joueur*/
    SDL_Rect rDestRect={0,0,135,94};
    int nAnimation=0;
    const int NBIMAGETILESET = 4;

    while(nFonctionnement)
    {
        nTempsActuel = SDL_GetTicks(); //SDL_GetTicks renvoie le nombre de millisecondes depuis que la SDL a été initialisé.
        if (nTempsActuel > nTempsPrecedent + nDeltaTime)
        //On effectue l'affichage à chaque frame.
        {
            nTempsPrecedent = nTempsActuel;

            nAnimation++;
            if (nAnimation>=NBIMAGETILESET)
            {
                nAnimation=0;
            }

            /*Inputs*/

            rDestRect=inputsJoueur(DECALAGEMAX,Evenement,&nXDecalage,&nFonctionnement,&nPause,1,rDestRect);


            /*Affichage*/

            NettoyerRendu(SDLmanager);

            Affichage(SDLmanager,nXDecalage, tMap);

            AffichageJoueur(SDLmanager,NBIMAGETILESET,nAnimation,rDestRect);

            if (nPause==1)
            {
                AffichagePause(SDLmanager);
            }

            AfficherRendu(SDLmanager);

        }
    }
}

