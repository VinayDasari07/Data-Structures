#include<stdio.h>

int binarysearch(int x[], int n , int ele)
{
 int l=0,h=n-1,m;
 while(l<=h)
 {
  m=(l+h)/2;
  if(ele==x[m])
   return 1;
  if(ele<x[m])
   h=m-1;
  else
   l=m+1;
 }
 return 0;
}
