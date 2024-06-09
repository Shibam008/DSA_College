#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* creatNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("memory allocation failed!");
    }
    else {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
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

void printLL(Node* head) {
    Node* temp = head;
    printf("\nLinked List : ");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

void deleteNode(Node **head, Node **tail, int position) {

    if(*head == NULL) {
        printf("\nEmpty List!");
        return;
    }

    if(*head == *tail) {      
        //* Single element
        Node* temp = *head;
        free(temp);
        printf("\ndeleted single element\n");
        *head = *tail = NULL;
    }

    int len = getLen(*head);

    if(position == 1) {
        // delete from head
        Node* temp = *head;
        *head = (*head)->next; // update new head
        temp->next = NULL;
        (*head)->prev = NULL;
        free(temp);
    }
    else if(position == len) {
        // delete from tail
        Node* prevNode = (*tail)->prev;
        prevNode->next = NULL;
        (*tail)->prev = NULL;
        free(*tail);
        *tail = prevNode;
    }
    else {
        Node* prevNode = NULL;
        Node* currNode = *head;
        while(position != 1) 
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        free(currNode);
    }   
}

int main() {
    Node *head = NULL, *tail = NULL;
    int choise = 1;

    while(choise) {
        int data;
        printf("Enter data : ");
        scanf("%d", &data);
        Node* newNode = creatNode(data);

        if(head == NULL) {
            head = tail = newNode;
        }else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        printf("Do you want to continue ? (0/1) : ");
        scanf("%d", &choise);
    }
    printLL(head);

    int pos;
    printf("\nEnter position for deleting element : ");
    scanf("%d", &pos);
    deleteNode(&head, &tail, pos);
    printLL(head);
    //printf("\nHead -> %d , tail -> %d", head->data, tail->data);
}
