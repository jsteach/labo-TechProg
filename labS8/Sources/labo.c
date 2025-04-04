#include "labo.h"

/*
* Programmer l'algorithme de fibonacci. Commencer par faire l'algorithme de base et par la suite ajouter la memoization.
* Faire attention lorsque vous utilisez un type pour une variable qui represente un nombre, int ne depasse pas 2^31-1 ou 2,147,483,647
*/
long long memoization[2048] = { 0 };
long long fibonacci(long long n) {
	if (n <= 1) {
		return n;
	}
	if (memoization[n] != 0) {
		return memoization[n];
	}

	memoization[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return memoization[n];
};

/*
* Creer un Noeud, assigner lui la valeur de data, metter c'est reference a NULL et retourner le noeud.
*/
TreeNode* tree_create_node(void* data) {
	TreeNode* Treenode = (TreeNode*)allocate(sizeof(TreeNode));

	Treenode->data = data;
	Treenode->left = NULL;
	Treenode->right = NULL;

	return Treenode;
}

/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de left a right. Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
void tree_add_node(TreeNode* root, TreeNode* node) {
	if (root->left == NULL && root->right == NULL) {
		root->left = node;
		return;
	}
	if (root->left != NULL && root->right != NULL) {
		return;
	}
	if (root->left == NULL) {
		root->left = node;
		return;
	}
	if (root->right == NULL) {
		root->right = node;
		return;
	}
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key) {
	TreeNode* temp = root;
	Stack s = stack_init(16);
	int nodes_visited = 0;

	if (root->data == key) {
		nodes_visited++;
		return nodes_visited;
	}

	stack_push(&s, temp);

	while (s.top != -1 && temp->data != key) {
		temp = stack_pop(&s);
		if (temp->right != NULL) {
			stack_push(&s, temp->right);
		}
		if (temp->left != NULL) {
			stack_push(&s, temp->left);
		}
		nodes_visited++;
	}

	return nodes_visited;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/
int bfs(TreeNode* root, void* key) {
	int nodes_visited = 0;
	TreeNode* temp = root;
	Queue q;
	queue_init(&q);

	if (root->data == key) {
		nodes_visited++;
		return nodes_visited;
	}

	queue_push(&q, temp);

	while (q.data != NULL && temp->data != key) {
		temp = queue_pop(&q);
		if (temp->left != NULL) {
			queue_push(&q, temp->left);
		}
		if (temp->right != NULL) {
			queue_push(&q, temp->right);
		}
		nodes_visited++;
	}

	return nodes_visited;

}