#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

/**
 * Création d'une node représentant 1 occurrence de la chaîne 'path' associé à sa taille 'size'.
 * La chaîne doit être copiée lors de la création et libérée lorsque la node est libérée de la mémoire.
 */
node *create_node(char path[], long int size) {
    node *n = malloc(sizeof(node));
    n->path = malloc(strlen(path)+1);
    strcpy(n->path, path);
    n->size = size;
    n->next = NULL;
    return n;
}

void free_node(node *n) {
    free(n->path);
    free(n);
}


void free_list(node *lst) {
    while (lst) {
        node *tmp = lst;
        lst = lst->next;
        free_node(tmp);
    }
}

// Renvoie la taille de la liste
int size_list(node* list) {
	node* tmp = list;
	int size = 0;
	while (tmp!=NULL) {
		size++;
		tmp = tmp->next;
	}
	return size;
}

/*	Insère l'élément dans la liste puis renvoie la liste mis à jour
 *	Insertion en gardant un ordre croissant
 */
node* insert_list(node* list, char path[], long int size) {
	node* tmp = list;
	node *n = create_node(path, size);

	while (tmp!=NULL) {
		// Dans le cas où on a parcouru toute la liste (on ajoute à la fin)
		if (tmp->next == NULL) {
			tmp->next = n;
			return list;
		}

		// Dans le cas où on insère au début de la liste
		if (tmp->size>=size) {
			n->next = tmp;
			return n;
		}

		// Dans le cas où on insére au milieu de la liste
		if (tmp->next->size>=size) {
			n->next = tmp->next;
			tmp->next = n;
			return list;
		}

		tmp = tmp->next;
	}

	// Cas où on a une liste vide
	tmp = n;
	return tmp;;
}

/*	Vérifie si la nouvelle valeur doit être insérée et renvoie la liste une fois l'ajout terminé.
 */
node* verify_and_insert_list(node* list, char path[], long int size) {
	// Si - de 10 éléments : on renvoie la liste directement
	if(size_list(list)<10) {
		list = insert_list(list, path, size);
		return list;
	}

	// Sinon, on ajoute à la liste seulement si notre plus petite valeur est inférieur à la nouvelle valeur (size)
	if (list->size<size) {
		list = insert_list(list, path, size);
		node* tmp = list;
		list = list->next;
		free_node(tmp);
		return list; // On renvoie la 2ème valeur de la chaîne pour garder une taille de 10 éléments
	}

	// Il ne s'est rien passé : déjà 10 éléments | Le nouvel élément est trop petit
	return list;
}

/* Affichage en ordre décroissant des fichiers trouvés.
 */
void print_files(node* list) {
	if (list == NULL) {
		return;
	}
	print_files(list->next);
	printf("%s : %ld octets\n", list->path, list->size);
}