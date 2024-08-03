#include <stdio.h>

int main() {
	int a, b;
	int *pa, *pb;
	int tong, hieu, tich;
	float thuong;

	// Gán giá trị cho a và b
	printf("Nhap so a: ");
	scanf("%d", &a);
	printf("Nhap so b: ");
	scanf("%d", &b);

	// Gán địa chỉ của a và b cho các con trỏ pa và pb
	pa = &a;
	pb = &b;

	// Tính toán tổng, hiệu, tích, và thương
	tong = *pa + *pb;
	hieu = *pa - *pb;
	tich = (*pa) * (*pb);
	thuong = (float)(*pa) / (*pb); // Ép kiểu để tính thương chính xác hơn

	// Xuất kết quả và địa chỉ các ô nhớ
	printf("Tong cua %d và %d là: %d, tai dia chi: %p\n", *pa, *pb, tong, (void*)&tong);
	printf("Hieu cua %d và %d là: %d, tai dia chi: %p\n", *pa, *pb, hieu, (void*)&hieu);
	printf("Tich cua %d và %d là: %d, tai dia chi: %p\n", *pa, *pb, tich, (void*)&tich);
	printf("Thuong cua %d và %d là: %.2f, tai dia chi: %p\n", *pa, *pb, thuong, (void*)&thuong);

	return 0;
}
