#include <stdbool.h>;
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));

	n->data = newData;
	n->prev = NULL;
	n->next = NULL;

	if (currNode->next != NULL)
	{
		n->next = currNode->next;
		currNode->next->prev = n;
	}

	currNode->next = n;
	n->prev = currNode;
}

/*
* Creer un noeud et l'ajouter apres le noeud de fin.
* Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));

	n->data = newData;
	n->prev = NULL;
	n->next = NULL;

	if (head->data == NULL)
	{
		head->data = newData;
	}

	if (head->next != NULL)
	{
		n->next = head->next;
		head->next->prev = n;
	}

	head->next = n;
	n->prev = head;
}

/*
* Creer un noeud et l'ajouter apres le noeud head.
* Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));

	n->data = newData;
	n->prev = NULL;
	n->next = NULL;

	if (head->data == NULL)
	{
		head->data = newData;
	}

	if (head->next != NULL)
	{
		n->next = head->next;
		head->next->prev = n;
	}

	n->prev = head;
	head->next = n;
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode)
{
	Node* temp = currNode;

	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	}

	if (temp->prev != NULL) {
		temp->prev->next = temp->next;
	}


	temp->next = NULL;
	temp->prev = NULL;
}


/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic.
* Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[])
{
}