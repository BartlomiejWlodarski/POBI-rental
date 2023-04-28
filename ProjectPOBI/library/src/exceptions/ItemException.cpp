//
// Created by student on 10.06.2022.
//

#include "exceptions/ItemException.h"

ItemException::ItemException(const std::string & what_arg) noexcept : logic_error(what_arg) {}