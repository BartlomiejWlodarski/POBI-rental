//
// Created by student on 31.05.2022.
//

#include "model/Premium.h"

Premium::Premium(int maxItems, int penalty) : ClientType(maxItems, penalty){}

Premium::~Premium() {}

int Premium::maxLength() const {
    return 100;
}

int Premium::calculatePenalty(int days, int items) {
    return days * items;
}

std::string Premium::getTypeInfo() const {
    return ClientType::getTypeInfo() + "Premium";
}