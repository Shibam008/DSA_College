#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

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

void insertAtHead(Node** head) {
    int data;
    printf("\nEnter data for inserting at head : ");
    scanf("%d", &data);
    Node* newNode = createNode(data);

    //! updating new head
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node** head) {
    int data;
    printf("\nEnter data for inserting at tail : ");
    scanf("%d", &data);
    Node* newNode = createNode(data);

    //! Updating new tail
    Node* lastNode = *head;
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
    lastNode = newNode;
}

int main() {
    Node *head, *temp;
    head = NULL;
    int choise = 1;

    while(choise) {
        
        int data;
        printf("Enter data : ");
        scanf("%d", &data);
        Node* newNode = createNode(data);
        
        if(head == NULL) {
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
    //printReverse(head);

    insertAtHead(&head);
    //insertAtTail(&head);
    
    printLL(head);
    //printReverse(head);
    
    return 0;
}