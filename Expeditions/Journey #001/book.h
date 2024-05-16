#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book(std::string _title = "", std::string _author = "", std::string _isbn = "", bool _available = true);

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    bool isAvailable() const;

    void displayInfo() const;
    bool checkOut();
    void returnBook();
};

#endif // BOOK_H
