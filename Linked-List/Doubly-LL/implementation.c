#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
} Node;

void printLL(Node *head) {
    Node* temp = head;
    printf("\nLinked List : ");
    while(temp != NULL) {
        printf("%d->",temp->data);
        temp = temp->next;
    }
}

void printReverse(Node *head) {
    Node* temp = head;

    //! go to the last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    printf("\nReversed Linked List : ");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->prev;
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
        newNode->next = NULL;
        newNode->prev = NULL;       //* extra line compared to singly ll
        

        if(head == 0) {
            head = temp = newNode;
        }else {
            temp->next = newNode;
            newNode->prev = temp;   //* extra line compared to singly ll
            temp = newNode;
        }

        printf("Do you want to continue ? (0/1) : ");
        scanf("%d", &choise);
    }

    printLL(head);
    printReverse(head);
    
    return 0;
}