#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char maThuoc[6];
    char tenThuoc[21];
    char nhaSanXuat[21];
    char dangThuoc[11];
    float donGia;
    char congDung[51];
} Thuoc;

void nhapThuoc(Thuoc* t) {
    printf("Nhap ma thuoc (5 ky tu): ");
    scanf("%5s", t->maThuoc);
    printf("Nhap ten thuoc (20 ky tu): ");
    scanf(" %20[^\n]", t->tenThuoc);
    printf("Nhap nha san xuat (20 ky tu): ");
    scanf(" %20[^\n]", t->nhaSanXuat);
    printf("Nhap dang thuoc (10 ky tu): ");
    scanf(" %10s", t->dangThuoc);
    printf("Nhap don gia: ");
    scanf("%f", &t->donGia);
    printf("Nhap cong dung (50 ky tu): ");
    scanf(" %50[^\n]", t->congDung);
}

void xuatThuoc(Thuoc t) {
    printf("Ma thuoc: %s\n", t.maThuoc);
    printf("Ten thuoc: %s\n", t.tenThuoc);
    printf("Nha san xuat: %s\n", t.nhaSanXuat);
    printf("Dang thuoc: %s\n", t.dangThuoc);
    printf("Don gia: %.2f\n", t.donGia);
    printf("Cong dung: %s\n", t.congDung);
}

void hoanDoi(Thuoc* a, Thuoc* b) {
    Thuoc temp = *a;
    *a = *b;
    *b = temp;
}

void sapXepTheoMaThuoc(Thuoc dsThuoc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(dsThuoc[j].maThuoc, dsThuoc[j + 1].maThuoc) > 0) {
                hoanDoi(&dsThuoc[j], &dsThuoc[j + 1]);
            }
        }
    }
}

int binarySearch(Thuoc dsThuoc[], int n, char* maThuoc) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (strncmp(dsThuoc[mid].maThuoc, maThuoc, 3) == 0) {
            return mid;
        }
        else if (strncmp(dsThuoc[mid].maThuoc, maThuoc, 3) > 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n = 0;
    Thuoc dsThuoc[MAX];
    int luaChon;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Nhap danh sach thuoc\n");
        printf("2. Xuat danh sach thuoc\n");
        printf("3. Sap xep danh sach thuoc theo ma thuoc\n");
        printf("4. Tim thuoc co ma bat dau bang 'T01'\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Nhap so luong thuoc: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap thong tin thuoc thu %d:\n", i + 1);
                nhapThuoc(&dsThuoc[i]);
            }
            break;
        case 2:
            printf("\nDanh sach thuoc:\n");
            for (int i = 0; i < n; i++) {
                printf("Thong tin thuoc thu %d:\n", i + 1);
                xuatThuoc(dsThuoc[i]);
            }
            break;
        case 3:
            sapXepTheoMaThuoc(dsThuoc, n);
            printf("\nDanh sach thuoc sau khi sap xep theo ma thuoc:\n");
            for (int i = 0; i < n; i++) {
                printf("Thong tin thuoc thu %d:\n", i + 1);
                xuatThuoc(dsThuoc[i]);
            }
            break;
        case 4: {
            char maCanTim[4] = "T01";
            int index = binarySearch(dsThuoc, n, maCanTim);
            if (index != -1) {
                printf("\nThong tin thuoc co ma bat dau bang \"%s\":\n", maCanTim);
                xuatThuoc(dsThuoc[index]);
            }
            else {
                printf("\nKhong tim thay thuoc co ma bat dau bang \"%s\"\n", maCanTim);
            }
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le! Vui long chon lai.\n");
            break;
        }
    } while (luaChon != 0);

    return 0;
}
