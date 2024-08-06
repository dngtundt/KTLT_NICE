#include <stdio.h>

// Hàm đệ quy để tính giá trị của Yn
long long TinhY(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 3;
	}
	else {
		return TinhY(n - 1) + 2 * TinhY(n - 2) + 3 * TinhY(n - 3);
	}
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	long long result = TinhY(n);

	printf("Gia tri cua Y(%d) la: %lld\n", n, result);

	return 0;
}
