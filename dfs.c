#include<stdio.h>
#include<stdlib.h>
int s[10],visited[10],i,f,j,n,adj[10][10],top=0,v,k,item;
void push(int v)
{
	top++;
	s[top]=v;
}
int pop()
{
	v= s[top];
	top--;
	return v;
}
int main()
{
	printf("Total no of vertices :: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		 visited[i]=0;
	printf("\nenter the adjacency matrix!\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				scanf("%d",&adj[i][j]);
		}
	}
	printf("spanning tree edges are:\n");
	//printf("\nselect a starting vertex from 1 to  %d:",n);
	push(1);
	i=1;
	while(top!=0 && i<n)
	{
		f=0;
		item=s[top];
		visited[item]=1;
		for(j=1;j<=n;j++)
		{
			if(adj[item][j]==1 && visited[j]==0)
			{
				printf("%d-->%d",item,j);
				push(j);
				f=1;
				break;
			}
		}	
	if(f==0)
	k=pop();
	else
	i++;
	}
	
return 0;
}
