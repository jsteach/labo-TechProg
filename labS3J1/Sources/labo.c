#include <stdbool.h>;
#include "labo.h";
#include <stdlib.h>
typedef struct Node {
	void* data;
	struct Node* Next;
}Node;
void insert(Node* currNode, void* newData) {
	Node n = { 0 };
	n.data = newData;
	n.Next = NULL;
	if (currNode->Next != NULL) {
		n.Next = currNode->Next;
	}
	currNode->Next = n;
}


void insertHead(Node* head, void* newData) {
	if (head->data == NULL) {
		head->data = newData;
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->Next = head;
	head = newNode;

}

Node* removeByData(Node* head, void* rmData)
{
	return NULL;
}

Node* removeByName(Node* head, char* name)
{
	return NULL;
}

void sort(Node* head)
{
}