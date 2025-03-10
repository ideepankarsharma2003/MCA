#include <stdio.h>

void merge(int a[], int mid, int low, int high)
{
    int i, j, k, b[20];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
            a[i] = b[i];
    }
void mergesort(int a[], int low, int high){
    int mid; 
    if (low < high) {
        mid = (low + high) /2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, mid, low, high);
    }
}
void print_array(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void read_array(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
int main(){
   int a[50], n;
   printf("Enter the size of the array :");
   scanf("%d", &n);
   printf("Enter the elements :");
   read_array(a,n);
   mergesort(a,0,n-1);
   printf("The sorted array is :\n");
   print_array(a,n);
   return(0);
}