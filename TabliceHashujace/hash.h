#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>

using namespace std;

class Hash{


    static const int arrSize = 10;

    struct Element{

        int key;
        string value;
        Element* next;


    };

    Element* hashTable[arrSize];

public:

    int hashF(int key);
    Hash();
    void insert(int key, string value);
    int hashTableSize(int index);
    void print();
    void printIndex(int index);
    bool find(int key);
    void remove(int key);


};





#endif // HASH_H
