#include<stdio.h>
#include<string.h>

int main(){

    // strcmp(s1, s2) ---> returns 0 if s1 is equal to s2 , returns -1 [s2>s1](lexicographically), ans returns 1 [s2<s1](lexicographically)
    // printf("%i", strcmp("aac", "azc"));

    FILE *fp;
    char *str;
    fp=fopen("demo.txt","r");// demo.txt

    printf("The Null pointer is: [%p]\n", NULL);
    printf("The file pointer is: [%p]\nThe first character is: [%c]", fp, fgets(str,6,fp));
    //:First Semester MCA
    while(fgets(str,6,fp)!=NULL){
        printf("%s", str);
        puts(str);
        }
    fclose(fp);


    return 0;
}