#include "labo.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

long long FiboToFind[75] = { 0 }; //je pense que c'est ca qui a fix fibo; welp il m'en donne 76 si j'ecris 75, donc si j'�cris 74 il m'en donne 75; bon ben non, toujours 76 de sorti

long long fibonacci(int n) {
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
}

TreeNode* tree_create_node(void* data)
{
	TreeNode* NewTreeNode = allocate(sizeof(TreeNode));
	NewTreeNode->data = data;
	NewTreeNode->left = NULL;
	NewTreeNode->right = NULL;
	return NewTreeNode;
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

int dfs(TreeNode* root, void* key) //je pourrais utiliser return 6; mais je ne le ferais pas, ce serait de la triche
{
	Stack StackOfDFS = stack_init(sizeof(Stack));

	//ok, j'ai cherché, je ne suis pas sur de comprendre pour le moment, je vais réfléchir un peu plus a ca en fin de semaine

	return;

}

int bfs(TreeNode* root, void* key) //je pourrais utiliser return 6; mais je ne le ferais pas, ce serait de la triche
{

	//ok, j'ai cherché, je ne suis pas sur de comprendre pour le moment, je vais réfléchir un peu plus a ca en fin de semaine
	return;
}