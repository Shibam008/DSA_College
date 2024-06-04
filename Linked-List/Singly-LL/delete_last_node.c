#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

int getLen(Node *head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteLastNode(Node **head) {

    if(*head == NULL) {
        printf("empty list!");
        return;
    }

    int len = getLen(*head);
    
    if(len == 1) {            // single element
        Node* temp = *head;
        free(temp);
        (*head) = NULL;
        return;
    }
    else {
        Node* prev = NULL;
        Node* curr = *head;
        while(len != 1) {  // 'prev' will point second last node after loop termination
            len--;
            prev = curr;
            curr = curr->next;
        }
        Node* lastNode = prev->next;
        prev->next = NULL;
        free(lastNode);
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
    
    deleteLastNode(&head);
    printf("\nDeleting last node...");
    printLL(head);

    
    return 0;
}