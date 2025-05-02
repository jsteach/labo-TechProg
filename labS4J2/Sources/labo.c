#include "labo.h"

void push(Queue* q, Node* n) {
	if (q->next == NULL) {
		q->next = q->prev = n;
	}
	else {
		Node* last = q->next;
		n->next = last;
		last->prev = n;
		q->next = n;
	}
}

Node* pop(Queue* q) {
	Node* n = q->prev;
	if (q->prev != NULL) {
		if (q->prev == q->next) {
			q->next = q->prev = NULL;
		}
		else {
			q->prev = q->prev->prev;
		}
	}
	return n;
}

Node* peek(Queue* q) {
	return q->prev;
}

void pushAsPriorityQueue(Queue* q, Node* n) {
	Node* n = q;
	Person* p;
	while (q->data > p->age ) {
		q->next = q->next->data;
		if (q->data > p->age) {
			void* delete = pop(q);
		}

	}

	
}

void sortQueue(Queue* q) {

}