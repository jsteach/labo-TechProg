#include <stdbool.h>
#include "labo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



void push(Queue* q, Node* n)
{
	if (q->head == NULL) {
		q->head = n;
		q->tail = n;
	}
	else {
		q->tail->next = n;
		n->prev = q->tail;
		q->tail = n;
	}
	n->next = NULL;

}

Node* pop(Queue* q)
{
	if (q->head == NULL) {
		return NULL;
	}
	Node* n = q->head;
	q->head = q->head->next;
	if (q->head != NULL) {
		q->head->prev = NULL;
	}
	else {
		q->tail = NULL;
	}
	n->next = NULL;
	n->prev = NULL;
	return n;
}

Node* peek(Queue* q)
{
	return q->head;
}

void pushAsPriorityQueue(Queue* q, Node* n)
{
}

void sortQueue(Queue* q)
{
}
