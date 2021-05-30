#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "pile.h"

void read_string(char* string, node* p, char* letter) {
	// Lecture de la ligne de l'utilisateur

		// Si caractère numérique : insertion pile
		// Si caractère alphabétique : case -> puis fonction correpondante
		// Si caractère mathématique : case -> puis fonction mathématique correspondante
}

int main(int argc, char* argv[]) {
	node* pile;
	char* prompt = NULL;
	char* string = NULL;
	char letter = 'z';
	while (letter!='q') {
		char* string = readline(prompt);
		read_string(string, pile, &letter);
	}
	free(prompt);
	free(string);
	return 0;
}