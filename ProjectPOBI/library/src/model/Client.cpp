//
// Created by student on 31.05.2022.
//

#include "model/Client.h"
#include "exceptions/ClientException.h"

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const AddressPtr &address, ClientTypePtr &clientType) : firstName(firstName), lastName(lastName), personalId(personalId),
                                            address(address), clientType(clientType) {
    if (personalId.empty()) throw ClientException("Client instantiation error: PersonalID must not be empty.");
    if (address == nullptr) throw ClientException("Client instantiation error: Address must not be a nullptr.");
    if (clientType == nullptr) throw ClientException("Client instantation error: ClientType must not be a nullptr.");
}

Client::~Client() {

}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getPersonalId() const {
    return personalId;
}

const AddressPtr &Client::getAddress() const {
    return address;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

void Client::setFirstName(const std::string &firstName) {
    if(firstName.empty())
        throw ClientException("Client error: Client must have a name.");
    Client::firstName = firstName;
}

void Client::setLastName(const std::string &lastName) {
    if (lastName.empty())
        throw ClientException("Client error: LastName must not be empty.");
    Client::lastName = lastName;
}

void Client::setAddress(const AddressPtr &address) {
    if(address == nullptr)
        throw ClientException("Client error: Address must not be a nullptr.");
    Client::address = address;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    if(clientType == nullptr)
        throw ClientException("Client error: ClientType must not be a nullptr.");
    Client::clientType = clientType;
}

int Client::maxLength() const {
    return clientType->maxLength();
}

std::string Client::getClientInfo() const {
    return firstName + " " + lastName + ", personalId: " + personalId + ", " + clientType->getTypeInfo() + ", " + address->getAddressInfo();
}
