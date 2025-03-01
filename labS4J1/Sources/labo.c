#include <stdbool.h>
#include "labo.h"


Stack* new_stack(size_t max_size)
{
	Stack* s = allocate(sizeof(Stack));
	
	s->max_size = max_size;
	s->top = -1;
	s->data = allocate(sizeof(Person) * s->max_size);
	
	return s;
}

void push(Stack* s, void* newData)
{
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
	else {
		//printf("Stack overflow\n");
	}
}

void* pop(Stack* s)
{
	void* out = NULL;
	if (s->top >= 0) {
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
	if (s->top == -1) {
		//printf("The Stack is empty\n");
		return;
	}
	void* topElement = pop(s); //Retirer l'element supérieur
	reverseStack(s);
	int i;
	for (i = s->top; i >= 0; i--) {
		s->data[i + 1] = s->data[i];
		
	}
	s->data[0] = topElement;
	s->top++;
}

void sortStack(Stack* s)
{
	if (s->top == -1) {
		// le pile est vide
		return;
	}
	void* topElement = pop(s);
	

}