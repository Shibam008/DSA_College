#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
   int data;
   struct Node* next;
}Node;

Node* createNode (int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   if( !newNode ) {
      printf("memory allocation failed!");
      exit(1);
   }
   newNode->data = data;
   newNode->next  = NULL;
   return newNode;
}

int getLen(Node* head) {
   int count = 0;
   Node* temp = head;
   while(temp->next != head) {
      count++;
      temp = temp->next;
   }
   return count+1;
}

void insertAtHead(Node** head, Node** tail) {
   int data;
   printf("\nEnter data for inserting at head : ");
   scanf("%d", &data);
   Node* newNode = createNode(data);

   if(*head == NULL) {
      *head = *tail = newNode;
      (*tail)->next = newNode;
   }
   else {
      newNode->next = *head;
      (*tail)->next = newNode;
      *head = newNode;
   }
}

void insertAtTail(Node** head, Node** tail) {
   int data;
   printf("\nEnter data for inserting at tail : ");
   scanf("%d", &data);
   Node* newNode = createNode(data);

   if(*head == NULL) {
      *head = *tail = newNode;
      (*tail)->next = newNode;
   }
   else {
      (*tail)->next = newNode;
      newNode->next = *head;
      *tail = newNode;
   }
}

void insertAtAny(Node** head, Node** tail, int position) {

   int len = getLen(*head);

   if ( position < 0 || (position > len && position != len+1) ) {
      printf("Invalid position!\n");
      return;
   }

   if (position == 1) {
      insertAtHead(head, tail);
      return;
   }
   else if(position == len+1) {
      insertAtTail(head, tail);
      return;
   }
   else {
      int data;
      printf("Enter data: ");
      scanf("%d", &data);
      Node* newNode = createNode(data);

      Node* temp = *head;
      for(int i=1; i<position-1; i++) {
         temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
   }
}

void display(Node* head) {
   if(head == NULL) {
      printf("Empty list!");
      exit(1);
   }
   else {
      Node* temp = head;
      printf("\nCircular linked list : ");
      while(temp->next != head) {
         printf("%d->", temp->data);
         temp = temp->next;
      }
      printf("%d->", temp->data);
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
      }else {
         tail->next = newNode;
         tail = newNode;
      }
      tail->next = head;

      printf("Do you want to continue ? (0/1) : ");
      scanf("%d", &choise);
   }
   printf("\nTail data : %d ||| Head data : %d",tail->next->data, head->data);

   display(head);

   // insertAtHead(&head, &tail);
   // display(head);
   // printf("\nTail data : %d ||| Head data : %d",tail->next->data, head->data);
   

   // insertAtTail(&head, &tail);
   // display(head);
   // printf("\nTail data : %d ||| Head data : %d",tail->next->data, head->data);

   int pos;
   printf("\nEnter valid position for inserting data : ");
   scanf("%d", &pos);
   insertAtAny(&head, &tail, pos);
   display(head);
   printf("\nTail data : %d ||| Head data : %d",tail->next->data, head->data);

   return 0;
}