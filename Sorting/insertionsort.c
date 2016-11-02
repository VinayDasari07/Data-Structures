#include<stdio.h>

void insertionsort(int x[], int n)
{
 int i,j,val;
 for(i=0;i<n-1;i++)
 {
  val=x[i+1];
  for(j=i;j>=0;j--)
   if(x[j]>val)
     x[j+1]=x[j];
   else break;
  x[j+1]=val;
 }
}
void main()
{
 int n, a[50], i, ch;
 printf("Enter number of elements\n");
 scanf("%d", &n);
 for(i=0;i<n;i++)
 {
  printf("Enter element %d ", i+1);
  scanf("%d", &a[i]);
 }
 insertionsort(a,n);
 printf("Sorted Array:\n");
 for(i=0;i<n;i++)
  printf("%d ", a[i]);
}
