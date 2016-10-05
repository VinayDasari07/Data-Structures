#include<stdio.h>
#define MAX 4

int q[MAX], f=0, r=-1;

void insert(int ele)
{
	if(r==MAX-1)
	{
		printf("Queue overflow\n");
		return;
	}
	r++;
	q[r]=ele;
}

int isempty()
{
	if(f==r+1)
		return 1;
	else
		return 0;
}

int delete1() // Modified Delete
{	
	int max,pos=0,i;
	max=q[f];
	pos=f;
	for(i=f+1;i<=r;i++)
	{
		if(q[i]>max)
		{
			max=q[i];
			pos=i;
		}
	}
	for(i=pos;i<r;i++)
	{
		q[i]=q[i+1];
	}
	r--;
	return max;
}

int queuefront()
{
	if(isempty())
	{
		printf("Queue empty\n");
		return -1;
	}
	else
		return(q[f]);
}

void display()
{
	int i;
	if(isempty())
	{
		printf("Queue empty\n");
		return -1;
	}
	for(i=f;i<=r;i++)
	{
		printf("%d\t", q[i]);
	}
	printf("\n");
}


void main()
{
	int ch, ele, x;
	while(1)
	{
		printf("Enter choice: \n 1. Insert \n 2. Delete \n 3. Queuefront \n 4. Display \n 5. Exit\n");
		scanf("%d", &ch);
		if(ch==5)
			return;
		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted\n");
				scanf("%d", &ele);
				if(r==MAX-1)
				{
					printf("Queue overflow\n");
					break;
				}
				insert(ele);
				display();
				break;
			case 2:
				if(isempty())
				{
					printf("Queue underflow\n");
					break;
				}
				x=delete1();
				printf("Deleted element=%d\n",x);
				break;
			case 3:
				if(isempty())
				{
					printf("Queue empty\n");
					break;
				}
				x=queuefront();
				printf("Queue front =%d\n",x);
				break;
			case 4:
				if(isempty())
				{
					printf("Queue empty\n");
					break;
				}
				display();
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
	}
}

