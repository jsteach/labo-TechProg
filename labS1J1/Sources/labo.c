#include "labo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char* characters;
	int length;
} String;
char* sousTexte(char* texte, int from, int to)
{
	// Vérification des indices
	if (from < 0 || to < from || to >= strlen(texte)) {
		return NULL; // Retoune NULL si les indices sont invalides 
	}
	// calcul de la taille du sous-tableau
	int taille = to - from + 1;
	// Allocation de mémoire pour le sous-tableau
	char* mot_extraire = (char*)malloc((taille + 1) * sizeof(char));
	mot_extraire[taille] = '\0';

	return mot_extraire;

	//return nullptr;
}

void set_String(char* text, String* s)
{
	s->length = strlen(text);
	s->characters = (char*)malloc((s->length + 1) * sizeof(char));
	strcpy(s->characters, text);

}

int String_is_palindrome(String* s)
{
	int from = 0;
	int to = s->length - 1;
	while (from < to) {
		if (s->characters[from] != s->characters[to]) {
			return 0; // On a pas de Palindrome
		}
		from++;
		to--;
	}
	return 1; // On a un palindrome
		

}

void bubbleSort(int elements[], int n)
{
}
