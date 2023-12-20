#include "LinearHashing.h"

int LinearHashing::getAddress(int key, int address, int attempt) {
    return address + attempt * step;
}
