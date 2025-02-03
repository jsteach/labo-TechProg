#include "labo.h"

char* sousTexte(char* texte, int from, int to)
{
    static char sous_tab[512] = { 0 };
    for (int i = from; i != to; i++) {
        sous_tab[i-from] = texte[i];
    }
    
    return sous_tab;
}

void set_String(char* text, String* s)
{
    int longueur = 0;
    for (int i = 0; text[i] != 0 ;i++) {
       s->characters[i] = text[i];
       longueur++;
    }
    s->length = longueur;
}

int String_is_palindrome(String* s)
{
    int check = 0;
    int longueur = s->length;
    for (int i = 0;i <= longueur;i++) {
        if (s->characters[i] == s->characters[longueur]) {
            check = 1;
            longueur--;
            if (i = longueur) {
                break;
            }
        }
        else {
            check = 0;
        }
    }
    return check;
}

void bubbleSort(int elements[], int n)
{
    int tempo = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (elements[j] > elements[j + 1]) {
                tempo = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = tempo;
            }
            else {
                continue;
            }
                
        }
    }
}
