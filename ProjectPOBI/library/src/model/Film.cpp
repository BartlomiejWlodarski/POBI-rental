//
// Created by student on 31.05.2022.
//

#include "model/Film.h"
#include "exceptions/ItemException.h"

Film::Film(const std::string &title, int releaseYear, const std::string &director, int filmDuration) : Item(title, releaseYear),
director(director), filmDuration(filmDuration) {
    if (director.empty()) throw ItemException("Item instantiation error: Director must not be an empty string.");
    if (filmDuration <= 0) throw ItemException("Item instantiation error: Film Duration must be greater than 0.");
}

Film::~Film() {}

const std::string &Film::getDirector() const {
    return director;
}

int Film::getFilmDuration() const {
    return filmDuration;
}

std::string Film::getItemInfo() const {
    return Item::getItemInfo() + ", director: " + director + ", film duration: " + std::to_string(filmDuration);
}
