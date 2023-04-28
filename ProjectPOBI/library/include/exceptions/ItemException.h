//
// Created by student on 10.06.2022.
//

#ifndef PROJECTPOBI_ITEMEXCEPTION_H
#define PROJECTPOBI_ITEMEXCEPTION_H

#include <stdexcept>

class ItemException : public std::logic_error {
public:
    explicit ItemException(const std::string & what_arg) noexcept;
};


#endif //PROJECTPOBI_ITEMEXCEPTION_H
