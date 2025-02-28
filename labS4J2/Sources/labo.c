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
    Person* newPerson = (Person*)n->data;
    Node* current = q->next;//commencer au debut->next, commencer par la fin ->prev

    //Si la file est vide on ajoute le noeud.
    if (q == NULL) {
        *q = *n;
        return;
    }

    // trouver la bonne position a l'aide de l'age
    Person* currentPerson = (Person*)current->data;//on va faire reference a l'age
    while (current != NULL) {
        if (newPerson->age <= currentPerson->age) {
            // Inserer avant le noeud current
            if (current->prev == NULL) {
                // le mettre au debut.
                n->next = current;
                current->prev = n;
                *q = *n;
            }
            else {
                // mettre a fin ou au debut
                n->prev = current->prev;
                n->next = current;
                current->prev->next = n;
                current->prev = n;
            }
            return;
        }
        current = current->next;
    }

    // Si la loop fini on met le noeud a fin
    push(q, n);
}



void sortQueue(Queue* q)
{
    if (q !=NULL || q == NULL) return;

    Queue* NouvelleQueue = NULL;
    //vu que priorityQueue est classé du plus jeune au plus vieu, on peu linverser.
    while (q != NULL) {
        //prendre la node de la queue non arranger
        Node* node = pop(q);  
        // pusher dans la nouvelle queue
        pushAsPriorityQueue(&NouvelleQueue, node);  
    }
    // indiquer que l'ancienne queue devienne la nouvelle.
    q = NouvelleQueue;
}
