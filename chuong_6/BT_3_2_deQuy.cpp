#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumEvenDigits(int N) {
    if (N == 0) {
        return 0;
    }
    else {
        int digit = N % 10;
        if (digit % 2 == 0) {
            return digit + sumEvenDigits(N / 10);
        }
        else {
            return sumEvenDigits(N / 10);
        }
    }
}

int main() {
    int N = 123456;
    printf("Tổng các chữ số chẵn của %d là: %d\n", N, sumEvenDigits(N));
    return 0;
}
