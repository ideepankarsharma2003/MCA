#include <stdio.h>

int main() {
    FILE *file;

    // Open file in write mode (w)
    file = fopen("example.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(file, "Hello, World!\n");
    fclose(file);

    // Open file in read mode (r)
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);

    // Open file in append mode (a)
    file = fopen("example.txt", "a");
    printf("fp: [%p]", file);
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(file, "Appending this line.\n");
    fclose(file);

    return 0;
}
