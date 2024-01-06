#include <stdio.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int i, n, sum = 0;
    float average;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    for(i = 0; i < n; i++) {
        printf("Enter name and marks for student %d: ", i+1);
        scanf("%s %d", students[i].name, &students[i].marks);
        sum += students[i].marks;
    }

    average = (float)sum / n;

    printf("\nAverage marks = %.2f\n", average);
    printf("\nStudents scoring above the average:\n");
    for(i = 0; i < n; i++) {
        if(students[i].marks > average) {
            printf("%s\n", students[i].name);
        }
    }
    printf("\nStudents scoring below the average:\n");
    for(i = 0; i < n; i++) {
        if(students[i].marks < average) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}
