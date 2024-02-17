#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int digits = 0, spaces = 0, alphabets = 0;

    file = fopen("b3_file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if(ch >= '0' && ch <= '9')
            digits++;
        else if(ch == ' ')
            spaces++;
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            alphabets++;
    }

    printf("Number of Alphabets: %d\n", alphabets);
    printf("Number of Digits: %d\n", digits);
    printf("Number of Spaces: %d\n", spaces);

    fclose(file);

    return 0;
}
