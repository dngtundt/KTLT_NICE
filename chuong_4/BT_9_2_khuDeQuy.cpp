#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int S2_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S2(n) = %d\n", S2_iterative(n));
    return 0;
}
