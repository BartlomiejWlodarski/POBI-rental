//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_ADDRESS_H
#define INTRODUCTIONPROJECT_ADDRESS_H


#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int number;
public:
    Address(const std::string &city, const std::string &street, int number);

    std::string getAddressInfo() const;

    const std::string &getCity() const;
    const std::string &getStreet() const;
    int getNumber() const;

    void setCity(const std::string &city);
    void setStreet(const std::string &street);
    void setNumber(int number);
};


#endif //INTRODUCTIONPROJECT_ADDRESS_H
