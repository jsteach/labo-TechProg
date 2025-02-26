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
	//stack temporaire pour contenir les éléments
	Stack* tempo = (Stack*)allocate(sizeof(Stack));
	//tant que ma stack n'est pas vide,mettre l'élément le plus récent a l'aide de pop en premier dans la temporaire avec push
	while (s != NULL) {//tant que la stack n'est pas vide
		push(tempo,pop(s));
	}
	//indiquer que notre stack est maintenant égale a notre stack temporaire;
	s = tempo;
	
}


void sortStack(Stack* s) {
	Stack* tempo = (Stack*)allocate(sizeof(Stack));
	
	for (int i = 0; i < s->max_size; i++){

	}
}
