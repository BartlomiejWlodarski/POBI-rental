//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_FILM_H
#define INTRODUCTIONPROJECT_FILM_H

#include "Item.h"

class Film : public Item {
private:
    std::string director;
    int filmDuration;
public:
    Film(const std::string &title, int releaseYear, const std::string &director, int filmDuration);
    virtual ~Film();

    const std::string &getDirector() const;
    int getFilmDuration() const;

    std::string getItemInfo() const override;
};


#endif //INTRODUCTIONPROJECT_FILM_H
