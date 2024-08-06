#include <stdio.h>

// Hàm đệ quy để tính giá trị của xn
long long Tinhx(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 2;
	}
	else {
		long long tong = 0;
		for (int i = 0; i < n; i++) {
			tong += Tinhx(i);
		}
		return n * Tinhx(0) + (n - 1) * Tinhx(1) + tong;
	}
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	long long result = Tinhx(n);

	printf("Gia tri cua x(%d) la: %lld\n", n, result);

	return 0;
}
