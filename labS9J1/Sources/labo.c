#include "labo.h"
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


void add_adjacent_node(Node* root, Node* node) {
	root->adj[root->len] = node;
	root->len++;
};


int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
	int VisitCount = 0;

	if (curr == NULL) {
		curr = root[0];
	}
	stack_push(s, curr); 
	curr->visited = 1;

	while (s->top > -1) {
		Node* PopNode = stack_pop(s);
		curr = PopNode;
		VisitCount++;

		if (curr->data == key) {
			while (s->top > -1) stack_pop(s);

			Stack tempStack = stack_init(100);
			stack_push(&tempStack, curr);

			while (curr->revPath != NULL && curr->revPath->prev != NULL) {
				curr = curr->revPath->prev->data;
				stack_push(&tempStack, curr);
			}

			while (tempStack.top > -1) {
				stack_push(s, stack_pop(&tempStack));
			}

			return VisitCount;
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

int bfs(Node* root[], void* key, Stack* s) {
	int VisitCount = 0;
	Queue Queue;
	queue_init(&Queue);

	Node* curr = root[0];
	curr->visited = 1;
	curr->revPath->data = curr; 
	curr->revPath->prev = NULL;
	queue_push(&Queue, curr);

	while (Queue.count > 0) {
		curr = queue_pop(&Queue);
		VisitCount++;

		if (curr->data == key) {
			stack_push(s, curr);

			while (curr->revPath && curr->revPath->prev) {
				curr = curr->revPath->prev->data;
				stack_push(s, curr);
			}

			return VisitCount;
		}

		for (int i = 0; i < curr->len; i++) {
			Node* adjnode = curr->adj[i];
			if (adjnode->visited == 0) {
				adjnode->visited = 1;

				adjnode->revPath->data = adjnode;
				adjnode->revPath->prev = curr->revPath;

				queue_push(&Queue, adjnode);
			}
		}
	}

	return VisitCount;
}