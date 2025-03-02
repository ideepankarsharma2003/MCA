#include<stdio.h>
#include<conio.h>
int near[10], cost[10][10], tree[10][5], min, mincost=0;
int input(int,int);
int display(int);
int prims(int);

int input(int num, int edges)
{
	int i, j, u, v, c;
	for(i=1; i<=num; i++)
	   for(j=1; j<=num; j++)
		cost[i][j]=999;	
	printf("\nEnter the edges\n\n");
	for(i=1; i<=edges; i++)
	{
		printf("Enter egde %d and its cost :", i);
		scanf("%d%d%d",&u,&v,&c);
		cost[u][v]=cost[v][u]=c;
	}
	return 0;
}
int display(int num)
{
	int i, j;
	printf("\nThe cost of adjacency matrix\n\n");
	
	for(i=1; i<=num; i++)
	{
		for(j=1; j<=num; j++)
		{
			printf("%d", cost[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	return 0;
}

int prims(int num)
{
	int i, j, k, l, u, v, min;
	
	min=999;
	for(i=1;i<=num;i++)
	   for(j=1;j<=num;j++)
		if(cost[i][j]< min)
	         {
			min=cost[i][j];
			k=u=i; 
			l=v=j;
		   }
	tree[1][1]=k;tree[1][2]=l;tree[1][3]=mincost=cost[k][l];
	for(i=1;i<=num;i++)
	   if(cost[i][k]<cost[i][l])
		near[i]=k;
	   else
		near[i]=l;
	near[k]=near[l]=0;
	for(i=2;i<=num-1;i++)
	{
		min=999;
		for(j=1;j<=num;j++)
		   if ((near[j]!=0)&&(cost[j][near[j]]<min))
		   {
			min=cost[j][near[j]];
			k=j;
		   }
		tree[i][1]=k;tree[i][2]=near[k];tree[i][3]=min;
 		mincost=mincost+min;
 		near[k]=0;
	      for(j=1;j<=num;j++)
		   if((near[j]!=0)&&(cost[j][near[j]]>cost[j][k]))
			near[j]=k;
	}
	printf("The spanning tree edges and costs are :\n");
	for(i=1;i<=num-1;i++)
	   printf("Edge %d : %d %d cost = %d\n",i,tree[i][1],tree[i][2],tree[i][3]);
	
	printf("\n\n\n Minimun cost=%d",mincost);
}
int main()
{
	int num,edges;
	printf("\n\t\t\tPrim's Algorithm");
	printf("\n\nEnter the number of nodes and edges= ");
	scanf("%d%d", &num,&edges);
	input(num,edges);
	display(num);
	prims(num);
	getch();
	return 0;
}