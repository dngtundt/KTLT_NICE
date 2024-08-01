#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>  // De su dung int max

// Ham kiem tra so nguyen to
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Ham liet ke cac so nguyen to nho hon n
void listPrimes(int n) {
    bool found = false;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nao nho hon %d", n);
    }
    printf("\n");
}

// Ham tinh tong cac phan tu co chu so dau la chu so le
int sumOddFirstDigit(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        while (num >= 10) {
            num /= 10;
        }
        if (num % 2 != 0) {
            sum += a[i];
        }
    }
    return sum;
}

// Ham liet ke so lan xuat hien cua cac phan tu trong mang
void listOccurrences(int a[], int n) {
    int* counts = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        counts[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (counts[i] == -1) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j]) {
                    count++;
                    counts[j] = 0;
                }
            }
            counts[i] = count;
        }
    }
    for (int i = 0; i < n; i++) {
        if (counts[i] != 0) {
            printf("%d xuat hien %d lan\n", a[i], counts[i]);
        }
    }
    free(counts);
}

// Ham sap xep mang co so chan tang dan, so le giam dan
void sortEvenAscOddDesc(int a[], int n) {
    int* evens = (int*)malloc(n * sizeof(int));
    int* odds = (int*)malloc(n * sizeof(int));
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evens[evenCount++] = a[i];
        }
        else {
            odds[oddCount++] = a[i];
        }
    }

    // Sap xep mang chan tang dan
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (evens[i] > evens[j]) {
                int temp = evens[i];
                evens[i] = evens[j];
                evens[j] = temp;
            }
        }
    }

    // Sap xep mang le giam dan
    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = i + 1; j < oddCount; j++) {
            if (odds[i] < odds[j]) {
                int temp = odds[i];
                odds[i] = odds[j];
                odds[j] = temp;
            }
        }
    }

    // Ket hop lai
    for (int i = 0; i < evenCount; i++) {
        a[i] = evens[i];
    }
    for (int i = 0; i < oddCount; i++) {
        a[evenCount + i] = odds[i];
    }

    free(evens);
    free(odds);
}

// Ham tim day con giam dai nhat
void findLongestDecreasingSubsequence(int a[], int n) {
    int* length = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        length[i] = 1;
    }
    int maxLength = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j] && length[i] < length[j] + 1) {
                length[i] = length[j] + 1;
            }
        }
        if (length[i] > maxLength) {
            maxLength = length[i];
        }
    }
    printf("Do dai day con giam dai nhat la: %d\n", maxLength);
    free(length);
}

// Ham tim so nho thu 2 trong mang
void findSecondSmallest(int a[], int n) {
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < smallest) {
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] < secondSmallest && a[i] != smallest) {
            secondSmallest = a[i];
        }
    }
    if (secondSmallest == INT_MAX) {
        printf("Khong co so nho thu 2\n");
    }
    else {
        printf("So nho thu 2 la: %d\n", secondSmallest);
    }
}

// Ham kiem tra xem x co xuat hien trong so a hay khong
bool containsDigits(int num, int x) {
    char numStr[12], xStr[3];
    sprintf(numStr, "%d", num);
    sprintf(xStr, "%d", x);

    return strstr(numStr, xStr) != NULL;
}

// Ham tim cac phan tu co chua cac chu so cua x
void findNumbersContainingDigits(int a[], int n, int x) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (containsDigits(a[i], x)) {
            printf("%d ", a[i]);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co phan tu nao chua cac chu so cua %d\n", x);
    }
    printf("\n");
}

// Ham sap xep mang sao cho cac phan tu chan tang dan, cac phan tu le giu nguyen vi tri
void sortEvenAscOddUnchanged(int a[], int n) {
    int* evens = (int*)malloc(n * sizeof(int));
    int evenCount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evens[evenCount++] = a[i];
        }
    }

    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (evens[i] > evens[j]) {
                int temp = evens[i];
                evens[i] = evens[j];
                evens[j] = temp;
            }
        }
    }

    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[i] = evens[j++];
        }
    }

    free(evens);
}

// Ham sap xep mang: so le o dau mang, so chan o cuoi mang
void sortOddFirstEvenLast(int a[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[index++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[index++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
    free(temp);
}

// Ham in mang
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Ham main de hien thi menu va thuc hien cac chuc nang
int main() {
    int choice, n, x;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Liet ke cac so nguyen to nho hon n\n");
        printf("2. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("3. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
        printf("4. Sap xep mang co so chan tang dan, so le giam dan\n");
        printf("5. Tim day con giam dai nhat trong a\n");
        printf("6. Tim so nho thu 2 trong mang\n");
        printf("7. Tim cac phan tu co chua cac chu so cua x\n");
        printf("8. Sap xep mang sao cho cac phan tu chan tang dan, cac phan tu le giu nguyen vi tri\n");
        printf("9. Sap xep mang: so le o dau mang, so chan o cuoi mang\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so n: ");
            scanf("%d", &n);
            listPrimes(n);
            break;
        case 2:
            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sumOddFirstDigit(a, n));
            break;
        case 3:
            listOccurrences(a, n);
            break;
        case 4:
            sortEvenAscOddDesc(a, n);
            printArray(a, n);
            break;
        case 5:
            findLongestDecreasingSubsequence(a, n);
            break;
        case 6:
            findSecondSmallest(a, n);
            break;
        case 7:
            printf("Nhap so x co 2 chu so: ");
            scanf("%d", &x);
            findNumbersContainingDigits(a, n, x);
            break;
        case 8:
            sortEvenAscOddUnchanged(a, n);
            printArray(a, n);
            break;
        case 9:
            sortOddFirstEvenLast(a, n);
            printArray(a, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 0);

    free(a);
    return 0;
}
