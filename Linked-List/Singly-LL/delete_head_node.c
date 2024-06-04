/*
    Operator Precedence:
        '->' (member access via pointer) has higher precedence than '*' (dereference).
        This means that *head->next is interpreted as *(head->next), which is not what you intend when working with a pointer to a pointer to a Node.
        
    Correct Syntax:
        (*head)->next ensures that *head is evaluated first, and then ->next is accessed.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void deleteHeadNode(Node **head) {
    if(*head == NULL) {
        printf("empty list!");
        return;
    }else{
        Node* newHead = *head;
        *head = newHead->next; // updating head
        free(newHead);
    }
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
    
    deleteHeadNode(&head);
    printf("\nDeleting head node...");
    printLL(head);
    return 0;
}