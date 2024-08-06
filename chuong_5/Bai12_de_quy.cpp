#include <stdio.h>

// Khai báo trước các hàm đệ quy
long long Tinhxdequy(int n);
long long Tinhydequy(int n);

// Hàm đệ quy để tính số hạng thứ n của dãy x
long long Tinhxdequy(int n) {
	if (n == 0) {
		return 1;
	}
	return Tinhxdequy(n - 1) + Tinhydequy(n - 1);
}

// Hàm đệ quy để tính số hạng thứ n của dãy y
long long Tinhydequy(int n) {
	if (n == 0) {
		return 0;
	}
	return 3 * Tinhxdequy(n - 1) + 2 * Tinhydequy(n - 1);
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	long long x = Tinhxdequy(n);
	long long y = Tinhydequy(n);

	printf("So hang thu %d cua day x là: %lld\n", n, x);
	printf("So hang thu %d cua day y là: %lld\n", n, y);

	return 0;
}
