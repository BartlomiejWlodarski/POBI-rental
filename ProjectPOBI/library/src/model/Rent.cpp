//
// Created by student on 31.05.2022.
//

#include "model/Rent.h"
#include "typedef.h"
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

namespace uid = boost::uuids;
namespace pt = boost::posix_time;

Rent::Rent(const ClientPtr &client, const ItemPtr &item, const boost::posix_time::ptime &beginTime)
    : id(boost::uuids::random_generator()()), beginTime(beginTime), item(item), client(client)
{
    if (Rent::beginTime == pt::not_a_date_time)
        Rent::beginTime = pt::second_clock::local_time();
    else
        Rent::beginTime = beginTime;
    endTime = pt::not_a_date_time;
}

Rent::Rent(const ClientPtr &client, const ItemPtr &item) : id(boost::uuids::random_generator()()), item(item), client(client)
{
    beginTime = pt::second_clock::local_time();
    endTime = pt::not_a_date_time;
}

const uid::uuid &Rent::getId() const {
    return id;
}

const boost::posix_time::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const boost::posix_time::ptime &Rent::getEndTime() const {
    return endTime;
}

const ItemPtr &Rent::getItem() const {
    return item;
}

const ClientPtr &Rent::getClient() const {
    return client;
}

std::string Rent::getRentInfo() {
    std::stringstream ss;
    ss << "Rent ID: " << uid::to_string(id) << ", begin time: " << getBeginTime() << "\n\t" << "Client: "
    << client->getClientInfo() << "\n\t" << "Item: " << item->getItemInfo();
    return ss.str();
}

void Rent::endRent(boost::posix_time::ptime endRentTime = pt::not_a_date_time) {
    if (endTime != pt::not_a_date_time)
        return;
    if (endRentTime == pt::not_a_date_time)
        endTime = pt::second_clock::local_time();
    else if (endRentTime <= beginTime)
        endTime = beginTime;
    else
        endTime = endRentTime;

    //TODO:rentCost = getRentDays() * getClient()->applyDiscount(getVehicle()->getBasePrice());
    //item->setArchive(true);
}

unsigned int Rent::getRentDays() {
    if (beginTime+pt::minutes(1) >= endTime)
        return 0;
    else {
        pt::ptime roundedBeginTime = pt::ptime(beginTime.date(), pt::hours(beginTime.time_of_day().hours()));
        return ((endTime - roundedBeginTime).hours() / 24)+1;
    }
}
