#include <stdio.h>
#include <string.h>

typedef struct Node Node;

void* allocate(size_t size) {
	return malloc(size);
}

struct Node {
	void* data;
	Node* next;
};

typedef struct person_t {
	char name[256];
	size_t age;
} Person;

void insert(Node* currNode, void* newData) {
	Node* new_node = allocate(sizeof(Node));
	new_node->data = newData;
	new_node->next = currNode->next;
	currNode->next = new_node;
}

void insertHead(Node* head, void* newData) {
	Node* new_node = allocate(sizeof(Node));
	new_node->data = newData;
	new_node->next = head->next;
	head->next = new_node;
	if (head->data == NULL) {
		head->data = newData;
	}
}

Node* removeByData(Node* head, void* rmData) {
	Node* current = head;
	while (current->next != NULL) {
		if (current->next->data == rmData) {
			Node* temp = current->next;
			current->next = current->next->next;  
			memset(temp, 0, sizeof(Node));  
			free(temp);  
			return current;  
		}
		current = current->next;
	}
	return NULL;
}

Node* removeByName(Node* head, char* name) {
	Node* current = head;
	while (current->next != NULL) {
		Person* person = (Person*)current->next->data;
		if (strcmp(person->name, name) == 0) {  
			Node* temp = current->next;
			current->next = current->next->next;  
			memset(temp, 0, sizeof(Node)); 
			free(temp);  
			return current; 
		}
		current = current->next;
	}
	return NULL;
}

void sort(Node* head) {

}
