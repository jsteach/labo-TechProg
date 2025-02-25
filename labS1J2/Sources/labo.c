
#include "labo.h"

void insertionSort(int elements[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = elements[i]; int P = i - 1;
		while ((temp < elements[P]) && (P >= 0)) {
			elements[P + 1] = elements[P]; P = P - 1; }
		elements[P + 1] = temp; 
	} 
}
void swap(int* a, int* b) {
	int temp = *a; a = b; *b = temp;
}

void quickSort(int* elements, int left, int right)  { 
	if (left >= right) {
		return ; 
	} 
	int piv = elements[left];
	int i = left + 1;
	int P = right; int temp; 
	while (i <= P) {
		while (i <= right && elements[i] <= piv) {
			i++; 
		} 
		while (elements[P] > piv) {
			P--; 
		}
		if (i < P) 	{
			swap(&elements[i], &elements[P]); i++; P--;
		} 
	} swap(&elements[left], &elements[P]); quickSort(elements, left, P - 1); 
}



