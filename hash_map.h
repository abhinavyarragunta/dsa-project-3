#include <iostream>
#include <string>
#include <vector>
#include "movie.cpp"
#include <functional>

using namespace std;

class popPickTable
{
    public:
        popPickTable(long size = 10);
        void insert(const string& key, const Movie& value);
        Movie* search(const string& key);
        void printTable() const;
    private:
        struct keyValuePair
        {
            string key;
            Movie value;
            keyValuePair();
            keyValuePair(string k, Movie v);
        };

        vector<keyValuePair> table;
        vector<bool> occupied;
        long numElements;
        const double loadThreshold = 0.7;

        void rehash();
        int hashFunction(const string& key) const;

};