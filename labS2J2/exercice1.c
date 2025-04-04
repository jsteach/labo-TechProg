#include<stdio.h>
#define RANGE 10

int max (int a[], int n){//O(n)
   int max = a[0];//12
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}

void sort (int a[], int n){
   int bucket[RANGE][RANGE], bucket_count[RANGE];//10
   int i, j, k, r, NUM_DIGIT = 0;//O(1)
   int dividor = 1;//O(1)
   int msd = max (a, n);//O(n)
   while (msd > 0){//O(log n)
      NUM_DIGIT++;
      msd /= 10;
   }
   for (int d_count = 0; d_count < NUM_DIGIT; d_count++){//O(m)
      for (i = 0; i < RANGE; i++){
         bucket_count[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / dividor) % RANGE;
         bucket[r][bucket_count[r]] = a[i];
         bucket_count[r] += 1;
      }
      i = 0;
      for (k = 0; k < RANGE; k++){
         for (j = 0; j < bucket_count[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      dividor *= RANGE;//*10
   }
}
int main (){
   int i, n;
   int arr[] = { 12, 11, 13, 5, 6, 7 };

   sort (arr, n);
   return 0;
}
//O(n log m)