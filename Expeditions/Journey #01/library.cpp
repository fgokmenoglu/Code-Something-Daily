#include "library.h"

void Library::addBook(const Book& book) {
    books.push_back(book);
}

Book* Library::findBookByTitle(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title && book.isAvailable()) {
            return &book;
        }
    }
    std::cout << "Book not found or not available." << std::endl;
    return nullptr;
}
