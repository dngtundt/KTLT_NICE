#include <stdio.h>
#include <ctype.h>  // Để sử dụng các hàm toupper và isspace
#include <string.h> // Để sử dụng hàm strlen

void XuatKyTu(char *st) {
	printf("Cac ky tu trong chuoi:\n");
	while (*st != '\0') {
		printf("%c ", *st);
		st++;
	}
	printf("\n");
}

void KyTuHoa(char *st) {
	while (*st != '\0') {
		*st = toupper((unsigned char)*st);
		st++;
	}
}

void ChuoiKyTuHoa(char *st) {
	int KyTuKeTiep = 1; // Đặt cờ để xác định khi nào cần viết hoa ký tự
	while (*st != '\0') {
		if (isspace((unsigned char)*st)) {
			KyTuKeTiep = 1; // Đặt cờ khi gặp dấu cách
		}
		else if (KyTuKeTiep && islower((unsigned char)*st)) {
			*st = toupper((unsigned char)*st);
			KyTuKeTiep = 0;
		}
		else {
			*st = tolower((unsigned char)*st);
		}
		st++;
	}
}

int main() {
	char st[100];
	int choice;

	printf("Nhap chuoi: ");
	fgets(st, sizeof(st), stdin);

	size_t len = strlen(st);
	if (len > 0 && st[len - 1] == '\n') {
		st[len - 1] = '\0';
	}

	do {
		printf("\n--------- MENU----------\n");
		printf("1. Xuat gia tri tung ky tu cua chuoi\n");
		printf("2. Chuyen toan bo chuoi ve chu hoa\n");
		printf("3. Viet hoa ky tu dau moi tu\n");
		printf("4. Thoat\n");
		printf("Nhap lua chon cua ban (1-4): ");
		scanf("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
			XuatKyTu(st);
			break;
		case 2:
			KyTuHoa(st);
			printf("Chuoi sau khi chuyen ve chu hoa: %s\n", st);
			break;
		case 3:
			ChuoiKyTuHoa(st);
			printf("Chuoi sau khi viet hoa ky tu dau moi tu: %s\n", st);
			break;
		case 4:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (choice != 4);

	return 0;
}
