#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "move.h"
#include "human_vs_stupid_machine.h"
/*struct Position *firstValidMove(struct Board *current ){
    struct Board *new=NULL;
	struct Position *move;
	for(move->x=0;move->x<XMAX;move->x++)
		for(move->y=0;move->y<YMAX;move->y++)
			if((new=placePiece(*move,current,1))!=NULL)
                return move;
    move->x=-1; move->y=-1; move->score=0;
    return move;

}*/
struct Position *lookAhead(int n, char turn, struct Board *current, int lookAheadLevel){
	struct Position move; /* move to test */
	struct Position *moveBest;  /* best move */
	struct Position *moveLower; /* best move of lower level */
	struct Board *new=NULL;
	moveBest = malloc(sizeof(struct Position));
	moveBest->x=-1;
	moveBest->y=-1;
	if(turn)moveBest->score=100; /*lowest number of opponent pieces best*/
	else moveBest->score=0;
	if (n == lookAheadLevel){
		moveBest->score=countPieces(current,'0');
		return(moveBest);
	}
	for(move.x=0;move.x<XMAX;move.x++)
		for(move.y=0;move.y<YMAX;move.y++){
			if((new=placePiece(move,current,turn))!=NULL){
				moveLower = lookAhead(n+1,!turn,new,lookAheadLevel);
				if(turn && moveLower->score < moveBest->score){
					moveBest->score=moveLower->score;
					moveBest->x=move.x;
					moveBest->y=move.y;
				}else if(!turn && moveLower->score > moveBest->score)
					moveBest->score=moveLower->score;
                    free(new);
                    free(moveLower);
               }
		}
	return(moveBest);
}
int PlayHumanVsStupidMachine(int LookAheadLevel)
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
		move=lookAhead(0,1,current,LookAheadLevel);
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
void HumanVsStupidMachine(int LookAheadLevel)
{
    int winner;
    winner=PlayHumanVsStupidMachine(LookAheadLevel);
    if(winner==1) printf("La machine a gagné !!\n");
    else if (winner==0) printf("Vous avez gagné !!!\n");
    else if (winner==-1) printf("Personne n'a gagné !!!\n");
}
