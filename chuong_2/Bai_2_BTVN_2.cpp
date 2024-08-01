#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int phanNguyen;
    float phanSo;
} HonSo;

void nhapMang(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan nguyen va phan so cua b[%d]: ", i);
        scanf("%d %f", &b[i].phanNguyen, &b[i].phanSo);
    }
}

void xuatMang(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d + %.2f ", b[i].phanNguyen, b[i].phanSo);
    }
    printf("\n");
}

int linearSearch(HonSo b[], int n, HonSo x) {
    for (int i = 0; i < n; i++) {
        if (b[i].phanNguyen == x.phanNguyen && b[i].phanSo == x.phanSo) {
            return i;
        }
    }
    return -1;
}

void sapXepChanLe(HonSo b[], int n) {
    HonSo* chan = (HonSo*)malloc(n * sizeof(HonSo));
    HonSo* le = (HonSo*)malloc(n * sizeof(HonSo));
    int chanCount = 0, leCount = 0;

    for (int i = 0; i < n; i++) {
        if (b[i].phanNguyen % 2 == 0) {
            chan[chanCount++] = b[i];
        }
        else {
            le[leCount++] = b[i];
        }
    }

    for (int i = 0; i < chanCount; i++) {
        b[i] = chan[i];
    }
    for (int i = 0; i < leCount; i++) {
        b[chanCount + i] = le[i];
    }

    free(chan);
    free(le);
}

int compareHonSo(HonSo a, HonSo b) {
    if (a.phanNguyen != b.phanNguyen) {
        return a.phanNguyen - b.phanNguyen;
    }
    return (a.phanSo > b.phanSo) - (a.phanSo < b.phanSo);
}

int binarySearch(HonSo b[], int n, HonSo x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = compareHonSo(b[mid], x);
        if (cmp == 0) {
            return mid;
        }
        else if (cmp < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

void chiaMang(HonSo b[], int n, int s1[], float s2[]) {
    for (int i = 0; i < n; i++) {
        s1[i] = b[i].phanNguyen;
        s2[i] = b[i].phanSo;
    }
}

void xoaPhanTu(HonSo b[], int* n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        b[i] = b[i + 1];
    }
    (*n)--;
}

void themPhanTu(HonSo b[], int* n, int k, HonSo x) {
    if (k < 0 || k > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *n; i > k; i--) {
        b[i] = b[i - 1];
    }
    b[k] = x;
    (*n)++;
}

void taoMangC(HonSo b[], int n, float c[]) {
    for (int i = 0; i < n; i++) {
        c[i] = b[i].phanNguyen + b[i].phanSo;
    }
}

HonSo tongMang(HonSo b[], int n) {
    HonSo tong = { 0, 0.0 };
    for (int i = 0; i < n; i++) {
        tong.phanNguyen += b[i].phanNguyen;
        tong.phanSo += b[i].phanSo;
    }
    return tong;
}

HonSo timMax(HonSo b[], int n) {
    HonSo max = b[0];
    for (int i = 1; i < n; i++) {
        if (compareHonSo(b[i], max) > 0) {
            max = b[i];
        }
    }
    return max;
}

HonSo timMin(HonSo b[], int n) {
    HonSo min = b[0];
    for (int i = 1; i < n; i++) {
        if (compareHonSo(b[i], min) < 0) {
            min = b[i];
        }
    }
    return min;
}

void xuatViTriChan(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        if (b[i].phanNguyen % 2 == 0) {
            printf("Vi tri %d: %d + %.2f\n", i, b[i].phanNguyen, b[i].phanSo);
        }
    }
}

void xuatViTriMaxMin(HonSo b[], int n) {
    HonSo max = timMax(b, n);
    HonSo min = timMin(b, n);
    for (int i = 0; i < n; i++) {
        if (compareHonSo(b[i], max) == 0) {
            printf("Vi tri phan tu lon nhat: %d\n", i);
        }
        if (compareHonSo(b[i], min) == 0) {
            printf("Vi tri phan tu nho nhat: %d\n", i);
        }
    }
}

int main() {
    int n, choice, k;
    HonSo x;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    HonSo* b = (HonSo*)malloc(n * sizeof(HonSo));
    nhapMang(b, n);

    do {
        printf("\nMenu:\n");
        printf("1. Tim hon so x trong mang b theo giai thuat Linear Search\n");
        printf("2. Sap xep b sao cho cac phan tu co phan nguyen chan len dau, phan tu co phan nguyen le o cuoi mang\n");
        printf("3. Tim hon so x theo giai thuat binary search trong mang b da duoc sap xep tang/giam\n");
        printf("4. Chia mang b thanh 2 mang s1 va s2\n");
        printf("5. Xoa phan tu thu k trong mang b\n");
        printf("6. Them hon so x vao mang b tai vi tri k\n");
        printf("7. Tao mang c chua cac phan tu la phan so duoc doi tu cac phan tu hon so cua mang b\n");
        printf("8. Tinh tong cac phan tu cua mang b\n");
        printf("9. Tim phan tu lon nhat/nho nhat cua b\n");
        printf("10. Xuat vi tri phan tu co phan nguyen chan cua b\n");
        printf("11. Xuat vi tri cua phan tu lon nhat/nho nhat cua b\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap phan nguyen va phan so cua hon so x: ");
            scanf("%d %f", &x.phanNguyen, &x.phanSo);
            {
                int index = linearSearch(b, n, x);
                if (index != -1) {
                    printf("Tim thay hon so x tai vi tri %d\n", index);
                }
                else {
                    printf("Khong tim thay hon so x\n");
                }
            }
            break;
        case 2:
            sapXepChanLe(b, n);
            xuatMang(b, n);
            break;
        case 3:
            printf("Nhap phan nguyen va phan so cua hon so x: ");
            scanf("%d %f", &x.phanNguyen, &x.phanSo);
            {
                int foundIndex = binarySearch(b, n, x);
                if (foundIndex != -1) {
                    printf("Tim thay hon so x tai vi tri %d\n", foundIndex);
                }
                else {
                    printf("Khong tim thay hon so x\n");
                }
            }
            break;
        case 4: {
            int* s1 = (int*)malloc(n * sizeof(int));
            float* s2 = (float*)malloc(n * sizeof(float));
            chiaMang(b, n, s1, s2);
            printf("Mang s1 (phan nguyen): ");
            for (int i = 0; i < n; i++) {
                printf("%d ", s1[i]);
            }
            printf("\nMang s2 (phan so): ");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", s2[i]);
            }
            printf("\n");
            free(s1);
            free(s2);
            break;
        }
        case 5:
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &k);
            xoaPhanTu(b, &n, k);
            xuatMang(b, n);
            break;
        case 6:
            printf("Nhap vi tri can them: ");
            scanf("%d", &k);
            printf("Nhap phan nguyen va phan so cua hon so x: ");
            scanf("%d %f", &x.phanNguyen, &x.phanSo);
            themPhanTu(b, &n, k, x);
            xuatMang(b, n);
            break;
        case 7: {
            float* c = (float*)malloc(n * sizeof(float));
            taoMangC(b, n, c);
            printf("Mang c (phan so doi tu hon so cua mang b): ");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", c[i]);
            }
            printf("\n");
            free(c);
            break;
        }
        case 8: {
            HonSo tong = tongMang(b, n);
            printf("Tong cac phan tu cua mang b: %d + %.2f\n", tong.phanNguyen, tong.phanSo);
            break;
        }
        case 9: {
            HonSo max = timMax(b, n);
            HonSo min = timMin(b, n);
            printf("Phan tu lon nhat: %d + %.2f\n", max.phanNguyen, max.phanSo);
            printf("Phan tu nho nhat: %d + %.2f\n", min.phanNguyen, min.phanSo);
            break;
        }
        case 10:
            xuatViTriChan(b, n);
            break;
        case 11:
            xuatViTriMaxMin(b, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 0);

    free(b);
    return 0;
}
