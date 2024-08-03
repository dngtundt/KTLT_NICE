#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int S3_iterative(int n) {
    int sum = 0;
    int partial_sum = 0;
    for (int i = 1; i <= n; i++) {
        partial_sum += i;
        sum += partial_sum;
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S3(n) = %d\n", S3_iterative(n));
    return 0;
}
