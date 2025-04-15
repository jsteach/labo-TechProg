#include "labo.h"

Node* create_node(void* data) {
	Node* newNode = allocate(sizeof(Node));
	memset(newNode->adj, 0, sizeof(Node*) * UINT8_MAX);
	newNode->visited = 0;
	newNode->len = 0;
	newNode->revPath = allocate(sizeof(QNode));
	newNode->revPath->prev = NULL;
	newNode->data = data;
	return newNode;
}

void add_adjacent_node(Node* root, Node* node) {
	root->adj[root->len] = node;
	root->len++;

}
/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
* La Stack devrait contenir la liste en ordre inverse de celle parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner C -> B -> A
*/
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {


	return 0;
}

int bfs(Node* root[], void* key, Stack* s) {
	Queue queue = {0};
	queue_init(&queue);
	Node* currNode = root[0];
	queue_push(&queue, currNode);

  	while (currNode != NULL)
	{
			
		currNode = queue_pop(&queue);
   		currNode->visited = 1;
 		char* data = (char*)currNode->data;
  		if (data == key) {

			Node* pathNode = currNode; 

			while (pathNode != NULL) {
				stack_push(s, pathNode);
				pathNode = pathNode->revPath->prev;
			}
		
			
			return 1;
		}

 		for (int j = 0; j < currNode->len; j++) {
  			queue_push(&queue, currNode->adj[j]);
			currNode->adj[j]->visited = 1;
			currNode->adj[j]->revPath->prev = currNode;
 		}
			
 	}
	return 0;

}