#include<stdio.h>
#define MAX 6

int q[MAX], f=MAX/2, r=MAX/2;

void insertleft(int ele)
{
 if(f==-1)
 {
  printf("Queue overflow\n");
  return;
 }
 q[f]=ele;
 f--;
}

void insertright(int ele)
{
 if(r==MAX-1)
 {
  printf("Queue overflow\n");
  return;
 }
 r++;
 q[r]=ele;
}

int isempty()
{
 if(f==r)
  return 1;
 else return 0;
}

int deleteleft()
{
 if(isempty())
 {
  printf("Queue underflow\n");
  return -1;
 }
 f++;
 return(q[f]);
}

int deleteright()
{
 if(isempty())
 {
  printf("Queue underflow\n");
  return -1;
 }
 z=q[r];
 r--;
 return z;
}

void display()
{
 int i;
 if(isempty())
 {
  printf("Queue Empty\n");
  return;
 }
 for(i=f;i<=r;i++)
  printf("%d", q[i]);
 printf("\n");
}
