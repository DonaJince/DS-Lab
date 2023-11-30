#include<stdio.h>
#include<stdlib.h>
int q[10],visited[10],i,j,n,edge[10][10],front=1,rear=0,v,item;
void insert(int v)
{
	rear++;
	q[rear]=v;
}
int delete()
{
	v= q[front];
	front++;
	return v;
}
int main()
{
	printf("Total no of vertices :: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		 visited[i]=0;
	printf("\nif edge is present assign 1 ,otherwise 0!\n");
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(i!=j)
			{
				printf("is edge (%d,%d)||edge(%d,%d) exist or not???:",i,j,j,i);
				scanf("%d",&edge[i][j]);
				edge[j][i]=edge[i][j];
			}
			else
			 	edge[j][i]=edge[i][j]=0;
		}
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		printf("%d    ",edge[i][j]);
		}
	printf("\n");
	}*/
	//printf("\nselect a starting vertex from 1 to  %d:",n);
	insert(1);
	for(i=1;i<=n;i++)
	{
		item=delete();
		visited[item]=i;
		for(j=1;j<=n;j++)
		{
			if(edge[i][j]==1 && visited[j]==0)
			{
				insert(j);
			}
		}
	}
	printf("\n");
	for(i=1;i<=n;i++)
	 printf("%d\n",visited[i]);
return 0;
}
