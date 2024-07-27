
#include<stdio.h>

int main() {
    int arr[][3] = {
        {0, 2, 3},
        {0, 0, 2},
        {0, 5, 0},
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
        printf("Not a sparse matrix!");
    }
    else {
        int sparse[nonZeroCount][3], k = 0;
        for(int row = 0; row < 3; row++) {
            for(int col = 0; col < 3; col++) {
                if(arr[row][col] != 0) 
                {
                    sparse[k][0] = row;
                    sparse[k][1] = col;
                    sparse[k][2] = arr[row][col];
                    k++;
                }
            }
        }
        printf("\nSparse matrix representation : \n\n");
        printf(" row | col | value \n");
        for(int row = 0; row < nonZeroCount; row++) {
            for(int col = 0; col < 3; col++) {
                printf("  %d   ", sparse[row][col]);
            }
            printf("\n");
        }
        
    }
    return 0;
}