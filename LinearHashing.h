#ifndef ASP3_LINEARHASHING_H
#define ASP3_LINEARHASHING_H

#include "AdressFunction.h"

class LinearHashing : public AddressFunction {
public:
    LinearHashing(int s) : s(s) {}
    int getAddress(int k, int a, int i) override { return a + i * s; }

private:
    int s;
};


#endif
