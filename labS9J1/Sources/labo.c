#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, visited a faux, len a 0, allouer de la memoire pour le QNode et assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data) {
	printf("%s\n", (char*)data);
	Node* newNode = (Node*)allocate(sizeof(Node));
	(char*)newNode->data = (char*)data;
	memset(newNode->adj, 0, sizeof(newNode->adj));
	newNode->visited = 0;
	newNode->len = 0;
	newNode->revPath = (QNode*)allocate(sizeof(QNode));
	newNode->revPath->data = newNode;
	return newNode;
};

/*
* Ajouter le node dans la liste d'adjacence de root.
*/
void add_adjacent_node(Node* root, Node* node) {
	root->adj[root->len] = node;
	root->len++;
};

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
* La Stack devrait contenir la liste en ordre inverse de celle parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner C -> B -> A
*/
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
	int VisitedCounter = 0;

	for (int i = 0; i < len; i++) {
		root[i]->visited = 0;
	}
	if (curr == NULL) {
		curr = root[0]; // Commencer a l'index 0 de root si le curr n'existe pas
	}
	stack_push(s, curr); // Créer le stack
	curr->visited = 1;

	while (s->top > -1) {
		Node* PoppedNode = stack_pop(s);
		curr = PoppedNode;
		VisitedCounter++;

		if (curr->data == key) {
			while (s->top > -1) stack_pop(s);
			stack_push(s, curr);
			while (curr->revPath->prev != NULL) {
				curr = curr->revPath->prev->data;
				stack_push(s, curr);
			}
			return VisitedCounter;
		}
		for (int i = 0; i < curr->len; i++) {
			if (curr->adj[i]->visited == 0) {
				curr->adj[i]->visited = 1;
				curr->adj[i]->revPath->prev = curr->revPath;
				stack_push(s, curr->adj[i]);
			}
		}

	}
	return -1;
};

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s){

};