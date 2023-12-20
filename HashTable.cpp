#include <cmath>
#include "HashTable.h"

string *HashTable::findKey(int key) {
    int address = hashMethod(key);
    if (map[address].length()) return &map[address];
    return nullptr;
}

bool HashTable::insertKey(int key, string value) {
    if (keyCount() == hashTableSize) {
        cout << endl << "Greska pri unosu: Tabela puna." << endl;
        return false;
    }
    int address = hashMethod(key), newAddress = address, attempt = 0;
    while (map[newAddress].length())
        newAddress = linearHashing -> getAddress(key, address, ++attempt) % hashTableSize;
    map[newAddress] = value;
    ++numOfKeys;
    return true;
}

bool HashTable::deleteKey(int key) {
    if (findKey(key)) {
        *findKey(key) = "";
        --numOfKeys;
        return true;
    }
    cout << endl << "Greska pri brisanju: Kljuc ne postoji." << endl;
    return false;
}

int HashTable::avgAccessSuccess() {
    return avgSuccess;
}

int HashTable::avgAccessUnsuccess() {
    return avgUnsuccess;
}

void HashTable::resetStatistics() {
    avgSuccess = avgUnsuccess = 0;
}

void HashTable::clear() {
    resetStatistics();
    for (int i = 0; i < hashTableSize; ++i) map[i] = "";
    numOfKeys = 0;
}

int HashTable::keyCount() {
    return numOfKeys;
}

int HashTable::tableSize() {
    return hashTableSize;
}

double HashTable::fillRatio() {
    return numOfKeys / (double)hashTableSize;
}

ostream &operator<<(ostream &os, const HashTable &table) {
    os << endl << "Tabela:" << endl;
    for (int i = 0; i < table.hashTableSize; ++i)
        os << i << " " << (table.map[i].length() ? table.map[i] : "EMPTY") << endl;
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