#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct node
{
 char data;
 struct node *left,*right;
}node;
 
node *s[MAX];
node *root=NULL;
int tos=-1;

void push(node *x)
{
 tos++;
 s[tos]=x;
}

node* pop()
{
 tos--;
 return s[tos+1];
}

int isoperand(char ch)
{
 if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
      return 1;
 else return 0;
}

void convert(char post[])
{
 int i;
 node *p;
 int l=strlen(post);
 for(i=0;i<l;i++)
 {
  if(isoperand(post[i]))
  {
   p=(node*)malloc(sizeof(node));
   p->data=post[i];
   p->left=p->right=NULL;
   push(p);
  }
  else
  {
    p=(node*)malloc(sizeof(node));
    p->data=post[i];
    p->right=pop();
    p->left=pop();
    push(p);
  }
 }
 root=pop();
}

void inorder(node *x)
{
    if(x!=NULL)
    {
     inorder(x->left);
     printf("%c ",x->data);
     inorder(x->right);
    }
}

void preorder(node *x)
{
    if(x!=NULL)
    {
     printf("%c ",x->data);
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
     printf("%c ",x->data);
    }
}

void main()
{
  int ch;
  char post[100];
  printf("Enter postfix expression: \n");
  gets(post);
  convert(post);
  while(1)
  {
   printf("Enter choice: 1.Infix 2.Postfix 3.Prefix 4.Exit\n");
   scanf("%d",&ch);
   if(ch==4)
     break;
   switch(ch)
   {
    case 1:printf("Infix Expression is: ");
           inorder(root);
           printf("\n");
           break;
    case 2:printf("Postfix Expression is: ");
           postorder(root);
           printf("\n");
           break;
    case 3:printf("Prefix Expression is: ");
           preorder(root);
           printf("\n");
           break;
   }
  }
}
