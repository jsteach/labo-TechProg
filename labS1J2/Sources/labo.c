#include "labo.h"

void insertionSort(int elements[], int n)
{
	for (int i = 1; i < n; i++)
	{
		while (i > 0 && elements[i] < elements[i - 1]) {
			int temp = elements[i];
			elements[i] = elements[i - 1];
			elements[i - 1] = temp;

			--i;
		}

	}
}

void quickSort(int* elements, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int L = left;
	int R = right;

	int pivot = elements[(L + R) / 2];

	while (L <= R) {
		while (elements[L] < pivot) {
			L++;
		}

		while (elements[R] > pivot) {
			R--;
		}

		if (L <= R)
		{
			int temp = elements[L];
			elements[L] = elements[R];
			elements[R] = temp;

			L++; R--;
		}
	}

	int index = L;

	quickSort(elements, left, index - 1);

	quickSort(elements, index, right);
}
