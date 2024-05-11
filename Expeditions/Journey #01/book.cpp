#include "book.h"

// Constructors
Book::Book(std::string _title, std::string _author, std::string _isbn, bool _available)
    : title(_title), author(_author), isbn(_isbn), available(_available) {}

// Getters
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }
bool Book::isAvailable() const { return available; }

// Methods
void Book::displayInfo() const {
    std::cout << "Title: " << title
        << ", Author: " << author
        << ", ISBN: " << isbn
        << ", Available: " << (available ? "Yes" : "No") << std::endl;
}

bool Book::checkOut() {
    if (available) {
        available = false;
        std::cout << title << " has been checked out." << std::endl;
        return true;
    }
    else {
        std::cout << title << " is not available for checkout." << std::endl;
        return false;
    }
}

void Book::returnBook() {
    available = true;
    std::cout << title << " has been returned." << std::endl;
}
