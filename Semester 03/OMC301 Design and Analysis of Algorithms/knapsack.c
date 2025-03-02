#include <stdio.h>
#include <conio.h>
int n,w[20],p[20],m;
void knapsack();
int max(int, int);
int main()
{
    int i,j;
    printf("Enter the number of items :");
    scanf("%d",&n);
    printf("\nEnter the weights and profits \n");
    for(i=1;i<=n;i++)
    {
        printf("Enter the weight and profit of item %d:",i);
        scanf("%d%d",&w[i],&p[i]);
    }
    printf("\nEnter the knapsack capacity :");
    scanf("%d",&m);
    knapsack();
    return(0);
    
}
void knapsack()
{ 
    int V[20][20],i,y,x[20];
    for(y=0; y<= m; y++)
       V[0][y] = 0;    // no object included
    for(i=0; i<=n;i++)
       V[i][0] = 0;    // remaining knapsack capacity 0
    for(i=1; i<=n; i++)
      for(y=1; y<=m; y++)
      { 
          if (w[i] > y)
             V[i][y]=V[i-1][y];
          else
             V[i][y]=max(V[i-1][y],p[i]+V[i-1][y-w[i]]);
      }
      for(i=n,y=m;i>=1;i--)
        if(V[i][y]==V[i-1][y])
            x[i]=0;
        else
        {
            x[i]=1;
            y=y-w[i];
        }
    printf("\n\nThe items included in the knapsack are :");
    for(i=1;i<=n;i++)
       if(x[i]==1)
          printf("Item %d  ",i);
    printf("\nThe value of the knapsack is: %d\n",V[n][m]);
} 
int max(int x, int y)
{
    return((x>y)?x :y);
}