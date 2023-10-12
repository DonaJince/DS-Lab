#include<stdio.h>
#include<stdlib.h>
int max=5;
int rear=-1;
int front=-1;
int a[10],i;
void insertion();
void deletion();
void traversal();
int main()
{
	int c;
	while(1)
	{
	printf("1.insertion \n2.deletion\n3.traversal \n4.exit\n");
		printf("enter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			insertion();
			break;
			case 2:
			deletion();
			break;
			case 3:
			traversal();
			break;
			case 4:
			return 0;

			default:
			printf("\n invalid choice\n");
		}
	}
}
void insertion()
{
		int item;
		if((rear+1)%max==front)
			printf("queue is full\n");
		else
		{
			printf("enter the item:");
		         scanf("%d",&item);
			if(rear==-1&&front==-1)
			{
				rear=0;
				front=0;
			}
			else
			{
			    rear=(rear+1)%max;
			}
			 a[rear]=item;	
			 printf("%d is inserted\n",item);
		}
	   
}
void deletion()
{
	int item;
	if(front==-1)
	{
		printf("queue underflow\n");
	}
	else
	{
		if(rear==front)
		{
			item=a[front];
			rear=-1;
			front=-1;
		}
		else
		{
			item=a[front];
			front=(front+1)%max;
		}
		 printf("%d is deleted\n",item);
	}
}
void traversal()
{
	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("the list is\n");
		if(rear>=front)
		{
			for(i=front;i<=rear;i++)
			printf("%d\n",a[i]);
		}
		if(rear<front)
		{
			for(i=front;i<max;i++)
			printf("%d\n",a[i]);
			for(i=0;i<=rear;i++)
			printf("%d\n",a[i]);	
		}
	}
}


