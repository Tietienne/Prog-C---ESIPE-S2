#include <stdio.h>
#include <stdlib.h>

char** alloc_tab(int line, int column) {
	char** tab;
	if ((tab=(char**) malloc(line*sizeof(char*))) == NULL) {
		printf("Pas assez de place en mémoire !");
		exit(1);
	}
	for (int i=0; i<line; i++) {
		if ((tab[i]=(char*) malloc(column*sizeof(char))) == NULL) {
			printf("Pas assez de place en mémoire !");
			exit(1);
		}		
	}
	return tab;
}

void free_tab(char** tab, int line) {
	if (tab==NULL) {
		return;
	}
	for (int i=0; i<line; i++) {
		if (tab[i]!=NULL) {
			free(tab[i]);
		}
	}
	free(tab);
}

void scan_values(int* val1, int* val2) {
	printf("Saississez 2 valeurs : ");
	scanf("%i %i", val1, val2);
}

void insert_tab(char** tab, int line, int column) {
	char letter = 'a', letter_line = 'a';
	for (int i=0; i<line; i++) {
		for (int j=0; j<column; j++) {
			tab[i][j] = letter;
			// Décompte de la lettre de chaque colonne
			if (letter == 'z') {
				letter = 'a';
			} else {
				letter++;
			}
		}
		// Décompte de la 1ère lettre de chaque ligne
		if (letter_line == 'z') {
			letter_line = 'a';
		} else {
			letter_line++;
		}
		letter = letter_line;
	}
}

void print_tab(char** tab, int line, int column) {
	for (int i=0; i<line; i++) {
		for (int j=0; j<column; j++) {
			printf("%c ", tab[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]) {
	int line = 0, column = 0;
	scan_values(&line, &column);

	char** tab = alloc_tab(line, column);
	insert_tab(tab, line, column);
	print_tab(tab, line, column);
	free_tab(tab, line);

	return 0;
}