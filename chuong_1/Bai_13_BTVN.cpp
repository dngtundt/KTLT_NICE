#include <stdio.h>

#define MAX_SIZE 100 
void TinhChiaMang(int a[], int b[], int sizeA, int sizeB) {
	// Kiểm tra kích thước của hai mảng
	if (sizeA != sizeB) {
		printf("Kich thuoc cua hai mang phai bang nhau.\n");
		return;
	}

	printf("Ket qua phep chia cac phan tu mang a cho cac phan tu mang b:\n");

	for (int i = 0; i < sizeA; i++) {
		if (b[i] == 0) {
			printf("Phan tu b[%d] = 0: Khong the chia cho 0.\n", i);
		}
		else {
			printf("a[%d] / b[%d] = %f\n", i, i, (float)a[i] / b[i]);
		}
	}
}

int main() {
	int a[MAX_SIZE], b[MAX_SIZE];
	int sizeA, sizeB;

	printf("Nhap so phan tu cua mang a: ");
	scanf("%d", &sizeA);
	if (sizeA <= 0 || sizeA > MAX_SIZE) {
		printf("Kich thuoc mang a khong hop le.\n");
		return 1;
	}
	printf("Nhap cac phan tu cua mang a:\n");
	for (int i = 0; i < sizeA; i++) {
		printf("a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	printf("Nhap so phan tu cua mang b: ");
	scanf("%d", &sizeB);
	if (sizeB <= 0 || sizeB > MAX_SIZE) {
		printf("Kich thuoc mang b khong hop le.\n");
		return 1;
	}
	printf("Nhap cac phan tu cua mang b:\n");
	for (int i = 0; i < sizeB; i++) {
		printf("b[%d]: ", i);
		scanf("%d", &b[i]);
	}

	TinhChiaMang(a, b, sizeA, sizeB);

	return 0;
}
