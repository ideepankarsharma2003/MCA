
#include <stdio.h>
#define INFN 999;
void dfs(int);
int n, i, j, e, src;
int visited[20] = {0}, e, a[10][10];
void main()
{
	int u, v, c;
 	printf("\nEnter the number of nodes:");
 	scanf("%d",&n);
	printf("\nEnter the number of edges :");
	scanf("%d",&e);
	for(i=1; i<=n; i++)
	   for(j=1; j<=n; j++)
		a[i][j]=0;	
	printf("\nEnter the edges\n\n");
	for(i=1; i<=e; i++)
	{
		printf("\nEnter egde %d :", i);
		scanf("%d%d",&u,&v);
		a[u][v]=a[v][u]=1;
	}
 	printf("\n\nEnter the source vertex :");
	scanf("%d", &src);
	printf("\n\nThe DFS order of vertices :");
	dfs(src);
}
void dfs(int src)
{
    int v;
    visited[src]=1;
    printf("\t%d",src);
    for(v=1;v<=n;v++)
       if((a[src][v]==1)&&(visited[v]==0))
          dfs(v);
}