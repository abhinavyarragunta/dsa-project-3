#include <iostream>
#include <movie.cpp>
#include "hash_map.h"
#include <functional>
using namespace std;

//Constructors for keyValuePairs, no default constructor for movie. So initialization list must be used
popPickTable::keyValuePair::keyValuePair() : key(""), value(Movie("","")) {}

popPickTable::keyValuePair::keyValuePair(string k, Movie v) : key(k), value(v) {}

popPickTable::popPickTable(long size, double threshold)
{
    table.resize(size);
    occupied.resize(size, false);
    numElements = 0;
    loadThreshold =  threshold;
}

int popPickTable::hashFunction(const string& key) const
{
    int hashValue = static_cast<long>(std::hash<string>{}(key));
    return hashValue % table.size();
}

void popPickTable::rehash()
{
    int newTableSize = table.size() * 2;
    vector<keyValuePair> oldTable = table;
    vector<bool> oldOccupied = occupied;

    table.resize(newTableSize);
    occupied.resize(newTableSize, false);
    numElements = 0;

    for(int i = 0; i < oldTable.size(); i++)
    {
        if(oldOccupied[i])
        {
            insert(oldTable[i].key, oldTable[i].value);
        }
    }
}