
//! Adaptable and Stable algo

#include<stdio.h>

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

void insertionSort(int *arr, int n) {
   for(int i=0; i<n-1; i++) {
      int j = i+1;
      while(j >= 1 && arr[j] < arr[j-1]) {
         swap(&arr[j], &arr[j-1]);
         j--;
      }
   }
}

int main () {
   int arr[] = {12, 15, 10, 52, 18};
   int size = sizeof(arr)/sizeof(int);
   
   insertionSort(arr, size);

   for(int i=0; i<size; i++) {
      printf("%d ", arr[i]);
   }
}