#include"main.h"

void borrow_book(struct Library *library) {
    char title[100];
    printf("Enter the title of the book to borrow: ");
    fgets(title, sizeof(title), stdin);
    // Remove newline character from title
    title[strcspn(title, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < library->book_count; i++) {
        if (strcasecmp(library->books[i].title, title) == 0) {
            found = 1;
            if (library->books[i].is_borrowed) {
                printf("This book is already borrowed.\n");
            } else {
                printf("Book borrowed successfully! The due date is %d-%02d-%02d.\n",
                    library->books[i].due_year,
                    library->books[i].due_month,
                    library->books[i].due_day);
                library->books[i].is_borrowed = 1;
            }
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}
