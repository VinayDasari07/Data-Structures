#include<stdio.h>

void modifiedbubblesort(int x[], int n)
{
 int i,j,t,exchange=1;
 for(i=0;exchange==1&&i<n-1;i++)
 {
  exchange=0;
  for(j=0;j<n-1;j++)
  {
   if(x[j]>x[j+1])
   {
    exchange=1;
    t=x[j];
    x[j]=x[j+1];
    x[j+1]=t;
   }
  }
 }
}

void main()
{
 int x[50],n,i;
 printf("Enter number of elements\n");
 scanf("%d", &n);
 printf("Enter array\n");
 for(i=0;i<n;i++)
  scanf("%d", &x[i]);
 modifiedbubblesort(x,n);
 printf("Sorted Array\n");
 for(i=0;i<n;i++)
  printf("%d", x[i]);
}
