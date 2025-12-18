

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[20];
    int age;
    float gpa;
} Student;

/**
 * @brief Thêm sinh viên m?i vào danh sách
 *
 * Ki?m tra trùng ID trý?c khi thêm.
 * N?u ID ð? t?n t?i, không thêm sinh viên.
 *
 * @param students M?ng sinh viên
 * @param n        Con tr? s? lý?ng sinh viên
 * @param newStu   Sinh viên c?n thêm
 *
 * @return int
 *  - 1 n?u thêm thành công
 *  - 0 n?u ID b? trùng
 */
int addStudent(Student students[], int *n, Student newStu) {
    for (int i = 0; i < *n; i++) {
        if (students[i].id == newStu.id) {
            return 0; // Trùng ID
        }
    }

    students[*n] = newStu;
    (*n)++;
    return 1;
}

/**
 * @brief Xóa sinh viên theo ID
 *
 * Duy?t m?ng ð? t?m ID c?n xóa.
 * N?u t?m th?y, d?n m?ng ð? lo?i b? sinh viên ðó.
 *
 * @param students M?ng sinh viên
 * @param n        Con tr? s? lý?ng sinh viên
 * @param id       ID sinh viên c?n xóa
 *
 * @return int
 *  - 1 n?u xóa thành công
 *  - 0 n?u không t?m th?y ID
 */
int deleteStudentById(Student students[], int *n, int id) {
    int foundIndex = -1;

    for (int i = 0; i < *n; i++) {
        if (students[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        return 0; // Không t?n t?i
    }

    for (int i = foundIndex; i < *n - 1; i++) {
        students[i] = students[i + 1];
    }

    (*n)--;
    return 1;
}

/**
 * @brief Ghi danh sách sinh viên ra file
 */
void saveToFile(Student students[], int n) {
    FILE *f = fopen("students.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %d %.1f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].gpa);
    }
    fclose(f);
}

/**
 * @brief Ð?c d? li?u sinh viên t? file
 */
int loadFromFile(Student students[]) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) return 0;

    int n = 0;
    while (fscanf(f, "%d %s %d %f",
                  &students[n].id,
                  students[n].name,
                  &students[n].age,
                  &students[n].gpa) == 4) {
        n++;
    }

    fclose(f);
    return n;
}

int main() {
    Student students[MAX];
    int n = loadFromFile(students);

    // ===== THÊM SINH VIÊN =====
    Student newStu = {4, "Dung", 22, 6.5};
    addStudent(students, &n, newStu);

    // ===== XÓA SINH VIÊN =====
    deleteStudentById(students, &n, 2);

    // ===== C?P NH?T FILE =====
    saveToFile(students, n);

    // ===== IN K?T QU? =====
    printf("Danh sach sau khi chinh sua:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }

    return 0;
}


