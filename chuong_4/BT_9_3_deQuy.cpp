#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int k) {
    if (k == 1)
        return 1;
    return k + sum(k - 1);
}

int S3_recursive(int n) {
    if (n == 1)
        return 1;
    return S3_recursive(n - 1) + sum(n);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S3(n) = %d\n", S3_recursive(n));
    return 0;
}
