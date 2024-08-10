#include<stdio.h>

int main() {
    int arr[100] = {10, 12, 15, 18};
    int size = 4;
    int data;
    printf("Enter element for inserting at end : ");
    scanf("%d", &data);

    arr[size] = data;
    size++;

    printf("\nNew array : ");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nsize of array : %d", size);
}