#include <stdio.h>
#include<math.h>
void nqueens(int);
int place(int);
int x[20];
int main()
{
    int n;
    printf("Enter the number of queens : ");
    scanf("%d",&n);
    printf("The solutions are :");
    nqueens(n);
    return 0;
}
void nqueens(int n)
{
    int k=1,i;
	x[k]=0;
	while(k!=0)
	{
		x[k]=x[k]+1;
		while((x[k]<=n)&&(!place(k)))
		   x[k]++;
		if(x[k]<=n) 
		{
			if(k==n)
			{
			    printf("\n\n");
			    for(i=1;i<=n;i++)
			       printf("\t\t%d",x[i]);
			}
			    
			else 
			{
				k++;
				x[k]=0;
			}
		} 
		else
		   k--;
	}
}
int place(int k)
{
    int j;
    for(j=1;j<=k-1;j++)
        if ((x[j]==x[k])||(fabs(x[j]-x[k])==fabs(j-k)))
            return(0);
    return(1);
}