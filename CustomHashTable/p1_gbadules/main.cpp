#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main()
{

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line))
    {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    HashTable hashTable(k);

    // Insert each token into the hash table
    for (int i = 0; i < n; i++)
    {
        hashTable.insertItem(texts[i]);
    }

    // Print the required outputs
    hashTable.printTable();       // Print the contents of the first 5 slots
    hashTable.printSlotLengths(); // Print the lengths of each slot
    cout << "==== Printing the standard variance ====" << endl;
    cout << fixed << setprecision(4) << hashTable.calculateStandardDeviation() << endl;

    return 0;
}