#include "labo.h"
#include "stdio.h"

#define _CRT_SECURE_NO_WARNINGS
char* sousTexte(char* texte, int from, int to) {
	char soustableau[512] = { 0 };

	for (int i = from; i < to; i++) {
		soustableau[i - from] = texte[i];
	}
	return soustableau;
}

void set_String(char* text, String* s) {
	for (int i = 0; text[i] != 0; i++) {
		s->characters[i] = text[i];
	}
	s->length = strlen(text);
}

int String_is_palindrome(String* s) {
	int count = 0;
	for (int i = 0; i < s->length; i++) {
		if (s->characters[i] != s->characters[s->length]) {
			count++;
		}
	}
	if (count == s->length) {
		return 1;
	}
	else {
		return 0;
	}

}


void bubbleSort(int elements[], int n) {
	int time = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int P = 0; P < n - 1 - i; P++) {
			if (elements[P] > elements[P + 1]) {
				time = elements[P];
				elements[P] = elements[P + 1];
				elements[P + 1] = time;
			}
		}
	}
}