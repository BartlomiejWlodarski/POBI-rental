//
// Created by student on 31.05.2022.
//

#include "model/Item.h"
#include "exceptions/ItemException.h"
#include <boost/uuid/uuid_io.hpp>

Item::Item(const std::string &title, int releaseYear) : itemID(boost::uuids::random_generator()()), title(title),
                                                                                 releaseYear(releaseYear) {
    if (title.empty()) throw ItemException("Item instantiation error: Title must not be an empty string.");
    if (releaseYear < 0) throw ItemException("Item instantiation error: Release Year must not be negative.");
    if (releaseYear > 2022) throw ItemException("Item instantiation error: Release Year must not be from the future.");
}
Item::~Item() {}

const uid::uuid &Item::getItemId() const {
    return itemID;
}

const std::string &Item::getTitle() const {
    return title;
}

int Item::getReleaseYear() const {
    return releaseYear;
}

std::string Item::getItemInfo() const {
    return "[" + uid::to_string(itemID) + "], title: " + title + ", release year: " + std::to_string(releaseYear);
}