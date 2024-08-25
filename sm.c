#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10000000

struct Student {
    int id;
    char name[50];
    char course[50];
    float grade;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter student details:\n");

        printf("ID: ");
        scanf("%d", &students[studentCount].id);

        printf("Name: ");
        scanf("%s", students[studentCount].name);

        printf("Course: ");
        scanf("%s", students[studentCount].course);

        printf("Grade: ");
        scanf("%f", &students[studentCount].grade);

        studentCount++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void displayStudents() {
	int i;
    if (studentCount > 0) {
        printf("\nStudent List:\n");
        printf("ID\tName\t\tCourse\t\tGrade\n");

        for (i = 0; i < studentCount; i++) {
            printf("%d\t%s\t\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].course, students[i].grade);
        }
    } else {
        printf("No students in the system.\n");
    }
}

void searchStudent() {
	int i;
    if (studentCount > 0) {
        int searchId;
        printf("Enter student ID to search: ");
        scanf("%d", &searchId);

        int found = 0;

        for (i = 0; i < studentCount; i++) {
            if (students[i].id == searchId) {
                printf("\nStudent Found:\n");
                printf("ID\tName\t\tCourse\t\tGrade\n");
                printf("%d\t%s\t\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].course, students[i].grade);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Student with ID %d not found.\n", searchId);
        }
    } else {
        printf("No students in the system.\n");
    }
}

void deleteStudent() {
	int i,j;
    if (studentCount > 0) {
        int deleteId;
        printf("Enter student ID to delete: ");
        scanf("%d", &deleteId);

        int found = 0;

        for (i = 0; i < studentCount; i++) {
            if (students[i].id == deleteId) {
                // Remove the student by shifting the remaining elements
                for (j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }

                studentCount--;
                found = 1;
                printf("Student with ID %d deleted successfully.\n", deleteId);
                break;
            }
        }

        if (!found) {
            printf("Student with ID %d not found.\n", deleteId);
        }
    } else {
        printf("No students in the system.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nStudent Information Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
