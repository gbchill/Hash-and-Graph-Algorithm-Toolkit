#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Node structure for the linked list
struct Node
{
    string key;
    Node *next;

    Node(string key) : key(key), next(nullptr) {}
};

// Hash table class definition
class HashTable
{
public:
    HashTable(int size);
    ~HashTable();
    void insertItem(string key);
    void printTable();
    void printSlotLengths();
    float calculateStandardDeviation();

private:
    int tableSize;
    Node **table; // Array of pointers to Node
    int hashFunction(string key);
};

#endif // HASH_H
