//
// Created by student on 10.06.2022.
//

#ifndef PROJECTPOBI_CLIENTEXCEPTION_H
#define PROJECTPOBI_CLIENTEXCEPTION_H

#include <stdexcept>

class ClientException : public std::logic_error{
public:
    explicit ClientException(const std::string & what_arg) noexcept;
};


#endif //PROJECTPOBI_CLIENTEXCEPTION_H
