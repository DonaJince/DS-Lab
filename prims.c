#include<stdio.h>
#include<stdlib.h>
int vertex[20],cost[20][20],n,t[20][20],mincost=0,near[10],min[20][20];
int main()
{
	int i,j,b,k=0,l=0;
	
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
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(i!=j)
			{
				printf("enter the cost[%d][%d]||cost[%d][%d]:",vertex[i],vertex[j],vertex[j],vertex[i]);
				scanf("%d",&cost[i][j]);
				cost[j][i]=cost[i][j];
				if(cost[i][j]==0)
					{
					   cost[i][j]=999;
					   cost[j][i]=999;
					}
			}
		}
	}
	k=1;
	l=2;
	mincost=cost[1][2];               //setting mincost
	t[1][1]=k;                                              //minimum cost edge
	t[1][2]=l;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				if(cost[i][j]!=0)                                
				{
					if(cost[i][j]<mincost)
					{
						k=i;
						l=j;
						mincost=cost[i][j];               //setting mincost
						t[1][1]=k;                                              //minimum cost edge
						t[1][2]=l;
					}
				}
		}
	}

	//display cost of all edges in the graph
	printf("cost matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[i][j]!=999)
	          	{
			printf("%d      ",cost[i][j]);
			}
		else
		       printf("0	");
		}
		}
		printf("\n\n");
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
/*	//display cost matrix after setting the non exiting edgecost  to high value
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d      ",cost[i][j]);
		}
		printf("\n\n");
	}*/

	
	//setting near
	for(i=1;i<=n;i++)
	{
		if(cost[i][l]<cost[i][k])
			near[i]=l;
		else
			near[i]=k;
	}
		printf("initial near :");
	for(i=1;i<=n;i++)
	{
		printf("%d       ",near[i]);
	}
	printf("\n");
	near[k]=near[l]=0;
	for(i=2;i<=n-1;i++)
	{
		//finding j such that near[j]!=0 and cost is minimum
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0)
			{
				
			}
		}
		t[i][1]=j;
		t[i][2]=near[j];
		mincost+=cost[j][near[j]];
		near[j]=0;
		for(k=1;k<=n;k++)
		{
			if(near[k]!=0 && cost[k][near[k]]>cost[k][j])
				near[k]=j;
		}
	}
	//spanning tree and mincost
	printf("result:\n");
	for(i=1;i<=n-1;i++)
	{
			for(j=1;j<=2;j++)
			{
				printf("%d      ",t[i][j]);
			}
			printf("\n\n ");
	}
	printf("mincost=%d      ",mincost);	
	return 0;
}
