#include <stdio.h>

#define MAX_SIZE 100 

typedef struct {
	int tu; 
	int mau; 
} PhanSo;

// Hàm để rút gọn phân số
void RutGon(PhanSo *ps) {
	int a = ps->tu;
	int b = ps->mau;
	int temp;

	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}

	ps->tu /= a;
	ps->mau /= a;
}

// Hàm để tìm phân số lớn nhất và nhỏ nhất
void TimMaxMin(PhanSo arr[], int size, PhanSo *max, PhanSo *min) {
	if (size == 0) {
		printf("Mang rong.\n");
		return;
	}

	*max = arr[0];
	*min = arr[0];

	for (int i = 1; i < size; i++) {
		RutGon(&arr[i]);
		RutGon(max);
		RutGon(min);

		if ((arr[i].tu * max->mau > max->tu * arr[i].mau)) {
			*max = arr[i];
		}
		if ((arr[i].tu * min->mau < min->tu * arr[i].mau)) {
			*min = arr[i];
		}
	}
}

// Hàm để xóa phần tử tại vị trí k
void XoaPhanTu(PhanSo arr[], int *size, int k) {
	if (k < 0 || k >= *size) {
		printf("Vi tri xoa khong hop le.\n");
		return;
	}
	for (int i = k; i < *size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*size)--;
}

// Hàm để thêm phần tử x tại vị trí k
void ThemPhanTu(PhanSo arr[], int *size, int k, PhanSo x) {
	if (k < 0 || k > *size || *size >= MAX_SIZE) {
		printf("Vi tri them khong hop le hoac mang da day.\n");
		return;
	}
	for (int i = *size; i > k; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	(*size)++;
}

int main() {
	PhanSo arr[MAX_SIZE];
	int size = 0;
	int choice, k;
	PhanSo x, max, min;

	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &size);
	if (size <= 0 || size > MAX_SIZE) {
		printf("Kich thuoc mang khong hop le.\n");
		return 1;
	}
	printf("Nhap cac phan tu cua mang (tu mau):\n");
	for (int i = 0; i < size; i++) {
		printf("Phan tu %d - Tu: ", i + 1);
		scanf("%d", &arr[i].tu);
		printf("Phan tu %d - Mau: ", i + 1);
		scanf("%d", &arr[i].mau);
		if (arr[i].mau == 0) {
			printf("Mau so phai khac 0. Nhap lai.\n");
			i--;
		}
	}

	do {
		printf("\n--- MENU ---\n");
		printf("1. Tim phan so lon nhat va nho nhat\n");
		printf("2. Xoa phan tu tai vi tri k\n");
		printf("3. Them phan tu x tai vi tri k\n");
		printf("4. Thoat\n");
		printf("Nhap lua chon cua ban (1-4): ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			TimMaxMin(arr, size, &max, &min);
			printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);
			printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);
			break;
		case 2:
			printf("Nhap vi tri k: ");
			scanf("%d", &k);
			XoaPhanTu(arr, &size, k);
			printf("Mang sau khi xoa:\n");
			for (int i = 0; i < size; i++) {
				printf("%d/%d ", arr[i].tu, arr[i].mau);
			}
			printf("\n");
			break;
		case 3:
			printf("Nhap vi tri k: ");
			scanf("%d", &k);
			printf("Nhap phan tu x - Tu: ");
			scanf("%d", &x.tu);
			printf("Nhap phan tu x - Mau: ");
			scanf("%d", &x.mau);
			if (x.mau == 0) {
				printf("Mau so phai khac 0.\n");
				break;
			}
			ThemPhanTu(arr, &size, k, x);
			printf("Mang sau khi them:\n");
			for (int i = 0; i < size; i++) {
				printf("%d/%d ", arr[i].tu, arr[i].mau);
			}
			printf("\n");
			break;
		case 4:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (choice != 4);

	return 0;
}
