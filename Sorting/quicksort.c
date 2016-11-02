void quicksort(int x[], int lb, int ub)
{
 int p;
 if(lb<ub)
 {
  p=partition(x,lb,ub);
  quicksort(x,lb,p-1);
  quicksort(x,p+1,ub);
 }
}

int partition(int x[], int lb, int ub)
{
 int val = x[lb], down=lb+1, up=ub, t;
 while(down<=up)
 {
  while(down<=up&&x[down]<=val)
   down++;
  while(x[up]>val)
   up--;
  if(down<up)
  {
   t=x[down];
   x[down]=x[up];
   x[up]=t;
  }
 }
 x[lb]=x[ub];
 x[up]=val;
 return up;
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
 quicksort(a,lb,ub);
 printf("Sorted Array:\n");
 for(i=0;i<n;i++)
 printf("%d ", a[i]);
}
