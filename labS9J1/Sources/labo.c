#include "labo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




Node* create_node(void* data) {
	Node* NewNode = allocate(sizeof(Node));
	NewNode->data = data;
	memset(NewNode->adj,0,sizeof(Node*)* UINT8_MAX);

	NewNode->visited = 0;
	NewNode->len = 0;
	QNode* NewQNode = allocate(sizeof(QNode));
	NewQNode->prev = NULL;
	NewQNode->data = NULL;
	NewNode->revPath = NewQNode;
	return NewNode;
}


void add_adjacent_node(Node* root, Node* node) {
	root->adj[root->len] = node;
	root->len++;
}


int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
	if (curr == NULL)
	{
		int ValidateCode = 0;
		for (int i = 0; i < len; i++)
		{
			ValidateCode = dfs(root, len, root[i], key, s);
			if (ValidateCode != 0)
			{
				break;
			}
		}
	}
	else
	{
		curr->visited = 1;
		stack_push(s, curr);
		if (curr->data == key)
		{
			return 1;
		}
		else
		{
			int count =0;
			for (int i = 0; i < curr->len; i++)
			{
				if (curr->adj[i]->visited == 0)
				{
					int ValidateCode = 0;
					ValidateCode = dfs(root, len, curr->adj[i], key, s);
					if (ValidateCode != 0)
					{
						return ValidateCode;
					}
				}
				count++;
				if (count == curr->len)
				{
					stack_pop(s);
					return 0;
				}
			}
		}
	}
}


int bfs(Node* root[], void* key, Stack* s) {
	Queue* TempQueue1 = allocate(sizeof(Queue));
	queue_init(TempQueue1);

	Node* TempNode1 = root[0];
	queue_push(TempQueue1, TempNode1);

	int count = 0;
	while (TempNode1 != NULL)
	{
		TempNode1 = queue_pop(TempQueue1);
		TempNode1->visited = 1;
		count++;
		if (TempNode1->data == key)
		{
			break;
		}
		for (int i = 0; i < TempNode1->len; i++)
		{
			if (!TempNode1->adj[i]->visited) 
			{
				queue_push(TempQueue1, TempNode1->adj[i]);
				if (TempNode1->adj[i]->revPath->data == NULL)
				{
					TempNode1->adj[i]->revPath->data = TempNode1;
				}
			}
		}
	}
	while (TempNode1 != NULL)
	{
		stack_push(s, TempNode1);
		TempNode1 = TempNode1->revPath->data;
	}
	return count;
}