#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "board.h"
#include "move.h"
/* conversion : convertit les caractères entrés par le joueur en des nombres utilisés comme des indices dans la grille */
int conversion(char c)
{
    switch(c)
    {
    case 'A' : case 'a' : return 0;
    case 'B' : case 'b' : return 1;
    case 'C' : case 'c' : return 2;
    case 'D' : case 'd' : return 3;
    case 'E' : case 'e' : return 4;
    case 'F' : case 'f' : return 5;
    case 'G' : case 'g' : return 6;
    case 'H' : case 'h' : return 7;
    case 'P' : case 'p' : return -1;
    default  : return -1;
    }
}
/*Mouvement : retourne le mouvement (x,y) entré par le joueur */
struct Position *Mouvement(int joueur){
    char c;
	struct Position *move;
	move=malloc(sizeof(struct Position));
     printf("\nDonnez votre mouvement en tant que  '%d' x,y (P,0 pour passer) >>",joueur);
	scanf(" %c,%d",&c,&move->y);
	move->x=conversion(c);
	Sleep(1000);
	return(move);
}
/*tournerPiece : tourne les pièces de la couleur "!tour" entre une pièce de la couleur "tour" dans la position "move"
et une autre dans la direction "dir" */
struct Grille *tournerPiece(struct Position move, struct Grille *nouveau,int tour,struct Position *dir){
	int x,y;
	char tourPiece='0';
	char autrePiece='1';
	tourPiece+=tour;
	autrePiece-=tour;
	x=move.x + dir->x;
	y=move.y + dir->y;
     if(LIMITES_GRILLE)
     {
          if(nouveau->othello[x][y]==autrePiece){
               while(nouveau->othello[x][y]==autrePiece && LIMITES_GRILLE){
                    x+=dir->x;
                    y+=dir->y;
               }
               if(nouveau->othello[x][y]==tourPiece && LIMITES_GRILLE){
                    x=move.x+dir->x;
                    y=move.y+dir->y;
                    dir->score=1;
                    while(nouveau->othello[x][y]==autrePiece){
                         nouveau->othello[x][y]=tourPiece;
                         x+=dir->x;
                         y+=dir->y;
                    }
     }
		}
	}
	return(nouveau);
}
/*placerPiece : retourne une grille dont la pièce de la couleur "tour" est placée dans la position "move"
de la grille "courant", si cette postion est valide, sinon NULL*/
struct Grille *placerPiece(struct Position move, struct Grille *courant,int tour){
	int x,y;
	struct Grille *nouveau;
	struct Position dir={0,0,0}; //pour vérifier en tout les directions
	char tourPiece='0';
	tourPiece+=tour;

	if(courant->othello[move.x][move.y]!=' ') return(NULL);
	nouveau=initGrille();

	*nouveau=*courant;
	for(x=-1;x<=1;x++)
		for(y=-1;y<=1;y++)
			if(x!=0 || y!=0){
				dir.x=x;
				dir.y=y;
                /*dir.x=-1 dir.y=-1 : Nord Ouest, dir.x=0 dir.y=1 : Est ...*/
				nouveau=tournerPiece(move,nouveau,tour,&dir);
			}
	if(dir.score){
		nouveau->othello[move.x][move.y]=tourPiece;
		return(nouveau);
	}else
     {
          free(nouveau);
          return(NULL);
	}
}
/*mouvementValid : retourne Vrai(1) si le joueur de la couleur "tour" tourne au moins une pièce
de la couleur "!tour" dans la position "move" */
int mouvementValid(struct Grille *courant, struct Position move,int tour)
{
    int i,j;
    int x,y;
    struct Position dir={0,0,0};
    char tourPiece='0';
	char autrePiece='1';
	tourPiece+=tour;
	autrePiece-=tour;
	if(courant->othello[move.x][move.y]!=' ') return 0;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			if(i!=0 || j!=0){
				dir.x=i;
				dir.y=j;
				x=move.x+dir.x;
				y=move.y+dir.y;
				if(courant->othello[x][y]==autrePiece){
               while(courant->othello[x][y]==autrePiece && LIMITES_GRILLE){
                    x+=dir.x;
                    y+=dir.y;
               }
               if(courant->othello[x][y]==tourPiece && LIMITES_GRILLE){
                    x=move.x+dir.x;
                    y=move.y+dir.y;
                    dir.score=1;
               }
				}
			}
			if(dir.score) return 1;
			else return 0;
}
/*bloque : retourne Vrai(1) si le joueur de la couleur "tour" n'a aucun mouvement possible, Faux (0) sinon */
int bloque(struct Grille *courant ,int tour ){
	int i,j; struct Position move;
	for(i=0;i<XMAX;i++)
        for(j=0;j<YMAX;j++){
            if(courant->othello[i][j]==' ')
            {
                move.x=i; move.y=j;
                if(mouvementValid(courant,move,tour))
                    return 0;
            }
        }
	return 1;
}
