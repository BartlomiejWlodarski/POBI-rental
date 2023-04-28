//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_TYPEDEF_H
#define INTRODUCTIONPROJECT_TYPEDEF_H

#include <memory>
#include <functional>

class Address;
class ClientType;
class Item;
class Client;
class Book;
class Rent;

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Item> ItemPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Book> BookPtr;
typedef std::shared_ptr<Rent> RentPtr;

#endif //INTRODUCTIONPROJECT_TYPEDEF_H
