/**
 * @file lab_08_files.c
 * Develop a C Program that reads the contents of two files namely one.dat and
two.dat. Store 50 numbers in each file. Merge both the files and store the
numbers in a sorted form in a new file with the name third.dat.
 */


#include<stdio.h>

void create_files(){
    FILE* f1, *f2;
    f1= fopen("files/one.dat", "w");
    for (int i = 0; i < 50; i++)
    {
        fprintf(f1, "%d\n", i);
    }
    fclose(f1);

    f2= fopen("files/two.dat", "w");
    for (int i = 450; i < 500; i++)
    {
        fprintf(f2, "%d\n", i);
    }
    fclose(f2);
}




// Function to merge and sort two arrays
void Sort(int merged[]) {
    

    for (int i = 0; i < 99; i++)
    {
        for (int j = i; j < 99; j++)
        {
            // Swap if the element found is greater than next pointer
            if (merged[j] > merged[j + 1]){
                printf("i= %d, j= %d, swap [%d], [%d]\n", i, j, merged[j], merged[j+1]);
                int temp = merged[j];
                merged[j] = merged[j+1];    
                merged[j+1] = temp;
            }

        }
        
    }
    

    
}




int main(){
    create_files();


    FILE *f1, *f2, *f3;
    int arr1[50], arr2[50], merged[100];

    f1= fopen("files/one.dat", "r");
    for (int i = 0; i < 50; i++)
        fscanf(f1, "%d", &arr1[i]);
    fclose(f1);

    f2= fopen("files/two.dat", "r");
    for (int i = 0; i < 50; i++)
        fscanf(f2, "%d", &arr2[i]);
    fclose(f2);


    // for (int i = 0; i < 50; i++)
    //     printf("%d\t", arr1[i]);
    // for (int i = 0; i < 50; i++)
    //     printf("%d\t", arr2[i]);

    for (int i = 0; i < 100; i++)
    {
        if (i<50) merged[i]= arr1[i];
        else merged[i]= arr2[i-50];
        // printf("%d:-> ", merged[i]);
    }
    // printf("%d\n\n", merged[100]);


    Sort(merged);
    f3= fopen("files/third.dat", "w");
    for (int i = 0; i < 100; i++){
        // printf("%d, ", merged[i]);
        fprintf(f3, "%d\n", merged[i]);
    }
    fclose(f3);
    

    
    


    return 0;
}