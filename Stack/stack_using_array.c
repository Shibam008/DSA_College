#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
   int *arr;
   int size;
   int top;
}stack;


stack* createStack(int size) {
      stack* st = (stack*)malloc(sizeof(stack));
      st->arr = (int*)malloc(sizeof(int));
      st->size = size;
      st->top = -1;
      return st;
}

void push(stack* st, int data) {
   if(st->top == st->size - 1) {
      printf("Stack Overflow!");
   }
   else {
      st->top++;
      st->arr[st->top] = data;
   }
}

void pop(stack* st) {
   if(st->top == -1) {
      printf("Stack Underflow!");
   }
   else {
      st->top--;
   }
}

bool isEmpty(stack* st) {
   return st->top == -1;
}

int getTop(stack* st) {
   if(st->top == -1) {
      printf("empty stack");
   }
   else {
      return st->arr[st->top];
   }
}

int getSize(stack* st) {
   return (st->top + 1);
}

void print(stack* st) {
   printf("Top index : %d\n", st->top);
   printf("Top element : %d\n", getTop(st));
   printf("Stack : ");
   for(int i=0; i<getSize(st); i++) {
      printf("%d ", st->arr[i]);
   }
   printf("\n\n");
}



int main() {
   stack* st = createStack(5);
   
   push(st, 10);
   print(st);

   push(st, 15);
   print(st);

   push(st, 25);
   push(st, 23);
   push(st, 63);
   print(st);

   push(st, 36);

   
}