#include <stdio.h>
#define INFN 999;
void floyds();
int n, i, j, e;
int a[20][20], n, e, cost[10][10];
int main()
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
		cost[u][v]=c;
	}
 	floyds();
	printf("\nshortest path matrix :\n");
	for(i=1;i<=n;i++)
	{
	   for(j=1;j<=n;j++)
		printf("%5d", a[i][j]);
	   printf("\n");
	}
	return(0);
}
void floyds()
{ int i,j,k;
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
		a[i][j]=cost[i][j];
	  a[i][i]=0;
	}
	for(k=1;k<=n;k++)
	   for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		   if(a[i][k]+a[k][j]<a[i][j])
			a[i][j]=a[i][k]+a[k][j];
}