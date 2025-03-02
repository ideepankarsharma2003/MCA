#include<stdio.h>
#include<conio.h>
int parent[20]={0}, edges[20][5], tree[20][5], mincost=0;
int find(int);
void uni(int, int);
void input(int,int);
int display(int);
void kruskals(int,int);
void input(int num, int e)
{
	int i, j, u, v, c;
	printf("\nEnter the edges in the increasing order of their cost \n\n");
	for(i=1; i<=e; i++)
	{
		printf("Enter egde %d and its cost :", i);
		scanf("%d%d%d",&u,&v,&c);
		edges[i][1]=u;
		edges[i][2]=v;
		edges[i][3]=c;
	}
}
/* int display(int num)
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
*/
int find(int x)
{
	while(parent[x]!=0)
		x=parent[x];
	return(x);
}

void uni(int k1,int k2)
{
	parent[k1]=k2;
}



void kruskals(int num, int e)
{
	int i, j, ne=1, a, b, u, v,c, k=0;
	
	while(ne <= e) 
	{   
		u=edges[ne][1];
		v=edges[ne][2];
		c=edges[ne][3];
		a=find(u);
		b=find(v);
		if (a!=b)
		{
			k++;
			tree[k][1]=u;
			tree[k][2]=v;
			tree[k][3]=c;
			uni(a,b);
			mincost+=c;
		}
		ne++;
	}
	if (k < num-1)
		printf("spanning tree does not exist\n");
	else
	{
		printf("The spanning tree edges are :\n");
		for(i=1;i<num;i++)
			printf("%d %d %d \n", tree[i][1],tree[i][2],tree[i][3]);
		printf("\n\n\n Minimun cost=%d",mincost);
	}
}
int main()
{
	int num,e;
	printf("\n\t\t\tKruskal's Algorithm");
	printf("\n\nEnter the number of nodes and edges= ");
	scanf("%d%d", &num,&e);
	input(num,e);
	//display(num);
	kruskals(num,e);
	getch();
	return 0;
}