#include "graphics.h"
#include <stdlib.h>
#include <string.h>

MLV_Image* create_window(char* file_path){
	/* Create the window */
	MLV_create_window("Jeu de Taquin", "Jeu de Taquin", 512, 512);
	MLV_Image* img = MLV_load_image(file_path);
	return img;
}

void draw_lines_rec(int n, int distance, MLV_Image* img){
	if (n<=0) {
		return;
	}
	MLV_draw_filled_rectangle_on_image(0,n*distance-5,511,5, MLV_COLOR_BLACK, img);
	draw_lines_rec(n-1, distance, img);
}

void draw_lines(int n, MLV_Image* img){
	int distance = 512/n;
	draw_lines_rec(n, distance, img);
}

void draw_columns_rec(int m, int distance, MLV_Image* img){
	if (m<=0) {
		return;
	}

	MLV_draw_filled_rectangle_on_image(m*distance-5,0,5,511, MLV_COLOR_BLACK, img);
	draw_columns_rec(m-1, distance, img);
}

void draw_columns(int m, MLV_Image* img){
	int distance = 512/m;
	draw_columns_rec(m, distance, img);
}

void draw_black_square(int line, int column, int distance_x, int distance_y, MLV_Image* img) {
	MLV_draw_filled_rectangle_on_image((column)*distance_y,(line)*distance_x,distance_y,distance_x, MLV_COLOR_BLACK, img);
}

void move_image_square(int line_source, int column_source, int distance_x, int distance_y, MLV_Image* img, int line_destination, int column_destination) {
	MLV_draw_partial_image_on_image(img, (column_source)*distance_y,(line_source)*distance_x,distance_y,distance_x, img, (column_destination)*distance_y,(line_destination)*distance_x);
	draw_black_square(line_source, column_source, distance_x, distance_y, img);
}

void actualise_img(MLV_Image* img) {
	MLV_draw_image(img,0,0);
	MLV_actualise_window();
}