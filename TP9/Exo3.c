#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** alloc_tab(int size, char** argv) {
	char** tab;
	if ((tab=(char**) malloc(size*sizeof(char*))) == NULL) {
		printf("Pas assez de place en mémoire !");
		exit(1);
	}
	for (int i=0; i<size; i++) {
		// Allocation de la mémoire de chaque argument en fonction de sa taille (+1 pour le dernier caractère '\0')
		if ((tab[i]=(char*) malloc((strlen(argv[i])+1)*sizeof(char))) == NULL) {
			printf("Pas assez de place en mémoire !");
			exit(1);
		}		
	}
	return tab;
}

void free_tab(char** tab, int size) {
	if (tab==NULL) {
		return;
	}
	for (int i=0; i<size; i++) {
		if (tab[i]!=NULL) {
			free(tab[i]);
		}
	}
	free(tab);
}

void insert_tab(char** tab, int size, char** argv) {
	for (int i=0; i<size; i++) {
		int j=0;
		char c=argv[i][j];
		while (c!='\0'){
			tab[i][j]=c;
			j++;
			c=argv[i][j];
		}
		tab[i][j]=c; // Pour le dernier caractère '\0'
	}
}

void print_tab(char** tab, int size) {
	char c;
	int j;
	for (int i=0; i<size; i++) {
		printf("arg[%i] : ", i);
		j = 0;
		c = tab[i][j];
		while(c!='\0') {
			printf("%c", c);
			j++;
			c = tab[i][j];
		}
		printf("\n");
	}	
}

int main(int argc, char* argv[]) {
	int size = argc;
	char** tab = alloc_tab(size, argv);
	insert_tab(tab, size, argv);
	print_tab(tab, size);
	free_tab(tab, size);
	return 0;
}