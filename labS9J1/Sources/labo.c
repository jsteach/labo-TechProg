#include "labo.h"
#include <stdio.h>
#include <string.h>

Node* create_node(void* data)
{
	Node* node = (Node*)allocate(sizeof(Node));
	assert(node != NULL);

	node->data = data;
	memset(node->adj, 0, sizeof(Node*) * UINT8_MAX);
	node->len = 0;
	node->visited = 0;

	node->revPath = (QNode*)allocate(sizeof(QNode));
	assert(node->revPath != NULL);
	node->revPath->prev = NULL;
	node->revPath->next = NULL;
	node->revPath->data = node;
	node->revPath->count = 0;



	return node;
}

void add_adjacent_node(Node* root, Node* node)
{
	if (root == NULL || node == NULL || root->len >= UINT8_MAX) return;
	root->adj[root->len++] = node;
}

int dfs(Node* root[], int len, Node* curr, void* key, Stack* s)
{
	if (curr == NULL) {
		/*for (int i = 0; i < len; i++)
		{
			root[i]->visited = 0;
		}*/

		for (int i = 0; i < len; i++)
		{
			if (!root[i]->visited) {
				if (dfs(root, len, root[i], key, s)) {
					return 1;
				}
			}

		}
		return 0;
		
	}
	/*if (curr == NULL) {
		
	}*/
	curr->visited = 1;

	if ( curr->data == key)
	{
		stack_push(s, curr);
		return 1;

	}

	for (uint8_t i = 0; i < curr->len; i++) {
		Node* next = curr->adj[i];
		if (next != NULL && !next->visited) {
			if (dfs(root, len, next, key, s)) {
				stack_push(s, curr);
				return 1;
			}
		}
	}
		
	return 0;

}

int bfs(Node* root[], void* key, Stack* s)
{
	Queue q;
	queue_init(&q);

	for (int i = 0; root[i] != NULL; i++) {
		root[i]->visited = 0;
		root[i]->revPath = NULL;

	}
	for (int i = 0; i < root[i]; i++)
	{
		if (!root[i]->visited) {
			root[i]->visited = 1;
			queue_push(&q, root[i]);

			while (q.count > 0)
			{
				Node* curr = (Node*)queue_pop(&q);
				if (strcmp((char*)curr->data, (char*)key) == 0) {
					while (curr != NULL)
					{
						stack_push(s, curr);
						if (curr->revPath != NULL)
							curr = (Node*)curr->revPath->data;
						else
							curr = NULL;

					}

					Stack tmp = stack_init(s->max);
					while (s->top >= 0)
						stack_push(&tmp, stack_pop(s));
					*s = tmp;

					return tmp.top;


				}
				for (int j = 0; j < curr->len; j++) {
					Node* next = curr->adj[j];
					if (next != NULL && !next->visited) {
						next->visited = 1;

						QNode* rev = (QNode*)malloc(sizeof(QNode));
						rev->data = curr;
						rev->prev = NULL;
						rev->next = NULL;
						rev->count = 0;
						next->revPath = rev;

						queue_push(&q, next);

					}
				}


			}

		}

	}
	
	return 0;
}
