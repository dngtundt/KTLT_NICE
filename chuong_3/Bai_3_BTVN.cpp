#include <stdio.h>
#include <limits.h> 
#include <stdbool.h> 

#define MAX_SIZE 100

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
	return 0;
}