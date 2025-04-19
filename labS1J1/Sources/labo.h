#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* Déclarer une structure de donnée qui va s'appeler String. La structure va avoir une propriété characters et une propriété length.
*/
typedef struct {
	char* characters;
	int length;
} String;

/*
* Faire une fonction qui retourne a sous-tableau de character de celui passer. 
*/
char* sousTexte(const char* texte, int from, int to) {
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

}


/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {
	s->length = strlen(text);
	s->characters = (char*)malloc((s->length + 1) * sizeof(char));
	strcpy(s->characters, text);

}

/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {
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

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {
	
}