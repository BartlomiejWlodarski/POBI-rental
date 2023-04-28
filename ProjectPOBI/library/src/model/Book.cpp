//
// Created by student on 31.05.2022.
//

#include "model/Book.h"
#include "exceptions/ItemException.h"

Book::Book(const std::string &title, int releaseYear, const std::string &author, int pageCount) : Item(title, releaseYear),
author(author), pageCount(pageCount) {
    if (author.empty()) throw ItemException("Item instantiation error: Author must not be an empty string.");
    if (pageCount <= 0) throw ItemException("Item instantiation error: Page Count must be greater than 0.");
}

Book::~Book() {}

const std::string &Book::getAuthor() const {
    return author;
}

int Book::getPageCount() const {
    return pageCount;
}

std::string Book::getItemInfo() const {
    return Item::getItemInfo() + ", author: " + author + ", page count: " + std::to_string(pageCount);
}