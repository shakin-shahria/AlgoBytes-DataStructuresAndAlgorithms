#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};


struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

// Sum function
int sumEvenNodes(struct node* root)
{
  if (root == NULL) return 0;

  // Taking only odd values
  int sum = 0;
  if (root->data % 2 == 1) sum += root->data;

  // Recursively sum the nodes in the left and right subtrees
  sum += sumEvenNodes(root->left);
  sum += sumEvenNodes(root->right);

  return sum;
}

int main()
{

  struct node* root = newNode(8);
  root->left = newNode(3);
  root->right = newNode(10);
  root->left->left = newNode(1);
  root->left->right = newNode(6);
  root->left->right->left = newNode(4);
  root->left->right->right = newNode(7);
  root->right->left = newNode(13);
  printf("Sum of even nodes: %d\n", sumEvenNodes(root));

  return 0;
}

