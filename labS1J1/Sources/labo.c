#include <stdbool.h>;
#include "labo.h"
#include <string.h>

char* sousTexte(char* texte, int from, int to) {
	static char nouveau_tableau[512] = { 0 };
	for (int i = from; i < to; i++) {
		nouveau_tableau[i - from] = texte[i];
	}
	nouveau_tableau[to - from] = 0;
	return nouveau_tableau;
}

void set_String(char* text, String* s)
{
	strcpy(s->characters, text);
	s->length = strlen(text);
}

int String_is_palindrome(String* s) {
	char caractere[512] = { 0 };
	for (int i = 0; i < s->length - 1; i++) {
		if (s->characters[0] != s->characters[s->length - 1])
		{
			return 0;
		}
	}
	return 1;
}

void bubbleSort(int elements[], int n){

	bool echanger = true;

	while (echanger) {

		echanger = false;

		for (int i = 0; i < n - 1; i++) {
			if (elements[i] > elements[i + 1]) {

				echanger = true;

				int temp = elements[i];
				elements[i] = elements[i + 1];
				elements[i + 1] = temp;
			}

			if (i >= n - 1 && echanger == true)
			{
				echanger = false;
				i = -1;
			}
		}
	};
}
