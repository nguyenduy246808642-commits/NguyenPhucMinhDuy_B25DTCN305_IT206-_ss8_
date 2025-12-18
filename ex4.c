#include <stdio.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float gpa;
} Student;

int readFromFile(const char *filename, Student students[]) {
    FILE *file = fopen(filename, "r");
    int count = 0;

    if (file == NULL) {
        return 0;
    }

    while (fscanf(file, "%d %s %d %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  &students[count].gpa) == 4) {
        count++;
        if (count >= MAX_STUDENTS) break;
    }

    fclose(file);
    return count;
}

int main() {
    Student students[MAX_STUDENTS];
    int n = readFromFile("students.txt", students);

    if (n > 0) {
        printf("Danh sách ð?c t? file:\n");
        for (int i = 0; i < n; i++) {
            printf("%d %s %d %.1f\n",
                   students[i].id,
                   students[i].name,
                   students[i].age,
                   students[i].gpa);
        }
    }

    return 0;
}

