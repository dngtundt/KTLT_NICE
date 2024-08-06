#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double S_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double)i / (i * pow(i + 1, i));
    }
    return sum;
}

int main() {
    int n = 5;
    printf("S(%d) = %lf\n", n, S_iterative(n));
    return 0;
}
