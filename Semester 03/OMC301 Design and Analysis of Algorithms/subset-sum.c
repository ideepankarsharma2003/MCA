#include <stdio.h>
int n,w[20],x[20],m;
void sum_of_subsets(int,int,int);
int main()
{
    int i,r=0;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("\n\nEnter the set members in the non-decreasing order :");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        r=r+w[i];
    }
    printf("Enter the target sum :");
    scanf("%d",&m);
    sum_of_subsets(0,1,r);
    return 0;
}
void sum_of_subsets(int s, int k, int r)
{
   int i;
   x[k]=1;
   if(s+w[k]==m)
   {
       printf("\n\nThe elements are :");
       for(i=1;i<=k;i++)
         if(x[k]==1)
          printf("\t%d",w[i]);
        /*for(i=1;i<=n;i++)
          x[i]=0;*/
   }
   else
        if(s+w[k]+w[k+1]<=m)
            sum_of_subsets(s+w[k],k+1,r-w[k]);
    if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
    {
        x[k]=0;
        sum_of_subsets(s,k+1,r-w[k]);
    }
}