#include <stdio.h>

// Hàm tính giá trị của U(n) (khử đệ quy)
long long TinhUkhudequy(int n) {
	if (n < 6) {
		return n;
	}

	long long U[100] = { 0 };  // Mảng để lưu giá trị của U(n)
	for (int i = 0; i < 6; i++) {
		U[i] = i;  // Khởi tạo các giá trị của U(n) khi n < 6
	}

	for (int i = 6; i <= n; i++) {
		U[i] = U[i - 5] + U[i - 4] + U[i - 3] + U[i - 2] + U[i - 1];
	}

	return U[n];
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	long long result = TinhUkhudequy(n);

	printf("Gia tri cua U(%d) la: %lld\n", n, result);

	return 0;
}
