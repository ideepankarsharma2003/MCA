/**
 * @file lab_06_euclidean_distance.c
Develop a C program to compute the distance between the points (x1, y1)
and (x2, y2)
 * 
 */

#include<stdio.h>
#include<math.h>

int main(){
    double x1,y1,x2,y2; // coordinates of two points
    printf("Enter the coordinates for point A(x1, y1): \n");
    scanf("%lf %lf", &x1,&y1);
    printf("\nEnter the coordinates for point B(x2, y2): \n");
    scanf("%lf %lf", &x2,&y2);

    double eucDistance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    printf("\nThe Euclidean Distance is: %.3lf\n", eucDistance);
    return 0;
}