/**
 * @file lab_04_consecutiveA.c
 * Demonstrate a C program that reads a string. Check whether there are three
consecutive ‘a’. If there are three consecutive ‘a’, then print YES else print
NO.
Input: Maharaja
Output: NO
Input: Bazaar
Output: YES
 */

#include<stdio.h>
#include<strings.h>

void consecutive_A_in_String(char* str){
    int i=0, count=0;

    while(str[i]!='\0'){
        // printf("%c-", str[i]);

        if (str[i]=='a') count+=1;
        else count=0;
        if (count>=3) {printf("YES"); return;}
        i++;
    }
    printf("NO");
}

int main(){
    char str[100];
    printf("Enter the string: ");
    gets(str);
    

    consecutive_A_in_String(str);
    return 0;
}