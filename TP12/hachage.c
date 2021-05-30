#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define MAX_WORD_LENGTH 80
#define NB_PACK 4096

/**
 * Create a table
 */
table *create_table(int M) {
    table *tab = malloc(sizeof(table));
    tab->M = M;
    tab->distinct = 0;

    node **bucket = malloc(sizeof(node)*M);
    for (int i = 0; i<M; i++) {
        bucket[i] = NULL;
    }
    tab->bucket = bucket;
    return tab;
}

/**
 * Create a node representing 1 occurence of the string 'word'.
 * The string is copied and must be freed when the node is freed.
 */
node *create_node(char word[]) {
    node *n = malloc(sizeof(node));
    n->word = malloc(strlen(word)+1);
    strcpy(n->word, word);
    n->next = NULL;
    return n;
}

void free_node(node *n) {
    free(n->word);
    free(n);
}

void free_list(node *lst) {
    while (lst) {
        node *tmp = lst;
        lst = lst->next;
        free_node(tmp);
    }
}

void free_table(table *tab) {
    for (int i=0; i<tab->M; i++) {
        free_list(tab->bucket[i]);
    }
    free(tab->bucket);
    free(tab);
}

// Fonction de hachage
int hachage(char word[], int seaux) {
    unsigned nbHach=0;
    for (int i=0; word[i]!='\0'; i++){
        nbHach = nbHach+(i+1)*word[i];
    }
    return nbHach %= seaux;
}

int equal(char* w1, char* w2) {
    return strcmp(w1, w2) == 0;
}

node *find_list(node* lst, char word[]) {
    node *ptr = lst;
    while (ptr != NULL && !equal(ptr->word, word))
        ptr = ptr->next;
    return ptr;
}

node *insert_first_list(node *lst, char word[]) {
    node *tmp = create_node(word);
    tmp->next = lst;
    return tmp;
}

void add_occ_table(table *tab, char word[]) {
    int nbHach = hachage(word, tab->M);
    node **bucket = tab->bucket;
    node* ptr=find_list(bucket[nbHach], word);

    if (ptr==NULL) {
        bucket[nbHach] = insert_first_list(bucket[nbHach], word); // Le mot n'existe pas dans la liste
        tab->distinct++;
    }
}

table *read_text(FILE *infile, int M) {
    table *tab = create_table(M);
    char *word = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    while (fscanf(infile, "%s ", word) != -1) {
        add_occ_table(tab, word);   
    }
    free(word);
    return tab;
}

int table_length(table* t) {
    return t->distinct;
}

int main(int argc, char* argv[]){
    FILE *f = fopen("Germinal.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file for reading 'Germinal.txt'.\n");
        return 1;
    }

    int M = NB_PACK;

    table *tab = read_text(f, M);
    fclose(f);

    printf("%d different words found in Germinal.\n", table_length(tab));
    free_table(tab);

	return 0;
}