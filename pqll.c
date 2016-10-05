#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;
 
node *start=NULL;

void insert(int ele)
 {
  node *p,*q;
  p=(node*)malloc(sizeof(node));
  p->data=ele;
  if(start==NULL)
   start=p;
  else if((p->data)>(start->data))
  {
   p->next=start;
   start=p;
  }
  else
  {
   q=start;
   while((p->data)<(q->next->data))
    {
     q=q->next; 
    }
    p->next=q->next;
    q->next=p;
  }
}
 

int delete1()
{
 node *p;
 if(start==NULL)
 {
  printf("Linked List Empty\n");
  return -1;
 }
 p=start;
 start=start->next;
 return(p->data);
}   

void display()
{
 node *q;
 q=start;
 if(start==NULL)
 {
  printf("Linked list empty\n");
  return;
 }
 while(q!=NULL)
 {
  printf("%d\t",q->data);
  q=q->next;
 }
} 

void main()
{
 int ele,ch;
 while (1)
 {
   printf("Enter a choice\n 1.insert\n 2.delete\n 3.display\n 4.exit\n");
   scanf("%d",&ch);
   if(ch==4)
  break;
  switch(ch)
  {
    case 1:
    printf("enter an element ");
    scanf("%d",&ele);
    insert(ele);
    display();
    break;
    
    case 2:
    ele=delete1();
    printf("%d",ele);
    display();
    break;
    
    case 3:
    display();
    break;
    
    default:
    printf("Invalid choice");
  }
 }
}
