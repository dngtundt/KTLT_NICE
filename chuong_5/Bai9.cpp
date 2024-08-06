#include <stdio.h>
//Câu 1
double S1(int n) {
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		sum += 1.0 / (i * (i + 1) * (i + 2));
	}
	return sum;
}

double S1_DeQuy(int n) {
	if (n == 1) {
		return 1.0 / (1 * 2 * 3);
	}
	return 1.0 / (n * (n + 1) * (n + 2)) + S1_DeQuy(n - 1);
}

//Câu 2
int S2(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * i;
	}
	return sum;
}

int S2_DeQuy(int n) {
	if (n == 1) {
		return 1;
	}
	return n * n + S2_DeQuy(n - 1);
}

//Câu3
int S3(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			sum += j;
		}
	}
	return sum;
}

int sum_DeQuy(int k) {
	if (k == 1) {
		return 1;
	}
	return k + sum_DeQuy(k - 1);
}

int S3_DeQuy(int n) {
	if (n == 1) {
		return 1;
	}
	return sum_DeQuy(n) + S3_DeQuy(n - 1);
}

//Bai4
long long factorial(int k) {
	if (k == 0 || k == 1) return 1;
	long long fact = 1;
	for (int i = 2; i <= k; i++) {
		fact *= i;
	}
	return fact;
}

double S4(int n) {
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		int sign = (i % 2 == 0) ? 1 : -1;
		int numerator = (2 * i - 1) + (2 * i);
		long long denominator = factorial(2 * i);
		sum += sign * ((double)numerator / denominator);
	}
	return sum;
}

double S4_DeQuy(int n) {
	if (n == 1) {
		return -((1 + 2) / (double)factorial(2));
	}
	int sign = (n % 2 == 0) ? 1 : -1;
	int numerator = (2 * n - 1) + (2 * n);
	long long denominator = factorial(2 * n);
	return sign * ((double)numerator / denominator) + S4_DeQuy(n - 1);
}

int main() {
	int n;
	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	printf("Ket qua S1 (khu de quy): %lf\n", S1(n));
	printf("Ket qua S1 (de quy): %lf\n", S1_DeQuy(n));
	printf("Ket qua S2 (khu de quy): %d\n", S2(n));
	printf("Ket qua S2 (de quy): %d\n", S2_DeQuy(n));
	printf("Ket qua S3 (khu de quy): %d\n", S3(n));
	printf("Ket qua S3 (de quy): %d\n", S3_DeQuy(n));
	printf("Ket qua S4 (khu de quy): %lf\n", S4(n));
	printf("Ket qua S4 (de quy): %lf\n", S4_DeQuy(n));

	return 0;
}

