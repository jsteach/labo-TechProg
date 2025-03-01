#include <stdbool.h>;
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));


	n->data = newData;
	n->next = NULL;


	if (currNode->next != NULL)
	{
		n->next = currNode->next;
	}

	currNode->next = n;
}

/*
* Creer un noeud et l'ajouter apres le noeud head.
* Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));

	n->data = newData;
	n->next = NULL;

	if (head->data == NULL)
	{
		head->data = newData;
		return;
	}

	if (head->next != NULL)
	{
		n->next = head->next;
	}

	head->next = n;
}

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData.
* Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData)
{
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL) {
		if (temp->data == rmData)
		{
			last->next = temp->next;
			memset(temp, 0, sizeof(Node));
			return last;
		}

		last = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		return;
	}
	last->next = temp->next;
	free(temp);
}

/*
* Supprimer le noeud ayant le nom passer par name.
* Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name)
{
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL) {
		if (temp->data == name)
		{
			last->next = temp->next;
			memset(temp, 0, sizeof(Node));
			return last;
		}

		last = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		return;
	}
	last->next = temp->next;
	free(temp);
}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head)
{


	bool echanger = true;

	while (echanger) {

		echanger = false;
		Node* temp = head;

		while (temp->next != NULL) {
			if (((Person*)temp->data)->age > ((Person*)temp->next->data)->age) {
				// �change des valeurs
				void* swap = temp->data;
				temp->data = temp->next->data;
				temp->next->data = swap;

				echanger = true;
			}
			temp = temp->next;
		}
	}
}