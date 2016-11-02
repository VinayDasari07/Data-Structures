void shellsort(int x[], int n)
{
 int i,j,k,inc,val;
 for(inc=n/2;inc>=1;inc=inc/2)
 {
  for(k=0;k<inc;k++)
  {
   for(i=k;i<n-inc;i=i+inc)
   {
    val=x[i+inc];
    for(j=i;j>=k;j=j-inc)
    {
     if(x[j]>val)
      x[j+inc]=x[j];
     else break;
    }
    x[j+inc]=val;
   }
  }
 }
}
void main()
{
 int n, a[50], i, ch;
 printf("Enter number of elements\n");
 scanf("%d", &n);
 for(i=0;i<n;i++)
 {
  printf("Enter element %d ", i+1);
  scanf("%d", &a[i]);
 }
 shellsort(a,n);
 printf("Sorted Array:\n");
 for(i=0;i<n;i++)
 printf("%d ", a[i]);
}
