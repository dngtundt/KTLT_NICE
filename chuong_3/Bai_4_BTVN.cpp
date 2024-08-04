#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

#include <stdio.h>
#include <stdlib.h> // Để sử dụng qsort

#define MAX_SIZE 100

// Hàm so sánh tăng dần
int asc(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

// Hàm so sánh giảm dần
int desc(const void *a, const void *b) {
	return (*(int *)b - *(int *)a);
}
//Sắp xếp đường chéo phụ tăng dần / giảm dần.
void SapXepDuongCheoPhu(int a[MAX_SIZE][MAX_SIZE], int n, int tangDan) {
	int temp[MAX_SIZE];
	for (int i = 0; i < n; i++) {
		temp[i] = a[i][n - 1 - i];
	}

	// Sắp xếp mảng tạm thời
	if (tangDan) {
		qsort(temp, n, sizeof(int), asc);
	}
	else {
		qsort(temp, n, sizeof(int), desc);
	}

	// Gán lại giá trị cho đường chéo phụ
	for (int i = 0; i < n; i++) {
		a[i][n - 1 - i] = temp[i];
	}
}
//Sắp xếp ma trận sao cho : các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần.
void SapXepDong(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			qsort(a[i], n, sizeof(int), desc);
		}
		else {
			qsort(a[i], n, sizeof(int), asc);
		}
	}
}

//Sắp xếp ma trận sao cho : các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần.
void SapXepCot(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int j = 0; j < n; j++) {
		int temp[MAX_SIZE];
		for (int i = 0; i < n; i++) {
			temp[i] = a[i][j];
		}

		if (j % 2 == 0) {
			qsort(temp, n, sizeof(int), asc);
		}
		else {
			qsort(temp, n, sizeof(int), desc);
		}

		for (int i = 0; i < n; i++) {
			a[i][j] = temp[i];
		}
	}
}

//Sắp xếp mảng sao cho các phần tử trên các đường chéo chính và các đường chéo song song với đường chéo chính tăng dần.
void SapXepDuongCheoChinhVaSongSong(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int d = -n + 1; d < n; d++) {
		int temp[MAX_SIZE];
		int k = 0;

		for (int i = 0; i < n; i++) {
			int j = i + d;
			if (j >= 0 && j < n) {
				temp[k++] = a[i][j];
			}
		}

		qsort(temp, k, sizeof(int), asc);

		k = 0;
		for (int i = 0; i < n; i++) {
			int j = i + d;
			if (j >= 0 && j < n) {
				a[i][j] = temp[k++];
			}
		}
	}
}
//In ma trận
void InMaTran(int a[MAX_SIZE][MAX_SIZE], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int a[MAX_SIZE][MAX_SIZE];
	int n;
	int choice;

	printf("Nhap cap cua ma tran vuong (n): ");
	scanf("%d", &n);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	do {
		printf("\nMenu:\n");
		printf("1. Sap xep duong cheo phu tang dan\n");
		printf("2. Sap xep duong cheo phu giam dan\n");
		printf("3. Sap xep cac dong (le tang dan, chan giam dan)\n");
		printf("4. Sap xep cac cot (le giam dan, chan tang dan)\n");
		printf("5. Sap xep cac duong cheo chinh va song song\n");
		printf("6. Di chuyen cac phan tu chan len dau va le xuong cuoi\n");
		printf("7. Kiem tra doi xung qua duong cheo chinh\n");
		printf("8. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			SapXepDuongCheoPhu(a, n, 1);
			printf("Ma tran sau khi sap xep duong cheo phu tang dan:\n");
			InMaTran(a, n);
			break;
		case 2:
			SapXepDuongCheoPhu(a, n, 0);
			printf("Ma tran sau khi sap xep duong cheo phu giam dan:\n");
			InMaTran(a, n);
			break;
		case 3:
			SapXepDong(a, n);
			printf("Ma tran sau khi sap xep cac dong (le tang dan, chan giam dan):\n");
			InMaTran(a, n);
			break;
		case 4:
			SapXepCot(a, n);
			printf("Ma tran sau khi sap xep cac cot (le giam dan, chan tang dan):\n");
			InMaTran(a, n);
			break;
		case 5:
			SapXepDuongCheoChinhVaSongSong(a, n);
			printf("Ma tran sau khi sap xep cac duong cheo chinh va song song:\n");
			InMaTran(a, n);
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 8);

	return 0;
}