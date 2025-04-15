#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, visited a faux, len a 0, allouer de la memoire pour le QNode et assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data) {
	Node* newNode = (Node*)allocate(sizeof(Node));
	(char*)newNode->data = (char*)data;
	memset(newNode->adj, 0, sizeof(newNode->adj));
	newNode->visited = 0;
	newNode->len = 0;
	newNode->revPath = (QNode*)allocate(sizeof(QNode));
	newNode->revPath->data = newNode;
	newNode->revPath->prev = NULL;
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

			Stack tempStack = stack_init(100);
			stack_push(&tempStack, curr); // Je fais un temp stack pour que je puisse l'inverser. Ex: A, B = B, A

			while (curr->revPath != NULL && curr->revPath->prev != NULL) {
				curr = curr->revPath->prev->data;
				stack_push(&tempStack, curr);
			} // Je recompose le chemin dans le stack temporaire

			while (tempStack.top > -1) {
				stack_push(s, stack_pop(&tempStack));
			} // Je vide le stack temporaire dans celui actuel pour l'inverser.

			return VisitedCounter;
		}
		for (int i = 0; i < curr->len; i++) {
			if (curr->adj[i]->visited == 0) {
				curr->adj[i]->visited = 1;
				curr->adj[i]->revPath->prev = curr->revPath;
				stack_push(s, curr->adj[i]);
			}
		} // J'ajoute les nodes adjacents et je set leur parent

	}
	return -1;
};

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s) {
    int VisitedCounter = 0;
    Queue BFS_Queue;
    queue_init(&BFS_Queue);

    Node* curr = root[0];
    curr->visited = 1;
    curr->revPath->data = curr; //Je sais pas si revpath c'est comme ca que je devais l'utiliser mais ca marche
    curr->revPath->prev = NULL;
    queue_push(&BFS_Queue, curr);

    while (BFS_Queue.count > 0) {
        curr = queue_pop(&BFS_Queue);
        VisitedCounter++;

        if (curr->data == key) {
            stack_push(s, curr);

            while (curr->revPath && curr->revPath->prev) {
				curr = curr->revPath->prev->data;
                stack_push(s, curr);
            }

            return VisitedCounter;
        }

		//J'ajoute les voisins dans la queue
        for (int i = 0; i < curr->len; i++) {
            Node* adjnode = curr->adj[i];
            if (adjnode->visited == 0) {
				adjnode->visited = 1;

				adjnode->revPath->data = adjnode;
				adjnode->revPath->prev = curr->revPath;

                queue_push(&BFS_Queue, adjnode);
            }
        }
    }

    return -1;
}