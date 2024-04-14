
//LIBRARY MANAGEMENT SYSTEM APPLICATION
/*This application is used for library management service for books */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "Addbooks.c"
#include "searchbooks.c"
#include "Borrowbooks.c"



int main() {
    struct Library library = { .book_count = 0 };
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book to Library Inventory\n");
        printf("2. Search for Books by Title or Author\n");
        printf("3. Borrow a Book\n");
        printf("4. Display Borrowed Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        while (getchar() != '\n'); // Clear input buffer
                switch (choice) {
            case 1:
                add_books_to_library(&library);
                break;
            case 2:
                search_book_by_title_or_author(&library);
                break;
            case 3:
                borrow_book(&library);
                break;
            case 4:
                // Display borrowed books
                printf("Borrowed Books:\n");
                for (int i = 0; i < library.book_count; i++) {
                    if (library.books[i].is_borrowed) {
                        printf("Title: %s, Author: %s, Due Date: %d-%02d-%02d\n",
                            library.books[i].title,
                            library.books[i].author,
                            library.books[i].due_year,
                            library.books[i].due_month,
                            library.books[i].due_day);
                    }
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

