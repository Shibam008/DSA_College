#include<stdio.h>

void sum(int* x, int* y, int* res) {
    *res = *x + *y; 
}

void subtract(int* x, int* y, int* res) {
    *res = *x - *y; 
}

void multiply(int* x, int* y, int* res) {
    *res = *x * *y; 
}

void divide(int* x, int* y, float* res) {
    if(*y != 0) {
        *res = (float)(*x)/ *y;
    }
    else {
        printf("Error : Division by zero error!");
    } 
}

int main() {
    int num1, num2;
    int add, sub, mul;
    float quotient;

    int* ptr1 = &num1;
    int* ptr2 = &num2;

    printf("Enter first number : ");
    scanf("%d", ptr1);
    printf("Enter second number : ");
    scanf("%d", ptr2);

    sum(ptr1, ptr2, &add);
    subtract(ptr1, ptr2, &sub);
    multiply(ptr1, ptr2, &mul);
    divide(ptr1, ptr2, &quotient);

    printf("Sum : %d\n", add);
    printf("Subtraction : %d\n", sub);
    printf("Multiplication : %d\n", mul);
    printf("Quotient : %.3f\n", quotient);

    return 0;
}