#include <stdio.h>
#include "labo.h"

long long fibonacci(int n)
{
	if (n == 0 || n == 1) {
		return n; 
	}
	else {
		return (fibonacci(n - 1) + fibonacci(n - 2));
	}
}

//SOURCE: https://waytolearnx.com/2019/08/suite-de-fibonacci-en-c.html

TreeNode* tree_create_node(void* data)
{
	Node* n = allocate(sizeof(Node));
	n->prev = NULL;
	n->next = NULL;
	n->data = data;
	return n;
}

void tree_add_node(TreeNode* root, TreeNode* node)
{
	if (root->left == NULL && root->right != NULL) {
		root->left = node;
	}
	if (root->right == NULL && root->left != NULL) {
		root->right = node;
	}
	if (root->left == NULL && root->right == NULL) {
		root->left = node;
	}
	if (root->left != NULL && root->right != NULL) {
		return;
	}
}

int dfs(TreeNode* root, void* key)
{
	//Ne fonctionne pas

	/*int count = 0;
	Stack* s;
	TreeNode* currNode = stack_pop(&s);
	if (currNode == key) {
		count += 1;
		return count;
	}
	if (currNode->left != NULL) {
		dfs(currNode->left, key);
	}
	if (currNode->right != NULL) {
		dfs(currNode->right, key);
	}
	return;*/
}

int bfs(TreeNode* root, void* key)
{
	Queue q;
	queue_init(&q);
	queue_push(&q, root);
	int count = 0;
	while (&q != NULL) {
		TreeNode* currNode = queue_pop(&q);
		count += 1;
		if (currNode->data == key) {
			return count;
		}
		if (currNode->left != NULL) {
			queue_push(&q, currNode->left);
		}
		if (currNode->right != NULL) {
			queue_push(&q, currNode->right);
		}
	}
	return;
}

