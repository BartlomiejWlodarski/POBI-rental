cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/model/Client.cpp include/model/Client.h src/model/Book.cpp include/model/Book.h src/model/Rent.cpp include/model/Rent.h src/managers/ItemManager.cpp include/managers/ItemManager.h src/model/Film.cpp include/model/Film.h src/managers/ClientManager.cpp include/managers/ClientManager.h src/managers/RentManager.cpp include/managers/RentManager.h src/model/Address.cpp include/model/Address.h src/model/Item.cpp include/model/Item.h src/model/Regular.cpp include/model/Regular.h src/model/Premium.cpp include/model/Premium.h src/Repository.cpp include/Repository.h include/typedef.h src/model/ClientType.cpp include/model/ClientType.h src/exceptions/ClientException.cpp include/exceptions/ClientException.h src/exceptions/RentException.cpp include/exceptions/RentException.h src/exceptions/ItemException.cpp include/exceptions/ItemException.h)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing() # dodane wcześniej w punkcie 2

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES test/master.cpp src/model/Client.cpp include/model/Client.h src/model/Book.cpp include/model/Book.h src/model/Rent.cpp include/model/Rent.h src/managers/ItemManager.cpp include/managers/ItemManager.h src/model/Film.cpp include/model/Film.h src/managers/ClientManager.cpp include/managers/ClientManager.h src/managers/RentManager.cpp include/managers/RentManager.h src/model/Address.cpp include/model/Address.h src/model/Item.cpp include/model/Item.h src/model/Regular.cpp include/model/Regular.h src/model/Premium.cpp include/model/Premium.h src/Repository.cpp include/Repository.h include/typedef.h test/AddressTest.cpp src/model/ClientType.cpp include/model/ClientType.h test/ClientTest.cpp test/ItemTest.cpp src/exceptions/ClientException.cpp include/exceptions/ClientException.h src/exceptions/RentException.cpp include/exceptions/RentException.h src/exceptions/ItemException.cpp include/exceptions/ItemException.h test/RentTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})