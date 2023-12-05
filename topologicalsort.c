#include<stdio.h>
#include<stdlib.h>
int n,adj[10][10],i,j,c,f,in,order[10];
int indegree(int v)
{
f=0;
		for(c=1;c<=n;c++)
		{
			if(adj[c][v]==0)
			{
				f=1;
			}
		}
		if(f==1)
			return 1;
		else
			return 0;
}
int main()
{
	printf("Total no of vertices :: ");
	scanf("%d",&n);
	printf("\nenter the adjacency matrix!\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				scanf("%d",&adj[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		 order[i]=i;
	printf("\ntopological ordering of above graph is :\n\n");
	for(i=1;i<=n;i++)
	{
		in=indegree(i);
		if(in==1 && order[i]!=0)
		{
			printf("%d-->",i);
			order[i]=0;
			for(j=1;j<=n;j++)
			{
				adj[i][j]=0;
			}
			i=1;
		}
	}
return 0;
}
