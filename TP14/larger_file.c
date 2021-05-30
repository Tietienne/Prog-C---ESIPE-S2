#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include "node.h"

node* list = NULL;

static int verify_size(const char* fpath, const struct stat *sb, int tflag) {
	// Si on tombe sur un fichier : on vérifie et on insère si nécessaire
	if (tflag==FTW_F) {
		list = verify_and_insert_list(list, (char *) fpath, sb->st_size);
	}
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc<2) {
		printf("Usage : %s <path>\n", argv[0]);
		return 1;
	}

	if (ftw(argv[1], verify_size, 20)==-1) {
		perror("Error");
		return 1;
	}

	print_files(list);
	free_list(list);
	return 0;
}