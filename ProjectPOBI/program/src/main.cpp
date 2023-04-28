#include <iostream>
#include "model/Address.h"
#include "model/Client.h"
#include "model/Premium.h"
#include "model/Book.h"
#include "model/Rent.h"
#include "typedef.h"

using namespace std;

int main()
{
    AddressPtr a1 = std::make_shared<Address>("Lodz", "Piotrkowska", 123);
    ClientTypePtr ct1 = std::make_shared<Premium>(5, 50);
    ClientPtr c1 = make_shared<Client>("Jan", "Kowalski", "1234567890", a1, ct1);
    BookPtr b = make_shared<Book>("Harry Potter", 1997, "J.K. Rowling", 223);
    RentPtr r = make_shared<Rent>(c1, b);
    cout << r->getRentInfo() << endl;

    r->endRent(boost::posix_time::second_clock::local_time());
    cout << r->getEndTime() << endl;

    return 0;
}

