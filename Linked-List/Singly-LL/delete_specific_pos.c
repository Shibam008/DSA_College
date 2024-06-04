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

void deleteFromAny(Node **head, int position) {
    
    int len = getLen(*head);

    if(*head == NULL) {
        printf("empty list!");
        return;
    }

    if(position > len || position < 1) {
        printf("Invalid position!");
        return;
    }
    
    if(position == 1) {           // First Node
        Node* newHead = *head;
        *head = newHead->next;
        free(newHead);
    }
    else if(position == len) {    // last node
        Node* prev = NULL;
        Node* curr = *head;
        while(len != 1) {  
            len--;
            prev = curr;
            curr = curr->next;
        }
        Node* lastNode = prev->next;
        prev->next = NULL;
        free(lastNode);
    }
    else {                       // general case
        Node* prev = NULL;
        Node* curr = *head;
        while(position != 1) {
            position--;
            prev = curr;
            curr = curr->next;
        }
        Node* nextNode = curr->next;
        curr->next = NULL;
        prev->next = nextNode;
        free(curr);
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

    int pos;
    printf("\nEnter position from where you want to delete the node : ");
    scanf("%d", &pos);

    deleteFromAny(&head, pos);
    printf("\nDeleting node...");
    printLL(head);

    return 0;
}