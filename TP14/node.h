#ifndef __NODE__
#define __NODE__

typedef struct node{
	char* path; // Chaîne représentant un lien vers un fichier
	long int size; // long int représentant la taille en octet de ce fichier
	struct node* next;
} node;

node *create_node(char path[], long int size);

void free_node(node *n);
void free_list(node *lst);

node* verify_and_insert_list(node* list, char path[], long int size);
void print_files(node* list);

#endif