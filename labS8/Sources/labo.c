#include "labo.h"
static int memoire[3000];
long long fibonacci(int n)
{
	if (n == 0) {
		return 0;;
	} 
	if (n == 1) {
		return 1;
	}
	if (memoire[n] == 0) {
		memoire[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	else {
		memoire[n];
	}
	return memoire[n];
	
}

TreeNode* tree_create_node(void* data)
{
	TreeNode* node = allocate(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void tree_add_node(TreeNode* root, TreeNode* node)
{
	if (root->left == NULL) {
		root->left = node;
	}
	else if (root->right == NULL) {
		root->right = node;
	}
}

int dfs(TreeNode* root, void* key)
{
	Stack empiler = stack_init(100);
	stack_push(&empiler, root);
	int resultat = 1;
	while (empiler.top != -1) {
		TreeNode* node= stack_pop(&empiler);
	
		if (node->data == key) {

			return resultat++;

		}

		if (node->right) {
			stack_push(&empiler, node->right);
		}
		if (node->left) {
			stack_push(&empiler, node->left);

		}
		resultat++;
	}
}

int bfs(TreeNode* root, void* key)
{
	Queue q;
	queue_init(&q);
	queue_push(&q, root);
	int resultat = 1;
	while (q.count != -1) {
		TreeNode* node = queue_pop(&q);
		if (node->data == key) {

			return resultat++;

		}

		if (node->left) {
			queue_push(&q, node->left);
		}
		if (node->right) {
			queue_push(&q, node->right);

		}
		resultat++;
	}


	return 0;
}
