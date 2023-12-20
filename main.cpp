#include <iostream>

class AddressFunction {
public:
    virtual int getAddress(int key, int baseAddress, int attempt) = 0;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
