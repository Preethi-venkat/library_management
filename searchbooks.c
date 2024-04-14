#include"main.h"

// Function to search for a book by title or author
void search_book_by_title_or_author(struct Library *library) {
    char query[100];
    printf("Enter the title or author of the book to search: ");
    fgets(query, sizeof(query), stdin);
    // Remove newline character from query
    query[strcspn(query, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < library->book_count; i++) {
        if (strcasecmp(library->books[i].title, query) == 0 || strcasecmp(library->books[i].author, query) == 0) {
            found = 1;
            printf("Title: %s, Author: %s, Due Date: %d-%02d-%02d\n",
                library->books[i].title,
                library->books[i].author,
                library->books[i].due_year,
                library->books[i].due_month,
                library->books[i].due_day);
        }
    }
    if (!found) {
        printf("No book found with the given title or author.\n");
    }
}
