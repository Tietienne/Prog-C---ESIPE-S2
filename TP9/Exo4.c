#include <stdio.h>
#include <stdlib.h>

void print_info_zone(void* adr) {
	size_t* info_adr = (size_t*)adr;
	printf("Zone à l'adresse : %p\n", adr);
	printf("%lu \n", info_adr[-1]);
	printf("%lu \n", info_adr[-2]);
}

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