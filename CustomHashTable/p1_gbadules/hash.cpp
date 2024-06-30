#include "hash.h"

// Constructor
HashTable::HashTable(int size)
{
    this->tableSize = size;
    table = new Node *[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = nullptr;
    }
}

// Destructor
HashTable::~HashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        Node *entry = table[i];
        while (entry != nullptr)
        {
            Node *prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}

// Hash function
int HashTable::hashFunction(string key)
{
    // Simple hash function implementation (You can design your own)
    int hash = 0;
    for (char c : key)
    {
        hash = (hash * 31 + c) % tableSize;
    }
    return hash;
}

// Insert item
void HashTable::insertItem(string key)
{
    int index = hashFunction(key);
    Node *newNode = new Node(key);
    if (table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else
    {
        newNode->next = table[index];
        table[index] = newNode;
    }
}

// Print the contents of the first 5 slots
void HashTable::printTable()
{
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < min(tableSize, 5); i++)
    {
        cout << "Slot " << i << ": ";
        Node *entry = table[i];
        while (entry != nullptr)
        {
            cout << entry->key << " ";
            entry = entry->next;
        }
        cout << endl;
    }
}

// Print the length of each slot
void HashTable::printSlotLengths()
{
    cout << "==== Printing the slot lengths ====" << endl;

    for (int i = 0; i < 5; i++)
    {
        int count = 0;
        Node *entry = table[i];
        while (entry != nullptr)
        {
            count++;
            entry = entry->next;
        }
        cout << "Slot " << i << ": " << count << endl;
    }
}

// Calculate and print the standard deviation of the slot lengths
float HashTable::calculateStandardDeviation()
{
    float mean = 0;
    float sum = 0;
    for (int i = 0; i < tableSize; i++)
    {
        int count = 0;
        Node *entry = table[i];
        while (entry != nullptr)
        {
            count++;
            entry = entry->next;
        }
        sum += count;
    }
    mean = sum / tableSize;
    float variance = 0;
    for (int i = 0; i < tableSize; i++)
    {
        int count = 0;
        Node *entry = table[i];
        while (entry != nullptr)
        {
            count++;
            entry = entry->next;
        }
        variance += pow(count - mean, 2);
    }
    variance = variance / tableSize;
    return sqrt(variance);
}

