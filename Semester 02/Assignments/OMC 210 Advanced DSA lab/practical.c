#include <stdio.h>

int binary_search(int arr[], int left, int right, int x) {
    if (left > right) {
        return -1;
    }

    // int mid = left + (right - left) / 2; // To avoid overflow
    int mid = (left+right)/ 2; // To avoid overflow

    if (arr[mid] == x) {
        return mid;
    }

    if (arr[mid] > x) return binary_search(arr, left, mid - 1, x);
    else return binary_search(arr, mid + 1, right, x);
}



int main() {
    int n=10, i, x, result;

    int arr[10];

    printf("Enter %d integers (elements of array) in ascending order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search:\n");
    scanf("%d", &x);

    result = binary_search(arr, 0, n - 1, x);

    if (result == -1)
        printf("Number not present in array.\n");
    else
        printf("Number is present at index %d.\n", result);

    return 0;
}
