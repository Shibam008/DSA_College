
//! use cse :  when we are given a small size array
//! UNSTABLE sort

#include<stdio.h>

void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

void selectionSort(int arr[], int n) {
   for(int i=0; i<n-1; i++) {
      int minIdx = i;
      for(int j=i+1; j<n; j++) {
         if(arr[j] < arr[minIdx]) {
            minIdx = j;
         }
      }
      swap(&arr[minIdx], &arr[i]);
   }
}

int main() {
   int arr[] = {12, 15, 10, 52, 18};
   int size = sizeof(arr)/sizeof(int);
   
   selectionSort(arr, size);

   for(int i=0; i<size; i++) {
      printf("%d ", arr[i]);
   }
}

/*
in every phase we considering first element as min and then comparing with rest of the elements.
if there exists any other min value then we update the minIdx and swap it with the first selected element of every phase
*/