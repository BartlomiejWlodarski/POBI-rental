//
// Created by student on 06.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Premium.h"
#include "exceptions/ClientException.h"


BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        AddressPtr a1 = std::make_shared<Address>("Lodz", "Piotrkowska", 123);
        ClientTypePtr ct1 = std::make_shared<Premium>(5, 50);
        Client c1("Jan", "Kowalski", "1234567890", a1, ct1);
        BOOST_TEST(c1.getFirstName() == "Jan");
        BOOST_TEST(c1.getLastName() == "Kowalski");
        BOOST_TEST(c1.getPersonalId() == "1234567890");
        BOOST_TEST(c1.getAddress() == a1);
        BOOST_TEST(c1.getClientType() == ct1);

        AddressPtr an;
        ClientTypePtr ctn;
        BOOST_CHECK_THROW(Client c("", "", "", an, ctn), ClientException);

        BOOST_CHECK_THROW(Address a("", "", -3), ClientException);
    }

    BOOST_AUTO_TEST_CASE(SetterTest) {
        AddressPtr a1 = std::make_shared<Address>("Lodz", "Piotrkowska", 123);
        ClientTypePtr ct1 = std::make_shared<Premium>(5, 50);
        Client c1("Jan", "Kowalski", "1234567890", a1, ct1);

        AddressPtr a2 = std::make_shared<Address>("Warszawa", "Piotrkowska", 321);
        ClientTypePtr ct2 = std::make_shared<Premium>(7, 70);

        c1.setFirstName("Jakub");
        c1.setLastName("Nowak");
        c1.setAddress(a2);
        c1.setClientType(ct2);

        BOOST_TEST(c1.getFirstName() == "Jakub");
        BOOST_TEST(c1.getLastName() == "Nowak");
        BOOST_TEST(c1.getPersonalId() == "1234567890");
        BOOST_TEST(c1.getAddress() == a2);
        BOOST_TEST(c1.getClientType() == ct2);

        BOOST_CHECK_THROW(c1.setFirstName(""), ClientException);
        BOOST_CHECK_THROW(c1.setLastName(""), ClientException);
        BOOST_CHECK_THROW(c1.setAddress(nullptr), ClientException);
        BOOST_CHECK_THROW(c1.setClientType(nullptr), ClientException);
    }

BOOST_AUTO_TEST_SUITE_END()