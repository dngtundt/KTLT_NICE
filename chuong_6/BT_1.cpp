//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    int id;
//    char description[100];
//} Exercise;
//
//void showMenu(Exercise exercises[], int count);
//void exercise1();
//void exercise2();
//void handleChoice(int choice, Exercise exercises[], int count);
//
//int main() {
//    Exercise exercises[] = {
//        {1, "Bài tập 1: In ra câu chào 'Hello, World!'"},
//        {2, "Bài tập 2: Tính tổng hai số nguyên"}
//    };
//    int exerciseCount = sizeof(exercises) / sizeof(exercises[0]);
//    int choice;
//
//    while (1) {
//        showMenu(exercises, exerciseCount);
//        printf("Nhập số thứ tự bài tập bạn muốn thực hiện (0 để thoát): ");
//        if (scanf("%d", &choice) != 1) {
//            printf("Lỗi: Vui lòng nhập một số nguyên.\n");
//            continue;
//        }
//        if (choice == 0) {
//            break;
//        }
//        handleChoice(choice, exercises, exerciseCount);
//    }
//
//    return 0;
//}
//
//void showMenu(Exercise exercises[], int count) {
//    printf("\nDanh sách bài tập:\n");
//    for (int i = 0; i < count; i++) {
//        printf("%d. %s\n", exercises[i].id, exercises[i].description);
//    }
//}
//
//void handleChoice(int choice, Exercise exercises[], int count) {
//    switch (choice) {
//    case 1:
//        exercise1();
//        break;
//    case 2:
//        exercise2();
//        break;
//    default:
//        printf("Lỗi: Không có bài tập nào với số thứ tự này.\n");
//        break;
//    }
//}
//
//void exercise1() {
//    printf("Hello, World!\n");
//}
//
//// Thân hàm bài tập 2
//void exercise2() {
//    int a, b;
//    printf("Nhập hai số nguyên: ");
//    if (scanf("%d %d", &a, &b) != 2) {
//        printf("Lỗi: Vui lòng nhập hai số nguyên.\n");
//        return;
//    }
//    printf("Tổng của hai số %d và %d là: %d\n", a, b, a + b);
//}
