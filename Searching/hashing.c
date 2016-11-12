#include<stdio.h>
#define N 11

int h[N][20]={0}, count[N]={0};

void fillhashtable(int x[], int n)
{
 int i,hk;
 for(i=0;i<n;i++)
 {
  hk=x[i]%N;
  h[hk][count[hk]]=x[i];
  count[hk]++;
 }
}

int search(int ele)
{
 int hk,i;
 hk=ele%N;
 for(i=0;i<count[hk],i++)
 {
  if(ele==h[hk][i])
   return 1;
 }
 return 0;
}
