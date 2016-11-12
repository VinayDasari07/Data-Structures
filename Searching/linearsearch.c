#include<stdio.h>

int linearsearch(int x[], int n, int ele)
{
 for(i=0;i<n;i++)
 {
  if(ele==x[i])
   return 1;
 }
 return 0;
}
