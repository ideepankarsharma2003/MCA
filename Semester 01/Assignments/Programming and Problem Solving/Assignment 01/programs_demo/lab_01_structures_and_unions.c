/**
 * @file lab_01_structures_and_unions.c
 * Compare structures and unions using suitable examples.
 */

#include <stdio.h>

typedef struct 
{
    int integer; 
    char character;
    float real_value;
}lab_01_structure;

typedef  union
{
    int integer; 
    char character;
    float real_value;
}lab_01_union;

int main(){
    lab_01_structure structure = {5, 'A', 3.4f};
    lab_01_union union_type = {7};

    printf("Structure: %d\n", sizeof(structure));
    printf("Union: %d\n", sizeof(union_type));

    // union_type.character='Z';
    printf("struct->character: %c\n", structure.character);
    printf("union->character: %c\n", union_type.character);

    printf("struct->real_value: %f\n", structure.real_value);
    printf("union->real_value: %f\n", union_type.real_value);

    printf("struct->integer: %d\n", structure.integer);
    printf("union->integer: %d\n", union_type.integer);
    
}