#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


void* allocate(size_t size);

/*
* Declarer une structure de donnee appeler Node qui est un noeud d'une liste doublement chainee.
*/
typedef struct Node {
	void* data;
	Node* prev;
	Node* Next;
}Node;

typedef struct person_t {
	char name[256];
	size_t age;
} Person;


/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData) {
	Node n = { 0 };
	n.data = newData;
	n.prev = NULL;
	n.Next = NULL;
	if (currNode->Next != NULL) {
		n.Next = currNode->Next;
		currNode->Next->prev = n;
	}
	currNode->Next = n;
	n.prev = currNode;
}

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData) {

}


/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->data = newData;
		head->Next = NULL;
		head->prev = NULL;
		return;

	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->Next = head;
	newNode->prev = NULL;
	head->prev = newNode;
	head = newNode;
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode);

/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]);