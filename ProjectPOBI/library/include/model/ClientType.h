//
// Created by student on 06.06.2022.
//

#ifndef INTRODUCTIONPROJECT_CLIENTTYPE_H
#define INTRODUCTIONPROJECT_CLIENTTYPE_H


#include <string>

class ClientType {
private:
    int maxItems;
    int penalty;
public:
    ClientType(int maxItems, int penalty);

    virtual ~ClientType() = 0;

    virtual int maxLength() const;
    virtual int calculatePenalty(int days, int items);
    virtual std::string getTypeInfo() const;

};


#endif //INTRODUCTIONPROJECT_CLIENTTYPE_H
