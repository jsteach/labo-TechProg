#include "labo.h"
#include <stdio.h>
#include <stdbool.h>
//adding comment to pull request, hopefully

void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;
	if (currNode->next != NULL) {
		n->next = currNode->next;
	}
	currNode->next = n;
}

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL) {
		head->data = newData;
		//return;
	}
	else {
		insert(head, newData);
	}
}

Node* removeByData(Node* head, void* rmData)
{
	Node* currNode = head;
	Node* previous = NULL;
	while (currNode != NULL) {

		if (currNode->data == rmData) {

			if (previous != NULL) {
				previous->next = currNode->next;
				memset(currNode, 0, sizeof(currNode));
				return previous;
			}
			else {
				head = currNode->next;
				return NULL;
			}
			
		}
previous = currNode;
			currNode = currNode->next;
	}
}

Node* removeByName(Node* head, char* name)
{
	Node* currNode = head;
	Node* previous = NULL;

	while (currNode != NULL) {
		Person* p = (Person*)currNode->data;

		if (strcmp(p->name, name) == 0) {
			if (previous != NULL) {
				previous->next = currNode->next;
				memset(currNode, 0, sizeof(currNode));
				return previous;
			}
			else {
				head = currNode->next;
				return NULL;
			}
		}

		previous = currNode;
		currNode = currNode->next;
	}

	return NULL;
}

void sort(Node* head)
{
	if (head == NULL) return;
	int exchange = true;
	Node* placeholder1;
	Node* placeholder2 = NULL;
	while (exchange)
	{
		exchange = false;
		placeholder1 = head;
		while (placeholder1->next != placeholder2)
		{
			Person* man1 = (Person*)placeholder1->data;
			Person* man2 = (Person*)placeholder1->next->data;
			if (man1->age > man2->age) {
				Person* placeholder3 = placeholder1->data;
				placeholder1->data = placeholder1->next->data;
				placeholder1->next->data = placeholder3;
				exchange = true;
			}
			placeholder1 = placeholder1->next;
		}
		placeholder2 = placeholder1;
	}
}
