
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    int age;
    int phone[10];
};


struct Student students[MAX_STUDENTS];
int count = 0;


int findStudent(int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}


void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("\nStudent record limit reached!\n");
        return;
    }

    int id;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    if (findStudent(id) != -1) {
        printf("Student ID already exists!\n");
        return;
    }

    students[count].id = id;

    printf("Enter Student Name: ");
    scanf(" %s[^\n]", students[count].name);

    printf("Enter Student Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Student Phone: ");
    scanf("%d", &students[count].phone);

    count++;

    printf("\nStudent added successfully!\n");
}


void displayStudents() {
    if (count == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID    : %d\n", students[i].id);
        printf("Name  : %s\n", students[i].name);
        printf("Age   : %d\n", students[i].age);
        printf("Phone : %d\n", students[i].phone);
    }
}


void searchStudent() {
    int id;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    int index = findStudent(id);

    if (index == -1) {
        printf("\nStudent not found!\n");
    } else {
        printf("\nStudent Found!\n");
        printf("ID    : %d\n", students[index].id);
        printf("Name  : %s\n", students[index].name);
        printf("Age   : %d\n", students[index].age);
        printf("Phone : %d\n", students[index].phone);
    }
}


void updateStudent() {
    int id;

    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    int index = findStudent(id);

    if (index == -1) {
        printf("\nStudent not found!\n");
        return;
    }

    printf("Enter New Name: ");
    scanf(" %49[^\n]", students[index].name);

    printf("Enter New Age: ");
    scanf("%d", &students[index].age);

    printf("Enter New Phone: ");
    scanf("%d", &students[index].phone);

    printf("\nStudent record updated successfully!\n");
}


void deleteStudent() {
    int id;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    int index = findStudent(id);

    if (index == -1) {
        printf("\nStudent not found!\n");
        return;
    }

    
    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;

    printf("\nStudent deleted successfully!\n");
}


int main() {
    int choice;

    do {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");

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
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 0:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
