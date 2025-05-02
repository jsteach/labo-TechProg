#include "labo.h"

void insertionSort(int elements[], int n) {
	n = 6;
	elements[n] = {147,89,20,40,27,12};
	for (int i = 1; i < n; i++) {
		int y = i;
		for (y = 1; i < n; y++) {
			while ((y > 0) && elements[y] < elements[y - 1]) {
				int temp = elements[y];
				elements[y] = elements[y - 1];
				elements[y - 1] = temp;
				--y;
			}
		}
	}
}
void quickSort(int* elements, int left, int right) {
	elements = { 233,17,45,682,59,431,1,4 };
	int i;
	int y;
	int pivot = 8;
	left = i;
	right = y;
	while (left <= right) {
		while (elements[left] < pivot) { left++; }
		while(elements[right] > pivot) {right--; }
		if (left <= right) {
			int temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++; right--;
		}
	}

}
