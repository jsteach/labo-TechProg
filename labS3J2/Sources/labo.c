#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"

void insert(Node* currNode, void* newData) {
	Node* n = (Node*)allocate(sizeof(Node));
	n->data = newData;
	n->prev = NULL;
	n->next = NULL;
	if (currNode->next != NULL) {
		currNode->next->prev = n;
		n->next = currNode->next;
	}
	currNode->next = n;

}


void insertTail(Node* head, void* newData) {
	if (head->data == NULL) {
		head->data = newData;
		head->next = head;
		head->prev = head;
		return;
	}
	insert(head->prev, newData);

}


void insertHead(Node* head, void* newData) {
	if (head->data == NULL) {
		head->data = newData;
		head->next = head;
		head->prev = head;
		return;
	}
	insert(head->next, newData);
}


Node* removeNode(Node* currNode) {
	Node* temp = currNode;
	int wasFound = 0;
	while (temp == currNode) {
		if ((int)temp->data == currNode->data) { wasFound = 1; break; }
		temp = temp->next;
	}
	if (!wasFound) {
		return;
	}
	temp->prev = temp->next;
	temp->next = temp->prev;
	free(temp);
}



void alphabetise(Node* head, char* names[]) {

}