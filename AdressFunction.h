#ifndef ASP3_ADRESSFUNCTION_H
#define ASP3_ADRESSFUNCTION_H


class AddressFunction {
public:
    virtual int getAddress(int key, int baseAddress, int attempt) = 0;
};


#endif
