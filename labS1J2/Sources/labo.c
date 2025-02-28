#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionSort(int elements[], int n){
	int tempo = 0;
	for(int i = 1;i < n;i++){
		int y = i;
		while (y > 0 && elements[y] < elements[y - 1]) {
			tempo = elements[y];
			elements[y] = elements[y - 1];
			elements[y - 1] = tempo;
			--y;
		}
	}
}

void quickSort(int* elements, int left, int right) {
	int L = 0;
	int R = 0;
	int pivot = 0;
	int tempo = 0;
	int index = 0;
	if(left >= right) {
		return;
	}
	L = left; 
	R = right;
	pivot = elements[(left + right) / 2];
	while(left <= right) {
		while(elements[left] < pivot) {
			left++; 
		}
		while(elements[right] > pivot) {
			right--; 
		}
		if(left <= right) {
			tempo = elements[left];
			elements[left] = elements[right];
			elements[right] = tempo;
			left++; right--;
		}
	}
	
	index = left;
	quickSort(elements, L, index - 1);
	quickSort(elements, index, R);
}