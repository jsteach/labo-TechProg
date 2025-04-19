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
	// V�rification des indices
	if (from < 0 || to < from || to >= strlen(texte)) {
		return NULL; // Retoune NULL si les indices sont invalides 
	}
	// calcul de la taille du sous-tableau
	int taille = to - from + 1;
	// Allocation de m�moire pour le sous-tableau
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

void bubbleSort(int elements[], int n) {
	int echanger;
	for (int i = 0; i < n - 1; i++) {
		echanger = 0; // R�initialiser echanger � chaque passe
		for (int j = 0; j < n - 1 - i; j++) { // R�duire la port�e � chaque passe
			if (elements[j] > elements[j + 1]) {
				// �change avec une variable temporaire
				int temp = elements[j];
				elements[j] = elements[j + 1];
				elements[j + 1] = temp;
				echanger = 1; // Indiquer qu'un �change a eu lieu
			}
		}
		// Si aucun �change n'a eu lieu, le tableau est d�j� tri�
		if (echanger == 0) {
			break;
		}
	}
}
