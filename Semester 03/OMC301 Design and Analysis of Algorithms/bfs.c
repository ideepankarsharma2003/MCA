#include <stdio.h>
#define INFN 999;
void bfs(int);
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
	printf("\n\nThe BFS order of vertices :");
	bfs(src);
}
void bfs(int src)
{
    int v,u, q[20],f=0,r=0;
    visited[src]=1;
    r++;
    q[r]=u=src;
    printf("\t%d",src);
    while(f!=r)   // queue not empty
    {
       for(v=1;v<=n;v++)
          if((a[u][v]==1)&&(visited[v]==0))
          {
              visited[v]=1;
              r++;
              q[r]=v;
              printf("\t%d",v);
          }
        u=q[++f];
    }
    
}