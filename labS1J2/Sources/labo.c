#include "labo.h"

void insertionSort(int elements[], int n)
{
	for (int i = 1; i < n; i++) {
		while (i > 0 && elements[i] < elements[i - 1]) {
			int temp = elements[i];
			elements[i] = elements[i - 1];
			elements[i - 1] = temp;
			i--;
		}
    }
}

void quickSort(int* elements, int left, int right)
{
	if (left >= right) { return; }
	int L = left;
	int R = right;
	int pivot = elements[(left + right) / 2];
	while (left <= right) {
		while (elements[left] < pivot) { left++; }
		while (elements[right] > pivot) { right--; }
		if (left <= right) {
			int temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++;
			right--;
		}
	}
	int index = left;
	quickSort(elements, L, index - 1);
	quickSort(elements, index, R);
}
