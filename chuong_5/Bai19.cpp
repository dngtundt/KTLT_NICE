#include <stdio.h>

// Hàm đệ quy để tính giá trị của An
long long TinhA(int n) {
	// Trường hợp cơ sở
	if (n == 1) {
		return 1;
	}
	else if (n % 2 == 0) {  // Nếu n là số chẵn
		int k = n / 2;
		return k + TinhA(k) + 2;
	}
	else {  // Nếu n là số lẻ
		int k = (n - 1) / 2;
		return k * k + TinhA(k) * TinhA(k + 1) + 1;
	}
}

int main() {
	int n;

	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	long long result = TinhA(n);

	printf("Gia tri cua A(%d) la: %lld\n", n, result);

	return 0;
}
