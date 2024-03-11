#include <stdio.h>

int main() {
    int a[10][10], r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("\nEnter matrix elements (row-wise):\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nActual Matrix matrix:\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    printf("\nThe transpose of the matrix:\n");
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}
