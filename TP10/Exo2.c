#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell{
	char* first_name;
	char* last_name;
	int age;
	struct cell* next;
}Cell, *List;

Cell* allocate_cell(char* first, char* last, int age) {
	Cell* new_cell;
	new_cell = (Cell*) malloc(sizeof(Cell));
	if (new_cell==NULL) {
		printf("Pas assez de place en mémoire !");
		exit(1);
	}
	new_cell->first_name = first;
	new_cell->last_name = last;
	new_cell->age = age;
	return new_cell;
}

void print_list(List l) {
	List tmp = l;
	while (tmp!=NULL) {
		printf("%s %s, %d ans\n", tmp->first_name, tmp->last_name, tmp->age);
		tmp = tmp->next;
	}
}

void free_cell(Cell* c) {
	free(c->first_name);
	free(c->last_name);
	free(c);
}

void free_list(List l) {
	List tmp = l;
	while (l!=NULL) {
		tmp = l->next;
		free_cell(l);
		l = tmp;
	}
}

// Une autre façon de faire pour passer d'une chaine à une cellule : utilisation de scanf
Cell* cell_from_sentence(char* s) {
	char c = s[0];
	int n = 0;

	char* sub = (char*) malloc(strlen(s)+1);
	int n_sub = 0;

	char* first_name = NULL;
	char* last_name = NULL;

	// On parcourt la chaine
	while (c!='\0' && c!='\n'){
		if(c==' ') { 
			// Si on tombe sur un espace, on coupe et on récupère d'abord le prénom puis le nom
			sub[n_sub]='\0';
			if (first_name==NULL) {
				first_name = (char*) malloc(strlen(sub)+1); // On alloue la taille de notre chaine en fonction de la taille actuelle de la chaine parcourue.
				strcpy(first_name, sub);		    // Ainsi, on évite d'allouer plus de mémoire que nécessaire (strlen(s) par exemple).
				
			} else {
				last_name = (char*) malloc(strlen(sub)+1);
				strcpy(last_name, sub);
			}
			n_sub = 0;
		} else {
			// Sinon, on ajoute le caractère à la suite.
			sub[n_sub]=c;
			n_sub++;
		}
		n++;
		c=s[n];
	}

	// La dernière chaine représente l'âge
	sub[n_sub]='\0';
	int age = atoi(sub);
	free(sub);

	// On créé une nouvelle cellule à partir des infos récupérés et on la renvoie
	Cell* cell = allocate_cell(first_name, last_name, age);
	return cell;
}

int just_age_order(Cell* p1, Cell* p2) {
	if (p1->age<p2->age) {
		return 0;
	}
	return 1;	
}

int name_order(Cell* p1, Cell* p2) {
	int last_cmp = strcmp(p1->last_name, p2->last_name);
	// Comparaison du nom : p2 apparait avant p1 alphabétiquement
	if (last_cmp>0) {
		return 1;
	}
	if (last_cmp==0) {
		int first_cmp = strcmp(p1->first_name, p2->first_name);
		// Comparaison du prénom : p2 apparait avant p1 alphabétiquement
		if (first_cmp>0) {
			return 1;
		}
		// Comparaison juste de l'âge
		if (first_cmp==0) {
			return just_age_order(p1, p2);
		}
	}
	return 0;
}

int age_order(Cell* p1, Cell* p2) {
	// âge p1 < âge p2
	if (p1->age<p2->age) {
		return 0;
	}
	// Les 2 âges sont égaux : donc tri alphabétiquement
	if (p1->age==p2->age) {
		return name_order(p1, p2);
	}
	return 1;
}

List ordered_insertion(List l, Cell* c, int order_func(Cell*, Cell*)) { // 3ème paramètre : une fonction générique prenant 2 argument Cell*
	if (c==NULL) {
		return l;
	}
	if (l==NULL) {
		c->next = NULL;
		l = c;
		return l;
	}

	Cell* tmp = l;
	// Si 1er élément : on insére au début de la liste
	if (order_func(tmp, c)==1) {
		c->next = tmp;
		l = c;
		return l;
	}
	while (tmp->next!=NULL) {
		// Si on trouve l'emplacement de notre cellule : on l'insére
		if (order_func(tmp->next, c)==1) {
			c->next = tmp->next;
			tmp->next = c;
			return l;
		}
		tmp = tmp->next;
	}
	tmp->next = c;
	c->next = NULL;
	return l;
}

// si type_order="age", on tri par rapport à l'âge sinon alphabétiquement
List parse_file(char* name_file, List l, char* type_order) {
	FILE* f = fopen(name_file, "r");
	if (f==NULL) {
		return l;
	}
	char s[4096];
	while (fgets(s, 4096, f)!=NULL) {
		Cell* c = cell_from_sentence(s);
		if (strcmp(type_order, "age")==0) {
			l = ordered_insertion(l, c, age_order);
		} else {
			l = ordered_insertion(l, c, name_order);
		}
		
	}
	fclose(f);
	return l;
}


int main(int argc, char* argv[]) {

	// ---- Premiers tests

	// Cell* personne1 = allocate_cell("Etienne", "ALEXANDRE", 20);
	// Cell* personne2 = allocate_cell("Florian", "ALEXANDRE", 17);
	// personne1->next = personne2;

	// print_list(personne1);
	// free_list(personne1);

	// ----

	List l = NULL;
	l = parse_file("liste_nom.txt", l, "autre");
	print_list(l);
	free_list(l);

	return 0;
}
