#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;

/*
 * Hàm tìm kiếm sinh viên theo ID
 * students: mảng sinh viên
 * n: số lượng sinh viên trong mảng
 * id: ID cần tìm
 *
 * Trả về:
 *  - Con trỏ tới Student nếu tìm thấy
 *  - NULL nếu không tìm thấy hoặc ID không hợp lệ
 */
Student* findStudentById(Student students[], int n, int id) {
    if (id < 0) return NULL;

    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return NULL;
}

int main() {
    Student students[] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0}
    };
    int n = 3;
    int searchId;

    printf("Nhap ID can tim: ");
    scanf("%d", &searchId);

    Student *result = findStudentById(students, n, searchId);

    if (result != NULL) {
        printf("\nKet qua tim kiem:\n");
        printf("ID: %d, Name: %s, Age: %d, GPA: %.1f\n",
               result->id,
               result->name,
               result->age,
               result->gpa);
    } else {
        printf("\nKhong tim thay\n");
    }

    return 0;
}
