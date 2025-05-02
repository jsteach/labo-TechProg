#include "labo.h"

Stack* new_stack(size_t max_size) {
	Stack* s;
	s->max_size = 3;
	s->top = -1;
	s->data = malloc(sizeof(Stack));
}
void push(Stack* s, void* newData) {
	if (s->top + 1 < s->max_size) { //lorsque la premiere donnee est inferieure au nombre maximal de donnees
		s->top += 1; //la premiere donnee devient alors la deuxieme
		s->data[s->top] = newData; //met a jour les donnees de la stack
	}
}
void* pop(Stack* s) {
	void* out = NULL;
	if (s->top - 1 >= 0) { //lorsque que la premiere donnee est superieure a 0
		out = s->data[s->top]; //met la donnee hors des limites de la stack
		s->top -= 1; //supprime la donnee
	}
	return out;
}
void* peek(Stack* s) {
	void* out = pop(s); //rapelle la fonction pop pour acceder a la donnee au sommet de la pile
	if (out != NULL) { 
		push(s, out); //rapelle la fonction push pour ne pas retire la donnee
	}
	return out;
}
void reverseStack(Stack* s) {
	while (s->max_size != s->top) {
		if (s->top + 1 < s->max_size) {
			s->top -= 1;
		}
	}
}
void sortStack(Stack* s) {

}
