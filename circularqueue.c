#include<stdio.h>
#include<stdlib.h>
int max=5;
int rear=-1;
int front=-1;
int a[10],i;
void insertion();
void deletion();
void traversal();
void search();
int main()
{
	int c;
	while(1)
	{
	printf("\n1.insertion \n2.deletion\n3.traversal \n4.search\n5.exit\n");
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
			search();
			break;
			case 5:
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
			if(front==0)
			{
				for(i=front;i<=rear;i++)
				{
					printf("\n%d",a[i]);	
				}
				for(i=rear+1;i<max;i++)
				{
					printf("\n-");	
				}
			}
			if(front>rear)
			{
				for(i=0;i<=rear;i++)
				{
					printf("\n%d",a[i]);	
				}
				for(i=rear+1;i<front;i++)
				{
					printf("\n-");	
				}
					for(i=front;i<max;i++)
				{
					printf("\n%d",a[i]);	
				}
			}
			if(rear>=front && front!=0)
			{
				for(i=0;i<front;i++)
				{
					printf("\n-");	
				}
				for(i=front;i<=rear;i++)
				{
					printf("\n%d",a[i]);	
				}
				for(i=rear+1;i<max;i++)
				{
					printf("\n-");	
				}
			}
	}
		
}
void search()
{
	int item,loc=-1;
	if(front==-1)
	{
		printf("queue is empty\n");
		return;
	}
	else
	{
		printf("enter the element to be searched:");
		scanf("%d",&item);
		if(front==0)
		{
			for(i=front;i<=rear;i++)
			{
				if(item==a[i])
				{
					loc=i;
					break;	
				}
			}
		}
		if(front>rear)
		{
			for(i=0;i<=rear;i++)
			{
				if(item==a[i])
				{
					loc=i;
					break;	
				}
			}
			for(i=front;i<max;i++)
			{
				if(item==a[i])
				{
					loc=i;
					break;	
				}
			}
		}
		if(rear>=front && front!=0)
		{
			for(i=front;i<=rear;i++)
			{
				if(item==a[i])
				{
					loc=i;
					break;	
				}
			}
		}
		if(loc==-1)
			printf("%d is not found\n",item);
		else
			printf("%d is found at index:%d\n",item,loc);
	}
}
