#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "move.h"
#include "human_vs_stupid_machine.h"
#include "human_vs_medium_machine.h"
int PlayHumanVsMediumMachine(int LookAheadLevel)
{
    struct Board *current;
    struct Board *new;
    struct Position *move;
    int gameover=0;
    int win;
    current=setupBoard();
    while(!gameover){
		printBoard(current);
		do{
                move=getMove(0);
                printf("x=%d y=%d",move->x,move->y);
                if(move->x==-1 )break;
                new=placePiece(*move,current,0);
                free(move);
          }while(new==NULL);
		if(move->x!=-1){
               free(current);
               current=new;
		}
		printBoard(current);
		printf("computer moving...");
		move=lookAhead(0,1,current,1);
          printf("move entered : x=%i, y=%i\n", move->x, move->y);
          if(move->x!=-1)
          {
               new=placePiece(*move,current,1);
               free(current);
               current = new;
          }
          free(move);
        if(boardFull(current)|| countPieces(current,'0')==0 || countPieces(current,'1')==0 )
                    gameover=1;
     }
	printBoard(current);
	win=checkWin(current);
	return win;

}
void HumanVsMediumMachine(int LookAheadLevel)
{
    int winner;
    winner=PlayHumanVsMediumMachine(LookAheadLevel);
    if(winner==1) printf("La machine a gagné !!\n");
    else if (winner==0) printf("Vous avez gagné !!!\n");
    else if (winner==-1) printf("Personne n'a gagné !!!\n");
}
