#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void insertAtBegining(Node** head) {
    // taking new node data
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory Allocation Failed !");
        return;
    }
    printf("\nEnter data you want to insert at begining : ");
    scanf("%d", &newNode->data);

    // updating head
    newNode->next = *head;
    *head = newNode;
} 

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
    head = NULL;
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

        if(head == NULL) {
            head = temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to continue ? (0/1) : ");
        scanf("%d", &choise);
    }
    printLL(head);

    insertAtBegining(&head);
    printLL(head);
    
    return 0;
}



// some key points we should keep in mind
/*
    1. Ensure that malloc succeeds by checking if the return value is NULL

    2. The function insertAtBegining requires the head of the linked list to be passed as an argument, and it should accept a pointer to the head pointer (Node**) to modify the head.

    3. Pass the head of the linked list when calling insertAtBegining.
*/