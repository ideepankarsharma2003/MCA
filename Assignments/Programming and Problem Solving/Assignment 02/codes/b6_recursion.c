#include <stdio.h>
#include <math.h>

int binaryToDecimal(int binary, int n) {
    if(binary == 0) {
        return 0;
    } else {
        return ((binary%10) * pow(2,n)) + binaryToDecimal(binary/10, n+1);
    }
}

int main() {
    int binary;
    printf("Enter a binary number: ");
    scanf("%d", &binary);
    printf("Decimal: %d", binaryToDecimal(binary, 0));
    return 0;
}
