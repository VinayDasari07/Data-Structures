#include<stdio.h>

int findmax(int x[], int n)
{
 int i, max=x[0];
 for(i=1;i<n;i++)
  if(x[i]>max)
   max=x[i];
 return max;
}

void bucketsort(int x[], int n)
{
 int count[50]={0},m,i,j,k;
 m=findmax(x,n)+1;
 for(i=0;i<n;i++)
  count[x[i]]++;
 j=0;
 for(i=0;i<m;i++)
  for(k=0;k<count[i];k++)
   x[j++]=i;
}

void main()
{
 int x[50],n,i;
 printf("Enter number of elements\n");
 scanf("%d", &n);
 printf("Enter array\n");
 for(i=0;i<n;i++)
  scanf("%d", &x[i]);
 bucketsort(x,n);
 printf("Sorted Array\n");
 for(i=0;i<n;i++)
  printf("%d", x[i]);
}
