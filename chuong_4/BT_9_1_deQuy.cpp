#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double S1_recursive(int n) {
    if (n == 1)
        return 1.0 / (1 * 2 * 3);
    return S1_recursive(n - 1) + 1.0 / (n * (n + 1) * (n + 2));
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S1(n) = %lf\n", S1_recursive(n));
    return 0;
}
