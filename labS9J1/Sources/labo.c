#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, visited a faux, len a 0,
allouer de la memoire pour le QNode et assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data) {
	Node* newnode = (Node*)allocate(sizeof(Node));
	newnode->data = data;
	newnode->visited = 0;
	newnode->len = 0;
	memset(newnode->adj, 0, sizeof(Node) * UINT8_MAX);

	QNode* Qnode = (QNode*)allocate(sizeof(QNode));
	Qnode->next = NULL;
	Qnode->prev = NULL;

	return newnode;
}

/*
* Ajouter le node dans la liste d'adjacence de root.
*/
void add_adjacent_node(Node* root, Node* node) {
	root->adj[root->len++] = node;
	//for (int i = 0; i <= root->adjroot->adj[i] = node;i++) { // Ca ici marche mais O(n)
	//	if (root->adj[i]==NULL){
	//		root->adj[i] = node;
	//		return;
	//	}
	//}
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle.
* Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
* La Stack devrait contenir la liste en ordre inverse de celle parcouru.
* i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner C -> B -> A
*/
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
	if (curr == NULL) {
		curr = root[0];
	}

	curr->visited = 1;
	stack_push(s, curr);

	if (curr->data == key) {
		return 1;
	}

	for (int i = 0; i < curr->len;i++) {
		if (curr->adj[i] != NULL && curr->adj[i]->visited != 1) {
			if (dfs(root, len, curr->adj[i], key, s)) {
				return 1;
			}
		}
	}
	stack_pop(s);
	return 0;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. 
* Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s) {
	Queue* q = (Queue*)allocate(sizeof(Queue));
	queue_init(q);

	queue_push(q, root[0]);
	root[0]->visited = 1;
	root[0]->revPath = NULL;

	while (q->prev!=NULL) {
		Node* temp = (Node*)queue_pop(q);

		if (((Node*)temp)->data == key) {
			Node* revPath = temp;
			while (revPath != NULL) {
				stack_push(s, revPath);
				revPath = (Node*)revPath->revPath;
			}
			return 1;
		}
		
		for (int i = 0; i < temp->len;i++) {
			Node* adj = temp->adj[i];
			if (adj != NULL && adj->visited != 1) {
				queue_push(q, adj);
				adj->visited = 1;
				adj->revPath = temp;
			}
		}
	}
	return 0;
}