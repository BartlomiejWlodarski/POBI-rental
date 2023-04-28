//
// Created by student on 31.05.2022.
//

#include "model/Regular.h"

Regular::Regular(int maxItems, int penalty) : ClientType(maxItems, penalty){}

Regular::~Regular() {}

int Regular::maxLength() const {
    return 200;
}

int Regular::calculatePenalty(int days, int items) {
    return 2 * days * items;
}

std::string Regular::getTypeInfo() const {
    return ClientType::getTypeInfo() + "Regular";
}