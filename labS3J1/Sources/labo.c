#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "labo.h"
/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData){
	Node* newNode = (Node*)allocate(sizeof(Node));
	newNode->data = newData;
	newNode->next = NULL;
	if (currNode->next != NULL) {
		newNode->next = currNode->next;
	}
	currNode->next = newNode;
}
/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData){
	if (head->data == NULL) { //si le noeud est vide il va attribuer de nouvelle donnees
		head->data = newData;
	}
	else {
		Node* newNode = (Node*)allocate(sizeof(Node));
		newNode->data = newData;
		newNode->next = head->next;
		head->next = newNode;
	}

}
/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData){
	Node* temp = head;
	Node* last = NULL;
	while (temp != NULL && temp->data != rmData) {
		last = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		return;
	}
	if (last != NULL) {
		last->next = temp->next;
	}
	else {
		head = temp->next;
	}
	memset(temp, 0, sizeof(Node)); //reset de la memoire

	return last;
}
/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name){
		Node* temp = head;
		Node* last = NULL;
		while (temp != NULL && temp->data != name) {
			last = temp;
			temp = temp->next;
		}
		if (temp == NULL) {
			return;
		}
		if (last != NULL) {
			last->next = temp->next;
		}
		else {
			head = temp->next;
		}
		memset(temp, 0, sizeof(Node));

		return last;
}
/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head){
	Node* i = head;
	Node* j = i->next;
	for (i = head; i->next != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			Person* info_1 = (Person*)i->data;
			Person* info_2 = (Person*)j->data;
			Person temp;
			if (info_1->age > info_2->age) {
				temp = *info_1;
				*info_1 = *info_2;
				*info_2 = temp;
			}
		}
	}
}
