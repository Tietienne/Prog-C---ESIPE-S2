#include <stdio.h>
#include <stdlib.h>

void swap_mem(void* z1, void* z2, size_t size) {
	unsigned char* t1 = (unsigned char*) z1;
	unsigned char* t2 = (unsigned char*) z2;
	unsigned char* tmp = (unsigned char*) malloc(size);

	// On swap la zone mémoire caractère par caractère
	for (int i=0; i<size; i++) {
		tmp[i] = t1[i];
		t1[i] = t2[i];
		t2[i] = tmp[i];
	}

	free(tmp);
}

int main(int argc, char* argv[]) {
	int test1 = 5;
	int test2 = 2;

	double test3 = 645.36452324;
	double test4 = 28.47512;

	char* test5 = "ceci est un test";
	char* test6 = "encore un autre test";

	printf("Entier 1 : %d\n", test1);
	printf("Entier 2 : %d\n", test2);
	printf("Swap\n");
	swap_mem(&test1, &test2, sizeof(int));
	printf("Entier 1 : %d\n", test1);
	printf("Entier 2 : %d\n", test2);

	printf("Double 1 : %f\n", test3);
	printf("Double 2 : %f\n", test4);
	printf("Swap\n");
	swap_mem(&test3, &test4, sizeof(double));
	printf("Double 1 : %f\n", test3);
	printf("Double 2 : %f\n", test4);

	printf("Char * 1 : %s\n", test5);
	printf("Char * 2 : %s\n", test6);
	printf("Swap\n");
	swap_mem(&test5, &test6, sizeof(char*));
	printf("Char * 1 : %s\n", test5);
	printf("Char * 2 : %s\n", test6);

	return 0;
}
