#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node* left, *right;
}node;

node *root=NULL;

node* father(node *p)
{
 node *q;
 if(p==root)
  return NULL;
 q=root;
 while(q!=NULL)
 {
  if(q->left==p || q->right==p)
   return q;
  if(p->data <= q->data)
   q=q->left;
  else
   q=q->right;
 }
 return NULL;
}

node *findmax(node *p)
{
 if(p->right==NULL)
  return p;
 else return(findmax(p->right));
}

int search(int ele)
{
 int z;
 node *q=root;
 while(q!=NULL)
 {
  if(ele==q->data)
   return 1;
  if(ele<q->data)
   q=q->left;
  else
   q=q->right;
 }
 return 0;
}

void insert(int ele)
{
 node *p, *q;
 p=(node*)malloc(sizeof(node));
 p->data=ele;
 p->left=p->right=NULL;
 if(root==NULL)
  {
   root=p;
   return;
  }
 q=root;
 while(q!=NULL)
 {
  if(ele<=q->data)
  {
   if(q->left==NULL)
   {
    q->left=p;
    return;
   }
   else q=q->left;
  }
  else if(q->right==NULL)
  {
   q->right=p;
   return;
  }
  else
   q=q->right;
 }
}

void delete1(int ele)
{
 node *q;
 if(q==NULL)
 {
  printf("BST Empty\n");
  return;
 }
 q=root;
 while(q!=NULL)
 {
  if(ele==q->data)
   break;
  if(ele<q->data)
   q=q->left;
  else
   q=q->right;
 }
 if(q==NULL)
 {
  printf("%d not Found\n, ele");
  return;
 }
 if(q->left==NULL && q->right==NULL)
 {
  if(q==root)
  {
   root=NULL;
   return;
  }
  if(father(q)->left == q)
  {
   father(q)->left=NULL;
   return;
  }
  else 
  {
   father(q)->right=NULL;
   return;
  }
 }
 if(q->left!=NULL)
 {
  int val;
  node *max = findmax(q->left);
  val=max->data;
  delete1(max->data);
  q->data=val;
  return;
 }
 if(q==root)
 {
  root=root->right;
  return;
 }
 if(father(q)->left==q)
 {
  father(q)->left=q->right;
 }
 else
  father(q)->right=q->right;
}

void inorder(node *x)
{
 if(x!=NULL)
 {
  inorder(x->left);
  printf("%d", x->data);
  inorder(x->right);
 }
}

void preorder(node *x)
{
 if(x!=NULL)
 {
  printf("%d", x->data);
  preorder(x->left);
  preorder(x->right);
 }
}

void postorder(node *x)
{
 if(x!=NULL)
 {
  postorder(x->left);
  postorder(x->right);
  printf("%d", x->data);
 }
}

void main()
{
 int ch, ele,z;
 while(1)
 {
  printf("Enter Choice:\n 1. Insert \n 2.Delete \n 3. Search \n 4. Inorder \n 5. Preorder \n 6. Postorder \n 7. Exit\n");
  scanf("%d", &ch);
  if(ch==7)
   break;
  switch(ch)
  {
   case 1:
    printf("Enter element to be inserted\n");
    scanf("%d", &ele);
    insert(ele);
    break;
   case 2:
    printf("Enter element to be deleted\n");
    scanf("%d", &ele);
    delete1(ele);
    break;
   case 3:
    printf("Enter element to be searched\n");
    scanf("%d", &ele);
    z=search(ele);
    if(z==1)
     printf("Element found");
    else
     printf("Element not found");
    break;
   case 4:
    inorder(root);
    break;
   case 5:
    preorder(root);
    break;
   case 6:
    postorder(root);
    break;
  }
 }
}
