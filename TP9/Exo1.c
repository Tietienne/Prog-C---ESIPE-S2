#include <stdio.h>
#include <stdlib.h>

int* alloc_tab(int size) {
	int * tab;
	tab = (int *) malloc(size*sizeof(int));
	if (tab==NULL) {
		printf("Pas assez de place en mémoire !");
		exit(1);
	}
	return tab;
}

void free_tab(int* tab) {
	if (tab==NULL) {
		return;
	}
	free(tab);
}

void insert_tab(int* tab, int size) {
	for (int i=0;i<size;i++) {
		tab[i]=i+1;
	}	
}

void print_tab(int * tab, int size) {
	for (int i=0;i<size;i++) {
		printf("%i ",tab[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[]) {
	if (argc>=2) {
		int size = atoi(argv[1]);
		int * tab = alloc_tab(size);
		insert_tab(tab, size);
		print_tab(tab, size);
		free_tab(tab);
	}
	return 0;
}