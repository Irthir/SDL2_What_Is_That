#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h" //Inclusion de la biblioth�que SDL

void LesPoints();
void AfficherUnRectangle(SDL_Renderer* renderer,SDL_Rect* rect);
void RemplirUnRectangle (SDL_Renderer* renderer,SDL_Rect* rect);
void DessinerUnCercle(SDL_Renderer * pRendu, int nCentreX, int nCentreY, int nRayon);
void DessinerUnDisque(SDL_Renderer * pRendu, int nCentreX, int nCentreY, int nRayon);

int main(int argc, char *argv[])//modification du main pour y ajouter un compteur d'arguments et un tableau de chaines.
{
    //Initialisation de trois pointeurs sur r�f�rence NULL pour pouvoir les manipuler par la suite.
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window poss�de la r�f�rence d'une window(win32)
    SDL_Renderer *pRenderer=NULL; //Pointeur typedef SDL_Renderer poss�de la r�f�rence du rendu encapsul� dans window.
    SDL_Texture *pTexture=NULL; //Pointeur typedef SDL_Texture poss�de la r�f�rence de l'objet image, mat�riel ou texture qui sera blitt� dans le rendu.
    //La SDL manipule des types.

    //Initialisation de la SDL.
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)//Si il n'y a pas d'erreur alors la SDL fonctionne.
    {
        printf("La SDL est initialisee !\n");

        printf("Creation de la fenetre.\n");
        pWindow=SDL_CreateWindow("SDL2WhatIsThat",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);

        //On v�rifie si la fenetre a ete cree correctement.
        if (pWindow == NULL)
        {
            // Si c'est le cas, la fenetre n'a pas ete creee.
            printf("La fenetre n'a pas pu etre creee: %s\n", SDL_GetError());
            return 1;
        }

        LesPoints();

        printf("Question 10) Quant aux SDL_Point et SDL_Rect.\n");
        SDL_Point monPoint={30,40};
        SDL_Rect monRectangle={5,5,100,200};
        printf("Mon point a comme coordonnees x=%d, y=%d.\n",monPoint.x,monPoint.y);
        printf("Mon Rectangle a comme point de depart : (%d,%d) et comme dimensions : Hauteur=%d Largeur=%d.\n",monRectangle.x,monRectangle.y,monRectangle.h,monRectangle.w);


        printf("Question 12) Donnez le code permettant d'afficher un fond rouge dans le rendu.\n");
        pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //On cr�e le rendu.
        SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255); //On change la couleur du rendu, ici on met du rouge.
        SDL_RenderClear(pRenderer); //On efface ce qu'on avait avant le rendu.
        SDL_RenderPresent(pRenderer); //On affiche le rendu     .
        LesPoints();
        SDL_Delay(2000);

        printf("Question 13) Dessiner dans le rendu : donnez le code des fonctions permettant de dessiner dans le rendu les formes suivantes : carre vide, carre plein, cercle vide, cercle plein.\n");
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //On change la couleur du rendu, ici on met du rouge.
        SDL_Rect tonRectangle={5,5,150,150};
        AfficherUnRectangle(pRenderer,&tonRectangle); //Affichage d'un carr� vide.
        tonRectangle.x=300;
        AfficherUnRectangle(pRenderer,&tonRectangle); //Affichage d'un carr� plein.
        RemplirUnRectangle (pRenderer,&tonRectangle);
        DessinerUnCercle(pRenderer, 105, 300, 100);//Affichage du cercle.
        DessinerUnDisque(pRenderer, 405, 300, 100);//Affichage d'un disque
        SDL_RenderPresent(pRenderer); //On affiche le rendu.
        LesPoints();
        SDL_Delay(4000);  //On met l'execution en pause pendant 4 secondes pour pouvoir voir la fenetre.

        //On finit le rendu.
        SDL_DestroyRenderer(pRenderer);
        printf("Rendu finit.\n");
        //On ferme la fenetre.
        SDL_DestroyWindow(pWindow);
        printf("Fenetre fermee.\n");
    }
    SDL_Quit();//Fermeture de la SDL.
    printf("Fin de l'utilisation de la SDL.\n");

    printf("Fin du programme.\n");
    return 0;
}

void LesPoints()
//BUT : Afficher des points pour structurer l'affichage dans la console.
//ENTREE : Rien.
//SORTIE : Des points affich�s.
{
    for (int nI=0; nI<=100; nI++)
    {
        printf("*");
    }
    printf("\n");
}

void AfficherUnRectangle(SDL_Renderer* renderer,SDL_Rect* rect)
//BUT : Afficher un rectangle.
//ENTREE : Un rectangle SDL, le rendu pour l'affichage.
//SORTIE : L'affichage du rectangle dans la fen�tre.
{
    if(SDL_RenderDrawRect(renderer,rect)<0)
    {
        printf("Erreur lors de la creation d'un rectangle: %s",SDL_GetError());
        return EXIT_FAILURE;
    }
}

void RemplirUnRectangle (SDL_Renderer* renderer,SDL_Rect* rect)
//BUT : Remplir un rectangle.
//ENTREE : Un rectangle SDL, le rendu pour l'affichage.
//SORTIE : Le remplissage d'un rectangle dans la fen�tre.
{
    if(SDL_RenderFillRect(renderer,rect)<0)
    {
        printf("Erreur lors du remplissage d'un rectangle : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
}

void DessinerUnCercle(SDL_Renderer * pRendu, int nCentreX, int nCentreY, int nRayon)
//BUT : Dessiner un cercle.
//ENTREE : Le rendu, les coordonn�es du centre du cercle et le rayon.
//SORTIE : Le cercle affich� � l'�cran.
{
    const int nDiametre = (nRayon * 2);
    int nX = (nRayon - 1);
    int nY = 0;
    int tX = 1;
    int tY = 1;
    int nErreur = (tX - nDiametre);

    while (nX >= nY)
    {
        SDL_RenderDrawPoint(pRendu, nCentreX + nX, nCentreY - nY);
        SDL_RenderDrawPoint(pRendu, nCentreX + nX, nCentreY + nY);
        SDL_RenderDrawPoint(pRendu, nCentreX - nX, nCentreY - nY);
        SDL_RenderDrawPoint(pRendu, nCentreX - nX, nCentreY + nY);
        SDL_RenderDrawPoint(pRendu, nCentreX + nY, nCentreY - nX);
        SDL_RenderDrawPoint(pRendu, nCentreX + nY, nCentreY + nX);
        SDL_RenderDrawPoint(pRendu, nCentreX - nY, nCentreY - nX);
        SDL_RenderDrawPoint(pRendu, nCentreX - nY, nCentreY + nX);

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


void DessinerUnDisque(SDL_Renderer * pRendu, int nCentreX, int nCentreY, int nRayon)
//BUT : Dessiner un disque.
//ENTREE : Le rendu, les coordonn�es du centre du disque et le rayon.
//SORTIE : Le disque affich� � l'�cran.
{
    int nDiametre = 3 - (2 * nRayon);
    int nX = 0;
    int nY = nRayon;

    while (nY >= nX)
    {
        SDL_RenderDrawLine(pRendu, nCentreX - nX, nCentreY - nY, nCentreX - nX +  2 * nX + 1, nCentreY - nY);
        SDL_RenderDrawLine(pRendu, nCentreX - nX, nCentreY + nY, nCentreX - nX +  2 * nX + 1, nCentreY + nY);
        SDL_RenderDrawLine(pRendu, nCentreX - nY, nCentreY - nX, nCentreX - nY +  2 * nY + 1, nCentreY - nX);
        SDL_RenderDrawLine(pRendu, nCentreX - nY, nCentreY + nX, nCentreX - nY +  2 * nY + 1, nCentreY + nX);

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
