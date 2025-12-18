#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;

/* In danh sách sinh viên */
void printStudents(Student students[], int n) {
    printf("\nID   Name   Age   GPA\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d %-6s %-5d %.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

/* Nh?p sinh viên t? bàn phím */
void inputStudents(Student students[], int *n) {
    int count;
    printf("Nhap so sinh vien can them: ");
    scanf("%d", &count);

    for (int i = 0; i < count && *n < MAX_STUDENTS; i++) {
        printf("Nhap (id name age gpa): ");
        scanf("%d %s %d %f",
              &students[*n].id,
              students[*n].name,
              &students[*n].age,
              &students[*n].gpa);
        (*n)++;
    }
}

/* Ghi danh sách sinh viên ra file */
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
    printf("Da ghi file students.txt\n");
}

/* Ð?c danh sách sinh viên t? file */
int readFromFile(Student students[]) {
    FILE *f = fopen("students.txt", "r");
    int n = 0;

    if (f == NULL) {
        printf("Khong mo duoc file\n");
        return 0;
    }

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

/* T?m ki?m sinh viên theo ID */
void searchStudent(Student students[], int n) {
    int id;
    printf("Nhap ID can tim: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            printf("ID: %d, Name: %s, Age: %d, GPA: %.1f\n",
                   students[i].id,
                   students[i].name,
                   students[i].age,
                   students[i].gpa);
            return;
        }
    }
    printf("Khong tim thay\n");
}

/* S?p x?p sinh viên theo GPA gi?m d?n */
void sortByGPA(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                Student tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
        }
    }
}

/* Thêm sinh viên m?i */
void addStudent(Student students[], int *n) {
    Student s;
    printf("Nhap (id name age gpa): ");
    scanf("%d %s %d %f", &s.id, s.name, &s.age, &s.gpa);

    for (int i = 0; i < *n; i++) {
        if (students[i].id == s.id) {
            printf("ID bi trung\n");
            return;
        }
    }

    students[*n] = s;
    (*n)++;
}

/* Xóa sinh viên theo ID */
void deleteStudent(Student students[], int *n) {
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Da xoa sinh vien\n");
            return;
        }
    }
    printf("Khong tim thay ID\n");
}

int main() {
    Student students[MAX_STUDENTS] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0},
        {4, "Dung", 22, 6.5},
        {5, "Ha", 20, 8.5},
        {6, "Lan", 21, 8.0},
        {7, "Minh", 20, 7.8},
        {8, "Nam", 22, 6.9},
        {9, "Phuc", 19, 8.2},
        {10,"Son", 21, 7.0}
    };
    int n = 10;
    int choice;

    do {
        printf("\n===== Student Manager =====\n");
        printf("1. Nhap sinh vien\n");
        printf("2. In danh sach\n");
        printf("3. Ghi file\n");
        printf("4. Doc file\n");
        printf("5. Tim kiem\n");
        printf("6. Sap xep\n");
        printf("7. Them sinh vien\n");
        printf("8. Xoa sinh vien\n");
        printf("0. Thoat\n");
        printf("===========================\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputStudents(students, &n); break;
            case 2: printStudents(students, n); break;
            case 3: saveToFile(students, n); break;
            case 4: n = readFromFile(students); break;
            case 5: searchStudent(students, n); break;
            case 6: sortByGPA(students, n); break;
            case 7: addStudent(students, &n); break;
            case 8: deleteStudent(students, &n); break;
            case 0: printf("Thoat chuong trinh\n"); break;
            default: printf("Lua chon khong hop le\n");
        }
    } while (choice != 0);

    return 0;
}

