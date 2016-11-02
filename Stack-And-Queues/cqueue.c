#include<stdio.h>
#define MAX 4

int q[MAX], f=0, r=MAX-1, ele, count=0;

void insert(int ele)
{
	if(count==MAX)
	{
		printf("Queue overflow\n");
		return;
	}
	count++;
	r=(r+1)%MAX;
	q[r]=ele;
}

int isempty()
{
	if(count==0)
		return 1;
	else
		return 0;
}

int delete1()
{
	int z;
	if(isempty())
	{
		printf("Queue underflow\n");
		return -1;
	}
	count--;
	z=q[f];
	f=(f+1)%MAX;
	return z;
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
		return;
	}
	i=f;
	while(1)
	{
		printf("%d ", q[i]);
		if(i==r)
			break;
		else
			i=(i+1)%MAX;
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
				if(count==MAX)
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

				
						
