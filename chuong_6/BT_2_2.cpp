#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool containsDigit4(int num) {
    if (num == 0) {
        return false;
    }

    if (num % 10 == 4) {
        return true;
    }
    else {
        return containsDigit4(num / 10);
    }
}

void printElementsWith4(int a[], int n) {
    if (n == 0) {
        return;
    }

    if (containsDigit4(a[n - 1])) {
        printf("%d ", a[n - 1]);
    }

    printElementsWith4(a, n - 1);
}

int main() {
    int a[] = { 123, 456, 789, 404, 234 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("Các phần tử chứa chữ số 4 trong mảng: ");
    printElementsWith4(a, n);
    printf("\n");

    return 0;
}
