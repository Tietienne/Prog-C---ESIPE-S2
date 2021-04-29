#ifndef __DAMES__
#define __DAMES__

int bit_value_ULI(unsigned long int n, int position);
void print_ULI(unsigned long int n);
void set_positive_bit_ULI(unsigned long int* n, int position);
void set_negative_bit_ULI(unsigned long int* n, int position);
int game_over(unsigned long int n);
void set_all_positive_bits(unsigned long int* n, int line, int column);
int line_column_to_position(int line, int column);

#endif