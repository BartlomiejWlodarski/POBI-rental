//
// Created by student on 31.05.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Address a1("Lodz", "Piotrkowska", 123);
        BOOST_TEST(a1.getNumber() == 123);
        BOOST_TEST(a1.getCity() == "Lodz");
        BOOST_TEST(a1.getStreet() == "Piotrkowska");
    }

    BOOST_AUTO_TEST_CASE(SetterTest) {
        Address a1("Lodz", "Piotrkowska", 123);

        a1.setCity("Warszawa");
        a1.setStreet("Przybyszewskiego");
        a1.setNumber(321);

        BOOST_TEST(a1.getNumber() == 321);
        BOOST_TEST(a1.getCity() == "Warszawa");
        BOOST_TEST(a1.getStreet() == "Przybyszewskiego");
    }

BOOST_AUTO_TEST_SUITE_END()