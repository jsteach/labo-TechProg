#include "labo.h"

void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	n->next = currNode->next;
	n->data = newData;
	currNode->next = n;
	
}

void insertHead(Node* head, void* newData)
{
	if(head->data == NULL){
		head->data = newData;
		return;
	}

	insert(head, newData);
}

Node* removeByData(Node* head, void* rmData)
{
	Node* prev;
	Node* current = head;
	while(current->data != NULL && current->data != rmData){
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	memset(current, 0, sizeof(Node));
	return prev;
}

Node* removeByName(Node* head, char* name)
{
	Node* previous;
	Node* current = head;
	Person* data = current->data;
	while(data != NULL && data->name != name){
		previous = current;
		current = current->next;
		data = current->data;
	}
	previous->next = current->next;
	memset(current, 0, sizeof(Node));
	return previous;
}

void sort(Node* head)
{
	void* tmpData;
	Node* currentTarget = head;
	Node* currentNext;
	while(currentTarget->next->next != NULL){
		currentNext = currentTarget->next;
		while(currentNext != NULL){
			Person* curr = currentTarget->data;
			Person* next = currentNext->data;
			
			if(curr->age > next->age){
				tmpData = currentNext->data;
				currentNext->data = currentTarget->data;
				currentTarget->data = tmpData;
			}
			currentNext = currentNext->next;
		}
		currentTarget = currentTarget->next;
	}
}


