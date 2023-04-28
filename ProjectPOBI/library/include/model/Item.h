//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_ITEM_H
#define INTRODUCTIONPROJECT_ITEM_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace uid = boost::uuids;

class Item {
private:
    uid::uuid itemID;
    std::string title;
    int releaseYear;
public:
    Item(const std::string &title, int releaseYear);
    virtual ~Item() = 0;

    const uid::uuid &getItemId() const;
    const std::string &getTitle() const;
    int getReleaseYear() const;
    virtual std::string getItemInfo() const;
};


#endif //INTRODUCTIONPROJECT_ITEM_H
