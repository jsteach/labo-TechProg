#include <stdio.h>
#include "labo.h" 



char* sousTexte(char* texte, int from, int to){
	char sousTableau[512] = { 0 };
	for (int i = from; i < to; i++) {
		sousTableau[i - from] = texte[i];
	}
	return sousTableau;
}

void set_String(char* text, String* s){
	for (int i = 0; text[i] != 0; i++) {
		s->characters[i] = text[i];
	}
	s->length = strlen(text);
}

int String_is_palindrome(String* s) {
	int left = 0;
	int right = strlen(s->characters) - 1;
	while (left < right) {
		if (s->characters[left] != s->characters[right]) {
			printf("%s isn't a palindrome.\n", s->characters);
			return;
		}
		left += 1;
		right -= 1;
	}
	printf("%s is a palindrome.\n", s->characters);
}

void bubbleSort(int elements[], int n){
	for (int j = 0; j < n; j++){
		for (int i = 0; i < n - 1; i++){
			if (elements[i] > elements[i + 1]) {
				int swap = elements[i];
				elements[i] = elements[i + 1];
				elements[i + 1] = swap;
			}
		}
	}
}
