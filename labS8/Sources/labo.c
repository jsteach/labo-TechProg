#include "labo.h"
#include <stdio.h>

/*
* Programmer l'algorithme de fibonacci. Commencer par faire l'algorithme de base et par la suite ajouter la memoization.
* Faire attention lorsque vous utilisez un type pour une variable qui represente un nombre, int ne depasse pas 2^31-1 ou 2,147,483,647
*/
long long fibonacci(int n) {

	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return (n-1) + (n-2);
}

/*
* Creer un Noeud, assigner lui la valeur de data, metter c'est reference a NULL et retourner le noeud.
*/
TreeNode* tree_create_node(void* data) {

	TreeNode* NewNode = (TreeNode*)allocate(sizeof(TreeNode));

	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de gauche a droite. Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
void tree_add_node(TreeNode* root, TreeNode* node) {

	if (root->left == NULL) {
		root->left = node;
	}
	else if (root->right == NULL) {
		root->right = node;
	}
	return;
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key) {
	
	Stack pile = stack_init(256);
	
	if (root->data != key) {
		stack_push(&pile, root);
	}

	return;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/
int bfs(TreeNode* root, void* key) {

	return;
}