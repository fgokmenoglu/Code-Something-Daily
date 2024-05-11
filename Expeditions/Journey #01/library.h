#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    Book* findBookByTitle(const std::string& title);
};

#endif // LIBRARY_H
