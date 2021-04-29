#include "graphics.h"
#include <stdlib.h>
#include <string.h>


void create_window(int width, int height) {
	MLV_create_window("TP 13 - Jeu des 8 Dames", "images/queen.png", width, height);
}

void draw_case_gray(int x, int y, int width, int height) {
	MLV_draw_filled_rectangle(x, y, width, height, MLV_COLOR_DARKGRAY);
}

void draw_lines_cases(int x, int y, int case_size) {
	for (int i=0; i<4; i++) {
		draw_case_gray(x+(case_size*2)*i,y,case_size,case_size);
	}
}

void draw_lines(int height) {
	MLV_draw_line(0, height-50, height-50, height-50, MLV_COLOR_BLACK);
	MLV_draw_line(0, height-2, height, height-2, MLV_COLOR_BLACK);
	MLV_draw_line(height-50, 0, height-50, height-50, MLV_COLOR_BLACK);
	MLV_draw_line(height, 0, height, height-2, MLV_COLOR_BLACK);
}

void draw_numbers(int height, int case_size) {
	for (int i=0; i<8; i++) {
		char* c = (char*) malloc(sizeof(char));
		sprintf(c, "%d", 7-i);
		MLV_draw_text(case_size/2+case_size*i, height-25, c, MLV_COLOR_BLACK);
		free(c);
	}
	for (int i=0; i<8; i++) {
		char* c = (char*) malloc(sizeof(char));
		sprintf(c, "%d", 7-i);
		MLV_draw_text(height-25, case_size/2+case_size*i, c, MLV_COLOR_BLACK);
		free(c);
	}
}

void create_board(int width, int height, int marge, int case_size) {
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_LIGHTGRAY);
	for (int i=0; i<8; i++) {
		if (i%2==0) {
			draw_lines_cases(case_size, case_size*i, case_size);
		} else {
			draw_lines_cases(0, case_size*i, case_size);
		}
	}
	draw_lines(height);
	draw_numbers(height, case_size);
	MLV_update_window();
}

void draw_dame(int line, int column, int case_size) {
	MLV_Image* img = MLV_load_image("images/queen.png");
	MLV_resize_image(img, case_size-10, case_size-10);
	MLV_draw_image(img, column*case_size, line*case_size);
	MLV_update_window();
}

void draw_loser(int height) {
	MLV_draw_text(height+75, height/2, "Dommage ... toutes les cases sont attaquées.", MLV_COLOR_BLACK);
	MLV_draw_text(height+75, height/2+50, "Vous n'avez pas réussi à placer les 8 dames.", MLV_COLOR_BLACK);

	MLV_update_window();
}

void draw_winner(int height) {
	MLV_draw_text(height+100, height/2, "Bravo ! Vous avez réussi à placer les 8 dames.", MLV_COLOR_BLACK);
	MLV_update_window();
}

void free_window() {
	MLV_free_window();
}