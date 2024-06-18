#include<stdio.h>
#include<stdlib.h>

void solve(int *arr, int s, int e) {

   int mid = s + (e-s)/2;

   int left_len = (mid - s + 1);
   int right_len = (e - mid);

   //* creat two new array
   int* left_arr = (int*)malloc(left_len * sizeof(int));
   int* right_arr = (int*)malloc(right_len * sizeof(int));

   //* copying element from original to left_arr
   int idx = s;
      for(int i=0; i<left_len; i++) {
         left_arr[i] = arr[idx];
         idx++;
      }
   //* copying element from original to right_arr
   idx = mid+1;
      for(int i=0; i<right_len; i++) {
         right_arr[i] = arr[idx];
         idx++;
      }

   //! Now we are merging two sorted arrays
   int l_idx = 0, r_idx = 0;
   idx = s;

   while( (l_idx < left_len) && (r_idx < right_len) ) 
   {
      if(left_arr[l_idx] < right_arr[r_idx]) {
         arr[idx++] = left_arr[l_idx++];
      }
      else{
         arr[idx++] = right_arr[r_idx++];
      }
   }

   while(l_idx < left_len) {
      arr[idx++] = left_arr[l_idx++];
   }
   while(r_idx < right_len) {
      arr[idx++] = right_arr[r_idx++];
   }

   free(left_arr);
   free(right_arr);
}

void mergeSort(int *arr, int s, int e) {
      
   if(s >= e) {
      return;
   }
   int mid = s + (e-s)/2;

   //* sort left part 
   mergeSort(arr, s, mid);

   //* sort right part
   mergeSort(arr, mid+1, e);

   solve(arr, s, e);
}

int main() {
   int arr[] = {1, 21, 14, 7, 3, 9};
   int size = sizeof(arr)/sizeof(int);
   int s = 0;
   int e = size-1;

   mergeSort(arr, s, e);

   for(int i=0; i<size; i++) {
      printf("%d ", arr[i]);
   } 
   return 0;
}