#include<stdio.h>

void merge(int x[], int lb, int m, int ub)
{
 int temp[50], i=lb, j=m+1, k=0;
 while(i<=m&&j<=ub)
 {
  if(x[i]<x[j])
   temp[k++]=x[i++];
  else temp[k++]=x[j++];
 }
 while(i<=m)
  temp[k++]=x[i++];
 while(j<=ub)
  temp[k++]=x[j++];
 k=0;
 for(i=lb;i<=ub;i++)
  x[i]=temp[k++];
}

void mergesort(int x[], int lb, int ub)
{
 int m;
 if(lb<ub)
 {
  m=(lb+ub)/2;
  mergesort(x,lb,m);
  mergesort(x,m+1,ub);
  merge(x,lb,m,ub);
 }
}
void main()
{
 int n, a[50], i, ch, lb, ub;
 printf("Enter number of elements\n");
 scanf("%d", &n);
 lb=0;
 ub=n-1;
 for(i=0;i<n;i++)
 {
  printf("Enter element %d ", i+1);
  scanf("%d", &a[i]);
 }
 mergesort(a,lb,ub);
 printf("Sorted Array:\n");
 for(i=0;i<n;i++)
 printf("%d ", a[i]);
}
