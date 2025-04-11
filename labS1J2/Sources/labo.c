#define _CRT_SECURE_SECURE_NO_WARNINGS
#include "labo.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int elements[], int n) {
	for (int i = 1; i < n; i++) {
		int placehold1 = elements[i];
		int placehold2 = i - 1;

		while (placehold2 >= 0 && elements[placehold2] > placehold1) {

			elements[placehold2 + 1] = elements[placehold2];
			placehold2 = placehold2 - 1;
		}
		elements[placehold2 + 1] = placehold1;
	}
	return elements;
}

void quickSort(int* elements, int left, int right) {
	if (left >= right) {
		return 0;
	}
	int placehold3 = left;
	int placehold4 = right;
	int MidGround = elements[(left + right) / 2];
	while (left <= right) {
		while (elements[left] < MidGround) {
			left++;
		}
		while (elements[right] > MidGround) {
			right--;
		}
		if (left <= right) {
			int temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++;
			right--;
		}
	}
	int index = left;
	quickSort(elements, placehold3, index - 1);
	quickSort(elements, index, placehold4);
}
