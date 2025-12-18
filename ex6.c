#include <stdio.h>

#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;

float calculateAverageGPA(Student students[], int n) {
    if (n == 0) return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += students[i].gpa;
    }
    return sum / n;
}

int main() {
    // ===== Test case: 10 sinh viên giả lập =====
    Student students[10] = {
        {1, "A", 20, 8.0},
        {2, "B", 21, 8.5},
        {3, "C", 19, 7.5},
        {4, "D", 22, 9.0},
        {5, "E", 20, 8.0},
        {6, "F", 21, 8.5},
        {7, "G", 19, 7.0},
        {8, "H", 22, 9.0},
        {9, "I", 20, 8.0},
        {10,"J", 21, 8.0}
    };

    int n = 10;

    float avg = calculateAverageGPA(students, n);
    printf("GPA trung binh cua lop la: %.2f\n", avg);

    // ===== Test case: danh sách rỗng =====
    Student emptyList[1];
    int emptyCount = 0;

    float avgEmpty = calculateAverageGPA(emptyList, emptyCount);
    printf("GPA trung binh khi danh sach rong la: %.2f\n", avgEmpty);

    return 0;
}
