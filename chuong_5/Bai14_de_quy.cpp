#include <stdio.h>

// Khai báo trước hàm đệ quy
long long TinhUdequy(int n);

// Hàm đệ quy để tính giá trị của U(n)
long long TinhUdequy(int n) {
	if (n < 6) {
		return n;
	}
	return TinhUdequy(n - 5) + TinhUdequy(n - 4) + TinhUdequy(n - 3) + TinhUdequy(n - 2) + TinhUdequy(n - 1);
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	long long result = TinhUdequy(n);

	printf("Gia tri cua U(%d) la: %lld\n", n, result);

	return 0;
}
