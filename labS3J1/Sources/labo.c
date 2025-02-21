#include<stdio.h>
#include "labo.h"


void insert(Node* currNode, void* newData)
{
	Node*n = allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;
	if (currNode->next != NULL) {
		n->next = currNode->next;
	}
	currNode->next = n;
}

void insertHead(Node* head, void* newData){
	if (head->data == NULL) {
		head->data = newData;
		return;
	}
	insert(head, newData);
}

Node* removeByData(Node* head, void* rmData)
{
	Node* nodeActuel = head;
	Node* nodeprecedent = NULL;
	while (nodeActuel != NULL && nodeActuel->data != rmData) {
		nodeprecedent = nodeActuel;
		nodeActuel = nodeActuel->next;
	}
	if (nodeActuel == NULL) {
		return NULL;
	}
	nodeprecedent->next = nodeActuel->next;
	memset(nodeActuel, 0, sizeof(Node));
	return nodeprecedent;
}

Node* removeByName(Node* head, char* name)
{
	Node* nodNow = head;
	Node* nodeAvant = NULL;
	Person* p = (Person*)nodNow->data;
	while (nodNow != NULL && p->name != name) {
		nodeAvant = nodNow;
		nodNow = nodNow->next;
	}
	if (nodNow == NULL) {
		return NULL;
	}
	nodeAvant->next = nodNow->next;
	memset(nodNow, 0, sizeof(Node));
	return nodeAvant;
}

void sort(Node* head)
{
	Person* personne1 = (Person *)head->data;
	Person* personne2 = (Person*)head->next->data;
	while (head != NULL && personne1->age > personne2->age) {
		int temp = personne1->age;
		personne1->age = personne2->age;
		personne2->age = temp;
	}
}
