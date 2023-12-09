#include<stdio.h>
#include<stdlib.h>
int n,adj[10][10],i,j,c,f,in,visited[10],temp;
int indegree(int v)
{
f=0;
  for(c=1;c<=n;c++)
  {
   if(adj[c][v]==0 && visited[v]!=-1)
   {
    f++;
   }
  }
  if(f==temp)
   return 1;
  else
   return 0;
}
int main()
{
 printf("Total no of vertices :: ");
 scanf("%d",&n);
 temp=n;
 printf("\nenter the adjacency matrix!\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
    scanf("%d",&adj[i][j]);
  }
 }
 for(i=1;i<=n;i++)
   visited[i]=i;
 printf("\ntopological ordering of above graph is :\n\n");
 for(i=1;i<=n;i++)
 {
  in=indegree(i);
  if(in==1 && visited[i]!=-1)
  {
   printf("%d-->",i);
     temp--;
   visited[i]=-1;
   for(j=1;j<=n;j++)
   {
    adj[i][j]=-1;
    adj[j][i]=-1;
   }
   i=1;
  }
 }
return 0;
}