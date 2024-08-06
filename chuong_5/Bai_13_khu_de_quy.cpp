#include <stdio.h>

// Hàm tính phần tử thứ n của cấp số nhân (khử đệ quy)
long long CapSoNhankhudequy(int n, long long a, long long q) {
	long long result = a;
	for (int i = 1; i < n; i++) {
		result *= q;
	}
	return result;
}

int main() {
	int n;
	long long a, q;

	printf("Nhap gia tri hang dau a: ");
	scanf("%lld", &a);
	printf("Nhap gia tri cong boi q: ");
	scanf("%lld", &q);
	printf("Nhap gia tri phan tu thu n: ");
	scanf("%d", &n);

	long long result = CapSoNhankhudequy(n, a, q);

	printf("Phan tu thu %d cua cap so nhan la: %lld\n", n, result);

	return 0;
}
