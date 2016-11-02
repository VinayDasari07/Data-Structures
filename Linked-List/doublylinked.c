#include<stdio.h>
#include<stdlib.h>

typdef struct node
{
 int data;
 struct node *next, *prev;
}node;

node *start=NULL, *last=NULL;

void insertbeg(int ele)
{
 node *p;
 p=(node*)malloc(sizeof(node));
 p->data=ele;
 p->next=p->prev=NULL;
 if(start==NULL)
  start=last=p;
 else
 {
  p->next=start;
  start->prev=p;
  start=p;
 }
}

void insertend(int ele)
{
 node *p;
 p=(node*)malloc(sizeof(node));
 p->data=ele;
 p->next=p->prev=NULL;
 if(start==NULL)
  start=last=p;
 else
 {
  p->prev=last;
  last->next=p;
  last=p;
 }
}

void display()
{
 node *q;
 if(start==NULL)
 {
  printf("DLL Empty\n");
  return;
 }
 q=start;
 while(q!=NULL)
 {
  printf("%d", q->data);
  q=q->next;
 }
 printf("\n");
}

void revdisplay()
{
 node *q;
 if(start==NULL)
 {
  printf("DLL Empty\n");
  return;
 }
 q=last;
 while(q!=NULL)
 {
  printf("%d", q->data);
  q=q->prev;
 }
 printf("\n");
}

int deletebeg()
{
 node *p;
 if(start==NULL)
 {
  printf("DLL Empty\n");
  return -1;
 }
 p=start;
 if(start==last)
  start=last=NULL;
 else
 {
  start=start->next;
  start->prev=NULL;
 }
 return(p->data);
}

int deleteend()
{
 node *p;
 if(start==NULL)
 {
  printf("DLL Empty\n");
  return -1;
 }
 p=last;
 if(start==last)
  start=last=NULL;
 else
 {
  last=last->prev;
  last->next=NULL;
 }
 return(p->data);
}
