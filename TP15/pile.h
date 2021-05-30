#ifndef __PILE__
#define __PILE__

typedef struct node{
	int elt;
	struct node* previous;
} node;

/* Fonctions de création et de libération de la pile */
node *create_node(int elt);
void free_node(node *n);
void free_pile(node *p);

/* Fonctions de modification de la pile */
node* insert_pile(node* p, int elt);
node* reverse_head(node* p);

/* Fonctions d'affichage de la pile */
void print_head(node* p);
void print_pile(node* p);


/* Fonctions mathématiques sur la pile*/
node* add(node* p);
node* sub(node* p);
node* mul(node* p);
node* division(node* p);
node* mod(node* p);
node* facto(node* p);
node* expo(node* p);

#endif