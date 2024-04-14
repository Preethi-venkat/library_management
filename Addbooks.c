

#include"main.h"




// Function to add books to the library with tracked due dates
void add_books_to_library(struct Library *library) {
    // Array of book details (title, author, due year, due month, due day)
    char book_details[10][5][100] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", "2024", "4", "15"},
        {"To Kill a Mockingbird", "Harper Lee", "2024", "4", "20"},
        {"1984", "George Orwell", "2024", "4", "25"},
        {"Pride and Prejudice", "Jane Austen", "2024", "5", "1"},
        {"The Catcher in the Rye", "J.D. Salinger", "2024", "5", "6"},
        {"Animal Farm", "George Orwell", "2024", "5", "11"},
        {"The Hobbit", "J.R.R. Tolkien", "2024", "5", "16"},
        {"Brave New World", "Aldous Huxley", "2024", "5", "21"},
        {"Lord of the Flies", "William Golding", "2024", "5", "26"},
        {"The Lord of the Rings", "J.R.R. Tolkien", "2024", "5", "31"}
    };

    printf("Books added to the library successfully.\n");

    // Display the list of books
    printf("List of Books:\n");
    for (int i = 0; i < 10; i++) {
        strcpy(library->books[library->book_count].title, book_details[i][0]);
        strcpy(library->books[library->book_count].author, book_details[i][1]);
        library->books[library->book_count].due_year = atoi(book_details[i][2]);
        library->books[library->book_count].due_month = atoi(book_details[i][3]);
        library->books[library->book_count].due_day = atoi(book_details[i][4]);
        library->book_count++;
        printf("%d. Title: %s, Author: %s, Due Date: %s-%s-%s\n", i + 1, book_details[i][0], book_details[i][1], book_details[i][2], book_details[i][3], book_details[i][4]);
    }
}
