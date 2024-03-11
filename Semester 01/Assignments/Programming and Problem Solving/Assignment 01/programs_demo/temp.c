#include <stdio.h>
int main(){
    int x=1;
    int y=0;



    for (int i = 0; i < 100; i++)
    {
        /* code */
        if (i%2==0)
        {
            continue;
        }
        if (i==9)
        {
            break;
        }

        printf("%d_", i);
        
        
    }
    
}