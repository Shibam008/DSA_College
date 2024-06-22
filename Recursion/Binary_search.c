
//! Binary Search always applicabe on sorted array
//! Time complexity : O(Log n)

#include<stdio.h>

int binSearch(int *arr, int s, int e, int target)
{
   // base case
   if(s > e) {
      return -1;
   }

   int mid = s + (e-s)/2;
   if(arr[mid] == target) {
      return mid;
   }

   if(arr[mid] < target) {
      // searching in right part
      return binSearch(arr, mid + 1, e, target);
   }
   else{
      // searching in left part
      return binSearch(arr, s, mid - 1, target);
   }
}

int sortArray(int *arr, int n)
{
   for(int i=0; i<n-1; i++)
   {
      for(int j=0; j<n-i-1; j++)
      {
         if(arr[j] > arr[j+1])
         {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

int main() {
   int arr[] = {10, 30, 50, 40, 20};
   int size = sizeof(arr)/sizeof(int);

   int start = 0;
   int end = size-1;

   int target;
   printf("Enter your target : ");
   scanf("%d",&target);

   sortArray(arr, size);
   printf("Sorted Array : ");
   for(int i=0; i<size; i++) {
      printf("%d ",arr[i]);
   }

   int ans = binSearch(arr, start, end, target);

   if(ans != -1) {
      printf("\nTarget present at index : %d", ans);
   }else {
      printf("\nTarget not found!");
   }
   return 0;
}