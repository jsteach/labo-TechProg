#include <stdio.h>

typedef struct Node Node;

struct Node {
	void* data;
	Node* prev;
	Node* next;
};

typedef struct person_t {
	char name[256];
	size_t age;
} Person;

void insert(Node* currNode, void* newData){
	Node n = { 0 };
	n.data = newData;
	n.prev = NULL;
	n.next = NULL;
	if (currNode->next != NULL) {
		n.next = currNode->next;
		currNode->next->prev = n;
	}
	currNode->next = n;
	n.prev = currNode;
}

void insertTail(Node* head, void* newData){

}

void insertHead(Node* head, void* newData){

}

Node* removeNode(Node* currNode){

	return NULL;
}

void alphabetise(Node* head, char* names[]){

}
