#include <iostream>
#include <movie.cpp>
#include "hash_map.h"
using namespace std;

//Constructors for keyValuePairs, no default constructor for movie. So initialization list must be used
popPickTable::keyValuePair::keyValuePair() : key(""), value({}) {}

popPickTable::keyValuePair::keyValuePair(string k, vector<string> v) : key(k), value(v) {}

popPickTable::popPickTable(long size)
{
    table.resize(size);
    occupied.resize(size, false);
    numElements = 0;
}

int popPickTable::hashFunction(const string& key) const
{
    long hash = 0;
    int prime = 31; //Primes are good for hashing
    int tableSize = table.size();

    for(char ch : key)
    {
        hash = (hash*prime+ch) % tableSize; 
    }
    return hash;
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

void popPickTable::insert(const string& key, vector<string> value)
{
    if((double)numElements/table.size() > loadThreshold)
    {
        rehash();
    }

    int index = hashFunction(key);
    int originalIndex = index;

    while(occupied[index])
    {
        if(table[index].key == key)
        {
            table[index].value = value;
            return;
        }
        index = (index + 1) % table.size();
    }

    table[index] = keyValuePair(key, value);
    occupied[index] = true;
    numElements++;
}

string popPickTable::searchTitle(const string& key)
{
    int index = hashFunction(key);
    int originalIndex = index;

    while(occupied[index])
    {
        if(table[index].key == key)
        {
            return table[index].key;
        }
        index = (index+1) % table.size();
    }

    return "Not Found"; //not found
}

vector<string> popPickTable::searchGenres(const string& key)
{
    int index = hashFunction(key);
    int originalIndex = index;

    while(occupied[index])
    {
        if(table[index].key == key)
        {
            return table[index].value;
        }
        index = (index+1) % table.size();
    }

    return {};
}

int popPickTable::size()
{
    return table.size();
}

