#include <stdbool.h>

/*
* Déclarer une structure de donnée qui va s'appeler String. La structure va avoir une propriété characters et une propriété length.
*/

typedef struct string
{
	char* characters;
	int length;
}String;


/*
* Faire une fonction qui retourne a sous-tableau de character de celui passer. 
*/
char* sousTexte(char* texte, int from, int to) {
	static char sub[256] = { 0 };
	int j = 0;

	for (int i = from; i < to; i++) {
		sub[j] = texte[i];
		j++;
	}
	sub[j] = '\0';
	return sub;
}


/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {
	s->characters = text;
	s->length = strlen(text);
}

/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {

	if (s->length == 0 || s->length == 1) {
		return 1; 
	}

	int left = 0;                      
	int right = s->length - 1;

	while (left < right) {
		if (s->characters[left] != s->characters[right]) {
			return 0; 
		}
		left++;
		right--;
	}

	return 1; 
}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n)
{
	bool echanger = false;

	for (int i = 0; i <= n - 1; i++) {

		if (elements[i] > elements[i + 1]) {
			echanger = true;
			int temp = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = temp;
		}

		if (i > n - 1 && echanger) {
			echanger = false;
			i = -1;
		}

	}
}