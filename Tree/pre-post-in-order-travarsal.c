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

void preOrderTrvrsl(TreeNode* root) {  // NLR
   // base case 
   if(root == NULL) {
      return;
   }

   printf("%d ", root->data);
   preOrderTrvrsl(root->left);
   preOrderTrvrsl(root->right);
}

void inOrderTrvrsl(TreeNode* root) {  // LNR
   // base case
   if(root == NULL) {
      return;
   }

   inOrderTrvrsl(root->left);
   printf("%d ", root->data);
   inOrderTrvrsl(root->right);
}

void postOrderTrvrsl(TreeNode* root) {  // LRN
   // base case
   if(root == NULL) {
      return;
   }

   postOrderTrvrsl(root->left);
   postOrderTrvrsl(root->right);
   printf("%d ", root->data);
}

int main() {
   TreeNode* root = buildTree();
   printf("\nRoot node of tree : %d\n", root->data);

   printf("\nPre Order Travarsal : ");
   preOrderTrvrsl(root);
   printf("\n");

   printf("\nIn Order Travarsal : ");
   inOrderTrvrsl(root);
   printf("\n");

   printf("\nPost Order Travarsal : ");
   postOrderTrvrsl(root);
   printf("\n");
}