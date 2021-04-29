#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <MLV/MLV_all.h>

void create_window(int width, int height);
void create_board(int width, int height, int marge, int case_size);
void draw_dame(int line, int column, int case_size);
void draw_loser(int height);
void draw_winner(int height);
void free_window();

#endif