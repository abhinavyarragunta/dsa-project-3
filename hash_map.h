#include <iostream>
#include <string>
#include <vector>
#include "movie.cpp"

using namespace std;

class popPickTable
{
    private:
        struct keyValuePair
        {
            string key;
            vector<string> value;
            keyValuePair();
            keyValuePair(string k, vector<string> v);
        };

        
        long numElements;
        const double loadThreshold = 0.7;

        void rehash();
        int hashFunction(const string& key) const;

    public:
        popPickTable(long size = 10);
        void insert(const string& key, vector<string> value);
        string searchTitle(const string& key);
        vector<string> searchGenres(const string& key);
        void printTable() const;
        int size();
        vector<bool> occupied;
        vector<keyValuePair> table;



        

        
};
