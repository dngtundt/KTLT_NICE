#include <stdio.h>
#include <stdbool.h> 

#define MAX_SIZE 100 

void XuatSoCucTieu(int arr[], int size) {
	bool found;
	printf("Cac so cuc tieu trong mang:\n");
	for (int i = 0; i < size; i++) {
		if (i > 0 && i < size - 1) {
			found = (arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]);
		}
		else if (i == 0) {
			found = (arr[i] < arr[i + 1]);
		}
		else if (i == size - 1) {
			found = (arr[i] < arr[i - 1]);
		}
		if (found) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

void XoaPhanTu(int arr[], int *size, int k) {
	if (k < 0 || k >= *size) {
		printf("Vi tri xoa khong hop le.\n");
		return;
	}
	for (int i = k; i < *size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*size)--;
}

void ThemPhanTu(int arr[], int *size, int k, int x) {
	if (k < 0 || k > *size || *size >= MAX_SIZE) {
		printf("Vi tri them khong hop le hoac mang da day.\n");
		return;
	}
	for (int i = *size; i > k; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	(*size)++;
}

void ChiaSoChanLe(int arr[], int size) {
	int temp[MAX_SIZE]; 
	int index = 0;

	// Sao chép số chẵn vào đầu mảng temp
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			temp[index++] = arr[i];
		}
	}

	// Sao chép số lẻ vào cuối mảng temp
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			temp[index++] = arr[i];
		}
	}

	// Sao chép mảng temp về lại mảng arr
	for (int i = 0; i < size; i++) {
		arr[i] = temp[i];
	}
}

bool KiemTraChanLeXenKe(int arr[], int size) {
	if (size < 2) return false; // Không thể có chẵn lẻ xen kẽ với ít hơn 2 phần tử

	for (int i = 1; i < size; i++) {
		if ((arr[i] % 2 == 0 && arr[i - 1] % 2 == 0) ||
			(arr[i] % 2 != 0 && arr[i - 1] % 2 != 0)) {
			return false; // Không xen kẽ
		}
	}
	return true; // Có chẵn lẻ xen kẽ
}

int main() {
	int arr[MAX_SIZE];
	int size = 0;
	int choice, k, x;

	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &size);
	if (size <= 0 || size > MAX_SIZE) {
		printf("Kich thuoc mang khong hop le.\n");
		return 1;
	}
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < size; i++) {
		printf("Phan tu %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	do {
		printf("\n--- MENU ---\n");
		printf("1. Xuat cac so cuc tieu\n");
		printf("2. Xoa phan tu tai vi tri k\n");
		printf("3. Them phan tu x tai vi tri k\n");
		printf("4. Chuyen so chan len dau mang, so le xuong cuoi mang\n");
		printf("5. Kiem tra mang co chua chan le xen ke khong\n");
		printf("6. Thoat\n");
		printf("Nhap lua chon cua ban (1-6): ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			XuatSoCucTieu(arr, size);
			break;
		case 2:
			printf("Nhap vi tri k: ");
			scanf("%d", &k);
			XoaPhanTu(arr, &size, k);
			printf("Mang sau khi xoa:\n");
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;
		case 3:
			printf("Nhap vi tri k: ");
			scanf("%d", &k);
			printf("Nhap gia tri x: ");
			scanf("%d", &x);
			ThemPhanTu(arr, &size, k, x);
			printf("Mang sau khi them:\n");
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;
		case 4:
			ChiaSoChanLe(arr, size);
			printf("Mang sau khi chuyen so chan len dau, so le xuong cuoi:\n");
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;
		case 5:
			if (KiemTraChanLeXenKe(arr, size)) {
				printf("Mang co chua chan le xen ke.\n");
			}
			else {
				printf("Mang khong chua chan le xen ke.\n");
			}
			break;
		case 6:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (choice != 6);

	return 0;
}
