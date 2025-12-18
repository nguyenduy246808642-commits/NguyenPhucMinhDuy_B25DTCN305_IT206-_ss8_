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
 * Hàm thêm sinh viên mới vào danh sách
 * students: mảng sinh viên
 * n: con trỏ lưu số lượng sinh viên hiện tại
 * newStudent: sinh viên cần thêm
 *
 * Trả về:
 *  1  - thêm thành công
 *  0  - ID bị trùng
 * -1  - danh sách đã đầy
 */
int addStudent(Student students[], int *n, Student newStudent) {
    if (*n >= MAX_STUDENTS) return -1;

    for (int i = 0; i < *n; i++) {
        if (students[i].id == newStudent.id) {
            return 0;
        }
    }

    students[*n] = newStudent;
    (*n)++;
    return 1;
}

/*
 * Hàm xóa sinh viên theo ID
 * students: mảng sinh viên
 * n: con trỏ lưu số lượng sinh viên hiện tại
 * id: ID cần xóa
 *
 * Trả về:
 *  1 - xóa thành công
 *  0 - không tìm thấy ID
 */
int deleteStudentById(Student students[], int *n, int id) {
    int foundIndex = -1;

    for (int i = 0; i < *n; i++) {
        if (students[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) return 0;

    for (int i = foundIndex; i < *n - 1; i++) {
        students[i] = students[i + 1];
    }

    (*n)--;
    return 1;
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

int main() {
    Student students[MAX_STUDENTS] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0}
    };
    int n = 3;

    Student newStudent = {4, "Dung", 22, 6.5};
    addStudent(students, &n, newStudent);

    deleteStudentById(students, &n, 2);

    printf("Danh sach sau khi chinh sua:\n");
    printStudents(students, n);

    return 0;
}



