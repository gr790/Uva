#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
  int data;
  struct node *left, *right;
}NODE;

NODE* newNode(int data)
{
  NODE *tmp = (NODE*)malloc(sizeof(NODE));
  tmp->left = tmp->right = NULL;
  tmp->data = data;
  return tmp;
}

void CreateBST(NODE *&root, int val)
{
  if(root==NULL)
  {
    root = newNode(val);
    root->left = root->right = NULL;
  }
  else
  {
    if(root->data <= val)
      CreateBST(root->right, val);
    else if(root->data > val)
      CreateBST(root->left, val);
  }
}

void postorder(NODE *root)
{
  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
  }
}

void deleteBinaryTree(NODE *&root)
{
  if(root!=NULL)
  {
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    free(root);
    root = NULL;
  }
}


int main()
{
  freopen("./sample.txt", "r", stdin);
  int num;  
  NODE *root = NULL;
  while(scanf("%d\n", &num) != EOF)
  {
    CreateBST(root, num);
  }
  postorder(root);
  cout << endl;
  deleteBinaryTree(root);
  return 0;
}
