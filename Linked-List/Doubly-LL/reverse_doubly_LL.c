#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
   int data;
   struct Node *prev, *next;
}Node;

Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   if(!newNode) {
      printf("memory allocation failed !");
      exit(1);
   }
   else {
      newNode->data = data;
      newNode->prev = NULL;
      newNode->next = NULL;
   }
   return newNode;
}

void printLL(Node* head) {
   Node* temp = head;
   printf("\nLinked List : ");
   while(temp != NULL) {
      printf("%d->", temp->data);
      temp = temp->next;
   }
}

Node* reverseDLList(Node** head, Node** tail) {
   Node *currNode, *nextNode;
   currNode = *head;

   // swapping two addressed of a node
   while(currNode != NULL) {
      nextNode = currNode->next;
      currNode->next = currNode->prev;
      currNode->prev = nextNode;
      currNode = nextNode;
   }

   // updating head and tail
   currNode = *head;
   *head = *tail;
   *tail = currNode;
}

int main () {
   Node *head = NULL, *tail = NULL;
   int choise = 1;

   while(choise) {
      int data;
      printf("Enter Data : ");
      scanf("%d", &data);
      Node* newNode = createNode(data);

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
   printf("\n[ Head data : %d || Tail data : %d ]", head->data, tail->data);


   printf("\n\nReversed Linked List - ");
   reverseDLList(&head, &tail);
   printLL(head);
   printf("\n[ Head data : %d || Tail data : %d ]", head->data, tail->data);
}