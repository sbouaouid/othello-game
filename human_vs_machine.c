#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "board.h"
#include "move.h"
#include "human_vs_machine.h"

/*premierMOuvementValid :  retourne le premier mouvement valide pur '1' dans la grille 'courant*/
struct Position *premierMouvementValid(struct Grille *courant ){
	int i,j; struct Position *move;
	move=malloc(sizeof(struct Position));
	move->x=-1;
	move->y=-1;
	for(i=0;i<XMAX;i++)
        for(j=0;j<YMAX;j++){
            if(courant->othello[i][j]==' ')
            {
                move->x=i; move->y=j;
                if(mouvementValid(courant,*move,1))
                    return move;

            }
            }
	return move;

}
struct Position *Machine(int n, char tour, struct Grille *courant, int niveau){
	struct Position move;
	struct Position *meilleur;
	struct Position *pire;
	struct Grille *nouveau=NULL;
	meilleur = malloc(sizeof(struct Position));
	meilleur->x=-1;
	meilleur->y=-1;
	if(tour)meilleur->score=100;
	else meilleur->score=0;
	if (n == niveau){
		meilleur->score=nbPieces(courant,'0');
		return(meilleur);
	}
	for(move.x=0;move.x<XMAX;move.x++)
		for(move.y=0;move.y<YMAX;move.y++){
			if((nouveau=placerPiece(move,courant,tour))!=NULL){
				pire = Machine(n+1,!tour,nouveau,niveau);
				if(tour && pire->score < meilleur->score){
					meilleur->score=pire->score;
					meilleur->x=move.x;
					meilleur->y=move.y;
				}else if(!tour && pire->score > meilleur->score)
					meilleur->score=pire->score;
                    free(nouveau);
                    free(pire);
               }
		}
	return(meilleur);
}
int PlayHumanVsMachine(int niveau)
{
    struct Grille *courant;
    struct Grille *new;
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
                }
                move=Mouvement(0);
                if(move->x==-1 )break;
                new=placerPiece(*move,courant,0);
                free(move);
          }while(new==NULL);
		if(move->x!=-1){
               free(courant);
               courant=new;
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
            Sleep(1000);
            if(niveau==0)
                move=premierMouvementValid(courant);
            else
                move=Machine(0,1,courant,niveau);
			if(move->x==-1 )break;
			new=placerPiece(*move,courant,1);
               free(move);
          }while(new==NULL);
		if(move->x!=-1){
               free(courant);
               courant=new;
		}
     }
	win=Gagnant(courant);
	return win;

}
void Congrats()
{
system("color 24");Sleep(200);system("color 21");Sleep(200);system("color 23");
Sleep(200);system("color 25");Sleep(200);system("color 26");Sleep(200);system("color 27");
Sleep(200);system("color 24");
system("color 24");Sleep(200);system("color 21");Sleep(200);system("color 23");
Sleep(200);system("color 25");Sleep(200);system("color 26");Sleep(200);system("color 27");
Sleep(200);system("color 20");
printf("\n\n\n\t\tFELICITATIONS ! VOUS AVEZ GAGNE\n\n\n\n\n\n");
Sleep(1500);
return ;
}
void HumanVsMachine(int niveau)
{
    int gagnant;
    gagnant=PlayHumanVsMachine(niveau);
    if(gagnant==1) printf("\n\n\t\t\tLa machine a gagne !!\n\n");
    else if (gagnant==0) Congrats();
    else if (gagnant==-1) printf("\n\n\t\t\tPersonne n'a gagne !!!\n");
    getch();
}
