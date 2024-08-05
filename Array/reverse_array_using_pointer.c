#include<stdio.h>

void reverse(int arr[], int n) 
{
    int *start = arr;
    int *end = arr + n -1;
    int temp;
    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++; end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(int);
    
    printf("Reversed array : ");
    reverse(arr, size);
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}