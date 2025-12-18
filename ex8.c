
#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

// Khai báo struct Student
typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;

/*
 * Hàm đọc danh sách sinh viên từ file
 * filename: tên file lớp học (classA.txt, classB.txt, ...)
 * students: mảng lưu sinh viên đọc được
 * Trả về: số lượng sinh viên đọc được
 */
int readStudentsFromFile(const char *filename, Student students[]) {
    FILE *file;
    int count = 0;

    // Mở file ở chế độ đọc
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong mo duoc file %s\n", filename);
        return 0;
    }

    // Đọc lần lượt từng dòng trong file
    while (fscanf(file, "%d %s %d %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  &students[count].gpa) == 4) {
        count++;
        if (count >= MAX_STUDENTS) {
            break;
        }
    }

    // Đóng file sau khi đọc xong
    fclose(file);
    return count;
}

/*
 * Hàm in danh sách sinh viên ra màn hình
 */
void printStudents(Student students[], int n, const char *className) {
    printf("Danh sach sinh vien lop %s:\n", className);
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    char filename[50];
    int n;

    // Nhập tên file lớp học cần đọc
    printf("Nhap ten file: ");
    scanf("%s", filename);

    // Đọc dữ liệu sinh viên từ file
    n = readStudentsFromFile(filename, students);

    // Nếu đọc được dữ liệu thì in ra màn hình
    if (n > 0) {
        printStudents(students, n, filename);
    }

    return 0;
}



