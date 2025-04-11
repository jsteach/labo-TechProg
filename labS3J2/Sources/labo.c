#include <stdio.h>
#include "labo.h"
/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData) {

	Node* n = (Node*)allocate(sizeof(Node));
	n->data = newData;
	n->prev = NULL;
	n->next = NULL;

	if (currNode->next == NULL && currNode->prev == NULL) {

		currNode->prev = n;
		currNode->next = n;
	}
	else {

		currNode->prev->next = n;
		n->prev = currNode->prev;
		currNode->prev = n;
		currNode->next->prev = n;
		currNode->prev->next = currNode->next;

	}

	return;
}

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData) {

	if (head->data == NULL) {
		head->data = newData;
	}
	else{
		insert(head, newData);
	}
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {

	if (head->data == NULL) {
		head->data = newData;
	}
	else {
		insert(head, newData);
	}
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode) {

	currNode->prev->next = currNode->next;
	currNode->next->prev = currNode->prev;
	currNode->next = NULL;
	currNode->prev = NULL;
	return currNode;
}

/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]) {

	return;
}