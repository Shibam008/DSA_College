#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        printf("memory allocation failed!");
        exit(1);
    }
    else {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

void printLL(Node* head) {
    Node* temp = head;
    printf("\nLinked List : ");
    while(temp != NULL) { 
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

Node* reverse_List(Node** prev, Node** curr) {
    // base case
    if(*curr == NULL) {
        return *prev;
    }

    // handle one case
    Node* nextNode = (*curr)->next;
    (*curr)->next = *prev;
    *prev = *curr;
    *curr = nextNode;
    
    // recursive solution
    return reverse_List(prev, curr);
 }

int main() {
    Node *head, *newNode, *temp;
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
            temp = newNode;
        }

        printf("Do you want to continue ? (0/1) : ");
        scanf("%d", &choise);
    }

    printLL(head);

    // for recursive approach
    Node* prev = NULL;
    Node* curr = head;
    printf("\nReversed Linked List : ");

    // update the head to the new reversed head
    head = reverse_List(&prev, &curr);
    printLL(head);
}