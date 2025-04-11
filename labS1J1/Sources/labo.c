#define _CRT_SECURE_NO_WARNINGS
#include "labo.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

char* sousTexte(char* texte, int from, int to)
{
	static char soustab[256];
	for (int i = 0; i < (to - from); i++) {
		soustab[i] = texte[from + i];
	}
	return soustab;
}

void set_String(char* text, String* s)
{
	strcpy(s->characters, text);
	s->length = strlen(text);
}

int String_is_palindrome(String* s)
{
	for (int j = 0; j < s->length; j++) {
		if (s->characters[j] == s->characters[s->length - j - 1]) {
		}
		else {
			return 0;
		}
	}
	return 1;
}

void bubbleSort(int elements[], int n)
{
	int exchange = false;
	for (int u = 0; u < n-1; ++u) {
		if (elements[u] > elements[u + 1]) {
			exchange = true;
			int temp = elements[u];
			elements[u] = elements[u + 1];
			elements[u + 1] = temp;
			//temp = 0;
		}
		if (exchange) {
			exchange = false;
			u = -1;
		}
		//u--;
	}

	//return 0;
	/*int goesbefore;
	int goesafter;
	for (int u = 0; u < n; u++) {
		if (elements[u] < elements[n - u]) {
			goesbefore = elements[u];
			goesafter = elements[u + 1];
			return elements[u];
		}

	}*/
}
