/**
 * Develop a C program that reads a person’s age and name. Print the name of a person as many times as his/her age. Use for, while, or do-while loop.
 * 
 */

#include<stdio.h>

int main(){
    int age;
    char name[30];

    printf("Enter the name of the person: ");
    gets(name);
    printf("Enter the age of the person: ");
    scanf("%d", &age);

    for (int i = 0; i < age; i++)
    {
        /* code */
        printf("%s\n", name);
    }
    return 0;
}