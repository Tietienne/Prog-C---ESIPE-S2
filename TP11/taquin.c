#include "taquin.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void InitialisationPlateau(Plateau* P){
	for (int i=0; i<NB_LIG; i++) {
		for(int j=0; j<NB_COL; j++) {
			Carre* c = (Carre *) malloc(sizeof(Carre));
			c->lig = i;
			c->col = j;
			(P->bloc)[i][j] = c;
		}
	}
	// Le carré noir se trouve en bas à droite à la base
	P->line_bs = NB_LIG-1;
	P->column_bs = NB_COL-1;
}

// Problème avec le free : le trouver et le résoudre
void freePlateau(Plateau* P) {
	for (int i=0; i<NB_LIG; i++) {
		for(int j=0; j<NB_COL; j++) {
			free((P->bloc)[i][j]);
		}
	}
	free(P);
}

// 1 = terminé | 0 = pas terminé
int isFinish(Plateau* P) {
	for (int i=0; i<NB_LIG; i++) {
		for(int j=0; j<NB_COL; j++) {
			if (((P->bloc)[i][j])->lig != i || ((P->bloc)[i][j])->col != j) {
				return 0;
			}
		}
	}
	return 1;
}

void getCoordsBS(Plateau* P, int* line_bs, int* column_bs) {
	*line_bs = P->line_bs;
	*column_bs = P->column_bs;
}

void updateBS(Plateau *P, int new_line, int new_column) {
	P->line_bs = new_line;
	P->column_bs = new_column;
}

void swapCarre(Plateau* P, int line_source, int column_source, int line_dest, int column_dest) {
	if (line_source<0 || column_source<0 || line_dest<0 || column_dest<0 || line_source>NB_LIG-1 || column_source>NB_COL-1 || line_dest>NB_LIG-1 || column_dest>NB_COL-1 ) {
		return;
	}
	Carre* tmp = (P->bloc)[line_source][column_source];
	(P->bloc)[line_source][column_source] = (P->bloc)[line_dest][column_dest];
	(P->bloc)[line_dest][column_dest] = tmp;
}

int verifyManualSwap(Plateau* P, int line, int column) {
	// Soit à une place d'écart sur la même colonne
	if ((P->line_bs-1==line || line==P->line_bs+1) && column == P->column_bs) {
		return 1;
	}
	// Soit à une place d'écart sur la même ligne
	if ((P->column_bs-1==column || column==P->column_bs+1) && line == P->line_bs) {
		return 1;
	}
	// Sinon, impossible de swap
	return 0;
}

// Vérifier swap pour random, direction : 1 = haut | 2 = droite | 3 = bas | 4 = gauche
void canSwap(Plateau* P, int direction, int* line_toSwap, int* column_toSwap) {
	int line, column;
	switch (direction) {
		case 1: line=P->line_bs-1;
				column=P->column_bs;
				break;
		case 2: line=P->line_bs;
				column=P->column_bs+1;
				break;
		case 3: line=P->line_bs+1;
				column=P->column_bs;
				break;
		case 4: line=P->line_bs;
				column=P->column_bs-1;
				break;
		default: return;
	}

	if (line<0 || line>=NB_LIG || column<0 || column>=NB_COL) {
		return;
	}
	*line_toSwap = line;
	*column_toSwap = column;
}