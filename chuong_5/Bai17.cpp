#include <stdio.h>

// Hàm đệ quy để tính giá trị của Xn
long long TinhX(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return TinhX(n - 1) + (n - 1) * TinhX(n - 2);
	}
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	long long result = TinhX(n);

	printf("Gia tri cua X(%d) la: %lld\n", n, result);

	return 0;
}
