#include <stdio.h>

// Hàm tính số Fibonacci thứ n
long long Fibonacci(int n) {
	if (n <= 2) {
		return 1;
	}
	else {
		long long a = 1, b = 1, c;
		for (int i = 3; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

// Hàm in các số Fibonacci thuộc đoạn [m, n]
void Xuat_Fibonacci(int m, int n) {
	int i = 1;
	long long fib;
	printf("Cac so Fibonacci thuoc doan [%d, %d]:\n", m, n);
	while (1) {
		fib = Fibonacci(i);
		if (fib > n) {
			break;
		}
		if (fib >= m) {
			printf("%lld ", fib);
		}
		i++;
	}
	printf("\n");
}

int main() {
	int m, n;
	printf("Nhap gia tri m: ");
	scanf("%d", &m);
	printf("Nhap gia tri n: ");
	scanf("%d", &n);

	Xuat_Fibonacci(m, n);

	return 0;
}
