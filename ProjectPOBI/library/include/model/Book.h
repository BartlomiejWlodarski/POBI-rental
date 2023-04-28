//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_BOOK_H
#define INTRODUCTIONPROJECT_BOOK_H

#include "Item.h"

class Book : public Item {
private:
    std::string author;
    int pageCount;
public:
    Book(const std::string &title, int releaseYear, const std::string &author, int pageCount);
    virtual ~Book();

    const std::string &getAuthor() const;
    int getPageCount() const;

    std::string getItemInfo() const override;
};


#endif //INTRODUCTIONPROJECT_BOOK_H
