//
// Created by student on 06.06.2022.
//

#include "model/ClientType.h"

ClientType::ClientType(int maxItems, int penalty) : maxItems(maxItems), penalty(penalty) {}

ClientType::~ClientType() {}

int ClientType::maxLength() const {
    return 0;
}

int ClientType::calculatePenalty(int days, int items) {
    return days * items;
}

std::string ClientType::getTypeInfo() const {
    return "Client type: ";
}