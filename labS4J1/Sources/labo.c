#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"


Stack* new_stack(size_t max_size) {
	Stack* NewStack = (Stack*)allocate(sizeof(Stack));//allouer de la mémoire pour la stack
	NewStack->max_size = max_size;//definir la taille maximale de la stack
	NewStack->data = (void**)allocate(sizeof(void*) * NewStack->max_size);//je dois allouer de la memoire pour la futur data, on multiplie par le max size pour creer un tableau de data
	NewStack->top = -1;//indication quelle est vide.
}


void push(Stack* s, void* newData) {
	if (s->top +1 < s->max_size ) {
		s->top += 1;
		s->data[s->top] = newData;
	}
	else{
		return; 
	}
}



void* pop(Stack* s) {
	void* out = NULL;
	if (s->top >= 0) {
		out = s->data[s->top];
		s->top -= 1;
	}
	return out;
}

void* peek(Stack* s) {
	void* out = pop(s);
	if (out != NULL) {
		push(s, out);
	}
	return out;
}


void reverseStack(Stack* s) {
	void* swap;
	for (int i = 0; i < s->top-i; i++) {
		swap = s->data[i];
		s->data[i] = s->data[s->top-i];
		s->data[s->top - i] = swap;
	}
	
}


void sortStack(Stack* s) {
	//stack temporaire 
	
	Stack* tempo = new_stack(s->max_size);
	Person* TopPerson1 = NULL;
	Person* TopPerson2 = NULL;
	int y = 0;
	for (int i = 0; i < s->top;i++) {//je sais cest bancale comme methode
		while(s->top >= 1){
			//prendre 2 top a comparer
			TopPerson1 = pop(s);
			TopPerson2 = pop(s);
			//si person1 est plus petite que 2 , la mettre dans stack tempo pour ensuite lors du push dans la stack originale se met du plus grand(bas) au plus petit(haut)
			if (TopPerson1->age < TopPerson2->age){
				push(tempo, TopPerson1);
				push(s, TopPerson2);
			}
			else {
				push(tempo, TopPerson2);
				push(s, TopPerson1);
			}
		}
		//mettre les donné de tempo qui est organiser dans la stack originale
		while (tempo->top != -1) {	
			push(s, pop(tempo));
		}
	}
}
