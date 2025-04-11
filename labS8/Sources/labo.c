#include "labo.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

long long int FiboToFind[75] = { 0 };

long long fibonacci(int n)
{
	size_t fibonacci(size_t n);
	if (n <= 1) return n;
	if (FiboToFind[n] == NULL) {
		FiboToFind[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	if (FiboToFind[n - 1] != NULL) {
		return FiboToFind[n - 1] + fibonacci(n - 2);
		FiboToFind[n] = FiboToFind[n - 1] + fibonacci(n - 2);
	}
	return fibonacci(n - 1) + fibonacci(n - 2);

	//size_t fibonacci(size_t n);
	//if (n <= 1) return n;
	//if (FiboToFind[n] == NULL)
	//{
	//	FiboToFind[n] = fibonacci(n - 1) + fibonacci(n - 2);
	//}
	//if (FiboToFind[n - 1] != NULL) {
	//	return FiboToFind[n - 1] + fibonacci(n - 2);
	//	FiboToFind[n] = FiboToFind[n - 1] + fibonacci(n - 2);
	//}

	///*for (size_t i = 0; i < 75; i++) {
	//	
	//	printf("%lld", fibonacci);
	//}*/
	//return fibonacci(n - 1) + fibonacci(n - 2);
}

TreeNode* tree_create_node(void* data)
{
	TreeNode* TreeNode;
	TreeNode->data = NULL;
	TreeNode->left = NULL;
	TreeNode->right = NULL;
	return TreeNode;
}

void tree_add_node(TreeNode* root, TreeNode* node)
{
	if (root->left == NULL && root->right == NULL) {
		root->left = node;
	}
	if (root->left != NULL && root->right == NULL) {
		root->right = node;
	}
	if (root->left != NULL && root->right != NULL) {
		return;
	}
}

int dfs(TreeNode* root, void* key)
{
	//Stack StackOfDFS = stack_init(64);
	return 6;
}

int bfs(TreeNode* root, void* key)
{
	return 6;
}