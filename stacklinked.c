#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*top;
void push();
void pop();
void traversal();
void search();
int main()
{
	int choice;
	while(1)
	{
		printf("1.push \n2.pop\n3.traversal \n4.search\n5.exit\n");
		printf("\n enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			traversal();
			break;
			case 4:
			search();
			break;
			case 5:
			exit(0);

			default:
			printf("\n invalid choice");
		}
	}
}
void push()
{
	node *ptr,*temp;
	int i,item;
	printf("enter the item:");
	scanf("%d",&item);
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	if(top==NULL)
	{
		top=ptr;
		top->next=NULL;
		printf("item is inserted\n");
	}
	else
	{
		temp=top;
		while(temp->next!=0)
		{
		temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=NULL;
		printf("item is inserted\n");
	}
}
void pop()
{
	node *ptr,*temp;
	int i,item;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else if(top->next==NULL)
	{
		item=top->data;
		free(top);
		printf("%d is deleted\n",item);
	}
	else
	{
		temp=top;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		ptr=temp->next;
		temp->next=NULL;
		item=ptr->data;
		free(ptr);
		printf("%d is deleted\n",item);
	}
}
void traversal()
{
	node *ptr,*temp;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		temp=top;
		printf("list is:\n");
		while(temp!=0)
		{
		printf("%d\n",temp->data);
		temp=temp->next;
		}
	}
}
void search()
{
	node*ptr;
	int item,count=0,i=0;
	ptr=top;
	if(ptr==NULL)
	{
		printf("\n empty list\n");
	}
	else
	{
		printf("\n enter element to be searched :");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->data==item)
		{
		printf("\n %d found at position %d\n ",ptr->data,i+1);
		count=1;
		break;
	}
	ptr=ptr->next;
	i++;
	}
	if(count==0)
	{
		printf("\n element not found\n");
	}
	}
}
