#include<stdio.h>

void towers(int n, char s, char d, char a)
{
 if(n==1)
  printf("Move disc from %c to %c\n", s,d);
 else
 {
  towers(n-1,s,a,d);
  towers(1,s,d,a);
  towers(n-1,a,d,s);
 }
}

void main()
{
 int n;
 printf("Enter number of discs\n");
 scanf("%d", &n);
 towers(n,'A','B','C');
}
