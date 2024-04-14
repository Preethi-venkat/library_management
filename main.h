#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Book structure
struct Book {
    char title[100]; // Array of char to store title and author of the book
    char author[100];
    int due_year;   // Due year
    int due_month;  // Due month
    int due_day;    // Due day
    int is_borrowed; // Flag to track if the book is borrowed or not
};

// Library structure
struct Library {
    struct Book books[100];
    int book_count;
};

// Function prototypes
void add_books_to_library(struct Library *library);
void search_book_by_title_or_author(struct Library *library);
void borrow_book(struct Library *library);

#endif
