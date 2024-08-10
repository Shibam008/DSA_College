#include<stdio.h>

int main() {
    int arr[][3] = {
        {0, 2, 3},
        {0, 0, 2},
        {0, 5, 8},
    };

    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
    
    int zeroCount = 0, nonZeroCount = 0;
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(arr[row][col] == 0) zeroCount++;
            else nonZeroCount++;
        }
    }

    if(zeroCount < nonZeroCount) {
        printf("\nNot a sparse matrix!");
    }
    else {
        printf("\nIt is a sparse matrix.");
    }
    return 0;
}