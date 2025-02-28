#include "labo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS


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
   for (int i = 0; i < s->length; i++) {
        if (s->characters[i] == s->characters[s->length - i - 1]) {
        }
        else {
            return 0;
        }
    }
    return 1;
}

void bubbleSort(int elements[], int n)
{
    int TempSwap = 0;
    while (n > 1) {
        for (int i = 0; i < n; i++) {
            if (i + 1 <= n - 1) {
                if (elements[i] > elements[i + 1]) {
                    TempSwap = elements[i];
                    elements[i] = elements[i + 1];
                    elements[i + 1] = TempSwap;
                }
            }
        }
        n--;
    }
}
