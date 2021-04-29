#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "graphics.h"
#include "taquin.h"

#define number_swap 120
#define name_image "images/panda_roux.jpeg"

int distance_x = 512/NB_LIG;
int distance_y = 512/NB_COL;

void make_swap(Plateau* P, int line_toSwap, int column_toSwap, MLV_Image* img) {
	int line_bs = -1;
	int column_bs = -1;
	getCoordsBS(P, &line_bs, &column_bs);
	swapCarre(P, line_toSwap, column_toSwap, line_bs, column_bs); // On fait l'échange dans notre Plateau
	move_image_square(line_toSwap, column_toSwap, distance_x, distance_y, img, line_bs, column_bs); // On fait l'échange graphiquement
	updateBS(P, line_toSwap, column_toSwap); // On met à jour le carré noir du plateau
}

void random_swaps(Plateau* P, MLV_Image* img) {
	for (int i=0; i<number_swap; i++) {
		int line_toSwap = -1;
		int column_toSwap = -1;
		// On boucle sur le random tant qu'on obtient pas une valeur valide
		while(line_toSwap == -1 && column_toSwap == -1) {
			int random = MLV_get_random_integer(1,5);
			canSwap(P, random, &line_toSwap, &column_toSwap);
		}
		make_swap(P, line_toSwap, column_toSwap, img);
	}
}

int main(int argc, char* argv[]){
	// Création du plateau et mélange du jeu //
	Plateau* P = (Plateau *) malloc(sizeof(Plateau));
	InitialisationPlateau(P);

	char* image_path = name_image;
	MLV_Image* img = create_window(image_path);
	draw_lines(NB_LIG, img);
	draw_columns(NB_COL, img);

	draw_black_square(NB_LIG, NB_COL, distance_x, distance_y, img);

	random_swaps(P, img);

	actualise_img(img);

	// ---- //

	// Boucle principale //
	while (isFinish(P)==0) {
		// On récupère les coordonnées x,y de la souris
		int x, y, line, column;
		MLV_wait_mouse(&x, &y);

		// Puis on les transforme en position ligne, colonne
		column = x/distance_x;
		line = y/distance_y;
		
		// Si les coordonnées sont valides, on effectue le swap
		if (verifyManualSwap(P, line, column)==1) {
			make_swap(P, line, column, img);
			actualise_img(img);
		}
	}
	// ---- //
	
	MLV_wait_seconds(10);

	// Libération des allocations
	freePlateau(P);
	MLV_free_image(img);
	MLV_free_window();
	return 0;
}