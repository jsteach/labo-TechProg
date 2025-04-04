#include <stdio.h>

void sort(int* arr,int length){
    int y = 0;
    for(int i = length; i >= 0;){//O(n)
        arr[y] = arr[--i];//O(n)
        if(i < 0){
            printf(stderr,"Something went wrong...");
        }
        ++y;
    }
}

int main(int argc, char** argv){
    int arr[] = {6,9,10,102,27,14};
    int len = sizeof(arr)/sizeof(arr[0]);//
    sort(arr,len);//O(n)
    printf("Sorted array is: ");
    int i = 0;
    for(; arr[i+1]; ++i ){//O(n+k)
        printf(" %i,",arr[i]);
    }
    printf(" %i",arr[i]);
}//O(n)