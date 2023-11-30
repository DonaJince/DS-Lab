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
	printf("\nienter the adjacency matrix!\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				scanf("%d",&edge[i][j]);
		}
	}
	printf("spanning tree edges are:\n");
	//printf("\nselect a starting vertex from 1 to  %d:",n);
	insert(1);
	for(i=1;i<=n;i++)
	{
		item=delete();
		visited[item]=1;
		for(j=1;j<=n;j++)
		{
			if(edge[i][j]==1 && visited[j]==0)
			{
				insert(j);
				printf("edge(%d,%d)\n",i,item);
			}
		}
	}
	printf("\n");
return 0;
}
