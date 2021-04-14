#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#define XMAX 8		//Nombre maximales des lignes 
#define YMAX 8		//Nombre maximales des colonnes
#define LIMITES_GRILLE x<XMAX && x>=0 && y<YMAX && y>=0
struct Grille{
	char othello[XMAX][YMAX];  
};
struct Position{
	int x;
	int y;
	int score;
};
void afficherGrille(struct Grille *current );
struct Grille *initGrille(void);
int Plein(struct Grille *current);
int nbPieces(struct Grille *current,char c);
int Gagnant(struct Grille* current);


#endif // Grille_H_INCLUDED
