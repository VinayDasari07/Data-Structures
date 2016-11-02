#include<stdio.h>

void display(int n) // Function to display first n natural numbers using Recursion.
{
 if(n>1)
 {
  display(n-1);
 }
 printf("%d", n);
}
