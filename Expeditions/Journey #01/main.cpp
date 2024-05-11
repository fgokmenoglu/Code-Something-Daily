#include "book.h"
#include "library.h"

int main() {
    Library myLibrary;

    // Add books to the library
    myLibrary.addBook(Book("Book1", "Author1", "ISBN1"));
    myLibrary.addBook(Book("Book2", "Author2", "ISBN2"));
    myLibrary.addBook(Book("Book3", "Author3", "ISBN3"));

    // Try to find and check out a book
    Book* foundBook = myLibrary.findBookByTitle("Book2");
    if (foundBook) {
        foundBook->displayInfo();
        foundBook->checkOut();
    }
    else {
        std::cout << "Book2 not found or unavailable for checkout." << std::endl;
    }

    // Try another find and return
    foundBook = myLibrary.findBookByTitle("Book1");
    if (foundBook) {
        foundBook->displayInfo();
        foundBook->returnBook();
        foundBook->displayInfo();
    }
    else {
        std::cout << "Book1 not found or unavailable." << std::endl;
    }

    return 0;
}
