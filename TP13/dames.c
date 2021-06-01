#include "dames.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Exercice préliminaire :

int bit_value_ULI(unsigned long int n, int position) {
	return (n&((unsigned long int) 1<<position)) ? 1 : 0;
}

void print_ULI(unsigned long int n) {
	for (int i = 63; i>=0; i--) {
		printf("%c", (n&((unsigned long int) 1<<i)) ? '1': '0');
	}
	printf("\n");
}

void set_positive_bit_ULI(unsigned long int* n, int position) {
	*n=(*n)|((unsigned long int) 1<<position);
}

void set_negative_bit_ULI(unsigned long int* n, int position) {
	*n=(*n)&~((unsigned long int) 1<<position);
}

// ---- //

int game_over(unsigned long int n) {
	for (int i = 63; i>=0; i--) {
		if (!(n&((unsigned long int) 1<<i))) {
			return 0; // S'il reste 1 bit disponible : ce n'est pas perdu
		}
	}
	return 1;
}

void set_all_positive_bits(unsigned long int* n, int line, int column) {
	for (int i=0;i<8;i++) {
		// Colonne
		set_positive_bit_ULI(n, line_column_to_position(line, i));
		// Ligne
		set_positive_bit_ULI(n, line_column_to_position(i, column));
	}

	int i, j, k, l;
	// Diagonales //
	if (line<=column) { // Premier cas de diagonales
		i = 0; // ligne
		j = column - line; // colonne
		
		k = 0; // ligne
		l = column + line; // colonne
	} else { // Deuxième cas de diagonale
		i = line - column; // ligne
		j = 0; // colonne
		
		k = 0; // ligne
		l = column + line; // colonne
	}
	while (i<8 && j<8) { // 1ère diagonale
		set_positive_bit_ULI(n, line_column_to_position(i, j));
		i++;
		j++;
	}
	while (k<8 && l<0) { // 2nde diagonale
		set_positive_bit_ULI(n, line_column_to_position(k, l));
		k++;
		l--;
	}
}

int line_column_to_position(int line, int column) {
	return (7-column)*8+(7-line);
}
