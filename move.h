#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED
int conversion(char c);
struct Position *Mouvement(int joueur);
struct Grille *tournerPiece(struct Position move, struct Grille *new,int tour,struct Position *dir);
struct Grille *placerPiece(struct Position move, struct Grille *courant,int tour);
int mouvementValid(struct Grille *courant, struct Position move,int tour);
int bloque(struct Grille *courant ,int tour );

#endif // MOVE_H_INCLUDED
