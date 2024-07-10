#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
   int data;
   struct TreeNode *left, *right;

} TreeNode;

TreeNode* createTreeNode(int data) {

   TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;

   return newNode;
}

TreeNode* buildTree() {
   
   int data;
   printf("Enter data : ");
   scanf("%d", &data);

   if(data == -1) {
      return NULL;
   }

   TreeNode* root = createTreeNode(data);

   printf("Enter data for left of node %d\n", data);
   root->left = buildTree();

   printf("Enter data for right of node %d\n", data);
   root->right = buildTree();

   return root;
}

int main() {
   TreeNode* root = buildTree();
   printf("Root Node of tree : %d", root->data);
}