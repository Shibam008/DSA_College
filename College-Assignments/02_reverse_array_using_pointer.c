#include<stdio.h>

void reverseArray(int arr[], int n) {
   int *start = arr;
   int *end = arr + n - 1;
   int temp;

   while(start <= end) {
      temp = *start;
      *start = *end;
      *end = temp;
      start++, end--;
   }
}
int main() {
   int arr[] = {1, 2, 3, 4, 5, 6};
   int size = sizeof(arr)/sizeof(int);

   printf("Actual array : ");
   for(int i=0; i<size; i++) {
      printf("%d ", arr[i]);
   }
   
   reverseArray(arr, size);

   printf("\nReversed array : ");
   for(int i=0; i<size; i++) {
      printf("%d ", arr[i]);
   }
}