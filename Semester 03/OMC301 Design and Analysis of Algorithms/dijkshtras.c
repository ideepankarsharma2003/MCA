#include <stdio.h>
#define INFN 999;
void dijkstras(int);
int n, i, j, e, src;
int visited[20] = {0},min,e, cost[10][10];
void main()
{
	int u, v, c;
 	printf("\nEnter the number of nodes:");
 	scanf("%d",&n);
	printf("Enter the number of edges :");
	scanf("%d",&e);
	for(i=1; i<=n; i++)
	   for(j=1; j<=n; j++)
		cost[i][j]=999;	
	printf("\nEnter the edges\n\n");
	for(i=1; i<=e; i++)
	{
		printf("Enter egde %d and its cost :", i);
		scanf("%d%d%d",&u,&v,&c);
		cost[u][v]=cost[v][u]=c;
	}
 	printf("Enter the source vertex :");
	scanf("%d", &src);
	dijkstras(src);
}
void dijkstras(int src)
{// src is the source vertex.
    int d[20],min,i,j,k,u,v;
    for (i = 1; i <= n; i++)
    {
         visited[i] = 0;  // Shortest path to vertex i not yet found.
         d[i] = cost[src][i];  // Initialize the distance array
     }
     visited[src] = 1;  // Source vertex is visited
     d[src] = 0;      // Distance of source vertex from itself
     for (i = 1; i <= n-1; i++) 
     {
          min = INFN;
	    // choose vertex u ∉ S such that d[u] is minimum
	    for( k = 1; k <= n; k++)
		if ((visited[k] == 0) && (d[k] < min))
		{   min = d[k];
		    u = k;
		}
	    visited[u] = 1;
	    for(v = 1; v <= n; v++)
	    {   if (visited[v] == 0) 
                if (d[u] + cost[u][v] < d[v]) 
                      d[v] = d[u] + cost[u][v];
        }
     }
	printf("The lengths of the shortest paths are :\n");
	for(i = 1; i <= n; i++)
	   printf("The length of the shortest path from %d to %d is %d\n", src, i, d[i]);
}