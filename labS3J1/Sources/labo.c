#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"



void insert(Node* currNode, void* newData) {
	if (currNode == NULL) return;

	Node* newNode = (Node*)allocate(sizeof(Node));
	newNode->data = newData;
	newNode->next = currNode->next;
	currNode->next = newNode;
}

void insertHead(Node* head, void* newData) {
	if (head == NULL) return;
	Node* newNode = (Node*)allocate(sizeof(Node));
	newNode->data = newData;
	newNode->next = head->next;
	head->next = newNode;

}

Node* removeByData(Node* head, void* rmData) {
    if (head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL) {
        if (curr->data == rmData) {
            prev->next = curr->next;
            memset(curr, 0, sizeof(Node));  // enlever le noeud en réinitialisant la mémoire
            free(curr);
            return prev;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

Node* removeByName(Node* head, char* name) {
    if (head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL) {
        Person* person = (Person*)curr->data;
        if (strcmp(person->name, name) == 0) {
            prev->next = curr->next;
            memset(curr, 0, sizeof(Node)); 
            free(curr);
            return prev;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

void sort(Node* head) {
    if (head == NULL || head->next == NULL) return;

    int swapped;
    do {
        swapped = 0;
        Node* curr = head->next;
        while (curr != NULL && curr->next != NULL) {
            Person* person1 = curr->data;
            Person* person2 = curr->next->data;

            if (person1->age > person2->age) { //swap des donnes
                void* temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;

                swapped = 1;
            }
            curr = curr->next;
        }
    } while (swapped);
}

