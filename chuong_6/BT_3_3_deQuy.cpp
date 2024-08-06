#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printOddFibonacciInRange(int m, int n, int current = 1, int next = 1) {
    if (current > n) {
        return;
    }
    if (current >= m && current % 2 != 0) {
        printf("%d ", current);
    }
    printOddFibonacciInRange(m, n, next, current + next);
}

int main() {
    int m = 10, n = 30;
    printf("Các số Fibonacci lẻ trong đoạn [%d, %d]: ", m, n);
    printOddFibonacciInRange(m, n);
    printf("\n");
    return 0;
}
