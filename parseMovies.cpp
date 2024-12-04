#include "graph.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<Movie> createMoviesFromAPI(string filename) {
    vector<Movie> movies;
    ifstream file(filename);
    string line;
    const string delimiter = " ::: ";

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return movies;
    }

    while (getline(file, line)) {
        vector<string> fields;
        int start = 0;
        int end = line.find(delimiter);

        while (end != string::npos) {
            fields.push_back(line.substr(start, end - start));
            start = end + delimiter.length();
            end = line.find(delimiter, start);
        }
        fields.push_back(line.substr(start));

        string title = fields[1];
        string genre = fields[2];
        string description = fields[3];

        Movie newMovie(title, genre, description);
        movies.push_back(newMovie);
    }

    file.close();
    return movies;
}