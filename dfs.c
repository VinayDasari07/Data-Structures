#include<stdio.h>
int adj[20][20]={0}, visited[20]={0}, n;

void dfs(int node)
{
 int i;
 visited[node]=1;
 printf("%d ", node+1);
 for(i=0;i<n;i++)
  if(adj[node][i]==1 && visited[i]==0)
   dfs(i);
}

void main()
{
 int i,e,v1,v2,node;
 printf("Enter number of nodes\n");
 scanf("%d", &n);
 printf("Enter number of edges\n");
 scanf("%d", &e);
 printf("Enter edges\n");
 for(i=0;i<e;i++)
 {
  scanf("%d%d", &v1, &v2);
  adj[v1-1][v2-1]=adj[v2-1][v1-1]=1;
 }
 printf("Enter starting vertex\n");
 scanf("%d", &node);
 dfs(node-1);
}
