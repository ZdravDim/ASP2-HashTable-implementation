#include <cmath>
#include "HashTable.h"

string *HashTable::findKey(int key) {
    int stepsCounter = 0;
    int address = hashMethod(key), startAddress = address;
    if (keys[address] == key) {
        ++totalSuccess;
        ++numSuccess;
        return &values[address];
    }
    address = linearHashing -> getAddress(key, startAddress, ++stepsCounter) % hashTableSize;
    while (address != startAddress && keys[address] != key)
        address = linearHashing -> getAddress(key, startAddress, ++stepsCounter) % hashTableSize;
    if (keys[address] == key) {
        totalSuccess += stepsCounter + 1;
        ++numSuccess;
        return &values[address];
    }
    totalUnsuccess += stepsCounter;
    ++numUnsuccess;
    return nullptr;
}

bool HashTable::insertKey(int key, string value) {
    if (keyCount() == hashTableSize) {
        cout << endl << "Greska pri unosu: Tabela puna." << endl;
        return false;
    }
    int address = hashMethod(key), newAddress = address, attempt = 0;
    while (values[newAddress].length())
        newAddress = linearHashing -> getAddress(key, address, ++attempt) % hashTableSize;
    values[newAddress] = value;
    keys[newAddress] = key;
    ++numOfKeys;
    return true;
}

bool HashTable::deleteKey(int key) {
    if (findKey(key)) {
        *findKey(key) = "";
        keys[findKey(key) - values] = -1; //nije provereno da li radi
        --numOfKeys;
        return true;
    }
    cout << endl << "Greska pri brisanju: Kljuc ne postoji." << endl;
    return false;
}

double HashTable::avgAccessSuccess() const {
    return totalSuccess ? numSuccess / (double)totalSuccess : 0;
}

double HashTable::avgAccessUnsuccess() const {
    return totalUnsuccess ? numUnsuccess / (double)totalUnsuccess : 0;
}

void HashTable::resetStatistics() {
    numSuccess = numUnsuccess = totalSuccess = totalUnsuccess = 0;
}

void HashTable::clear() {
    resetStatistics();
    for (int i = 0; i < hashTableSize; ++i) values[i] = "";
    numOfKeys = 0;
}

int HashTable::keyCount() const {
    return numOfKeys;
}

int HashTable::tableSize() const {
    return hashTableSize;
}

double HashTable::fillRatio() const {
    return numOfKeys / (double)hashTableSize;
}

ostream &operator<<(ostream &os, const HashTable &table) {
    os << endl << "Tabela:" << endl;
    for (int i = 0; i < table.hashTableSize; ++i) {
        os << i << " ";
        if (table.values[i].length())
            os << table.values[i] << " " << table.keys[i] << endl;
        else cout << "EMPTY" << endl;
    }
    return os;
}

int HashTable::hashMethod(int key) const {
    return key % primeN;
}

bool HashTable::isPrimeNumber(int number) {
    if (number == 2) return true;
    for (int i = 2; i <= ceil(sqrt(number)); i++)
        if (number % i == 0) return false;
    return true;
}

int HashTable::findN(int number) {
    for (int i = number; i > 1; i--)
        if (isPrimeNumber(i))
            return i;
    return number;
}

int HashTable::index(int key) {
    return findKey(key) - values;
}
