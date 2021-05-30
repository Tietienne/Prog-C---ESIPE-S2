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
	int size = 10;
	int * tab = alloc_tab(size);
	int * tab2 = alloc_tab(size);
	print_info_zone(tab);
	print_info_zone(tab2);
	free(tab);
	int * tab3 = alloc_tab(size);
	print_info_zone(tab3);
	int * tab4 = alloc_tab(20);
	print_info_zone(tab4);
	free_tab(tab2);
	free_tab(tab3);
	free_tab(tab4);
	return 0;
}