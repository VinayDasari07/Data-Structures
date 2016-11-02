#include<stdio.h>

void heapup(int x[], int r, int b)
{
 int p,t,;
 if(b>r)
 {
  p=(b-1)/2;
  if(x[p]<x[b])
  {
   t=x[p];
   x[p]=x[b];
   x[b]=t;
   heapup(x,r,p);
  }
 }
}

void heapdown(int x[], int r, int b)
{
 int lc=2*r+1,rc=2*r+2,mc,t;
 if(lc<=b)
 {
  if(lc==b)
   mc=lc;
  else if(x[lc]>x[rc])
   mc=lc;
  else mc=rc;
  if(x[r]<x[mc])
  {
   t=x[r];
   x[r]=x[mc];
   x[mc]=t;
   heapdown(x,mc,b);
  }
 }
}

void heapsort(int x[], int n)
{
 int i,t;
 for(i=0;i<n-1;i++)
  heapup(x,0,i+1)
 for(i=n-1;i>0;i--)
 {
  t=x[0];
  x[0]=x[i];
  x[i]=t;
  heapdown(x,0,i-1);
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
 heapsort(x,n);
 printf("Sorted Array\n");
 for(i=0;i<n;i++)
  printf("%d", x[i]);
}
