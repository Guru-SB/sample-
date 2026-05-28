#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int math;
    int science;
    int english;
} Student;

void printStudent(const Student *s) {
    printf("ID: %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("Math: %d\n", s->math);
    printf("Science: %d\n", s->science);
    printf("English: %d\n", s->english);
    printf("Average: %.2f\n", (s->math + s->science + s->english) / 3.0);
}

void addStudent(Student students[], int index) {
    printf("Enter student %d ID: ", index + 1);
    scanf("%d", &students[index].id);
    getchar();
    printf("Enter student %d name: ", index + 1);
    fgets(students[index].name, MAX_NAME_LEN, stdin);
    students[index].name[strcspn(students[index].name, "\n")] = '\0';
    printf("Enter Math score: ");
    scanf("%d", &students[index].math);
    printf("Enter Science score: ");
    scanf("%d", &students[index].science);
    printf("Enter English score: ");
    scanf("%d", &students[index].english);
}

int findStudentById(const Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void printReport(const Student students[], int count) {
    printf("\nStudent Report:\n");
    printf("----------------\n");
    for (int i = 0; i < count; i++) {
        printStudent(&students[i]);
        printf("----------------\n");
    }
}

int main(void) {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    
    do {
        printf("\nStudent Management\n");
        printf("1. Add student\n");
        printf("2. Find student by ID\n");
        printf("3. Print report\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    addStudent(students, studentCount);
                    studentCount++;
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;
            case 2: {
                int id;
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                int index = findStudentById(students, studentCount, id);
                if (index >= 0) {
                    printStudent(&students[index]);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            }
            case 3:
                if (studentCount > 0) {
                    printReport(students, studentCount);
                } else {
                    printf("No students to display.\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}


