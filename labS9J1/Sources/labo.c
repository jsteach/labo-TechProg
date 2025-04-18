#include "labo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>


/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, visited a faux, len a 0, allouer de la memoire pour le QNode et assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data) {
	Node* NewNode = allocate(sizeof(Node));
	QNode* Qnode = allocate(sizeof(QNode));
	((QNode*)NewNode)->prev = NULL;
	NewNode->visited = 0;
	NewNode->data = data;
	memset(NewNode->adj, 0, sizeof(Node*) * UINT8_MAX);
	NewNode->len = 0;
	NewNode->revPath = allocate(sizeof(QNode));
	NewNode->revPath->prev = NULL;
	NewNode->revPath->data = NULL;
	NewNode->revPath->next = NULL;
	NewNode->revPath->count = 0;
	return NewNode;

}




void add_adjacent_node(Node* root, Node* node) {
	if (root == NULL) {
		return;
	}
	root->adj[root->len++] = node;

}

//Stack stack_init(size_t max_size);
//void stack_push(Stack* s, void* element);
//void* stack_pop(Stack* s);

int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
	if (curr == NULL) {
		curr = root[0];
	}
	if (curr->visited) {
		return 0;
	}

	curr->visited = 1;

	if (curr->data == key) {
		stack_push(s, curr);
		return 1;
	}

	for (int i = 0; i < curr->len; ++i) {
		if (!curr->adj[i]->visited) {
			if (dfs(root, len, curr->adj[i], key, s)) {
				stack_push(s, curr);
				return 1;
			}
		}
	}

	return 0;
}

//void queue_init(Queue* q);
//void queue_push(Queue* q, void* data);
//void* queue_pop(Queue* q);

int bfs(Node* root[], void* key, Stack* s) {
	int nodeVisited = 0;
	Queue q;
	queue_init(&q);

	Node* head = root[0];
	head->visited = 1;
	queue_push(&q, head);
	nodeVisited++;

	while (q.prev != NULL) {
		Node* curr = queue_pop(&q);

		if (curr->data ==key) {
			while (curr != NULL) {
				stack_push(s, curr);
				if (curr->revPath)
					curr = curr->revPath->data;
				else
					break;
			}
			return nodeVisited;
		}

		for (int i = 0; i < curr->len; ++i) {
			Node* neighbor = curr->adj[i];
			if (!neighbor->visited) {
				neighbor->visited = 1;
				neighbor->revPath->data = curr;
				queue_push(&q, neighbor);
				nodeVisited++;
			}
		}
	}

	return 0;
}
