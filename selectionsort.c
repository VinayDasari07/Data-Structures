#include<stdio.h>

void selectionsort(int x[], int n)
{
 int i,j,min,pos;
 for(i=0;i<n-1;i++)
 {
  min=x[i];
  pos=i;
  for(j=i+1;j<n;j++)
  {
   if(x[j]<min)
    min=x[j];
    pos=j;
  }
  x[pos]=x[i];
  x[i]=min;
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
 selectionsort(x,n);
 printf("Sorted Array\n");
 for(i=0;i<n;i++)
  printf("%d", x[i]);
}
