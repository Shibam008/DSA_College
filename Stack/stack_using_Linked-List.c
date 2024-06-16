#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
      int data;
      struct Node* next;
}  Node;

typedef struct {
      Node* top;
      int size;
}  stack;

Node* createNode (int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   if(!newNode) {
      printf("memory allocation failed!");
      exit(1);
   }
   else {
      newNode->data = data;
      newNode->next = NULL;
      return newNode; 
   }
}

stack* createStack() {
   stack* st = (stack*)malloc(sizeof(stack));
   if(!st) {
      printf("Memory allocation failed!");
      exit(1);
   }
   else {
      st->top = NULL;
      st->size = 0;
      return st;
   }
}

void push(stack* st, int data) {
   Node* newNode = createNode(data);
   newNode->next = st->top;
   st->top = newNode;
   st->size++;
}

void pop(stack* st) {
   if(st->top == NULL) {
      printf("Stack Underflow!");
      return;
   }
   Node* temp = st->top;
   st->top = st->top->next;
   free(temp);
   st->size--;
}

//* stack will full when heap memory is exhausted
bool isEmpty(stack* st) {
   return st->top == NULL;
}

int getTop(stack* st) {
   if(st->top == NULL) {
      printf("Stack is empty!");
      return -1;
   }
   return st->top->data;
}

int getSize(stack* st) {
   return st->size;
}

void print(stack* st) {
   printf("Top index : %d\n", st->size-1);
   printf("Top element : %d\n", getTop(st));
   printf("Stack : ");

   Node* temp = st->top;
   while(temp != NULL) {
      printf("%d", temp->data);
      temp = temp->next;
   }
   printf("\n\n");
}


int main () {
   // creation
   stack* st = createStack();

   // push 
   push(st, 10);
   print(st);

   pop(st);
   print(st);

   free(st);
}