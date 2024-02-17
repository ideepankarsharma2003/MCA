/**
 * @file lab_05_ArmstrongNumber.c
 * Develop a C Program to check whether the entered number is an
Armstrong number. Armstrong number is a number where the sum of the
cube of each digit is the same as the original number as given below.
0= 03 
1= 13 
153= 13 + 53 + 33
370= 33 + 73 + 03
 * 
 */

#include<stdio.h>


int checkArmstrong(int num){
    int real_num= num;

    int sum= 0;
    while(num!=0){
        int temp= num%10;
        num= num/10;
        sum+= (temp*temp*temp);
        printf("sum=%d num=%d\n", sum, num);
    }
    return sum==real_num;
}

int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if (checkArmstrong(num)) printf("%d is an armstrong number !", num);
    else printf("%d isn't an armstrong number !", num);
    return 0;
}