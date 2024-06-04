#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

void insertAtTail(Node** head) {
    // taking data for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory Allocation Failed !");
        return;
    }
    printf("\nEnter data for inserting at tail : ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    // going to the last node 
    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // updating new tail;
    temp->next = newNode;  

}

void printLL(Node* head) {
    Node *temp = head;
    printf("\nLinked List : ");
    while(temp != NULL) {
        printf("%d->", temp->data);
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
        scanf("%d",&choise);
    }

    printLL(head);
    insertAtTail(&head);
    printLL(head);
}