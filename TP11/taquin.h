#ifndef __TAQUIN__
#define __TAQUIN__

#define NB_COL 2
#define NB_LIG 2

typedef struct carre{
	int lig;
	int col;
}Carre;

typedef struct plateau{
	Carre* bloc[NB_COL][NB_LIG];
	int line_bs; // Ligne et colonne du carré noir.
	int column_bs;
}Plateau;

void InitialisationPlateau(Plateau* P);
void freePlateau(Plateau* P);
void getCoordsBS(Plateau* P, int* line_bs, int* column_bs);
void updateBS(Plateau *P, int new_line, int new_column);
int isFinish(Plateau* P);
void swapCarre(Plateau* P, int line_source, int column_source, int line_dest, int column_dest);
void canSwap(Plateau* P, int direction, int* line_toSwap, int* column_toSwap);
int verifyManualSwap(Plateau* P, int line, int column);

#endif