#include<stdio.h>
int main() {

    int arr[][4] = {
        {10,20,30,40},
        {50,60,70,80},
        {15,25,35,45},
        {35,95,55,65}
    };

    int row = 4, col = 4;

    printf("\nActual matrix : \n\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    // Doing transpose 
    for(int i = 0; i < row; i++) {
        for(int j = i; j < col; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    printf("\nTranspose matrix : \n\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}