#include<stdio.h>

int findmaxdig(int x[], int n)
{
 int i, max=x[0],d=0;
 for(i=1;i<n;i++)
  if(x[i]>max)
   max=x[i];
  while(max!=0)
  {
   d++;
   max=max/10;
  }
  return d;
}

void radixsort(int x[], int n)
{
 int i,j,k,dig,d,r;
 d=findmaxdig(x,n);
 for(k=1;k<=d;k++)
 {
  int nos[10][10]={0}, count[10]={0};
  for(i=0;i<n;i++)
  {
   dig=x[i]/(int)pow(10,k-1)%10;
   nos[dig][count[dig]]=x[i];
   count[dig]++;
  }
  r=0;
  for(i=0;i<10;i++)
   for(j=0;j<count[i];j++)
    x[r++]=nos[i][j];
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
 radixsort(x,n);
 printf("Sorted Array\n");
 for(i=0;i<n;i++)
  printf("%d", x[i]);
}
