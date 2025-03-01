#include <stdbool.h>;
#include "labo.h"


/*
* Creer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size)
{
	Stack* s = allocate(sizeof(Stack));

	s->max_size = max_size;
	s->top = -1;
	s->data = allocate(sizeof(Person) * s->max_size);

	return s;
}

/*
* Ajouter l'element sur la stack. Prevener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData)
{
	//top == 0
	if (s-> top + 1 < s->max_size) {
		s->top += 1;
		//top == 1
		s->data[s->top] = newData;
	}
	else {
		return;
	}
}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s)
{
	void* out = NULL;
	if (s->top >= 0)
	{
		out = s->data[s->top];
		s->top--;
	}
	return out;
}

/*
* Retourner l'element du top sans l'enlever de la stack. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s)
{

	void* out = pop(s);
	if (out != NULL) {
		push(s, out);
	}
	return out;
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.
* Vous ne devez pas utiliser la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s)
{
	int start = 0;
	int end = s->top;
	while (start < end)
	{
		int* temp = s->data[start];
		s->data[start] = s->data[end];
		s->data[end] = temp;

		start++;
		end--;
	}

	/*for (int i = 0; i < s->top; i++)
	{
		int* temp = s->data[i];
		s->data[i] = s->data[s->top - i];
		s->data[s->top - i] = temp;
	}*/
	//je sais pas pourquoi il passe pas avec la boucle for pourtant c'est la même logique
}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune.
* Vous ne pouvez pas modifier la propriete data directement.
* Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s)
{
	if (s == NULL || s->top <= 0) {
		return;
	}

	Stack* temp = allocate(sizeof(Stack));
	temp->max_size = s->max_size;
	temp->top = -1;
	temp->data = allocate(sizeof(void*) * temp->max_size);

	while(s->top >=0){
		Person* current = (Person*)peek(s);
		pop(s);

		while (temp->top >= 0 && ((Person*)peek(temp))->age > current->age)
		{
			void* older = peek(temp);
			pop(temp);
			push(s, older);
		}
		push(temp, current);
	}

	while (temp->top >= 0) {
		void* person = peek(temp);
		pop(temp);
		push(s, person);
	}
}