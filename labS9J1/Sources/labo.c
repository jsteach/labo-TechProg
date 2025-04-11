#include "labo.h"

Node* create_node(void* data) {
	Node* n = data;
	Node* adj = memset; 0;
	Node* visited = 0;
	uint8_t len = 0;
	QNode* q = allocate(sizeof(QNode));
	q->prev = NULL;
	if (n->next == NULL) {
		n->next = q;
	}
	return n->next;
}
void add_adjacent_node(Node* root, Node* node){
	node = root;
	node = node->visited;
	node->visited = 0;
	root = allocate(sizeof(Node));
	while (root != root->visited) {
		if (root != root->visited) {
			return node->len;
		}
		if (node->visited > node->len) {
			node->visited = root->len;
			root->len = revPath;
		}   
	}
}
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {

}
int bfs(Node* root[], void* key, Stack* s) {

}