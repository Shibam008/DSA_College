#include<stdio.h>

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

void bubbleSort(int arr[], int n) {
   for(int i=0; i<n-1; i++) {
      for(int j=0; j<n-i-1; j++) {
         if(arr[j] > arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
         }
      }
   }
}

int main () {
   int arr[] = {12, 15, 10, 52, 18};
   int size = sizeof(arr)/sizeof(int);
   
   bubbleSort(arr, size);

   for(int i=0; i<size; i++) {
      printf("%d ", arr[i]);
   }
}