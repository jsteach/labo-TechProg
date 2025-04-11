#include <stdint.h>
#include <stdio.h>
#include "labo.h"


Stack* new_stack(size_t max_size){
	Stack* s = allocate(sizeof(Stack)); 
	s->max_size = max_size;
	s->top = -1;
	return s;
}

void push(Stack* s, void* newData){
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
}

void* pop(Stack* s){
	void* out = NULL;
	if (s->top - 1 >= 0) {
		out = s->data[s->top];
		s->top -= 1;
	}
	return out;
}

void* peek(Stack* s){
	void* out = pop(s);
	if (out != NULL) {
		push(s, out);
	}
	else {
		return NULL;
	}
	return out;
}

void reverseStack(Stack* s) {
	/*for (int i = 0; i < s->max_size; i++) {
		if (s->data[s->top] > s->data[i]) {
			int temp = s->data[s->top];
			s->data[s->top] = s->data[i];
			s->data[i] = temp;
		}
	}*/
}

void sortStack(Stack* s){
	/*Stack* tempStack = new_stack(s->max_size);
	for (int i = 0; i < s->max_size; i++) {
		int temp = pop(s->top);
		if (temp > s->top) {
			push(new_stack, s->top);
		}
		else {
			push(new_stack, temp);
			temp = pop(s->top);
		}
	}*/
	//Ici je recommencerai l'operation mais cette fois-ci en poussant de new_stack vers s, et en poussant le plus gros des chiffres compares a la place du plus petit.
}


//Sources: 
// https://www.digitalocean.com/community/tutorials/stack-in-c