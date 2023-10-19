#include<stdio.h>
int i,n,a[10],item;
void read(int n);
void linear();
void binary();
int main()
{
int choice;
	while(1)
	{
		printf("1.linearsearch\n2.binarysearch\n3.exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			linear();
			break;
			case 2:
			binary();
			break;
			case 3:
			return 0;

			default:
			printf("\n invalid choice");
		}
	}
return 0;
}
void read(int n)
{
	for(i=0;i<n;i++)
	{
		printf("enter the item:");
		scanf("%d",&a[i]);
	}
	printf("Array is :\n");
	for(i=0;i<n;i++)
	{
	 	printf("%d\n",a[i]);
	}
}
void linear()
{
	int flag=0;
	printf("enter the limit of array:");
	scanf("%d",&n);
	read(n);
	printf("enter the value to be searched:");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
		{
			printf("%d is found at index %d\n",item,i);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("item not found\n");
	}
}
void binary()
{
	int mid,high,low;
	printf("enter the limit of array:");
	scanf("%d",&n);
	printf("enter the items in ascending order\n");
	read(n);
	printf("enter the value to be searched:");
	scanf("%d",&item);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=low+high/2;
		if(a[mid]==item)
		{
			printf("%d is found at index %d\n",item,mid);
			break;
		}
		else if(item<a[mid])
		{
			high=mid-1;
		}
		else if(item>a[mid])
		{
			low=mid+1;
		}
	}
	if(low>high)
	printf("item not found\n");
}
