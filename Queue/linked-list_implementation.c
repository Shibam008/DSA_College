#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Queue* crearteQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}



void push(Queue* q, int val) 
{
    Node* newNode = createNode(val);
    if(q->rear == NULL) {
        // Empty queue!
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("\npushed %d, into the queue.", val);
}

void pop(Queue* q) 
{
    if(q->rear == NULL) {
        printf("\nEmpty Queue!\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;

    // If the queue is now empty
    // means if we pop the single element.
    // set rear to NULL
    if(q->front == NULL) q->rear = NULL;

    printf("\nPopped %d from the queue.", temp->data);
    free(temp);
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

int getSize(Queue* q) 
{
    Node* temp = q->front;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int getFront(Queue* q) 
{
    if(q->front != NULL) {
        return q->front->data;
    } 
    else {
        printf("\nNo element present!");
        return -1;
    }
}

int getRear(Queue* q) 
{
    if(q->rear != NULL) {
        return q->rear->data;
    } 
    else {
        printf("\nNo element present!");
        return -1;
    }
}

void display(Queue* q) {
    Node* temp = q->front;
    printf("\nQueue : ");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = crearteQueue();

    push(q, 10);
    display(q);

    push(q, 20);
    display(q);

    push(q, 30);
    display(q);

    push(q, 40);
    display(q);

    pop(q);
    display(q);


    if(isEmpty(q)) {
        printf("\nEmpty ? -> Yes.\n");
    } else {
        printf("\nEmpty ? -> No.\n");
    }
    

    int size = getSize(q);
    printf("\nSize of the queue : %d\n\n", size);
    // Free allocated memory for each node 

    printf("-----Free allocated memory!-----");
    while(!isEmpty(q)) {
        pop(q);
    }
    free(q);
    return 0;
}