#include "labo.h"

/*
* Programmer l'algorithme de fibonacci. Commencer par faire l'algorithme de base et par la suite ajouter la memoization.
* Faire attention lorsque vous utilisez un type pour une variable qui represente un nombre, int ne depasse pas 2^31-1 ou 2,147,483,647
*/
static int cache[2048];

long long fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	if (cache[n] == 0)
	{
		cache[n] = fibonacci(n - 2) + fibonacci(n - 1);
	}
	else {
		cache[n];
	}

	return cache[n];
}

/*
* Creer un Noeud, assigner lui la valeur de data, metter c'est reference a NULL et retourner le noeud.
*/
TreeNode* tree_create_node(void* data)
{
	TreeNode* n = allocate(sizeof(TreeNode));

	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return n;
}

/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de gauche a droite. 
* Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
void tree_add_node(TreeNode* root, TreeNode* node)
{
	if (root->left == NULL) {
		root->left = node;
	}
	else if (root->right == NULL) {
		root->right = node;
	}
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. 
* Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key)
{
	Stack s = stack_init(100);
	stack_push(&s,root);
	int count = 1;
	while (s.top != -1)
	{
		TreeNode* current = stack_pop(&s);

		if (current->data == key) {
			return count++;
		}

		if (current->right) stack_push(&s, current->right);
		if (current->left) stack_push(&s, current->left);

		count++;
	}
	return 0;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. 
* Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/
int bfs(TreeNode* root, void* key)
{
	Queue q;
	queue_init(&q);
	queue_push(&q,root);
	int count = 1;
	while (q.prev != NULL)
	{
		TreeNode* current = queue_pop(&q);

		if (current->data == key)
		{
			return count++;
		}

		if (current->left) { 
			queue_push(&q, current->left); 
		}
		if (current->right) {
			queue_push(&q, current->right);
		}

		count++;
	}
	return 0;
}
