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
	root->adj[UINT8_MAX] = node;
	root->len++;
}
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s) {
	s->max = 3;
	s->top = -1;
	s->elements = malloc(sizeof(Stack));
	if (s->top + 1 < s->max) {
		s->top += 1;
		s->elements[s->top] = key;
	}
	curr = root;
	Node* edge;
	for (int i = 0; i < 1; i++) {
	root[i]->data = curr->visited;
		if (curr->visited == key) {
			return;
		}
		edge = root[i]; 
		if (root[i] == key) {
			return 1;
		}
		else {
			edge = root[i]; 
		}
		return 0;
	}
}
int bfs(Node* root[], void* key, Stack* s) {

}