#include<stdio.h>
#define size 5
int createindex(int x[],int n, int index[])
{
  int i, j=0;
  for(i=0;i<n;i+=size)
  {
    index[j++]=x[i];
  }
    index[j++]=x[n-1];
   return j;
}

int search(int x[],int n,int index[], int m, int ele)
{
    int i,j,k;
    if(ele<x[0] || ele>x[n-1])
    return 0;
    for(i=0;i<=m;i++)
    {
        if (ele <= index[i])
            break;
    }
        j=i*size;
        if(j>n-1)
            j=n-1;
        for(k=j;k>(i-1)*size;k--)
        {
            if (ele>= x[k])
                break;
        }
            if(ele==x[k])
                return 1;
            else return 0;
}

void main()
{
    int x[50],n,i,ele,z,a,index[50];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the sorted array\n");
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("enter the number to be searched\n");
    scanf("%d",&ele);
    z=createindex(x,n,index);
    a=search(x,n,index,z,ele);
    if(a)
    {
        printf("element found\n");
    }
    else
        printf("element not found\n");
}
