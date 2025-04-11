#include "labo.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


Stack* new_stack(size_t max_size)
{
	Stack* new_stack = allocate(sizeof(Stack));
	new_stack->max_size = max_size;
	new_stack->top = -1;
	new_stack->data = (void**)allocate(sizeof(void*) * max_size);
	return new_stack;
}

void push(Stack* s, void* newData)
{
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
	else {
		printf("Stack is Overflowing\n");
	}
}

void* pop(Stack* s)
{
	if (s->top <= -1) {
		return NULL;
	}
	else {
		return s->data[(s->top)--];
	}
}

void* peek(Stack* s) {
	if (s->top >= 0) {
		return s->data[s->top];
	}
	else
	{
		return NULL;
	}
}

void reverseStack(Stack* s) {
	if (s->top <= -1) {
		return;
	}
	int start = 0;
	int end = s->top;
	while (start < end)
	{
		Person* temp = s->data[start];
		s->data[start] = s->data[end];
		s->data[end] = temp;
		start++;
		end--;
	}
}

void sortStack(Stack* s) {
	Stack* temp_stack = new_stack(s->max_size);
	Person* P1 = NULL;		//person 1
	Person* P2 = NULL;		//person 2
	//int repetitions = s->top;
	while (s->top > 0) {
		P1 = (Person*)pop(s);
		P2 = (Person*)pop(s);
		if (P1->age < P2->age) {
			push(temp_stack, P1);
			push(s, P2);

		}
		else
		{
			push(temp_stack, P2);
			push(s, P1);

		}
	}
		while (temp_stack->top != -1) {
			if (temp_stack->top == 0) {
				push(s, pop(temp_stack));
				return;
			}
			P1 = pop(temp_stack);
			P2 = pop(temp_stack);
			if (P1->age > P2->age) {
				push(s, P1);
				push(temp_stack, P2);
			}
			else {
				push(s, P2);
				push(temp_stack, P1);
			}
		}
}
