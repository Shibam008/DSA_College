#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        printf("memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int getLen(Node *head) {
    Node* temp = head;
    int size = 0;
    while(temp != NULL) {
        temp = temp->next;
        size++;
    }
    return size;
}

void insertAtAny(Node** head, int position) {
    int data;
    printf("\nEnter data : ");
    scanf("%d", &data);
    Node* newNode = createNode(data);

    int len = getLen(*head);

    if((position > len) && (position != len+1) || position < 1) {
        //! (position != len+1) add this condition for inserting element at end
        printf("Invalid position!\n");
        return;
    }

    if(position == 1) {            //* insert at head
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else if(position == len+1) {   //* insert at end
        Node* lastNode = *head;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
        //lastNode = newNode;
    }
    else {                         //* insert at any position
        Node* prevNode = NULL;
        Node* currNode = *head;

        while(position != 1) {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }

        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = currNode;
        currNode->prev = newNode;
    }
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
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

        if(!head) {
            head = temp = newNode;
        }else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }

        printf("\nDo you want to continue : ");
        scanf("%d", &choise);
    }

    printLL(head);

    int pos;
    printf("\nEnter position where you want to insert data : ");
    scanf("%d", &pos);

    insertAtAny(&head, pos);
    printLL(head);

    return 0;
}