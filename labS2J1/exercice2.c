#include <stdio.h>

#define RANGE 9     //O(1)

void sort(int arr[], int length)
{
    int output[256];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count) * (RANGE + 1));

    for (i = 0; arr[i]; ++i)        //O(n)
        ++count[arr[i]];

    for (i = 0; i <= RANGE; ++i){           //O(n)
        count[i] += count[i - 1];
    }

    for (i = 0; arr[i]; ++i) {                  //O(n)
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; arr[i]; ++i){                   //O(n)
        arr[i] = output[i];
    }
        
}           //O(n)

//Main fourni à titre d'exemple
int main()
{
    int arr[] = {9, 1, 4, 8, 9, 7, 5, 2,1,2};

    sort(arr,9);
    printf("Sorted array is: ");
    int i = 0;
    for(; arr[i+1]; ++i ){
        printf(" %i,",arr[i]);
    }
    printf(" %i",arr[i]);

    return 0;
}
