#include <stdbool.h>;
#include "labo.h";
#include <stdlib.h>
#include <stdbool.h>


void* allocate(size_t size) {

}

typedef struct person_t {
	char name[256];
	size_t age;
} Person;

void insert(Node* currNode, void* newData) {
	Node n = { 0 };
	n.data = newData;
	n.prev = NULL;
	n.Next = NULL;
	if (currNode->Next != NULL) {
		n.Next = currNode->Next;
		currNode->Next->prev = n;
	}
	currNode->Next = n;
	n.prev = currNode;
}

void insertTail(Node* head, void* newData) {

}


void insertHead(Node* head, void* newData) {
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->data = newData;
		head->Next = NULL;
		head->prev = NULL;
		return;

	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->Next = head;
	newNode->prev = NULL;
	head->prev = newNode;
	head = newNode;
}


Node* removeNode(Node* currNode) {

}


void alphabetise(Node* head, char* names[]) {

}