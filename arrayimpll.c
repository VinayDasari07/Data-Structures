#include<stdio.h>
#include<stdlib.h>
#define N 10

int a[N][2]={-2}, start=-1;

//Allocating Memory Function:

int allocate()
{
 int i;
 for(i=0;i<N;i++)
  if(a[i][1]==-2)
   return i;
  return -1;
}

void insertbeg(int ele)
{
 int p;
 p=allocate();
 if(p==-1)
  {
  printf("Memory Full\n");
  return;
  }
 a[p][0]=ele;
 a[p][1]=start;
 start=p;
}

void insertend(int ele)
{
 int p,q;
 p=allocate();
 if(p==-1)
  {
  printf("Memory Full\n");
  return;
  }
 a[p][0]=ele;
 a[p][1]=-1;
 if(start==-1)
  start=p;
 else
 {
  q=start;
  while(a[q][1]!=-1)
   q=a[q][1];
  a[q][1]=p;
 }
}

void display()
{
 int q;
 if(start==-1)
 {
  printf("Linked List Empty\n");
  return;
 }
 q=start;
 while(q!=-1)
 {
  printf("%d", a[q][0]);
  q=a[q][1];
 }
 printf("\n");
}
