#include<stdio.h>
#include<stdlib.h>
int s[10],visited[10],i,j,n,edge[10][10];
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
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			
		}
	}
}