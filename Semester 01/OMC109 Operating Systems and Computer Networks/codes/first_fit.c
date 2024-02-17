# include <stdio.h>

void first_fit(int m, int n, int Blocks[], int Process[]){

    int i,j;

    int allocation[n];
    for ( i = 0; i < n; i++)
    {
        /* code */
        allocation[i]= -1;
    }

    for ( i = 0; i < n; i++) // # processes
    {
        /* code */
        for (  j = 0; j<m; j++) // # blocks
        {
            /* code */
            if (Blocks[j] >=Process[i]){

                allocation[i]= j;

                Blocks[j]= Blocks[j]-Process[i];
                break;
                
            }
        }
        
    }

    printf("\nP. No.\tP. Size\tBlock No.\n");
    for (i = 0; i < n; i++)
    {
        /* code */
        printf("%d\t%d\t", i+1, Process[i]);

        if (allocation[i]!=-1)
        {
            printf("%i\n", allocation[i]+1);
        }else printf("Not Allocated\n");
        
    }
    
    
    
}



int main(){
    int m, n, Blocks[10], Process[10];

    printf("Enter # processes: "); scanf("%d", &n);
    printf("Enter # blocks: "); scanf("%d", &m);

    printf("Enter the process sizes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Process[i]);

    }

    printf("Enter the block sizes\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &Blocks[i]);

    }

    first_fit(m, n, Blocks, Process);

    return 0;
    
}