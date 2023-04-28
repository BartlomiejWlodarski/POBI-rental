//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_RENT_H
#define INTRODUCTIONPROJECT_RENT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/date_time.hpp>
#include "typedef.h"
#include "model/Client.h"
#include "model/Item.h"

class Rent {
private:
    boost::uuids::uuid id;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime;
    ItemPtr item;
    ClientPtr client;
public:
    Rent(const ClientPtr &client, const ItemPtr &item, const boost::posix_time::ptime &beginTime);
    Rent(const ClientPtr &client, const ItemPtr &item);

    ~Rent() = default;

    const uid::uuid &getId() const;
    const boost::posix_time::ptime &getBeginTime() const;
    const boost::posix_time::ptime &getEndTime() const;
    const ItemPtr &getItem() const;
    const ClientPtr &getClient() const;

    std::string getRentInfo();
    void endRent(boost::posix_time::ptime endRentTime);
    unsigned int getRentDays();

};


#endif //INTRODUCTIONPROJECT_RENT_H
