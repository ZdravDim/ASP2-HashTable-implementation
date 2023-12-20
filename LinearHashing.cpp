#include "LinearHashing.h"

int LinearHashing::getAddress(int key, int address, int attempt) {
    //...
    //ukoliko nema mesta
    return key + address * attempt;
    //u suprotnom vrati hash(key);
}
