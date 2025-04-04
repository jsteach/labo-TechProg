#include <stdio.h>
#include <stdlib.h>
int subSearch(int* arr,int n, int key, int start){//O(2n)

  if(start >= n) return -1;
  if(start > -1 && arr[start] == key){
      return start;
  }
  int a = subSearch(arr,n,key,start+2);//O(n)
  int b = subSearch(arr,n,key,start+1);//O(n)
  if(a != -1) return a;
  if(b != -1) return b;
  return -1;
}

int search(int* arr,int n, int key){//O(2n)
  return subSearch(arr,n,key,-2);
}

//Main fourni à titre d'exemple
int main()
{
	int arr[] = {4,7,6,5,9,1,2};
    int index = search(arr,7,2);//O(2n)

    printf("Index : %i",index);

	return 0;
}//O(n)
