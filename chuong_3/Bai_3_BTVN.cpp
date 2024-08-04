#include <stdio.h>
#include <limits.h> 
#include <stdbool.h> 

#define MAX_SIZE 100

//Xuất các cột chỉ chứa số lẻ
void XuatCotSoLe(int a[][MAX_SIZE], int rows, int cols) {
    printf("Cac cot chi chua so le:\n");
    for (int j = 0; j < cols; j++) {
        bool allOdd = true;
        for (int i = 0; i < rows; i++) {
            if (a[i][j] % 2 == 0) {
                allOdd = false;
                break;
            }
        }
        if (allOdd) {
            printf("Cot %d: ", j);
            for (int i = 0; i < rows; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

//Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận.
int TimMaxTrenBien(int a[][MAX_SIZE], int rows, int cols) {
	int max = INT_MIN;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
				if (a[i][j] > max) {
					max = a[i][j];
				}
			}
		}
	}
	return max;
}

int DemSo2(int num) {
	int count = 0;
	while (num != 0) {
		if (num % 10 == 2) {
			count++;
		}
		num /= 10;
	}
	return count;
}

//Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó.
int DemPhanTuCoSo2(int a[][MAX_SIZE], int rows, int cols) {
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (DemSo2(a[i][j]) > 0) {
				count++;
			}
		}
	}
	return count;
}

//Xuất các phần tử cực tiểu của ma trận.
void XuatPhanTuCucTieu(int a[][MAX_SIZE], int rows, int cols) {
	printf("Cac phan tu cuc tieu trong ma tran:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			bool isCucTieu = true;
			if (i > 0 && a[i][j] >= a[i - 1][j]) isCucTieu = false;
			if (i < rows - 1 && a[i][j] >= a[i + 1][j]) isCucTieu = false;
			if (j > 0 && a[i][j] >= a[i][j - 1]) isCucTieu = false;
			if (j < cols - 1 && a[i][j] >= a[i][j + 1]) isCucTieu = false;
			if (isCucTieu) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}

//Sắp xếp ma trận sao cho : các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần.
void SapXepDong(int a[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols - 1; j++) {
			for (int k = j + 1; k < cols; k++) {
				if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
	}
}
//Sắp xếp ma trận sao cho : các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần.
void SapXepCot(int a[][MAX_SIZE], int rows, int cols) {
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows - 1; i++) {
			for (int k = i + 1; k < rows; k++) {
				if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
					int temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}
			}
		}
	}
}

//Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
bool KiemTraGiamDan(int a[][MAX_SIZE], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols - 1; j++) {
			if (a[i][j] < a[i][j + 1]) {
				return false;
			}
		}
	}
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows - 1; i++) {
			if (a[i][j] < a[i + 1][j]) {
				return false;
			}
		}
	}
	return true;
}

//Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void LietKeDongChan(int a[][MAX_SIZE], int rows, int cols) {
	printf("Chi so cac dong chua toan gia tri chan:\n");
	for (int i = 0; i < rows; i++) {
		bool allEven = true;
		for (int j = 0; j < cols; j++) {
			if (a[i][j] % 2 != 0) {
				allEven = false;
				break;
			}
		}
		if (allEven) {
			printf("Dong %d\n", i);
		}
	}
}

//Liệt kê các dòng chứa giá trị giảm dần
void LietKeDongGiamDan(int a[][MAX_SIZE], int rows, int cols) {
	printf("Chi so cac dong chua gia tri giam dan:\n");
	for (int i = 0; i < rows; i++) {
		bool isGiamDan = true;
		for (int j = 0; j < cols - 1; j++) {
			if (a[i][j] < a[i][j + 1]) {
				isGiamDan = false;
				break;
			}
		}
		if (isGiamDan) {
			printf("Dong %d\n", i);
		}
	}
}

//Tìm giá trị xuất hiện nhiều nhất trong ma trận
int TimGiaTriXuatHienNhieuNhat(int a[][MAX_SIZE], int rows, int cols) {
	int maxCount = 0;
	int giaTri = a[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int count = 0;
			for (int k = 0; k < rows; k++) {
				for (int l = 0; l < cols; l++) {
					if (a[i][j] == a[k][l]) {
						count++;
					}
				}
			}
			if (count > maxCount) {
				maxCount = count;
				giaTri = a[i][j];
			}
		}
	}
	return giaTri;
}

//Tìm các chữ số xuất hiện nhiều nhất trong ma trận
int TimChuSoXuatHienNhieuNhat(int a[][MAX_SIZE], int rows, int cols) {
	int count[10] = { 0 };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int num = a[i][j];
			while (num != 0) {
				count[num % 10]++;
				num /= 10;
			}
		}
	}
	int maxCount = 0;
	int chuSo = 0;
	for (int i = 0; i < 10; i++) {
		if (count[i] > maxCount) {
			maxCount = count[i];
			chuSo = i;
		}
	}
	return chuSo;
}

//Liệt kê các cột có tổng nhỏ nhất trong ma trận
void LietKeCotCoTongNhoNhat(int a[][MAX_SIZE], int rows, int cols) {
	int minSum = INT_MAX;
	int minCol = -1;
	for (int j = 0; j < cols; j++) {
		int sum = 0;
		for (int i = 0; i < rows; i++) {
			sum += a[i][j];
		}
		if (sum < minSum) {
			minSum = sum;
			minCol = j;
		}
	}
	printf("Cac cot co tong nho nhat la: ");
	for (int j = 0; j < cols; j++) {
		int sum = 0;
		for (int i = 0; i < rows; i++) {
			sum += a[i][j];
		}
		if (sum == minSum) {
			printf("%d ", j);
		}
	}
	printf("\n");
}

int main() {
	int a[MAX_SIZE][MAX_SIZE];
	int rows, cols;

	printf("Nhap so dong cua ma tran: ");
	scanf("%d", &rows);
	printf("Nhap so cot cua ma tran: ");
	scanf("%d", &cols);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	XuatCotSoLe(a, rows, cols);

	printf("Phan tu lon nhat tren bien cua ma tran la: %d\n", TimMaxTrenBien(a, rows, cols));

	printf("So phan tu co chu so 2 xuat hien trong chu so cua no: %d\n", DemPhanTuCoSo2(a, rows, cols));

	XuatPhanTuCucTieu(a, rows, cols);

	SapXepDong(a, rows, cols);
	printf("Ma tran sau khi sap xep cac dong (le tang dan, chan giam dan):\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	SapXepCot(a, rows, cols);
	printf("Ma tran sau khi sap xep cac cot (le giam dan, chan tang dan):\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("Ma tran giam dan theo cot va dong (ziczac): %s\n", KiemTraGiamDan(a, rows, cols) ? "Dung" : "Sai");

	LietKeDongChan(a, rows, cols);

	LietKeDongGiamDan(a, rows, cols);

	printf("Gia tri xuat hien nhieu nhat trong ma tran la: %d\n", TimGiaTriXuatHienNhieuNhat(a, rows, cols));

	printf("Chu so xuat hien nhieu nhat trong ma tran la: %d\n", TimChuSoXuatHienNhieuNhat(a, rows, cols));

	LietKeCotCoTongNhoNhat(a, rows, cols);
	return 0;
}