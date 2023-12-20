#ifndef ASP3_HASHTABLE_H
#define ASP3_HASHTABLE_H

#include <iostream>
#include "LinearHashing.h"
using namespace std;

class HashTable {
public:
    HashTable(int size, int s) : size(size), linearHashing(new LinearHashing(s)) {}
    ~HashTable() { delete linearHashing; }

    string* findKey(int key);
    bool insertKey(int key, string value);
    bool deleteKey(int key);
    int avgAccessSuccess();
    int avgAccessUnsuccess();
    void resetStatistics();
    void clear();
    int keyCount();
    int tableSize();
    double fillRatio();
    friend ostream& operator<<(ostream& os, const HashTable& table);

private:
    int size = -1;
    LinearHashing *linearHashing = nullptr;
};


#endif
