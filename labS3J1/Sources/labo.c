#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {

	Node* n = (Node*)allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;
	if (currNode->next != NULL) {
		n->next = currNode->next;
	}
	currNode->next = n;

	return;
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {

	Node* n = (Node*)allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;
	if (head->next != NULL) {
		n->next = head->next;
	}
	if (head->data == NULL) {
		head->data = newData;
	}
	head->next = n;

	return;
}

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData) {

	Node* temp = head;
	Node* last = (Node*)allocate(sizeof(Node));
	while(temp->data != rmData) {

		last = temp;
		temp = temp->next;
		if (temp->next == NULL) {

			printf("Error: Couldn't find the value");
			return head;
		}
	}

	last->next = temp->next;
	temp = memset(temp, 0, sizeof(temp));
	return last;
}

/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name) {

	Node* temp = head;
	Node* last = (Node*)allocate(sizeof(Node));
	while(temp->data != name) {

		last = temp;
		temp = temp->next;
		if (temp->next == NULL) {

			printf("Error: Couldn't find the value");
			return head;
		}
	}

	last->next = temp->next;
	memset(temp, 0, sizeof(temp));
	return last;
}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {

	Node* temp = (Node*)allocate(sizeof(Node));
	Node* bubble = head;
	bool change = false;
	while (bubble->next != NULL) {

		temp = bubble;
		if (temp->data >= bubble->next->data) {

			change = true;
			bubble = bubble->next;
			temp->next = bubble->next;
			bubble->next = temp;
		}

		if (bubble->next == NULL && change == true) {

			change = false;
			bubble = head;
		}
		else
		{
			bubble = bubble->next;
		}
		
	}
	return;
}