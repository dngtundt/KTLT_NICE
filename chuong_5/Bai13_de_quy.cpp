#include <stdio.h>

// Hàm đệ quy để tính phần tử thứ n của cấp số nhân
long long CapSoNhandequy(int n, long long a, long long q) {
	if (n == 1) {
		return a;
	}
	return q * CapSoNhandequy(n - 1, a, q);
}

int main() {
	int n;
	long long a, q;

	printf("Nhap gia tri hang dau a: ");
	scanf("%lld", &a);
	printf("Nhap gia tri cong boi q: ");
	scanf("%lld", &q);
	printf("nhap gia tri phan tu n: ");
	scanf("%d", &n);

	long long result = CapSoNhandequy(n, a, q);

	printf("Phan tu thu %d cua cap so nhan la: %lld\n", n, result);

	return 0;
}
