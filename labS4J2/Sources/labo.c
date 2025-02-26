#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"





void push(Queue* q, Node* n)
{
	if (q->next == NULL) {
		q->next = q->prev = n;
	}
	else {
		Node* last = q->next;
		n->next = last;
		last->prev = n;
		q->next = n;
	}
}



Node* pop(Queue* q) 
{
	Node* n = q->prev;
	if(q->prev != q->next){
		if (q->prev == q->next) {
			q->next = q->prev = NULL;
		}
		else{
			q->prev = q->prev->prev;
		}
	}
	return n;
}




Node* peek(Queue* q) 
{
	return q->prev;
}


void pushAsPriorityQueue(Queue* q, Node* n)
{
    if (!q || !n) return;

    Person* newPerson = (Person*)n->data;
    Node* current = q;

    //Si la file est fide on ajoute le noeud.
    if (q == NULL) {
        *q = *n;
        return;
    }

    // trouver la bonne position a l'aide de l'age
    while (current != NULL) {
        Person* currentPerson = (Person*)current->data;
        if (newPerson->age <= currentPerson->age) {
            // Inserer avant le noeud current
            if (current->prev == NULL) {
                // le mettre au debut.
                n->next = current;
                current->prev = n;
                *q = *n;
            }
            else {
                // mettre a la fin ou au debut
                n->prev = current->prev;
                n->next = current;
                current->prev->next = n;
                current->prev = n;
            }
            return;
        }
        current = current->next;
    }

    // Si la loop fini on le met a fin
    push(q, n);
}



void sortQueue(Queue* q)
{
    if (!q || q == NULL) return;

    Queue* NouvelleQueue = NULL;
    while (q != NULL) {
        //prendre la node de la queue non arranger
        Node* node = pop(q);  
        // pusher dans la nouvelle queue
        pushAsPriorityQueue(&NouvelleQueue, node);  
    }
    // indiquer que l'ancienne queue devienne la nouvelle.
    q = NouvelleQueue;
}
