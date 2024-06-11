#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if( !newNode ) {
        printf("memory allocation failed !");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLen(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAfterGivenNode(Node** head, int position) {

    int len = getLen(*head);

    if(((position > len) && position != len+1) || position < 1) { 
        //! (position != len+1) add this condition for inserting element at end
        printf("Invalid position");
        return;
    }
    
    // making new node
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    Node* newNode = createNode(data);

    if(position == 1) {             // insert at head
            newNode->next = *head;
            *head = newNode;
    }
    else if(position == len+1) {      // insert at tail
            Node* temp = *head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
    }
    else {                           // general case
            Node* prev = NULL;
            Node* curr = *head;
            while(position != 1) {
                position--;
                prev = curr;
                curr = curr->next;
            }
            prev->next = newNode;
            newNode->next = curr;
    }
}

void printLL(Node* head) {
    Node* temp;
    temp = head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}


int main() {
    Node *head = NULL, *temp;
    int choise = 1;

    while(choise) {
        int data;
        printf("Enter Data : ");
        scanf("%d", &data);
        Node* newNode = createNode(data);
        
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

    int pos;
    printf("\n\nEnter position for inserting new node/data: ");
    scanf("%d", &pos);

    insertAfterGivenNode(&head, pos);
    printLL(head);
}