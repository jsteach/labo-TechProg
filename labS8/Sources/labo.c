#include "labo.h"


static long long fiboTable[1000] = { 0 };

long long fibonacci(int n) {
	if (n == 1 || n == 0) {
		return n;
	}
	if (!fiboTable[n]) {
		fiboTable[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return fiboTable[n];
}
TreeNode* tree_create_node(void* data) {
	TreeNode* node = allocate(sizeof(TreeNode));
	node->data = allocate(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void tree_add_node(TreeNode* root, TreeNode* node) {
	if (root->left == NULL && root->right == NULL) {
		root->left = node;
	}
	else {
		root->right = node;
	}
	if (root->left != NULL && root->right != NULL) {
		return;
	}
}
int dfs(TreeNode* root, void* key) {
	Stack tempoStack = stack_init(100);
	TreeNode* elem = root;
	int nodeVisite = 0;
	stack_push(&tempoStack, root);
	while (elem != NULL) {
		elem = stack_pop(&tempoStack);
		nodeVisite += 1;
		if (elem->right != NULL) {
			stack_push(&tempoStack, elem->right);
		}
		if (elem->left != NULL) {
			stack_push(&tempoStack, elem->left);
		}
		if (elem->data == key) {
			return nodeVisite;
		}
	}

}
int bfs(TreeNode* root, void* key) {
	int nodeVisite = 0;
	Queue tempoQueue;
	queue_init(&tempoQueue);
	queue_push(&tempoQueue, root);
	TreeNode* elem = root;
	while (elem != NULL) {
		elem = queue_pop(&tempoQueue);
		nodeVisite += 1;
		if (elem->left != NULL) {
			queue_push(&tempoQueue, elem->left);
		}
		if (elem->right != NULL) {
			queue_push(&tempoQueue, elem->right);
		}
		if (elem->data == key) {
			return nodeVisite;
		}
	}
}

