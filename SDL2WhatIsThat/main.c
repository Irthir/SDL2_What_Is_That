#include "modele.h"
#include "vue.h"
#include "AfficheForme.h"
#include "cercle.h"


int main(int argc, char *argv[])
{
    //Initialisation de la SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)//Si il n'y a pas d'erreur alors la SDL fonctionne.
    {
        printf("La SDL est initialisee !\n");

	    sdl_manager *manager=malloc(sizeof(sdl_manager*));
	    SDL_ManagerInit(manager);

        printf("Creation de la fenetre.\n");
        CreationFenetre(manager,1024,780,"SDL2WhatIsThat");
        LesPoints();

        printf("Question 10) Quant aux SDL_Point et SDL_Rect.\n");
        SDL_Point monPoint={30,40};
        SDL_Rect monRectangle={5,5,100,200};
        printf("Mon point a comme coordonnees x=%d, y=%d.\n",monPoint.x,monPoint.y);
        printf("Mon Rectangle a comme point de depart : (%d,%d) et comme dimensions : Hauteur=%d Largeur=%d.\n",monRectangle.x,monRectangle.y,monRectangle.h,monRectangle.w);
        LesPoints();

        printf("Question 12) Donnez le code permettant d'afficher un fond rouge dans le rendu.\n");
        CreationRendu(manager); //On crée notre rendu.
        CouleurRendu(manager,255, 0, 0, 255);//On change la couleur du rendu, ici on met du rouge.
        NettoyerRendu(manager); //On efface ce qu'on avait avant le rendu.
        AfficherRendu(manager); //On affiche le rendu.
        LesPoints();
        SDL_Delay(2000);

        printf("Question 13) Dessiner dans le rendu : donnez le code des fonctions permettant de dessiner dans le rendu les formes suivantes : carre vide, carre plein, cercle vide, cercle plein.\n");
        CouleurRendu(manager, 0, 0, 0, 255); //On change la couleur du rendu, ici on met du rouge.
        SDL_Rect tonRectangle={5,5,150,150};
        DessinerUnRectangle(manager,&tonRectangle); //Affichage d'un carré vide.
        tonRectangle.x=300;
        DessinerUnRectangle(manager,&tonRectangle); //Affichage d'un carré plein.
        RemplirUnRectangle (manager,&tonRectangle);
        //tCercle cCercle=CreatCercle(CreatPoint(105,300),100);
        DessinerUnCercle(manager, 105, 300, 100);//Affichage du cercle.
        DessinerUnDisque(manager, 405, 300, 100);//Affichage d'un disque
        AfficherRendu(manager); //On affiche le rendu.
        LesPoints();
        SDL_Delay(4000);  //On met l'execution en pause pendant 4 secondes pour pouvoir voir la fenetre.

        printf("Question 19) Dessiner dans une surface : Donnez le code de la fonction SDL_FillRect.\n");
        NettoyerRendu(manager);
        CreationSurface(manager,500,500);//On crée notre surface.
        SDL_FillRect(manager->pSurface,NULL,SDL_MapRGB(manager->pSurface->format,0,255,0)); //On remplit la surface d'un rectangle vert.

        //Il s'agit là du test de l'affichage de la surface après la question 19.
        CreationTexture(manager); //On met la surface dans une texture pour l'afficher.
        CopierTextureSurRendu(manager,NULL,NULL); //On copie la totalité de la texture sur la totalité du rendu.
        AfficherRendu(manager);
        LesPoints();
        SDL_Delay(4000);

        printf("Question 20) SDL_BlitSurface(..) : donnez le code pour tester cette méthode.\n");
        //Avant de remettre notre surface verte sur le rendu, on va réinitialiser le rendu.
        NettoyerRendu(manager);
        AfficherRendu(manager); //Et l'afficher 2 secondes pour que ce soit visible.
        SDL_Delay(2000);
        SDL_Surface *pWindowSurface=NULL; //Pointeur typedef SDL_Surface que l'on va utiliser pour la fenêtre.
        pWindowSurface=SDL_GetWindowSurface(manager->pWindow);
        if (pWindowSurface==NULL)
        {
        	printf("Erreur lors de l'utilisation de la recuperation de la surface de la fenetre : %s",SDL_GetError());
            return EXIT_FAILURE;
        }
        if(SDL_BlitSurface(manager->pSurface,NULL,pWindowSurface,NULL)<0)//On test la fonction Blitsurface.
        {
            printf("Erreur lors de l'utilisation de la fonction BlitSurface: %s",SDL_GetError());
            return EXIT_FAILURE;
        }
        if (SDL_UpdateWindowSurface(manager->pWindow)<0)//Et on actualise la fenêtre pour afficher notre merveilleux vert !
        {
            printf("Erreur lors de l'utilisation de la fonction UpdateWindowSurface: %s",SDL_GetError());
            return EXIT_FAILURE;
        }
        LesPoints();
        SDL_Delay(4000);

        NettoyerRendu(manager);
        AfficherRendu(manager);
        printf("Question 22) Dessinez dans une texture : SDL_RenderTarget, donnez le code pour tester cette methode.\n");
        AssocierCibleRendu(manager); //On met la texture en cible des fonctions de dessins du rendu.
        DessinerUnDisque(manager,155,155,150);
        AfficherRendu(manager);
        LesPoints();
        SDL_Delay(2000);

        printf("Question 23) SDL_RenderCopy : A quoi sert cette methode, donnez le code pour tester cette methode.\n");
        CopierTextureSurRendu(manager,NULL,NULL);
        AfficherRendu(manager);
        DissocierCibleRendu(manager); //On met fin au rendertarget.
        LesPoints();
        SDL_Delay(4000);

        printf("Question 24) SQL_QueryTexture : A quoi sert cette methode, donnez le code pour tester cette methode.\n");
        int nLargeur=0;
        int nHauteur=0;
        SDL_QueryTexture(manager->pTexture,NULL,NULL,&nLargeur,&nHauteur);
        monRectangle.x=0;
        monRectangle.y=0;
        monRectangle.w=nLargeur;
        monRectangle.h=nLargeur;
        NettoyerRendu(manager);
        CopierTextureSurRendu(manager,&monRectangle,&monRectangle);
        AfficherRendu(manager);
        LesPoints();
        SDL_Delay(4000);

        printf("Question 25) Les Images : La SDL2 et SDL_LoadBMP.\n");
        AppliquerImageBMPSurface(manager,"Assets/BMP/CirnoIcone.bmp");
        AfficherIconeFenetre(manager);
        LesPoints();
        SDL_Delay(4000);

        printf("Question 26) et 27) Creer une texture a partir d'une image, puis afficher l'image.\n");
        NettoyerRendu(manager);
        AppliquerImageBMPSurface(manager,"Assets/BMP/Cirno.bmp");
        CreationTexture(manager);
        SDL_QueryTexture(manager->pTexture,NULL,NULL,&nLargeur,&nHauteur);
        monRectangle.w=nLargeur;
        monRectangle.h=nHauteur;
        CopierTextureSurRendu(manager,&monRectangle,&monRectangle);
        AfficherRendu(manager);
        LesPoints();
        SDL_Delay(4000);


		printf("Question 28) Liberer les instances de la SDL2.\n");
        SDL_FreeSurface(pWindowSurface);
        printf("Surface liberee.\n");
        LibererManager(manager);
    }
    else
    {
    	printf("Erreur lors de l'initialisation de la SDL : %s.\n",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Quit();//Fermeture de la SDL.
    printf("Fin de l'utilisation de la SDL.\n");

    printf("Fin du programme.\n");
    return 0;
}
