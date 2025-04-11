#include <stdio.h>

void insertionSort(int elements[], int n){
    int echange, j;
    for (int i = 0; i < n; i++) {
        echange = elements[i];
        j = i - 1;
        while (j >= 0 && elements[j] > echange) {
            elements[j + 1] = elements[j];
            j = j - 1;
        }
        elements[j + 1] = echange;
    }
}

int partition(int* elements, int left, int right) {
    int pivot = elements[right], i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (elements[j] < pivot) {
            i++;
            int swap = elements[i];
            elements[i] = elements[j];
            elements[j] = swap;
        }
    }
    
    int swap = elements[i + 1];
    elements[i + 1] = elements[right];
    elements[right] = swap;

    return i + 1;
    
}

void quickSort(int* elements, int left, int right) {
    if (right < left) {
        int pivot = partition(elements, left, right);
        quickSort(elements, left, right);
        quickSort(elements, left, pivot - 1);
        quickSort(elements, pivot + 1, right);
    }
}
