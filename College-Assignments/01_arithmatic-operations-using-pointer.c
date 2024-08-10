#include<stdio.h>

void add(float *x, float *y, float *result) {
   *result = *x + *y;
}

void subtract(float *x, float *y, float *result) {
   *result = *x - *y;
}

void multiply(float *x, float *y, float *result) {
   *result = *x * *y;
}

void divide(float *x, float *y, float *result) {
   *result = *x / *y;
}

int main() {

   float num1, num2, result;
   char oper;

   printf("Enter 1st number : ");
   scanf("%f", &num1);

   printf("Enter 2nd number : ");
   scanf("%f", &num2);
   
   printf("Enter operation (+, -, *, /) : ");
   scanf(" %c", &oper);

   switch(oper) {
      case '+' : 
         add(&num1, &num2, &result);
         printf("Addition result = %.2f", result);
         break;

      case '-' : 
         subtract(&num1, &num2, &result);
         printf("Subtraction result = %.2f", result);
         break;

      case '*' : 
         multiply(&num1, &num2, &result);
         printf("Multiplication result = %.2f", result);
         break;

      case '/' : 
         divide(&num1, &num2, &result);
         printf("Division result = %.2f", result);
         break;

      default :
         printf("Invalid operation!");
         break;
   }
   return 0;
}