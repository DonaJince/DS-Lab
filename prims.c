#include<stdio.h>
#include<stdlib.h>
int vertex[20],cost[20][20],n,t[20][20],mincost=0,near[10],edgecount=0;
int main()
{
	int i,j,k=0,l=0;
	
	//count of vertices
	printf("enter the number of vertices:");
	scanf("%d",&n);
	
	//vertices in the graph
	printf("\n Enter vertices  \n\n");
	for(i=1;i<=n;i++)
	{
		printf("vertex[%d] :: ",i);
		scanf("%d",&vertex[i]);
	}
	//cost of all edges in the graph
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(i+1!=j)
			{
				printf("enter the cost[%d][%d]||cost[%d][%d]:",vertex[i+1],vertex[j],vertex[j],vertex[i+1]);
				scanf("%d",&cost[i+1][j]);
				cost[j][i+1]=cost[i+1][j];
				if(cost[i+1][j]!=0)
				{
					edgecount++;
					if(cost[i+1][j]<=mincost)
					{
						k=i+1;
						j=j;
						mincost=cost[i+1][j];
						t[1,1]=k;
						t[1][2]=j;
					}
				}
			}
		}
	}
	
		//display cost of all edges in the graph
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d      ",cost[i][j]);
		}
		printf("\n");
	}
	
	//setting the cost of  non existing nodes to a high value
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(cost[i][j]==0&& cost[j][i]==0)
			{
			cost[i][j]=999;
			cost[j][i]=999;
			}
			
		}
	}
	//display cost matrix after setting the non exiting edgecost  to high value
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d      ",cost[i][j]);
		}
		printf("\n");
	}
	printf("%d",edgecount);
	return 0;
}
