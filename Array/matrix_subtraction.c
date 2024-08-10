#include<stdio.h>
int main() {
    int row1, row2, col1, col2;
    printf("\tEnter details of first matrix : \n");
    printf("Enter number of rows and columns : ");
    scanf("%d %d", &row1, &col1);
    printf("Enter elements for first matrix -> \n");
    int mat1[row1][col1];
    for(int i=0; i<row1; i++) {
        for(int j=0; j<col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\tEnter details of second matrix : \n");
    printf("Enter number of rows and columns : ");
    scanf("%d %d", &row2, &col2);
    printf("Enter elements for second matrix -> \n");
    int mat2[row2][col2];
    for(int i=0; i<row2; i++) {
        for(int j=0; j<col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    if(row1 != row2 && col1 != col2) 
    {
        printf("Matrix subtraction can't be performed!\nWe need square matrix");
    }
    else 
    {
        int res[row1][col1];
        printf("\nSubtraction  of two matrices : \n");
        for(int i=0; i<row1; i++) {
            for(int j=0; j<col1; j++) {
                res[i][j] = mat1[i][j] - mat2[i][j];
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}