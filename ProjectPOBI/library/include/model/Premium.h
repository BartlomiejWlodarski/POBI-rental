//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_PREMIUM_H
#define INTRODUCTIONPROJECT_PREMIUM_H

#include "ClientType.h"

class Premium : public ClientType {
public:
    Premium(int maxItems, int penalty);
    ~Premium();
    virtual int maxLength() const override;
    virtual int calculatePenalty(int days, int items) override;
    virtual std::string getTypeInfo() const override;

};


#endif //INTRODUCTIONPROJECT_PREMIUM_H
