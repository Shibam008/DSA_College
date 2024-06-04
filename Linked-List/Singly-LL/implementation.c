#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printLL(Node *head) {
    Node* temp = head;
    printf("\nLinked List : ");
    while(temp != NULL) {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}


int main() {
    Node *head, *newNode, *temp;
    head = 0;
    int choise = 1;

    while(choise) {
        newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL) {
            printf("Memory Allocation Failed !");
            return 1;
        }
        printf("Enter data : ");
        scanf("%d", &newNode->data);
        newNode->next = 0;

        if(head == 0) {
            head = temp = newNode;
        }else {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to continue ? (0/1) : ");
        scanf("%d", &choise);
    }

    printLL(head);
    
    return 0;
}