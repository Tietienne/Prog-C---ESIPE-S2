#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "pile.h"

void print_help() {
	printf("Entrez un nombre pour l'ajouter dans la pile.\n");
	printf("Entrez une lettre pour utiliser la fonctionnalité associée.\n");
	printf("Le caractère espace ' ' ou retour chariot servent de délimiteur entre les arguments donnés.\n\n");

	printf("Fonctionnalités :\n");
	printf("a : Affiche la pile\n");
	printf("p : Affiche la tête de la pile\n");
	printf("c : Libère la pile\n");
	printf("r : Echange la tête de la pile avec l'élement qui le précède\n");
	printf("q : Quitter le programme\n");
	printf("h - help : Affiche cette aide\n\n");

	printf("Opérations :\n");
	printf("+ : Addition des 2 élements en tête de pile\n");
	printf("- : Soustraction de l'élément en tête de pile avec son prédécesseur\n");
	printf("* : Multiplication des 2 élements en tête de pile\n");
	printf("/ : Division de l'élément en tête de pile avec son prédécesseur\n");
	printf("%% : Modulo de l'élément en tête de pile avec son prédécesseur\n");
	printf("! : Factorielle de l'élément en tête de pile\n");
	printf("^ : Exponentiation de l'élément en tête de pile avec son prédécesseur\n");
}

// Fonction regroupant toutes les fonctionnalités et opérations de la calculatrice, renvoie la pile si modification
node* pile_switch(char letter, node* p) {
	switch(letter) {
		// Fonctionnalités
		case 'a' : print_pile(p); break;
		case 'p' : print_head(p); break;
		case 'c' : free_pile(p); p = NULL; break;
		case 'r' : p = reverse_head(p); break;
		case 'h' : print_help(); break;

		// Opérations
		case '+' : p = add(p); break;
		case '-' : p = sub(p); break;
		case '*' : p = mul(p); break;
		case '/' : p = division(p); break;
		case '%' : p = mod(p); break;
		case '!' : p = facto(p); break;
		case '^' : p = expo(p); break;

		default : printf("Commande non reconnue : '%c'\n", letter);
	}
	return p;
}

// Fonction de lecture d'une chaîne, renvoie la pile en cas de modification, modifie la valeur de letter si besoin
node* read_string(char* string, node* p, char* letter) {
	// Lecture de la ligne de l'utilisateur
	char* sub = (char*) malloc(strlen(string)+1);
	sub[0] = string[0];
	int i_sub = 1;

	char c = string[0];
	int i = 0;


	while(c!='\0' && c!='\n') {
		i++;
		c = string[i];
		if(c==' ' || c=='\0') { 
			// Si on tombe sur un espace ou fin de ligne
			sub[i_sub] = '\0';
			if (isdigit(sub[0])) {
				// Nombre obligatoirement
				int n = atoi(sub);
				p = insert_pile(p, n);
			} else {
				if (strlen(sub)==1) {
					// Sinon - 1 caractère :
					*letter = sub[0];
					if (*letter == 'q') {
						break; // On quitte la boucle directement
					}
					p = pile_switch(*letter, p);
				} else {
					if (strcmp(sub,"help")==0) {
						print_help();
					} else {
						printf("Commande non reconnue : '%s'\n", sub);
					}
				}
			}
			i_sub = 0;
		} else {
			sub[i_sub] = c;
			i_sub++;
		}
	}
	free(sub);
	return p;
}

int main(int argc, char* argv[]) {
	node* pile = NULL;

	/* Tests sur les fonctions élémentaires */

	// pile = insert_pile(pile, 1);
	// pile = insert_pile(pile, 2);
	// pile = insert_pile(pile, 3);

	// print_pile(pile);

	// print_head(pile);

	// free_pile(pile);

	/* ---- */

	char* string = NULL;
	char letter = 'z';

	while (letter!='q') {
		char* string = readline(NULL);
		pile = read_string(string, pile, &letter);
		add_history(string);
		free(string);
	}
	clear_history();
	free_pile(pile);
	free(string); // Ne sert à rien : pour duper le compilateur - sinon, 'warning' - string not used
	return 0;
}