/**
 * @file lab_03_price_quantity.c
 * Develop a C Program to read the price and quantity of electronic items in a shop. Calculate the cost of each item as quantity X price items as an input.
 * Develop another C function to calculate the discount according to the following rules: 
 * For a total of less than Rs.1000, the discount is 5%.
 * For a total greater than Rs.1000 but less than Rs.5000, the discount is 10%.
 * For a total greater than Rs.5000, the discount is 15%
 * 
 */

#include<stdio.h>

float calculateDiscount(float price){
    float discount= 0.0;
    if (price<=1000)discount= price*0.05;
    else if (price<5000) discount= price*0.1;
    else discount = price*0.15;
    return discount;
}

int main(){
    char option='N';
    float total_price= 0;
    do
    {
        /* code */
        float price;
        int num_items;
        printf("Enter the price per item: ");scanf("%f", &price);
        printf("Enter number of items purchased: "); scanf("%d", &num_items);
        total_price+= price*num_items;


        printf("Are there any more items purchased? (Y/N): ");
        fflush(stdin);
        scanf("%c", &option);

    } while (option=='Y' ||  option=='y');


    printf("The total discount offered on total price of %.2f is %.2f !!", total_price, calculateDiscount(total_price));
    
}