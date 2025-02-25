#include <stdbool.h>;
#include "labo.h"


/*
* Creer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size)
{
	Stack* s = (Stack*)allocate(sizeof(s));

	s->max_size = max_size;
	s->top = 0;
	s->data = allocate(sizeof(void*) * s->max_size);

	return s;
	//j'ai eu du mal avec la ligne 13 quand je mettais -1 j'avais un bug j'ai monter le code � ChatGPT et il m'a corrig�
}

/*
* Ajouter l'element sur la stack. Prevener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData)
{
	if (s->top == s->max_size - 1)
	{
		printf("Stack overflow!\n");
	}
	else {
		s->top = s->top + 1;
		s->data[s->top] = newData;
	}

	//if (s->top + 1 < s->max_size) {
	//	s->top += 1;
	//	s->data[s->top] = newData;
	//}
	//else {
	//	//printf("Stack overflow!\n");
	//	return;
	//}
}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s)
{
	if (s->top == -1)
	{
		return NULL;
	}
	else {
		s->top = s->top - 1;
		return s->data[s->top];
	}
	/*void* out = NULL;
	if (s->top - 1 >= 0) {
		out = s->data[s->top];
		s->top -= 1;
	}
	return out;*/
}

/*
* Retourner l'element du top sans l'enlever de la stack. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s)
{

	if (s->top == -1)
	{
		return NULL;
	}
	else {
		return s->top;
	}
	/*void* out = pop(s);
	if (out != NULL) {
		push(s, out);
	}
	else {
		return NULL;
	}
	return out;*/
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.
* Vous ne devez pas utiliser la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s)
{
}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune.
* Vous ne pouvez pas modifier la propriete data directement.
* Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s)
{

}