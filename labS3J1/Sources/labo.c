#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"



void insert(Node* currNode, void* newData) {
     Node* n = allocate(sizeof(Node));
     n->data = newData;
     n->next = NULL;
	if (currNode->next == NULL){
        currNode->next = n;
        n->next = currNode->next;
        return;
    }
    currNode->next = n;
}

void insertHead(Node* head, void* newData) {
    if (head->data == NULL) {
        head->data = newData;
        head->next = head;
        return;
    }
    insert(head->next, newData);

}

Node* removeByData(Node* head, void* rmData) {
    Node* temp = head;
    Node* last = NULL;
    while (temp != NULL && temp->data != rmData) {
        last = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    last->next = temp->next;
    free(temp);
}

Node* removeByName(Node* head, char* name) {
    Node* temp = head;
    Node* last = NULL;
    while (temp != NULL && temp->data != name) {
        last = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    last->next = temp->next;
    free(temp);
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

