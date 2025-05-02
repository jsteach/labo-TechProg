#include "labo.h"

void insert(Node* currNode, void* newData) {
	Node* n = { 0 };
	n->data = newData;
	n->prev = NULL;
	n->next = NULL;
	if (currNode->next != NULL) {
		n->next = currNode->next;
		currNode->next->prev = n;
	}
	currNode->next = n;
	n->prev = currNode;
}
void insertTail(Node* head, void* newData) {
	Node* n = { 0 };
	n->data = newData;
	n->prev = n->next;
	n->next = n;
	if (head->data == NULL) {
		head = n->next;
	}
}
void insertHead(Node* head, void* newData) {
	Node* n = { 0 };
	n->data = newData;
	n->next = head->next;
	if (head->data == NULL) {
		head = n->next;
	}
}
Node* removeNode(Node* currNode) {

}
void alphabetise(Node* head, char* names[]) {

}