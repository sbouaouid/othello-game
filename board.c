#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "board.h"
void Color(int couleurDuTexte,int couleurDeFond) //fonction d'affichage des couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void afficherGrille(struct Grille *courant )
{
    int i,j;
    system("cls");
    printf("\n\tScore :          '0'=%d             '1'=%d\n",nbPieces(courant,'0'),nbPieces(courant,'1'));
	printf("\n\t\t   ");Color(10,2);
	for(i=0;i<XMAX;i++)
        printf("%2c  ",'A'+i);
    printf("\n\t\t   +---+---+---+---+---+---+---+---+");

	 putchar('\n');
	for(j=0;j<YMAX;j++){printf("\t\t");
		printf("%2d |",j);
		for(i=0;i<XMAX;i++){
		if(courant->othello[i][j]=='1'){
				Color(15,2);
			printf(" %c ",courant->othello[i][j]);
		    Color(10,2);
		    printf("|");

		}else {
		Color(0,2);
		printf(" %c ",courant->othello[i][j]);
		Color(10,2);printf("|");}}

		 printf("\n");printf("\t\t   +---+---+---+---+---+---+---+---+\n");
	}
	Color(0,2);
}
/*initGrille : retourne une grille vide dont les quatre cases de centre sont remplies*/
struct Grille *initGrille(void){
	int i,j;
	struct Grille *nouveau;
	nouveau=malloc(sizeof(struct Grille));
     /*beta++;*/
     for(j=0;j<YMAX;j++)
		for(i=0;i<XMAX;i++)
			nouveau->othello[i][j]=' ';

	nouveau->othello[3][3]='1';
	nouveau->othello[3][4]='0';
	nouveau->othello[4][3]='0';
	nouveau->othello[4][4]='1';
	return(nouveau);
}
/*Plein : retourne Vrai(1) si la grille "courant" est pleine; aucune case n'est vide */
int Plein(struct Grille *courant)
{
     int i, j;
     for(i=0; i<XMAX; i++)
          for(j=0; j<YMAX; j++)
               if(courant->othello[i][j] == ' ') // S'il y a au moins une case vide, Plein retourne Faux(0)
                    return 0;
     return 1;
}
/*nbPieces : retourne le nombre de pieces de la couleur "c" dans la grille "courant" */
int nbPieces(struct Grille *courant,char c){
	int i,j;
	int total=0;
	for(j=0;j<YMAX;j++)
		for(i=0;i<XMAX;i++)
			if(courant->othello[i][j]==c)total++;
	return(total);
}
/*Gagnant : retourne le nombre du joueur gagnant (0 pour le noir, 1 pour le blanc, et -1 si personne n'a gangné) */
int Gagnant(struct Grille* courant)
{
    int c0,c1;
    c0=nbPieces(courant,'0');
    c1=nbPieces(courant,'1');
    if(c0>c1) return 0;
    else if (c0<c1) return 1;
    else return -1;
}
