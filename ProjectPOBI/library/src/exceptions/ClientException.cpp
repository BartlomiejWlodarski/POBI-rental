//
// Created by student on 10.06.2022.
//

#include "exceptions/ClientException.h"

ClientException::ClientException(const std::string &what_arg) noexcept : std::logic_error(what_arg){}