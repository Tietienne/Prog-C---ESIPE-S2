#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "graphics.h"
#include "dames.h"

#define height 1000
#define width height+400
#define marge 50

void add_dame(int line, int column, int case_size, unsigned long int* n, int* dame) {
	draw_dame(line, column, case_size); // Ajout graphique
	set_all_positive_bits(n, line, column); // Ajout bits
	*dame += 1;
}

int main(int argc, char* argv[]){
	// Tests sur les fonctions préliminaires

	// unsigned long int n = 1;
	// printf("%d\n", bit_value_ULI(n, 0));
	// set_positive_bit_ULI(&n, 36);
	// print_ULI(n);
	// set_negative_bit_ULI(&n, 36);
	// print_ULI(n);

	// ---- //

	create_window(width, height);
	int case_size = (height-marge)/8;
	create_board(width, height, marge, case_size);
	int dame = 0;
	unsigned long int n = 0;
	while (dame!=8 && game_over(n)!=1) {
		int x, y, line, column, position;
		MLV_wait_mouse(&x, &y);
		if (x<case_size*8 && y<case_size*8) {
			line = y/case_size;
			column = x/case_size;
			position = line_column_to_position(line, column);
			if (bit_value_ULI(n, position)==0) {
				add_dame(line, column, case_size, &n, &dame);
			}
		}
	}
	if (dame!=8) {
		draw_loser(height);
	} else {
		draw_winner(height);
	}
	MLV_wait_seconds(10);
	free_window();
	return 0;
}