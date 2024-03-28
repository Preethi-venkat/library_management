
/*LIBRARY MANAGEMENT SYSTEM
OVERALL WORK:BOOK MANAGEMENT:ADD NEW BOOKS TO LIBRARY INVENTORY,SEARCH FOR BOOKS BY AUTHOR OR TITLE FOR EASY ACCESS TRACE DUE DATES TO ENSURE TIMELY RETURN
             LIBRARY MEMBER MANAGEMENT :MANAGE LIBRARY MEMBERS INFO &ACCOUNTS,KEEP TRACK OF BORROWING HISTORY AND DUE DATES FOR EACH MEMBER
user for book information:Display a prompt asking user to enter the title and author of new book.*/



#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int due_year;   // Due year
    int due_month;  // Due month
    int due_day;    // Due day
};

struct Library {
    struct Book books[100];
    int book_count;
};

// Prototype declarations
void add_book_to_library(struct Library *library);
int search_book_by_title(struct Library *library, char title[100]);
void borrow_book(struct Library *library, char title[100]);

// Definition of add_book_to_library
void add_book_to_library(struct Library *library) {
    printf("Enter the title of the book: ");
    scanf("%s", library->books[library->book_count].title);

    printf("Enter the author of the book: ");
    scanf("%s", library->books[library->book_count].author);

    printf("Enter the due year (YYYY format): ");
    scanf("%d", &library->books[library->book_count].due_year);

    printf("Enter the due month (MM format): ");
    scanf("%d", &library->books[library->book_count].due_month);

    printf("Enter the due day (DD format): ");
    scanf("%d", &library->books[library->book_count].due_day);

    library->book_count++;
    printf("Book added to the library successfully.\n");
}

// Definition of search_book_by_title
int search_book_by_title(struct Library *library, char title[100]) {
    for (int i = 0; i < library->book_count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            return 1; // Book found
        }
    }
    return 0; // Book not found
}

// Definition of borrow_book (simplified, doesn't track borrowed status)
void borrow_book(struct Library *library, char title[100]) {
    int book_found = search_book_by_title(library, title);

    if (book_found) {
        printf("Book borrowed successfully! The due date is %d-%02d-%02d.\n",
            library->books[book_found - 1].due_year,
            library->books[book_found - 1].due_month,
            library->books[book_found - 1].due_day);
    } else {
        printf("Book not found.\n");
    }
}

int main() {
    struct Library library = { .book_count = 0 };
    int choice;

    while (1) {
        printf("\nLibrary Management System (Due Dates)\n");
        printf("1. Add a Book\n");
        printf("2. Search Book by Title\n");
        printf("3. Borrow a Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book_to_library(&library);
                break;
            case 2:
                {
                    char title[100];
                    printf("Enter the book title to search: ");
                    scanf("%s", title);
                    int search_result = search_book_by_title(&library, title);
                    if (search_result == 1) {
                        printf("Book found!\n");
                    } else {
                        printf("Book not found.\n");
                    }
                }
                break;
            case 3:
                {
                    char title[100];
                    printf("Enter the title of the book to borrow: ");
                    scanf("%s", title);
                    borrow_book(&library, title);
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
