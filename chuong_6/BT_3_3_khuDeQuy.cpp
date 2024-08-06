#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printOddFibonacciInRange_iterative(int m, int n) {
    int current = 1, next = 1;
    while (current <= n) {
        if (current >= m && current % 2 != 0) {
            printf("%d ", current);
        }
        int temp = current + next;
        current = next;
        next = temp;
    }
}

int main() {
    int m = 10, n = 30;
    printf("Các số Fibonacci lẻ trong đoạn [%d, %d]: ", m, n);
    printOddFibonacciInRange_iterative(m, n);
    printf("\n");
    return 0;
}
