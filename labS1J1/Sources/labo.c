#include<stdio.h>
#include"labo.h"
#include<string.h>
char* sousTexte(char* texte, int from, int to)
{
	static char sousTableau[512];
	for (int i = 0; i < (to-from); i++) {
		sousTableau[i] = texte[from + i];
	}
	return sousTableau;
}

void set_String(char* text, String* s)
{
	strcpy( s->characters, text);
	s->length = strlen(text);
}

int String_is_palindrome(String* s)
{
	for (int i = 0; i < s->length; i++) {
		if (s->characters[i] == s->characters[s->length - i - 1]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void bubbleSort(int elements[], int n)
{
	
	for (int i = 0; i < n; i++) {
		if (elements[i] < elements[i + 1]) {
			int temp  = elements[i + 1];
			elements[i + 1] = elements[i];
			elements[i] = temp;
		}
		if (i >= n - 1) {
			i = -1;
		}
	}
}
