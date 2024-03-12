#include <stdio.h>
#include <stdlib.h>

void FCFS(int cylinder[], int num_cyli, int head_pos) {
    int movement = 0;
    int cur_cyli, distance;
    
    printf("\nHead Movements\n");
    printf("\nFrom\tTo\tMovement\n");
    
    for (int i = 0; i < num_cyli; i++) {
        cur_cyli = cylinder[i];
        distance = abs(head_pos - cur_cyli);
        movement += distance;
        printf("%d\t%d\t%d\n", head_pos, cur_cyli, distance);
        head_pos = cur_cyli;
    }
    
    printf("Total number of head movements = %d\n", movement);
}

int main() {
    int cylinder[20]; // request array
    int num_cyli, head_pos;
    
    printf("Enter the number of requests: ");
    scanf("%d", &num_cyli);
    
    printf("Enter the disk queue of cylinders: ");
    for (int i = 0; i < num_cyli; i++)
        scanf("%d", &cylinder[i]);
    
    printf("Enter the initial head position: ");
    scanf("%d", &head_pos);
    
    FCFS(cylinder, num_cyli, head_pos);
    
    return 0;
}
