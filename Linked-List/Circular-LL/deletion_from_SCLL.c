#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
   int data;
   struct Node *next;
}Node;

Node* createNode(int data)
{
   Node* newNode = (Node*)malloc(sizeof(Node));
   if(!newNode) {
      printf("Memory allocation failed!");
      exit(1);
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

int getLen(Node *head) {  
   Node* temp = head;
   int size = 0;
   while(temp->next != head) 
   {
      temp = temp->next;
      size++;
   }
   return size;
}

void deleteHead(Node** head, Node** tail) 
{
   if(*head == NULL) {
      printf("The list is empty. Nothing to delete.\n");
      return;
   }
   else if(*head == *tail) {
      free(*head);
      *head = *tail = NULL;
   }
   else {
      Node* temp = *head;       // storing head node
      *head = (*head)->next;   // updating new head node
      (*tail)->next = *head;  // pointing to new head
      free(temp);            // delete first node
   }
}

void deleteTail(Node** head, Node** tail) 
{
   if(*head == NULL) {
      printf("The list is empty. Nothing to delete.\n");
      return;
   }
   else if(*head == *tail) {
      *tail = NULL;
      free(*head);
   }
   else {
      Node* prev = NULL;
      Node* curr = *head;
      while(curr->next != *head) 
      {
         prev = curr;
         curr = curr->next;
      }
      prev->next = (*tail)->next;  
      *tail = prev; // updating tail
      free(curr);   // deleting last node
   }
}

void deleteFromAnyPos(Node** head, int pos) 
{
   if (*head == NULL) {
      printf("The list is empty. Nothing to delete.\n");
      return;
   }

   int len = getLen(*head);

   if (pos < 1 || pos > len) {
      printf("Invalid position!\n");
      return;
   }

   Node* prev = NULL;
   Node* curr = *head;
   while(pos != 1) 
   {
      pos--;
      prev = curr;
      curr = curr->next;
   }
   prev->next = curr->next;
   free(curr);
}

void display(Node* head) 
{
   if(head == NULL) {
      printf("\nEmpty list");
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

int main () {
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

   display(head);

   // deleteTail(&head, &tail);
   // display(head);

   int pos;
   printf("\nEnter position from where you want to delete : ");
   scanf("%d", &pos);
   deleteFromAnyPos(&head, pos);
   display(head);

   //printf("\nTail data : %d ||| Head data : %d",tail->next->data, head->data);
}