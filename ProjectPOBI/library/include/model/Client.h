//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENT_H
#define INTRODUCTIONPROJECT_CLIENT_H

#include "Address.h"
#include "typedef.h"
#include "ClientType.h"

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalId;
    AddressPtr address;
    ClientTypePtr clientType;
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           const AddressPtr &address, ClientTypePtr &clientType);

    ~Client();

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;
    const AddressPtr &getAddress() const;
    const ClientTypePtr &getClientType() const;

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setAddress(const AddressPtr &address);
    void setClientType(const ClientTypePtr &clientType);

    std::string getClientInfo() const;
    //TODO: penalty
    int maxLength() const;
};


#endif //INTRODUCTIONPROJECT_CLIENT_H
