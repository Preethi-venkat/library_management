
/*LIBRARY MANAGEMENT SYSTEM
OVERALL WORK:BOOK MANAGEMENT:ADD NEW BOOKS TO LIBRARY INVENTORY,SEARCH FOR BOOKS BY AUTHOR OR TITLE FOR EASY ACCESS TRACE DUE DATES TO ENSURE TIMELY RETURN
             LIBRARY MEMBER MANAGEMENT :MANAGE LIBRARY MEMBERS INFO &ACCOUNTS,KEEP TRACK OF BORROWING HISTORY AND DUE DATES FOR EACH MEMBER
*user for book information:Display a prompt asking user to enter the title and author of new book.*/



//define a structure for book
#include <stdio.h>
struct Book {
    char title[100];
    char author[100];
};


//define a structure for library
struct Library  {
struct Book books[100]; //array to store books
int book_count; //no of book currently in library
};


//function to add a book to the library
void add_book_to_library(struct Library *library)
{

   printf("Enter the title of the book:  ");
   scanf("%s" ,library->books[library->book_count].title);

   printf("Enter the author of the book:  ");
   scanf("%s" ,library->books[library->book_count].author);

//Increment book count
   library->book_count++;
   printf("Book added to the library successfully.\n");

}

int main ()
{
    //add books to library
    struct Library library = { .book_count = 0 };

    //add book to library
    for(int i =0; i < 5; i++) {
        add_book_to_library(&library);
    }

   //print the books in library
   printf("Books in the library:\n");
   for (int i = 0; i < library.book_count; i++) {
    printf("Title: %s, Author: %s\n",library.books[i].title, library.books[i].author);
   }
   return 0;
}
