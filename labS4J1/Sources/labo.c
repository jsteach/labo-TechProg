#include "labo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Stack* new_stack(size_t max_size)
{
	Stack* Stack_N = (Stack*)allocate(sizeof(Stack));
	Stack_N->max_size = max_size;
	Stack_N->data = (Stack*)allocate(sizeof(Stack) * Stack_N->max_size);
	Stack_N->top = -1;
	
}

void push(Stack* s, void* newData)
{
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
	else {
		printf("stack overflow");
	}

}

void* pop(Stack* s)
{
	void* out = NULL;
	if (s->top - 1 >= -1) {
		out = s->data[s->top];
		s->top -= 1;
	}
	return out;
}

void* peek(Stack* s)
{
	void* out = pop(s);
	if (out != NULL) {
		push(s, out);
	}
	return out;
}

void reverseStack(Stack* s)
{
	Stack* Stack_N = new_stack(s->max_size);
	if (s->data == NULL || s->top == -1) {
		return NULL;
	}
	while (s->top != -1) {
		push(Stack_N, pop(s));
	}
	*s = *Stack_N;
}

void sortStack(Stack* s)
{
	Stack* Stack_N = new_stack(s->max_size);
	Stack* Stack_T = new_stack(s->max_size);
	while (s->top != -1) {
		Person* temp = pop(s);
		while (Stack_N->top != -1 && temp->age < ((Person*)Stack_N->data[Stack_N->max_size])){ //attention
			push(Stack_T, pop(Stack_N));
		}
		push(Stack_N, temp);
		while (Stack_T->top != -1) {
			push(Stack_N, pop(Stack_T));
		}
	}
	while (Stack_N->top != -1) {
		push(s, pop(Stack_N));
	}
}