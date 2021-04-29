#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <MLV/MLV_all.h>

MLV_Image* create_window();
void draw_lines(int n, MLV_Image* img);
void draw_columns(int m, MLV_Image* img);
void draw_black_square(int line, int column, int distance_x, int distance_y, MLV_Image* img);
void move_image_square(int line_source, int column_source, int distance_x, int distance_y, MLV_Image* img, int line_destination, int column_destination);
void actualise_img(MLV_Image* img);

#endif