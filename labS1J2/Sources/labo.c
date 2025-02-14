#include "labo.h"
#include <stdio.h>

void swap(int i, int j, int* tri) {
    int temp = tri[i];
    tri[i] = tri[j];
    tri[j] = temp;
}

void insertionSort(int elements[], int n)
{
   int i;
   int j;
   int tri[] = { 147,89,20,40,27,12 };
    for (int i = 0; i < 6; i++) {
        for (int j = i; j > 0; j--) {
            printf("%d\n", tri[i]);
            swap(i, j - 1, tri);
              
            
    }
    }
   
}


void quickSort(int* elements, int left, int right)
{
}
