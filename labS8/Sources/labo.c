#include "labo.h"
/*
* Programmer l'algorithme de fibonacci. Commencer par faire l'algorithme de base et par la suite ajouter la memoization.
* Faire attention lorsque vous utilisez un type pour une variable qui represente un nombre, int ne depasse pas 2^31-1 ou 2,147,483,647
*/
long long int Memory[75] = { 0 };
long long fibonacci(int n) {
	size_t fibonacci(size_t n); {
		if (n <= 1) return n;
		if (Memory[n] == NULL) Memory[n] = fibonacci(n - 1) + fibonacci(n - 2);
		if (Memory[n - 1] != NULL) {
			return Memory[n - 1] + fibonacci(n - 2);
			Memory[n] = Memory[n - 1] + fibonacci(n - 2);
		}
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
		
	
}
/*
* Creer un Noeud, assigner lui la valeur de data, metter c'est reference a NULL et retourner le noeud.
*/
TreeNode* tree_create_node(void* data) {
	TreeNode* Node = allocate(sizeof(TreeNode));
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}
/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de gauche a droite. Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
void tree_add_node(TreeNode* root, TreeNode* node) {
	if (root->left == NULL && root->right == NULL) {
		root->left = node;
	}
	if (root->left != NULL && root->right == NULL) {
		root->right = node;
	}
	if (root->left == NULL && root->right != NULL) {
		root->left = node;
	}
	if (root->left != NULL && root->right != NULL) {
		return;
	}

}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key) {
	

	

}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/
int bfs(TreeNode* root, void* key) {
	
}