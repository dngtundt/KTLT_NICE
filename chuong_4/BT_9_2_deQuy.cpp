#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int S2_recursive(int n) {
    if (n == 1)
        return 1;
    return S2_recursive(n - 1) + n * n;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("S2(n) = %d\n", S2_recursive(n));
    return 0;
}
