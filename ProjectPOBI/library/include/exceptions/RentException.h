//
// Created by student on 10.06.2022.
//

#ifndef PROJECTPOBI_RENTEXCEPTION_H
#define PROJECTPOBI_RENTEXCEPTION_H

#include <stdexcept>

class RentException : public std::logic_error {
public:
    explicit RentException(const std::string & what_arg) noexcept : logic_error(what_arg) {}
};


#endif //PROJECTPOBI_RENTEXCEPTION_H
