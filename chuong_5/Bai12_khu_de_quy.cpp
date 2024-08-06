#include <stdio.h>

// Hàm tính số hạng thứ n của dãy x và y (khử đệ quy)
void TinhxyKhuDeQuy(int n, long long *x, long long *y) {
	*x = 1;  // x0 = 1
	*y = 0;  // y0 = 0

	long long xn = *x, yn = *y;
	for (int i = 1; i <= n; i++) {
		long long temp_x = xn;
		xn = xn + yn;
		yn = 3 * temp_x + 2 * yn;
	}
	*x = xn;
	*y = yn;
}

int main() {
	int n;
	long long x, y;

	printf("Nhap so duong n: ");
	scanf("%d", &n);

	TinhxyKhuDeQuy(n, &x, &y);

	printf("So hang thu %d cua day x là: %lld\n", n, x);
	printf("So hang thu %d cua dãy y là: %lld\n", n, y);

	return 0;
}
