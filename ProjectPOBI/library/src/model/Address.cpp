//
// Created by student on 31.05.2022.
//

#include "model/Address.h"
#include "exceptions/ClientException.h"

Address::Address(const std::string &city, const std::string &street, int number) : city(city), street(street),
                                                                                   number(number) {
    if (city.empty()) throw ClientException("Address instantiation error: City must not be empty.");
    if (street.empty()) throw ClientException("Address instantiation error: Street must not be empty.");
    if (number < 1) throw ClientException("Address instantiation error: Number must be higher or equal to 1.");
}

const std::string &Address::getCity() const {
    return city;
}

const std::string &Address::getStreet() const {
    return street;
}

int Address::getNumber() const {
    return number;
}

void Address::setCity(const std::string &city) {
    if(city.empty())
        throw ClientException("Address error: City must not be empty.");
    Address::city = city;
}

void Address::setStreet(const std::string &street) {
    if(street.empty())
        throw ClientException("Address error: Street must not be empty.");
    Address::street = street;
}

void Address::setNumber(int number) {
    if (number < 1)
        throw ClientException("Address error: Number must be higher or equal to 1.");
    Address::number = number;
}

std::string Address::getAddressInfo() const {
    return "address: " + getStreet() + " " + std::to_string(getNumber()) + ", " + getCity();
}
