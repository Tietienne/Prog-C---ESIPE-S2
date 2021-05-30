#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

node *create_node(int elt) {
    node *n = malloc(sizeof(node));
    n->elt = elt;
    n->previous = NULL;
    return n;
}

void free_node(node *n) {
    free(n);
}

void free_pile(node *p) {
    while (p) {
        node *tmp = p;
        p = p->previous;
        free_node(tmp);
    }
}

int verify_first_elements(node* p) {
	if (p==NULL || p->previous==NULL) {
		return 0;
	}
	return 1;
}

node* insert_pile(node* p, int elt) {
	node* n = create_node(elt);
	n->previous = p;
	return n;
}

void print_head(node* p) {
	if (p==NULL) {
		return;
	}
	printf("%d\n", p->elt);
}

void print_pile(node* p) {
	print_head(p);
	print_pile(p->previous);
}

node* reverse_head(node* p) {
	if (verify_first_elements(p)==0) {
		return p;
	}
	node* tmp = p->previous;
	p->previous = p->previous->previous;
	tmp->previous = p;
	return tmp;
}

node* add(node* p) {
	if (verify_first_elements(p)==0) {
		return p;
	}
	node* tmp = p->previous;
	tmp->elt = tmp->elt + p->elt;
	free_node(p);
	return tmp;
}

node* sub(node* p) {
	if (verify_first_elements(p)==0) {
		return p;
	}
	node* tmp = p->previous;
	tmp->elt = tmp->elt - p->elt;
	free_node(p);
	return tmp;
}

node* mul(node* p) {
	if (verify_first_elements(p)==0) {
		return p;
	}
	node* tmp = p->previous;
	tmp->elt = tmp->elt * p->elt;
	free_node(p);
	return tmp;
}

node* division(node* p) {
	if (verify_first_elements(p)==0) {
		return p;
	}
	if (p->elt==0) {
		printf("Division par 0 impossible !\n");
		return p;
	}
	node* tmp = p->previous;
	tmp->elt = tmp->elt / p->elt;
	free_node(p);
	return tmp;
}

node* mod(node* p) {
	if (verify_first_elements(p)==0) {
		return p;
	}
	node* tmp = p->previous;
	tmp->elt = tmp->elt % p->elt;
	free_node(p);
	return tmp;
}

node* facto(node* p) {
	if (p==NULL) {
		return p;
	}
	int result = 1;
	for (int i=0;i<p->elt;i++) {
		result*=i+1;
	}
	p->elt = result;
	return p;
}

node* expo(node* p) {
	if (verify_first_elements(p)==0) {
		return p;
	}
	node* tmp = p->previous;
	int result = 1;
	for (int i=0;i<p->elt;i++) {
		result*=tmp->elt;
	}
	tmp->elt = result;
	free_node(p);
	return tmp;
}