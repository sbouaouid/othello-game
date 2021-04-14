#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "board.h"
#include "move.h"
#include "human_vs_human.h"
/* nbJoueur : retourne 1 ou 0 */
int nbJoueur()
{
    int x;
    x=rand()%2;
    return x;
}

/*PlayHumanVsHuman : retourne le joueur gagnant ; np1 ou np2 */
int PlayHumanVsHuman(int np1, int np2) //np1 : le joueur Noire, np2 : le joueur Blanc
{
    struct Grille *courant;
    struct Grille *nouveau;
    struct Position *move;
    int gameover=0;
    int win;
    courant=initGrille();
    while(!gameover){
		afficherGrille(courant);
		if(Plein(courant)|| nbPieces(courant,'0')==0 || nbPieces(courant,'1')==0 )
		{
		    gameover=1;
		    break;
		}

		do{
                if(bloque(courant,0))
                {
                    move->x=-1;
                    break;
                }//si le joueur '0' n'a aucun mouvement valide, on passe à '1'
                move=Mouvement(0);
                if(move->x==-1 )break;
                nouveau=placerPiece(*move,courant,0);
                free(move);
          }while(nouveau==NULL);
		if(move->x!=-1){
               free(courant);
               courant=nouveau;
		}
		afficherGrille(courant);
		if(Plein(courant)|| nbPieces(courant,'0')==0 || nbPieces(courant,'1')==0 )
		{
		    gameover=1;
		    break;
		}
		do{
                if(bloque(courant,1))
                {
                    move->x=-1;
                    break;
                }
               move=Mouvement(1);
			if(move->x==-1 )break;
			nouveau=placerPiece(*move,courant,1);
               free(move);
          }while(nouveau==NULL);
		if(move->x!=-1){
               free(courant);
               courant=nouveau;
		}
     }
	afficherGrille(courant);
	win=Gagnant(courant);
	if(win==0)
        return np1;
    else if (win==1)
        return np2;
    else return -1;

}
void congrats(int gagnant)
{
system("color 24");Sleep(200);system("color 21");Sleep(200);system("color 23");
Sleep(200);system("color 25");Sleep(200);system("color 26");Sleep(200);system("color 27");
Sleep(200);system("color 24");
system("color 24");Sleep(200);system("color 21");Sleep(200);system("color 23");
Sleep(200);system("color 25");Sleep(200);system("color 26");Sleep(200);system("color 27");
Sleep(200);system("color 20");
printf("\n\n\n\t\tFELICITATIONS JOUEUR %d ! VOUS AVEZ GAGNE\n\n\n\n\n\n",gagnant);
Sleep(1500);
return ;
}
void HumanVsHuman()
{
    int joueur1;
    int gagnant;
    srand(time(NULL));
    joueur1=nbJoueur();
    if(joueur1)
    {
        Sleep(500);
        printf("\n\n\t\t\tJoueur 1 a la couleur Blanc : '1'");
        Sleep(500);
        printf("\n\n\t\t\tJoueur 2 a la couleur Noir : '0'\n");
        Sleep(1000);
        printf("\n\n\t\t\tCliquez pour continuer ...");
        getch();
        gagnant=PlayHumanVsHuman(2,1);
    }
    else
    {
        Sleep(500);
        printf("\n\n\t\tJoueur 1 a la couleur Noir : '0'");
        Sleep(500);
        printf("\n\n\t\tJoueur 2 a la couleur Blanc : '1'\n");
        Sleep(1000);
        printf("\n\n\t\tCliquez pour continuer ...");
        getch();
        gagnant=PlayHumanVsHuman(1,2);
    }
    Sleep(1000);
    if(gagnant==-1) printf("\n\n\t\t\tPersonne n'a gagne\n\n");
    else congrats(gagnant);
    printf("\t\t\tCliquez pour continuez >>>>");
    getch();

}
