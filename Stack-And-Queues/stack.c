#include<stdio.h>
#include<conio.h>
#define MAX 4
int s[4];
int tos=-1;

int isempty()
{
 if(tos==-1)
   return 1;
 else
   return 0;
}
void push(int ele)
{
 if(tos==MAX-1)
   printf("Stack Overflow.");
 else
 {
   tos++;
   s[tos]=ele;
 }
}
int pop()
{
 if(isempty())
 {
  printf("Stack Underflow.");
  return -1;
 }
 else
  {
   tos--;
   return s[tos+1];
  }
}
int stacktop()
{
  if(isempty())
  {
    printf("Stack empty.");
    return -1;
  }
  else
    return s[tos];
}
void display()
{
 int i;
 for(i=tos;i>=0;i--)
 {
  printf("%d\n",s[i]);
 }
}
void main()
{
 int ch,n;
 clrscr();
 while (1)
 {
  printf("Enter choice\n 1.Push 2.Pop 3.Stacktop 4. Display 5.Exit");
  scanf("%d",&ch);
  if(ch==5)
   break;
  switch(ch)
  {
   case 1:printf("Enter element.");
	  scanf("%d",&n);
	  push(n);
	  display();
	  break;
   case 2:if(isempty())
	   printf("Stack underflow\n");
	  else
	  {
	   printf("Popped element is %d\n",pop());
	   display();
	  }
	  break;
   case 3:printf("The topmost element is %d\n",stacktop());
	  display();
	  break;
   case 4:display();
	  break;
  }
 }
}
