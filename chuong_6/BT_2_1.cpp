#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int productOfEvens(int a[], int n) {
    if (n == 0) {
        return 1;
    }

    if (a[n - 1] % 2 == 0) {
        return a[n - 1] * productOfEvens(a, n - 1);
    }
    else {
        return productOfEvens(a, n - 1);
    }
}

int main() {
    int a[] = { 2, 3, 4, 5, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    int product = productOfEvens(a, n);

    if (product == 1) {
        printf("Không có số chẵn trong mảng.\n");
    }
    else {
        printf("Tích các số chẵn trong mảng là: %d\n", product);
    }

    return 0;
}
