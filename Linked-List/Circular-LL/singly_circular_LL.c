#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
   int data;
   struct Node *next;
}Node;

Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   if( !newNode ) {
      printf("memory allocation failed!");
      exit(1);
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

void display(Node* head) {
   if (head == NULL) {
      printf("Empty List !");
   }
   else {
      Node* temp = head;
      printf("\ncircular linked list : ");
      while(temp->next != head) {
         printf("%d->", temp->data);
         temp = temp->next;
      }
      printf("%d->", temp->data); // printing last node value 
   }
}

int main() {
   Node *head = NULL, *tail = NULL;
   int choise = 1;

   while(choise) {
      int data;
      printf("Enter data : ");
      scanf("%d", &data);
      Node* newNode = createNode(data);

      if(head == NULL) {
         head = tail = newNode;
      }else{
         tail->next = newNode;
         tail = newNode;
      }
      tail->next = head;  //! extra line to covert singly-LL to circular-singly-LL 

      printf("Do you want to continue ? (0/1) : ");
      scanf("%d", &choise);
   }

   display(head);
   printf("\nTail value : %d || Head value : %d", tail->next->data, head->data);
}