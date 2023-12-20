#ifndef ASP3_LINEARHASHING_H
#define ASP3_LINEARHASHING_H

#include "AdressFunction.h"

class LinearHashing : public AddressFunction {
public:
    LinearHashing(int step) : step(step) {}
    int getAddress(int key, int address, int attempt) override;

private:
    int step;
};


#endif
