//
// Created by student on 31.05.2022.
//

#ifndef INTRODUCTIONPROJECT_REGULAR_H
#define INTRODUCTIONPROJECT_REGULAR_H

#include "ClientType.h"

class Regular : public ClientType {
public:
    Regular(int maxItems, int penalty);
    ~Regular();
    virtual int maxLength() const override;
    virtual int calculatePenalty(int days, int items) override;
    virtual std::string getTypeInfo() const override;

};


#endif //INTRODUCTIONPROJECT_REGULAR_H
