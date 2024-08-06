#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumEvenDigits_iterative(int N) {
    int sum = 0;
    while (N > 0) {
        int digit = N % 10;
        if (digit % 2 == 0) {
            sum += digit;
        }
        N /= 10;
    }
    return sum;
}

int main() {
    int N = 123456;
    printf("Tổng các chữ số chẵn của %d là: %d\n", N, sumEvenDigits_iterative(N));
    return 0;
}
