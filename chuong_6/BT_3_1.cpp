#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double S_recursive(int n) {
    if (n == 1) {
        return 1.0 / (1 * pow(2, 1));
    }
    else {
        return (double)n / (n * pow(n + 1, n)) + S_recursive(n - 1);
    }
}

int main() {
    int n = 5;
    printf("S(%d) = %lf\n", n, S_recursive(n));
    return 0;
}
