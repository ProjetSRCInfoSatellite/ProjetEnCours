
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "interface_boutons.h"
#define X_BOUTON_START 1150
#define Y_BOUTON_START 722
#define X_BOUTON_STOP 1110
#define Y_BOUTON_STOP 722
#define HAUTEUR_BOUTON_FICHIER 30
#define LARGEUR_BOUTON_FICHIER 60


int main ( int argc, char** argv )
{

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    /* Creation nouvelle fenetre*/
    SDL_Surface* screen = SDL_SetVideoMode(1200, 750, 32,SDL_HWSURFACE);

    /* Declaration boutons */
    Bouton BoutonStart;
    Bouton BoutonStop;

     /* creation boutons*/
    create_button(&BoutonStart,X_BOUTON_START,Y_BOUTON_START,"Start");
    create_button(&BoutonStop,X_BOUTON_STOP,Y_BOUTON_STOP,"Stop");

    /* Creation Surface Proba*/
    SDL_Surface* FondProba=NULL;
    FondProba=SDL_LoadBMP("Fond_Proba.bmp");
    SDL_Rect positionFondProba;
    positionFondProba.x = 0;
    positionFondProba.y= 460;

    /*Creation BarreBoutons*/
    SDL_Surface* BarreBoutons=NULL;
    BarreBoutons=SDL_LoadBMP("BarreBoutons.bmp");
    SDL_Rect positionBarreBoutons;
    positionBarreBoutons.x = 0;
    positionBarreBoutons.y= 720;

    /*Creation BarreMenu*/
    SDL_Surface* BarreMenu=NULL;
    BarreMenu=SDL_LoadBMP("BarreMenu.bmp");
    SDL_Rect positionBarreMenu;
    positionBarreMenu.x = 0;
    positionBarreMenu.y= 0;



    int continuer =1;
    while (continuer)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_MOUSEBUTTONUP:
                if (   event.button.y >BoutonStart.Position.y
                  && event.button.y <= BoutonStart.Position.y+20 // +HAUTEUR
                  && event.button.x > BoutonStart.Position.x
                  && event.button.x <= BoutonStart.Position.x+20 ) //+LARGEUR
                {
                  /* CODE BOUTON START*/
                }

                if (   event.button.y >BoutonStop.Position.y
                    && event.button.y <= BoutonStop.Position.y+20 // +HAUTEUR
                    && event.button.x > BoutonStop.Position.x
                    && event.button.x <= BoutonStop.Position.x+20 ) //+LARGEUR
                {
                    // CODE BOUTON STOP
                }
                if (   event.button.y >0
                    && event.button.y <= HAUTEUR_BOUTON_FICHIER // +HAUTEUR
                    && event.button.x > 0
                    && event.button.x <= LARGEUR_BOUTON_FICHIER ) //+LARGEUR
                {

                }
                break;
            }
        }

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 240, 240,240));

        /* Affichage Boutons */


        SDL_BlitSurface(FondProba,NULL,screen,&positionFondProba);
        SDL_BlitSurface(BarreBoutons,NULL,screen,&positionBarreBoutons);
        SDL_BlitSurface(BarreMenu,NULL,screen,&positionBarreMenu);
        SDL_BlitSurface(BoutonStart.Surface,NULL,screen,&(BoutonStart.Position));
        SDL_BlitSurface(BoutonStop.Surface,NULL, screen,&(BoutonStop.Position));
        /* Mise à jour de l'écran*/
        SDL_Flip(screen);
    } /* FIN BOUCLE */

    // free loaded bitmap
    SDL_FreeSurface(BoutonStart.Surface);
    SDL_FreeSurface(BoutonStop.Surface);

    SDL_FreeSurface(FondProba);
    SDL_FreeSurface(BarreBoutons);


    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}

