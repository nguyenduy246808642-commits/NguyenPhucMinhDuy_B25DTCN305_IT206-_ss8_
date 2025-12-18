#include <stdio.h>

#define MAX_STUDENTS 5
#define NAME_LEN 50

// Khai báo struct Student
typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;

// Hàm in danh sách sinh viên dạng bảng
void printStudents(Student students[], int n) {
    printf("\n%-5s %-10s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-10s %-5d %-5.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n;

    // Nhập số lượng sinh viên (tối đa 5)
    printf("Nhap so luong sinh vien (toi da 5): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_STUDENTS) {
        printf("So luong sinh vien khong hop le.\n");
        return 0;
    }

    // Nhập thông tin sinh viên
    for (int i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d (id name age gpa):\n", i + 1);
        scanf("%d %s %d %f",
              &students[i].id,
              students[i].name,
              &students[i].age,
              &students[i].gpa);
    }

    // In danh sách sinh viên
    printStudents(students, n);

    return 0;
}
