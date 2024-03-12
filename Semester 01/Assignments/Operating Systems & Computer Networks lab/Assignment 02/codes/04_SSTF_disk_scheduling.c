#include <stdio.h>
#include <stdlib.h>

void SSTF(int cylinder[], int num_cyli, int head_pos) {
    int i, k, movement = 0, cur_pos, index[20], minimum, temp[20], j = 0, min_index, distance;

    cur_pos = head_pos;

    for (k = 0; k < num_cyli; k++) {
        for (i = 0; i < num_cyli; i++) {
            index[i] = abs(cur_pos - cylinder[i]);
        }

        minimum = index[0];
        min_index = 0;

        for (i = 1; i < num_cyli; i++) {
            if (minimum > index[i]) {
                minimum = index[i];
                min_index = i;
            }
        }

        temp[j] = cylinder[min_index];
        j++;

        cur_pos = cylinder[min_index];

        cylinder[min_index] = 9999;
    }

    printf("\nHead Movements\n");
    printf("\nFrom\tTo\tMovement\n");

    movement += abs(head_pos - temp[0]);
    printf("%d\t%d\t%d\n", head_pos, temp[0], movement);

    for (i = 1; i < num_cyli; i++) {
        distance = abs(temp[i] - temp[i - 1]);
        movement += distance;
        printf("%d\t%d\t%d\n", temp[i - 1], temp[i], distance);
    }

    printf("\nTotal number of head movements = %d\n", movement);
}

int main() {
    int cylinder[20]; // request array
    int num_cyli, head_pos;

    printf("Enter the initial head position: ");
    scanf("%d", &head_pos);

    printf("Enter the number of requests: ");
    scanf("%d", &num_cyli);

    printf("Enter the disk queue of cylinders: ");
    for (int i = 0; i < num_cyli; i++)
        scanf("%d", &cylinder[i]);

    SSTF(cylinder, num_cyli, head_pos);

    return 0;
}
