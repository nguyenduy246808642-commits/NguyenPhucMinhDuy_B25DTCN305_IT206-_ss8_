#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50


typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;


void saveToFile(Student students[], int n) {
    FILE *file;

   
    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("? Khong the tao file students.txt\n");
        return;
    }

   
    fprintf(file, "%-5s %-10s %-5s %-5s\n", "ID", "Name", "Age", "GPA");

   
    for (int i = 0; i < n; i++) {
        fprintf(file, "%-5d %-10s %-5d %-5.1f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].gpa);
    }

    // Ðóng file sau khi ghi xong
    fclose(file);

    printf("? Da luu danh sach sinh vien vao students.txt\n");
}

int main() {
    // D? li?u m?u t? Bài 1
    Student students[] = {
        {1, "An", 20, 8.0},
        {2, "Binh", 21, 7.5},
        {3, "Chi", 19, 9.0}
    };

    int n = 3;

    
    saveToFile(students, n);

    return 0;
}

