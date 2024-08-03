#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double S1_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S1(n) = %lf\n", S1_iterative(n));
    return 0;
}
