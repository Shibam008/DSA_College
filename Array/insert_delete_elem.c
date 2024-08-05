#include<stdio.h>
void insertElement(int *arr, int idx, int elem, int *size) 
{
    if(idx <= *size && idx >= 0) 
    {
        for(int i = *size; i > idx ; i--) {
            arr[i] = arr[i-1];
        }
        arr[idx] = elem;
        (*size)++;
    }
    else 
    {
        printf("invalid index!");
    }
    
}

void deleteElement(int *arr, int idx, int *size) 
{
    for(int i = idx; i < *size; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

void display(int *arr, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {10, 12, 15, 16, 17, 18};
    int size = 6;

    int choise;
    printf("Press (1) to add and (0) to delete element from array : ");
    scanf("%d", &choise);

    int elem, idx;

    switch(choise) {
        case 1 :
            printf("enter index : ");
            scanf("%d", &idx);
            printf("Enter element : ");
            scanf("%d", &elem);
            insertElement(arr, idx, elem, &size);
            printf("\nAfter adding element, new array : ");
            display(arr, size);
            printf("\nsize : %d", size);
            break;
        case 0 :
            printf("enter index to delete existing element : ");
            scanf("%d", &idx);
            deleteElement(arr, idx, &size);
            printf("\nAfter deleting, new array : ");
            display(arr, size);
            printf("\nsize : %d", size);
            break;
        default :
            printf("Wrong input!");
    }


}