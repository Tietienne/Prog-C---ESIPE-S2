#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define MAX_WORD_LENGTH 80

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

node *read_text(FILE *infile) {
    node *n = NULL;
    char *word = (char *)malloc(MAX_WORD_LENGTH*sizeof(char));
    while (fscanf(infile, "%s ", word) != -1) {
        node* ptr = find_list(n, word);
        if (ptr==NULL) {
            n = insert_first_list(n, word); // Le mot n'existe pas dans la liste
        }        
    }
    free(word);
    return n;
}

int list_length(node *lst) {
    int distinct_words = 0;
    node *ptr;
    for (ptr = lst; ptr != NULL; ptr = ptr->next) {
        distinct_words++;
    }
    return distinct_words;
}

int main(int argc, char* argv[]){
    FILE *f = fopen("Germinal.txt", "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file for reading 'Germinal.txt'.\n");
        return 1;
    }

    node *lst = read_text(f);
    fclose(f);

    printf("%d different words found in Germinal.\n", list_length(lst));
    free_list(lst);

	return 0;
}