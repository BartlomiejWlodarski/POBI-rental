//
// Created by student on 06.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Book.h"
#include "model/Film.h"
#include "exceptions/ItemException.h"

BOOST_AUTO_TEST_SUITE(TestSuiteItem)

    BOOST_AUTO_TEST_CASE(BookConstructorTest) {
        Book b("Harry Potter", 1997, "J.K. Rowling", 223);
        BOOST_TEST(b.getTitle() == "Harry Potter");
        BOOST_TEST(b.getReleaseYear() == 1997);
        BOOST_TEST(b.getAuthor() == "J.K. Rowling");
        BOOST_TEST(b.getPageCount() == 223);

        BOOST_CHECK_THROW(Book b2("", -100, "", -100), ItemException);
    }

    BOOST_AUTO_TEST_CASE(FilmConstructorTest) {
        Film f("Star Wars: Episode I – The Phantom Menace", 1999, "George Lucas", 136);
        BOOST_TEST(f.getTitle() == "Star Wars: Episode I – The Phantom Menace");
        BOOST_TEST(f.getReleaseYear() == 1999);
        BOOST_TEST(f.getDirector() == "George Lucas");
        BOOST_TEST(f.getFilmDuration() == 136);

        BOOST_CHECK_THROW(Film f2("", 3000, "", -100), ItemException);
    }

BOOST_AUTO_TEST_SUITE_END()