#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int *arr;
    int size;
    int front;
    int rear;
} Queue;

Queue* createQueue(int size) 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(size * sizeof(int));
    q->size = size;
    q->front = -1;
    q->rear = -1;
    return q;
}

void push(Queue* q, int val) 
{
    if(q->rear == q->size-1) {
        printf("\nQueue overflow!\n");
        return;
    }
    else if(q->front == -1 && q->rear == -1) {
        // single element
        q->front++;
        q->rear++;
        q->arr[q->rear] = val;
    }
    else {
        // general case
        q->rear++;
        q->arr[q->rear] = val;
    }
}

void pop(Queue* q) 
{
    if(q->front == -1 && q->rear == -1) {
        printf("\nQueue underflow!\n");
        return;
    }
    else if(q->front == q->rear) {
        // single element
        q->arr[q->front] = -1;
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->arr[q->front] = -1;
        q->front++;
    }
}

bool isEmpty(Queue* q) 
{
    return (q->front == -1 && q->rear == -1); 
}

int getSize(Queue* q) 
{
    if(q->front == -1 && q->rear == -1) {
        return 0;
    }else {
        return (q->rear - q->front + 1);
    }
}

int getFront(Queue* q) 
{
    if(q->front == -1) {
        printf("\nNo element present in the queue!\n");
        return -1;
    }else {
        return q->arr[q->front];
    }
}

int getRear(Queue* q) 
{
    if(q->rear == -1) {
        printf("\nmpty!\n");
        return -1;
    }else {
        return q->arr[q->rear];
    }
}

void display(Queue* q) 
{
    printf("\nFront -> %d | Rear -> %d", q->front, q->rear);
    printf("\nQueue : ");
    for(int i=0; i < q->size; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}



int main() {
    Queue *q = createQueue(5);

    push(q, 5);
    display(q);

    push(q, 8);
    display(q);

    push(q, 3);
    display(q);

    push(q, 15);
    display(q);

    push(q, 5);
    display(q);

    pop(q);
    display(q);

    free (q->arr);
    free (q);

    return 0;
}