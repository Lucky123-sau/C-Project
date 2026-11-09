
#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    int issued;
};

struct Book books[100];
int count = 0;


void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == books[count].id) {
            printf("Book ID already exists!\n");
            return;
        }
    }

    printf("Enter Book Title: ");
    scanf(" %49[^\n]", books[count].title);

    books[count].issued = 0;
    count++;

    printf("Book added successfully!\n");
}


void removeBook() {
    int id, found = -1;

    printf("Enter Book ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Book not found!\n");
        return;
    }

    if (books[found].issued) {
        printf("Return the book before removing it!\n");
        return;
    }

    for (int i = found; i < count - 1; i++) {
        books[i] = books[i + 1];
    }

    count--;
    printf("Book removed successfully!\n");
}


void issueBook() {
    int id;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued) {
                printf("Book is already issued!\n");
            } else {
                books[i].issued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}


void returnBook() {
    int id;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued) {
                books[i].issued = 0;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued!\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}


void displayBooks() {
    printf("\n--- Book List ---\n");

    if (count == 0) {
        printf("No books available!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Book ID: %d\n", books[i].id);
        printf("Book Title: %s\n", books[i].title);
        printf("Status: %s\n",
               books[i].issued ? "Issued" : "Available");
        printf("------------------\n");
    }
}


int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT =====\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Books\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                displayBooks();
                break;
            case 0:
                printf("Program closed!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
