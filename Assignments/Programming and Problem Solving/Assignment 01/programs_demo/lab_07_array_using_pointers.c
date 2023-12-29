/**
 * @file lab_07_array_using_pointers.c
 * Develop a C program to read and print numbers in an array using pointers.
 */
#include <stdio.h>
int main(){
    int arr [5];
    int *input_ptr=arr, *output_ptr=arr;

    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("Enter arr[%d]: ", i);
        scanf("%d", input_ptr);
        input_ptr++;
    }
    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("%d: ", *output_ptr);
        output_ptr++;
    
    }

    return 0;
    

}