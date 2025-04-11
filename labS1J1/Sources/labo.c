#include <stdio.h>
#include <stdbool.h>
#include "labo.h"

/*
* Faire une fonction qui retourne un sous-tableau de character de celui passer.
*/
char* sousTexte(char* texte, int from, int to) {
	

	static char newText[512] = {0};
	int currChar = 0;
	
	for (int i = from; i < to; i++) {
		currChar = i - from;
		newText[currChar] = texte[i];
	}

	return newText;
}


/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {
	int len = strlen(text) + 1;
	for (int i = 0; i < len ; i++) {

		s->characters[i] = text[i];
	}
	s->length = len;

	return;
}

/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {

	for (int i = 0; i < s->length - 2; i++) {
		
		if (s->characters[i] != s->characters[s->length - (i + 2)]) {
			return 0;
		}
	}
	return 1;
}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {

	int y = 0;
	bool change = false;
	for (int i = 0; i <= n-1; i++) {

		if (elements[i] >= elements[i + 1]) {

			change = true;
			y = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = y;
		}

		if (i >= n-1 && change == true){

			change = false;
			i = -1;
		}
	}
	return;
}